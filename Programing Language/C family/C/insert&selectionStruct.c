#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40

typedef struct siswa siswa;
struct siswa {
    int no;
    char nama[10];
    char nilai[10];
};

int masukData(struct siswa siswa[]);
int insertsort(struct siswa siswa[]);
int selection(struct siswa siswa[]);

int jum, pilihan, pilihan2;
int main()
{
    int pilihan;
    struct siswa data[MAX];

    puts("PRAKTIKUM 10.2\n");
    masukData(data);

    do{
       puts("\nMENU METODE SORTING");
       puts("1. Insertion sort");
       puts("2. Selection sort");
       puts("3. Metu");
       printf("masukkan pilihan anda : ");
       scanf("%d", &pilihan);
       fflush(stdin);

       if(pilihan == 1){
            fflush(stdin);
            puts("\n1.Ascending (kecil -> besar)");
            puts("2.Descending (besar -> kecil)");
            printf("pilih salah satu gan [1/2] : ");
            scanf("%d", &pilihan2);

            if (pilihan2 == 1 || pilihan2 == 2){
                insertsort(data);
            }else
                puts("pilihan salah");
       }

       else if(pilihan == 2){
        fflush(stdin);
        puts("\n1.Ascending (kecil -> besar)");
        puts("2.Descending (besar -> kecil)");
        printf("pilih salah satu gan [1/2] : ");
        scanf("%d", &pilihan2);
        if (pilihan2 == 1 || pilihan2 == 2){
            selection(data);
        }else
            puts("pilihan salah");
       }

       else{
        puts("arigatou gonzaimasu");
        exit(0);
       }
    }while(1);
}

int masukData(struct siswa sis[]){
    int i;

    printf("Mau memasukkan berapa data ? : ");
    scanf("%d", &jum);

    for(i = 0; i < jum; i++){
        printf("\nINPUTAN KE %d \n", i+1);
        printf("masukkan No : ");
        scanf("%d", &sis[i].no );
        fflush(stdin);

        printf("Masukkan Nama : ");
        gets(sis[i].nama );
        fflush(stdin);

        printf("Masukkan Nilai : ");
        gets(sis[i].nilai );
        fflush(stdin);
    }
}

int insertsort(struct siswa *sis){
    int i, key = 0, j = 0;
    char nama[10],nilai[10];

    puts("\nINSERTION SORT ASCENDING ");

    if(pilihan2 == 1){
        for (i = 1; i < jum; i++){
        key = sis[i].no;
        strcpy(nama,sis[i].nama);
        strcpy(nilai,sis[i].nilai);
        j = i - 1;
        while(j >= 0 && sis[j].no > key){
            sis[j+1].no = sis[j].no;
            strcpy(sis[j+1].nama,sis[j].nama);
            strcpy(sis[j+1].nilai,sis[j].nilai);
            j = j - 1;
        }
        sis[j+1].no =key;
        strcpy(sis[j+1].nama,nama);
        strcpy(sis[j+1].nilai,nilai);
      }
    }

    else if(pilihan2 == 2){
        for (i = 1; i < jum; i++){
        key = sis[i].no;
        strcpy(nama,sis[i].nama);
        strcpy(nilai,sis[i].nilai);
        j = i - 1;

        while(j >= 0 && sis[j].no < key){
            sis[j+1].no = sis[j].no;
            strcpy(sis[j+1].nama,sis[j].nama);
            strcpy(sis[j+1].nilai,sis[j].nilai);
            j = j - 1;
        }
        sis[j+1].no =key;
        strcpy(sis[j+1].nama,nama);
        strcpy(sis[j+1].nilai,nilai);
      }
    }

  printf("\nhasil pengurutan insertion sort gan :\n");
  for (i = 0; i < jum ; i++){
    printf("No    : %d \n", sis[i].no);
    printf("Nama  : %s \n", sis[i].nama);
    printf("Nilai : %s \n", sis[i].nilai);
    printf("\n");
  }
}

int selection(siswa *a){
    int  i,j,min,temp;
    char nama[10],nilai[10];
    if(pilihan2 == 1){
        for(i=0;i<jum;i++){
            min = i;
            j=i+1;
            while(j<jum){
                if(a[j].no<a[min].no)
                    min=j;
                j=j+1;
            }
            temp=a[i].no;
            strcpy(nama,a[i].nama);
            strcpy(nilai,a[i].nilai);
            a[i].no=a[min].no;
            strcpy(a[i].nama,a[min].nama);
            strcpy(a[i].nilai,a[min].nilai);
            a[min].no=temp;
            strcpy(a[min].nama,nama);
            strcpy(a[min].nilai,nilai);
        }
    }
    else{
        for(i=0;i<jum;i++){
            min = i;
            j=i+1;
            while(j<jum){
                if(a[j].no>a[min].no)
                    min=j;
                j=j+1;
            }
            temp=a[i].no;
            strcpy(nama,a[i].nama);
            strcpy(nilai,a[i].nilai);
            a[i].no=a[min].no;
            strcpy(a[i].nama,a[min].nama);
            strcpy(a[i].nilai,a[min].nilai);
            a[min].no=temp;
            strcpy(a[min].nama,nama);
            strcpy(a[min].nilai,nilai);
        }
    }

  printf("\nhasil pengurutan selection sort gan :\n");
 for (i = 0; i < jum ; i++){
    printf("No    : %d \n", a[i].no);
    printf("Nama  : %s \n", a[i].nama);
    printf("Nilai : %s \n", a[i].nilai);
    printf("\n");
  }
}
