#pragma once
#include <hl_type.h>

#define STACK_VEC_IMPL 1

#if STACK_VEC_IMPL == 1
typedef struct
{
    usize len;
    usize itm_sz;
    void *data;
} stack;

stack stack_create(usize itm_sz);
void stack_push(stack *stk, void *itm);
void *stack_pop(stack *stk);
void *stack_peek(stack *stk);
void stack_free(stack *stk);
#endif
