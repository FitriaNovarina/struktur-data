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
        printf("Operasi enqueue gagal. Antrian penuh.\n");
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
        printf("\nAntrian kosong!\n");
    }
    else
    {
        node *dltPtr;
        dltPtr = myQueue->front;
        printf("\nElemen yang dikeluarkan: %d\n", dltPtr->data);
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
    printf("Elemen antrian dari depan ke belakang:\n");
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
        printf("Antrian kosong.\n");
    }
    else
    {
        printf("Elemen depan: %d\n", myQueue.front->data);
    }
}

void queueRear(queue myQueue)
{
    if (myQueue.count == 0)
    {
        printf("Antrian kosong.\n");
    }
    else
    {
        printf("Elemen belakang: %d\n", myQueue.rear->data);
    }
}

void isEmptyQueue(queue myQueue)
{
    if (myQueue.count == 0)
    {
        printf("Antrian kosong.\n");
    }
    else
    {
        printf("Antrian tidak kosong.\n");
    }
}

void isFullQueue(queue myQueue)
{
    if (myQueue.count >= 10)
    {
        printf("Antrian penuh.\n");
    }
    else
    {
        printf("Antrian tidak penuh.\n");
    }
}

void queueCount(queue myQueue)
{
    printf("Jumlah elemen dalam antrian: %d\n", myQueue.count);
}

// Main Function
int main()
{
    int pilih, num;
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
        scanf("%d", &pilih);
        printf("\n\n");

        if (pilih == 1)
        {
            printf("\nElemen yang akan dimasukkan: ");
            scanf("%d", &num);
            enqueue(num, &myQueue);
            getch();
        }
        else if (pilih == 2)
        {
            dequeue(&myQueue);
            getch();
        }
        else if (pilih == 3)
        {
            display(myQueue);
            getch();
        }
        else if (pilih == 4)
        {
            queueFront(myQueue);
            getch();
        }
        else if (pilih == 5)
        {
            queueRear(myQueue);
            getch();
        }
        else if (pilih == 6)
        {
            isEmptyQueue(myQueue);
            getch();
        }
        else if (pilih == 7)
        {
            isFullQueue(myQueue);
            getch();
        }
        else if (pilih == 8)
        {
            queueCount(myQueue);
            getch();
        }
        else if (pilih == 9)
        {
            destroy(&myQueue);
            exit(1);
        }
        else
        {
            printf("\nPilihan tidak valid\n");
        }
    }

    return 0;
}
