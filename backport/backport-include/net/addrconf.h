#ifndef _BACKPORT_NET_ADDRCONF_H
#define _BACKPORT_NET_ADDRCONF_H 1

#include_next <net/addrconf.h>

#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(3,9,0)
static inline bool ipv6_addr_is_solict_mult(const struct in6_addr *addr)
{
#if defined(CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS) && BITS_PER_LONG == 64
	__u64 *p = (__u64 *)addr;
	return ((p[0] ^ cpu_to_be64(0xff02000000000000UL)) |
		((p[1] ^ cpu_to_be64(0x00000001ff000000UL)) &
		 cpu_to_be64(0xffffffffff000000UL))) == 0UL;
#else
	return ((addr->s6_addr32[0] ^ htonl(0xff020000)) |
		addr->s6_addr32[1] |
		(addr->s6_addr32[2] ^ htonl(0x00000001)) |
		(addr->s6_addr[12] ^ 0xff)) == 0;
#endif
}
#endif /* LINUX_VERSION_IS_LESS(3,9,0) */

#if LINUX_VERSION_IS_LESS(4,2,0)
static inline int ipv6_mc_check_mld(struct sk_buff *skb)
{
	WARN_ON(1);

	return -1;
}
#elif LINUX_VERSION_IS_LESS(5,1,0)
static inline int backport_ipv6_mc_check_mld(struct sk_buff *skb)
{
	return ipv6_mc_check_mld(skb, NULL);
}
#define ipv6_mc_check_mld LINUX_BACKPORT(ipv6_mc_check_mld)
#endif

#endif	/* _BACKPORT_NET_ADDRCONF_H */
