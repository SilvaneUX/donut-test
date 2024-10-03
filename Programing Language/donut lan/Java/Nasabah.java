package Tugas;

class Nasabah extends Bank{
    private String namaAwal;
    private String namaAkhir;
    private multiTabungan tabungan;

    public Nasabah(String namaAwal, String namaAkhir){
        this.namaAkhir = namaAkhir;
        this.namaAwal = namaAwal;
    }

    public String getNamaAwal(){
        return namaAwal;
    }

    public String getNamaAkhir(){
        return namaAkhir;
    }

    public multiTabungan getTabungan(){
        return tabungan;
    }

    public void setTabungan(multiTabungan tabungan){
        this.tabungan = tabungan;
    }
}
