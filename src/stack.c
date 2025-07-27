#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack new_stack(void)
{
    return NULL;
}

Bool is_empty_stack(Stack st)
{
    if(st == NULL)
        return True;

    return False;
}

Stack push_stack(Stack st, int value)
{
    StackElement* element;

    element = malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr, "Echec de l'allocation dynamique\n");
        exit(EXIT_FAILURE);
    }

    element->value = value;
    element->next = st;

    return element;
}

Stack pop_stack(Stack st)
{
    StackElement* element;

    if(is_empty_stack(st))
        return new_stack();

    element = st->next;
    free(st);

    return element;
}

Stack clear_stack(Stack st)
{
    while(!is_empty_stack(st))
        st = pop_stack(st);

    return new_stack();
}

void print_stack(Stack st)
{
    if(is_empty_stack(st))
    {
        printf("Rien a afficher, la Pile est vide.\n");
        return;
    }

    printf("\n--------------STACK----------------\n\n");

    printf("[%d] <- TOP\n", st->value);
    st = st->next;

    while(!is_empty_stack(st))
    {
        printf("[%d]\n", st->value);
        st = st->next;
    }

    printf("\n------------------------------------\n");
}

int top_stack(Stack st)
{
    if(is_empty_stack(st)) {
        printf("La pile est vide");
        return -1;
    }

    return st->value;
}

int stack_length(Stack st)
{
    int length = 0;

    while(!is_empty_stack(st))
    {
        length++;
        st = st->next;
    }

    return length;
}