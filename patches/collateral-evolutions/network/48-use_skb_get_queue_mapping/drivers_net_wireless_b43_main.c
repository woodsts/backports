--- a/drivers/net/wireless/b43/main.c
+++ b/drivers/net/wireless/b43/main.c
@@ -3456,11 +3456,11 @@
 	}
 	B43_WARN_ON(skb_shinfo(skb)->nr_frags);
 
-	skb_queue_tail(&wl->tx_queue[skb->queue_mapping], skb);
-	if (!wl->tx_queue_stopped[skb->queue_mapping]) {
+	skb_queue_tail(&wl->tx_queue[skb_get_queue_mapping(skb)], skb);
+	if (!wl->tx_queue_stopped[skb_get_queue_mapping(skb)]) {
 		ieee80211_queue_work(wl->hw, &wl->tx_work);
 	} else {
-		ieee80211_stop_queue(wl->hw, skb->queue_mapping);
+		ieee80211_stop_queue(wl->hw, skb_get_queue_mapping(skb));
 	}
 }
 