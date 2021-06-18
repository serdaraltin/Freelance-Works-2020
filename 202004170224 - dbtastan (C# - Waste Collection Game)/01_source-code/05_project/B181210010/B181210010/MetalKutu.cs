using System;
using System.Drawing;

namespace B181210010
{
    public class MetalKutu : IAtikKutusu
    {
        public int BosaltmaPuani
        {
            get
            {
                return 800;
            }
        }

        public int DoluHacim
        {
            get; set;
        }

        public int DolulukOrani
        {
            get
            {
                return  (DoluHacim / (Kapasite / 100));
            }
        }

        public int Kapasite 
        {
            get
            {
                return 2300;
            }
        }

        public bool Bosalt()
        {
            if(DolulukOrani > 75)
            {
                DoluHacim = 0;
                return true;
            }
            return false;
        }

        public bool Ekle(Atik atik)
        {
            if (Kapasite - DoluHacim >= atik.Hacim)
            {
                
                DoluHacim = DoluHacim + atik.Hacim;
                return true;
            }
            return false;
        }
    }
}
