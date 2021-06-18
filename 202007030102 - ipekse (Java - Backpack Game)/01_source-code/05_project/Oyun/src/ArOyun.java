
import java.text.DecimalFormat;
import java.util.ArrayList;
import javax.swing.JOptionPane;

public class ArOyun extends javax.swing.JFrame {

    Islemler islemler = new Islemler();
    float toplamKg, enCokKg;

    //bu classın yaratıcı methodu parametre olarak çanta kapasitesini alır
    public ArOyun(int kapasite) {
        initComponents();
        setLocationRelativeTo(null);
        enCokKg = kapasite;
        toplamKg = 0;

        switch (kapasite) {
            case 9:
                setTitle("Hoşgeldin HACI");
                break;
            case 7:
                setTitle("Hoşgeldin GEZGİN");
                break;
            case 5:
                setTitle("Hoşgeldin İZCİ");
                break;
            case 3:
                setTitle("Hoşgeldin SAVAŞÇI");
                break;
        }

        txtKapasite.setText(String.valueOf(enCokKg));
        txtBosAlan.setText(String.valueOf(enCokKg));

        islemler.Isle();
        Listele();
    }

    //o anki eşların listesini ilgili kutucuğa yazar
    public void Listele() {
        liste.setText("");
        liste.append("Eşya Adı\tKategori\tAğırlık\n");
        for (String[] deger : islemler.elbise) {
            liste.append(deger[0] + "\t" + deger[1] + "\t" + deger[2] + "\n");
        }

        for (String[] deger : islemler.yiyecekIcecek) {
            liste.append(deger[0] + "\t" + deger[1] + "\t" + deger[2] + "\n");

        }

        for (String[] deger : islemler.saglik) {
            liste.append(deger[0] + "\t" + deger[1] + "\t" + deger[2] + "\n");

        }

        for (String[] deger : islemler.arac) {
            liste.append(deger[0] + "\t" + deger[1] + "\t" + deger[2] + "\n");

        }
        liste.append("Eşya Adı\tKategori\tAğırlık\n");
    }

    //o anki çantadaki elemanları ilgili kutucuğa yazar
    public void CantaListele() {
        txtCanta.setText("");
        txtCanta.append("Eşya Adı\tKategori\tAğırlık\n");
        for (String[] deger : islemler.sirtCantasi) {
            txtCanta.append(deger[0] + "\t" + deger[1] + "\t" + deger[2] + "\n");
        }
    }

    public void Bitti() {
        islemler.sirtCantasiElemanlar = islemler.sirtCantasi.size();

        for (String[] strings : islemler.sirtCantasi) {
            islemler.gun_sayisi += Integer.parseInt(strings[3]);
        }
        JOptionPane.showMessageDialog(null,
                "Çanta Eşya : " + islemler.sirtCantasiElemanlar + " adet\n"
                + "Çanta Kapasite : " + enCokKg + " Kg\n"
                + "Çanta Ağırlık : " + String.format(new DecimalFormat("##.##").format((toplamKg))) + " Kg\n"
                + "Başarı : " + islemler.gun_sayisi + " gün hayatta kalabildiniz."
        );
        new ArZorlukSecim().setVisible(true);
        this.dispose();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        txtCanta = new javax.swing.JTextArea();
        cbKategori = new javax.swing.JComboBox<>();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        txtEsyaAdi = new javax.swing.JTextField();
        btnCantayaEkle = new javax.swing.JButton();
        lbCantaDurumu = new javax.swing.JLabel();
        txtKapasite = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        txtBosAlan = new javax.swing.JTextField();
        jLabel6 = new javax.swing.JLabel();
        jScrollPane2 = new javax.swing.JScrollPane();
        liste = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Hayatta Kalma Oyunu");
        setResizable(false);

        txtCanta.setColumns(20);
        txtCanta.setRows(5);
        txtCanta.setEnabled(false);
        jScrollPane1.setViewportView(txtCanta);

        cbKategori.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Elbise", "Yiyecek İçeçek", "Sağlık", "Araç Gereç" }));

        jLabel1.setText("Kategori");

        jLabel2.setText("Eşya Adı");

        btnCantayaEkle.setText("Çantaya Ekle");
        btnCantayaEkle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCantayaEkleActionPerformed(evt);
            }
        });

        lbCantaDurumu.setText("Çanta Durumu : ");

        txtKapasite.setEnabled(false);

        jLabel3.setText("Kapasite");

        jLabel4.setText("KG");

        jLabel5.setText("KG");

        txtBosAlan.setEnabled(false);

        jLabel6.setText("Boş Alan");

        liste.setColumns(20);
        liste.setRows(5);
        liste.setEnabled(false);
        jScrollPane2.setViewportView(liste);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(lbCantaDurumu)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(18, 18, 18)
                        .addComponent(cbKategori, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtEsyaAdi))
                    .addComponent(btnCantayaEkle, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.Alignment.TRAILING))
                .addContainerGap())
            .addGroup(layout.createSequentialGroup()
                .addGap(49, 49, 49)
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(txtKapasite, javax.swing.GroupLayout.PREFERRED_SIZE, 45, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel4)
                .addGap(30, 30, 30)
                .addComponent(jLabel6)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(txtBosAlan, javax.swing.GroupLayout.PREFERRED_SIZE, 45, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel5)
                .addContainerGap(50, Short.MAX_VALUE))
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(jScrollPane2)
                    .addContainerGap()))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(355, 355, 355)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(cbKategori, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel2)
                    .addComponent(txtEsyaAdi, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(btnCantayaEkle, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(lbCantaDurumu)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txtKapasite, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4)
                    .addComponent(txtBosAlan, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel6)
                    .addComponent(jLabel5))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 186, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(16, 16, 16)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 331, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addContainerGap(359, Short.MAX_VALUE)))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    //çantaya eleman ekleme butonu işlevi
    private void btnCantayaEkleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCantayaEkleActionPerformed

        if (islemler.elbise.size() == 0 && islemler.yiyecekIcecek.size() == 0 && islemler.saglik.size() == 0 && islemler.arac.size() == 0) {
            Bitti();
        }
        ArrayList<String[]> esyalar = new ArrayList<String[]>();
        switch (cbKategori.getSelectedIndex()) {
            case 0:
                esyalar = islemler.elbise;
                break;
            case 1:
                esyalar = islemler.yiyecekIcecek;
                break;
            case 2:
                esyalar = islemler.saglik;
                break;
            case 3:
                esyalar = islemler.arac;
                break;
        }
        String esyaAdi = txtEsyaAdi.getText();
        String[] esya;
        if (islemler.EsyaBul(esyalar, esyaAdi) != null) {
            //eşyabul fonksiyonu çağrılıp eşya listesi ve eşya adı verilerek listeden eşyanın silinmesi
            esya = islemler.EsyaBul(esyalar, esyaAdi);
            float kalanKg = enCokKg -toplamKg;
            float esyaKg = Float.parseFloat(esya[2]);
            System.out.println(kalanKg+" - "+esyaKg);
            if (esyaKg > kalanKg) {
                
                JOptionPane.showMessageDialog(null, "Uyarı : Seçilen öğe sırt çantasına sığmıyor!!!");
                return;
            }

            //sırt çantasına ilgili eşyanın eklenmesi
            toplamKg += Float.parseFloat(esya[2]);
            islemler.sirtCantasi.push(esya);
            esyalar.remove(esya);
            txtKapasite.setText(String.valueOf(enCokKg));
            txtBosAlan.setText(String.format(new DecimalFormat("##.##").format((enCokKg - toplamKg))));
            txtEsyaAdi.setText("");

            Listele();
            CantaListele();
            if ((enCokKg - toplamKg) < 0.1) {
                Bitti();
            }

        } else {
            JOptionPane.showMessageDialog(null, "Uyarı : Eşya Bulunamadı!!!");
        }

    }//GEN-LAST:event_btnCantayaEkleActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnCantayaEkle;
    private javax.swing.JComboBox<String> cbKategori;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JLabel lbCantaDurumu;
    private javax.swing.JTextArea liste;
    private javax.swing.JTextField txtBosAlan;
    private javax.swing.JTextArea txtCanta;
    private javax.swing.JTextField txtEsyaAdi;
    private javax.swing.JTextField txtKapasite;
    // End of variables declaration//GEN-END:variables
}
