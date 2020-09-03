package Soru2;

import java.util.Scanner;

public class Calistirilabilir {

    Islem islem = new Islem();

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.print("Sayi : ");
        int sayi = scn.nextInt();
        System.out.println("Iteratif : " + Islem.Fibonacci1(sayi));
        System.out.println("Rekursif : " + Islem.Fibonacci2(sayi));
    }
}
