#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createLL()
{
    struct Node *start = NULL;
    struct Node *temp;
    struct Node *nodeItem;
    int n;
    printf("Enter the number of terms you want:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        nodeItem = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the number: ");
        scanf("%d", &nodeItem->data);
        nodeItem->next = NULL;
        if (start == NULL)
        {
            start = nodeItem;
        }
        else
        {
            temp->next = nodeItem;
        }
        temp = nodeItem;
    }
    return start;
}

struct Node *rev(struct Node *start)
{
    struct Node *prev = NULL;
    struct Node *curr = start;
    struct Node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node *concatenate(struct Node *start1, struct Node *start2)
{
    struct Node *temp = start1;
    if (start1 == NULL)
    {
        return start2;
    }
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = start2;
    return start1;
}

void sort(struct Node *start)
{
    struct Node *i, *j;
    for (i = start; i != NULL; i = i->next)
    {
        for (j = start->next; i != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void display(struct Node *start)
{
    struct Node *temp = start;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *start = NULL;
    struct Node *start1 = NULL;
    struct Node *start2 = NULL;
    int choice;

    do
    {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Reverse Linked List\n");
        printf("4. Concatenate Two Linked Lists\n");
        printf("5. Sort Linked List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                start = createLL();
                break;

            case 2:
                display(start);
                break;

            case 3:
                start = rev(start);
                printf("Linked List Reversed Successfully!\n");
                break;

            case 4:
                printf("Create First Linked List:\n");
                start1 = createLL();

                printf("Create Second Linked List:\n");
                start2 = createLL();

                start = concatenate(start1, start2);
                printf("Linked Lists Concatenated!\n");
                break;

            case 5:
                sort(start);
                printf("Linked List Sorted!\n");
                break;

            case 6:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}
