#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int queue[100];
    int head;
    int tail;
} MyQueue;

typedef struct {
    MyQueue *queue1;
    MyQueue *queue2;
} MyStack;


MyQueue* initQueue()
{
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue)); 
    q->head = -1; 
    q->tail = -1; 
    return q;
}

void enQueue(MyQueue* queue, int x)
{
    if (queue->head == -1)
        queue->head = 0;

    queue->tail++;
    queue->queue[queue->tail] = x;

    printf("enQueue: queue->tail = %d\n", queue->tail);
}

int deQueue(MyQueue* queue)
{
    int val = queue->queue[queue->head];

    if (queue->head == queue->tail) {
        queue->head = -1; 
        queue->tail = -1; 
        return val;
    }

    queue->head++;

    return val;
}

bool isEmpty(MyQueue *q)
{
    return q->head == -1;
}

void freeQueue(MyQueue *queue)
{
    free(queue);
    queue = NULL;
}


/** Initialize your data structure here. */
MyStack* myStackCreate() {
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->queue1 = initQueue();
    s->queue2 = initQueue();

    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    MyQueue* tmp = NULL;
    int val = 0;
    int times = 0;

    enQueue(obj->queue2, x);

    while (!isEmpty(obj->queue1)) {
        val = deQueue(obj->queue1);

        enQueue(obj->queue2, val); 
    }

    tmp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = tmp;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return deQueue(obj->queue1);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queue1->queue[obj->queue1->head];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->queue1);
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}

int main(void)
{

/*********************************/

    MyStack* obj = myStackCreate();

    myStackPush(obj, 1);
    myStackPush(obj, 2);
    myStackPush(obj, 3);

    int param_2 = myStackPop(obj);
    int param_3 = myStackPop(obj);

    int param_4 = myStackPop(obj);

    bool param_5 = myStackEmpty(obj);

    printf("%d %d %d %d\n", param_2, param_3, param_4, param_5);

    myStackFree(obj);

/*********************************/

    return 0;
}
