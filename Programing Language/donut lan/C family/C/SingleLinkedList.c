#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct praktikum Node;
struct praktikum{
    int data;
    float nilai;
    char nama[MAX];
    Node *next;
};
Node *head = NULL, *p;
Node *cari;

void alokasi();
void insertdata();
void carik();
void deltentu();
void delawal();
void show();
void rata();

int main(){
    int input;
    puts("PRAKTIKUM 4 STRUCT REVIEW SLL");

    do{
        puts("\nMenu Utama : ");
        puts("1.penambahan secara urut ");
        puts("2.pencarian data");
        puts("3.penghapusan data");
        puts("4.rata-rata kelas");
        puts("5.keluar");
        printf("masukkan pilihan anda : ");
        scanf("%d", &input);

        if(input == 1){
            alokasi();
            insertdata();
            show();
        }
        else if(input == 2){
            carik();
        }
        else if(input == 3){
            deltentu();
            puts("hasil setelah penghapusan : \n");
            show();
        }
        else if(input == 4){
            rata();
        }
        else if(input == 5){
            exit(0);
        }
        else{
            puts("Anda salah input gan");
        }
  }while(1);
}

void carik(){
    int input = 0, itung = 0;

    if(head == NULL){
        puts("SLL masih kosong diisi dulu ya ");
        return 0;
    }else{
    printf("Data yang mau dicari : ");
    scanf("%d",&input);
    fflush(stdin);

    cari = head;
    while(cari != NULL){
        if(cari->data == input){
            itung++;
        }
        cari = cari->next;
    }
    if(input == 0)
        printf("data %d tidak ada di dalam SLL\n", input);
    else
        printf("data %d ketemu di sll %d kali\n",input , itung);
    }
}

void rata(){
    float tampung = 0, hasil = 0;
    int i = 0;

    if(head == NULL){
        puts("SLL masih kosong diisi dulu ya ");
        return 0;
    }else{
        cari = head;
        while(cari != NULL){
            tampung += cari->nilai;
            i++;
            cari = cari->next;
        }
        hasil = tampung / i;
        printf("hasil rata - rata adalah : %g\n", hasil);
        puts("");
    }
}

void insertdata(){
    Node *suk, *psuk;
    suk = head;

    if(head == NULL){
        head = p;
    }
    else if(head->data > p->data){
       awal();
    }else{
        while(p->data >= suk->data){
            if(suk->next != NULL){
                psuk = suk;
                suk = suk->next;
            }else
                break;
        }
        if(suk->next == NULL){
            if(suk->data > p->data){
                p->next = suk;
                psuk->next = p;
            }else{
                akhir();
            }
        }else{
            p->next = suk;
            psuk->next = p;
        }
    }
}

void alokasi(){
    p = (Node *) malloc(sizeof(Node));
    if(p == NULL){
        puts("Alokasi gagal");
        exit(0);
    }else{
        printf("\nMasukkan no mahasiswa\t: ");
        scanf("%d",&p->data);
        fflush(stdin);
        printf("Masukkan nama mahasiswa\t: ");
        gets(p->nama);
        fflush(stdin);
        printf("Masukkan nilai mahasiswa: ");
        scanf("%f",&p->nilai);
        p->next = NULL;
    }
}

void show(){
    Node *read;

    puts("\nisi dari SLL");
    read = head;
    if(read == NULL)
        puts("isi data SLL sudah kosong :(");
    while(read != NULL){
        printf("no\t:%d", read->data);
        printf("\nnama\t:%s", read->nama);
        printf("\nnilai\t:%g\n\n", read->nilai);
        read = read->next;
    }
}

void deltentu(){
    Node *hapus, *phapus;
    int input;

    if(head == NULL){
        puts("SLL masih kosong diisi dulu ya ");
        return 0;
    }else{
    printf("masukkan data yg mau dihapus : ");
    scanf("%d", &input);
    hapus = head;
    if(hapus->data == input)
        delawal();
    else{
        while(hapus->data != input){
            if(hapus->next == NULL){
                printf("\ndata %d tidak ada didalam SLL\n",input);
            }else{
                phapus = hapus;
                hapus = hapus->next;
            }
        }
        phapus->next = hapus->next;
        free(hapus);
        hapus =NULL;
        }
    }
}

void delawal(){
    Node *hapus;

    hapus = head;
    if(hapus->next == NULL)
        head = NULL;
    else{
        head = hapus->next;
        free(hapus);
        hapus = NULL;
    }
}

void akhir(){
    Node *tail;

    if(head == NULL){
        head = p;
    }else{
        tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = p;
        tail = tail->next;
    }
}

void awal(){
    if(head != NULL){
        p->next = head;
    }
    head = p;
}
