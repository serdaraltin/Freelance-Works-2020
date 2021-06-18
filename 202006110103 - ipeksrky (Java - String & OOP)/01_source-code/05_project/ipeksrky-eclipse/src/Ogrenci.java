//Ogrenci sınıfı
public class Ogrenci {

	//degiskenler
    private String ad;
    private String soyad;
    private String tcNo;
    private int dogumYili;
    private Adres adres;

    //ad degiskeni get methodu
    public String getAd() {
        return ad;
    }
    //ad degiskeni set methodu
    public void setAd(String ad) {
        if (Adkontrol(ad)) {
            char ch[] = ad.toCharArray();
            for (int i = 0; i < ad.length(); i++) {
                if (i == 0 && ch[i] != ' ' || ch[i] != ' ' && ch[i - 1] == ' ') {
                    if (ch[i] >= 'a' && ch[i] <= 'z') {
                        ch[i] = (char) (ch[i] - 'a' + 'A');
                    }
                } else if (ch[i] >= 'A' && ch[i] <= 'Z') {
                    ch[i] = (char) (ch[i] + 'a' - 'A');
                }
            }

            this.ad = new String(ch);
            return;
        }
        System.out.println("Hatali giris yapildi");
    }

    //soyad degiskeni get methodu
    public String getSoyad() {
        return soyad;
    }
	//soyad degiskeni set methodu
    public void setSoyad(String soyad) {
        if (SoyadKontrol(soyad)) {
            
            char ch[] = soyad.toCharArray();
            for (int i = 0; i < soyad.length(); i++) {
                if (i == 0 && ch[i] != ' ' || ch[i] != ' ' && ch[i - 1] == ' ') {
                    if (ch[i] >= 'a' && ch[i] <= 'z') {
                        ch[i] = (char) (ch[i] - 'a' + 'A');
                    }
                } else if (ch[i] >= 'A' && ch[i] <= 'Z') {
                    ch[i] = (char) (ch[i] + 'a' - 'A');
                }
            }

            this.soyad = new String(ch);
            return;
        }
        System.out.println("Hatali giris yapildi");
    }
    //tcno degiskeni get methodu
    public String getTcno() {
        return tcNo;
    }
    //tcno degiskeni set methodu
    public void setTcno(String tcNo) {
        if (tcNokontrol(tcNo)) {
            this.tcNo = tcNo;
            return;
        }
        System.out.println("Hatali giris yapildi");
    }
    //dogum yili degiskeni get methodu
    public int getDogumYili() {
        return dogumYili;
    }
    //dogum yili degiskeni set methodu
    public void setDogumYili(int dogumYili) {
        this.dogumYili = dogumYili;
    }
    //adres nesnesi get methodu
    public Adres getAdres() {
        return adres;
    }
    //adres nesnesi set methodu
    public void setAdres(Adres adres) {
        this.adres = adres;
    }

    //ad kontrol methodu, aldigi parametredeki degerin kontrolunu yapar
    public boolean Adkontrol(String ad) {
        if (ad.matches("[A-Za-z]+")) {
            return true;
        }
        return false;
    }
    //soyad kontrol methodu, aldigi parametredeki degerin kontrolunu yapar
    public boolean SoyadKontrol(String soyad) {
        if (soyad.matches("[A-Za-z]+")) {
            return true;
        }
        return false;
    }
    //tcno kontrol methodu, aldigi parametredeki degerin kontrolunu yapar
    public boolean tcNokontrol(String tcNo) {
        if (tcNo.length() != 11) {
            return false;
        }
        if (tcNo.matches("-?\\d+(\\.\\d+)?")) {
            return true;
        }
        return false;
    }
    //override edilmis toString methodu
    @Override
    public String toString() {
        return "---------------------" + "\nAd\t: " + ad + "\nSoyad\t: " + soyad + "\nTc No\t: " + tcNo + "\nDogum\t: " + dogumYili + "\n\n  Adres Bilgileri\n" + adres + "\n---------------------";
    }
    //yapıcı method, ilgili parametreleri alarak atama yapmakta
    public Ogrenci(String ad, String soyad, String tcNo, int dogumYili, Adres adres) {
        setAd(ad);
        setSoyad(soyad);
        setTcno(tcNo);
        this.dogumYili = dogumYili;
        this.adres = adres;
    }

    public Ogrenci() {
    }

    
}
