
import java.util.Scanner;

public class AVL {

    private AVLNode root;

    private int noOfNodes;

    public AVL() {
        root = null;
        noOfNodes = 0;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    AVLNode rightRotate(AVLNode y) {
        AVLNode x = y.left;
        AVLNode T2 = x.right;

        x.right = y;
        y.left = T2;

        y.count = max(Depth(y.left), Depth(y.right)) + 1;
        x.count = max(Depth(x.left), Depth(x.right)) + 1;
        return x;
    }

    AVLNode leftRotate(AVLNode x) {
        AVLNode y = x.right;
        AVLNode T2 = y.left;

        y.left = x;
        x.right = T2;

        x.count = max(Depth(x.left), Depth(x.right)) + 1;
        y.count = max(Depth(y.left), Depth(y.right)) + 1;
        return y;
    }

    int getBalance(AVLNode N) {
        if (N == null) {
            return 0;
        }
        return Depth(N.left) - Depth(N.right);
    }

    public AVLNode Root() {
        return root;
    }

    public int NoOfNodes() {
        return noOfNodes;
    }

    AVLNode insert(AVLNode node, int key) {
        if (node == null) {
            return (new AVLNode(key));
        }

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        } else {
            return node;
        }

        node.count = 1 + max(Depth(node.left),
                Depth(node.right));

        int balance = getBalance(node);

        if (balance > 1 && key < node.left.key) {
            return rightRotate(node);
        }

        if (balance < -1 && key > node.right.key) {
            return leftRotate(node);
        }

        if (balance > 1 && key > node.left.key) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node.right.key) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;
    }

    public AVLNode Insert(int key) {
        this.root = insert(this.root, key);
        return root;
    }

    AVLNode minValueNode(AVLNode node) {
        AVLNode current = node;

        while (current.left != null) {
            current = current.left;
        }
        return current;
    }

    AVLNode deleteNode(AVLNode root, int key) {

        if (root == null) {
            return root;
        }

        if (key < root.key) {
            root.left = deleteNode(root.left, key);
        } else if (key > root.key) {
            root.right = deleteNode(root.right, key);
        } else {

            if ((root.left == null) || (root.right == null)) {
                AVLNode temp = null;
                if (temp == root.left) {
                    temp = root.right;
                } else {
                    temp = root.left;
                }

                if (temp == null) {
                    temp = root;
                    root = null;
                } else {
                    root = temp;
                }
            } else {

                AVLNode temp = minValueNode(root.right);

                root.key = temp.key;

                root.right = deleteNode(root.right, temp.key);
            }
        }

        if (root == null) {
            return root;
        }

        root.count = max(Depth(root.left), Depth(root.right)) + 1;

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root.left) >= 0) {
            return rightRotate(root);
        }

        if (balance > 1 && getBalance(root.left) < 0) {
            root.left = leftRotate(root.left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root.right) <= 0) {
            return leftRotate(root);
        }

        if (balance < -1 && getBalance(root.right) > 0) {
            root.right = rightRotate(root.right);
            return leftRotate(root);
        }

        return root;
    }

    public int Delete(int key) {
        this.root = deleteNode(this.root, key);

        if (Find(key) != null) {
            return -1;
        }

        return 0;
    }

    AVLNode search(AVLNode node, int key) {
        if (node.key == key) {
            return node;
        }
        if (node.left != null) {
            return search(node.left, key);
        }
        if (node.right != null) {
            return search(node.right, key);
        }
        return null;
    }

    public AVLNode Find(int key) {
        AVLNode current = Root();

        return search(current, key);
    }

    public AVLNode Min() {
        AVLNode current = Root();
        while (current.left != null) {
            current = current.left;
        }
        return current;
    }

    public AVLNode Max() {
        AVLNode current = Root();
        while (current.right != null) {
            current = current.right;
        }
        return current;
    }

    int maxDepth(AVLNode node) {
        if (node == null) {
            return 0;
        } else {
            int lDepth = maxDepth(node.left);
            int rDepth = maxDepth(node.right);

            if (lDepth > rDepth) {
                return (lDepth + 1);
            } else {
                return (rDepth + 1);
            }
        }
    }

    public int Depth(AVLNode node) {
        if (node == null) {
            return 0;
        }
        return node.count;
    }

    void inOrder(AVLNode node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.key + " ");
            inOrder(node.right);
        }
    }

    public void Print() {
        inOrder(root);
        System.out.println();
    }

    public static void main(String[] args) {
        AVL tree = new AVL();

        while (true) {
            System.out.println("1) Insert");
            System.out.println("2) Delete");
            System.out.println("3) Find");
            System.out.println("4) Min");
            System.out.println("5) Max");
            System.out.println("6) Depth");
            System.out.println("7) Print");
            System.out.println("0) Exit");
            System.out.print("\nChoice : ");
            Scanner scanner = new Scanner(System.in);
            int choice = scanner.nextInt();

            int value;
            switch (choice) {
                case 0:
                    System.out.println("Exit...");
                    System.exit(0);
                    break;
                case 1:
                    System.out.print("\nValue : ");
                    value = scanner.nextInt();
                    tree.Insert(value);
                    break;
                case 2:
                    System.out.print("\nValue : ");
                    value = scanner.nextInt();
                    tree.Delete(value);
                    break;
                case 3:
                    System.out.print("\nValue : ");
                    value = scanner.nextInt();
                    if (tree.Find(value) != null) {
                        System.out.println("Found.");
                    } else {
                        System.out.println("Not Found.");
                    }
                    break;
                case 4:
                    System.out.println("Min : " + tree.Min().key);
                    break;
                case 5:
                    System.out.println("Max : " + tree.Max().key);
                    break;
                case 6:
                    System.out.println("Depth : " + ((tree.Depth(tree.root)) - 1));
                    break;
                case 7:
                    System.out.println("Print InOrder >>\t");
                    tree.Print();
                    break;
            }

        }
    }

};
