package Tugas;
import java.util.*;
class tesTugas extends Bank{
    public static void main(String[] args) {
        String namaAwal;
        String namaAkhir;
        int pilihan, tabungan, mataUang, tambahUang, ambilUang, temp;
        char ulang = 'n';
        boolean status;
        Scanner masukan = new Scanner(System.in);

        Bank bank = new Bank();
        System.out.print("Masukkan Nama Awal Anda : ");
        namaAwal = masukan.nextLine();
        System.out.print("Masukkan Nama Akhir Anda : ");
        namaAkhir = masukan.nextLine();
        bank.tambahNasabah(namaAwal, namaAkhir);

        System.out.println("\nPilihan Mata Uang");
        System.out.println("1. IDR ");
        System.out.println("2. USD ");
        System.out.println("3. AUD ");
        System.out.print("Masukkan Pilihan Mata uang : ");
        mataUang = masukan.nextInt();

        if(mataUang == 1){
            System.out.print("\nMasukkan Tabungan Awal (IDR) : ");
            tabungan = masukan.nextInt();
            bank.getNasabah(0).setTabungan(new multiTabungan(tabungan,mataUang));
        }
        else if(mataUang == 2){
            System.out.print("\nMasukkan Tabungan Awal (USD) : ");
            tabungan = masukan.nextInt();
            bank.getNasabah(0).setTabungan(new multiTabungan(tabungan,mataUang));
        }
        else if(mataUang == 3){
            System.out.print("\nMasukkan Tabungan Awal (AUD) : ");
            tabungan = masukan.nextInt();
            bank.getNasabah(0).setTabungan(new multiTabungan(tabungan,mataUang));
        }

        do{
            System.out.println("\nSelamat Datang " + bank.getNasabah(0).getNamaAwal() + " " + bank.getNasabah(0).getNamaAkhir());
            System.out.println("Pilihan Menu Bank");
            System.out.println("1. Cek Saldo ");
            System.out.println("2. Tambah Saldo");
            System.out.println("3. Ambil Saldo ");
            System.out.println("4. Keluar ");
            System.out.print("Masukkan Pilihan Menu : ");
            pilihan = masukan.nextInt();

            if(pilihan == 1){
                temp = bank.getNasabah(0).getTabungan().getSaldo(mataUang);
                if(mataUang == 2){
                    System.out.println("Saldo anda adalah (dalam USD) : " + temp);
                    temp *= 9;
                    System.out.println("Saldo anda adalah (dalam IDR) : " + temp);
                 }
                 else if(mataUang == 3){
                    System.out.println("Saldo anda adalah (dalam AUD) : " + temp);
                    temp *= 10;
                    System.out.println("Saldo anda adalah (dalam IDR) : " + temp);
                 }else{
                    System.out.println("Saldo anda adalah (dalam IDR) : " + temp);
                 }
            }
            else if(pilihan == 2){
                System.out.print("Berapa yang mau ditambah (sesuai mata uang) : ");
                tambahUang = masukan.nextInt();
                bank.getNasabah(0).getTabungan().simpanUang(tambahUang,mataUang);
                System.out.println("Berhasil !! sekarang saldo anda menjadi  " + bank.getNasabah(0).getTabungan().getSaldo(mataUang));
            }
            else if(pilihan == 3){
                System.out.print("Berapa yang mau dikurangi ? (sesuai mata uang) : ");
                ambilUang = masukan.nextInt();
                if(mataUang == 2){
                   ambilUang *= 9;
                }
                else if(mataUang == 3){
                    ambilUang *= 10;
                }
                status = bank.getNasabah(0).getTabungan().ambilUang(ambilUang);
                if(status)
                System.out.println("Berhasil !! sekarang saldo anda menjadi " + bank.getNasabah(0).getTabungan().getSaldo(mataUang));
                else
                System.out.println("Gagal uang anda di saldo terlalu sedikit");
            }
            else if(pilihan == 4){
                System.out.print("yakin keluar ? (Y/N) ");
                ulang = masukan.next().charAt(0);
            }
        }while(ulang == 'n' || ulang == 'N');
        masukan.close();
        System.out.print("Terimakasih telah bertransaksi dengan bank GGS :) ");
    }
}
