
import java.io.File;
import java.util.ArrayList;
import javax.swing.DefaultListModel;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;

public class Arayuz extends javax.swing.JFrame {

    ArrayList<String[]> muzikListesi = new ArrayList<String[]>();
    static String muzikAdi = "";
    static int satirNo = 0, secilenSatir = 0;

    Kontrol simpleAudioPlayer = new Kontrol();

    public Arayuz() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        lstMuzik = new javax.swing.JList<>();
        btnOynat = new javax.swing.JButton();
        btnDuraklat = new javax.swing.JButton();
        btnDurdur = new javax.swing.JButton();
        btnSonraki = new javax.swing.JButton();
        btnOnceki = new javax.swing.JButton();
        btnEkle = new javax.swing.JButton();
        lbOynatilan = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Müzik Çalar");
        setResizable(false);

        lstMuzik.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                lstMuzikValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(lstMuzik);

        btnOynat.setText("Oynat");
        btnOynat.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnOynatActionPerformed(evt);
            }
        });

        btnDuraklat.setText("Duraklat");
        btnDuraklat.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDuraklatActionPerformed(evt);
            }
        });

        btnDurdur.setText("Durdur");
        btnDurdur.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDurdurActionPerformed(evt);
            }
        });

        btnSonraki.setText("Sonraki");
        btnSonraki.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSonrakiActionPerformed(evt);
            }
        });

        btnOnceki.setText("Önceki");
        btnOnceki.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnOncekiActionPerformed(evt);
            }
        });

        btnEkle.setText("Ekle");
        btnEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEkleActionPerformed(evt);
            }
        });

        lbOynatilan.setText("...");
        lbOynatilan.setMaximumSize(new java.awt.Dimension(9, 388));
        lbOynatilan.setMinimumSize(new java.awt.Dimension(9, 388));
        lbOynatilan.setName(""); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(lbOynatilan, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 282, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(btnOynat, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnDuraklat, javax.swing.GroupLayout.DEFAULT_SIZE, 100, Short.MAX_VALUE)
                            .addComponent(btnDurdur, javax.swing.GroupLayout.DEFAULT_SIZE, 100, Short.MAX_VALUE)
                            .addComponent(btnSonraki, javax.swing.GroupLayout.DEFAULT_SIZE, 100, Short.MAX_VALUE)
                            .addComponent(btnOnceki, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 100, Short.MAX_VALUE)
                            .addComponent(btnEkle, javax.swing.GroupLayout.DEFAULT_SIZE, 100, Short.MAX_VALUE))))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 257, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btnOynat)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnDuraklat)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnDurdur)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnSonraki)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnOnceki)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btnEkle)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(lbOynatilan, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(8, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void lstMuzikValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_lstMuzikValueChanged
        secilenSatir = lstMuzik.getSelectedIndex();
    }//GEN-LAST:event_lstMuzikValueChanged

    private void btnOynatActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnOynatActionPerformed
        if (muzikListesi.isEmpty()) {
            return;
        }
        simpleAudioPlayer.ayarla(muzikListesi.get(secilenSatir)[1]);
        simpleAudioPlayer.oynat();
        lstMuzik.setSelectedIndex(secilenSatir);
        lbOynatilan.setText("Oynatılıyor : " + muzikListesi.get(secilenSatir)[0]);
    }//GEN-LAST:event_btnOynatActionPerformed

    private void btnDuraklatActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDuraklatActionPerformed
        if (simpleAudioPlayer.durum.equals("duraklat")) {
            btnDuraklat.setText("Duraklat");
            simpleAudioPlayer.devam();
            System.out.println(simpleAudioPlayer.konum);
            lbOynatilan.setText("Sürdürülüyor : " + muzikListesi.get(secilenSatir)[0]);
            return;
        }
        if (simpleAudioPlayer.durum.equals("oynat") || simpleAudioPlayer.durum.equals("resume")) {
            simpleAudioPlayer.duraklat();
            btnDuraklat.setText("Sürdür");
            System.out.println(simpleAudioPlayer.konum);
            lbOynatilan.setText("Duraklatıldı : " + muzikListesi.get(secilenSatir)[0]);
        }

    }//GEN-LAST:event_btnDuraklatActionPerformed

    private void btnDurdurActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDurdurActionPerformed
        simpleAudioPlayer.durdur();
         lbOynatilan.setText("...");
    }//GEN-LAST:event_btnDurdurActionPerformed

    private void btnSonrakiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSonrakiActionPerformed
        if (muzikListesi.size() == 0) {
            return;
        }
        if (secilenSatir + 1 > muzikListesi.size() - 1) {
            secilenSatir = 0;
            btnOynatActionPerformed(evt);
            return;
        }
        secilenSatir++;
        btnOynatActionPerformed(evt);
    }//GEN-LAST:event_btnSonrakiActionPerformed

    private void btnOncekiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnOncekiActionPerformed
        if (muzikListesi.size() == 0) {
            return;
        }
        if (secilenSatir - 1 < 0) {
            secilenSatir = muzikListesi.size() - 1;
            btnOynatActionPerformed(evt);
            return;
        }
        secilenSatir--;
        btnOynatActionPerformed(evt);
    }//GEN-LAST:event_btnOncekiActionPerformed

    private void btnEkleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnEkleActionPerformed
        JFileChooser dosyaSec = new JFileChooser();
        dosyaSec.setCurrentDirectory(new File("."));
        FileNameExtensionFilter filter = new FileNameExtensionFilter("Müzik", "aiff");
        dosyaSec.setMultiSelectionEnabled(false);
        dosyaSec.setFileFilter(filter);
        int kontrol = dosyaSec.showOpenDialog(this);
        if (kontrol == JFileChooser.APPROVE_OPTION) {
            String dosyaYolu = dosyaSec.getSelectedFile().getPath();
            String dosyaAdi = dosyaSec.getSelectedFile().getName();
            muzikListesi.add(new String[]{dosyaAdi, dosyaYolu});
        }
        DefaultListModel model = new DefaultListModel();
        muzikListesi.forEach((muzik) -> {
            model.addElement(muzik[0]);
        });
        lstMuzik.setModel(model);
    }//GEN-LAST:event_btnEkleActionPerformed

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                Arayuz arayuz = new Arayuz();
                arayuz.setLocationRelativeTo(null);
                arayuz.setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnDuraklat;
    private javax.swing.JButton btnDurdur;
    private javax.swing.JButton btnEkle;
    private javax.swing.JButton btnOnceki;
    private javax.swing.JButton btnOynat;
    private javax.swing.JButton btnSonraki;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel lbOynatilan;
    private javax.swing.JList<String> lstMuzik;
    // End of variables declaration//GEN-END:variables
}
