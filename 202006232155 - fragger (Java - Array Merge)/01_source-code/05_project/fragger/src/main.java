import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class main {

    public static void main(String[] args) {
        int array[] = FileRead("diziler.txt");
        array = siralamaYap(array);
        FileWrite("siralanmisDiziler.txt", array);
        Scanner scn = new Scanner(System.in);

        System.out.print("Aranacak Sayi : ");
        while (scn.hasNextInt()) {
            Find("siralanmisDiziler.txt", scn.nextInt());
            System.out.print("Aranacak Sayi : ");
        }
        System.out.println("Program sonlandirildi.");
        System.exit(0);
    }

    public static int[] FileRead(String fileName) {
        try {
            int array1Size = 0, array2Size = 0;
        
            File file = new File(fileName);
            Scanner scn1 = new Scanner(file);
            Scanner scn2 = new Scanner(file);

            boolean array2Add = false;

            while (scn1.hasNextLine()) {
                String line = scn1.nextLine();
                
                if (line.equals("dizi1")) {
                    continue;
                } 
                else if (line.equals("dizi2")) {
                    array2Add = true;
                    continue;
                }

                if (array2Add) {
                    array2Size++;
                } 
                else {
                    array1Size++;
                }
            }

            int array1[] = new int[array1Size];
            int array2[] = new int[array2Size];        
            array2Add = false;
            int i = 0;
            while (scn2.hasNextLine()) {
                String line = scn2.nextLine();
                
                if (line.equals("dizi1")) {
                    continue;
                } else if (line.equals("dizi2")) {
                    array2Add = true;
                    i = 0;
                    continue;
                }
                if (array2Add) {
                    array2[i] = Integer.parseInt(line);
                } 
                else {
                    array1[i] = Integer.parseInt(line);
                }
                i++;
            }
            array1 = siralamaYap(array1);
            array2 = siralamaYap(array2);

            int array3[] = arrayleriBirlestir(array1, array2);
            return array3;
        } catch (FileNotFoundException ex) {
            Logger.getLogger(main.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    public static int[] siralamaYap(int array[]) {
        for (int j = 0; j < array.length; j++) {
            for (int k = 0; k < array.length; k++) {
                if (array[j] < array[k]) {
                    int gecici = array[j];
                    array[j] = array[k];
                    array[k] = gecici;
                }
            }
        }
        return array;
    }

    public static int[] arrayleriBirlestir(int array1[], int array2[]) {
        int array[] = new int[array1.length + array2.length];

        for (int j = 0; j < array1.length; j++) {
            array[j] = array1[j];
        }

        for (int j = array1.length; j < array.length; j++) {
            array[j] = array2[j - array1.length];
        }
        return array;
    }

    public static boolean FileWrite(String fileName, int array[]) {
        FileWriter writeFile = null;
        try {
            File file = new File(fileName);
            if (file.exists()) {
                PrintWriter pwriter = new PrintWriter(file);
                pwriter.print("");
                pwriter.close();
            } 
            else {
                file.createNewFile();
            }

            writeFile = new FileWriter(file, true);

            try (BufferedWriter bufferWriter = new BufferedWriter(writeFile)) {
                for (int i : array) {
                    bufferWriter.write(String.valueOf(i));
                    bufferWriter.newLine();
                }
                return true;
            }
        } catch (IOException ex) {
            System.err.println(ex);
            return false;
        }
    }

    public static void Find(String fileName, int num) {
        try {
            File file = new File(fileName);

            if (!file.exists()) {
                System.out.println("Dosya mevcut degil!");
            }
            Scanner scn = new Scanner(file);

            int i = 1;
            while (scn.hasNextLine()) {
                String line = scn.nextLine();
                if (line.equals(String.valueOf(num))) {
                    System.out.println("Aradiginiz sayi fileda " + i + ". lineda bulunmaktadir.");
                    return;
                }
                i++;
            }
            System.out.println("Aradiginiz sayi bulunamadi.");
        } catch (FileNotFoundException ex) {
            System.err.println(ex);
        }
    }

}
