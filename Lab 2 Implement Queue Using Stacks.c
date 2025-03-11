#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100  // Define maximum queue size

// Stack Structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Queue Structure using Two Stacks
typedef struct {
    Stack *stack1;
    Stack *stack2;
} MyQueue;

// Function to create a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Function to check if stack is empty
bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto stack
void pushStack(Stack* stack, int x) {
    stack->data[++stack->top] = x;
}

// Function to pop an element from stack
int popStack(Stack* stack) {
    return stack->data[stack->top--];
}

// Function to get the top element of stack
int peekStack(Stack* stack) {
    return stack->data[stack->top];
}

// Function to initialize the queue
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}

// Function to push an element into the queue
void myQueuePush(MyQueue* obj, int x) {
    pushStack(obj->stack1, x);
}

// Function to pop the front element from the queue
int myQueuePop(MyQueue* obj) {
    if (isStackEmpty(obj->stack2)) {
        while (!isStackEmpty(obj->stack1)) {
            pushStack(obj->stack2, popStack(obj->stack1));
        }
    }
    return popStack(obj->stack2);
}

// Function to get the front element of the queue
int myQueuePeek(MyQueue* obj) {
    if (isStackEmpty(obj->stack2)) {
        while (!isStackEmpty(obj->stack1)) {
            pushStack(obj->stack2, popStack(obj->stack1));
        }
    }
    return peekStack(obj->stack2);
}

// Function to check if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return isStackEmpty(obj->stack1) && isStackEmpty(obj->stack2);
}

// Function to free the allocated memory for queue
void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}
