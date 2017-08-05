#include "xthread.h"

#ifdef WINNT

DWORD WINAPI mkxthread(void* lp);

#endif
#ifdef linux

void* mkxthread(void* lp);

#endif

#ifdef WINNT
DWORD WINAPI
#endif
#ifdef linux
void*
#endif
mkxthread(void* lp)
{
	((xthread_param*)lp)->task(((xthread_param*)lp)->param);
	return 0;
}

int xthread(xthread_param* param)
{
#ifdef WINNT
	void* hndl = CreateThread(0,0,mkxthread,param,0,0); //last — thread id
	if(hndl) return 0;
	return 1;
#endif
#ifdef linux
	pthread_t hndl;
	return pthread_create(&hndl,0,mkxthread,param);
#endif
}
