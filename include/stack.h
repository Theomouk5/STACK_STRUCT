#ifndef __STACK_H__
#define __STACK_H__

typedef enum {
    false,
    true
}Bool;

typedef struct StackElement {
    int value;
    struct StackElement* next;
}StackElement, *Stack;

#endif