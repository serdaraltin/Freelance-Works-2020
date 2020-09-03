import java.io.*;
import java.util.ArrayList;
import java.util.List;
public class RastgeleKisi {
    List<String> liste;
    public RastgeleKisi() throws FileNotFoundException, IOException {
        File file = new File("src/random_isimler.txt");
        FileReader r = new FileReader(file);
        BufferedReader buff = new BufferedReader(r);
        String satir;
        liste = new ArrayList();
        while ((satir = buff.readLine()) != null) {
            liste.add(satir);
        }
        r.close();
        buff.close();
    }
    public void KisileriOlustur(int adet) throws IOException {
        Kisi[] DKisi = new Kisi[adet];
        Rastgele rast = new Rastgele();
        int ad;
        for (int i = 0; i < adet; i++) {
            DKisi[i] = new Kisi();
            ad = rast.tamsayi(liste.size() + 1);
            DKisi[i] = Kisi.RastgeleKisiUret(liste.get(ad));
        }
        File _File = new File("src/Kisiler.txt");
        FileOutputStream _FileOut = new FileOutputStream(_File);
        BufferedWriter _buffw = new BufferedWriter(new OutputStreamWriter(_FileOut));
        for (int i = 0; i < DKisi.length; i++) {
            _buffw.write(DKisi[i].toString());
            _buffw.newLine();
        }
        _buffw.close();
    }
    public void DosyayiKontrolEt() throws FileNotFoundException, IOException {
        File file = new File("src/Kisiler.txt");
        FileReader r = new FileReader(file);
        BufferedReader buff = new BufferedReader(r);
        String satir;
        ArrayList<String> DKisi = new ArrayList();
        while ((satir = buff.readLine()) != null) {
            DKisi.add(satir);
        }
        r.close();
        buff.close();
        Kisi[] Rkisi = new Kisi[DKisi.size()];
        for (int i = 0; i < Rkisi.length; i++) {
            Rkisi[i] = Kisi.StringToKisi(DKisi.get(i));
        }
        int tc = 0;
        for (int i = 0; i < Rkisi.length; i++) {
            if (Rkisi[i]._KimlikNo.GecerliMi()) 
                tc++;
        }
        System.out.println("\nTC kimlik Kontrolü");
        System.out.println(tc + " Geçerli");
        System.out.println((Rkisi.length - tc) + " Geçersiz\n");
        int imei = 0;
        for (int i = 0; i < Rkisi.length; i++) {
            if (Rkisi[i]._T._IMEINo.ImeiKontrol()) 
                imei++;
        }
        System.out.println("IMEI Kontrolü");
        System.out.println(imei + " Geçerli");
        System.out.println((Rkisi.length - imei) + " Geçersiz");
    }
}
