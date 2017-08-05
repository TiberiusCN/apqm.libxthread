#pragma once

#include <stdlib.h>
#include <inttypes.h>

#ifdef linux

#include <pthread.h>

#endif
#ifdef WINNT

#include <windows.h>

#endif

typedef struct xthread_param
{
	void* param;
	void (*task)(void*);
} xthread_param;

int xthread(xthread_param* param);
