#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int insertsort(int a[], int n);
int tampil(int a[]);

int main(){
  int i, input;
  //int array[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
  //int array[] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
  //int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n =

  puts("PRAKTIKUM INSERTION SORT ");

  insertsort(array,input);
  tampil(array);
}

int quickSort(int a[], int low, int high) {
    int banding, tukar;

    if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
  printf("\njumlah perbandingan %d\n", banding);
  printf("jumlah pertukaran %d\n", tuker);
}

int partition(int a[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int tampil(int a[]){
  int i;

  printf("\nhasil pengurutan insertion sort gan :\n");
  for (i = 0; i < 10 ; i++){
    printf("%d ", a[i]);
  }
  puts("\n\narigato gonzaimasu");

}
