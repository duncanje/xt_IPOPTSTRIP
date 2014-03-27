#include <xtables.h>

static struct xtables_target ipoptstrip_tg_reg = {
	.version		= XTABLES_VERSION,
	.name			= "IPOPTSTRIP",
	.revision		= 0,
	.family			= NFPROTO_IPV4,
};

void _init(void) {
	xtables_register_target(&ipoptstrip_tg_reg);
}
