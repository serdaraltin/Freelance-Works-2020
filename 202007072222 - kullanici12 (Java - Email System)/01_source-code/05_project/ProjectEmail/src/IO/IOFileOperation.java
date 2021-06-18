package IO;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class IOFileOperation {

    public ArrayList<String[]> DosyaOku(String dosyaAdi) {
        try {
            File dosya = new File(dosyaAdi);

            if (!dosya.exists()) {
                return null;
            }
            Scanner scanner = new Scanner(dosya);
            ArrayList<String[]> veriler = new ArrayList<String[]>();
            while (scanner.hasNextLine()) {
                String satir = scanner.nextLine();
                veriler.add(satir.split(","));
            }
            return veriler;
        } catch (FileNotFoundException ex) {
            Logger.getLogger(IOFileOperation.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    public boolean DosyaYaz(String dosyaAdi, ArrayList<String[]> veri) {
        FileWriter dosyaYaz = null;
        try {
            File dosya = new File(dosyaAdi);

            if (dosya.exists()) {
                PrintWriter pwriter = new PrintWriter(dosya);
                pwriter.print("");
                pwriter.close();
            }
            if (!dosya.exists()) {
                dosya.createNewFile();
            }

            dosyaYaz = new FileWriter(dosya, true);

            try (BufferedWriter bufferWriter = new BufferedWriter(dosyaYaz)) {
                for (String[] strings : veri) {
                    for (String kolon : strings) {
                        bufferWriter.write(kolon + ",");
                    }
                    bufferWriter.newLine();
                }
                return true;
            }
        } catch (IOException ex) {
            System.err.println(ex);
            return false;
        }

    }

}
