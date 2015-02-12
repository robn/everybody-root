# everybody-root

This is a tiny `LD_PRELOAD` shim that causes `getpwnam()` and `getpwnam_r()` to
return info for root if the requested user is not found.

## setup

```bash
$ make
$ LD_PRELOAD=`pwd`/everybody-root.so /path/to/exe
```

## why?

I needed it so that I can could convince `sshd` to log people in as root while
passing their requested login name down to PAM.

## should I use this?

No.

## credits and license

Copyright (c) 2015 Robert Norris. MIT license. See LICENSE.
