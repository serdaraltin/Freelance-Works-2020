package lyricsound;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.TreeSet;

public class Main {

    public static ArrayList<Contact> sortByLastName(ArrayList<Contact> contacts) {
        String contactName1, contactName2;

        for (int i = 0; i < contacts.size(); i++) {
            contactName1 = contacts.get(i).getLastName();
            for (int n = i + 1; n < contacts.size() - 1; n++) {
                contactName2 = contacts.get(n).getLastName();

                if (contactName1.compareToIgnoreCase(contactName2) > 0) {
                    Contact temp = contacts.get(i);
                    contacts.set(i, contacts.get(n));
                    contacts.set(n, temp);
                }
            }
        }
        return contacts;
    }

    public static void main(String[] args) {
        String inputFile = args[0];

        ArrayList<Contact> contacts = FileOperation.ReadFileArrayList(inputFile);
        FileOperation.WriteFile("contactsArrayList.txt", contacts);

        ArrayList<Contact> contactsOrderByLastName = LastNameComparator.LastNameComparatorArrayList(contacts);
        FileOperation.WriteFile("contactsArrayListOrderByLastName.txt", contactsOrderByLastName);

        HashMap<String, Contact> hashMap = new HashMap<String, Contact>();
        for (Contact contact : contacts) {
            hashMap.put(contact.getPhoneNumber(), contact);
        }
        FileOperation.WriteFile("contactsHashMap.txt", hashMap);

        HashSet<Contact> hashSet = new HashSet<Contact>();

        for (Contact contact : contacts) {
            hashSet.add(contact);
        }
        FileOperation.WriteFile("contactsHashSet.txt", hashSet);

        TreeSet<Contact> treeSet = new TreeSet<Contact>();
        for (Contact contact : FileOperation.ReadFileArrayList(inputFile)) {
            treeSet.add(contact);
        }

        FileOperation.WriteFile("contactsTreeSet.txt", treeSet);

        TreeSet<Contact> treeSetOrderByLastName = new TreeSet<Contact>();
        for (Contact contact : contacts) {
            treeSetOrderByLastName.add(contact);
        }
        FileOperation.WriteFile("contactsTreeSetOrderByLastname.txt", treeSet);

    }

}
