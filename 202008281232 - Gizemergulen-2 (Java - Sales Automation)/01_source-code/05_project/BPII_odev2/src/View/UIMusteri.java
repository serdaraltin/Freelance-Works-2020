package View;

import javax.swing.*;
import Database.Veritabani;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

public class UIMusteri extends JFrame {

    Veritabani veritabani = new Veritabani();
    int id = 0;

    public UIMusteri() {
        initComponents();

        setSize(350, 410);
        setLocationRelativeTo(null);
        setVisible(true);
        setTitle("Müşteri");
    }

    public UIMusteri(int _id) {
        id = _id;
        initComponents();
        try {
            ArrayList<String> bilgiler = veritabani.GetirMusteri(id);
            txtTc.setText(bilgiler.get(1));
            txtAd.setText(bilgiler.get(2));
            txtSoyad.setText(bilgiler.get(3));
            txtTelefon.setText(bilgiler.get(4));
            txtAdres.setText(bilgiler.get(5));
            txtEmail.setText(bilgiler.get(6));
            txtSosyalMedya.setText(bilgiler.get(7));
            txtPosta.setText(bilgiler.get(8));
            setTitle("Müşteri NO : " + bilgiler.get(0));
            setSize(350, 410);
            setLocationRelativeTo(null);
            setVisible(true);
        } catch (SQLException ex) {
            Logger.getLogger(UIMusteri.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private void initComponents() {
       ///setType(Type.POPUP);
        txtTc = new javax.swing.JTextField();
        lblAd = new javax.swing.JLabel();
        lblBaslik = new javax.swing.JLabel();
        txtSoyad = new javax.swing.JTextField();
        lblAd2 = new javax.swing.JLabel();
        txtAd = new javax.swing.JTextField();
        lblAd3 = new javax.swing.JLabel();
        txtTelefon = new javax.swing.JTextField();
        lblAd4 = new javax.swing.JLabel();
        txtAdres = new javax.swing.JTextField();
        lblAd5 = new javax.swing.JLabel();
        lblAd6 = new javax.swing.JLabel();
        txtEmail = new javax.swing.JTextField();
        lblAd7 = new javax.swing.JLabel();
        txtSosyalMedya = new javax.swing.JTextField();
        txtPosta = new javax.swing.JTextField();
        lblAd8 = new javax.swing.JLabel();
        btnEkle = new javax.swing.JButton();

       
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        getContentPane().add(txtTc, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 70, 210, -1));

        lblAd.setText("Tc no");
        getContentPane().add(lblAd, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 70, 90, 30));

        lblBaslik.setFont(new java.awt.Font("Dialog", 1, 24));
        lblBaslik.setText("MÜŞTERİ EKLE");
        if (id != 0) {
            lblBaslik.setText("MÜŞTERİ GÜNCELLE");
        }

        getContentPane().add(lblBaslik, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 20, -1, -1));

        getContentPane().add(txtSoyad, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 130, 210, -1));
        lblAd2.setText("Soyad");
        getContentPane().add(lblAd2, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 130, 90, 30));

        getContentPane().add(txtAd, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 100, 210, -1));
        lblAd3.setText("Ad");
        getContentPane().add(lblAd3, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 100, 90, 30));

        getContentPane().add(txtTelefon, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 160, 210, -1));
        lblAd4.setText("Telefon");
        getContentPane().add(lblAd4, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 160, 90, 30));

        getContentPane().add(txtAdres, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 190, 210, -1));
        lblAd5.setText("Adres");
        getContentPane().add(lblAd5, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 190, 90, 30));

        lblAd6.setText("Email");
        getContentPane().add(lblAd6, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 220, 90, 30));
        getContentPane().add(txtEmail, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 220, 210, -1));

        lblAd7.setText("Sosyal Medya");
        getContentPane().add(lblAd7, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 250, 90, 30));

        getContentPane().add(txtSosyalMedya, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 250, 210, -1));

        getContentPane().add(txtPosta, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 280, 210, -1));

        lblAd8.setText("Posta");
        getContentPane().add(lblAd8, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 280, 90, 30));

        btnEkle.setFont(new java.awt.Font("Dialog", 1, 18));

        btnEkle.setText("Müşteri Ekle");

        if (id != 0) {
            btnEkle.setText("Müşteri Güncelle");
        }
        btnEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {

                if (id == 0) {
                    String sorgu = "Insert Into tbl_musteri (tc,ad,soyad,telefon,adres,email,sosyal_medya,posta) Values('"
                            + txtTc.getText() + "','"
                            + txtAd.getText() + "','"
                            + txtSoyad.getText() + "','"
                            + txtTelefon.getText() + "','"
                            + txtAdres.getText() + "','"
                            + txtEmail.getText() + "','"
                            + txtSosyalMedya.getText() + "','"
                            + txtPosta.getText() + "')";
                    if (veritabani.Sorgu(sorgu)) {
                        JOptionPane.showMessageDialog(null, "Kayıt eklendi.");
                    } else {
                        JOptionPane.showMessageDialog(null, "Kayıt başarısız.");
                    }
                } else {
                    String sorgu = "Update tbl_musteri set tc='" + txtTc.getText() + "',ad='" + txtAd.getText() + "',soyad='" + txtSoyad.getText()
                            + "',telefon='" + txtTelefon.getText()
                            + "',adres='" + txtAdres.getText() + "',email='" + txtEmail.getText()
                            + "',sosyal_medya='" + txtSosyalMedya.getText() + "',posta='" + txtPosta.getText() + "' where id=" + id;

                    if (veritabani.Sorgu(sorgu)) {
                        JOptionPane.showMessageDialog(null, "Kayıt güncellendi.");
                    } else {
                        JOptionPane.showMessageDialog(null, "Güncelleme başarısız.");
                    }
                }
            }
        });
        getContentPane().add(btnEkle, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 320, 210, 50));

        pack();

    }

    private javax.swing.JButton btnEkle;
    private javax.swing.JLabel lblAd;
    private javax.swing.JLabel lblAd2;
    private javax.swing.JLabel lblAd3;
    private javax.swing.JLabel lblAd4;
    private javax.swing.JLabel lblAd5;
    private javax.swing.JLabel lblAd6;
    private javax.swing.JLabel lblAd7;
    private javax.swing.JLabel lblAd8;
    private javax.swing.JLabel lblBaslik;
    private javax.swing.JTextField txtAd;
    private javax.swing.JTextField txtAdres;
    private javax.swing.JTextField txtEmail;
    private javax.swing.JTextField txtPosta;
    private javax.swing.JTextField txtSosyalMedya;
    private javax.swing.JTextField txtSoyad;
    private javax.swing.JTextField txtTc;
    private javax.swing.JTextField txtTelefon;
}
