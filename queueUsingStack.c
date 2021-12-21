#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int stack1[100];
    int stack2[100];
    int top1;
    int top2;
} MyQueue;



/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue)); 

    queue->top1 = 0;
    queue->top2 = 0;

    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[obj->top1++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (obj->top2 == 0) {
        while (obj->top1 != 0) {
            obj->stack2[obj->top2++] = obj->stack1[--obj->top1];;
        }
    }

    if (obj->top2 == 0)
        return -1;

    return obj->stack2[--obj->top2];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == 0) {
        while (obj->top1 != 0) {
            obj->stack2[obj->top2++] = obj->stack1[--obj->top1];;
        }
    }

    if (obj->top2 == 0)
        return -1;

    return obj->stack2[obj->top2-1];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (obj->top2 == 0) {
        while (obj->top1 != 0) {
            obj->stack2[obj->top2++] = obj->stack1[--obj->top1];;
        }
    }

    if (obj->top2 == 0)
        return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
    obj = NULL;
}

int main(void)
{
    MyQueue *obj = myQueueCreate();

    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    myQueuePush(obj, 3);

    int val = myQueuePop(obj);

    int val2 = myQueuePeek(obj);

    bool isEmpty = myQueueEmpty(obj);

    myQueuePush(obj, 4);
    myQueuePush(obj, 5);

    int val3 = myQueuePop(obj);
    int val4 = myQueuePop(obj);
    int val5 = myQueuePop(obj);

    printf("%d\n", val);
    printf("%d\n", val2);
    printf("%d\n", isEmpty);
    printf("%d\n", val3);
    printf("%d\n", val4);
    printf("%d\n", val5);

    myQueueFree(obj);

    return 0;
}
