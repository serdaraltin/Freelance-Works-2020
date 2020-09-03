package Gui;

import Controller.ControllerMail;
import Controller.ControllerUser;
import Type.TypeBasicUser;
import Type.TypeMail;
import javax.swing.JOptionPane;

public class FrameMailBox extends javax.swing.JFrame {

    ControllerMail controllerMail = new ControllerMail();
    ControllerUser controllerUser = new ControllerUser();

    String mail;
    TypeBasicUser user;
    String dosyaAdi;

    public FrameMailBox() {
        initComponents();
        setLocationRelativeTo(null);
    }

    public FrameMailBox(String eposta) {
        initComponents();
        setLocationRelativeTo(null);

        user = controllerUser.Getir(eposta);
        mail = eposta;
        setTitle("Gelen Kutusu >> " + user.getAd() + " " + user.getSoyad());
        dosyaAdi = "MailBox (" + user.getKullaniciId() + ").txt";
        Listele();
    }

    public void Listele() {
        if (controllerMail.Liste(dosyaAdi) != null) {
            tbMailler.setModel(controllerMail.TabloDoldur(tbMailler, controllerMail.Liste(dosyaAdi)));
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        tbMailler = new javax.swing.JTable();
        btnSil = new javax.swing.JButton();
        btnEpostaGonder = new javax.swing.JButton();
        btnYenile = new javax.swing.JButton();
        btnKapat = new javax.swing.JButton();
        btnGoruntule = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        tbMailler.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Gönderen", "Konu", "İçerik"
            }
        ));
        jScrollPane1.setViewportView(tbMailler);

        btnSil.setText("Sil");
        btnSil.setToolTipText("");
        btnSil.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSilActionPerformed(evt);
            }
        });

        btnEpostaGonder.setText("E-Posta Gönder");
        btnEpostaGonder.setToolTipText("");
        btnEpostaGonder.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEpostaGonderActionPerformed(evt);
            }
        });

        btnYenile.setText("Yenile");
        btnYenile.setToolTipText("");
        btnYenile.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnYenileActionPerformed(evt);
            }
        });

        btnKapat.setText("Kapat");
        btnKapat.setToolTipText("");
        btnKapat.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnKapatActionPerformed(evt);
            }
        });

        btnGoruntule.setText("Görüntüle");
        btnGoruntule.setToolTipText("");
        btnGoruntule.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGoruntuleActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 751, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btnEpostaGonder)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnYenile)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnGoruntule)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnSil)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnKapat)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnSil)
                    .addComponent(btnEpostaGonder)
                    .addComponent(btnYenile)
                    .addComponent(btnKapat)
                    .addComponent(btnGoruntule))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 380, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnEpostaGonderActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnEpostaGonderActionPerformed
        new FrameSendMail(user.getEposta()).setVisible(true);
    }//GEN-LAST:event_btnEpostaGonderActionPerformed

    private void btnKapatActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnKapatActionPerformed
        this.dispose();
    }//GEN-LAST:event_btnKapatActionPerformed

    private void btnSilActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSilActionPerformed
        TypeMail mail = new TypeMail();
        try {
            String gonderenEposta = tbMailler.getValueAt(tbMailler.getSelectedRow(), 0).toString();
            TypeBasicUser gonderen = controllerUser.Getir(gonderenEposta);
            mail.setGonderen(gonderen);
            mail.setAlan(user);
            mail.setKonu(tbMailler.getValueAt(tbMailler.getSelectedRow(), 1).toString());
            mail.setGovde(tbMailler.getValueAt(tbMailler.getSelectedRow(), 2).toString());

            if (controllerMail.Sil(dosyaAdi, mail)) {
                JOptionPane.showMessageDialog(null, "E-posta silindi.");
                Listele();
            } else {
                JOptionPane.showMessageDialog(null, "E-posta silinemedi !");
            }
        } catch (Exception ex) {
        }

    }//GEN-LAST:event_btnSilActionPerformed

    private void btnGoruntuleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGoruntuleActionPerformed
        TypeMail mail = new TypeMail();
        try {
            String gonderenEposta = tbMailler.getValueAt(tbMailler.getSelectedRow(), 0).toString();
            TypeBasicUser gonderen = controllerUser.Getir(gonderenEposta);
            mail.setGonderen(gonderen);
            mail.setAlan(user);
            mail.setKonu(tbMailler.getValueAt(tbMailler.getSelectedRow(), 1).toString());
            mail.setGovde(tbMailler.getValueAt(tbMailler.getSelectedRow(), 2).toString());
            new FrameSendMail(mail).setVisible(true);
        } catch (Exception ex) {
        }


    }//GEN-LAST:event_btnGoruntuleActionPerformed

    private void btnYenileActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnYenileActionPerformed
        Listele();
    }//GEN-LAST:event_btnYenileActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnEpostaGonder;
    private javax.swing.JButton btnGoruntule;
    private javax.swing.JButton btnKapat;
    private javax.swing.JButton btnSil;
    private javax.swing.JButton btnYenile;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable tbMailler;
    // End of variables declaration//GEN-END:variables
}
