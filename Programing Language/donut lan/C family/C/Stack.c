#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef char ItemType;
typedef struct
{
    ItemType Item[MAX];
    int Count;
} Stack;

void InisialisasiStack(Stack *S);
int Kosong(Stack *S);
int Penuh(Stack *S);
void show(Stack *S);
void Push(ItemType x, Stack *S);
ItemType Pop(Stack *S);

int main(){
    Stack tumpuk;
    int pilihan;
    ItemType x;

    puts("Praktikum Stack push pop");
    InisialisasiStack(&tumpuk);

    do{
        puts("\nMenu stack menggunakan ARRAY : ");
        puts("1. Mengisi stack (PUSH)");
        puts("2. Mengambil isi stack (POP)");
        puts("3. Menampilkan isi stack");
        puts("4. Keluar");
        printf("masukkan pilihan anda : ");
        scanf("%d", &pilihan);

        if(pilihan == 1){
            fflush(stdin);
            printf("masukkan data item : ");
            scanf("%c", &x);
            fflush(stdin);
            Push(x, &tumpuk);
            fflush(stdin);
        }

        else if(pilihan == 2){
            fflush(stdin);
            Pop(&tumpuk);
        }

        else if(pilihan == 3){
            fflush(stdin);
            show(&tumpuk);
            fflush(stdin);
        }

        else if(pilihan == 4){
            exit(0);
        }

        else
            puts("Pilihan Anda salah");

    }while(1);

}

void InisialisasiStack(Stack *S)
{
    S->Count = 0;
}

int Kosong(Stack *S)
{
    if(S->Count == 0)
        return(1);
    else
        return(0);
}

int Penuh(Stack *S)
{
    if(S->Count == MAX)
        return(1);
    else
        return(0);
}

void Push(ItemType x, Stack *S)
{
    if (Penuh(S))
    printf("Stack penuh! Data tidak dapat masuk!\n");
    else{
        S->Item[S->Count] = x;
        S->Count++;
    }
}

void show(Stack *S){
    int i, temp;

    temp = S->Count -1;
    for(i = temp; i >= 0; i--){
        printf("%c \n", S->Item[i]);
    }

}

ItemType Pop(Stack *S)
{
    ItemType x;

    if (Kosong(S)){
    printf("Stack masih kosong!\n");
    return(' ');
    }else{
        -S->Count;
        x = S->Item[--S->Count];
        return(x);
    }
}
