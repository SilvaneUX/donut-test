package Tugas1;
class Silinder extends Lingkaran{
    private double tinggi;

    public Silinder(){
        tinggi = 0;
    }

    public Silinder (double r, double t){
        super(r);
        this.tinggi = t;
    }

    public void setTinggi(double tinggi){
        this.tinggi = tinggi;
    }

    public double getTinggi(){
        return tinggi;
    }

    public double getVolume(){
        return 3.14 * super.getR() * super.getR() * tinggi;
    }

    public double getLuas(){
        return super.getLuas();
    }

    public String toString(){
        return (super.toString() + "\nvolume Silinder adalah : " + getVolume());
    }
}
