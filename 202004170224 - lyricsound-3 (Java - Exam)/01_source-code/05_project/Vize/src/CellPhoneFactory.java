
public class CellPhoneFactory{


    CellPhone produceCellPhone(String marka, String model, Battery battery, Screen screen) {
        CellPhone cellPhone = new CellPhone();
        cellPhone.setMarka(marka);
        cellPhone.setModel(model);
        cellPhone.setBattery(battery);
        cellPhone.setScreen(screen);    
        
        if(cellPhone.getBattery() != battery || cellPhone.getScreen() != screen)
           return null;
        System.out.println("Factory has produced one "+marka+"-"+model);
        return cellPhone;
    }
}
