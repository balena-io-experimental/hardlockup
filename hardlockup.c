#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
 
MODULE_LICENSE("GPL");

static int
hardlockup_thread(void *data)
{
    static DEFINE_SPINLOCK(lock);
    unsigned long flags;
 
    printk(KERN_INFO "Hogging a CPU now\n");
    spin_lock_irqsave(&lock, flags);
    while (1);
 
    /* unreached */
    return 0;
}

static int __init
hardlockup_init(void)
{
    int cpu = 0;
    struct task_struct *task;

    for_each_possible_cpu(cpu) {
        task = kthread_create_on_node(hardlockup_thread, NULL, cpu_to_node(cpu), "kswithardlockup_%d", cpu);
        kthread_bind(task, cpu);
        wake_up_process(task);
    }

    return 0;
}

module_init(hardlockup_init);
