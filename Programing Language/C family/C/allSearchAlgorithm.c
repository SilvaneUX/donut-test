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
struct siswa data[MAX];
int masukData(struct siswa siswa[]);
int insertsort(struct siswa siswa[]);
int tampil(struct siswa siswa[]);
int sequential(struct siswa siswa[]);
int binery(struct siswa siswa[],int,int);
int jum, pilihan, pilihan2, pilihan3, sama = 0, indeks = 0, carinomer = 0;
char carinama[20];

int main()
{
    puts("PRAKTIKUM 13.2\n");
    masukData(data);

    do{
       puts("\nMENU METODE SORTING");
       puts("1. Tampilkan Data");
       puts("2. Sequential Search");
       puts("3. Binary Search");
       puts("4. metu");
       printf("masukkan pilihan anda : ");
       scanf("%d", &pilihan);
       fflush(stdin);

       if(pilihan == 1){
            fflush(stdin);
            puts("\nUrutan Data");
            puts("1. Sorted");
            puts("2. Unsorted");
            printf("masukkan pilihan anda : ");
            scanf("%d", &pilihan2);
            fflush(stdin);

            if(pilihan2 == 1){
                insertsort(data);
                puts("Tampilan Data Sorted:");
                tampil(data);
            }
            else if(pilihan2 == 2){
                puts("Tampilan Data Unorted:");
                tampil(data);
            }else{
            puts("pilihan salah gann");
            }
       }

       else if(pilihan == 2){
            fflush(stdin);
            puts("\nSearch BY");
            puts("1. No");
            puts("2. Nama");
            printf("masukkan pilihan anda : ");
            scanf("%d", &pilihan3);
            fflush(stdin);

            if(pilihan3 == 1){
                fflush(stdin);
                printf("masukkan No yang Dicari : ");
                scanf("%d", &carinomer);
                fflush(stdin);
                sequential(data);
            }
            else if(pilihan3 == 2){
                fflush(stdin);
                printf("masukkan Nama yang Dicari : ");
                gets(carinama);
                fflush(stdin);
                sequential(data);
                if(sama == 0){
                    puts("moon maaf data tidak ada\n");
                }else{
                    printf("data ditemukan di indeks ke %d\n",indeks);
                }
            }else{
            puts("pilihan salah gann");
            }
       }

       else if(pilihan == 3){
            fflush(stdin);
            puts("\nSearch BY");
            puts("1. No");
            puts("2. Nama");
            printf("masukkan pilihan anda : ");
            scanf("%d", &pilihan3);
            fflush(stdin);

            if(pilihan3 == 1){
                fflush(stdin);
                printf("masukkan No yang Dicari : ");
                scanf("%d", &carinomer);
                fflush(stdin);
                insertsort(data);
                binery(data,0,jum-1);
                if(sama == 0){
                    puts("moon maaf data tidak ada\n");
                }else{
                    printf("data ditemukan di indeks ke %d\n",indeks);
                }
            }
            else if(pilihan3 == 2){
                fflush(stdin);
                printf("masukkan Nama yang Dicari : ");
                gets(carinama);
                fflush(stdin);
                insertsort(data);
                binery(data,0,jum-1);
                if(sama == 0){
                    puts("moon maaf data tidak ada\n");
                }else{
                    printf("data ditemukan di indeks ke %d\n",indeks);
                }
            }else{
            puts("pilihan salah gann");
            }
        }else{
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

int tampil(struct siswa *sis){
    int i;
        puts("No      Nama    Nilai");
    for (i = 0; i < jum ; i++){
        printf("%d      %s      %s\n", sis[i].no,sis[i].nama,sis[i].nilai);
  }
}

int insertsort(struct siswa *sis){
    int i, key = 0, j = 0;
    char nama[10],nilai[10];

    puts("\nINSERTION SORT ASCENDING ");

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

int sequential(struct siswa *sis){
  int i;

  if(pilihan3 == 1){
      for (i = 0; i < jum; i++){
        if(sis[i].no == carinomer){
            sama++;
            indeks = i;
        }
      }
  }
  else if(pilihan3 == 2){
      for (i = 0; i < jum; i++){
        if(strcmpi(sis[i].nama,carinama)== 0){
            sama++;
            indeks = i;
        }
      }
  }
  if(sama == 0){
        puts("moon maaf data tidak ada\n");
  }else{
        printf("data ditemukan di indeks ke %d\n",indeks);
    }
}

int binery(struct siswa *sis,int low,int high){

    if(pilihan3 == 1){
        if (high >= low) {
        int mid = low + (high - low) / 2;
            if (sis[mid].no == carinomer){
                sama++;
                indeks = mid;
            }

            if (sis[mid].no > carinomer){
                return binery(data, low, mid - 1);
            }
            return binery(data, mid + 1, high);
      }
    }
    else if(pilihan3 == 2){
        if (high >= low) {
        int mid = low + (high - low) / 2;
            if (strcmpi(sis[mid].nama,carinama)== 0){
                sama++;
                indeks = mid;
            }

            if (strcmpi(sis[mid].nama,carinama)== 0){
                return binery(data, low, mid - 1);
            }
            return binery(data, mid + 1, high);
      }
    }
}
