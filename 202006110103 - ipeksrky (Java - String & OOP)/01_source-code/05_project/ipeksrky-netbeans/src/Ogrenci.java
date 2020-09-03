
public class Ogrenci {

    private String ad;
    private String soyad;
    private String tcNo;
    private int dogumYili;
    private Adres adres;

    public String getAd() {
        return ad;
    }

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

    public String getSoyad() {
        return soyad;
    }

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

    public String getTcno() {
        return tcNo;
    }

    public void setTcno(String tcNo) {
        if (tcNokontrol(tcNo)) {
            this.tcNo = tcNo;
            return;
        }
        System.out.println("Hatali giris yapildi");
    }

    public int getDogumYili() {
        return dogumYili;
    }

    public void setDogumYili(int dogumYili) {
        this.dogumYili = dogumYili;
    }

    public Adres getAdres() {
        return adres;
    }

    public void setAdres(Adres adres) {
        this.adres = adres;
    }

    public boolean Adkontrol(String ad) {
        if (ad.matches("[A-Za-z]+")) {
            return true;
        }
        return false;
    }

    public boolean SoyadKontrol(String soyad) {
        if (soyad.matches("[A-Za-z]+")) {
            return true;
        }
        return false;
    }

    public boolean tcNokontrol(String tcNo) {
        if (tcNo.length() != 11) {
            return false;
        }
        if (tcNo.matches("-?\\d+(\\.\\d+)?")) {
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        return "---------------------" + "\nAd\t: " + ad + "\nSoyad\t: " + soyad + "\nTc No\t: " + tcNo + "\nDogum\t: " + dogumYili + "\n\n  Adres Bilgileri\n" + adres + "\n---------------------";
    }

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
