
public class DLL {

    public Node head;

    public class Node {

        Vehicle data;
        Node prev;
        Node next;

        Node(Vehicle d) {
            data = d;
        }
    }

    public void push(Vehicle new_data) {
        Node new_Node = new Node(new_data);
        new_Node.next = head;
        new_Node.prev = null;

        if (head != null) {
            head.prev = new_Node;
        }

        head = new_Node;
    }

    public void InsertAfter(Node prev_Node, Vehicle new_data) {

        if (prev_Node == null) {
            System.out.println("Bos!!!");
            return;
        }

        Node new_node = new Node(new_data);
        new_node.next = prev_Node.next;
        new_node.prev = prev_Node;

        if (new_node.next != null) {
            new_node.next.prev = new_node;
        }
    }

    public void apped(Vehicle new_data) {
        Node new_node = new Node(new_data);
        Node last = head;
        new_node.next = null;

        if (head == null) {
            new_node.prev = null;
            head = new_node;
            return;
        }

        while (last.next != null) {
            last = last.next;
        }

        last.next = new_node;
        new_node.prev = last;
    }

    public Node findNode(String plaka) {
        Node last = head;

        while (last.next != null) {
            if (last.data.getPlaka().equals(plaka)) {
                System.out.println("\nBulunan > " + plaka + "\n" + last.data + "\n");
                return last;
            }
            last = last.next;
        }
        return null;
    }

    public void deleteNode(Node head_ref, Node del) {
        if (head == null || del == null) {
            return;
        }
        System.out.println("\nSilinen > " + del.data.getPlaka() + "\n" + del.data + "\n");
        if (head == del) {
            head = del.next;
        }

        if (del.next != null) {
            del.next.prev = del.prev;
        }

        if (del.prev != null) {
            del.prev.next = del.next;
        }

        return;

    }

    public void printlist(Node node) {
        Node last = null;
        System.out.println("--------Listeleme > Normal--------\n");
        while (node != null) {

            Vehicle vehicle = node.data;
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
            last = node;
            node = node.next;

        }
        System.out.println("--------------------------------\n");

        System.out.println("--------Listeleme > Ters--------\n");
        while (last != null) {

            Vehicle vehicle = last.data;
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
            last = last.prev;
        }
        System.out.println("--------------------------------\n");
    }

}
