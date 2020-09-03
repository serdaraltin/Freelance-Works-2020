package tr.com.cagatayhanci.fe;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.border.EmptyBorder;

import tr.com.cagatayhanci.dal.AccountsDAL;
import tr.com.cagatayhanci.dal.PersonelDAL;
import tr.com.cagatayhanci.types.AccountsContract;
import tr.com.cagatayhanci.types.PersonelContract;

import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class SifreDuzenleFE extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField textField;
	private JTextField textField_1;


	
	public SifreDuzenleFE() {
		setTitle("Sifre Duzenle");
		setResizable(false);
		setModal(true);
		setBounds(100, 100, 277, 224);
		setLocationRelativeTo(null);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		{
			JComboBox comboBox = new JComboBox(new PersonelDAL().GetAll().toArray());
			comboBox.setBounds(87, 11, 149, 25);
			contentPanel.add(comboBox);
		
			JLabel lblPersonel = new JLabel("Personel");
			lblPersonel.setHorizontalAlignment(SwingConstants.RIGHT);
			lblPersonel.setBounds(10, 11, 67, 24);
			contentPanel.add(lblPersonel);
		
			JLabel lblSifre = new JLabel("Sifre");
			lblSifre.setHorizontalAlignment(SwingConstants.RIGHT);
			lblSifre.setBounds(10, 60, 67, 25);
			contentPanel.add(lblSifre);
		
			textField = new JPasswordField();
			textField.setColumns(10);
			textField.setBounds(87, 60, 149, 22);
			contentPanel.add(textField);
		
			JButton button = new JButton("Kaydet");
			
			button.setBounds(87, 134, 89, 26);
			contentPanel.add(button);
		
			textField_1 = new JPasswordField();
			textField_1.setColumns(10);
			textField_1.setBounds(87, 96, 149, 22);
			contentPanel.add(textField_1);
		
			JLabel lblSifreTekrar = new JLabel("Sifre Tekrar");
			lblSifreTekrar.setHorizontalAlignment(SwingConstants.RIGHT);
			lblSifreTekrar.setBounds(10, 96, 67, 25);
			contentPanel.add(lblSifreTekrar);
			
			button.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					if((textField.getText() != "" && textField_1.getText() != "") && textField.getText().equals(textField_1.getText())) {
						
						AccountsContract contract = new AccountsContract();
						PersonelContract pContract = (PersonelContract) comboBox.getSelectedItem();
						
						contract.setSifre(textField.getText());
						contract.setPersonelId(pContract.getId());
						
						new AccountsDAL().Update(contract);
						JOptionPane.showMessageDialog(null, "Sifre guncellendi");
						setVisible(false);
						
						
					}else {
						JOptionPane.showMessageDialog(null, "Sifreler uyusmuyor veya bos");
					}
					
					
				}
			});
		}
	}

}
