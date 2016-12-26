// This prompts the user for input twice. I haven't fixed the bug

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

void insertInLinkedList(struct ListNode **head, int data, int position);
void deleteFromLinkedList(struct ListNode **head, int position);
void freememory(struct ListNode **head);
void printList(struct ListNode **head);


int main()
{
    printf("i for insert, d for delete and p for printing the linked list\n");

    char command;

    ListNode **head;
    *head = (ListNode*) malloc(sizeof(ListNode));
    do
    {
        printf("Please enter a command: ");
        scanf("%c", &command);
        int data, position;

        if (command == 'i')
        {
            printf("Integer to add to the list followed by the position: ");
            scanf("%d %d", &data, &position);
            insertInLinkedList(head, data, position);

        }
        else if (command == 'd')
        {
            printf("Slot to be deleted: ");
            scanf("%d", &position);
            deleteFromLinkedList(head, position);
            
        }
        else if (command == 'p')
        {
            printf("\n\n");
            printf("Here's the list:-\n");
            printList(head);
            printf("\n\n");
        }

    } while (command != 'q');

    printf("Freeing memory");
    freememory(head);


    printf("Closing Program");
    return 0;
}

void insertInLinkedList(struct ListNode **head, int data, int position)
{
    int k = 1;
    struct ListNode *p, *q, *newnode;

    newnode = (ListNode*)malloc(sizeof(struct ListNode));

    newnode->data = data;
    p = *head;

    if (position == 1)
    {
        newnode->next = p;
        *head = newnode;
    }
    else 
    {
        while ((p != NULL) && (k < position))
        {
            q = p;
            p = p->next;
            k++;
        }
        q->next = newnode;
        newnode->next = p;
    }
}

void deleteFromLinkedList(struct ListNode ** head, int position)
{
    int k = 1; // can be done much later in the code as well
    ListNode *p, *q;
    p = *head;

    if (position == 1)
    {
        *head = p->next;
        free(p);

        return; // not returning anything and signalling the end of the function

    }
    else
    {
        while ((p != NULL) && (k < position))
        {
            q = p;
            p = p->next;
            k++;
        }

        // Different treatment if it's the last element
        if (p->next == NULL)
        {
            free(p);
            q->next = NULL;

        }
        else
        {
            q->next = p->next;
            free(p);
        }

    }
}

void freememory(ListNode **head)
{
    ListNode *p, *q;
    p = *head;

    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }

}

void printList(ListNode **head)
{
    ListNode *p;
    p = *head;

    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
