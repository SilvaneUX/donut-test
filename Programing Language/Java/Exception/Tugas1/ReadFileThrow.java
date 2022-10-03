package Tugas1;
import java.io.*;
public class ReadFileThrow {
    public static void method2() throws IOException {
        File file= new File("Data.txt");
        BufferedReader fileReader;
        fileReader = new BufferedReader(new FileReader(file));
        fileReader.close();
        while(true){
            String line = fileReader.readLine();
            if (line == null)
                break ;
            System.out.println(line);
        }
    }
    public static void main(String[] args) {
        try{
            method2();
        }
        catch (FileNotFoundException ex) {
            System.out.println("Muncul file Error FileNotFoundException File tidak tidak ditemukan");
            System.out.println("menggunakan Throw");
        }
        catch (IOException e) {
            System.out.println("Muncul file Error IOException");
        }
    }
}
