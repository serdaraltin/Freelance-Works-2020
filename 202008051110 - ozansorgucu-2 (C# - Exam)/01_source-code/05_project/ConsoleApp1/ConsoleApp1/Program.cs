﻿
/*
 * 1. Kalıtım nedir? Örnek bir program yazarak kendi ifadelerinizle açıklayınız?
 * 
 * Kalıtım : Nesneye yönelik programlamanın en önemli özelliklerinden biridir.
 * Miras alama yoluyla sınıfların birbirinden türetilmesidir.
 * Mevcut sınıflardan yeni bir sınıf üretme şeklidir.
 * Türeyen sınıf(türemiş sınıf) kendisinden yeni sınıfların oluşturulduğu sınıflara ise temel sınıf denir.
 * 
 */


using System;

namespace Kalitim
{
   

    //Programın ana sınıfı
    class Program
    {
        //Main methodu
        static void Main(string[] args)
        {
            //Insan sınıfından üretilen "insan" nesnesi
            Insan insan = new Insan();
            //insan nesnesine ilgili değerlerin atanması
            insan.el = 2;
            insan.ayak = 2;
            //insan nesnesinin "Konus" methodunun çağrılması
            insan.Konus();

            //Kopek sınıfından üretilen "kopek" nesnesi
            Kopek kopek = new Kopek();
            //kopek nesnesine ilgili değerlerin atanması
            kopek.el = 0;
            kopek.ayak = 4;
            //kopek nesnesinin "Havla" methodunun çağrılması
            kopek.Havla();

            Console.ReadKey();
        }
    }

    //Canli sınıfı
    class Canli
    {
        public int el;
        public int ayak;

    }
    //Kopek sınıfı : Canlı sınıfından kalıtım yapmıştır
    class Kopek : Canli
    {
        public void Havla()
        {
            Console.WriteLine("Hav Hav");
        }
    }

    //Insan sınıfı : Canlı sınıfından kalıtım yapmıştır
    class Insan : Canli
    {
        public void Konus()
        {
            Console.WriteLine("Merhaba benim "+el+" adet elim ve"+ayak+" adet ayağım var.");
        }
    }
}