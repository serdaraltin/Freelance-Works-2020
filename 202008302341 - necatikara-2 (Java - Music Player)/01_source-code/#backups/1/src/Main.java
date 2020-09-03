
import java.io.File;
import java.util.ArrayList;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.DefaultListModel;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;

public class Main extends javax.swing.JFrame {

    ArrayList<String[]> muzikler = new ArrayList<String[]>();
    static String selectedMusic = "";
    static int selectedIndex = 0, tmpselectedIndex = 0;
    Long currentFrame;
    Clip clip;
    String status = "";
    AudioInputStream audioInputStream;
    static String filePath = "";
    static String lastFilePath = "";

    public Main() {
        initComponents();
        setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        btnDurdur = new javax.swing.JButton();
        btnDuraklat = new javax.swing.JButton();
        btnBaslat = new javax.swing.JButton();
        btnOnceki = new javax.swing.JButton();
        btnSonraki = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        lstMuzik = new javax.swing.JList<>();
        lbDurum = new javax.swing.JLabel();
        btnEkle = new javax.swing.JButton();
        lbMuzik = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Müzik Çalar");
        setResizable(false);

        btnDurdur.setText("Durdur");
        btnDurdur.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDurdurActionPerformed(evt);
            }
        });

        btnDuraklat.setText("Duraklat");
        btnDuraklat.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDuraklatActionPerformed(evt);
            }
        });

        btnBaslat.setText("Başlat");
        btnBaslat.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnBaslatActionPerformed(evt);
            }
        });

        btnOnceki.setText("Önceki");
        btnOnceki.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnOncekiActionPerformed(evt);
            }
        });

        btnSonraki.setText("Sonraki");
        btnSonraki.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSonrakiActionPerformed(evt);
            }
        });

        lstMuzik.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        lstMuzik.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        lstMuzik.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                lstMuzikValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(lstMuzik);

        lbDurum.setText("Durum: ");

        btnEkle.setText("Ekle");
        btnEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEkleActionPerformed(evt);
            }
        });

        lbMuzik.setText("...");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(17, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btnBaslat)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnDuraklat)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnDurdur)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btnOnceki)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnSonraki))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(lbMuzik)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btnEkle))
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 432, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(lbDurum))
                .addGap(15, 15, 15))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(16, 16, 16)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnEkle)
                    .addComponent(lbMuzik))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 248, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnDurdur)
                    .addComponent(btnBaslat)
                    .addComponent(btnDuraklat)
                    .addComponent(btnOnceki)
                    .addComponent(btnSonraki))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(lbDurum)
                .addContainerGap(10, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnBaslatActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnBaslatActionPerformed

        if (muzikler.isEmpty()) {
            return;
        }
        Sec(tmpselectedIndex);
        play();

        if (btnDuraklat.getText().equals("Devam Ettir")) {
            btnDuraklat.setText("Duraklat");
        }
        lbDurum.setText("Durum: " + status);
    }//GEN-LAST:event_btnBaslatActionPerformed

    private void btnDuraklatActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDuraklatActionPerformed
        if (status.equals("play") || status.equals("paused") || status.equals("resume")) {
            if (btnDuraklat.getText().equals("Duraklat")) {
                btnDuraklat.setText("Devam Ettir");
                pause();
                return;
            }
            btnDuraklat.setText("Duraklat");
            resumeAudio();
        }
        lbDurum.setText("Durum: " + status);
    }//GEN-LAST:event_btnDuraklatActionPerformed

    private void btnDurdurActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDurdurActionPerformed
        if (!filePath.equals("")) {
            stop();
        }
        lbMuzik.setText("");
        lbDurum.setText("Durum: " + status);
    }//GEN-LAST:event_btnDurdurActionPerformed

    private void btnOncekiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnOncekiActionPerformed
        if (muzikler.isEmpty()) {
            return;
        }
        if (selectedIndex - 1 < 0) {
            selectedIndex = muzikler.size();
        }
        Sec(--selectedIndex);
        play();
        lbDurum.setText("Durum: " + status);
    }//GEN-LAST:event_btnOncekiActionPerformed

    private void btnSonrakiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSonrakiActionPerformed
        if (muzikler.isEmpty()) {
            return;
        }
        if (selectedIndex + 2 > muzikler.size()) {
            selectedIndex = -1;
        }
        Sec(++selectedIndex);
        play();
        lbDurum.setText("Durum: " + status);
    }//GEN-LAST:event_btnSonrakiActionPerformed

    private void btnEkleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnEkleActionPerformed
        JFileChooser chooser = new JFileChooser();
        chooser.setMultiSelectionEnabled(false);
        chooser.setCurrentDirectory(new File("."));
        FileNameExtensionFilter filter = new FileNameExtensionFilter("Ses Dosyaları", "aiff");
        chooser.setFileFilter(filter);
        int returnVal = chooser.showOpenDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            String path = chooser.getSelectedFile().getPath();
            String name = chooser.getSelectedFile().getName();

            if (!name.contains(".aiff")) {
                JOptionPane.showMessageDialog(this, "Seçilen dosya desteklenmemektedir, aiff formatında seçim yapınız.");
                return;
            }
            for (String[] strings : muzikler) {
                if (strings[0].equals(name)) {
                    JOptionPane.showMessageDialog(this, "Aynı müzik zaten var");
                    return;
                }
            }
            muzikler.add(new String[]{name, path});
        }
        Listele();
    }//GEN-LAST:event_btnEkleActionPerformed

    private void lstMuzikValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_lstMuzikValueChanged
        tmpselectedIndex = lstMuzik.getSelectedIndex();
    }//GEN-LAST:event_lstMuzikValueChanged

    public static void main(String args[]) {

        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Main().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnBaslat;
    private javax.swing.JButton btnDuraklat;
    private javax.swing.JButton btnDurdur;
    private javax.swing.JButton btnEkle;
    private javax.swing.JButton btnOnceki;
    private javax.swing.JButton btnSonraki;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel lbDurum;
    private javax.swing.JLabel lbMuzik;
    private javax.swing.JList<String> lstMuzik;
    // End of variables declaration//GEN-END:variables

    public void Listele() {
        if (muzikler.size() == 0) {
            return;
        }
        DefaultListModel model = new DefaultListModel();
        model.clear();

        for (String[] strings : muzikler) {
            model.addElement(strings[0]);
        }
        lstMuzik.setModel(model);
    }

    public void Sec(int indexNo) {
        selectedIndex = indexNo;
        filePath = muzikler.get(selectedIndex)[1];
        selectedMusic = muzikler.get(selectedIndex)[0];
        lstMuzik.setSelectedIndex(selectedIndex);
        lbMuzik.setText("Çalan: " + selectedMusic);
    }

    public void ready() {
        try {
            audioInputStream = AudioSystem.getAudioInputStream(new File(filePath).getAbsoluteFile());
            clip = AudioSystem.getClip();
            clip.open(audioInputStream);
            clip.loop(Clip.LOOP_CONTINUOUSLY);
        } catch (Exception ex) {
        }
    }

    public void play() {
        if (status.equals("durduruldu")) {
            restart();
            return;
        }
        if (status.equals("oynatılıyor") || status.equals("duraklatıldı") || status.equals("devam ettiriliyor")) {
            restart();
            return;
        }
        if (!lastFilePath.equals(filePath)) {
            lastFilePath = filePath;
            ready();
        }
        clip.start();
        status = "oynatılıyor";
    }

    public void pause() {
        if (status.equals("oynatılıyor") || status.equals("devam ettiriliyor")) {
            this.currentFrame = this.clip.getMicrosecondPosition();
            clip.stop();
            status = "duraklatıldı";
        }
    }

    public void resumeAudio() {
        if (status.equals("duraklatıldı")) {
            clip.close();
            resetAudioStream();
            clip.setMicrosecondPosition(currentFrame);
            clip.start();
            status = "devam ettiriliyor";
        }
    }

    public void restart() {
        if (!status.equals("durduruldu")) {
            clip.stop();
            clip.close();
        }
        resetAudioStream();
        currentFrame = 0L;
        clip.setMicrosecondPosition(0);
        status = "oynatılıyor";
        clip.start();
    }

    public void stop() {
        if (status.equals("durduruldu")) {
            return;
        }
        currentFrame = 0L;
        clip.stop();
        clip.close();
        status = "durduruldu";
    }

    public void resetAudioStream() {
        try {
            audioInputStream = AudioSystem.getAudioInputStream(new File(filePath).getAbsoluteFile());
            clip.open(audioInputStream);
            clip.loop(Clip.LOOP_CONTINUOUSLY);
        } catch (Exception ex) {
        }
    }
}
