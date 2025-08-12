#ifndef __STACK_H__
#define __STACK_H__

typedef enum {
    False,
    True
}Bool;

typedef struct StackElement {
    int value;
    struct StackElement* next;
}StackElement, *Stack;

Stack new_stack(void);
Bool is_empty_stack(Stack st);
Stack clear_stack(Stack st);
Stack push_stack(Stack st, int value);
Stack pop_stack(Stack st);
void print_stack(Stack st);
int top_stack(Stack st);
int stack_length(Stack st);


#endif