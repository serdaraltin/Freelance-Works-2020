package Gui;

public class FrameUserPanel extends javax.swing.JFrame {

    String mail;

    public FrameUserPanel(String Eposta) {
        initComponents();
        setLocationRelativeTo(null);

        mail = Eposta;
        
        setTitle(mail);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        btnGidenKutusu = new javax.swing.JButton();
        btnGelenKutusu = new javax.swing.JButton();
        btnEpostaGonder = new javax.swing.JButton();
        btnCikis = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        btnGidenKutusu.setText("Giden Kutusu");
        btnGidenKutusu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGidenKutusuActionPerformed(evt);
            }
        });

        btnGelenKutusu.setText("Gelen Kutusu");
        btnGelenKutusu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGelenKutusuActionPerformed(evt);
            }
        });

        btnEpostaGonder.setText("E-Posta Gönder");
        btnEpostaGonder.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEpostaGonderActionPerformed(evt);
            }
        });

        btnCikis.setText("Çıkış");
        btnCikis.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCikisActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnCikis, javax.swing.GroupLayout.PREFERRED_SIZE, 269, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnEpostaGonder, javax.swing.GroupLayout.PREFERRED_SIZE, 269, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnGelenKutusu, javax.swing.GroupLayout.PREFERRED_SIZE, 269, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnGidenKutusu, javax.swing.GroupLayout.PREFERRED_SIZE, 269, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(30, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(27, 27, 27)
                .addComponent(btnGelenKutusu, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(btnGidenKutusu, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(btnEpostaGonder, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(btnCikis, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(28, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnGelenKutusuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGelenKutusuActionPerformed
        new FrameMailBox(mail).setVisible(true);
       
    }//GEN-LAST:event_btnGelenKutusuActionPerformed

    private void btnGidenKutusuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGidenKutusuActionPerformed
        new FrameSendBox(mail).setVisible(true);
       
    }//GEN-LAST:event_btnGidenKutusuActionPerformed

    private void btnEpostaGonderActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnEpostaGonderActionPerformed
        new FrameSendMail(mail).setVisible(true);
    }//GEN-LAST:event_btnEpostaGonderActionPerformed

    private void btnCikisActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCikisActionPerformed
        new FrameUserLogin().setVisible(true);
        this.dispose();
    }//GEN-LAST:event_btnCikisActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnCikis;
    private javax.swing.JButton btnEpostaGonder;
    private javax.swing.JButton btnGelenKutusu;
    private javax.swing.JButton btnGidenKutusu;
    // End of variables declaration//GEN-END:variables
}
