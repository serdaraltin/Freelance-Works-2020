
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Main {

    static SimpleDateFormat dateFormat = new SimpleDateFormat("dd.MM.yyyy");

    public static void main(String[] args) throws ParseException {

        Scanner s = new Scanner(System.in);
        ReadFile ReadF = new ReadFile();
        VFind valuF = new VFind();

       
        String file_priceList =args[0];
        
        String file_shoppingList = args[1];

        String[] priceList = ReadF.readFile(file_priceList);
        String[] shoppingList = ReadF.readFile(file_shoppingList);

        System.out.println("\nPrice List >>");

        System.out.println("\n\nShopping List >>");
        for (String line : shoppingList) {
            String[] values = line.split("	");
            System.out.println("---" + values[0] + "---");
            String level = values[1];
            Date dateShop = dateFormat.parse(values[2]);

            float total = 0;
            int i = 0;

            for (String subv : values) {
                if (i > 2) {
                    if (i % 2 != 0) {
                        System.out.print(subv + "\t");
                    } else {
                        String price = values[i - 1];
                        String[] foundPrice = valuF.valueFind(priceList, price + "	" + level, dateShop);
                        float p = Float.parseFloat(foundPrice[4]);
                        float tp = p * Float.parseFloat(subv);
                        System.out.print(foundPrice[4] + "\t" + subv + "\t" + tp + "\n");
                        total += tp;
                    }
                }
                i++;
            }
            System.out.println("Total\t" + total);

        }

    }
}
