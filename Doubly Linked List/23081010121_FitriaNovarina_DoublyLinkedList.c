#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	int data;
    struct node *right;
    struct node *left;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahTengah (node **head);
void tambahAkhir (node **head); //fungsi 1
void tranverse(node *head);
void hapusAwal (node **head); //fungsi 2
void hapusTengah (node **head); //fungsi 3
void hapusAkhir (node **head); //fungsi 4
void cariData (node **head); //fungsi 5
void jumlahData (node **head); //fungsi 6
void totalData (node **head); //fungsi 7

//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal list\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir list\n");
     printf("4. cetak isi list\n");
     printf("5. hapus data di awal list\n");
     printf("6. hapus data di tengah list\n");
     printf("7. hapus data di akhir list\n");
     printf("8. cari data di dalam list\n");
     printf("9. jumlah data di dalam list\n");
     printf("0. hasil penjumlahan semua data dalam list\n");
     printf("MASUKKAN PILIHAN (tekan k untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == '2')
			tambahTengah(&head);
     else if (pilih == '3')
			tambahAkhir(&head);      
     else if (pilih == '4'){
     		tranverse(head);
         getch();
     }
     else if (pilih == '5')
			hapusAwal(&head);  
     else if (pilih == '6')
			hapusTengah(&head); 
     else if (pilih == '7')
			hapusAkhir(&head);   
     else if (pilih == '8')
			cariData(&head);  
     else if (pilih == '9')
			jumlahData(&head);  
     else if (pilih == '0')
			totalData(&head);  
    
  } while (pilih != 'k');
  
  return 0;
}


//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================
// menambah data di awal list

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = *head; 
        pNew->left = NULL;   

        if (*head != NULL) {
            (*head)->left = pNew;
        }
        *head = pNew;
        
        printf("Data berhasil ditambahkan di awal list\n");
        getch();
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}


//========================================================
// menambah data di tengah list

void tambahTengah(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> right;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nNode tidak ditemukan");
     getch();
  } else{
     if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = pCur->right; 
        pNew->left = pCur;   

        if (pCur->right != NULL) {
            pCur->right->left = pNew;
        }
        pCur->right = pNew;
        
        printf("Data berhasil ditambahkan di tengah list\n");
        getch();
    } else {
     printf("\nAlokasi memeori gagal");
     getch();
  }
  
}
}

//========================================================
//menambah data di akhir list
void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan sebuah bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node*)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = NULL;
        pNew->left = NULL;

        if (*head == NULL)
        {
            *head = pNew;
        }else{
            pCur = *head;
            while (pCur -> right != NULL)
            {
                pCur = pCur -> right;
            }
        pCur -> right = pNew;
        pNew -> left = pCur;
        printf("Data berhasil ditambahkan di akhir list\n");
        getch();
        }
    }else{
        printf("\nAlokasi memori gagal");
        getch();
    }
}

//========================================================
//cetak isi list
void tranverse(node *head){
	node *pWalker = head;

   system("cls");
   
    if (pWalker == NULL) {
        printf("List kosong.");
    } else {
        while (pWalker != NULL) {
            printf("%d <-> ", pWalker->data);
            pWalker = pWalker->right;
        }
        printf("NULL");
    }
}
//========================================================
//hapus data awal

void hapusAwal(node **head){
    node *pcur;\
    system("cls");
    if (*head == NULL)
    {
        printf("List kosong\n");
    } else {
        pcur=*head;
        *head=(*head)->right;

        if (*head != NULL){
            (*head)->left = NULL;
        }
        free(pcur);
        printf("\nData berhasil dihapus");
        getch();
    }
    
}
//========================================================
//hapus data tengah

void hapusTengah(node **head){
    int bil;
    node *pCur;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan nilai yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur=*head;
    while (pCur != NULL && pCur->data !=bil)
    {
        pCur=pCur->right;
    }
    if (pCur == NULL){
        printf("\nData tidak ditemukan");
    } else{
        if(pCur==*head){
            hapusAwal(head);
        } else {
            if (pCur->right != NULL) {
                pCur->right->left = pCur->left;
            }
            if (pCur->left != NULL) {
                pCur->left->right = pCur->right;
            }
        }
    free(pCur);
    printf("\nData berhasil dihapus");
    getch();
}
}
//========================================================
//hapus data akhir

void hapusAkhir(node **head){
    node *pCur;
    system("cls");

    if (*head == NULL){
        printf("\nList kosong, tidak ada nilai yang dihapus");
    } else if ((*head)->right ==NULL){
        free(*head);
        *head=NULL;
        printf("Data berhasil dihapus");
    } else {
        pCur =*head;
        while (pCur->right !=NULL){
            pCur=pCur->right;
        }
        pCur->left->right=NULL;
        free(pCur);
        printf("\nData berhasil dihapus");
        getch();
    }
}
//========================================================
//Cari data 

void cariData(node **head){
    int target, index=0;
    node *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan nilai yang dicari: ");
    fflush(stdin);
    scanf("%d", &target);

   pCur = *head;

   while (pCur != NULL )
   {
      if(pCur->data == target){
         printf("\nData %d ditemukan pada index : %d ", target, index=0);
         return;
      }

      pCur= pCur->right;
      index++;
      
   }

   printf("\nData tidak ditemukan");
   getch();

}
//========================================================
//jumlah data 
void jumlahData(node **head){
   int count = 0;
   node *pcur;
   system ("cls");

   if (*head == NULL)
   {
     printf("\nList kosong");
     getch();
     return;
   }

   pcur= *head;
   

   while (pcur != NULL)
   {
      count++;
      pcur=pcur->right;
   }

   printf("Jumlah data dalam list adalah %d ", count);
   getch();  
}

//========================================================
//Total data 

void totalData(node **head){
   int total = 0;
   node *pCur = *head;
   system("cls");

    if (*head == NULL)
   {
      printf("\nList kosong");
      getch();
   }

   pCur = *head;

   while (pCur != NULL)
   {
      total += pCur->data;
      pCur= pCur->right;
   }

   printf("Total penjumlahan data dalam list adalah %d ", total);
   getch(); 
}

