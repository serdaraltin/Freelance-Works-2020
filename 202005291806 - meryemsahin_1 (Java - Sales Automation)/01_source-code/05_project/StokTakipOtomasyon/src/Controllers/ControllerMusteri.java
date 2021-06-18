package Controllers;

import Interfaces.InterfaceController;
import Types.TypeMusteri;
import java.util.ArrayList;

public class ControllerMusteri implements InterfaceController<TypeMusteri> {

    @Override
    public boolean Ekle(ArrayList<TypeMusteri> list, TypeMusteri type) {
        try {
            if (Sec(list, type) == -1) {
                list.add(type);
                return true;
            }
            System.out.println("Aynı kodda müsteri bulunmaktadır !!!");
            return false;
        } catch (Exception ex) {
            System.err.println(ex);
            return false;
        }

    }

    @Override
    public boolean Guncelle(ArrayList<TypeMusteri> list, TypeMusteri type) {
        try {
            int index = Sec(list, type);
            if (index == -1) {
                //System.err.println("Güncellenecek müşteri bulunamadı !!!");
                return false;
            }
            list.get(index).setAd(type.getAd());
            list.get(index).setSoyad(type.getSoyad());
            return true;
        } catch (Exception ex) {
            System.err.println(ex);
            return false;
        }
    }

    @Override
    public boolean Sil(ArrayList<TypeMusteri> list, TypeMusteri type) {
        try {
            int index = Sec(list, type);
            if (list.get(index).getMusterino() != null) {
                list.remove(index);
                return true;
            }
            return false;
        } catch (Exception ex) {
            System.err.println(ex);
            return false;
        }
    }

    @Override
    public void Listele(ArrayList<TypeMusteri> list) {
        if (list.isEmpty()) {
            System.out.println("boş!!!");
            return;
        }
        System.out.println("MusteriKodu\tAdı\t\tSoyadı");
        for (TypeMusteri typeMusteri : list) {
            System.out.println(typeMusteri);
        }
        return;
    }

    public ArrayList<TypeMusteri> Listele(ArrayList<TypeMusteri> list, TypeMusteri type) {
        ArrayList<TypeMusteri> bulunanlar = new ArrayList<TypeMusteri>();

        for (TypeMusteri typeMusteri : list) {
            if (typeMusteri.veriKontrol(type)) {
                bulunanlar.add(typeMusteri);
            }
        }

        return bulunanlar;
    }

    @Override
    public int Sec(ArrayList<TypeMusteri> list, TypeMusteri type) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getMusterino().equals(type.getMusterino())) {
                return i;
            }
        }
        return -1;
    }

    @Override
    public TypeMusteri Ara(ArrayList<TypeMusteri> list, TypeMusteri type) {
        for (TypeMusteri typeMusteri : list) {
            if (typeMusteri.getMusterino().equals(type.getMusterino())) {
                return typeMusteri;
            }
        }
        return null;
    }

    @Override
    public void Yazdir(TypeMusteri type) {
        System.out.println("MusteriKodu\tAdı\tSoyadı");
        System.out.println(type);
    }

}
