package tr.com.cagatayhanci.fe;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import tr.com.cagatayhanci.dal.YetkilerDAL;
import tr.com.cagatayhanci.types.YetkilerContract;

import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class YetkiDuzenleFE extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField textField;

	
	public YetkiDuzenleFE() {
		setTitle("Yetki Duzenle");
		setModal(true);
		setResizable(false);
		setBounds(100, 100, 271, 219);
		setLocationRelativeTo(null);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		
		JComboBox comboBox = new JComboBox(new YetkilerDAL().GetAll().toArray());
		comboBox.setBounds(87, 24, 149, 25);
		contentPanel.add(comboBox);
		
		JLabel lblYetki = new JLabel("Yetki");
		lblYetki.setHorizontalAlignment(SwingConstants.RIGHT);
		lblYetki.setBounds(10, 24, 67, 24);
		contentPanel.add(lblYetki);
		
		textField = new JTextField();
		textField.setColumns(10);
		textField.setBounds(87, 73, 149, 22);
		contentPanel.add(textField);
		
		JLabel lblYeniAd = new JLabel("Yeni Ad");
		lblYeniAd.setHorizontalAlignment(SwingConstants.RIGHT);
		lblYeniAd.setBounds(10, 73, 67, 25);
		contentPanel.add(lblYeniAd);
		
		JButton button = new JButton("Kaydet");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(textField.getText() != "") {
				YetkilerContract contact = new YetkilerContract();
				YetkilerContract yContract = (YetkilerContract) comboBox.getSelectedItem();
				
				contact.setAdi(textField.getText());
				contact.setId(yContract.getId());
				
				new YetkilerDAL().Update(contact);
				
				JOptionPane.showMessageDialog(null, "Yetki guncellendi");
				setVisible(false);
				}else {
					JOptionPane.showMessageDialog(null, "Gerekli alanlari doldurun");
				}
			}
		});
		button.setBounds(87, 106, 89, 26);
		contentPanel.add(button);
		
		JLabel lblIlkYetkiyonetici = new JLabel("Ilk yetki \"Yonetici\" olarak kabul edilir.");
		lblIlkYetkiyonetici.setHorizontalAlignment(SwingConstants.LEFT);
		lblIlkYetkiyonetici.setBounds(40, 143, 196, 38);
		contentPanel.add(lblIlkYetkiyonetici);
	}

}
