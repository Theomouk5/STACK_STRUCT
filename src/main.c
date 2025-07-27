#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack sta = new_stack();

    sta = push_stack(sta, 14);
    sta = push_stack(sta, 47);
    sta = push_stack(sta, 26);
    print_stack(sta);

    sta = pop_stack(sta);
    print_stack(sta);

    sta = clear_stack(sta);

    return 0;
}