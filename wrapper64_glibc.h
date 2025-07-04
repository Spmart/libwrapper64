#ifndef WRAPPER64GLIBC_H
#define WRAPPER64GLIBC_H

int fcntl64(int fd, int cmd, ...);
int posix_fallocate64(int fd, long offset, long len);

#endif