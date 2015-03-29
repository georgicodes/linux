#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
 
static dev_t mydev; /* Global variable for the device number */
static char output[] = "Be a Linux unicorn!\n";
struct cdev my_cdev;

ssize_t
my_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    printk(KERN_INFO "In chardrv read routine.\n");
    printk(KERN_INFO "Count field is %lu.\n", count);
    printk(KERN_INFO "Offset is %lu.\n", *f_pos);

    if (output[*f_pos] == '\0') {
        printk(KERN_INFO "End of string, returning zero.\n");
        return 0;
    }

    copy_to_user(buf, &output[*f_pos], 1);
    *f_pos += 1;
    return 1;  // returned a single character
}

struct file_operations my_fops = {
    .owner = THIS_MODULE,
    .read = my_read,
};

static int __init driver_entry(void)
{
    printk(KERN_INFO "HelloChar: registered");

    alloc_chrdev_region(&mydev, 0, 1, "HelloChar");

    cdev_init(&my_cdev, &my_fops);
    my_cdev.owner = THIS_MODULE;
    cdev_add(&my_cdev, mydev, 1);

    printk(KERN_INFO "HelloChar: <Major, Minor>: <%d, %d>\n", MAJOR(mydev), MINOR(mydev));
    return 0;
}
 
static void __exit driver_exit(void)
{
    cdev_del(&my_cdev);
    unregister_chrdev_region(mydev, 1);
    printk(KERN_INFO "HelloChar: unregistered");
}
 
module_init(driver_entry);
module_exit(driver_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Georgi K");
MODULE_DESCRIPTION("Hello World Character Driver");