#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

struct StackNode {
	int value;
    struct StackNode* next;
} typedef StackNode;

StackNode* StackNode_new(int node_value) {
    StackNode* new_node = malloc(sizeof(StackNode));
    new_node->value = node_value;
    new_node->next  = NULL;

    return new_node;
}

struct Stack {
    StackNode* top;
} typedef Stack;

Stack* Stack_new() {
    Stack* new_stack = malloc(sizeof(StackNode));
    new_stack->top = NULL;

    return new_stack;
}

bool Stack_isEmpty(Stack* s) {
    return (s->top == NULL);
}

void Stack_push(Stack* s, StackNode* node) {
    node->next = s->top;
    s->top = node;
} 

StackNode* Stack_pop(Stack* s) {
    if (!Stack_isEmpty(s)) {
        StackNode* target = s->top;
        s->top = s->top->next;

        return target;
    }
    return NULL;
}

void Stack_destroy(Stack* s) {
    while (!Stack_isEmpty(s)) {
        free(Stack_pop(s));
    }
    free(s);
}
