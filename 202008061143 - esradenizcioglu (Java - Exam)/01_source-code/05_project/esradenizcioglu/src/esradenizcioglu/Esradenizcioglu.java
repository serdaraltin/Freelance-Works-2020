package esradenizcioglu;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Esradenizcioglu {

    public static void main(String[] args) {
        int[] dizi = new int[5];
        oku(dizi);
        pivotOku(dizi);
    }

    public static void oku(int[] dizi) {
        try {
            File dosya = new File("input.txt");
            Scanner scanner = new Scanner(dosya);
            int i = 0;

            while (scanner.hasNextLine()) {
                if (i == 5) {
                    break;
                }
                String line = scanner.nextLine();
                dizi[i] = Integer.parseInt(line);
                i++;
            }
        } catch (FileNotFoundException ex) {
            
        }
    }

    public static int pivotOku(int[] a) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Pivot değeri => ");
        int pivot =  scanner.nextInt();
        System.out.print(pivot+" sayısı {");
        for (int i : a) {
            System.out.print(i+" ");
        }
        System.out.println("} içinde "+say(a,pivot)+" kez geçmektedir.");
        return pivot;
    }

    public static int say(int[] dizi, int pivot) {
        int adet = 0;
        for (int i : dizi) {
            if(i==pivot)
                adet++;
        }
        return adet;
    }

}
