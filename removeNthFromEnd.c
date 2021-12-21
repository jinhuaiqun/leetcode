/*
 * @Author: RiGe
 * @Date: 2021-12-07 08:02:48
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int              val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int              i   = 0;
    int              cnt = 0;
    struct ListNode* tmp = head;

    while (tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }

    int seq = cnt - n + 1;

    if (seq == 1) {
        head = head->next;
    }
    else {
        tmp = head;
        for (i = 1; i < seq - 1; i++) {
            tmp = tmp->next;
        }
        if (tmp->next != NULL)
            tmp->next = tmp->next->next;
    }

    return head;
}

struct ListNode* createList(int arr[], int size)
{
    int              i    = 0;
    struct ListNode* head = NULL;
    struct ListNode* prev = NULL;

    for (i = 0; i < size; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val             = arr[i];
        node->next            = NULL;

        if (head == NULL) {
            head = node;
        }
        else {
            prev->next = node;
        }

        prev = node;
    }

    return head;
}

void printList(struct ListNode* head)
{
    while (head != NULL) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

int main(void)
{
    int arr[2] = {1, 2};

    struct ListNode* head = createList(arr, 2);

    printList(head);

    struct ListNode* newHead = removeNthFromEnd(head, 2);

    printList(newHead);

    return 0;
}