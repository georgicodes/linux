#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/usb.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Georgi");
MODULE_DESCRIPTION("Hello World with some USB fun times thrown in.");

// register with USB subsystem
static struct usb_driver usb_hello_driver = {
    .name =     "hello_usb_driver",
    .probe =    hello_usb_probe,
    .disconnect =   hello_usb_disconnect,
    .id_table = hello_usb_id_table
};

/* table of devices that work with this driver */
static struct usb_device_id hello_usb_id_table [] = {
    { USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
        USB_INTERFACE_SUBCLASS_BOOT,
        USB_INTERFACE_PROTOCOL_KEYBOARD)},
    { } /* Terminating entry */

};
MODULE_DEVICE_TABLE (usb, hello_usb_id_table);

static int hello_usb_probe(struct usb_interface *interface,
    const struct usb_device_id *id)
{
    return 0;
}

static void hello_usb_disconnect(struct usb_interface *interface)
{
    printk(KERN_DEBUG "Disconnecting USB.\n");
    return;
}

static int __init hello_init(void)
{
    printk(KERN_DEBUG "Hello world!\n");
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit hello_cleanup(void)
{
    // deregister driver with USB subsystem
    usb_deregister(&usb_hello_driver)
    printk(KERN_DEBUG "Cleaning up hello world module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);