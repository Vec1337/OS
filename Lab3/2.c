#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vedran");
MODULE_DESCRIPTION("Modul koji ispisuje sve procese");

int sviprocesi_init(void)
{
    struct task_struct *task;

    printk(KERN_INFO "Svi procesi:\n");

    // Iterate over all processes
    for_each_process(task) {
        pr_info("Ime: %s, PID: %d\n", task->comm, task->pid);
    }

    return 0;
}

module_init(sviprocesi_init);


