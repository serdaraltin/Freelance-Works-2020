package Arayuz;

import Veritabani.Veritabani;
import java.sql.Date;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.JSpinner;
import javax.swing.SpinnerDateModel;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class ArSiparis extends javax.swing.JFrame {
    
    Veritabani veritabani = new Veritabani();
    int id = 0, toplam = 0, musteri_id = 0, urun_id = 0;
    
    public ArSiparis() {
        initComponents();
        setSize(300, 350);
        setLocationRelativeTo(null);
        setVisible(true);
        setTitle("Sipariş");
        try {
            Listele();
        } catch (SQLException ex) {
            Logger.getLogger(ArSiparis.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public void MusteriSec(String musteri) {
        for (int i = 0; i < cbMusteri.getItemCount(); i++) {
            if (cbMusteri.getItemAt(i).equals(musteri)) {
                cbMusteri.setSelectedIndex(i);
            }
        }
    }
    
    public void UrunSec(String urun) {
        for (int i = 0; i < cbUrun.getItemCount(); i++) {
            if (cbUrun.getItemAt(i).equals(urun)) {
                cbUrun.setSelectedIndex(i);
            }
        }
    }
    
    public ArSiparis(int _id) throws SQLException {
        id = _id;
        initComponents();
        Listele();
        try {
            ArrayList<String> bilgiler = veritabani.GetirSiparis(id);
            musteri_id = Integer.parseInt(bilgiler.get(1));
            urun_id = Integer.parseInt(bilgiler.get(2));
            String musteri = veritabani.GetirMusteri(musteri_id).get(2);
            String urun = veritabani.GetirUrun(urun_id).get(1);
            MusteriSec(musteri);
            UrunSec(urun);
            
            spAdet.setValue(Integer.parseInt(bilgiler.get(3)));
            txtToplam.setText(bilgiler.get(4));
            
            txtTarih.setText(bilgiler.get(5));
            
            if (bilgiler.get(6).equals("Tamam")) {
                cbDurum.setSelectedIndex(1);
            }
            setTitle("Sipariş NO : " + bilgiler.get(0));
            setSize(300, 350);
            setLocationRelativeTo(null);
            setVisible(true);
        } catch (SQLException ex) {
            Logger.getLogger(ARMusteri.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    private void Listele() throws SQLException {
        for (String[] strings : veritabani.ListeleMusteri()) {
            cbMusteri.addItem(strings[2]);
        }
        for (String[] strings : veritabani.ListeleUrun()) {
            
            cbUrun.addItem(strings[1]);
        }
    }
    
    private void initComponents() {
        
        lbMusteri = new javax.swing.JLabel();
        cbMusteri = new javax.swing.JComboBox<>();
        lbToplam = new javax.swing.JLabel();
        cbDurum = new javax.swing.JComboBox<>();
        lbUrun = new javax.swing.JLabel();
        spAdet = new javax.swing.JSpinner();
        txtToplam = new javax.swing.JTextField();
        lbAdet = new javax.swing.JLabel();
        lbTarih = new javax.swing.JLabel();
        lbDurum = new javax.swing.JLabel();
        cbUrun = new javax.swing.JComboBox<>();
        lbBaslik = new javax.swing.JLabel();
        btnEkle = new javax.swing.JButton();
        txtTarih = new javax.swing.JTextField();
        // spTarih = new javax.swing.JSpinner();

        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());
        
        lbMusteri.setText("Müşteri");
        getContentPane().add(lbMusteri, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 70, 70, 30));
        getContentPane().add(cbMusteri, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 70, 170, -1));
        
        lbToplam.setText("Toplam");
        getContentPane().add(lbToplam, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 160, 70, 30));
        
        cbDurum.setModel(new javax.swing.DefaultComboBoxModel<>(new String[]{"Bekleniyor", "Tamam"}));
        getContentPane().add(cbDurum, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 220, 170, -1));
        
        lbUrun.setText("Ürün");
        getContentPane().add(lbUrun, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 100, 70, 30));
        getContentPane().add(spAdet, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 130, 90, -1));
        
        txtToplam.setEditable(false);
        getContentPane().add(txtToplam, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 160, 170, -1));
        
        lbAdet.setText("Adet");
        getContentPane().add(lbAdet, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 130, 70, 30));
        
        lbTarih.setText("Tarih");
        getContentPane().add(lbTarih, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 190, 70, 30));
        
        lbDurum.setText("Durum");
        getContentPane().add(lbDurum, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 220, 70, 30));
        getContentPane().add(cbUrun, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 100, 170, -1));
        
        lbBaslik.setFont(new java.awt.Font("Dialog", 1, 20));
        if (id == 0) {
            lbBaslik.setText("SİPARİŞ EKLE");
        } else {
            lbBaslik.setText("SİPARİŞ GÜNCELLE");
        }
        getContentPane().add(lbBaslik, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 20, -1, -1));
        
        btnEkle.setFont(new java.awt.Font("Dialog", 1, 18));
        if (id == 0) {
            btnEkle.setText("Sipariş Ekle");
        } else {
            btnEkle.setText("Sipariş Güncelle");
        }
        btnEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                int musteri_id = 0, urun_id = 0;
                try {
                    musteri_id = Integer.parseInt(veritabani.GetirMusteri(cbMusteri.getSelectedItem().toString()).get(0));
                    urun_id = Integer.parseInt(veritabani.GetirUrun(cbUrun.getSelectedItem().toString()).get(0));
                } catch (SQLException ex) {
                    Logger.getLogger(ArSiparis.class.getName()).log(Level.SEVERE, null, ex);
                }
                if (id == 0) {
                    
                    String sorgu = "Insert Into tbl_siparis (musteri_id,urun_id,adet,toplam,tarih,durum) Values("
                            + musteri_id + "," + urun_id + "," + Integer.parseInt(spAdet.getValue().toString()) + "," + Integer.parseInt(txtToplam.getText())
                            + ",'" + txtTarih.getText() + "','" + cbDurum.getSelectedItem().toString() + "')";
                    if (veritabani.Sorgu(sorgu)) {
                        JOptionPane.showMessageDialog(null, "Kayıt eklendi.");
                    } else {
                        JOptionPane.showMessageDialog(null, "Kayıt başarısız.");
                    }
                } else {
                    String sorgu = "Update tbl_siparis set musteri_id=" + musteri_id + ",urun_id=" + urun_id + ",adet=" + Integer.parseInt(spAdet.getValue().toString())
                            + ",toplam=" + Integer.parseInt(txtToplam.getText()) + ",durum='" + cbDurum.getSelectedItem().toString() + "' where id=" + id;
                    if (veritabani.Sorgu(sorgu)) {
                        JOptionPane.showMessageDialog(null, "Kayıt güncellendi.");
                    } else {
                        JOptionPane.showMessageDialog(null, "Güncelleme başarısız.");
                    }
                }
            }
        }
        );
        getContentPane()
                .add(btnEkle, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 260, 170, 50));
        /*
        spTarih.setModel(  new javax.swing.SpinnerDateModel());
        spTarih.setEditor(new JSpinner.DateEditor(spTarih,"dd.mm.yyyy"));
        
        getContentPane().add(spTarih, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 190, 170, -1));*/
        
        getContentPane().add(txtTarih, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 190, 170, -1));
        
        SpinnerModel numara = new SpinnerNumberModel(0, 0, 100, 1);
        
        spAdet.setModel(numara);
        
        spAdet.addChangeListener(new ChangeListener() {
            
            public void stateChanged(ChangeEvent ce) {
                int toplam = 0, urunFiyat = 0;
                try {
                    
                    urunFiyat = Integer.parseInt(veritabani.GetirUrun(cbUrun.getSelectedItem().toString()).get(3));
                } catch (SQLException ex) {
                    Logger.getLogger(ArSiparis.class.getName()).log(Level.SEVERE, null, ex);
                }
                toplam = Integer.parseInt(spAdet.getValue().toString()) * urunFiyat;
                txtToplam.setText(Integer.toString(toplam));
            }
        });
        pack();
    }
    
    private javax.swing.JButton btnEkle;
    private javax.swing.JComboBox<String> cbDurum;
    private javax.swing.JComboBox<String> cbMusteri;
    private javax.swing.JComboBox<String> cbUrun;
    private javax.swing.JLabel lbAdet;
    private javax.swing.JLabel lbBaslik;
    private javax.swing.JLabel lbDurum;
    private javax.swing.JLabel lbMusteri;
    private javax.swing.JLabel lbTarih;
    private javax.swing.JLabel lbToplam;
    private javax.swing.JLabel lbUrun;
    private javax.swing.JSpinner spAdet;
    // private javax.swing.JSpinner spTarih;
    private javax.swing.JTextField txtToplam;
    private javax.swing.JTextField txtTarih;
}
