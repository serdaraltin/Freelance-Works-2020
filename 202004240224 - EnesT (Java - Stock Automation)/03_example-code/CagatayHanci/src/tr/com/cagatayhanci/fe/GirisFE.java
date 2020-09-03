package tr.com.cagatayhanci.fe;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import tr.com.cagatayhanci.dal.AccountsDAL;
import tr.com.cagatayhanci.dal.PersonelDAL;
import tr.com.cagatayhanci.dal.YetkilerDAL;
import tr.com.cagatayhanci.types.AccountsContract;
import tr.com.cagatayhanci.types.PersonelContract;
import tr.com.cagatayhanci.types.YetkilerContract;

import java.awt.Window.Type;
import java.awt.Dialog.ModalExclusionType;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import java.awt.Frame;

import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;
import javax.swing.JPasswordField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;



public class GirisFE extends JFrame {

	private JPanel contentPane;
	private JPasswordField passwordField;


	public static void main(String[] args) {
		try {
    for (LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
        if ("Windows".equals(info.getName())) {
            UIManager.setLookAndFeel(info.getClassName());
            break;
        }
    }
} catch (Exception e) {
    // If Nimbus is not available, you can set the GUI to another look and feel.
}
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GirisFE frame = new GirisFE();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public GirisFE() {
		setResizable(false);
		setFont(new Font("Dialog", Font.PLAIN, 14));
		setTitle("Giris Yap");
		
		setType(Type.UTILITY);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 350, 193);
		setLocationRelativeTo(null);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblKullaniciAdi = new JLabel("Kullanici Adi");
		lblKullaniciAdi.setHorizontalAlignment(SwingConstants.RIGHT);
		lblKullaniciAdi.setBounds(24, 22, 87, 29);
		contentPane.add(lblKullaniciAdi);
		
		JComboBox comboBox = new JComboBox(new PersonelDAL().GetAll().toArray());
		comboBox.setFont(new Font("Tahoma", Font.PLAIN, 12));
		comboBox.setBounds(121, 22, 147, 29);
		contentPane.add(comboBox);
		
		JLabel lblSifre = new JLabel("Sifre");
		lblSifre.setHorizontalAlignment(SwingConstants.RIGHT);
		lblSifre.setBounds(24, 62, 87, 29);
		contentPane.add(lblSifre);
		
		passwordField = new JPasswordField();
		passwordField.setBounds(121, 62, 147, 29);
		contentPane.add(passwordField);
		
		JButton btnGirisYap = new JButton("Giris Yap");
		btnGirisYap.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if(passwordField.getText() != "") {
					
					
					PersonelContract pContract = (PersonelContract) comboBox.getSelectedItem();
				
					if(new AccountsDAL().GetPersonelIdVeSifre(pContract.getId(), passwordField.getText()).getId() != 0) {
						EventQueue.invokeLater(new Runnable() {
							public void run() {
								try {
									AnaPencereFE aframe = new AnaPencereFE();
									aframe.setYetki(new YetkilerDAL().GetPersonelYetki(new AccountsDAL().GetPersonelIdVeSifre(pContract.getId(), passwordField.getText()).getYetkiId() ).getAdi());
        							aframe.setPersonelId(pContract.getId());
									aframe.setVisible(true);
														
								} catch (Exception e) {
									e.printStackTrace();
								}
							}
						});
						setVisible(false);
						
					}else {
						JOptionPane.showMessageDialog(null, "Hatali sifre, tekrar deneyin");
					}
				}else {
					JOptionPane.showMessageDialog(null, "Lutfen sifre giriniz");
				}
			}
		});
		btnGirisYap.setBounds(121, 100, 89, 29);
		contentPane.add(btnGirisYap);
	}
}
