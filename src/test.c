#include <hl_type.h>
#include <stdint.h>
#include <stdio.h>
#include "stack.h"

void test_stack();

int main()
{
    test_stack();
}

void test_stack()
{
    printf("STACK TEST STARTED\n");
    stack stk = stack_create(sizeof(u16));
    printf("[STK_ITM_SZ]: %zu\n", stk.itm_sz);
    
    for (u16 i = 0;i < 25;++i)
    {
        stack_push(&stk, &i);
        printf("[STK_ITM_%zu]: %u ", stk.len, *((u16 *)stack_peek(&stk)));
    }
    printf("\n\n");
    while (stk.len != 0)
    {
        printf("[STK_POP]: %u ", *((u16 *)stack_pop(&stk)));
    }
    stack_free(&stk);
    printf("\nSTACK TEST FINISHED\n");
}
