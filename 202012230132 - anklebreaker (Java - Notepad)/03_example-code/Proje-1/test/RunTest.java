import java.io.File;
import java.util.ArrayList;
import org.junit.Test;
import static org.junit.Assert.*;


public class RunTest {

    YazimDenetimi controller_Yazim = new YazimDenetimi();
    DosyaIslemleri controller_Dosya = new DosyaIslemleri();

    @Test
    public void AyniMi() {

        String doguSozcuk = "default";
        String testSozcuk = "deafult";
        ArrayList<String> kelimeler = controller_Dosya.dosyaOkuListe(new File("words.txt"));
        kelimeler.add(doguSozcuk);
        assertEquals(doguSozcuk, controller_Yazim.sozlukAra(kelimeler, testSozcuk));
    }
}
