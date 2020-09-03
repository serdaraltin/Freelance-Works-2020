
public class main {

    public static void main(String[] args) {
        Vehicle[] vehicles = ReadFile.OkuVeriler("veriler.txt");

        System.out.println("--------Dizideki veriler----------");
        for (Vehicle vehicle : vehicles) {
            if (vehicle != null) {
                System.out.println(vehicle);
                if (vehicle instanceof Car) {
                    System.out.print("Sinif\t: ");
                    if (((Car) vehicle).getKapi() == 2) {
                        System.out.println("Spor araba");
                    }
                    if (((Car) vehicle).getKapi() == 5) {
                        System.out.println("SWagon araba");
                    }
                    if (((Car) vehicle).getKapi() == 4) {
                        System.out.println("Standart araba");
                    }
                }
                System.out.println();
            }
        }
        System.out.println("----------------------------------\n");

        DLL dll = new DLL();
        for (Vehicle vehicle : vehicles) {
            if (vehicle != null) {
                dll.apped(vehicle);
            }
        }

        System.out.println("----Cift Bagli Listedeki Veriler--");
        dll.printlist(dll.head);

        ReadFile.OkuIslemerler("islemler.txt", dll);

        System.out.println("----Cift Bagli Listedeki Veriler Yeni--");
        dll.printlist(dll.head);
    }
}
