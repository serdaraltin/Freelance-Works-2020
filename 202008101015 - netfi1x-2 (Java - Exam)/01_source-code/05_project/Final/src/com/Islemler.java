package com;

import com.interfaces.IButunIslemler;
import java.util.ArrayList;
import java.util.Scanner;

public class Islemler implements IButunIslemler{

    @Override
    public ArrayList<Ogrenci> NotGir() {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Ogrenci> ogrenciler = new ArrayList<Ogrenci>();
        
        System.out.print("Kac ogrenciye ait not girilecek? ");
        int ogrSayisi = scanner.nextInt();
        
        for (int i = 0; i < ogrSayisi; i++) {
            System.out.print(i+1+". ogrencinin notu : ");
            int not = scanner.nextInt();
            ogrenciler.add(new Ogrenci(not));
        }
        return ogrenciler;
    }

    @Override
    public float OrtalamaHesapla(ArrayList<Ogrenci> ogrenciler) {
        float ortalama = 0;
        float toplam = 0;
        for (int i = 0; i < ogrenciler.size(); i++) {
            toplam += ogrenciler.get(i).not;
        }
        ortalama = toplam / ogrenciler.size();
        return ortalama;
    }

}
