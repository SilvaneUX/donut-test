#include <stdio.h>
#include <stdlib.h>

struct pohon{
   char data;
   struct pohon *kiri;
   struct pohon *kanan;
};
struct pohon *root = NULL;
void masukdata(int data);
struct pohon* cari(int data);
void preorder(struct pohon* root);
void inorder(struct pohon* root);
void postorder(struct pohon* root);

int main(){
   int i, jum = 0, menu = 0;
   char carik;

   puts("PRAKTIKUM TREE SEARCHING GAGAS");
   printf("\nmau memasukkan berapa data ? : ");
   scanf("%d", &jum);
   char masuk[jum];
   fflush(stdin);

   for(i = 0; i < jum; i++){
    fflush(stdin);
    printf("masukkan data ke %d : ", i);
    scanf("%c", &masuk[i]);
    fflush(stdin);
   }

   for(i = 0; i < jum; i++)
      masukdata(masuk[i]);

   do{
       puts("\nMenu TREE");
       puts("1.PreOrder Tree");
       puts("2.InOrder Tree");
       puts("3.PostOrder Tree");
       puts("4.ALL Tree");
       puts("5.Cari Tree");
       puts("6.Exit");
       printf("masukkan pilihan anda : ");
       scanf("%d", &menu);
       fflush(stdin);


       if(menu == 1){
        printf("Preorder Tree: ");
        preorder(root);
        printf("\n");
       }

       else if(menu == 2){
         printf("Inorder Tree: ");
         inorder(root);
         printf("\n");
       }

       else if(menu == 3){
        printf("Postorder Tree: ");
        postorder(root);
        printf("\n");
       }

       else if(menu == 4){
        printf("Preorder Tree\t: ");
        preorder(root);

        printf("\nInorder Tree\t: ");
        inorder(root);

        printf("\nPostorder Tree\t: ");
        postorder(root);
        printf("\n");
       }

       else if(menu == 5){
           printf("\nmasukkan data yang ingin di cari (T untuk keluar) : ");
           scanf("%c", &carik);
           fflush(stdin);

           struct pohon* temp = cari(carik);
           if(temp != NULL) {
              printf("[%c] Ketemu.", carik);
              printf("\n");
           }else{
              printf("[%c] Tidak ketemu :((.\n", carik);
           }
       }else{
        puts("Arigatu Gonzaimas");
        exit(0);
       }
   }while(1);
}

void masukdata(int data) {
   struct pohon *tempNode = (struct pohon*) malloc(sizeof(struct pohon));
   struct pohon *current;
   struct pohon *parent;

   tempNode->data = data;
   tempNode->kiri = NULL;
   tempNode->kanan = NULL;

   if(root == NULL) {
      root = tempNode;
   }else {
      current = root;
      parent = NULL;

      while(1) {
         parent = current;

         if(data < parent->data) {
            current = current->kiri;

            if(current == NULL) {
               parent->kiri = tempNode;
               return;
            }
         }
         else {
            current = current->kanan;


            if(current == NULL) {
               parent->kanan = tempNode;
               return;
            }
         }
      }
   }
}

struct pohon* cari(int data) {
   struct pohon *current = root;
   printf("Pencarian Tree : ");

   while(current->data != data) {

      if(current->data > data) {
         current = current->kiri;
      }
      else {
         current = current->kanan;
      }

      if(current == NULL) {
         return NULL;
      }
   }
   return current;
}

void preorder(struct pohon* root) {
   if(root != NULL) {
      printf("%c ",root->data);
      preorder(root->kiri);
      preorder(root->kanan);
   }
}

void inorder(struct pohon* root) {
   if(root != NULL) {
      inorder(root->kiri);
      printf("%c ",root->data);
      inorder(root->kanan);
   }
}

void postorder(struct pohon* root) {
   if(root != NULL) {
      postorder(root->kiri);
      postorder(root->kanan);
      printf("%c ", root->data);
   }
}
