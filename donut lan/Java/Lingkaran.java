package Tugas1;
class Lingkaran{
    private double r;

    public Lingkaran(){
        r = 0;
    }

    public Lingkaran(double r){
        this.r = r;
    }

    public void setR(double r){
        this.r = r;
    }

    public double getR(){
        return r;
    }

    public double getDiameter(){
        return r*2;
    }

    public double getKeliling(){
        return 2 * 3.14 * r;
    }

    public double getLuas(){
        return 3.14 * r * r;
    }

    public String toString(){
        return ("luas r lingkaran adalah : " + getLuas() + " dan keliling lingkaran " + getKeliling());
    }
}
