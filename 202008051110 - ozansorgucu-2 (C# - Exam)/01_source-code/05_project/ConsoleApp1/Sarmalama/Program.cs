﻿/*
 * 5. Sarmalama/Paketleme (Kapsülleme) nedir? Örnek bir program yazarak kendi ifadelerinizle
 * açıklayınız?
 * 
 * Kapsülleme (Encapsulation): Nesne tabanlı programlamanın en önemli bölümlerinden birisidir.
 * Kapsüllemenin görevi verileri hatalı kullanım ve dış etkenlerden korumaktır.
 * 
 */


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sarmalama
{
    //Programın ana sınıfı
    class Program
    {
        //Main methodu
        static void Main(string[] args)
        {
            //Ogrenci sınıfından "yeni" adından nesne tanımlanması
            Ogrenci yeni = new Ogrenci();
            //yeni nesnesinin ogrenciadsoyad değişkenine değer atanması
            yeni.Ogrenciadsoyad = "Fatma Yağmur";
            //yeni nesnesinin bolum değişkenine değer atanması
            yeni.Bolum = "Bilgisayar Programcılığı";
            //yeni nesnesinin ogrencino değişkenine değer atanması
            yeni.Ogrencino = 120;
            //yeni nesnesinin "Yaz" methodunun çağrılması
            yeni.Yaz();

            Console.ReadKey();
        }
    }
    //Ogrenci sinifi
    class Ogrenci
    {
        //değişkenlerin private(özel) tanımlanması
        private string ogrenciadsoyad;
        private string bolum;
        private int ogrencino;

        //ogrenciadsoyad değişkeninin kapsüllenmesi
        public string Ogrenciadsoyad{
            get { return ogrenciadsoyad; }
            set { ogrenciadsoyad = value; }
        }

        //bolum değişkeninin kapsüllenmesi
        public string Bolum{
            get { return bolum; }
            set { bolum = value; }
        }

        //ogrencino değişkeninin kapsüllenmesi
        public int Ogrencino
        {
            get { return ogrencino; }
            set{
                if (value < 0){
                    ogrencino = 0;
                }
                else{
                    ogrencino = value;
                }
            }
        }
        //Yaz methodu
        public void Yaz()
        {
            Console.WriteLine("Öğrenci Adı {0}", ogrenciadsoyad);
            Console.WriteLine("Öğrenci Bölümü {0}", bolum);
            Console.WriteLine("Öğrenci Numarası {0}", ogrencino);
        }
    }
  

}