#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Structure Definitions
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

struct queue
{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

// Function Implementations

queue createQueue(void)
{
    queue myQueue;
    myQueue.count = 0;
    myQueue.front = NULL;
    myQueue.rear = NULL;
    return myQueue;
}

void enqueue(int data, queue *myQueue)
{
    if (myQueue->count >= 10)
    {
        printf("Operation enqueue failed. Queue is full.\n");
    }
    else
    {
        node *newPtr;
        newPtr = (node *)malloc(sizeof(node));
        newPtr->data = data;
        newPtr->next = NULL;
        if (myQueue->front == NULL)
        {
            myQueue->front = newPtr;
        }
        else
        {
            myQueue->rear->next = newPtr;
        }
        myQueue->rear = newPtr;
        myQueue->count++;
    }
}

node *createNode(void)
{
    node *newPtr;
    newPtr = (node *)malloc(sizeof(newPtr));
    return newPtr;
}

void dequeue(queue *myQueue)
{
    if (myQueue->count == 0)
    {
        printf("\nQueue is Empty!\n");
    }
    else
    {
        node *dltPtr;
        dltPtr = myQueue->front;
        printf("\nElement dequeued: %d\n", dltPtr->data);
        myQueue->front = myQueue->front->next;
        free(dltPtr);
        myQueue->count--;
    }
}

void destroy(queue *myQueue)
{
    node *temp;
    while (myQueue->count != 0)
    {
        temp = myQueue->front;
        myQueue->front = myQueue->front->next;
        myQueue->count--;
        free(temp);
    }
    myQueue->count = 0;
    myQueue->front = NULL;
    myQueue->rear = NULL;
}

void display(queue myQueue)
{
    node *temp;
    temp = myQueue.front;
    printf("Queue elements from front to rear:\n");
    while (temp)
    {
        printf("%4d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void queueFront(queue myQueue)
{
    if (myQueue.count == 0)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element: %d\n", myQueue.front->data);
    }
}

void queueRear(queue myQueue)
{
    if (myQueue.count == 0)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Rear element: %d\n", myQueue.rear->data);
    }
}

void isEmptyQueue(queue myQueue)
{
    if (myQueue.count == 0)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }
}

void isFullQueue(queue myQueue)
{
    if (myQueue.count >= 10)
    {
        printf("Queue is full.\n");
    }
    else
    {
        printf("Queue is not full.\n");
    }
}

void queueCount(queue myQueue)
{
    printf("Queue count: %d\n", myQueue.count);
}

// Main Function
int main()
{
    int choice, num;
    queue myQueue;

    myQueue = createQueue();
    while (1)
    {
        system("cls");
        printf("\n-----QUEUE MENU-----\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display Queue");
        printf("\n4. Queue Front");
        printf("\n5. Queue Rear");
        printf("\n6. Check if Queue is Empty");
        printf("\n7. Check if Queue is Full");
        printf("\n8. Queue Count");
        printf("\n9. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            printf("\nElement to be enqueued: ");
            scanf("%d", &num);
            enqueue(num, &myQueue);
            getch();
            break;
        case 2:
            dequeue(&myQueue);
            getch();
            break;
        case 3:
            display(myQueue);
            getch();
            break;
        case 4:
            queueFront(myQueue);
            getch();
            break;
        case 5:
            queueRear(myQueue);
            getch();
            break;
        case 6:
            isEmptyQueue(myQueue);
            getch();
            break;
        case 7:
            isFullQueue(myQueue);
            getch();
            break;
        case 8:
            queueCount(myQueue);
            getch();
            break;
        case 9:
            destroy(&myQueue);
            exit(1);
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }

    return 0;
}
