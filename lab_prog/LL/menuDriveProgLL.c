
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Insert at beginning
struct Node *insertHead(struct Node *head, int item)
{
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
        return head;

    temp->data = item;
    temp->next = head;

    return temp;
}

// Convert array to linked list
struct Node *convertArrToLL()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 0 || n > 100)
    {
        printf("Invalid size!\n");
        return NULL;
    }

    int arr[100];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    struct Node *head = NULL;

    for (int i = n - 1; i >= 0; i--)
    {
        head = insertHead(head, arr[i]);
    }

    return head;
}

// Insert at end
struct Node *insertTail(struct Node *head, int item)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return head;

    newNode->data = item;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

// Display linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
    printf("\n");
}

// Free allocated memory
void freeList(struct Node *head)
{
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    int choice, num;

    do
    {
        printf("1. Create Linked List\n");
        printf("2. Insert at Head\n");
        printf("3. Insert at Tail\n");
        printf("4. Display Linked List\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            freeList(head);
            head = convertArrToLL();
            break;

        case 2:
            printf("Enter the element: ");
            scanf("%d", &num);

            head = insertHead(head, num);
            break;

        case 3:
            printf("Enter the element: ");
            scanf("%d", &num);

            head = insertTail(head, num);
            break;

        case 4:
            display(head);
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    freeList(head);

    return 0;
}
