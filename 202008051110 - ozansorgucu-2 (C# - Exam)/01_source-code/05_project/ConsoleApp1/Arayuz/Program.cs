/*
 * 4. Arayüz nedir? Örnek bir program yazarak kendi ifadelerinizle açıklayınız?
 * 
 * Arayüz(Interface): Sınıflara ne yapacaklarını söyleyen, hangi değişkenlerin ve methodların
 * kullanılacağını bildiren, rehberlik eden yapılardır.
 * 
 */


using System;

namespace Arayuz
{
    class Program
    {
        static void Main(string[] args)
        {
            //IslemNo sınıfından üretilen "islem1" nesnesi ve değer ataması
            IslemNo islem1 = new IslemNo("001", "05/08/2020", 500.00);
            //IslemNo sınıfından üretilen "islem2" nesnesi ve değer ataması
            IslemNo islem2 = new IslemNo("002", "05/08/2020", 650.00);
            //islem1 nesnesi "islemgoster" methodu çağrılması
            islem1.islemgoster();
            //islem1 nesnesi "islemgoster" methodu çağrılması
            islem2.islemgoster();

            Console.ReadKey();

        }
    }
    //Iislemler arayüzü
    interface Iislemler
    {
        //arayüz method bildirimleri
        void islemgoster();
        double tutargetir();
    }
    //IslemNo sınıfı, arayüz olarak Iislemler
    class IslemNo : Iislemler
    {
        private string islemkodu;
        private string Tarih;
        private double Tutar;
        public IslemNo()
        {
            islemkodu = " ";
            Tarih = " ";
            Tutar = 0.0;
        }

        public IslemNo(string c, string d, double a)
        {
            islemkodu = c;
            Tarih = d;
            Tutar = a;
        }

        public double tutargetir()
        {
            return Tutar;
        }
        public void islemgoster()
        {
            Console.WriteLine("İşlem No: {0}", islemkodu);
            Console.WriteLine("Tarih: {0}", Tarih);
            Console.WriteLine("Tutar: {0}", tutargetir());
        }
    }
}
