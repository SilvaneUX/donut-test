package Tugas1;
class Kerucut extends Lingkaran {
    private double tinggi;

    public Kerucut(){
        tinggi = 0;
    }

    public Kerucut(double r, double t){
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
        return  0.33 * super.getLuas() * tinggi ;
    }

    public double getLuas(){
        return super.getLuas();
    }

    public String toString(){
        return (super.toString() + "\nvolume Kerucut adalah : " + getVolume());
    }
}
