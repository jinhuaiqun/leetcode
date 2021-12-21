/*
 * @Author: RiGe
 * @Date: 2021-08-31 17:18:40
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int              val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* newHead = NULL;
    struct ListNode* tmp     = head;
    struct ListNode* next    = NULL;
    struct ListNode* last    = NULL;

    if (head == NULL) {
        return NULL;
    }

    while (tmp != NULL && tmp->val == val) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    newHead = tmp;
    last    = newHead;

    while (tmp != NULL) {
        if (tmp->val == val) {
            last->next = tmp->next;
        }
        else {
            last = tmp;
        }

        tmp = tmp->next;
    }

    return newHead;
}

struct ListNode* createList(int arr[], int arrSize)
{
    struct ListNode* head = NULL;
    struct ListNode* tmp  = NULL;

    int i = 0;

    for (i = 0; i < arrSize; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val             = arr[i];
        node->next            = NULL;

        if (head == NULL) {
            head = node;
        }
        else {
            tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }

            tmp->next = node;
        }
    }

    return head;
}

void printList(struct ListNode* head)
{
    struct ListNode* tmp = head;

    while (tmp != NULL) {
        printf("%d\n", tmp->val);
        tmp = tmp->next;
    }
}

int main(void)
{
    int arr[] = {1, 2, 2, 1};

    struct ListNode* newListHead = createList(arr, sizeof(arr) / sizeof(arr[0]));

    printf("before remove\n");
    printList(newListHead);

    removeElements(newListHead, 2);

    printf("after remove\n");
    printList(newListHead);

    return 0;
}