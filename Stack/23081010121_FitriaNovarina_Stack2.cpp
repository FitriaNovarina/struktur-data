#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    int count;
    struct Node *top;
} Stack;

Stack stack;

void createStack(int size)
{
    stack.count = 0;
    stack.top = NULL;
}

bool emptyStack()
{
    return stack.top == NULL;
}

void push(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = stack.top;
    stack.top = newNode;
    stack.count++;
}

int pop()
{
    if (!emptyStack())
    {
        Node *dltPtr = stack.top;
        int value = dltPtr->data;
        stack.top = stack.top->next;
        stack.count--;
        free(dltPtr);
        return value;
    }
    return -1;
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

int isValidExpression(const char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];
        if (ch == '(')
        {
            push('(');
        }
        else if (ch == ')')
        {
            if (emptyStack())
            {
                return 0;
            }
            pop();
        }
    }
    return emptyStack();
}

void infixToPostfix(char *infix, char *postfix)
{
    int i, k = 0;
    createStack(100);
    for (i = 0; infix[i]; i++)
    {
        if (isdigit(infix[i]))
        {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!emptyStack() && stack.top->data != '(')
            {
                postfix[k++] = pop();
            }
            pop();
        }
        else if (isOperator(infix[i]))
        {

            while (!emptyStack() &&
                   (precedence(stack.top->data) > precedence(infix[i]) ||
                    (precedence(stack.top->data) == precedence(infix[i]) && infix[i] != '^')))
            {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    while (!emptyStack())
    {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int evaluasiPostfix(char *postfix)
{
    for (int i = 0; postfix[i]; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else if (isOperator(postfix[i]))
        {
            int operand2 = pop();
            int operand1 = pop();

            if (postfix[i] == '+')
            {
                push(operand1 + operand2);
            }
            else if (postfix[i] == '-')
            {
                push(operand1 - operand2);
            }
            else if (postfix[i] == '*')
            {
                push(operand1 * operand2);
            }
            else if (postfix[i] == '/')
            {
                push(operand1 / operand2);
            }
            else if (postfix[i] == '^')
            {
                push((int)pow(operand1, operand2));
            }
        }
    }
    return pop();
}

int main()
{
    char infix[100], postfix[100];

    system("cls");
    printf("Masukkan Ekspresi Infix: ");
    scanf("%s", infix);

    if (isValidExpression(infix))
    {
        infixToPostfix(infix, postfix);
        printf("Bentuk Ekspresi Postfix: %s\n", postfix);

        int result = evaluasiPostfix(postfix);
        printf("Hasil Evaluasi Postfix: %d\n", result);
    }
    else
    {
        printf("Ekspresi tidak valid!\n");
    }

    return 0;
}
