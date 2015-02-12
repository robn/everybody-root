#define _GNU_SOURCE
#include <dlfcn.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd *(*_getpwnam)(const char *) = 0;
int (*_getpwnam_r)(const char *, struct passwd *, char *, size_t, struct passwd **) = 0;

struct passwd *getpwnam(const char *name) {
    if (!_getpwnam)
        _getpwnam = dlsym(RTLD_NEXT, "getpwnam");

    struct passwd *pwd = _getpwnam(name);
    if (pwd)
        return pwd;

    return _getpwnam("root");
}

int getpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result) {
    if (!_getpwnam_r)
        _getpwnam_r = dlsym(RTLD_NEXT, "getpwnam_r");

    int r = _getpwnam_r(name, pwd, buf, buflen, result);
    if (r || *result)
        return r;

    return _getpwnam_r("root", pwd, buf, buflen, result);
}
