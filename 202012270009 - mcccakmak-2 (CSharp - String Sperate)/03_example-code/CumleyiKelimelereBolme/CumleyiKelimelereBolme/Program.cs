using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CumleyiKelimelereBolme
{
    class Program
    {
        static void Main(string[] args)
        {
            string metin = "Erişmekistedikleribirhedefiolmayanlarçalışmaktanzevkalmazlar";
            string[] kelimeler = DosyaOku("kelimeler.txt");

            foreach (string item in kelimeler)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine();
 
            Console.ReadKey();
        }

         

        static string[] DosyaOku(string dosya)
        {
            return File.ReadAllLines(dosya);
        }
    }
}
