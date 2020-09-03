
import java.io.File;
import java.io.FileNotFoundException;

import java.util.Scanner;

public class ReadFile {

    public static Vehicle[] OkuVeriler(String file) {
        try {
            File dosya = new File(file);
            if (!dosya.exists()) {
                return null;
            }
            Scanner scanner = new Scanner(dosya);
            Vehicle[] vehicles = new Vehicle[100];
            int i = 0;
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split(" ");
                if (line[0].equals("car")) {
                    vehicles[i] = new Car(line[1], line[2], line[3], Integer.parseInt(line[4]));
                }
                if (line[0].equals("truck")) {
                    vehicles[i] = new Truck(line[1], line[2], line[3], Integer.parseInt(line[4]));
                }
                i++;
            }
            return vehicles;
        } catch (FileNotFoundException ex) {
            System.err.println(ex);
            return null;
        }
    }

    public static void OkuIslemerler(String file, DLL dll) {
        try {
            File dosya = new File(file);
            if (!dosya.exists()) {
                return;
            }
            Scanner scanner = new Scanner(dosya);
            System.out.println("------------Islemler------------");
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split(" ");

                switch (line[0]) {
                    case "ekle":
                        if (line[0].equals("ekle")) {
                            if (line[1].equals("car")) {
                                Vehicle car = new Car(line[2], line[3], line[4], Integer.parseInt(line[5]));
                                dll.apped(car);
                            }
                            if (line[1].equals("truck")) {
                                dll.apped(new Truck(line[2], line[3], line[4], Integer.parseInt(line[5])));
                            }
                        }
                        break;
                    case "sil":
                        if (line[0].equals("sil")) {
                            dll.deleteNode(dll.head, dll.findNode(line[1]));
                        }
                        break;
                }

            }
            System.out.println("------------------------------\n");
        } catch (FileNotFoundException ex) {
            System.err.println(ex);
        }
    }
}
