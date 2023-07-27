#include <stack.h>
#include <stdlib.h>
#include <string.h>

#if STACK_VEC_IMPL == 1
stack stack_create(usize itm_sz)
{
    return (stack) {
        .len = 0,
        .itm_sz = itm_sz,
        .data = malloc(0)
    };
}

void stack_push(stack *stk, void *itm)
{
    stk->data = realloc(stk->data, (++stk->len) * stk->itm_sz);
    memcpy(stk->data + (stk->len - 1) * stk->itm_sz, itm, stk->itm_sz);
}

void *stack_pop(stack *stk)
{
    void *itm = malloc(stk->itm_sz);
    memcpy(itm, stk->data + (stk->len - 1) * stk->itm_sz, stk->itm_sz);
    stk->data = realloc(stk->data, (--stk->len) * stk->itm_sz);
    return itm;
}

void *stack_peek(stack *stk)
{
    return (stk->data + (stk->len - 1) * stk->itm_sz);
}

void stack_free(stack *stk)
{
    free(stk->data);
    *stk = (stack) {0};
}   
#endif
