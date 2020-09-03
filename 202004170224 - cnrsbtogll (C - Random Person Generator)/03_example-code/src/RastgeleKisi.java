/**
 * @author G161210113 - Hümeyra AY g161210113@sakarya.edu.tr B121210125 - Damla KARAGÖZ b121210125@sakarya.edu.tr
 * @since 1.4.2018
 * <p> Rastgele kişilerin oluşturulduğu ve kontrol edildiği sınıf </p>
 */

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class RastgeleKisi {
    List<String> adlar;

    public RastgeleKisi() throws FileNotFoundException, IOException {
        File dosya = new File("src\\random_isimler.txt");
        FileReader okuyucu = new FileReader(dosya);
        BufferedReader br = new BufferedReader(okuyucu);
        String satir;
        adlar = new ArrayList();
        while ((satir = br.readLine()) != null) {
            adlar.add(satir);
            //System.out.println(adlar.get(0));
        }
        okuyucu.close();
        br.close();
    }

    public void KisileriOlustur(int adet) throws IOException {
        Kisi[] kisiler = new Kisi[adet];
        RandomC random = new RandomC();
        int randomAd;
        for (int i = 0; i < adet; i++) {

            kisiler[i] = new Kisi();
            randomAd = random.randomint(adlar.size() + 1);
            kisiler[i] = Kisi.RastgeleKisiUret(adlar.get(randomAd));
        }
        File fout = new File("src\\Kisiler.txt");
        FileOutputStream fos = new FileOutputStream(fout);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));

        for (int i = 0; i < kisiler.length; i++) {
            bw.write(kisiler[i].Getir());
            bw.newLine();
        }

        bw.close();
    }

    public void DosyayiKontrolEt() throws FileNotFoundException, IOException {
        File dosya = new File("src\\Kisiler.txt");
        FileReader okuyucu = new FileReader(dosya);
        BufferedReader br = new BufferedReader(okuyucu);
        String satir;
        ArrayList<String> kisiler = new ArrayList();
        while ((satir = br.readLine()) != null) {
            kisiler.add(satir);
        }
        okuyucu.close();
        br.close();

        Kisi[] kisilerArray = new Kisi[kisiler.size()];
        for (int i = 0; i < kisilerArray.length; i++)
            kisilerArray[i] = Kisi.StringToKisi(kisiler.get(i));

        System.out.println("TC kimlik Kontrolü");
        int tc = 0;
        for (int i = 0; i < kisilerArray.length; i++)
            if (kisilerArray[i].kimlik.GecerliMi())
                tc++;
        System.out.println(tc + " Geçerli");
        System.out.println((kisilerArray.length - tc) + " Geçersiz");

        System.out.println("IMEI Kontrolü");
        int imei = 0;
        for (int i = 0; i < kisilerArray.length; i++)
            if (kisilerArray[i].tel.imei.GecerliMi())
                imei++;

        System.out.println(imei + " Geçerli");
        System.out.println((kisilerArray.length - imei) + " Geçersiz");
    }
}
