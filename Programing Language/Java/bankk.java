package Tugas;
class Bank {
    public int jumlahNasabah = 0, i = 0;
    public Nasabah[] nasabah;

    public Bank(){
        nasabah = new Nasabah[4];
    }

    public void tambahNasabah(String namaAwal, String namaAkhir){
        i = jumlahNasabah;
        nasabah[i] = new Nasabah(namaAwal, namaAkhir);
        jumlahNasabah++;
    }

    public int getJumlahNasabah(){
        return this.jumlahNasabah;
    }

    public Nasabah getNasabah(int indeks){
        return nasabah[indeks];
    }
}
