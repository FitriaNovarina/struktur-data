#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	int data;
    struct node *next;
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
     printf("10. hasil penjumlahan semua data dalam list\n");
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

void tambahAwal(node **head){
  int bil;
  node *pNew; 

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = NULL;
      //add before first logical node or to an empty list
	  pNew -> next = *head;
      *head = pNew;
  }
  else{
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
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nNode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nAlokasi memeori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}

//========================================================
//menambah data di akhir list
void tambahAkhir(node **head){
    int bil;
    node *pnew, *pcur;

    system("cls");
    fflush(stdin);
    printf("Masukkan sebuah bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pnew = (node*)malloc(sizeof(node));

    if (pnew != NULL) {
        pnew->data = bil;
        pnew->next = NULL;

        if (*head == NULL)
        {
            *head = pnew;
        }else{
            pcur = *head;
            while (pcur -> next != NULL)
            {
                pcur = pcur -> next;
            }
        pcur -> next = pnew;
        }
    }else{
        printf("\nAlokasi memori gagal");
        getch();
    }

}

//========================================================
//cetak isi list
void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d\t", pWalker -> data);
   	pWalker = pWalker -> next;
      printf(" -> ");
	}
   printf("NULL");
}
//========================================================
//hapus data awal

void hapusAwal(node **head){
    node *pcur;
    if (*head == NULL)
    {
        printf("List kosong\n");
        getch();
    }
        pcur=*head;
        *head=(*head)->next;
        free(pcur);
        printf("\nData berhasil dihapus");
        getch();
    
}
//========================================================
//hapus data tengah

void hapusTengah(node **head){
    int bil;
    node *pcur, *ppre;

    system("cls");
    tranverse(*head);
    printf("\nBilangan:");
    fflush(stdin);
    scanf("%d", &bil);

    pcur=*head;
    ppre=NULL;

    while (pcur != NULL && pcur->data !=bil)
    {
        ppre=pcur;
        pcur=pcur->next;
    }
    if (pcur == NULL)
    {
        printf("\nData tidak ditemukan");
        getch();
    }
    if(ppre == NULL)
    {
        *head = pcur->next;
    }else
    {
        ppre ->next = pcur->next;
    }
    free(pcur);
    printf("\nData berhasil dihapus");
    getch();
}
//========================================================
//hapus data akhir

void hapusAkhir(node **head){
    node *pcur, *ppre;
    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
        return;
    }
    pcur = *head;
    ppre = NULL;
    while (pcur->next != NULL)
    {
        ppre=pcur;
        pcur=pcur->next;
    }
    if(ppre == NULL)
    {
        *head = pcur->next;
    }else
    {
        ppre->next=NULL;
    }
    free(pcur);
    printf("\nData berhasil dihapus");
    getch();
}
//========================================================
//Cari data 

void cariData(node **head){
    int target, index=0;
    node *pcur, *ppre;

    system("cls");
    fflush(stdin);
    printf("Masukkan angka yang dicari: ");
    fflush(stdin);
    scanf("%d", &target);

    if (*head == NULL){
      printf("\nList kosong");
      getch();
      return;
   }

   pcur = *head;
   ppre = NULL;

   while (pcur != NULL )
   {
      if(pcur->data == target){
         printf("\nData %d ditemukan pada index : %d ", target, index);
         getch();
      }

      pcur= pcur->next;
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
      pcur=pcur->next;
   }

   printf("Jumlah data dalam list adalah %d ",count);
   getch();  
}

//========================================================
//Total data 

void totalData(node **head){
   int total;
   node *pcur;

   if (*head == NULL)
   {
      printf("\nList kosong");
      getch();
   }

   pcur = *head;

   while (pcur != NULL)
   {
      total += pcur->data;
      pcur= pcur->next;
   }

   printf("Total penjumlahan data dalam list adalah %d ", total);
   getch();
   
}

