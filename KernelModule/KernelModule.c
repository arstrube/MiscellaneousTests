/** KernelModule.c */

#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include "KernelModule.h"

int init_module(void)
{
	printk(KERN_INFO "Hello world 1.\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}
