#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int shellsort(int a[],int);
int random(int a[]);
int jum, pil2;
time_t t1, t2;
double waktukomputasi;

int main(){
  int i, jarak = 0;

  puts("PRAKTIKUM SHELL SORTING ");
  printf("masukkan jumlah randoman : ");
  scanf("%d", &jum);
  int a[jum];
  srand(time(NULL));
  random(a);

  puts("data awal array : ");
  for(i = 0; i < jum; i++){
    printf("%d ", a[i]);
  }
  printf("\n");

  printf("\npengurutan (1)ascending atau (2)descending ? ");
  scanf("%d", &pil2);
  time(&t1);
  jarak = sizeof(a) / sizeof(a[0]);
  shellsort(a, jarak);
  sleep(1);
  time(&t2);
  waktukomputasi = t2 - t1;

  printf("\n");
  printf("waktu komputasi = %lf\n", waktukomputasi);

  printf("\nHasil pengurutan sebagai berikut:\n");
  for(i = 0; i < jum; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int random(int a[]){
    int i;

    for(i = 0; i < jum; i++){
        a[i] = rand()/1000;
    }
}

int shellsort(int a[], int jar){
  int i, j, jarak = 0, temp = 0;
  int banding = 0, tuker = 0, geser = 0;

  if(pil2 == 1){
  for (int jarak = jar / 2; jarak > 0; jarak /= 2){
    for (int i = jarak; i < jar; i += 1) {
        temp = a[i];
        banding++;
      for (j = i; j >= jarak && a[j - jarak] > temp; j -= jarak) {
            a[j] = a[j - jarak];
            geser += 3;
            tuker++;
      }
      a[j] = temp;
    }
  }
  }

  else if(pil2 == 2){
  for (int jarak = jar / 2; jarak > 0; jarak /= 2){
    for (int i = jarak; i < jar; i += 1) {
        temp = a[i];
        banding++;
      for (j = i; j >= jarak && a[j - jarak] < temp; j -= jarak) {
            a[j] = a[j - jarak];
            geser += 3;
            tuker++;
      }
      a[j] = temp;
    }
  }
  }else{
  puts("pilihan salah gannn ");
  }
  printf("\njumlah banding = %d\n", banding);
  printf("jumlah tukar = %d\n", tuker);
  printf("jumlah geser = %d\n", geser);
}
