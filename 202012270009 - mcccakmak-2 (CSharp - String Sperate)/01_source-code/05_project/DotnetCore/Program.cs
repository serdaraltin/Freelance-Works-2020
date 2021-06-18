using System;
using System.IO;

namespace _05_project
{
    class Program
    {
        static dynamic DosyaOku(dynamic dosyaAdi)
        {
            dynamic kelimeler = File.ReadAllLines(dosyaAdi);
            for (dynamic i = 0; i < kelimeler.Length; i++)
            {
                kelimeler[i] = kelimeler[i].ToLower();
            }
            return kelimeler;
        }
        static dynamic IndexNo(dynamic cumle, dynamic kelime)
        {
            return cumle.IndexOf(kelime);
        }
        static dynamic VarMi(dynamic cumle, dynamic kelime)
        {
            dynamic cumleDizi = cumle.ToCharArray();
            dynamic kelimeDizi = kelime.ToCharArray();

            for (dynamic i = 0; i < cumleDizi.Length; i++)
            {
                if (cumleDizi[i] == kelimeDizi[0])
                {
                    for (dynamic j = 0, k = i; j < kelimeDizi.Length; j++, k++)
                    {
                        if (cumleDizi[k] == kelimeDizi[j] && j == kelimeDizi.Length - 1)
                        {
                            return true;
                        }
                    }
                }
            }

            return false;
        }
        static dynamic BaslangicVarMi(dynamic cumle, dynamic kelime)
        {
            dynamic cumleDizi = cumle.ToCharArray();
            dynamic kelimeDizi = kelime.ToCharArray();

            for (dynamic i = 0; i < kelimeDizi.Length; i++)
            {
                if (cumleDizi[i] != kelimeDizi[i])
                {
                    return false;
                }
            }

            return true;
        }
        static dynamic EnBuyukParca(dynamic pcumle, dynamic[] kelimeler)
        {
            dynamic cumle = pcumle.ToLower();
            dynamic sonKelime = "";

            foreach (dynamic kelime in kelimeler)
            {
                if (BaslangicVarMi(cumle, kelime) && IndexNo(cumle, kelime) != -1)
                {
                    if (kelime.Length > sonKelime.Length)
                    {
                        sonKelime = kelime;
                    }
                }
            }

            return sonKelime;
        }
        static dynamic Eksilt(dynamic pcumle, dynamic uzunluk)
        {
            dynamic parca = pcumle.Substring(0, uzunluk);
            Console.Write(parca + " ");
            pcumle = pcumle.Remove(0, uzunluk);
            return pcumle;
        }

        static void Main(string[] args)
        {
            dynamic kelimeler = DosyaOku("words.txt");

            dynamic cumle = "Erişmekistedikleribirhedefiolmayanlarçalışmaktanzevkalmazlar";
            dynamic cumleUzunluk = cumle.Length;
            Console.WriteLine("Girdi >> \n\n\t"+cumle);
            Console.WriteLine("\nSözlük >>\n");
            foreach(dynamic kelime in kelimeler){
                Console.Write(kelime+" ");
            }
            Console.WriteLine("\n\nSonuç >> \n\t");
            while (cumle.Length > 0)
            {
                if(cumle.Length == cumleUzunluk){
                    Console.Write("\t");
                }
                cumle = Eksilt(cumle, EnBuyukParca(cumle, kelimeler).Length);
            }
            Console.WriteLine();
            Console.ReadKey();


        }


    }
}
