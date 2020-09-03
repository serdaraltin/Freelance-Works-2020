package Soru3;

import java.util.Random;

public class Islem2 {

    public static void Method1(int[] dizi) {
        
        int min = 11, max = 1500000;
        for (int i = 0; i < 10; i++) {
            Random random = new Random();
            dizi[i] = random.nextInt((max - min) + 1) + min;
        }
       // dizi[2] = 371;
       // dizi[3] = 121;
        
        
        for (int i : dizi) {
            System.out.print(i + " ");
        }
        System.out.println();
      
        Method2(dizi);
    }

    public static void Method2(int[] dizi) {
        boolean armstrong = true;

        for (int i = 0; i < 10; i++) {

            int basamak = 1;
            int gecici = dizi[i];
            do {
                gecici = gecici / 10;
                basamak++;
            } while (gecici >= 10);

            int c = 0, a, temp;
            int n = dizi[i];
            temp = n;
            while (n > 0) {
                a = n % 10;
                n = n / 10;
                c = c + (int) Math.pow(a, basamak);
            }

            if (temp == c) {
                System.out.println("Armstrong [" + i + "] > " + dizi[i]);
                armstrong = false;
            }

        }

        if (armstrong) {
            System.out.println("Dizide armstrong sayisi bulunamadi!!!");
        }
        Method3(dizi);
    }

    public static void Method3(int[] dizi) {
        boolean palindrome = true;

        for (int i = 0; i < 10; i++) {
            int r, sum = 0, temp;
            int n = dizi[i];

            temp = n;
            while (n > 0) {
                r = n % 10;
                sum = (sum * 10) + r;
                n = n / 10;
            }
            if (temp == sum) {
                System.out.println("Palindrome [" + i + "] > " + dizi[i]);
                palindrome = false;
            }
        }
        if (palindrome) {
            System.out.println("Dizide palindrome sayisi bulunamadi!!!");
        }
    }
}
