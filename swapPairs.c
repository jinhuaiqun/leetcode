#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode *head)
{
    struct ListNode *curr = NULL;

    if (head == NULL || head->next == NULL)
        return head;

    curr = head;
    while (curr != NULL && curr->next != NULL) {
        int tmp = curr->val;
        curr->val = curr->next->val;
        curr->next->val = tmp;
        
        curr = curr->next->next;
    }
    return head;
}

void insert(struct ListNode **head, int val)
{
    struct ListNode *curr = NULL;

    if (*head == NULL) {
        *head = malloc(sizeof(struct ListNode)); 
        (*head)->val = val;
        (*head)->next = NULL;
        return;
    }

    curr = *head;
    while (curr != NULL) {
        if (curr->next == NULL)
            break;

        curr = curr->next; 
    }

    struct ListNode *tmp = malloc(sizeof(struct ListNode));
    tmp->val = val;
    tmp->next = NULL;

    curr->next = tmp;
}

void printList(struct ListNode *head)
{
    int i = 0;
    struct ListNode *curr = NULL;
    curr = head;

    printf("[");

    printf("%d", curr->val);

    curr = curr->next;
    while (curr != NULL) {
        printf(",%d", curr->val); 
        i++;
        curr = curr->next;
    } 

    printf("]\n");
}

int main(void)
{
    struct ListNode *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printList(head);

    swapPairs(head);

    printList(head);

    return 0;
}
