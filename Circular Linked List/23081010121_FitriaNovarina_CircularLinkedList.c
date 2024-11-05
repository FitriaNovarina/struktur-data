#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};
typedef struct node node;

int main()
{
    node *head;
    int pilih;

    head = NULL;
    do
    {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal list\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir list\n"); // fungsi 1
        printf("4. Cetak isi list\n");
        printf("5. Hapus data di awal list\n");
        printf("6. Hapus data di tengah list\n");
        printf("7. Hapus data di akhir list\n");
        printf("8. Cari data di dalam list\n");
        printf("9. Jumlah data di dalam list\n");
        printf("10. Hasil penjumlahan semua data dalam list\n");

        printf("MASUKKAN PILIHAN (tekan k untuk keluar) : ");
        fflush(stdin);
        scanf("%d", &pilih);
        if (pilih == 1)
            tambahAwal(&head);
        else if (pilih == 2)
            tambahTengah(&head);
        else if (pilih == 3)
            tambahAkhir(&head);
        else if (pilih == 4)
        {
            tranverse(head);
            getch();
        }
        else if (pilih == 5)
            hapusAwal(&head);
        else if (pilih == 6)
            hapusTengah(&head);
        else if (pilih == 7)
            hapusAkhir(&head);
        else if (pilih == 8)
            cariData(&head);
        else if (pilih == 9)
            jumlahData(&head);
        else if (pilih == 10)
            totalData(&head);

    } while (pilih != 0);

    return 0;
}

//========================================================

void tambahAwal(node **head)
{
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = bil;
        if (*head == NULL)
        {
            pNew->next = pNew; // Mengarah ke dirinya sendiri
            *head = pNew;
        }
        else
        {
            node *pCur = *head;
            // Mencari node terakhir
            while (pCur->next != *head)
            {
                pCur = pCur->next;
            }
            pNew->next = *head;
            pCur->next = pNew;
            *head = pNew;
        }
        printf("Node dengan data %d berhasil ditambahkan di awal\n", bil);
    }
    else
    {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahTengah(node **head)
{
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    scanf("%d", &pos);
    printf("Bilangan : ");
    scanf("%d", &bil);

    if (*head == NULL)
    {
        printf("\nList kosong. Menambahkan sebagai node pertama.");
        tambahAwal(head);
        return;
    }

    pCur = *head;
    do
    {
        if (pCur->data == pos)
        {
            break;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur->data != pos)
    {
        printf("\nNode tidak ditemukan");
        getch();
        return;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL)
    {
        printf("\nAlokasi memori gagal");
        getch();
        return;
    }

    pNew->data = bil;
    pNew->next = pCur->next;
    pCur->next = pNew;

    printf("\nData berhasil ditambahkan");
    getch();
}
//========================================================
// Menambah data di akhir list

void tambahAkhir(node **head)
{
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan sebuah bilangan : ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL)
    {
        pNew->data = bil;
        if (*head == NULL)
        {
            pNew->next = pNew; // Mengarah ke dirinya sendiri
            *head = pNew;
        }
        else
        {
            pCur = *head;
            // Mencari node terakhir
            while (pCur->next != *head)
            {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *head;
        }
        printf("\nData berhasil ditambahkan di akhir");
    }
    else
    {
        printf("\nAlokasi memori gagal");
    }
    getch();
}

//========================================================
// Cetak Isi List
void tranverse(node *head)
{
    // Traverse a circular linked list
    node *pWalker;

    system("cls");
    if (head == NULL)
    {
        printf("List kosong");
        return;
    }

    pWalker = head;
    do
    {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("( kembali ke head )\n");
}

//========================================================
// Hapus data awal
void hapusAwal(node **head)
{
    node *pCur, *pLast;
    system("cls");

    if (*head == NULL)
    {
        printf("List kosong\n");
        getch();
        return;
    }

    if ((*head)->next == *head)
    {
        // Hanya ada satu node
        free(*head);
        *head = NULL;
    }
    else
    {
        pCur = *head;
        // Mencari node terakhir
        while (pCur->next != *head)
        {
            pCur = pCur->next;
        }
        pLast = pCur;
        pCur = *head;
        *head = (*head)->next;
        pLast->next = *head;
        free(pCur);
    }

    printf("\nData berhasil dihapus dari awal");
    getch();
}

//========================================================
// Hapus data tengah
void hapusTengah(node **head)
{
    int bil;
    node *pCur, *ppre;

    system("cls");
    tranverse(*head);
    printf("\nBilangan yang ingin dihapus: ");
    scanf("%d", &bil);

    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
        return;
    }

    pCur = *head;
    ppre = NULL;
    do
    {
        if (pCur->data == bil)
        {
            break;
        }
        ppre = pCur;
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur->data != bil)
    {
        printf("\nData tidak ditemukan");
        getch();
        return;
    }

    if (ppre == NULL)
    {
        // Menghapus node head
        hapusAwal(head);
    }
    else
    {
        // Menghapus node di tengah atau akhir
        ppre->next = pCur->next;
        if (pCur == *head)
        {
            *head = ppre->next;
        }
        free(pCur);
        printf("\nData berhasil dihapus");
        getch();
    }
}

//========================================================
// Hapus data akhir

void hapusAkhir(node **head)
{
    node *pCur, *ppre;
    system("cls");

    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
        return;
    }

    if ((*head)->next == *head)
    {
        // Hanya ada satu node
        free(*head);
        *head = NULL;
        printf("\nData berhasil dihapus dari akhir (list kosong)");
        getch();
        return;
    }

    pCur = *head;
    ppre = NULL;
    while (pCur->next != *head)
    {
        ppre = pCur;
        pCur = pCur->next;
    }

    ppre->next = *head;
    free(pCur);
    printf("\nData berhasil dihapus dari akhir");
    getch();
}

//========================================================
// Cari data

void cariData(node **head)
{
    int target, index = 0;
    node *pCur;

    system("cls");
    printf("Masukkan angka yang dicari: ");
    scanf("%d", &target);

    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
        return;
    }

    pCur = *head;
    system("cls");
    do
    {
        if (pCur->data == target)
        {
            printf("\nData %d ditemukan pada index : %d", target, index);
            getch();
            return;
        }
        pCur = pCur->next;
        index++;
    } while (pCur != *head);

    printf("\nData tidak ditemukan");
    getch();
}

//========================================================
// Jumlah data
void jumlahData(node **head)
{
    int count = 0;
    node *pCur;

    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
        return;
    }

    pCur = *head;
    system("cls");
    do
    {
        count++;
        pCur = pCur->next;
    } while (pCur != *head);

    printf("Jumlah data dalam list adalah %d", count);
    getch();
}

//========================================================
// Total data

void totalData(node **head)
{
    int total = 0; // Inisialisasi total
    node *pCur;

    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
        return;
    }

    pCur = *head;
    system("cls");
    do
    {
        total += pCur->data;
        pCur = pCur->next;
    } while (pCur != *head);

    printf("Total penjumlahan data dalam list adalah %d", total);
    getch();
}
