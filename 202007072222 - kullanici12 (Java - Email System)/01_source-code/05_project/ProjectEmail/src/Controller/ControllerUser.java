package Controller;

import IO.IOFileOperation;
import Interface.InterfaceController;
import java.util.ArrayList;
import Type.TypeBasicUser;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class ControllerUser implements InterfaceController<TypeBasicUser> {

    IOFileOperation fileOperation = new IOFileOperation();

    String dosyaAdi = "Kullanicilar.txt";

    @Override
    public boolean Ekle(TypeBasicUser veri) {
        if (Kontrol(veri)) {
            return false;
        }

        ArrayList<TypeBasicUser> kullanicilar = Liste();
        kullanicilar.add(veri);

        return fileOperation.DosyaYaz(dosyaAdi, Cevir(kullanicilar));
    }

    @Override
    public boolean Guncelle(TypeBasicUser veri) {
        ArrayList<TypeBasicUser> basicUsers = Liste();

        for (int i = 0; i < basicUsers.size(); i++) {
            if (basicUsers.get(i).getKullaniciId() == veri.getKullaniciId()) {
                basicUsers.set(i, veri);
                break;
            }
        }
        return fileOperation.DosyaYaz(dosyaAdi, Cevir(basicUsers));
    }

    @Override
    public boolean Sil(TypeBasicUser veri) {
        ArrayList<TypeBasicUser> basicUsers = Liste();

        for (int i = 0; i < basicUsers.size(); i++) {
            if (basicUsers.get(i).getKullaniciId() == veri.getKullaniciId()) {
                basicUsers.remove(i);
                break;
            }
        }
        return fileOperation.DosyaYaz(dosyaAdi, Cevir(basicUsers));
    }

    @Override
    public ArrayList<TypeBasicUser> Liste() {
        ArrayList<String[]> veriler = fileOperation.DosyaOku(dosyaAdi);
        if (veriler == null) {
            return null;
        }

        ArrayList<TypeBasicUser> kullanicilar = new ArrayList<TypeBasicUser>();

        for (String[] veri : veriler) {
            kullanicilar.add(new TypeBasicUser(Integer.parseInt(veri[0]), veri[1], veri[2], veri[3], veri[4]));
        }
        return kullanicilar;
    }

    public TypeBasicUser Giris(String Eposta, String Parola) {
        if (Liste() == null) {
            return null;
        }

        for (TypeBasicUser basicUser : Liste()) {
            if (basicUser.getEposta().equals(Eposta) && basicUser.getParola().equals(Parola) ) {
                return basicUser;
            }
        }
        return null;
    }

    @Override
    public TypeBasicUser Ara(TypeBasicUser veri) {
        if (Liste() == null) {
            return null;
        }

        for (TypeBasicUser basicUser : Liste()) {
            if (basicUser.getAd().equals(veri.getAd()) || basicUser.getSoyad().equals(veri.getSoyad()) || basicUser.getEposta().equals(veri.getEposta())) {
                return basicUser;
            }
        }
        return null;
    }

    public ArrayList<TypeBasicUser> Ara(String aranan) {
        if (Liste() == null) {
            return null;
        }
        ArrayList<TypeBasicUser> sonuc = new ArrayList<TypeBasicUser>();
        for (TypeBasicUser basicUser : Liste()) {
            aranan = aranan.toLowerCase();
            if (basicUser.getAd().toLowerCase().contains(aranan) || basicUser.getSoyad().toLowerCase().contains(aranan) || basicUser.getEposta().toLowerCase().contains(aranan)) {
                sonuc.add(basicUser);
            }
        }
        return sonuc;
    }

    @Override
    public TypeBasicUser Getir(int id) {
        if (Liste() == null) {
            return null;
        }

        for (TypeBasicUser basicUser : Liste()) {
            if (basicUser.getKullaniciId() == id) {
                return basicUser;
            }
        }
        return null;
    }

    public TypeBasicUser Getir(String eposta) {
        if (Liste() == null) {
            return null;
        }

        for (TypeBasicUser basicUser : Liste()) {
            if (basicUser.getEposta().equals(eposta)) {
                return basicUser;
            }
        }
        return null;
    }

    public boolean Kontrol(TypeBasicUser veri) {
        if (Liste() == null) {
            return false;
        }
        for (TypeBasicUser basicUser : Liste()) {
            if (basicUser.getAd().equals(veri.getAd()) && basicUser.getSoyad().equals(veri.getSoyad())) {
                return true;
            }
        }
        return false;
    }

    @Override
    public ArrayList<String[]> Cevir(ArrayList<TypeBasicUser> veriler) {
        if (veriler == null) {
            return null;
        }
        ArrayList<String[]> cikti = new ArrayList<String[]>();
        for (TypeBasicUser typeBasicUser : veriler) {
            String[] bilgiler = {
                String.valueOf(typeBasicUser.getKullaniciId()),
                typeBasicUser.getAd(),
                typeBasicUser.getSoyad(),
                typeBasicUser.getEposta(),
                typeBasicUser.getParola()
            };
            cikti.add(bilgiler);
        }
        return cikti;
    }

    @Override
    public DefaultTableModel TabloDoldur(JTable Tablo, ArrayList<TypeBasicUser> veriler) {
        DefaultTableModel model = (DefaultTableModel) Tablo.getModel();

        model.setRowCount(0);

        for (TypeBasicUser user : veriler) {
            model.addRow(new Object[]{
                user.getKullaniciId(),
                user.getEposta(),
                user.getAd(),
                user.getSoyad(),
                user.getParola()
            });
        }
        return model;

    }
}
