package Gui;

import Controller.ControllerUser;
import Type.TypeBasicUser;
import java.util.Random;
import javax.swing.JOptionPane;

public class FrameUser extends javax.swing.JFrame {

    ControllerUser user = new ControllerUser();
    int KID = 0;

    public FrameUser() {
        initComponents();
        setLocationRelativeTo(null);

        Random random = new Random();
        int uretilenKullanicID = random.nextInt(9999) + 1000;
        while (user.Getir(uretilenKullanicID) != null) {
            uretilenKullanicID = random.nextInt(9999) + 1000;
        }
        txtKullaniciId.setText(String.valueOf(uretilenKullanicID));
    }

    public FrameUser(int kullaniciId) {
        if (user.Getir(kullaniciId) != null) {
            initComponents();
            setLocationRelativeTo(null);
            KID = kullaniciId;

            setTitle("Güncelle >> " + KID);
            txtKullaniciId.setText(String.valueOf(KID));
            TypeBasicUser basicUser = user.Getir(KID);
            txtAd.setText(basicUser.getAd());
            txtSoyad.setText(basicUser.getSoyad());
            txtEposta.setText(basicUser.getEposta());
            txtParola.setText(basicUser.getParola());

            btnEkle.setText("GÜNCELLE");
        }  
        if (user.Getir(kullaniciId) == null) { 
            JOptionPane.showMessageDialog(null, "Kullanıcı bulunamadı!");
            this.dispose();
        }
    }

  
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        txtKullaniciId = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        txtAd = new javax.swing.JTextField();
        txtSoyad = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        txtEposta = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        btnEkle = new javax.swing.JButton();
        txtParola = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Kullanıcı Ekle");

        txtKullaniciId.setEnabled(false);

        jLabel2.setText("Ad");
        jLabel2.setToolTipText("");

        txtSoyad.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                txtSoyadKeyReleased(evt);
            }
        });

        jLabel3.setText("Soyad");
        jLabel3.setToolTipText("");

        txtEposta.setText("@stu.aydin.edu.tr");
        txtEposta.setEnabled(false);

        jLabel4.setText("Eposta Adresi");
        jLabel4.setToolTipText("");

        btnEkle.setText("EKLE");
        btnEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEkleActionPerformed(evt);
            }
        });

        jLabel5.setText("Parola");
        jLabel5.setToolTipText("");

        jLabel6.setText("ID");
        jLabel6.setToolTipText("");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel3)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                        .addComponent(btnEkle, javax.swing.GroupLayout.PREFERRED_SIZE, 136, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel4)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jLabel5)
                                        .addGap(52, 52, 52))
                                    .addGroup(layout.createSequentialGroup()
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(jLabel6)
                                            .addComponent(jLabel2))
                                        .addGap(72, 72, 72)))
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(txtKullaniciId, javax.swing.GroupLayout.DEFAULT_SIZE, 191, Short.MAX_VALUE)
                                    .addComponent(txtAd)
                                    .addComponent(txtSoyad)
                                    .addComponent(txtParola, javax.swing.GroupLayout.Alignment.TRAILING))))
                        .addComponent(txtEposta, javax.swing.GroupLayout.DEFAULT_SIZE, 281, Short.MAX_VALUE)))
                .addContainerGap(26, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(51, 51, 51)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txtKullaniciId, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel6))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(txtAd, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(txtSoyad, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(txtParola, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(24, 24, 24)
                .addComponent(jLabel4)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(txtEposta, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(btnEkle, javax.swing.GroupLayout.PREFERRED_SIZE, 43, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(17, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void txtSoyadKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtSoyadKeyReleased
        if (KID == 0) {
            txtEposta.setText(txtAd.getText().toLowerCase() + "" + txtSoyad.getText().toLowerCase() + "@stu.aydin.edu.tr");
        }
    }//GEN-LAST:event_txtSoyadKeyReleased

    private void btnEkleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnEkleActionPerformed
        if (txtAd.getText().equals("") || txtSoyad.getText().equals("") || txtParola.getText().equals("")) {
            JOptionPane.showMessageDialog(null, "Gerekli alanları doldurunuz");
            return;
        }
        if (KID == 0) {
            if (user.Ekle(new TypeBasicUser(Integer.parseInt(txtKullaniciId.getText()), txtAd.getText(), txtSoyad.getText(), txtEposta.getText(), txtParola.getText()))) {
                JOptionPane.showMessageDialog(null, "Kullanıcı eklendi.");
            } else {
                JOptionPane.showMessageDialog(null, "Kullanıcı eklenemedi.\nGirilen bilgileri kontrol ediniz\nNot: Aynı kullanıcı tekrar eklenemez!");
            }
            return;
        }
        if (user.Guncelle(new TypeBasicUser(Integer.parseInt(txtKullaniciId.getText()), txtAd.getText(), txtSoyad.getText(), txtEposta.getText(), txtParola.getText()))) {
            JOptionPane.showMessageDialog(null, "Kullanıcı güncellendi.");
        } else {
            JOptionPane.showMessageDialog(null, "Kullanıcı güncellenemedi!\nBilgileri kontrol ediniz.");
        }
    }//GEN-LAST:event_btnEkleActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnEkle;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JTextField txtAd;
    private javax.swing.JTextField txtEposta;
    private javax.swing.JTextField txtKullaniciId;
    private javax.swing.JTextField txtParola;
    private javax.swing.JTextField txtSoyad;
    // End of variables declaration//GEN-END:variables
}
