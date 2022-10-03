#include <stdio.h>
#include <stdlib.h>

typedef char itemtype;
typedef struct queue node;
struct queue{
    itemtype data;
    int prio;
    node *next;
    int hitung;
};
node *head,*p;
node *suk, *psuk;

void inisialisasi();
int kosong(node*);
void enqu(node*);
void dequ(node*);
void show(node*);
void mallok();
void awal();
void akhir();
void tengah();

int main()
{
  node antri;
  int input;

  inisialisasi(&antri);
  puts("Menu QUEUE PRIORITAS");

  do{
    puts("\nMenu Operasi Queue SLL");
    puts("1. Enqueue");
    puts("2. Dequeue");
    puts("3. Show Queue");
    puts("4. Exit");
    printf("Masukkan pilihan Anda : ");
    scanf("%d",&input);

    if(input == 1){
        fflush(stdin);
        mallok();
        enqu(&antri);
    }
    else if(input == 2){
        fflush(stdin);
        dequ(&antri);
    }
    else if(input == 3){
        fflush(stdin);
        show(&antri);
    }else{
        puts("ARIGATOU GONZAIMASTA");
        exit(0);
    }
  }while(1);
}

void inisialisasi(node*q){
    q->hitung = 0;
}

void mallok(){
    itemtype input;
    int prio;

    printf("Masukkan data yang mau disimpan : ");
    scanf("%c",&input);

    printf("Masukkan value Prioritasnya[1/2/3] : ");
    scanf("%d",&prio);

    if(prio > 3){
        prio = 3;
        puts("prio salah default kembali ke 3");
    }

    p = (node*)malloc(sizeof(node));
    if(p == NULL){
        puts("Alokasi gagal, maaf");
        exit(0);
    }
    else{
        p->data = input;
        p->prio = prio;
        p->next = NULL;
    }
}

void enqu(node*q){
    suk = head;

    if(head == NULL){
        head = p;
    }
    else if(head->prio > p->prio){  //input prio lebih kecil dari prio di head
       awal();
    }else{
        while(p->prio >= suk->prio){
            if(suk->next != NULL){
                psuk = suk;
                suk = suk->next;    //menajalankan pointer psuk dan suk
            }else
                break;
        }
        if(suk->next == NULL){         //input dari prio sudah sampai akhir linked list
            if(suk->prio > p->prio){
                p->next = suk;
                psuk->next = p;
            }else
                akhir();
        }
        else{
            p->next = suk;
            psuk->next = p;
        }
    }
    q->hitung++;
}

int kosong(node*q){
    if(q->hitung == 0)
        return 1;
    else
        return 0;
}

void dequ(node*q){
    node *del;

    if(kosong(q))
        puts("QUEUE kosong tidak bisa hapus");
    else{
        printf("data %c dihapus",head->data);
        del = head;
        if(del->next == NULL)
            head = NULL;
        else{
            head = del->next;
            free(del);
            del = NULL;
        }
        q->hitung--;
    }
}

void show(node*q){
    node *show;

    show = head;

    if(head == NULL){
        puts("Queue Masih kosong, belum bisa menampilkan data");
    }
    else{
        puts("output isi QUEUE terurut prioritas :");
        printf("data\tprioritas poin\n");
        while(show != NULL){
            printf("%c\t%d\n",show->data,show->prio);
            show = show->next;
        }
    }
}

void awal(){
    if(head != NULL){
        p->next = head;
    }
    head = p;
}

void akhir(){
    suk->next = p;
    suk = suk->next;
}
