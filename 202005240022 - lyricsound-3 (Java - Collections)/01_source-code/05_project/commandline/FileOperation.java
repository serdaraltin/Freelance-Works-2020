import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class FileOperation {

    public static ArrayList<Contact> ReadFileArrayList(String file) {
        try {

            File dosyaKisiler = new File(file);
            if (!dosyaKisiler.exists()) {
                return null;
            }
            Scanner scanner = new Scanner(dosyaKisiler);
            ArrayList<Contact> data = new ArrayList<Contact>();
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split(" ");
                Contact contact = new Contact(line[0], line[1], line[2], line[3]);
                data.add(contact);
            }
            return data;
        } catch (FileNotFoundException ex) {
            System.err.println(ex);
            return null;
        }
    }

    public static boolean WriteFile(String file, ArrayList<Contact> Contacts) {
        FileWriter fileWriter = null;
        try {
            File writeFile = new File(file);
            if (writeFile.exists()) {
                PrintWriter pwriter = new PrintWriter(file);
                pwriter.print("");
                pwriter.close();
            } else {
                writeFile.createNewFile();
            }
            fileWriter = new FileWriter(writeFile, true);
            try (BufferedWriter bWriter = new BufferedWriter(fileWriter)) {
                for (Contact contact : Contacts) {
                    bWriter.write(contact.toString());
                    bWriter.newLine();
                }
                return true;
            }
        } catch (IOException ex) {
            System.err.println(ex);
            return false;
        }
    }
    
        public static boolean WriteFile(String file, HashMap<String,Contact> Contacts) {
        FileWriter fileWriter = null;
        try {
            File writeFile = new File(file);
            if (writeFile.exists()) {
                PrintWriter pwriter = new PrintWriter(file);
                pwriter.print("");
                pwriter.close();
            } else {
                writeFile.createNewFile();
            }
            fileWriter = new FileWriter(writeFile, true);
            try (BufferedWriter bWriter = new BufferedWriter(fileWriter)) {
                for (Map.Entry<String,Contact> conEntry : Contacts.entrySet()) {
                    bWriter.write(conEntry.getValue().toString());
                    bWriter.newLine();
                }
                return true;
            }
        } catch (IOException ex) {
            System.err.println(ex);
            return false;
        }
    }
        
    public static boolean WriteFile(String file, Set<Contact> Contacts) {
        FileWriter fileWriter = null;
        try {
            File writeFile = new File(file);
            if (writeFile.exists()) {
                PrintWriter pwriter = new PrintWriter(file);
                pwriter.print("");
                pwriter.close();
            } else {
                writeFile.createNewFile();
            }
            fileWriter = new FileWriter(writeFile, true);
            try (BufferedWriter bWriter = new BufferedWriter(fileWriter)) {
                for (Contact contact : Contacts) {
                    bWriter.write(contact.toString());
                    bWriter.newLine();
                }
                return true;
            }
        } catch (IOException ex) {
            System.err.println(ex);
            return false;
        }
    }

}
