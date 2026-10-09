#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void insert()
{
    int x;

    if ((rear + 1) % MAX == front)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &x);

        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        q[rear] = x;
    }
}

void delete()
{
    if (front == -1)
        printf("Queue Empty\n");
    else
    {
        printf("Deleted: %d\n", q[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void display()
{
    int i;

    if (front == -1)
        printf("Queue Empty\n");
    else
    {
        i = front;
        do
        {
            printf("%d ", q[i]);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);

        printf("\n");
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
        }
    } while(ch != 4);

    return 0;
}
