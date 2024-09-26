/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _NRC_BUILD_CONFIG_H_
#define _NRC_BUILD_CONFIG_H_

#include <linux/version.h>

#define NRC_SW_ID       1

#define NRC_BUILD_USE_HWSCAN
/* #define CONFIG_NRC_HIF_PRINT_BEACON */
/* #define CONFIG_NRC_HIF_PRINT_RX_AUTH */
/* #define CONFIG_NRC_HIF_PRINT_RX_DATA */
/* #define CONFIG_NRC_HIF_PRINT_TX_MGMT */
/* #define CONFIG_NRC_HIF_PRINT_TX_DATA */
/* #define CONFIG_NRC_HIF_PRINT_FLOW_CONTROL */
/* #define CONFIG_NRC_HIF_DUMP_S1G_RXINFO */

/*#define NRC_TEST_SUPPRESS_STA_KEEEP_ALIVE*/

/*#define CONFIG_SPI_HALF_DUPLEX*/

/*
 * README This is a temporary feature.
 * Use only 11n certification
 */
/* #define CONFIG_TRX_BACKOFF */

/*
 * To change the transmission order of txq in the nrc driver.
 */
#define CONFIG_TXQ_ORDER_CHANGE_NRC_DRV

/*
 * To change the non-QoS data frame to QoS data frame on the nrc driver.
 */
#define CONFIG_CONVERT_NON_QOSDATA

/*
 * README This is a temporary feature.
 * Use S1G channel on host
 */
/* #define CONFIG_S1G_CHANNEL */

/*
 * To improve mesh routing at low RSSI.
 */
#define CONFIG_SUPPORT_MESH_ROUTING

/*
 * These depend on kernel version.
 */
/*
 * #define NRC_TARGET_KERNEL_VERSION KERNEL_VERSION(4, 4, 1)
 */
#define NRC_TARGET_KERNEL_VERSION LINUX_VERSION_CODE

/*
 * On kernel version 6.0 or higher, the dynamic ps became impossible.
 * refer https://lore.kernel.org/all/20220713114425.fa593e78de9a.I67a99fcbfcac0cefb4dcbb85e8b7d719b16d8a7c@changeid/
 */
#if KERNEL_VERSION(6, 0, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_USE_VIF_CFG
#define CONFIG_USE_LINK_ID
#undef ENABLE_DYNAMIC_PS
#endif

#if KERNEL_VERSION(5, 19, 2) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_USE_BSS_CHAN_CONF
#endif

#if KERNEL_VERSION(5, 19, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SUPPORT_LINK_STA
#endif

#if KERNEL_VERSION(5, 15, 0) <= NRC_TARGET_KERNEL_VERSION
#else
#ifdef CONFIG_S1G_CHANNEL
#undef CONFIG_S1G_CHANNEL
#endif /* CONFIG_S1G_CHANNEL */
#endif /* KERNEL_VERSION(5, 10, 0) <= NRC_TARGET_KERNEL_VERSION */

#ifdef CONFIG_S1G_CHANNEL
/* #define S1G_INCLUDE_4M_OP_2M_TX */
#endif

#if KERNEL_VERSION(4, 10, 0) <= NRC_TARGET_KERNEL_VERSION
#define GENL_ID_GENERATE 0
#endif
#if KERNEL_VERSION(4, 8, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_USE_CFG80211_SCAN_INFO
#endif
#if KERNEL_VERSION(4, 7, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_USE_NEW_BAND_ENUM
#endif
#if KERNEL_VERSION(4, 6, 0) <= NRC_TARGET_KERNEL_VERSION || \
    (KERNEL_VERSION(4, 4, 69) <= NRC_TARGET_KERNEL_VERSION && \
     KERNEL_VERSION(4, 5, 0) > NRC_TARGET_KERNEL_VERSION)
#define CONFIG_USE_IEEE80211_AMPDU_PARAMS
#endif
#if (KERNEL_VERSION(4, 4, 0) <= NRC_TARGET_KERNEL_VERSION && \
     KERNEL_VERSION(4, 4, 69) > NRC_TARGET_KERNEL_VERSION) || \
    (KERNEL_VERSION(4, 5, 0) <= NRC_TARGET_KERNEL_VERSION && \
     KERNEL_VERSION(4, 6, 0) > NRC_TARGET_KERNEL_VERSION)
#define CONFIG_SUPPORT_NEW_AMPDU_ACTION
#endif
#if KERNEL_VERSION(4, 3, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_USE_IFF_NO_QUEUE_FLAG
#endif
#if KERNEL_VERSION(4, 2, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SUPPORT_LONG_HWFLAG
#endif
#if KERNEL_VERSION(4, 1, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_USE_TXQ
#define CONFIG_USE_IFACE_ITER
#define CONFIG_USE_CHANNEL_CONTEXT
#endif
#if KERNEL_VERSION(4, 0, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SUPPORT_CCMP_256
#define CONFIG_SUPPORT_KEY_RESERVE_TAILROOM
#define CONFIG_SUPPORT_GCMP  //To support GCMP & GCMP-256 by using SW encryption.
#define CONFIG_SUPPORT_GMAC  //To support GMAC & GMAC-256 by using SW encryption.

#endif
#if KERNEL_VERSION(3, 19, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SUPPORT_IFTYPE_OCB
#define CONFIG_SUPPORT_HWDEV_NAME
#endif
#if KERNEL_VERSION(3, 17, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_USE_NEW_SCAN_REQ
#define CONFIG_USE_NEW_ALLOC_NETDEV
#endif
#if KERNEL_VERSION(3, 16, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SUPPORT_BEACON_TEMPLATE
#define CONFIG_SUPPORT_NEW_FLUSH
#endif
#if KERNEL_VERSION(3, 15, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SUPPORT_BSS_MAX_IDLE_PERIOD
#endif
#if KERNEL_VERSION(3, 0, 37) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SUPPORT_AFTER_KERNEL_3_0_36
#define CONFIG_SUPPORT_TX_CONTROL
#define CONFIG_SUPPORT_CHANNEL_INFO
#define CONFIG_SUPPORT_ITERATE_INTERFACE
#define CONFIG_SUPPORT_GENLMSG_DEFAULT
#define CONFIG_SUPPORT_SPI_SYNC_TRANSFER
#define CONFIG_NEW_REG_NOTIFIER
#define CONFIG_USE_HW_QUEUE
#define CONFIG_USE_MONITOR_VIF
#define CONFIG_SUPPORT_NEW_NETLINK
#define CONFIG_SUPPORT_PS
#define CONFIG_SUPPORT_NEW_MAC_TX
#define CONFIG_SUPPORT_P2P
#define CONFIG_SUPPORT_BD
#define CONFIG_SUPPORT_LEGACY_ACK
#define CONFIG_SUPPORT_BEACON_BYPASS
#endif
#if KERNEL_VERSION(3, 0, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SUPPORT_TX_FRAMES_PENDING
#endif
#if KERNEL_VERSION(2, 6, 30) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SUPPORT_THREADED_IRQ
#endif

#if KERNEL_VERSION(4, 10, 0) > NRC_TARGET_KERNEL_VERSION
/* WDS was deprecated and re-enabled with CONFIG_WIRELESS_WDS since 4.10 */
#define CONFIG_WIRELESS_WDS
#endif

#if KERNEL_VERSION(4, 2, 0) > NRC_TARGET_KERNEL_VERSION
#define ieee80211_hw_check(hw, flg) (hw->flags & IEEE80211_HW_##flg)
#endif

#if defined(CONFIG_WIRELESS_WDS) || defined(CONFIG_USE_CHANNEL_CONTEXT)
/* Cannot use CONFIG_USE_CHANNEL_CONTEXT) */
#undef CONFIG_USE_CHANNEL_CONTEXT
#endif

#define CONFIG_SUPPORT_IBSS

/* for backports */
/*
 * #ifdef CONFIG_USE_IFF_NO_QUEUE_FLAG
 * #undef CONFIG_USE_IFF_NO_QUEUE_FLAG
 * #endif
 */

/* uncomment define below to set tx power via iw or iwconfig */
/* #define CONFIG_SUPPORT_IW_IWCONFIG_TXPWR */

/* Use DT for spi device,
   spi_busnum_to_master fuction which is used to call spi_new_device
   has been deleted since 5.16 kernel version */

#if KERNEL_VERSION(5, 16, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_SPI_USE_DT
#endif
/* You can enable forcely in current version */
/* #define CONFIG_SPI_USE_DT */

#if KERNEL_VERSION(5, 4, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_USE_MAX_MTU
#endif

#if KERNEL_VERSION(5, 9, 0) <= NRC_TARGET_KERNEL_VERSION
#define CONFIG_NEW_TASKLET_API
#endif

#define CONFIG_QOS_NULL_OFFLOAD

/* If this configuration is enabled, 
   the function to wake up the target will be delayed 
   from the start of sleep up to TARGET_MAX_TIME_TO_FALL_ASLEEP. */
//#define CONFIG_DELAY_WAKE_TARGET  

#endif
