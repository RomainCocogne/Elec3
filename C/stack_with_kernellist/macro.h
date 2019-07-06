#ifndef __MACRO_H_
#define __MACRO_H_

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>


#define FAIL	(-1)
#define OK	0

#define TRUE	1
#define FALSE	0

#define YES	1
#define NO	0

#define PRESENT	1
#define ABSENT	0

#define RETRY	2

#define SIZEOF(x) sizeof(x)/sizeof(*x)

#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type,member) );})

typedef int (*initcall_t)(void);
typedef uint8_t bool;

#define __define_initcall(level,fn,id) \
	static initcall_t __initcall_##fn##id __attribute__((__used__)) \
	__attribute__((__section__(".initcall." level))) = fn

#define pure_initcall(fn)		__define_initcall("0",fn,0)
#define core_initcall(fn)		__define_initcall("1",fn,1)



#define htonll(x) ((1==htonl(1)) ? (x) : ((uint64_t)htonl((x) & 0xFFFFFFFF) << 32) | htonl((uint32_t)((uint64_t)(x) >> 32)))
#define ntohll(x) ((1==htonl(1)) ? (x) : ((uint64_t)htonl((x) & 0xFFFFFFFF) << 32) | htonl((uint32_t)((uint64_t)(x) >> 32)))


#endif
