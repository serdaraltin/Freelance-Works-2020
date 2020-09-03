package Controllers;

import Interfaces.InterfaceController;
import Types.TypeMusteriSepeti;
import java.util.ArrayList;

public class ControllerMusteriSepeti implements InterfaceController<TypeMusteriSepeti> {

    @Override
    public boolean Ekle(ArrayList<TypeMusteriSepeti> list, TypeMusteriSepeti type) {
        try {
            if (Sec(list, type) == -1) {
                list.add(type);
                return true;
            }
            System.out.println("Aynı kodda urun daha once eklenmistir!!!");
            return false;
        } catch (Exception ex) {
            System.err.println(ex);
            return false;
        }
    }

    @Override
    public boolean Guncelle(ArrayList<TypeMusteriSepeti> list, TypeMusteriSepeti type) {
        try {
            int index = Sec(list, type);
            if (index == -1) {
                //System.err.println("Güncellenecek sepet bulunamadı !!!");
                return false;
            }
            list.get(index).setIslemMiktari(type.getIslemMiktari());
            list.get(index).setIslemTutari(type.getIslemTutari());
            list.get(index).setKdvTutari(type.getKdvTutari());
            list.get(index).setMusteriNo(type.getMusteriNo());
            list.get(index).setUrunKodu(type.getUrunKodu());

            return true;
        } catch (Exception ex) {
            System.err.println(ex);
            return false;
        }
    }

    @Override
    public boolean Sil(ArrayList<TypeMusteriSepeti> list, TypeMusteriSepeti type) {
        try {
            list.remove(type);
            return true;
        } catch (Exception ex) {
            System.err.println(ex);
            return false;
        }
    }

    @Override
    public void Listele(ArrayList<TypeMusteriSepeti> list) {
        if (list.isEmpty()) {
            System.out.println("Boş!!!");
            return;
        }
        System.out.println("MusteriKodu\tUrunKodu\tislemMiktari\tKdvTutari\tToplamTutar");
        for (TypeMusteriSepeti typeMusteriSepeti : list) {
            System.out.println(typeMusteriSepeti);
        }
        return;
    }

    public ArrayList<TypeMusteriSepeti> Listele(ArrayList<TypeMusteriSepeti> list, TypeMusteriSepeti type) {
        ArrayList<TypeMusteriSepeti> bulunanlar = new ArrayList<TypeMusteriSepeti>();

        for (TypeMusteriSepeti typeMusteriSepeti : list) {
            if (typeMusteriSepeti.getMusteriNo().equals(type.getMusteriNo())) {
                bulunanlar.add(typeMusteriSepeti);
            }
        }

        return bulunanlar;
    }

    @Override
    public int Sec(ArrayList<TypeMusteriSepeti> list, TypeMusteriSepeti type) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getMusteriNo().equals(type.getMusteriNo()) && list.get(i).getUrunKodu().equals(type.getUrunKodu())) {
                return i;
            }
        }
        return -1;
    }
    

    @Override
    public TypeMusteriSepeti Ara(ArrayList<TypeMusteriSepeti> list, TypeMusteriSepeti type) {

        for (TypeMusteriSepeti typeMusteriSepeti : list) {
            if (typeMusteriSepeti.getMusteriNo().equals(type.getMusteriNo())
                    && typeMusteriSepeti.getUrunKodu().equals(type.getUrunKodu())) {
                return typeMusteriSepeti;
            }
        }
        return null;
    }

    @Override
    public void Yazdir(TypeMusteriSepeti type) {
        System.out.println("MusteriKodu\tUrunKodu\tislemMiktari\tKdvTutari\tToplamTutar");
        System.out.println(type);
    }
}
