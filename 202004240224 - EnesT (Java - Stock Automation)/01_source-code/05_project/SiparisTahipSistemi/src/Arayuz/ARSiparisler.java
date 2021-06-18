package Arayuz;

import Veritabani.Veritabani;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

public class ARSiparisler extends javax.swing.JFrame {

    Veritabani veritabani = new Veritabani();
    int id = 0;

    public ARSiparisler() {
        initComponents();

        setSize(840, 480);
        setResizable(false);
        setLocationRelativeTo(null);
        setVisible(true);
        try {
            Listele();
        } catch (SQLException ex) {
            Logger.getLogger(ARSiparisler.class.getName()).log(Level.SEVERE, null, ex);
        }
        ;
    }

    private void Listele() throws SQLException {
        veritabani.Siparisler(tablo);
    }

    private void AraSiparis(int id) throws SQLException {
        veritabani.Siparisler(tablo, id);
    }

    private void AraMusteri(int musteri_id) throws SQLException {
        veritabani.SiparislerMus(tablo, musteri_id);
    }

    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        tablo = new javax.swing.JTable();
        txtSiparisNo = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        btnSiparisAra = new javax.swing.JButton();
        txtMusteriNo = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        btnUrunEkle = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        btnMusteriAra = new javax.swing.JButton();
        btnSil = new javax.swing.JButton();
        btnSiparisEkle = new javax.swing.JButton();
        btnMusteriEkle = new javax.swing.JButton();
        btnYenile = new javax.swing.JButton();
        btnGuncelle = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        tablo.setModel(new javax.swing.table.DefaultTableModel(
                new Object[][]{},
                new String[]{
                    "ID", "Müşteri ID", "Ürün ID", "Adet", "Toplam", "Tarih", "Durum"
                }
        ) {
            boolean[] canEdit = new boolean[]{
                false, false, false, false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit[columnIndex];
            }
        });
        jScrollPane1.setViewportView(tablo);

        getContentPane().add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(6, 100, 822, 340));
        getContentPane().add(txtSiparisNo, new org.netbeans.lib.awtextra.AbsoluteConstraints(440, 10, 60, 30));

        jLabel1.setText("Sipariş No");
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(370, 10, -1, 30));

        btnSiparisAra.setText("Ara");
        getContentPane().add(btnSiparisAra, new org.netbeans.lib.awtextra.AbsoluteConstraints(510, 10, 70, 28));
        getContentPane().add(txtMusteriNo, new org.netbeans.lib.awtextra.AbsoluteConstraints(680, 10, 60, 30));
        btnSiparisAra.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                try {
                    AraSiparis(Integer.parseInt(txtSiparisNo.getText()));
                } catch (SQLException ex) {
                    Logger.getLogger(ARSiparisler.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
        jLabel2.setText("Müşteri No");
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(600, 10, -1, 30));

        btnUrunEkle.setText("Ürün Ekle");
        btnUrunEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnUrunEkleActionPerformed(evt);
            }
        });
        getContentPane().add(btnUrunEkle, new org.netbeans.lib.awtextra.AbsoluteConstraints(715, 50, 108, 40));

        jLabel3.setFont(new java.awt.Font("Dialog", 1, 24));
        jLabel3.setText("SİPARİŞLER");
        getContentPane().add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 10, 300, -1));

        btnMusteriAra.setText("Ara");
        getContentPane().add(btnMusteriAra, new org.netbeans.lib.awtextra.AbsoluteConstraints(750, 10, 70, 28));
        btnMusteriAra.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                try {
                    AraMusteri(Integer.parseInt(txtMusteriNo.getText()));
                } catch (SQLException ex) {
                    Logger.getLogger(ARSiparisler.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });

        btnSil.setText("Sil");
        btnSil.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                try {
                    btnSilActionPerformed(evt);
                } catch (SQLException ex) {
                    Logger.getLogger(ARSiparisler.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
        getContentPane().add(btnSil, new org.netbeans.lib.awtextra.AbsoluteConstraints(210, 50, 95, 40));

        btnSiparisEkle.setText("Sipariş Ekle");
        btnSiparisEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSiparisEkleActionPerformed(evt);
            }
        });
        getContentPane().add(btnSiparisEkle, new org.netbeans.lib.awtextra.AbsoluteConstraints(430, 50, 165, 40));

        btnMusteriEkle.setText("Müşteri Ekle");
        btnMusteriEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnMusteriEkleActionPerformed(evt);
            }
        });
        getContentPane().add(btnMusteriEkle, new org.netbeans.lib.awtextra.AbsoluteConstraints(600, 50, 110, 40));

        btnYenile.setText("Yenile");
        btnYenile.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                try {
                    btnYenileActionPerformed(evt);
                } catch (SQLException ex) {
                    Logger.getLogger(ARSiparisler.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
        getContentPane().add(btnYenile, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 50, 95, 40));

        btnGuncelle.setText("Güncelle");
        btnGuncelle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                try {
                    btnGuncelleActionPerformed(evt);
                } catch (SQLException ex) {
                    Logger.getLogger(ARSiparisler.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
        getContentPane().add(btnGuncelle, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 50, 95, 40));

        tablo.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            public void valueChanged(ListSelectionEvent evt) {

                tabloSatirSec(evt);
            }
        });

        pack();
    }

    private void tabloSatirSec(ListSelectionEvent evt) {
        try {
            id = Integer.parseInt(tablo.getValueAt(tablo.getSelectedRow(), 0).toString());
        } catch (Exception ex) {

        }
    }

    private void btnUrunEkleActionPerformed(java.awt.event.ActionEvent evt) {
        ARUrun aRUrun = new ARUrun();
    }

    private void btnSilActionPerformed(java.awt.event.ActionEvent evt) throws SQLException {
        if (veritabani.Sorgu("Delete From tbl_siparis where id=" + id)) {
            JOptionPane.showMessageDialog(null, "Silindi.");
            Listele();
        } else {
            JOptionPane.showMessageDialog(null, "İşlem başarısız.");
        }
    }

    private void btnSiparisEkleActionPerformed(java.awt.event.ActionEvent evt) {
        ArSiparis arSiparis = new ArSiparis();
    }

    private void btnMusteriEkleActionPerformed(java.awt.event.ActionEvent evt) {
        ARMusteri aRMusteri = new ARMusteri();
    }

    private void btnYenileActionPerformed(java.awt.event.ActionEvent evt) throws SQLException {
        Listele();
    }

    private void btnGuncelleActionPerformed(java.awt.event.ActionEvent evt) throws SQLException {
        ArSiparis arSiparis = new ArSiparis(id);
    }



    private javax.swing.JButton btnGuncelle;
    private javax.swing.JButton btnMusteriAra;
    private javax.swing.JButton btnMusteriEkle;
    private javax.swing.JButton btnSil;
    private javax.swing.JButton btnSiparisAra;
    private javax.swing.JButton btnSiparisEkle;
    private javax.swing.JButton btnUrunEkle;
    private javax.swing.JButton btnYenile;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable tablo;
    private javax.swing.JTextField txtMusteriNo;
    private javax.swing.JTextField txtSiparisNo;

}
