#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vedran");
MODULE_DESCRIPTION("Modul koji ispisuje sve procese");

int newmodule_init(void)
{
    struct task_struct *task;

    printk(KERN_INFO "Ispis svih procesa:\n");

    for_each_process(task) {
        pr_info("Ime: %s, PID: %d, PPID: %d, Stanje: %c\n",
                task->comm, task->pid, task->real_parent->pid, task_state_to_char(task));
    }

    return 0;
}

void newmodule_exit(void) {

    printk(KERN_INFO "Uklanjam jezgreni modul\n");
}

module_init(newmodule_init);
module_exit(newmodule_exit);


