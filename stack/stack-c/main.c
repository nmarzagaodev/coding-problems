#include <stdio.h>
#include <assert.h>
#include "stack.c"

void Test_StackNode_new() {
	StackNode* stack_node = StackNode_new(10);
	assert(stack_node->value == 10);
	assert(stack_node->next == NULL);

	free(stack_node);
}

void Test_Stack_new() {
	Stack* stack = Stack_new();
	assert(stack->top == NULL);

	free(stack);
}

void Test_Stack_push() {
	Stack* stack = Stack_new();
	
	Stack_push(stack, StackNode_new(1));
	assert(stack->top->value == 1);

	Stack_push(stack, StackNode_new(2));
	Stack_push(stack, StackNode_new(3));
	
	assert(stack->top->value == 1);
	assert(stack->top->next->value == 2);
	assert(stack->top->next->next->value == 3);
	assert(stack->top->next->next->next == NULL);

	free(stack->top->next->next); // free 3
	free(stack->top->next); 	  // free 2
	free(stack->top); 			  // free 1
	free(stack);
}

int main(void) {
	

}
