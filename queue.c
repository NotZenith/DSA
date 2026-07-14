#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;




void enqueue(int vlaue)
{
    if (rear == SIZE - 1)
    {
        printf("Queve overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        printf("Enter the value to insert in queue: ");
        scanf("%d", &vlaue);
        queue[rear] = vlaue;
        rear++;
        printf("%d is inserted in queue", vlaue);
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("%d is deleted from queue", queue[front]);
        front++;
    }
}


void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Elements in queue are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice");
        }
    }
}

