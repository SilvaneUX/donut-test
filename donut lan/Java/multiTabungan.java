package Tugas;
class multiTabungan extends Bank{
    private int saldo;

    protected multiTabungan(int saldo, int mataUang){
        if(mataUang == 1){
            this.saldo = saldo;
        }
        else if(mataUang == 2){
            this.saldo = saldo * 9;
        }
        else if(mataUang == 3){
            this.saldo = saldo * 10;
        }   
    }

    protected int getSaldo(int mataUang){
        if(mataUang == 1){
            return saldo;
        }
        else if(mataUang == 2){
            return saldo / 9;
        }
        else if(mataUang == 3){
            return saldo / 10;
        }else{
            return saldo;
        }
    }

    protected void simpanUang(int jumlah, int mataUang){
        if(mataUang == 1){
            this.saldo += jumlah;
        }
        else if(mataUang == 2){
            this.saldo += (jumlah * 9);
        }
        else if(mataUang == 3){
            this.saldo += (jumlah * 10);
        }
    }

    protected void IDRtoAUD(int jumlah){
        jumlah *= 10;
    }

    protected void IDRtoUSD(int jumlah){
        jumlah *= 9;
    }

    protected boolean ambilUang(int jumlah){
        if(jumlah > this.saldo){
            return false;
        }else{
            this.saldo -= jumlah;
            return true;
        }
    }
}
