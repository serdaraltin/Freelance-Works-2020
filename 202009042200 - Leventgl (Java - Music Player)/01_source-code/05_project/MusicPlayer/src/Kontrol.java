import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

public class Kontrol {

    Long konum;
    Clip muzik;
    String durum = "";
    AudioInputStream oynatma;
    static String dosyaYolu;

    public Kontrol() {
    }

    public void ayarla(String file) {
        if (durum.equals("oynat") || durum.equals("duraklat") || durum.equals("resume")) {
            konum = 0L;
            muzik.stop();
            muzik.close();
            durum = "durdur";
        }
        try {
            dosyaYolu = file;
            oynatma = AudioSystem.getAudioInputStream(new File(dosyaYolu).getAbsoluteFile());
            try {
                muzik = AudioSystem.getClip();
            } catch (LineUnavailableException ex) {
                Logger.getLogger(Kontrol.class.getName()).log(Level.SEVERE, null, ex);
            }
            try {
                muzik.open(oynatma);
            } catch (LineUnavailableException ex) {
                Logger.getLogger(Kontrol.class.getName()).log(Level.SEVERE, null, ex);
            }
            muzik.loop(Clip.LOOP_CONTINUOUSLY);
        } catch (UnsupportedAudioFileException | IOException ex) {
            Logger.getLogger(Kontrol.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    public void oynat() {
        muzik.start();
        durum = "oynat";
    }

    public void duraklat() {
        if (durum.equals("duraklat")) {
            return;
        }
        if (durum.equals("oynat") || durum.equals("resume")) {
            this.konum = 0L;
            this.konum = this.muzik.getMicrosecondPosition();
            muzik.stop();
            durum = "duraklat";
        }
    }

    public void devam() {
        if (durum.equals("oynat")) {
            return;
        }
        muzik.close();
        yenile();
        this.muzik.setMicrosecondPosition(this.konum);
        durum = "resume";
        muzik.start();
    }

    public void yenidenBaslat() {
        muzik.stop();
        muzik.close();
        yenile();
        konum = 0L;
        muzik.setMicrosecondPosition(0);
        durum = "oynat";
        oynat();
    }

    public void durdur() {
        if (durum.equals("oynat") || durum.equals("duraklat") || durum.equals("resume")) {
            konum = 0L;
            muzik.stop();
            muzik.close();
            durum = "durdur";
        }
    }

    public void yenile() {
        try {
            try {
                oynatma = AudioSystem.getAudioInputStream(new File(dosyaYolu).getAbsoluteFile());
            } catch (UnsupportedAudioFileException ex) {
                Logger.getLogger(Kontrol.class.getName()).log(Level.SEVERE, null, ex);
            }
            muzik.open(oynatma);
            muzik.loop(Clip.LOOP_CONTINUOUSLY);
        } catch (LineUnavailableException ex) {
            Logger.getLogger(Kontrol.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Kontrol.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
