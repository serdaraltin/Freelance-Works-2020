package View;

import Database.Veritabani;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class UIYoneticiGiris extends javax.swing.JFrame {

    Veritabani veritabani = new Veritabani();

    public UIYoneticiGiris() {
        initComponents();
        setSize(350, 250);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void initComponents() {
        setTitle("Giriş");
        txtMail = new javax.swing.JTextField();
        lblMail = new javax.swing.JLabel();
        txtParola = new javax.swing.JTextField();
        lblParola = new javax.swing.JLabel();
        btnGiris = new javax.swing.JButton();
        lblBaslik = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setName("FrmYonetici");
        setResizable(false);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        getContentPane().add(txtMail, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 80, 210, -1));

        lblMail.setText("Mail");
        getContentPane().add(lblMail, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 80, 50, 30));

        getContentPane().add(txtParola, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 120, 210, -1));

        lblParola.setText("Parola");
        getContentPane().add(lblParola, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 120, 50, 30));

        btnGiris.setFont(new java.awt.Font("Dialog", 1, 18));
        btnGiris.setText("Giriş");
        btnGiris.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                try {
                    if (veritabani.YoneticiDogrula(txtMail.getText(), txtParola.getText())) {
                         setVisible(false);
                         new UIMain().setVisible(true);
                    } else {
                        JOptionPane.showMessageDialog(null, "Kullanıcı adı veya parola hatalı!");
                    }
                } catch (SQLException ex) {
                    Logger.getLogger(UIYoneticiGiris.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
        getContentPane().add(btnGiris, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 160, 120, -1));

        lblBaslik.setFont(new java.awt.Font("Dialog", 1, 24));
        lblBaslik.setText("YÖNETİCİ GİRİŞ");
        getContentPane().add(lblBaslik, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 20, -1, -1));

        pack();
        setLocationRelativeTo(null);
    }

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                UIYoneticiGiris aRYoneticiGiris = new UIYoneticiGiris();
                
            }
        });
    }

    private javax.swing.JButton btnGiris;
    private javax.swing.JLabel lblBaslik;
    private javax.swing.JLabel lblMail;
    private javax.swing.JLabel lblParola;
    private javax.swing.JTextField txtMail;
    private javax.swing.JTextField txtParola;

}
