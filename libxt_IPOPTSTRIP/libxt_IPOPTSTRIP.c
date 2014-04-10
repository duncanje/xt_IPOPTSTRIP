#include <stdio.h>
#include <xtables.h>
#include <getopt.h>
#include "../xt_IPOPTSTRIP/xt_IPOPTSTRIP.h"

/* Available options */
static const struct option ipoptstrip_tg_opts[] = {
	{.name = "keep-dest", .has_arg = false, .val = 'n'},
	{NULL}
};

/* Display help text */
static void ipoptstrip_tg_help(void) {
	printf("IPOPTSTRIP target options:\n"
	 " --keep-dest    In case of source routing, do not alter destination\n");
}

/* Parse options */
static int ipoptstrip_tg_parse(int c, char **argv, int invert,
	unsigned int *flags, const void *entry, struct xt_entry_target **targetinfo) {

	struct xt_ipoptstrip_tg_info *info = (void *) (*targetinfo)->data;

	/* Switch on the possible options */
	switch (c) {
	case 'n':
		/* Check if option has already been used */
		if (XT_IPOPTSTRIP_IS_SET(*flags, XT_IPOPTSTRIP_KEEP_DST))
			xtables_error(PARAMETER_PROBLEM, "--keep-dest may only be used once");
		
		*flags |= XT_IPOPTSTRIP_KEEP_DST; /* Passed to each call of _parse and _check */
		info->flags |= XT_IPOPTSTRIP_KEEP_DST;
		
		return true;
	}
	
	return false;
}

static struct xtables_target ipoptstrip_tg_reg = {
	.version		= XTABLES_VERSION,
	.name			= "IPOPTSTRIP",
	.revision		= 0,
	.family			= NFPROTO_IPV4,
	.size			= XT_ALIGN(sizeof(struct xt_ipoptstrip_tg_info)),
	.userspacesize	= XT_ALIGN(sizeof(struct xt_ipoptstrip_tg_info)),
	.parse			= ipoptstrip_tg_parse,
	.help			= ipoptstrip_tg_help,
	.extra_opts		= ipoptstrip_tg_opts,
};

void _init(void) {
	xtables_register_target(&ipoptstrip_tg_reg);
}
