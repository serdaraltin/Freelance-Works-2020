using System;
using System.IO;

namespace _05_project
{
    class Program
    {
        static string[] DosyaOku(string dosyaAdi)
        {
            string[] kelimeler = File.ReadAllLines(dosyaAdi);
            for (int i = 0; i < kelimeler.Length; i++)
            {
                kelimeler[i] = kelimeler[i].ToLower();
            }
            return kelimeler;
        }
        static int IndexNo(string cumle, string kelime)
        {
            return cumle.IndexOf(kelime);
        }
        static bool VarMi(string cumle, string kelime)
        {
            char[] cumleDizi = cumle.ToCharArray();
            char[] kelimeDizi = kelime.ToCharArray();

            for (int i = 0; i < cumleDizi.Length; i++)
            {
                if (cumleDizi[i] == kelimeDizi[0])
                {
                    for (int j = 0, k = i; j < kelimeDizi.Length; j++, k++)
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
        static bool BaslangicVarMi(string cumle, string kelime)
        {
            char[] cumleDizi = cumle.ToCharArray();
            char[] kelimeDizi = kelime.ToCharArray();

            for (int i = 0; i < kelimeDizi.Length; i++)
            {
                if (cumleDizi[i] != kelimeDizi[i])
                {
                    return false;
                }
            }

            return true;
        }
        static string EnBuyukParca(string pcumle, string[] kelimeler)
        {
            string cumle = pcumle.ToLower();
            string sonKelime = "";

            foreach (string kelime in kelimeler)
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
        static string Eksilt(string pcumle, int uzunluk)
        {
            string parca = pcumle.Substring(0, uzunluk);
            Console.Write(parca + " ");
            pcumle = pcumle.Remove(0, uzunluk);
            return pcumle;
        }

        static void Main(string[] args)
        {
            string[] kelimeler = DosyaOku("words.txt");

            string cumle = "Erişmekistedikleribirhedefiolmayanlarçalışmaktanzevkalmazlar";
            int cumleUzunluk = cumle.Length;
            Console.WriteLine("Girdi >> \n\n\t" + cumle);
            Console.WriteLine("\nSözlük >>\n");
            foreach (string kelime in kelimeler)
            {
                Console.Write(kelime + " ");
            }
            Console.WriteLine("\n\nSonuç >> \n\t");
            while (cumle.Length > 0)
            {
                if (cumle.Length == cumleUzunluk)
                {
                    Console.Write("\t");
                }
                cumle = Eksilt(cumle, EnBuyukParca(cumle, kelimeler).Length);
            }
            Console.WriteLine();
            Console.ReadKey();


        }


    }
}
