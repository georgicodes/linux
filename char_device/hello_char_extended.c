#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
 
static dev_t mydev; /* Global variable for the device number */

static int dev_open(struct inode *, struct file *);
static int dev_rls(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, char *, size_t, loff_t *);

static int __init driver_entry(void)
{
    printk(KERN_INFO "HelloChar: registered");
    
    alloc_chrdev_region(&mydev, 0, 1, "HelloChar");
    
    printk(KERN_INFO "HelloChar: <Major, Minor>: <%d, %d>\n", MAJOR(mydev), MINOR(mydev));
    return 0;
}
 
static void __exit driver_exit(void)
{
    unregister_chrdev_region(mydev, 1);
    printk(KERN_INFO "HelloChar: unregistered");
}
 
module_init(driver_entry);
module_exit(driver_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Georgi K");
MODULE_DESCRIPTION("Hello World Character Driver");