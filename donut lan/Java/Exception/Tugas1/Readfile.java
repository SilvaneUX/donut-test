package Tugas1;
import java.io.*;
public class Readfile {
    public static void main(String[] args) {
        try{
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
        catch(FileNotFoundException e) { 
            System.out.println("Muncul file Error FileNotFoundException File tidak tidak ditemukan");
        }
        catch(IOException e){
            System.out.println("Muncul ErrorIOExceptio ");
        }
    }
}

