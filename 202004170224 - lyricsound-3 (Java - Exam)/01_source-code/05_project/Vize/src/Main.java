
public class Main {

    public static void main(String[] args) {
        Battery nimhBattery = new NiMHBattery(3000, false);
        Battery lionBattery = new LiONBattery(5000, true);
        Screen lcdScreen = new LCDScreen(400, "1920x1080");
        Screen amoledScreen = new AMOLEDScreen(540, "3200x1440");

        CellPhoneFactory cpf = new CellPhoneFactory();
        CellPhone cphone1 = cpf.produceCellPhone("Nokia", "x", nimhBattery, lcdScreen);

        System.out.println(cphone1.getInfo());

        CellPhone cphone2 = cpf.produceCellPhone("Samsung", "s7", nimhBattery, lcdScreen);
        CellPhone cphone3 = cpf.produceCellPhone("Apple", "5s", nimhBattery, lcdScreen);
        CellPhone cphone4 = cpf.produceCellPhone("Samsung", "s20Ultra", lionBattery, amoledScreen);
    }

}
