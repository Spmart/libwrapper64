#include <fcntl.h>
#include <stdarg.h>

int fcntl64(int fd, int cmd, ...) {
    va_list args;
    va_start(args, cmd);
    void *arg = va_arg(args, void *);
    va_end(args);
    return fcntl(fd, cmd, arg);
}

extern int posix_fallocate(int fd, long offset, long len);
int posix_fallocate64(int fd, long offset, long len) {
    return posix_fallocate(fd, offset, len);
}