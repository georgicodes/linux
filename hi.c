/* Module source file 'hi.c'. */  
#include <linux/module.h>      // for all modules 
#include <linux/init.h>        // for entry/exit macros 
#include <linux/kernel.h>      // for printk priority macros 
#include <asm/current.h>       // process information, just for fun 
#include <linux/sched.h>       // for "struct task_struct" 

static int hi(void)
{
     printk(KERN_INFO "hi module being loaded.\n");
     printk(KERN_INFO "User space process is '%s'\n", current->comm);
     printk(KERN_INFO "User space PID is  %i\n", current->pid);
     return 0;       // to show a successful load 
}  

static void bye(void) 
{
     printk(KERN_INFO "hi module being unloaded.\n"); 
}  

module_init(hi);     // what's called upon loading 
module_exit(bye);    // what's called upon unloading  

MODULE_AUTHOR("Robert P. J. Day"); 
MODULE_LICENSE("Dual BSD/GPL"); 
MODULE_DESCRIPTION("You have to start somewhere.");