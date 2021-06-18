
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    static float maxKg = 0, backpackWeight = 0;
    static int clothingSize = 0, foodAndDrinkSize = 0, firstAidSize = 0, toolSize = 0;
    static Scanner scanner = new Scanner(System.in);
    static ArrayList<String[]> clothing = new ArrayList<String[]>();
    static ArrayList<String[]> foodAndDrink = new ArrayList<String[]>();
    static ArrayList<String[]> firstAid = new ArrayList<String[]>();
    static ArrayList<String[]> tool = new ArrayList<String[]>();
    static Stack<String[]> backPack = new Stack<String[]>();
    static double clothingTotalKg = 0, foodAndDrinkTotalKg = 0, firstAidTotalKg = 0, toolTotalKg = 0;

    public static void main(String[] args) {

        ItemsRead();

        System.out.println("Welcome to Survival Game!");
        while (!(clothing.size() == 0 && foodAndDrink.size() == 0 && firstAid.size() == 0 && tool.size() == 0)) {

            Menu();
            if (clothingSize == 0 && foodAndDrinkSize == 0 && firstAidSize == 0 && toolSize == 0) {
                Menu();
                break;
            }

            while ((maxKg - backpackWeight) >= 0.1) {
                String[] findItem = FindItem(maxKg - backpackWeight);
                if (findItem == null) {
                    break;
                }
                BackPackPush(findItem);
                switch (findItem[1]) {
                    case "0":
                        clothing.remove(findItem);
                        break;
                    case "1":
                        foodAndDrink.remove(findItem);
                        break;
                    case "2":
                        firstAid.remove(findItem);
                        break;
                    case "3":
                        tool.remove(findItem);
                        break;
                }

            }
        }
        Nextiew();
        System.out.println("No items left in boxes");
    }

    public static void BackPackPush(String[] value) {
        //System.out.println(value[0] + " > " + value[1] + " > " + value[2] + " > " + value[3]);
        backPack.push(value);
        backpackWeight += Float.parseFloat(value[2]);
    }

    public static String[] ReadFile(String path) {

        int i = 0;
        int lenght;

        try {
            lenght = Files.readAllLines(Paths.get(path)).size();

            String[] results = new String[lenght];

            for (String line : Files.readAllLines(Paths.get(path))) {
                results[i++] = line;
            }
            return results;

        } catch (IOException ex) {
            ex.printStackTrace();
            return null;
        }

    }

    public static void ItemsRead() {
        for (String line : ReadFile("items.txt")) {
            switch (line.split(",")[1]) {
                case "0":
                    clothing.add(line.split(","));
                    break;
                case "1":
                    foodAndDrink.add(line.split(","));
                    break;
                case "2":
                    firstAid.add(line.split(","));
                    break;
                case "3":
                    tool.add(line.split(","));
                    break;
            }
        }
    }

    public static void Menu() {
        clothingSize = clothing.size();
        foodAndDrinkSize = foodAndDrink.size();
        firstAidSize = firstAid.size();
        toolSize = tool.size();

        clothingTotalKg = 0;
        foodAndDrinkTotalKg = 0;
        firstAidTotalKg = 0;
        toolTotalKg = 0;
        Nextiew();

        backPack.clear();
        System.out.println("Select Difficulty:");
        System.out.println("[0] Pilgrim\t[1] Voyager\t[2]Stalker\t[3]Interloper\t[9]Exit");
        int chose = scanner.nextInt();

        switch (chose) {
            case 0:
                maxKg = 9;
                break;
            case 1:
                maxKg = 7;
                break;
            case 2:
                maxKg = 5;
                break;
            case 3:
                maxKg = 3;
                break;
            case 9:
                System.exit(0);
                break;
        }
    }

    public static String[] FindItem(float max) {
        float ivalue = 0;
        String[] cvalue = null;

        for (String[] value : clothing) {
            int gain = Integer.parseInt(value[3]);
            float weight = Float.parseFloat(value[2]);
            if ((gain / weight) > ivalue && max >= weight) {
                cvalue = value;
                ivalue = gain / weight;
            }
        }
        for (String[] value : foodAndDrink) {
            int gain = Integer.parseInt(value[3]);
            float weight = Float.parseFloat(value[2]);
            if ((gain / weight) > ivalue && max >= weight) {
                cvalue = value;
                ivalue = gain / weight;
            }
        }
        for (String[] value : firstAid) {
            int gain = Integer.parseInt(value[3]);
            float weight = Float.parseFloat(value[2]);
            if ((gain / weight) > ivalue && max >= weight) {
                cvalue = value;
                ivalue = gain / weight;
            }
        }
        for (String[] value : tool) {
            int gain = Integer.parseInt(value[3]);
            float weight = Float.parseFloat(value[2]);
            if ((gain / weight) > ivalue && max >= weight) {
                cvalue = value;
                ivalue = gain / weight;
            }
        }

        return cvalue;
    }

    public static void Nextiew() {
        System.out.println("*********************************");
        for (String[] value : clothing) {
            clothingTotalKg += Double.parseDouble(value[2]);
        }
        for (String[] value : foodAndDrink) {
            foodAndDrinkTotalKg += Double.parseDouble(value[2]);
        }
        for (String[] value : firstAid) {
            firstAidTotalKg += Double.parseDouble(value[2]);
        }
        for (String[] value : tool) {
            toolTotalKg += Double.parseDouble(value[2]);
        }
        System.out.println("Clothing\t" + clothingSize + " items | " + new DecimalFormat("##.##").format(clothingTotalKg) + " kg");
        System.out.println("Food & Drink\t" + foodAndDrinkSize + " items |  " + new DecimalFormat("##.##").format(foodAndDrinkTotalKg) + " kg");
        System.out.println("First Aid\t" + firstAidSize + " items |  " + new DecimalFormat("##.##").format(firstAidTotalKg) + " kg");
        System.out.println("Tool\t\t" + toolSize + " items |  " + new DecimalFormat("##.##").format(toolTotalKg) + " kg");
        if (backPack.size() != 0) {
            int lifespan = 0;

            for (String[] strings : backPack) {
                lifespan += Integer.parseInt(strings[3]);
            }
            System.out.println("Backpack\t" + backPack.size() + " items |  " + backpackWeight + " kg");
            System.out.println("Lifespan\t" + lifespan + " days |");
            backpackWeight = 0;

        }
        System.out.println("*********************************");
    }
}
