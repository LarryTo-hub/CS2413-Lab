#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100  // Define max queue size

// Queue structure
typedef struct {
    int data[MAX_SIZE];
    int front, rear, size;
} Queue;

// Stack structure using two queues
typedef struct {
    Queue *q1;  // Main queue
    Queue *q2;  // Temporary queue
} MyStack;

// Function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    return queue;
}

// Function to check if queue is empty
bool isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to enqueue an element
void enqueue(Queue* queue, int x) {
    if (queue->size == MAX_SIZE) {
        printf("Queue overflow\n");
        return;
    }
    queue->data[queue->rear++] = x;
    queue->size++;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    queue->size--;
    return queue->data[queue->front++];
}

// Function to get the front element of the queue
int front(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->front];
}

// Function to create a stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Function to push an element onto stack
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x); // Push new element into q2

    // Move all elements from q1 to q2
    while (!isQueueEmpty(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    // Swap q1 and q2
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

// Function to pop the top element of the stack
int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

// Function to get the top element of the stack
int myStackTop(MyStack* obj) {
    return front(obj->q1);
}

// Function to check if the stack is empty
bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q1);
}

// Function to free the allocated memory
void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}
