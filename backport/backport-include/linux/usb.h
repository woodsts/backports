#ifndef __BACKPORT_LINUX_USB_H
#define __BACKPORT_LINUX_USB_H
#include_next <linux/usb.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(4,12,0)
#define usb_find_common_endpoints LINUX_BACKPORT(usb_find_common_endpoints)
int __must_check
usb_find_common_endpoints(struct usb_host_interface *alt,
		struct usb_endpoint_descriptor **bulk_in,
		struct usb_endpoint_descriptor **bulk_out,
		struct usb_endpoint_descriptor **int_in,
		struct usb_endpoint_descriptor **int_out);
#endif /* < 4.12 */

#if LINUX_VERSION_IS_LESS(5,15,0)
#define usb_check_bulk_endpoints LINUX_BACKPORT(usb_check_bulk_endpoints)
bool usb_check_bulk_endpoints(
		const struct usb_interface *intf, const u8 *ep_addrs);
#endif /* < 5.15 */

#endif /* __BACKPORT_LINUX_USB_H */
