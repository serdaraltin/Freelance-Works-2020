using System;
using System.Drawing;

namespace B181210010
{
    public class Atik : IAtik
    {
        public Atik()
        {
        }
        public Atik(string tur, string ad, int hacim)
        {
            Tur = tur;
            Ad = ad;
            Hacim = hacim;
            Image = Image.FromFile(ad + ".jpg");
        }

        public string Ad
        { get; set; }

        public int Hacim
        { get; set; }

        public Image Image
        { get; set; }

        public string Tur
        { get; set; }
    }

}
