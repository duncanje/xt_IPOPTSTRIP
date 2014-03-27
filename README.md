## xt_IPOPTSTRIP
xtables target extension to strip all IP options from IPv4 packets

### Prerequisites
- iptables-dev
- Kernel headers

### Setup
	cd libxt_IPOPTSTRIP
	make install
	cd ../xt_IPOPTSTRIP
	make
	modprobe x_tables
	insmod xt_IPOPTSTRIP.ko

### Todo
Re-insert IP options for inbound packets

### Thanks
Engelhardt, Jan, and Nicolas Bouliane. "Writing Netfilter Modules." Revised, July 3 (2012).
