#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vedran");
MODULE_DESCRIPTION("Jednostavan modul");

int mymodule_init(void) {
 
    printk(KERN_INFO "Ucitavam jezgreni modul\n");
    printk(KERN_INFO "Jiffies: %lu %d\n",jiffies/HZ,HZ);

    return 0;
}

void mymodule_exit(void) {

    printk(KERN_INFO "Uklanjam jezgreni modul\n");
    printk(KERN_INFO "Jiffies: %lu %d\n",jiffies/HZ,HZ);
}

module_init(mymodule_init);
module_exit(mymodule_exit);
