package Controller;

import IO.IOFileOperation;
import Interface.InterfaceController;
import Type.TypeMail;
import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class ControllerMail implements InterfaceController<TypeMail> {

    ControllerUser controllerUser = new ControllerUser();
    IOFileOperation fileOperation = new IOFileOperation();

    public boolean Ekle(String gonderen, String[] alicilar, String konu, String govde) {

        int gonderenId = controllerUser.Getir(gonderen).getKullaniciId();
        String dosyaGonderen = "SentMailBox (" + gonderenId + ").txt";

        ArrayList<TypeMail> gonderenEpostalar = new ArrayList<TypeMail>();

        for (String alici : alicilar) {

            TypeMail mail = new TypeMail();
            mail.setGonderen(controllerUser.Getir(gonderen));
            mail.setAlan(controllerUser.Getir(alici));
            mail.setKonu(konu);
            mail.setGovde(govde);

            if (Liste(dosyaGonderen) != null) {
                gonderenEpostalar = Liste(dosyaGonderen);
            }
            gonderenEpostalar.add(mail);
        }
        fileOperation.DosyaYaz(dosyaGonderen, Cevir(gonderenEpostalar));

        for (String alici : alicilar) {
            ArrayList<TypeMail> alanEpostalar = new ArrayList<TypeMail>();
            TypeMail mail = new TypeMail();
            int alanId = controllerUser.Getir(alici).getKullaniciId();
            String dosyaAlan = "MailBox (" + alanId + ").txt";

            mail.setGonderen(controllerUser.Getir(gonderen));
            mail.setAlan(controllerUser.Getir(alici));
            mail.setKonu(konu);
            mail.setGovde(govde);

            if (Liste(dosyaAlan) != null) {
                alanEpostalar = Liste(dosyaAlan);
            }
            alanEpostalar.add(mail);
            fileOperation.DosyaYaz(dosyaAlan, Cevir(alanEpostalar));
        }

        return true;
    }

    @Override
    public boolean Ekle(TypeMail veri) {
        int gonderenId = veri.getGonderen().getKullaniciId();
        int alanId = veri.getAlan().getKullaniciId();
        String dosyaGonderen = "SentMailBox (" + gonderenId + ").txt";
        String dosyaAlan = "MailBox (" + alanId + ").txt";

        ArrayList<TypeMail> gonderenEpostalar = new ArrayList<TypeMail>();
        if (Liste(dosyaGonderen) != null) {
            gonderenEpostalar = Liste(dosyaGonderen);
        }
        gonderenEpostalar.add(veri);

        ArrayList<TypeMail> alanEpostalar = new ArrayList<TypeMail>();
        if (Liste(dosyaAlan) != null) {
            alanEpostalar = Liste(dosyaAlan);
        }
        alanEpostalar.add(veri);

        if (fileOperation.DosyaYaz(dosyaGonderen, Cevir(gonderenEpostalar))
                && fileOperation.DosyaYaz(dosyaAlan, Cevir(alanEpostalar))) {
            return true;
        }
        return false;
    }

    @Override
    public boolean Guncelle(TypeMail veri) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public boolean Sil(String dosyaAdi, TypeMail veri) {

        ArrayList<TypeMail> Epostalar = new ArrayList<TypeMail>();
        if (Liste(dosyaAdi) != null) {
            Epostalar = Liste(dosyaAdi);
        }
   
        for (int i = 0; i < Epostalar.size(); i++) {
            if(Kontrol(Epostalar.get(i), veri)){
               Epostalar.remove(i);
            }
        }
        return fileOperation.DosyaYaz(dosyaAdi, Cevir(Epostalar));
    }

    public boolean Kontrol(TypeMail veri1, TypeMail veri2) {
        if (veri1.getGonderen().getEposta().equals(veri2.getGonderen().getEposta())
                && veri1.getAlan().getEposta().equals(veri2.getAlan().getEposta())
                && veri1.getKonu().equals(veri2.getKonu())
                && veri1.getGovde().equals(veri2.getGovde())) {
            return true;
        }
        return false;
    }

    public ArrayList<TypeMail> Liste(String dosyaAdi) {
        ArrayList<String[]> veriler = fileOperation.DosyaOku(dosyaAdi);
        if (veriler == null) {
            return null;
        }

        ArrayList<TypeMail> epostalar = new ArrayList<TypeMail>();

        for (String[] veri : veriler) {
            epostalar.add(new TypeMail(controllerUser.Getir(veri[0]), controllerUser.Getir(veri[1]), veri[2], veri[3]));
        }
        return epostalar;
    }

    @Override
    public TypeMail Ara(TypeMail veri) {
        if (Liste() == null) {
            return null;
        }

        for (TypeMail mail : Liste()) {
            if (mail.getGonderen().equals(veri.getGonderen()) || mail.getAlan().equals(veri.getAlan()) || mail.getKonu().equals(veri.getKonu())) {
                return mail;
            }
        }
        return null;
    }

    @Override
    public TypeMail Getir(int id) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public ArrayList<String[]> Cevir(ArrayList<TypeMail> veriler) {
        if (veriler == null) {
            return null;
        }
        ArrayList<String[]> cikti = new ArrayList<String[]>();
        for (TypeMail mail : veriler) {
            String[] bilgiler = {
                mail.getGonderen().getEposta(),
                mail.getAlan().getEposta(),
                mail.getKonu(),
                mail.getGovde()
            };
            cikti.add(bilgiler);
        }
        return cikti;
    }

    @Override
    public ArrayList<TypeMail> Liste() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public boolean Sil(TypeMail veri) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public DefaultTableModel TabloDoldur(JTable Tablo, ArrayList<TypeMail> veriler) {
        if(veriler == null)
            return null;
        DefaultTableModel model = (DefaultTableModel) Tablo.getModel();

        model.setRowCount(0);

        for (TypeMail mail : veriler) {
            model.addRow(new Object[]{
                mail.getGonderen().getEposta(),
                mail.getKonu(),
                mail.getGovde()
            });
        }
        return model;
    }

    public DefaultTableModel TabloDoldur(boolean sentBox, JTable Tablo, ArrayList<TypeMail> veriler) {
        DefaultTableModel model = (DefaultTableModel) Tablo.getModel();

        model.setRowCount(0);

        for (TypeMail mail : veriler) {
            model.addRow(new Object[]{
                mail.getAlan().getEposta(),
                mail.getKonu(),
                mail.getGovde()
            });
        }
        return model;
    }

}
