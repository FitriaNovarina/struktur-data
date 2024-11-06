#include <iostream>
#include <conio.h>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    int count;
    struct Node *top;
    int maxSize;
} Stack;

Stack stack;

void createStack(int size)
{
    stack.count = 0;
    stack.top = NULL;
    stack.maxSize = size;
}

bool isEmpty()
{
    return stack.count == 0;
}

bool isFull()
{
    return stack.count == stack.maxSize;
}

void push(int data)
{
    if (isFull())
    {
        cout << "Stack penuh! Tidak dapat menambah data.\n";
        return;
    }

    Node *newPtr = new Node;
    if (newPtr == NULL)
    {
        cout << "Alokasi memori gagal!";
        return;
    }
    newPtr->data = data;
    newPtr->next = stack.top;
    stack.top = newPtr;
    stack.count++;
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack kosong! Tidak ada data untuk dihapus.\n";
        return;
    }
    Node *dltPtr = stack.top;
    stack.top = stack.top->next;
    stack.count--;
    delete dltPtr;
}

void stackTop()
{
    if (isEmpty())
    {
        cout << "Stack kosong!";
        return;
    }

    cout << stack.top->data;
}

int stackCount()
{
    return stack.count;
}

void destroyStack()
{
    while (stack.top != NULL)
    {
        Node *temp = stack.top;
        stack.top = stack.top->next;
        delete temp;
    }
    stack.count = 0;
}

int main()
{
    char pilih;
    int value, size;

    system("cls");
    cout << "Masukkan jumlah maksimum stack: ";
    cin >> size;

    createStack(size);

    do
    {
        system("cls");
        cout << "Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Stack Top\n";
        cout << "4. Empty Stack\n";
        cout << "5. Full Stack\n";
        cout << "6. Stack Count\n";
        cout << "7. Destroy Stack\n";
        cout << "Masukkan pilihan (tekan k untuk keluar): ";
        cin >> pilih;

        if (pilih == '1')
        {
            system("cls");
            if (isFull())
            {
                cout << "Stack penuh! Tidak dapat menambah data.\n";
            }
            else
            {
                cout << "Masukkan nilai untuk di push: ";
                cin >> value;
                push(value);
            }
            cout << "Data " << value << " berhasil dimasukkan ke dalam stack.\n";
            getch();
        }
        else if (pilih == '2')
        {
            system("cls");
            if (!isEmpty())
            {
                cout << "Data " << stack.top->data << " berhasil dihapus dari stack.\n";
                pop();
            }
            else
            {
                cout << "Stack kosong, tidak ada data yang dapat dihapus.\n";
            }
            getch();
        }
        else if (pilih == '3')
        {
            system("cls");
            cout << "Nilai pada stack top: ";
            stackTop();
            cout << endl;
            getch();
        }
        else if (pilih == '4')
        {
            system("cls");
            if (isEmpty())
            {
                cout << "Stack kosong.\n";
            }
            else
            {
                cout << "Stack tidak kosong.\n";
            }
            getch();
        }
        else if (pilih == '5')
        {
            system("cls");
            if (isFull())
            {
                cout << "Stack sudah penuh.\n";
            }
            else
            {
                cout << "Stack belum penuh.\n";
            }
            getch();
        }
        else if (pilih == '6')
        {
            system("cls");
            cout << "Jumlah data dalam stack: " << stackCount() << endl;
            getch();
        }
        else if (pilih == '7')
        {
            system("cls");
            destroyStack();
            cout << "Seluruh data pada stack berhasil dihapus.\n";
            getch();
        }
        else if (pilih == 'k')
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Input tidak valid!\n";
            getch();
        }

    } while (pilih != 'k');

    return 0;
}
