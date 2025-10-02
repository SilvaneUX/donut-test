#include <cstdlib>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;
int main(int argc, char** argv) {
    float d,e,f,pilih;
    kalkulator :
    system("cls");
    cout<<"================================================================================"<<endl;
    cout<<"\t\t\t<===>Kalkulator Sederhana<===>"<<endl;
    cout<<"\t\t\t====>\t   SilvanUS\t <===="<<endl;
    cout<<"\t\t\t====>\t  CyberTwenty\t <===="<<endl;
    cout<<"\t\t\t====>\t      X-1\t <===="<<endl;
    cout<<"\t\t\t====>\t      3 3\t <===="<<endl;
    cout<<"\t\t\t====>\t  SUX Project\t <===="<<endl;
    cout<<"================================================================================";
    cout<<" "<<endl;
    cout<<"Nilai Pertama : ";cin>>d;
    cout<<"Nilai Kedua   : ";cin>>e;
    cout<<"================================================================================"<<endl;
    cout<<"'+' = Penjumlahan  [1]"<<endl;
    cout<<"'-' = Pengurangan  [2]"<<endl;
    cout<<"'*' = Perkalian    [3]"<<endl;
    cout<<"'/' = Pembagian    [4]"<<endl;
    cout<<"'^' = Perpangkatan [5]"<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"Masukkan Operasi : ";cin>>pilih;
    if (pilih==1){
        f=d+e;
        cout<<"Hasil Penjumlahan : "<<f<<endl;
    }
    if (pilih==2){
        f=d-e;
        cout<<"Hasil Pengurangan : "<<f<<endl;
    }
    if (pilih==3){
        f=d*e;
        cout<<"Hasil Perkalian : "<<f<<endl;
    }
    if (pilih==4){
        f=d/e;
        cout<<"Hasil Pembagian : "<<f<<endl;
    }
    if (pilih==5){
        f=pow(d,e);
        cout<<"Hasil Perpangkatan : "<<f<<endl;
    }
    cout<<"================================================================================"<<endl;
    cout<<"MEnghitung Ulang [1]"<<endl;
    cout<<"Keluar Aplikasi  [2]"<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"Masukkan Pilihan : ";cin>>pilih;
    if (pilih==1){
        goto kalkulator;
    }
    if (pilih==2){
    system("cls");
    cout<<"================================================================================"<<endl;
    cout<<"\t\t   Terima Kasih Telah Menggunakan Kalkulator Ini"<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"\t\t\t\t   SilvaniUX"<<endl<<endl;
    cout<<"\t\t\t\t  CyberTwenty"<<endl<<endl;
    cout<<"\t\t\t\t      X-1"<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"{]zzz[]zzzzzzzzzzzzzz>       <.>      SUX     <.>       <zzzzzzzzzzzzzz[]zzz[}"<<endl;
    system("pause");
    }
    return 0;
}

