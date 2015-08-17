#ifndef PTHREAD_H
#define PTHREAD_H
#include "pthreadtypes.h"
#include "erron.h"

#define ATTR_STATE_ILEGAL 0
#define ATTR_STATE_LEGAL 1


enum
{
  PTHREAD_CREATE_JOINABLE,
  PTHREAD_CREATE_DETACHED
};


/* Mutex types.  */
enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
};


#ifdef __USE_XOPEN2K
/* Robust mutex or not flags.  */
enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
#endif


#if defined __USE_POSIX199506 || defined __USE_UNIX98
/* Mutex protocols.  */
enum
{
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};
#endif


int pthread_create(pthread_t *restrict thread,
					const pthread_attr_t *restrict attr,
			        void *(*start_routine)(void*), 
					void *restrict arg) __attribute__((nonnull (1, 3)));


pthread_t pthread_self();
int pthread_equal(pthread_t, pthread_t) __attribute__((nonnull (1, 2)));
void pthread_exit(void *value_ptr);
int pthread_cancel(pthread_t thread);

int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);
int pthread_attr_getdetachstate(const pthread_attr_t *attr, int *detachstate);
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);

int pthread_attr_getschedparam(const pthread_attr_t *restrict attr,
		       struct sched_param *restrict param);
int pthread_attr_setschedparam(pthread_attr_t *restrict attr,
		       const struct sched_param *restrict param);

int pthread_getschedparam(pthread_t thread, int *restrict policy, struct sched_param *restrict param);
int pthread_setschedparam(pthread_t thread, int policy, const struct sched_param *param);

int pthread_join(pthread_t thread, void **value_ptr);
int pthread_detach(pthread_t thread);

#endif

