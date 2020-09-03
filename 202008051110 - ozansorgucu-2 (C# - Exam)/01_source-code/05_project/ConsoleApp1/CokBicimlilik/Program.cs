/*
 * 3. Çok biçimlilik nedir? Örnek bir program yazarak kendi ifadelerinizle açıklayınız?
 * 
 * Çok Biçimlilik(Polymorphizm): Bir sınıf başka bir sınıftan türetildiğindan tüm özelliklerini miras alır.
 * Türetilmiş olan sınıf içerisinde türetilen sınıftan gelen bazı özelliklerin değiştirilmesi çok biçimliliktir.
 * Miras aldığı bir methodun içeriğinin değiştirilmesi çok biçimlilik örneğidir.
 * 
 */

using System;

namespace CokBicimlilik
{
    //Programın ana sınıfı
    class Program
    {
        //Main methodu
        static void Main(string[] args)
        {
            //Sinif1 sınıfından üretilen "s1" nesnesi
            Sinif1 s1 = new Sinif1();
            //s1 nesnesinin "yaz" methodunun çağrılması
            s1.yaz();

            //Sinif2 sınıfından üretilen "s2" nesnesi
            Sinif2 s2 = new Sinif2();
            //s2 nesnesinin "yaz" methodunun çağrılması
            s2.yaz();

            Console.ReadKey();
        }
    }

    //TememSinif
    class TemelSinif
    {
        public virtual void yaz()
        {
        }
    }

    //Sinif1 , TememSinif dan türetilmiştir
    class Sinif1 : TemelSinif
    {
        //Ovverride ile üst sınıfın methodu görmezden gelinir ve çok biçimlilik sağlanır.
        public override void yaz()
        {
            Console.WriteLine("sınıf 1");
        }
    }
    //Sinif2 , TememSinif dan türetilmiştir
    class Sinif2 : TemelSinif
    {
        //Ovverride ile üst sınıfın methodu görmezden gelinir ve çok biçimlilik sağlanır.
        public override void yaz()
        {
            Console.WriteLine("sınıf 2");
        }
    }
}

