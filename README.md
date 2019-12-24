# hardlockup

A kernel module that locks up all CPUs. Useful for testing hardware watchdogs.

Once the module is loaded it starts a kernel thread on each CPU that locks it. The system freezes immediately.

```
make
sudo insmod hardlockup.ko
```
