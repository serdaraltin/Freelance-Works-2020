package Test;

import Controller.ConBolum;
import Controller.ConOgretimUyesi;
import Core.ObjectHelper;
import Types.TypeBolum;
import Types.TypeOgretimUyesi;


public class Run extends ObjectHelper{
    

    public static void main(String[] args) {
        
        CreateDataBase createDataBase = new CreateDataBase();
        
        if(createDataBase.Create())
            System.out.println("Veritabani olusturuldu");
      
        ConBolum bolumler = new ConBolum();
        
        TypeBolum b;
        b = new TypeBolum();
        b.setAd("denemebolum");
        b.setDersProgrami_id(1);
        b.setSure(3);
        
        ConBolum ekle=new ConBolum();
        ekle.Ekle(b);
        ConOgretimUyesi ogretimUyesi = new ConOgretimUyesi();
        
        for(TypeOgretimUyesi uye: ogretimUyesi.Listele()){
            System.out.println(uye.toString());
        }
    }
}
