using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Text;
using System.Data;
using System.Collections;

namespace KomurArdiyesi
{
    class Class_VeritabaniIslemleri
    {
        SqlConnection baglanti = new SqlConnection("Data Source=" + Ayarlar.Default.Sunucu + ";Initial Catalog=" + Ayarlar.Default.Veritabani + ";Integrated Security=True");

        //BAĞLANTI TEST
        public bool BaglantiTest()
        {
            try
            {
                baglanti.Open();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }

        //FİRMA İŞLEMLERİ
        public bool FirmaEkle(string Ad, string Mail)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("FirmaEkle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Ad", Ad);
                komut.Parameters.AddWithValue("@Mail", Mail);
                komut.ExecuteNonQuery();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool FirmaGuncelle(int Id, string Ad, string Mail)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("FirmaGuncelle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.Parameters.AddWithValue("@Ad", Ad);
                komut.Parameters.AddWithValue("@Mail", Mail);
                komut.ExecuteNonQuery();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool FirmaSil(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("FirmaSil", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.ExecuteNonQuery();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public List<string> FirmalarAd()
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Firmalar", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                SqlDataReader oku = komut.ExecuteReader();
                List<string> veriler = new List<string>();
                while (oku.Read())
                {
                    veriler.Add(oku["Ad"].ToString().Trim());
                }
                baglanti.Close();
                return veriler;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public string[] FirmaBilgi(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("FirmaBilgi", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = {
                        oku["Ad"].ToString().Trim(),
                        oku["Mail"].ToString().Trim()
                    };

                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public string[] FirmaBilgi(string Ad)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("FirmaBilgiGetAd", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Ad", Ad);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = {
                        oku["Id"].ToString().Trim(),
                        oku["Ad"].ToString().Trim(),
                        oku["Mail"].ToString().Trim()
                    };

                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public DataSet Firmalar()
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Firmalar", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                SqlDataAdapter da = new SqlDataAdapter(komut);
                DataSet veriler = new DataSet();
                da.Fill(veriler);
                baglanti.Close();
                return veriler;

            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }

        //MÜSTERİ İŞLEMLERİ
        public bool MusteriEkle(string TcNo, string Ad, string Soyad, string Telefon, string Eposta, string Sehir, string Ilce, string Adres)
        {
            try
            {
                baglanti.Open();

                SqlCommand komut = new SqlCommand("MusteriEkle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@TcNo", TcNo);
                komut.Parameters.AddWithValue("@Ad", Ad);
                komut.Parameters.AddWithValue("@Soyad", Soyad);
                komut.Parameters.AddWithValue("@Telefon", Telefon);
                komut.Parameters.AddWithValue("@Eposta", Eposta);
                komut.Parameters.AddWithValue("@Sehir", Sehir);
                komut.Parameters.AddWithValue("@Ilce", Ilce);
                komut.Parameters.AddWithValue("@Adres", Adres);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;

            }
            catch
            {
                baglanti.Close();
                return true;
            }
        }
        public bool MusteriGuncelle(int Id, string TcNo, string Ad, string Soyad, string Telefon, string Eposta, string Sehir, string Ilce, string Adres)
        {
            try
            {
                baglanti.Open();

                SqlCommand komut = new SqlCommand("MusteriGuncelle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.Parameters.AddWithValue("@TcNo", TcNo);
                komut.Parameters.AddWithValue("@Ad", Ad);
                komut.Parameters.AddWithValue("@Soyad", Soyad);
                komut.Parameters.AddWithValue("@Telefon", Telefon);
                komut.Parameters.AddWithValue("@Eposta", Eposta);
                komut.Parameters.AddWithValue("@Sehir", Sehir);
                komut.Parameters.AddWithValue("@Ilce", Ilce);
                komut.Parameters.AddWithValue("@Adres", Adres);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;

            }
            catch
            {
                baglanti.Close();
                return true;
            }
        }
        public bool MusteriSil(int Id)
        {
            try
            {
                baglanti.Open();

                SqlCommand komut = new SqlCommand("MusteriSil", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;

            }
            catch
            {
                baglanti.Close();
                return true;
            }
        }
        public string[] MusteriBilgi(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("MusteriBilgi", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = {
                        oku["TcNo"].ToString().Trim(),
                        oku["Ad"].ToString().Trim(),
                        oku["Soyad"].ToString().Trim(),
                        oku["Telefon"].ToString().Trim(),
                        oku["Eposta"].ToString().Trim(),
                        oku["Sehir"].ToString().Trim(),
                        oku["Ilce"].ToString().Trim(),
                        oku["Adres"].ToString().Trim()
                    };

                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public DataSet Musteriler()
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Musteriler", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                SqlDataAdapter da = new SqlDataAdapter(komut);
                DataSet veriler = new DataSet();
                da.Fill(veriler);
                baglanti.Close();
                return veriler;

            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }

        //ÖDEME İŞLEMLERİ
        public bool OdemeEkle(int MusteriId, float Tutar, DateTime SiparisTarih, DateTime OdemeTarih, string FaturaNo, string OdemeYontem, DateTime GirisTarih, DateTime CikisTarih)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("OdemeEkle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Musteri_Id", MusteriId);
                komut.Parameters.AddWithValue("@Tutar", Tutar);
                komut.Parameters.AddWithValue("@SiparisTarih", SiparisTarih);
                komut.Parameters.AddWithValue("@OdemeTarih", OdemeTarih);
                komut.Parameters.AddWithValue("@FaturaNo", FaturaNo);
                komut.Parameters.AddWithValue("@OdemeYontem", OdemeYontem);
                komut.Parameters.AddWithValue("@GirisTarih", GirisTarih);
                komut.Parameters.AddWithValue("@CikisTarih", CikisTarih);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool OdemeGuncelle(int Id, int MusteriId, float Tutar, DateTime SiparisTarih, DateTime OdemeTarih, string FaturaNo, string OdemeYontem, DateTime GirisTarih, DateTime CikisTarih)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("OdemeGuncelle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.Parameters.AddWithValue("@Musteri_Id", MusteriId);
                komut.Parameters.AddWithValue("@Tutar", Tutar);
                komut.Parameters.AddWithValue("@SiparisTarih", SiparisTarih);
                komut.Parameters.AddWithValue("@OdemeTarih", OdemeTarih);
                komut.Parameters.AddWithValue("@FaturaNo", FaturaNo);
                komut.Parameters.AddWithValue("@OdemeYontem", OdemeYontem);
                komut.Parameters.AddWithValue("@GirisTarih", GirisTarih);
                komut.Parameters.AddWithValue("@CikisTarih", CikisTarih);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool OdemeSil(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("OdemeSil", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public string[] OdemeBilgi(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("OdemeBilgi", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = {
                        oku["Musteri_Id"].ToString().Trim(),
                        oku["Tutar"].ToString().Trim(),
                        oku["SiparisTarih"].ToString().Trim(),
                        oku["OdemeTarih"].ToString().Trim(),
                        oku["FaturaNo"].ToString().Trim(),
                        oku["OdemeYontem"].ToString().Trim(),
                        oku["GirisTarih"].ToString().Trim(),
                        oku["CikisTarih"].ToString().Trim()
                    };

                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public DataSet Odemeler()
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Odemeler", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                SqlDataAdapter da = new SqlDataAdapter(komut);
                DataSet veriler = new DataSet();
                da.Fill(veriler);
                baglanti.Close();
                return veriler;

            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }

        //SİPARİŞ İŞLEMLERİ
        public bool SiparisEkle(int MusteriId, DateTime SiparisTarih, DateTime TeslimatTarih, string TeslimatAdres)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("SiparisEkle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Musteri_Id", MusteriId);
                komut.Parameters.AddWithValue("@SiparisTarih", SiparisTarih);
                komut.Parameters.AddWithValue("@TeslimatTarih", TeslimatTarih);
                komut.Parameters.AddWithValue("@TeslimatAdres", TeslimatAdres);

                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool SiparisGuncelle(int Id, int MusteriId, DateTime SiparisTarih, DateTime TeslimatTarih, string TeslimatAdres)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("SiparisGuncelle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.Parameters.AddWithValue("@Musteri_Id", MusteriId);
                komut.Parameters.AddWithValue("@SiparisTarih", SiparisTarih);
                komut.Parameters.AddWithValue("@TeslimatTarih", TeslimatTarih);
                komut.Parameters.AddWithValue("@TeslimatAdres", TeslimatAdres);

                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool SiparisSil(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("SiparisSil", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public string[] SiparisBilgi(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("SiparisBilgi", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = {
                        oku["Musteri_Id"].ToString().Trim(),
                        oku["SiparisTarih"].ToString().Trim(),
                        oku["TeslimatTarih"].ToString().Trim(),
                        oku["TeslimatAdres"].ToString().Trim()
                    };

                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public DataSet Siparisler()
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Siparisler", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                SqlDataAdapter da = new SqlDataAdapter(komut);
                DataSet veriler = new DataSet();
                da.Fill(veriler);
                baglanti.Close();
                return veriler;

            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }


        //SİPARİŞ DETAY İŞLEMLERİ
        public bool SiparisDetayEkle(int Siparis_Id, int Urun_Id, int Miktar, float Fiyat)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Siparis_DetayEkle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Siparis_Id", Siparis_Id);
                komut.Parameters.AddWithValue("@Urun_Id", Urun_Id);
                komut.Parameters.AddWithValue("@Miktar", Miktar);
                komut.Parameters.AddWithValue("@Fiyat", Fiyat);
                komut.ExecuteNonQuery();
                baglanti.Close();

                int Tumu = Convert.ToInt32(UrunBilgi(Urun_Id)[3]);
                UrunGuncelleMiktar(Urun_Id, (Tumu - Miktar));
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool SiparisDetayGuncelle(int Id, int Siparis_Id, int Urun_Id, int Miktar, float Fiyat)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Siparis_DetayGuncelle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.Parameters.AddWithValue("@Siparis_Id", Siparis_Id);
                komut.Parameters.AddWithValue("@Urun_Id", Urun_Id);
                komut.Parameters.AddWithValue("@Miktar", Miktar);
                komut.Parameters.AddWithValue("@Fiyat", Fiyat);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool SiparisDetaySil(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Siparis_DetaySil", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public DataSet Siparis_Detaylar(int Siparis_Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Siparis_Detaylar", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Siparis_Id", Siparis_Id);
                SqlDataAdapter da = new SqlDataAdapter(komut);
                DataSet veriler = new DataSet();
                da.Fill(veriler);
                baglanti.Close();
                return veriler;

            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }

        //TOPTANCI İŞLEMLERİ
        public bool ToptanciEkle(int FirmaId, string Telefon, string Mail, string Adres)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("ToptanciEkle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Firma_Id", FirmaId);
                komut.Parameters.AddWithValue("@Telefon", Telefon);
                komut.Parameters.AddWithValue("@Mail", Mail);
                komut.Parameters.AddWithValue("@Adres", Adres);
                komut.ExecuteNonQuery();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool ToptanciGuncelle(int Id, int FirmaId, string Telefon, string Mail, string Adres)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("ToptanciGuncelle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.Parameters.AddWithValue("@Firma_Id", FirmaId);
                komut.Parameters.AddWithValue("@Telefon", Telefon);
                komut.Parameters.AddWithValue("@Mail", Mail);
                komut.Parameters.AddWithValue("@Adres", Adres);
                komut.ExecuteNonQuery();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool ToptanciSil(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("ToptanciSil", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.ExecuteNonQuery();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public string[] ToptanciBilgi(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("ToptanciBilgi", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = {
                        oku["Firma_Id"].ToString().Trim(),
                        oku["Telefon"].ToString().Trim(),
                        oku["Mail"].ToString().Trim(),
                        oku["Adres"].ToString().Trim(),
                    };
                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public DataSet Toptancilar()
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Toptancilar", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                SqlDataAdapter da = new SqlDataAdapter(komut);
                DataSet veriler = new DataSet();
                da.Fill(veriler);
                baglanti.Close();
                return veriler;

            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }

        //ÜRÜN İŞLEMLERİ
        public bool UrunEkle(string Barkod, string UrunAd, string Birim, int Miktar, float Fiyat, DateTime Giris_Tarih, DateTime Cikis_Tarih)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("UrunEkle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Barkod", Barkod);
                komut.Parameters.AddWithValue("@UrunAd", UrunAd);
                komut.Parameters.AddWithValue("@Birim", Birim);
                komut.Parameters.AddWithValue("@Miktar", Miktar);
                komut.Parameters.AddWithValue("@Fiyat", Fiyat);
                komut.Parameters.AddWithValue("@GirisTarih", Giris_Tarih);
                komut.Parameters.AddWithValue("@CikisTarih", Cikis_Tarih);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool UrunGuncelle(int Id, string Barkod, string UrunAd, string Birim, int Miktar, float Fiyat, DateTime Giris_Tarih, DateTime Cikis_Tarih)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("UrunGuncelle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.Parameters.AddWithValue("@Barkod", Barkod);
                komut.Parameters.AddWithValue("@UrunAd", UrunAd);
                komut.Parameters.AddWithValue("@Birim", Birim);
                komut.Parameters.AddWithValue("@Miktar", Miktar);
                komut.Parameters.AddWithValue("@Fiyat", Fiyat);
                komut.Parameters.AddWithValue("@GirisTarih", Giris_Tarih);
                komut.Parameters.AddWithValue("@CikisTarih", Cikis_Tarih);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool UrunSil(int Id)
        {
            try
            {
                baglanti.Open();

                SqlCommand komut = new SqlCommand("UrunSil", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;

            }
            catch
            {
                baglanti.Close();
                return true;
            }
        }
        public DataSet Urunler()
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Urunler", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                SqlDataAdapter da = new SqlDataAdapter(komut);
                DataSet veriler = new DataSet();
                da.Fill(veriler);
                baglanti.Close();
                return veriler;

            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public List<string> UrunlerAd()
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Urunler", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                SqlDataReader oku = komut.ExecuteReader();
                List<string> veriler = new List<string>();
                while (oku.Read())
                {
                    veriler.Add(oku["UrunAd"].ToString().Trim());
                }
                baglanti.Close();
                return veriler;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public string[] UrunBilgi(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("UrunBilgi", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = {
                        oku["Barkod"].ToString().Trim(),
                        oku["UrunAd"].ToString().Trim(),
                        oku["Birim"].ToString().Trim(),
                        oku["Miktar"].ToString().Trim(),
                        oku["Fiyat"].ToString().Trim(),
                        oku["GirisTarih"].ToString().Trim(),
                        oku["CikisTarih"].ToString().Trim(),

                    };
                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public string[] UrunBilgi(string UrunAd)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("UrunBilgiGetAd", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@UrunAd", UrunAd);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = {
                        oku["Id"].ToString().Trim(),
                        oku["Barkod"].ToString().Trim(),
                        oku["UrunAd"].ToString().Trim(),
                        oku["Birim"].ToString().Trim(),
                        oku["Miktar"].ToString().Trim(),
                        oku["Fiyat"].ToString().Trim(),
                        oku["GirisTarih"].ToString().Trim(),
                        oku["CikisTarih"].ToString().Trim(),

                    };
                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public bool UrunGuncelleMiktar(int Id, int Miktar)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("UrunGuncelleMiktar", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.Parameters.AddWithValue("@Miktar", Miktar);

                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }


        //YONETİCİ İŞLEMLERİ3
        public bool YoneticiVarlikKontrol()
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("YoneticiVarlikKontrol", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                SqlDataReader oku = komut.ExecuteReader();
                if (oku.Read())
                {
                    baglanti.Close();
                    return true;
                }
                return false;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool YoneticiKontrol(string KullaniciAd, string Parola)
        {
            try
            {
                baglanti.Open();        
                SqlCommand komut = new SqlCommand("YoneticiKontrol", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@KullaniciAd", KullaniciAd);
                komut.Parameters.AddWithValue("@Parola", Parola);
                SqlDataReader oku = komut.ExecuteReader();
                if (oku.Read())
                {
                    baglanti.Close();
                    return true;
                }
                return false;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool YoneticiEkle(string KullaniciAd, string Parola)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("YoneticiEkle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@KullaniciAd", KullaniciAd);
                komut.Parameters.AddWithValue("@Parola", Parola);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool YoneticiSil(string KullaniciAd, string Parola)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("YoneticiSil", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Kullaniciad", KullaniciAd);
                komut.Parameters.AddWithValue("@Parola", Parola);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool YoneticiGuncelle(int Id, string KullaniciAd, string Parola)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("YoneticiGuncelle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                komut.Parameters.AddWithValue("@KullaniciAd", KullaniciAd);
                komut.Parameters.AddWithValue("@Parola", Parola);
                komut.ExecuteNonQuery();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public string[] YoneticiBilgi(int Id)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("YoneticiBilgi", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Id", Id);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = { oku["KullaniciAd"].ToString().Trim(), oku["Parola"].ToString().Trim() };
                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public string[] YoneticiBilgiGetAd(string KullaniciAd)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("YoneticiBilgiGetAd", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@KullaniciAd", KullaniciAd);
                SqlDataReader oku = komut.ExecuteReader();

                if (oku.Read())
                {
                    string[] veriler = { oku["Id"].ToString().Trim(), oku["KullaniciAd"].ToString().Trim(), oku["Parola"].ToString().Trim() };
                    baglanti.Close();
                    return veriler;
                }
                return null;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public bool FirmaKontrol(string FirmaAd)
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("FirmaKontrol");
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@FirmaAd", FirmaAd);
                SqlDataReader oku = komut.ExecuteReader();
                if (oku.Read())
                {
                    baglanti.Close();
                    return true;
                }
                return false;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }

    }
}
