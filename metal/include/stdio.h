#ifndef __STDIO_H__
#define __STDIO_H__

#include <stdbool.h>

// Send Carrige Return before Linefeed
#define SEND_CR_BEFORE_LF

#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef __SIZE_T_DEFINED
#define __SIZE_T_DEFINED
typedef unsigned long size_t;
#endif

#define EOF (-1)


int getchar(void);

void putchar(char chr);

char *gets(char * str, int bufsize, bool echo, char * prompt);

void puts(char *ptr);

void putint(long long n, int base, bool upprcase);

void puthex(unsigned int val, int digits, bool uppercase);

int printf(char *fmt,...);


#endif // __STDIO_H__