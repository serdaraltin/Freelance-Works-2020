//İlgili kütüphanelerin dahil edilmesi
import java.io.File;
import java.util.ArrayList;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.DefaultListModel;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;

//ana sınıf, jframden katıltım yapmıştır
public class Main extends javax.swing.JFrame {
    
    //program içerisinde kontroller için kullanılan değişkenler
    ArrayList<String[]> muzikler = new ArrayList<String[]>();
    static String selectedMusic = "";
    static int selectedIndex = 0, tmpselectedIndex = 0;
    Long currentFrame;
    Clip clip;
    String status = "";
    AudioInputStream audioInputStream;
    static String filePath = "";
    static String lastFilePath = "";
    
    //yaratıcı method
    public Main() {
        arayuzHazirla();
        setLocationRelativeTo(null);
    }
    
    //arayüzdeki nesnelerin tanımı ve tasarımı
    private void arayuzHazirla() {
        //arayüz nesnelerinin tanımlanması
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
        
        //buton metni belirleme
        btnDurdur.setText("Durdur");
        //Durdur butonu tıklama referans belirleme
        btnDurdur.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDurdurActionPerformed(evt);
            }
        });
        
        //buton metni belirleme
        btnDuraklat.setText("Duraklat");
         //buton tıklama referans belirleme
        btnDuraklat.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDuraklatActionPerformed(evt);
            }
        });
        
        //buton metni belirleme
        btnBaslat.setText("Başlat");
        //buton tıklama referans belirleme
        btnBaslat.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnBaslatActionPerformed(evt);
            }
        });
        
        //buton metni belirleme
        btnOnceki.setText("Önceki");
        //buton tıklama referans belirleme
        btnOnceki.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnOncekiActionPerformed(evt);
            }
        });
        
        //buton metni belirleme
        btnSonraki.setText("Sonraki");
        //buton tıklama referans belirleme
        btnSonraki.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSonrakiActionPerformed(evt);
            }
        });

        //liste nesnesi tanımlaması
        lstMuzik.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        lstMuzik.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        //liste nesnesinin seçim yapma işlemi referans belirleme
        lstMuzik.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                lstMuzikValueChanged(evt);
            }
        });
        //liste nesnesi kaydırma çubuğu belirleme
        jScrollPane1.setViewportView(lstMuzik);
        
        //label metni belirleme
        lbDurum.setText("Durum: ");
        
        //buton metni belirleme
        btnEkle.setText("Ekle");
         //buton tıklama referans belirleme
        btnEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEkleActionPerformed(evt);
            }
        });
        //label metni belirleme
        lbMuzik.setText("...");

        //arayüzdeki nesnelerin konumlandırılması
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
        //tüm nesnelerin arayüze eklenmesi
        pack();
    }
    
    //başlat butonu tıklama olayı
    private void btnBaslatActionPerformed(java.awt.event.ActionEvent evt) {
        //listenin boş olma durumu kontrolü
        if (muzikler.isEmpty()) {
            return;
        }
        Sec(tmpselectedIndex);
        Cal();
        
        if (btnDuraklat.getText().equals("Devam Ettir")) {
            btnDuraklat.setText("Duraklat");
        }
        lbDurum.setText("Durum: " + status);
    }
    //duraklat butonu tıklama olayı
    private void btnDuraklatActionPerformed(java.awt.event.ActionEvent evt) {
        if (status.equals("oynatılıyor") || status.equals("duraklatıldı") || status.equals("devam ettiriliyor")) {
            if (btnDuraklat.getText().equals("Duraklat")) {
                btnDuraklat.setText("Devam Ettir");
                Duraklat();
                lbDurum.setText("Durum: " + "duraklatıldı");
                return;
            }
            btnDuraklat.setText("Duraklat");
            DevamEttir();
        }
        lbDurum.setText("Durum: " + status);
    }
    //Durdur butonu tıklama olayı
    private void btnDurdurActionPerformed(java.awt.event.ActionEvent evt) {
        //dosya yolunun boş olması kontrolü
        if (!filePath.equals("")) {
            Durdur();
        }
        lbMuzik.setText("...");
        lbDurum.setText("Durum: " + status);
    }
    //önceki butonu tıklama olayı
    private void btnOncekiActionPerformed(java.awt.event.ActionEvent evt) {
        //listenin boş olma durumu
        if (muzikler.isEmpty()) {
            return;
        }
        //o anki index değerinden bir öncekinin liste dışında olması durumu ve listenin son elemanının seçilmesi
        if (selectedIndex - 1 < 0) {
            selectedIndex = muzikler.size();
        }
        Sec(--selectedIndex);
        Cal();
        lbDurum.setText("Durum: " + status);
    }
    //sonraki butonu tıklama olayı
    private void btnSonrakiActionPerformed(java.awt.event.ActionEvent evt) {
        //listenin boş olma durumu
        if (muzikler.isEmpty()) {
            return;
        }
        //o anki index değerinden bir öncekinin liste dışında olması durumu ve listenin ilk elemanının seçilmesi
        if (selectedIndex + 2 > muzikler.size()) {
            selectedIndex = -1;
        }
        Sec(++selectedIndex);
        Cal();
        lbDurum.setText("Durum: " + status);
    }
    //ekle butonu tıklama olayı
    private void btnEkleActionPerformed(java.awt.event.ActionEvent evt) {
        //Dosya seçme nesnesi oluşturulması
        JFileChooser chooser = new JFileChooser();
        //çoklu seçimin kapatılması
        chooser.setMultiSelectionEnabled(false);
        //varsayılan dizinin programın çalıştığı dizin olarak belirlenmesi
        chooser.setCurrentDirectory(new File("."));
        //dosya filtreleme işlemi
        FileNameExtensionFilter filter = new FileNameExtensionFilter("Ses Dosyaları", "aiff");
        //filtre işleme
        chooser.setFileFilter(filter);
        //dosya seçme işleminden geriye dönen değer
        int returnVal = chooser.showOpenDialog(this);
        //dosya seçilmiş ise
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            //dosya yolunun atanması
            String path = chooser.getSelectedFile().getPath();
            //dosya adının atanması
            String name = chooser.getSelectedFile().getName();
            //aiff dışında bir dosyanın seçilmesi
            if (!name.contains(".aiff")) {
                JOptionPane.showMessageDialog(this, "Seçilen dosya desteklenmemektedir, aiff formatında seçim yapınız.");
                return;
            }
            //aynı müziğin olma durumu kontrolü
            for (String[] strings : muzikler) {
                if (strings[0].equals(name)) {
                    JOptionPane.showMessageDialog(this, "Aynı müzik zaten var");
                    return;
                }
            }
            //muziğin listeye eklenmesi
            muzikler.add(new String[]{name, path});
        }
        Listele();
    }
    //listedeki seçilen elemanın değişmesi olayı
    private void lstMuzikValueChanged(javax.swing.event.ListSelectionEvent evt) {
        tmpselectedIndex = lstMuzik.getSelectedIndex();
    }
    
    //main methodu
    public static void main(String args[]) {
        //nimnus temasının seçilmesi
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception ex) {
        }
        //arayüzün gösterilmesi
        Main main = new Main();
        main.setVisible(true);
    }
    //arayüz nesnelerinin tanımlanması
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
    
    //muziklerin liste nesnesine eklenmesi
    public void Listele() {
        if (muzikler.isEmpty()) {
            return;
        }
        DefaultListModel model = new DefaultListModel();
        model.clear();

        for (String[] strings : muzikler) {
            model.addElement(strings[0]);
        }
        lstMuzik.setModel(model);
    }
    //parametre olarak gelen index numarasındaki müziğin seçilmesi
    public void Sec(int indexNo) {
        selectedIndex = indexNo;
        filePath = muzikler.get(selectedIndex)[1];
        selectedMusic = muzikler.get(selectedIndex)[0];
        lstMuzik.setSelectedIndex(selectedIndex);
        lbMuzik.setText("Çalan: " + selectedMusic);
    }
    //müziğin çalınmaya hazır hale getirilmesi
    public void Hazirla() {
        try {
            audioInputStream = AudioSystem.getAudioInputStream(new File(filePath).getAbsoluteFile());
            clip = AudioSystem.getClip();
            clip.open(audioInputStream);
            clip.loop(Clip.LOOP_CONTINUOUSLY);
        } catch (Exception ex) {
        }
    }
    //müziğin çalınması
    public void Cal() {
        if (status.equals("Durduruldu")) {
            restart();
            return;
        }
        if (status.equals("oynatılıyor") || status.equals("duraklatıldı") || status.equals("devam ettiriliyor")) {
            restart();
            return;
        }
        if (!lastFilePath.equals(filePath)) {
            lastFilePath = filePath;
            Hazirla();
        }
        clip.start();
        status = "oynatılıyor";
    }
    //müziğin duraklatılması
    public void Duraklat() {
        if (status.equals("oynatılıyor") || status.equals("devam ettiriliyor")) {
            this.currentFrame = this.clip.getMicrosecondPosition();
            clip.stop();
            status = "duraklatıldı";
        }
    }
    //müziğin kaldığı yerden devam ettirilmesi
    public void DevamEttir() {
        if (status.equals("duraklatıldı")) {
            clip.close();
            Sifirla();
            clip.setMicrosecondPosition(currentFrame);
            clip.start();
            status = "devam ettiriliyor";
        }
    }
    //müziğin yeniden çalınması
    public void restart() {
        if (!status.equals("Durduruldu")) {
            clip.stop();
            clip.close();
        }
        Sifirla();
        currentFrame = 0L;
        clip.setMicrosecondPosition(0);
        status = "oynatılıyor";
        clip.start();
    }
    //müziğin Durdurulması
    public void Durdur() {
        if (status.equals("Durduruldu")) {
            return;
        }
        currentFrame = 0L;
        clip.stop();
        clip.close();
        status = "Durduruldu";
    }
    //müziğin sıfırlanması
    public void Sifirla() {
        try {
            audioInputStream = AudioSystem.getAudioInputStream(new File(filePath).getAbsoluteFile());
            clip.open(audioInputStream);
            clip.loop(Clip.LOOP_CONTINUOUSLY);
        } catch (Exception ex) {
        }
    }
}
