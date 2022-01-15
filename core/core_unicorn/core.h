#ifndef CORE_UNICORN_CORE_H
#define CORE_UNICORN_CORE_H

#include "unicorn/unicorn.h"

#include <stdlib.h>

// Public structs



// Arch structs

typedef enum _CORE_UNICORN_ARCH
{
    CORE_UNICORN_ARCH_X86,

}CORE_UNICORN_ARCH;

typedef enum _CORE_UNICORN_MODE
{
    CORE_UNICORN_MODE_16 = 1 << 1,
    CORE_UNICORN_MODE_32 = 1 << 2,
    CORE_UNICORN_MODE_64 = 1 << 3,

}CORE_UNICORN_MODE;



// Mem structs

typedef struct _MEM_LIST
{
    LIST_ENTRY listNode;

    unsigned int memStart;
    unsigned int memSize;

    unsigned int memLabel;

}MEM_LIST, * PMEM_LIST;



// Reg structs

typedef struct _REG_LIST_X86_32
{
    unsigned int eax;
    unsigned int ecx;
    unsigned int edx;
    unsigned int ebx;
    unsigned int esp;
    unsigned int ebp;
    unsigned int esi;
    unsigned int edi;
    unsigned int eip;
    unsigned int eflags;

}REG_LIST_X86_32;



// Core structs

typedef uc_engine* PUC_ENGINE;

typedef enum _CORE_UNICORN_ERR
{
    CORE_UNICORN_ERR_INTERNAL = -1,
    CORE_UNICORN_ERR_OK = 0,
    CORE_UNICORN_ERR_NOMEM,					// Out of Memory

}CORE_UNICORN_ERR;

typedef struct _CORE_UNICORN_ENGINE
{
    CORE_UNICORN_ARCH arch;
    CORE_UNICORN_MODE mode;
    PMEM_LIST memList;
    PVOID regList;
    uc_engine* ucEngine;

}CORE_UNICORN_ENGINE, * PCORE_UNICORN_ENGINE;

typedef struct _CORE_UNICORN_CONFIG
{
    CORE_UNICORN_ARCH arch;
    CORE_UNICORN_MODE mode;

}CORE_UNICORN_CONFIG;



unsigned int core_unicorn_init(PVOID* pEngine, CORE_UNICORN_CONFIG config);

#endif // !CORE_UNICORN_CORE_H
