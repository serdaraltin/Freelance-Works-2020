
public class Test {
  /*******************************************************
   * Test1
   *******************************************************/
  public static int Test1(){
    AVL AVL = new AVL();
    AVLNode node;
    int depth;

    // Insert keys
    AVL.Insert(10);
    AVL.Insert(5);
    AVL.Insert(15);
    AVL.Insert(15);
    AVL.Insert(5);
    AVL.Insert(5);

    // Print the AVL on the screen
    depth = AVL.Depth();
    System.out.print("Depth of the tree is: " + depth + "\n");
    AVL.Print();

    node = AVL.Root();
    if (node.key != 10 || node.count != 1) return 0;
 
    node = AVL.Root().left;
    if (node.key != 5 || node.count != 3) return 0;

    node = AVL.Root().right;
    if (node.key != 15 || node.count != 2) return 0;

    return 20;
  } //end-Test1

  /*******************************************************
   * Test2
   *******************************************************/
  public static int Test2(){
    AVL avl = new AVL();
    AVLNode node;
    int depth, noOfNodes;

    // Insert keys
    avl.Insert(5);
    avl.Insert(5);
    avl.Insert(10);
    avl.Insert(10);
    avl.Insert(1);
    avl.Insert(3);
    avl.Insert(2);
    avl.Insert(4);
    avl.Insert(20);
    avl.Insert(15);
    avl.Insert(30);
    avl.Insert(40);

    // Print the AVL on the screen
    depth = avl.Depth();
    noOfNodes = avl.NoOfNodes();
    if (depth != 4) return 0;
    if (noOfNodes != 10) return 0;

    System.out.print("Tree Depth: " + depth + ", NoOfNodes: " + noOfNodes + "\n"); 
    avl.Print();

    node = avl.Min();
    if (node.key != 1 || node.left != null) return 0;

    node = avl.Max();
    if (node.key != 40 || node.right != null) return 0;

    // Check the validity of the tree
    node = avl.Root();
    if (node.key != 5 || node.count != 2) return 0;

    node = avl.Root().left;
    if (node.key != 3 || node.count != 1) return 0;

    node = avl.Root().left.left;
    if (node.key != 1 || node.count != 1) return 0;

    node = avl.Root().left.right.left;
    if (node.key != 4 || node.count != 1) return 0;

    node = avl.Root().left.left.right;
    if (node.key != 2  || node.count != 1) return 0;

    node = avl.Root().right;
    if (node.key != 20  || node.count != 1) return 0;

    node = avl.Root().right.right;
    if (node.key != 30 || node.count != 1) return 0;

    node = avl.Root().right.right.right;
    if (node.key != 40  || node.count != 1) return 0;

    node = avl.Root().right.left;
    if (node.key != 10 || node.count != 2) return 0;

    node = avl.Root().right.left.right;
    if (node.key != 15  || node.count != 1) return 0;

    // Test AVLFind
    node = avl.Find(17);
    if (node != null) return 0;

    node = avl.Find(15);
    if (node.key != 15 || node.count != 1) return 0;

    return 20;
  } //end-Test2

  /*******************************************************
   * Test3
   *******************************************************/
  public static int Test3(){
    AVL avl = new AVL();
    AVLNode node;

    // Insert keys
    avl.Insert(5);
    avl.Insert(5);
    avl.Insert(10);
    avl.Insert(10);
    avl.Insert(1);
    avl.Insert(3);
    avl.Insert(2);
    avl.Insert(4);
    avl.Insert(20);
    avl.Insert(15);
    avl.Insert(12);
    avl.Insert(11);
    avl.Insert(13);
    avl.Insert(17);
    avl.Insert(16);
    avl.Insert(18);
    avl.Insert(30);

    // Test delete
    if (avl.Delete(35) == 0) return 0;

    // Delete leaf node
    if (avl.Delete(30)!=0) return 0;
    node = avl.Find(20);
    if (node.right!=null && node.left.key!=18) return 0;

    // Delete internal node with only a right subtree
    avl.Delete(1);
    node = avl.Find(3);
    if (node.left.key != 2) return 0;
  
    // Delete internal node with only a left subtree
    avl.Delete(5);
    node = avl.Find(3);
    if (node.right.key != 4) return 0;

    // Delete an internal node with 2 children
    avl.Delete(15);
    node = avl.Find(13);
    if (node.right.key != 12 && node.right.key != 17) return 0;

    // Delete an internal node with 2 children (root)
    avl.Delete(12);
    node = avl.Root();
    if (node.key != 11) return 0;
    if (avl.NoOfNodes()!=11) return 0;
  
    avl.Print();
  
    return 30;
  } //end-Test3

  /*******************************************************
   * Test4
   *******************************************************/
  public static int Test4(){
    AVL avl = new AVL();
    AVLNode node;
    int min, max;

    int N = 10000;
    int numbers[] = new int[N];
    int i;
	
	for (i=0; i<N; i++) numbers[i] = 0;			

	min = N; max = -1;
    for (i=0; i<100000; i++){
      int key = (int)(Math.random()*(N-1));
      numbers[key]++;

      if (key < min) min = key;
      if (key > max) max = key;

      // Insert into AVL
      avl.Insert(key);
    } //end-for

    node = avl.Min();
    if (node == null || node.key != min || node.count != numbers[min]) return 0;

    node = avl.Max();
    if (node == null || node.key != max || node.count != numbers[max]) return 0;

    // Search all numbers and check if they are corrently inserted
    for (i=0; i<N; i++){
      node = avl.Find(i);

      if (numbers[i] == 0){
        if (node != null) return 0;
      } else {
        if (node.key != i || node.count != numbers[i]) return 0;
        if (node.left != null && node.left.key >= node.key) return 0;
        if (node.right != null && node.right.key <= node.key) return 0;
      } //end-else
    } //end-for

    // Now delete all keys from the tree until the tree is empty
    for (i=0; i<N; i++){
      int ret = avl.Delete(i);

      if (numbers[i] == 0){ 
        if (ret != -1) return 0; 
      } else if (ret != 0) return 0;
    } //end-for
  
    if (avl.Root() != null) return 0;
    if (avl.NoOfNodes() != 0) return 0;

    return 30;
  } //end-Test4

  /*******************************************************
   * Main Function
   *******************************************************/
  public static void main(String args[]){
    int grade = 0;

    System.out.print("---------------------------------- TEST1 ---------------------------\n");
    grade += Test1();
    System.out.print("Your grade after Test1: " + grade + "\n");

    System.out.print("---------------------------------- TEST2 ---------------------------\n");
    grade += Test2();
    System.out.print("Your grade after Test2: " + grade + "\n");

    System.out.print("---------------------------------- TEST3 ---------------------------\n");
    grade += Test3();
    System.out.print("Your grade after Test3: " + grade + "\n");

    System.out.print("---------------------------------- TEST4 ---------------------------\n");
    grade += Test4();
    System.out.print("Your grade after Test4: " + grade + "\n");

    System.out.print("--------------------------------------------------------------------\n");
    System.out.print("!=!=!=!=!=!=> Your project grade is: " + grade + "\n");
  } /* end-main */
};

