# hardlockup

A kernel module that locks up all CPUs. Useful for testing hardware watchdogs.

Once the module is loaded it starts a kernel thread on each CPU that locks it. The system freezes immediately.

### Compiling the module under Debian

```
sudo apt install build-essential linux-headers-$(uname -r)
make
```

### Running the modile
```
sudo insmod hardlockup.ko
```

### Compiling and running under balenaOS

https://github.com/balena-io-playground/hardlockup-balena
