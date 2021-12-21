/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int          val;
    struct Node* next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate()
{
    MyLinkedList* head = malloc(sizeof(MyLinkedList));
    if (head == NULL) {
        return NULL;
    }

    head->val  = -1;
    head->next = NULL;

    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index)
{
    int cnt = 0;
    MyLinkedList* tmp = obj->next;

    if (tmp == NULL || index < 0) {
        return -1;
    }

    while (tmp != NULL) {
        if (cnt == index) {
            return tmp->val;
        }
        tmp = tmp->next;
        cnt++;
    }

    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    if (obj == NULL) {
        return;
    }

    MyLinkedList* node = malloc(sizeof(MyLinkedList));
    if (node == NULL) {
        return;
    }

    node->val  = val;
    node->next = obj->next;

    obj->next = node;
    return;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    MyLinkedList* tmp = obj;

    if (obj == NULL) {
        return;
    }

    MyLinkedList* node = malloc(sizeof(MyLinkedList));
    if (node == NULL) {
        return;
    }

    node->val  = val;
    node->next = NULL;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = node;

    return;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    int           count = 0;
    MyLinkedList* tmp   = obj;
    MyLinkedList* node  = NULL;

    if (tmp == NULL) {
        return;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
        count++;
    }

    if (index > count) {
        return;
    }

    node = malloc(sizeof(MyLinkedList));
    if (node == NULL) {
        return;
    }
    node->val = val;
    node->next = NULL;

    if (index < 0) {
        node->next = obj->next;
        obj->next  = node;
    }
    else if (index == count) {
        tmp->next = node;
    }
    else {
        tmp = obj;
        while (index-- > 0) {
            tmp = tmp->next;
        }
        node->next = tmp->next;
        tmp->next  = node;
    }

    return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    int           cnt    = 0;
    MyLinkedList* tmp  = obj;
    MyLinkedList* node = NULL;

    if (index < 0) {
        return;
    }

    while (tmp->next != NULL) {
    
        if (cnt == index) {
            node = tmp->next;
            tmp->next = tmp->next->next;
            // free(node);
            return;
        }
        cnt++;
        tmp = tmp->next;
    }

    return;
}

void myLinkedListFree(MyLinkedList* obj)
{
    MyLinkedList* tmp  = obj;
    MyLinkedList* next = NULL;
    if (tmp == NULL) {
        return;
    }

    while (tmp != NULL) {
        next = tmp->next;
        // free(tmp);
        tmp->val = -1;
        tmp      = next;
    }
    return;
}

void display(MyLinkedList* obj)
{
    MyLinkedList* tmp = obj->next;

    if (tmp == NULL) {
        return;
    }

    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");

    return;
}

int main()
{
    MyLinkedList* obj = myLinkedListCreate();

    myLinkedListAddAtHead(obj, 1);

    display(obj);

    myLinkedListAddAtTail(obj, 2);

    display(obj);

    myLinkedListAddAtIndex(obj, 1, 2);

    display(obj);

    int num = myLinkedListGet(obj, 1);

    printf("%d\n", num);

    myLinkedListDeleteAtIndex(obj, 1);

    printf("after delete:\n");
    display(obj);

    myLinkedListFree(obj);
    return 0;
}