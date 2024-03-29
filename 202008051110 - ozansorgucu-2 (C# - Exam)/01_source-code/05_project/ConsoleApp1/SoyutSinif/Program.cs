﻿/*
 * 2. Soyut Sınıflar nedir? Örnek bir program yazarak kendi ifadelerinizle açıklayınız?
 * 
 * Soyut Sınıf(Abstract Class) : Tamamen kalıtım amaçlı kullanılan temel sınıfları oluştururken Abstrack
 * anahtar sözcüğü kullanılır. Soyut bir sınıf oluşturabilmek için erişim belirtecleri kullanılır.
 * 
 */

using System;


namespace SoyutSinif
{
    //Programın ana sınıfı
    class Program
    {
        //Main methodu
        static void Main(string[] args)
        {
            //TuretilmisSinif sınıfından oluşturulan "turetilmisSinif" nesnesi
            TuretilmisSinif turetilmisSinif = new TuretilmisSinif();
            //turetilmisSinif sınıfının "Metot_1" methodunun çağrılması.
            turetilmisSinif.Metot_1();
            //turetilmisSinif sınıfının "Metot_2" methodunun çağrılması.
            turetilmisSinif.Metot_2();

            Console.ReadKey();
        }
    }

    //TemelSinif, soyut sınıf.
    public abstract class TemelSinif
    {
        public void Metot_1()
        {
            Console.WriteLine("Abstract sınıf içerisinde tanımlanmış metot.");
        }

        public abstract void Metot_2();
    }
    //Temel sınıftan türetilmiş sınıf.
    public class TuretilmisSinif : TemelSinif
    {
        //Soyut sınıftan kalıtılınan "Metot_2" nin içeriğinin eklenmesi.
        public override void Metot_2()
        {
            Console.WriteLine("Türetilmiş sınıf içerisinde tanımlanmış metot.");
        }
    }

}
