#include <stdio.h>
#define maks 100

typedef struct{
    char NPM [20];
    char nama[50];
    float IP;
} data_mahasiswa;
data_mahasiswa mhs [maks];

int main() {
    FILE *file = fopen("data.txt", "a");
    /*write*/
    int pilih, ch;
    printf  ("\n\t\t\tMasukkan berapa data yang akan dimasukkan : ");
    scanf   ("%d", &pilih);
    printf ("\n");

    for (int i = 0; i < pilih; i++) {
        while ((ch = getchar()) != '\n' && ch != EOF)
            continue;
        printf  ("Masukkan NPM Mahasiswa  ke-%d     : ", i+1);
        gets(mhs[i].NPM);
        printf  ("Masukkan Nama Mahasiswa ke-%d     : ", i+1);
        gets    (mhs[i].nama);
        printf  ("Masukkan IP Mahasiswa   ke-%d     : ", i+1);
        scanf   ("%f", &mhs[i].IP);
        printf("\n");
        fwrite(&mhs[i], sizeof(mhs), 1, file);
    }
    fclose(file);

    /*read*/
    file = fopen("data.txt", "rb");
    printf  ("\t\t\t\tHASIl DATA MAHASISWA\n");
    printf  ("\n\t\t=================================================");
    printf  ("\n\t\t==================DATA MAHASISWA=================");
    printf  ("\n\t\t=================================================\n");
    printf  ("\t\t|| %-11s || %-20s || %-3s  ||", "NPM", "Nama", "IP");
    printf  ("\n\t\t=================================================\n");

    for (int i = 0; i < pilih; i++) {
      while (fread(&mhs, sizeof(mhs), 1, file)) {
         printf ("\t\t|| %-11s || %-20s || %-3.2f ||\n", mhs[i].NPM, mhs[i].nama, mhs[i].IP);
    }
    }
    printf  ("\t\t=================================================\n");

    fclose(file);
    getchar();
    return 0;
}
