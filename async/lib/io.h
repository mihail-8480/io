#ifndef IO_IO_H
#define IO_IO_H

#include <async.h>

#ifdef __cplusplus
extern "C" {
#endif

int32_t io_mkdir(char *path, mode_t mode);
int32_t io_write(int fd, const char *buf, uint32_t amount, size_t offset);
int32_t io_read(int fd, char *buf, uint32_t amount, size_t offset);
int32_t io_close(int fd);
int32_t io_socket(int domain, int type, int protocol, int flags);
int32_t io_accept(int fd, struct sockaddr *addr, socklen_t *addrlen, int flags);
int32_t io_bind(int fd, struct sockaddr *addr, socklen_t addrlen);
int32_t io_listen(int fd, int queue);
int32_t io_openat(int dfd, const char *path, int flags, mode_t mode);
int32_t io_cancel(task_t *task, int flags);
int32_t io_cancel_fd(int fd, int flags);
int32_t io_connect(int fd, const struct sockaddr *addr, socklen_t addrlen);
int32_t io_epoll_ctl(int epfd, int fd, int op, struct epoll_event *ev);
int32_t io_fadvise(int fd, size_t offset, off_t len, int advice);
int32_t io_fallocate( int fd, int mode, off_t offset, off_t len);
int32_t io_fgetxattr(int fd, const char *name, const char *value, size_t len);
int32_t io_fsetxattr(int fd, const char *name, const char *value, int flags, size_t len);
int32_t io_files_update(int *fds, unsigned int nr_fds, int offset);
int32_t io_fsync(int fd, unsigned int fsync_flags);
int32_t io_link(const char *oldpath, const char *newpath, int flags);
int32_t io_linkat(int olddfd, const char *oldpath, int newdfd, const char *newpath, int flags);
int32_t io_madvise(void *addr, off_t length, int advice);
int32_t io_mkdirat(int dfd, const char *path, mode_t mode);
int32_t io_msg_ring(int fd, unsigned int len, __u64 data, unsigned int flags);
int32_t io_multishot_accept(int fd, struct sockaddr *addr, socklen_t *addrlen, int flags);
int32_t io_nop();
int32_t io_setxattr(const char *name, const char *value, const char *path, int flags, size_t len);
int32_t io_getxattr(const char *name, const char *value, const char *path, int flags, size_t len);
int32_t io_poll_add(int fd, unsigned int poll_mask);
int32_t io_poll_remove(task_t *task);
int32_t io_poll_multishot(int fd, unsigned int poll_mask);
int32_t io_poll_update(task_t *task, unsigned int poll_mask, unsigned int flags);
int32_t io_provide_buffers(void *addr, int len, int nr, int bgid, int bid);
int32_t io_remove_buffers(int nr, int bgid);
int32_t io_recv(int sockfd, void *buf, size_t len, int flags);
int32_t io_recvmsg(int fd, struct msghdr *msg, unsigned int flags);
int32_t io_rename(const char *oldpath, const char *newpath);
int32_t io_renameat(int olddfd, const char *oldpath, int newdfd, const char *newpath, int flags);
int32_t io_send(int sockfd, const void *buf, size_t len, int flags);
int32_t io_sendmsg(int fd, const struct msghdr *msg, unsigned int flags);
int32_t io_shutdown(int fd, int how);
int32_t io_splice(int fd_in, int64_t off_in, int fd_out, int64_t off_out, unsigned int nbytes, unsigned int splice_flags);
int32_t io_statx(int dfd, const char *path, int flags, unsigned int mask, struct statx *statxbuf);
int32_t io_symlink(const char *target, const char *linkpath);
int32_t io_symlinkat(const char *target, int newdirfd, const char *linkpath);
int32_t io_sync_file_range(int fd, unsigned int len, size_t offset, int flags);
int32_t io_timeout(struct __kernel_timespec *ts, unsigned int count, unsigned int flags);
int32_t io_timeout_remove(task_t *task, unsigned int flags);
int32_t io_timeout_update(task_t *task,  struct __kernel_timespec *ts, unsigned int flags);
int32_t io_unlink(const char *path, int flags);
int32_t io_unlinkat(int dfd, const char *path, int flags);
int32_t io_rw(int op, int fd, const void *addr, unsigned int len, size_t offset);


#ifdef __cplusplus
}

#include <span>
#include <cstring>

namespace io {
    static inline int32_t mkdir(char *path, mode_t mode) {
        return io_mkdir(path, mode);
    }

    static inline int32_t write(int fd, const char *buf, uint32_t amount, size_t offset = 0) {
        return io_write(fd, buf, amount, offset);
    }

    static inline int32_t read(int fd, char *buf, uint32_t amount, size_t offset = 0) {
        return io_read(fd, buf, amount, offset);
    }

    static inline int32_t close(int fd) {
        return io_close(fd);
    }

    static inline int32_t accept(int fd, sockaddr *addr, socklen_t *addrlen, int flags) {
        return io_accept(fd, addr, addrlen, flags);
    }

    static inline int32_t socket(int domain, int type, int protocol, int flags) {
        return io_socket(domain, type, protocol, flags);
    }

    static inline int32_t bind(int fd, sockaddr *addr, socklen_t addrlen) {
        return io_bind(fd, addr, addrlen);
    }

    static inline int32_t openat(int dfd, const char *path, int flags, mode_t mode) {
        return io_openat(dfd, path, flags, mode);
    }

    static inline int32_t cancel(task_t *task, int flags) {
        return io_cancel(task, flags);
    }

    static inline int32_t cancel_fd(int fd, int flags) {
        return io_cancel_fd(fd, flags);
    }

    static inline int32_t connect(int fd, const struct sockaddr *addr, socklen_t addrlen) {
        return io_connect(fd, addr, addrlen);
    }

    static inline int32_t epoll_ctl(int epfd, int fd, int op, struct epoll_event *ev) {
        return io_epoll_ctl(epfd, fd, op, ev);
    }

    static inline int32_t fadvise(int fd, size_t offset, off_t len, int advice) {
        return io_fadvise(fd, offset, len, advice);
    }

    static inline int32_t fallocate(int fd, int mode, off_t offset, off_t len) {
        return io_fallocate(fd, mode, offset, len);
    }

    static inline int32_t fgetxattr(int fd, const char *name, const char *value, size_t len) {
        return io_fgetxattr(fd, name, value, len);
    }

    static inline int32_t fsetxattr(int fd, const char *name, const char *value, int flags, size_t len) {
        return io_fsetxattr(fd, name, value, flags, len);
    }

    static inline int32_t files_update(int *fds, unsigned int nr_fds, int offset) {
        return io_files_update(fds, nr_fds, offset);
    }

    static inline int32_t fsync(int fd, unsigned int fsync_flags) {
        return io_fsync(fd, fsync_flags);
    }

    static inline int32_t link(const char *oldpath, const char *newpath, int flags) {
        return io_link(oldpath, newpath, flags);
    }

    static inline int32_t linkat(int olddfd, const char *oldpath, int newdfd, const char *newpath, int flags) {
        return io_linkat(olddfd, oldpath, newdfd, newpath, flags);
    }

    static inline int32_t madvise(void *addr, off_t length, int advice) {
        return io_madvise(addr, length, advice);
    }

    static inline int32_t mkdirat(int dfd, const char *path, mode_t mode) {
        return io_mkdirat(dfd, path, mode);
    }

    static inline int32_t msg_ring(int fd, unsigned int len, __u64 data, unsigned int flags) {
        return io_msg_ring(fd, len, data, flags);
    }

    static inline int32_t multishot_accept(int fd, struct sockaddr *addr, socklen_t *addrlen, int flags) {
        return io_multishot_accept(fd, addr, addrlen, flags);
    }

    static inline int32_t nop() {
        return io_nop();
    }

    static inline int32_t setxattr(const char *name, const char *value, const char *path, int flags, size_t len) {
        return io_setxattr(name, value, path, flags, len);
    }

    static inline int32_t getxattr(const char *name, const char *value, const char *path, int flags, size_t len) {
        return io_getxattr(name, value, path, flags, len);
    }

    static inline int32_t poll_add(int fd, unsigned int poll_mask) {
        return io_poll_add(fd, poll_mask);
    }

    static inline int32_t poll_remove(task_t *task) {
        return io_poll_remove(task);
    }

    static inline int32_t poll_multishot(int fd, unsigned int poll_mask) {
        return io_poll_multishot(fd, poll_mask);
    }

    static inline int32_t poll_update(task_t *task, unsigned int poll_mask, unsigned int flags) {
        return io_poll_update(task, poll_mask, flags);
    }

    static inline int32_t provide_buffers(void *addr, int len, int nr, int bgid, int bid) {
        return io_provide_buffers(addr, len, nr, bgid, bid);
    }

    static inline int32_t remove_buffers(int nr, int bgid) {
        return io_remove_buffers(nr, bgid);
    }

    static inline int32_t recv(int sockfd, void *buf, size_t len, int flags) {
        return io_recv(sockfd, buf, len, flags);
    }

    static inline int32_t recvmsg(int fd, struct msghdr *msg, unsigned int flags) {
        return io_recvmsg(fd, msg, flags);
    }

    static inline int32_t rename(const char *oldpath, const char *newpath) {
        return io_rename(oldpath, newpath);
    }

    static inline int32_t renameat(int olddfd, const char *oldpath, int newdfd, const char *newpath, int flags) {
        return io_renameat(olddfd, oldpath, newdfd, newpath, flags);
    }

    static inline int32_t send(int sockfd, const void *buf, size_t len, int flags) {
        return io_send(sockfd, buf, len, flags);
    }

    static inline int32_t sendmsg(int fd, const struct msghdr *msg, unsigned int flags) {
        return io_sendmsg(fd, msg, flags);
    }

    static inline int32_t shutdown(int fd, int how) {
        return io_shutdown(fd, how);
    }

    static inline int32_t splice(int fd_in, int64_t off_in, int fd_out, int64_t off_out, unsigned int nbytes, unsigned int splice_flags) {
        return io_splice(fd_in, off_in, fd_out, off_out, nbytes, splice_flags);
    }

    static inline int32_t statx(int dfd, const char *path, int flags, unsigned int mask, struct statx *statxbuf) {
        return io_statx(dfd, path, flags, mask, statxbuf);
    }

    static inline int32_t symlink(const char *target, const char *linkpath) {
        return io_symlink(target, linkpath);
    }

    static inline int32_t symlinkat(const char *target, int newdirfd, const char *linkpath) {
        return io_symlinkat(target, newdirfd, linkpath);
    }

    static inline int32_t sync_file_range(int fd, unsigned int len, size_t offset, int flags) {
        return io_sync_file_range(fd, len, offset, flags);
    }

    static inline int32_t timeout(struct __kernel_timespec *ts, unsigned int count, unsigned int flags) {
        return io_timeout(ts, count, flags);
    }

    static inline int32_t timeout_remove(task_t *task, unsigned int flags) {
        return io_timeout_remove(task, flags);
    }

    static inline int32_t timeout_update(task_t *task,  struct __kernel_timespec *ts, unsigned int flags) {
        return io_timeout_update(task, ts, flags);
    }

    static inline int32_t unlink(const char *path, int flags) {
        return io_unlink(path, flags);
    }

    static inline int32_t unlinkat(int dfd, const char *path, int flags) {
        return io_unlinkat(dfd, path, flags);
    }

    static inline int32_t rw(int op, int fd, const void *addr, unsigned int len, size_t offset) {
        return io_rw(op, fd, addr, len, offset);
    }

    static inline int32_t listen(int fd, int queue) {
        return io_listen(fd, queue);
    }

    struct address {
        sockaddr* m_addr{};
        socklen_t m_addrlen{};
        address();
        address(const address&& old);
        address(const address& old);
        address(void* addr, size_t size);
        address operator=(const address& old);
        std::string ip() const;
        uint16_t port() const;
        ~address();
        static address from(const std::string& ip, short port);
    };

    struct file {
        file(int fd, bool close = false);
        size_t read(const std::span<char>& buf, size_t offset = 0) const;
        size_t write(const std::span<char>& buf, size_t offset = 0) const;
        size_t write(const std::string_view& str, size_t offset = 0) const;
        file accept(address& address, int flags = 0) const;
        void close() const;
        void bind(const io::address& addr) const;
        void listen(int queue = 0) const;
        void set_socket_options(int level, int name, int value = 1) const;
        static file create_socket(int domain, int type, int protocol, int flags);
        static file create_tcp(int options = SO_REUSEADDR | SO_REUSEPORT);
        static file create_tcp(const std::string& ip, int port, int queue = 0, int options = SO_REUSEADDR | SO_REUSEPORT);
        ~file();
    private:
        int m_fd;
        bool m_should_close;
    };
}

#endif
#endif //IO_IO_H
