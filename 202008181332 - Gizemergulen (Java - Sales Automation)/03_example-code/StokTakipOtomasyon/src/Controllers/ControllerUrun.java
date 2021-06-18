package Controllers;

import Interfaces.InterfaceController;
import Types.TypeUrun;
import java.util.ArrayList;

public class ControllerUrun implements InterfaceController<TypeUrun> {

    @Override
    public boolean Ekle(ArrayList<TypeUrun> list, TypeUrun type) {
        try {
            if (Sec(list, type) == -1) {
                list.add(type);
                return true;
            }
            System.out.println("Aynı kodda ürün bulunmaktadır !!!");
            return false;
        } catch (Exception ex) {
            System.err.println(ex);
            return false;
        }
    }

    @Override
    public boolean Guncelle(ArrayList<TypeUrun> list, TypeUrun type) {
        try {
            int index = Sec(list, type);
            if (index == -1) {
                //System.err.println("Güncellenecek ürün bulunamadı !!!");
                return false;
            }
            list.get(index).setAdi(type.getAdi());
            list.get(index).setBirimFiyati(type.getBirimFiyati());
            list.get(index).setKdvOrani(type.getKdvOrani());
            return true;
        } catch (Exception ex) {
            System.err.println(ex);
            return false;
        }
    }

    @Override
    public boolean Sil(ArrayList<TypeUrun> list, TypeUrun type) {
        try {
            int index = Sec(list, type);
            if (list.get(index).getUrunkodu() != null) {
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
    public void Listele(ArrayList<TypeUrun> list) {
        if (list.isEmpty()) {
            System.out.println("Boş!!!");
            return;
        }
        System.out.println("UrunKodu\tAdı\tBirimFiyati\tKdvOrani");
        for (TypeUrun typeUrun : list) {
            System.out.println(typeUrun);
        }
        return;
    }

    @Override
    public int Sec(ArrayList<TypeUrun> list, TypeUrun type) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getUrunkodu().equals(type.getUrunkodu())) {
                return i;
            }
        }
        return -1;
    }

    @Override
    public TypeUrun Ara(ArrayList<TypeUrun> list, TypeUrun type) {
        for (TypeUrun typeUrun : list) {
            if (typeUrun.getUrunkodu().equals(type.getUrunkodu())) {
                return typeUrun;
            }
        }
        return null;
    }

    @Override
    public void Yazdir(TypeUrun type) {
        System.out.println("UrunKodu\tAdı\tBirimFiyati\tKdvOrani");
        System.out.println(type);
    }

}
