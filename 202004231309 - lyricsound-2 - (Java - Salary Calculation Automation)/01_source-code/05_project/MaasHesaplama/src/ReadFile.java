import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ReadFile {

    public ArrayList<Personnel> ReadPersonel(String file) {
        try {
            File filePersonel = new File(file);
            Scanner scanner = new Scanner(filePersonel);
            ArrayList<Personnel> data = new ArrayList<Personnel>();
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split("	");
                Personnel personnel = new Personnel(line[0].split(" ")[0], line[0].split(" ")[1], line[1], line[2], Integer.parseInt(line[3]));
                data.add(personnel);
            }
            return data;
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ReadFile.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }

    public ArrayList<Monitor> ReadMonitor(String file) {
        try {
            File filePersonel = new File(file);
            Scanner scanner = new Scanner(filePersonel);
            ArrayList<Monitor> data = new ArrayList<Monitor>();
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split("	");
                Monitor monitor = new Monitor(line[0], Integer.parseInt(line[1]), Integer.parseInt(line[2]), Integer.parseInt(line[3]), Integer.parseInt(line[4]));
                data.add(monitor);
            }
            return data;
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ReadFile.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }

    public Monitor ReadMonitor(String RegisterNumber,String file) {
        try {
            File filePersonel = new File(file);
            Scanner scanner = new Scanner(filePersonel);
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split("	");
                Monitor monitor = new Monitor(line[0], Integer.parseInt(line[1]), Integer.parseInt(line[2]), Integer.parseInt(line[3]), Integer.parseInt(line[4]));
                if (monitor.getRegisterNumber().equals(RegisterNumber)) {
                    return monitor;
                }
            }
            return null;
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ReadFile.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
}
