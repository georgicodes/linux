#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_DEUBG
#include <linux/init.h>      // included for __init and __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Georgi");
MODULE_DESCRIPTION("A Simple Hello World module");

static int __init hello(void)
{
    printk(KERN_DEBUG ">>> Hello world! <<<\n");
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit goodbye(void)
{
    printk(KERN_DEBUG ">>> Goodbye world! <<<\n");
}

module_init(hello);
module_exit(goodbye);