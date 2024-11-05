#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_MAHASISWA 20 

struct node {
    char nama[50];
    char jenisKelamin;
    struct node *next;
};
typedef struct node node;

void tambah(node **head);
void hapus(node **head);
void tampilkanDataBerdasarkanJK(node *head, char jk);
void traverseUtama(node *head);
int hitungJumlahPerempuan(node *head); 

int jumlahMahasiswa = 0; 

int main() {
    node *head;
    char pilih;

    head = NULL;
    do {
        system("cls");
        printf("1. Tambah data\n");
        printf("2. Hapus data\n");
        printf("3. Cetak isi list\n");
        printf("4. Cetak isi list lingkaran Mahasiswa\n");
        printf("5. Cetak isi list lingkaran Mahasiswi\n");
        printf("MASUKKAN PILIHAN (tekan k untuk keluar) : ");
        fflush(stdin); 
        scanf(" %c", &pilih); 

        if (pilih == '1')
            tambah(&head);
        else if (pilih == '2')
            hapus(&head);
        else if (pilih == '3'){
            traverseUtama(head);
            getch();
        }
        else if (pilih == '4'){
            tampilkanDataBerdasarkanJK(head, 'L');
            getch();
        }
        else if (pilih == '5'){
            tampilkanDataBerdasarkanJK(head, 'P');
            getch();
        }
    } while (pilih != 'k');

    return 0;
}

void tambah(node **head) {
    char nama[50];
    char jenisKelamin;
    
    if (jumlahMahasiswa >= MAX_MAHASISWA) {
        printf("Jumlah mahasiswa/i telah mencapai batas maksimum (%d).\n", MAX_MAHASISWA);
        getch();
        return;
    }
    
    node *pList = (node *)malloc(sizeof(node));
    node *temp = *head;

    system("cls");
    printf("Masukkan nama mahasiswa/i (Tulis awalan kapital): ");
    fflush(stdin); 
    scanf("%s", nama);
    printf("Masukkan jenis kelamin (L untuk laki-laki || P untuk perempuan): ");
    fflush(stdin); 
    scanf(" %c", &jenisKelamin); 

    if (jenisKelamin == 'L' || jenisKelamin == 'l' || jenisKelamin == 'P' || jenisKelamin == 'p') {
        strcpy(pList->nama, nama);
        pList->jenisKelamin = jenisKelamin;

        if (strcmp(nama, "Irsyad") == 0 || strcmp(nama, "Arsyad") == 0) {
            
            if (jumlahMahasiswa >= 2) {
                printf("Irsyad dan Arsyad selalu bersama dan tidak bisa dipisahkan.\n");
                free(pList);
                getch();
                return;
            }
        }

        if (jenisKelamin == 'P' && strcmp(nama, "Cindy") == 0) {
            int jumlahPerempuan = hitungJumlahPerempuan(*head);
            if (jumlahPerempuan < 1) { 
                printf("Karena tidak ada perempuan di dalam lingkaran, Cindy tidak bergabung dalam api unggun.\n");
                free(pList);
                getch();
                return;
            }
        }

        if (*head == NULL) {
            *head = pList;
            pList->next = *head;
        } else {
            if (jenisKelamin == 'L' || jenisKelamin == 'l') {
                pList->next = *head;
                temp = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }
                temp->next = pList;
                *head = pList;
            } else {
                temp = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }
                temp->next = pList;
                pList->next = *head;
            }
        }
        jumlahMahasiswa++; 
    } else {
        printf("Jenis kelamin tidak valid. Gunakan 'L' untuk laki-laki atau 'P' untuk perempuan.\n");
        free(pList);
    }
}

void hapus(node **head) {
    system("cls");
    char nama[50];
    
    if (*head == NULL) { 
        printf("Tidak terdapat mahasiswa atau mahasiswi yang mengikuti camping\n");
        getch();
        return;
    }

    printf("Masukkan nama mahasiswa/i yang ingin dihapus: ");
    fflush(stdin);
    scanf("%s", nama);

    node *pWalker = *head;
    node *prev = NULL;
    int found = 0;

    do {
        if (strcmp(pWalker->nama, nama) == 0) {
            found = 1;
            break;
        }
        prev = pWalker;
        pWalker = pWalker->next;
    } while (pWalker != *head);

    if (!found) {
        printf("Nama mahasiswa/i tidak ditemukan dalam list.\n");
        getch();
        return;
    }

    if (prev) {
        prev->next = pWalker->next;
    } else {
        node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = pWalker->next; 
        *head = pWalker->next; 
    }

    if (pWalker->jenisKelamin == 'P') {
        node *cindyWalker = *head;
        node *prevCindy = NULL;
        int foundCindy = 0;
        
        do {
            if (strcmp(cindyWalker->nama, "Cindy") == 0) {
                foundCindy = 1;
                break;
            }
            prevCindy = cindyWalker;
            cindyWalker = cindyWalker->next;
        } while (cindyWalker != *head);

        if (foundCindy) {
            if (prevCindy) {
                prevCindy->next = cindyWalker->next; 
            } else {
                node *temp = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }
                temp->next = cindyWalker->next; 
                *head = cindyWalker->next; 
            }
            printf("Cindy juga ikut keluar karena mahasiswi lain sudah keluar.\n");
            free(cindyWalker);
            jumlahMahasiswa--; 
        }
    }

    printf("Mahasiswa/i bernama %s telah keluar dari api unggun.\n", pWalker->nama);
    free(pWalker);
    
    getch();
    jumlahMahasiswa--; 
}

void traverseUtama(node *head) {
    node *pWalker;

    system("cls");
    pWalker = head;

    if (head == NULL) {
        printf("Tidak terdapat mahasiswa atau mahasiswi yang mengikuti camping\n");
        return;
    } else {
        printf("Acara camping dimulai, para mahasiswa serta mahasiswi berkumpul untuk merayakan api unggun bersama.\n");
        do {
            printf("%s, dengan Jenis Kelamin %c sedang bernyanyi, dilanjutkan oleh: %s\n", 
                pWalker->nama, pWalker->jenisKelamin, pWalker->next->nama);
            pWalker = pWalker->next;
        } while (pWalker != head);
        printf("Acara camping telah berakhir, para mahasiswa serta mahasiswi kembali ke tenda masing-masing\n");
    }
}

void tampilkanDataBerdasarkanJK(node *head, char jk) {
    node *pWalker = head;

    system("cls");
    if (head == NULL) {
        printf("Tidak terdapat mahasiswa atau mahasiswi yang mengikuti camping\n");
        return;
    }

    printf("Mahasiswa yang berada dalam lingkaran api unggun %c:\n", jk);
    do {
        if (pWalker->jenisKelamin == jk) {
            printf("%s\n", pWalker->nama);
        }
        pWalker = pWalker->next;
    } while (pWalker != head);
}

int hitungJumlahPerempuan(node *head) {
    int count = 0;
    node *pWalker = head;

    if (head == NULL) {
        return count;
    }

    do {
        if (pWalker->jenisKelamin == 'P') {
            count++;
        }
        pWalker = pWalker->next;
    } while (pWalker != head);

    return count;
}


