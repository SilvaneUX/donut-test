#include <stdio.h>
#include <stdlib.h>

typedef struct praktikum DNode;
struct praktikum{
    int data;
    DNode *next, *prev;
};
DNode *head = NULL, *p, *pepe, *tentu;

void alokasi();
void show();
void insertauto();
void deltentu();
void awal();
void akhir();
void delaker();
void delawal();

int main()
{
    int pilihan;

    puts("praktikum Double Linked List");

    do{
        puts("\nMenu praktikum DLL");
        puts("1. Insert Auto");
        puts("2. Delete Tertentu");
        puts("3. Exit");
        printf("masukkan pilihan anda : ");
        scanf("%d",&pilihan);
        printf("\n");

        if(pilihan == 1){
            alokasi();
            fflush(stdin);
            insertauto();
            show();
        }
        else if (pilihan == 2){
            if(head == NULL){
                puts("SLL masih kosong gan, diisi dulu");
            }else{
                deltentu();
                fflush(stdin);
                show();
            }
        }
        else if(pilihan == 3){
            puts("ARIGATOU GOZAIMASTA OHAYOU");
            exit(0);
        }
    }while(1);
}

void alokasi(){
    p = (DNode *)malloc(sizeof(DNode));

    if(p == NULL){
        puts("Alokasi gagal, maaf");
        exit(0);
    }
    else{
        printf("Masukkan nilai\t: ");
        scanf("%d",&p->data);
        fflush(stdin);
        p->next = NULL;
        p->prev = NULL;
    }
}

void insertauto(){
    pepe = head;

    if(head == NULL || head->data > p->data){
        awal();
    }else{
        while(p->data >= pepe->data){       //menjalankan pointer
            if(pepe->next != NULL){
               pepe = pepe->next;
            }
            else
                break;
        }
        if(pepe->next == NULL){
            if(pepe->data > p->data){
                p->next = pepe;
                p->prev = pepe->prev;
                pepe->prev->next = p;
                pepe->prev = p;
            }else
                akhir();
        }
        else{
            p->next = pepe;
            p->prev = pepe->prev;
            pepe->prev->next = p;
            pepe->prev = p;
        }
    }
}

void deltentu(){
    int key;

    fflush(stdin);
    printf("Data yang ingin dihapus : ");
    scanf("%d",&key);
    fflush(stdin);

    tentu = head;
    if(head == NULL){
        puts("SLL Kosong gan isi auto dulu\n");
    }
        while(tentu->data != key){
            if(tentu->next==NULL){
                printf("data %d tidak ada di DLL\n",key);
            }
            else
                tentu = tentu->next;
        }
        if(head->data == key){
            delawal();
        }
        else if(tentu->next == NULL){
            delaker();
        }else{
            tentu->prev->next = tentu->next;
            tentu->next->prev = tentu->prev;
        }
    free(tentu);
    tentu = NULL;
}

void awal(){
    if(head != NULL){
        p->next = head;
    }
    head = p;
}

void akhir(){
    DNode *tail;

    tail = head;
    if(head == NULL){
        head = p;
    }else {
        while(tail->next != NULL){
        tail = tail->next;
        }
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
}

void delaker(){

    while(tentu->next != NULL){
        tentu = tentu ->next;
    }
    tentu ->prev->next = NULL;

    free(tentu);
    tentu  = NULL;
}

void delawal(){

    if(tentu ->next == NULL){
        head = NULL;
    }else{
    head = tentu ->next;
    tentu ->next->prev = NULL;
    }

    free(tentu );
    tentu = NULL;
}

void show(){
    DNode *read;

    puts("isi dari SLL");
    read = head;
    if(read == NULL)
        puts("isi data SLL sudah kosong :(");
    while(read != NULL){
        printf("%d\n", read->data);
        read = read->next;
    }
}
