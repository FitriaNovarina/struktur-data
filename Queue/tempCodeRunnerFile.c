#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

queue createQueue(void)
{
    queue myQueue;
    myQueue.count = 0;
    myQueue.front = NULL;
    myQueue.rear = NULL;
    return myQueue;
}

int enqueue(int data, queue *myQueue)
{
    if (myQueue->count >= 5)
    {
        return 0; // Queue is full
    }
    else
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;

        if (myQueue->front == NULL)
        {
            myQueue->front = newNode;
        }
        else
        {
            myQueue->rear->next = newNode;
        }
        myQueue->rear = newNode;
        myQueue->count++;
        return 1;
    }
}

void dequeue(queue *myQueue)
{
    if (myQueue->count == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        node *temp = myQueue->front;
        int dequeuedValue = temp->data;
        myQueue->front = myQueue->front->next;
        free(temp);
        myQueue->count--;
        printf("Dequeued element: %d\n", dequeuedValue);
    }
}

int queueFront(queue myQueue)
{
    if (myQueue.count == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return myQueue.front->data;
    }
}

int queueRear(queue myQueue)
{
    if (myQueue.count == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return myQueue.rear->data;
    }
}

int emptyQueue(queue myQueue)
{
    return myQueue.count == 0;
}

int fullQueue(queue myQueue)
{
    return myQueue.count >= 10;
}

int queueCount(queue myQueue)
{
    return myQueue.count;
}

void destroy(queue *myQueue)
{
    node *temp;
    while (myQueue->count > 0)
    {
        temp = myQueue->front;
        myQueue->front = myQueue->front->next;
        free(temp);
        myQueue->count--;
    }
    myQueue->front = NULL;
    myQueue->rear = NULL;
}

void display(queue myQueue)
{
    if (myQueue.count == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        node *temp = myQueue.front;
        printf("Queue elements: ");
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, num, success;
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
        printf("\n9. Destroy Queue");
        printf("\n10. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n\n");

        if (choice == 1)
        {
            printf("\nElement to be enqueued: ");
            scanf("%d", &num);
            success = enqueue(num, &myQueue);
            if (success == 0)
            {
                printf("Enqueue operation failed\n");
            }
            else
            {
                printf("Element %d enqueued\n", num);
            }
            getch();
        }
        else if (choice == 2)
        {
            dequeue(&myQueue);
            getch();
        }
        else if (choice == 3)
        {
            display(myQueue);
            getch();
        }
        else if (choice == 4)
        {
            printf("Queue Front: %d\n", queueFront(myQueue));
            getch();
        }
        else if (choice == 5)
        {
            printf("Queue Rear: %d\n", queueRear(myQueue));
            getch();
        }
        else if (choice == 6)
        {
            if (emptyQueue(myQueue))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            getch();
        }
        else if (choice == 7)
        {
            if (fullQueue(myQueue))
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
            getch();
        }
        else if (choice == 8)
        {
            printf("Queue count: %d\n", queueCount(myQueue));
            getch();
        }
        else if (choice == 9)
        {
            destroy(&myQueue);
            printf("Queue destroyed\n");
            getch();
        }
        else if (choice == 10)
        {
            destroy(&myQueue);
            exit(0);
        }
        else
        {
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}
