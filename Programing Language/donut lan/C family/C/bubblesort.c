#include <stdlib.h>
#include <stdio.h>

int bubblesort(int a[]);
int tampil(int a[]);

int main(){
  int i;
  int a[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};

  puts("PRAKTIKUM BUBBLE SORTING ");
  puts("data awal array : ");
  for(i = 0; i < 10; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  bubblesort(a);

  printf("\nHasil pengurutan sebagai berikut:\n");
  for(i = 0; i < 10; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int tampil(int a[]){
    int i = 0;

    printf("\n");
    for(i = 0; i < 10; i++){
      printf("%d ", a[i]);
  }
}

int bubblesort(int a[]){
  int i, j;
  int tukar = 0, banding = 0, tuker = 0, geser = 0;

  for (i = 0; i < 10-1; i++){
       for (j = 0; j < 10 - i - 1; j++){
            banding++;
            if (a[j] > a[j+1]){
                tukar = a[j];
                geser += 3;
                tuker++;
                a[j] = a[j+1];
                a[j+1] = tukar;
                tampil(a);
           }
       }
  }
  printf("\n\njumlah banding = %d\n", banding);
  printf("jumlah tukar = %d\n", tuker);
  printf("jumlah geser = %d\n", geser);
}
