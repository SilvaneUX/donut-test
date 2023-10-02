#include<stdio.h>
struct sparse{
    int row;
    int col;
    int val;
};

int main(){
    int r,c;
    printf("enter the rows and columns:");
    scanf("%d %d",&r,&c);
    printf("enter the matrix:");
    int k= 1;
    int arr[10][10];
    struct sparse a[10];
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] != 0){
                a[k].row = i;
                a[k].col = j;
                a[k].val = arr[i][j];
                k++;
            }
        }
    }
   
    a[0].row = r;
    a[0].col = c;
    a[0].val = k-1;
    int n = k-1;
    printf("the sparse matrix is : \n");
    for(int i = 0;i<=n;i++){
            printf("%d %d %d \n", a[i].row,a[i].col,a[i].val);
    }
    struct sparse trans[10];
    trans[0].row = c;
    trans[0].col = r;
    trans[0].val = n;
    int row_terms[100], pos[100];
    for(int i = 0;i<c;i++){
        row_terms[i] = 0;
    }
    for(int i = 1;i<=n;i++){
        row_terms[a[i].col]++; 
    }
    pos[0] = 1;
    for(int i = 1;i<c;i++){
        pos[i] = pos[i-1] + row_terms[i-1];
    }
    int j;
    for(int i =1;i<=n;i++){
        j = pos[a[i].col]++;
        trans[j].row = a[i].col;
        trans[j].col = a[i].row;
        trans[j].val = a[i].val;
    }
    printf("the transpose of matrix is : \n");
    for(int i = 0;i<=n;i++){
            printf("%d %d %d \n", trans[i].row,trans[i].col,trans[i].val);
    }

}