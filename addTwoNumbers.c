#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int carry = 0, sum = 0;
    struct ListNode *res = NULL;
    struct ListNode *tmp = NULL;
    struct ListNode *tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode)); 
        tmp->next = NULL;

        sum = l1->val + l2->val + carry;
        if (sum >= 10) {
            tmp->val = sum%10;
            carry = 1;
        } else {
            tmp->val = sum; 
            carry = 0;
        }
        
        if (tail == NULL) {
            res = tmp; 
            tail = tmp;
            l1 = l1->next; 
            l2 = l2->next;
            continue;
        }

        tail->next = tmp;
        tail = tmp;

        l1 = l1->next; 
        l2 = l2->next;
    }

    while (l1 != NULL) {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode)); 
        tmp->next = NULL;

        sum = l1->val + carry;
        if (sum >= 10) {
            tmp->val = sum%10;
            carry = 1;
        } else {
            tmp->val = sum; 
            carry = 0;
        }

        tail->next = tmp;
        tail = tmp;

        l1 = l1->next; 
    }

    while (l2 != NULL) {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode)); 
        tmp->next = NULL;

        sum = l2->val + carry;
        if (sum >= 10) {
            tmp->val = sum%10;
            carry = 1;
        } else {
            tmp->val = sum; 
            carry = 0;
        }

        tail->next = tmp;
        tail = tmp;

        l2 = l2->next; 
    }

    if (carry == 1) {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode)); 
        tmp->next = NULL;
        tmp->val = carry;
        tail->next = tmp;
    }

    return res;
}

struct ListNode *createList(int arr[], int size)
{
    int i = 0;
    struct ListNode *head = NULL;
    struct ListNode *tmp = NULL;
    struct ListNode *tail = NULL;

    if (size <= 0)
        return NULL;

    for (i = 0; i < size; i++) {
        tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = arr[i];
        tmp->next = NULL;

        if (tail == NULL) {
            head = tmp;        
            tail = tmp;
            continue;
        }

        tail->next = tmp;
        tail = tmp;
    }

    return head;
}

void printList(struct ListNode *head)
{
    struct ListNode *curr = head;

    while(curr != NULL) {
        printf("%d\n", curr->val); 
        curr = curr->next;
    }
}

int main(void)
{
    int arr1[] = {0};
    int arr2[] = {0};

    struct ListNode *l1 = createList(arr1, 1);
    struct ListNode *l2 = createList(arr2, 1);

    struct ListNode *res = addTwoNumbers(l1, l2);

    printList(res);

    return 0;
}
