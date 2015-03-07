#ifndef XV6_SIGNAL
#define XV6_SIGNAL

#define SIGHUP 1
#define SIGINT 2
#define SIGQUIT 3
#define SIGILL 4
#define SIGABRT 6
#define SIGFPE 8
#define SIGKILL 9
#define SIGSEGV 11
#define SIGPIPE 13
#define SIGALRM 14
#define SIGTERM 15

// You should define anything signal related that needs to be shared between
// kernel and userspace here
/*
struct sighandler_t{
	uint eip;
	int handled;
	void *function;
}; typedef struct sighandler_t sighandler_t;
*/
typedef *(*void) sig_func_pointer(int signumber) sighandler_t;
// At a minimum you must define the signal constants themselves
// as well as a sighandler_t type.

#endif
