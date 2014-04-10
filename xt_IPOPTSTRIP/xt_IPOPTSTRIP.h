#ifndef _LINUX_NETFILTER_XT_IPOPTSTRIP_H
#define _LINUX_NETFILTER_XT_IPOPTSTRIP_H 1

#define XT_IPOPTSTRIP_IS_SET(flags,flag) flags & flag

enum {
	XT_IPOPTSTRIP_KEEP_DST = 0x01,
};

struct xt_ipoptstrip_tg_info {
	__u8 flags;
};

#endif 
