package tr.com.cagatayhanci.fe;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import tr.com.cagatayhanci.dal.MusteriDAL;
import tr.com.cagatayhanci.dal.SehirDAL;
import tr.com.cagatayhanci.types.MusteriContract;
import tr.com.cagatayhanci.types.SehirContract;

import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import javax.swing.JComboBox;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class MusteriDuzenleFE extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;

	
	public MusteriDuzenleFE() {
		setTitle("Musteri Duzenle");
		setModal(true);
		setResizable(false);
		setBounds(100, 100, 295, 273);
		setLocationRelativeTo(null);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		{
			JButton button = new JButton("Kaydet");
			
			button.setBounds(87, 201, 89, 26);
			contentPanel.add(button);
		
			JLabel lblTelefon = new JLabel("Telefon");
			lblTelefon.setHorizontalAlignment(SwingConstants.RIGHT);
			lblTelefon.setBounds(10, 96, 67, 25);
			contentPanel.add(lblTelefon);
		
			JLabel labela = new JLabel("Ad\u0131 Soyadi");
			labela.setHorizontalAlignment(SwingConstants.RIGHT);
			labela.setBounds(10, 60, 67, 25);
			contentPanel.add(labela);
		
			JComboBox comboBox = new JComboBox(new MusteriDAL().GetAll().toArray());
			comboBox.setBounds(87, 11, 149, 25);
			contentPanel.add(comboBox);
		
			JLabel lblMusteri = new JLabel("Musteri");
			lblMusteri.setHorizontalAlignment(SwingConstants.RIGHT);
			lblMusteri.setBounds(10, 11, 67, 24);
			contentPanel.add(lblMusteri);
		
		JLabel lblAdres = new JLabel("Adres");
		lblAdres.setHorizontalAlignment(SwingConstants.RIGHT);
		lblAdres.setBounds(10, 129, 67, 25);
		contentPanel.add(lblAdres);
		
		JComboBox scomboBox = new JComboBox(new SehirDAL().GetAll().toArray());
		scomboBox.setBounds(87, 162, 149, 25);
		contentPanel.add(scomboBox);
		
		JLabel label = new JLabel("Musteri");
		label.setHorizontalAlignment(SwingConstants.RIGHT);
		label.setBounds(10, 162, 67, 24);
		contentPanel.add(label);
		
		textField = new JTextField();
		textField.setBounds(87, 61, 149, 22);
		contentPanel.add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setColumns(10);
		textField_1.setBounds(87, 98, 149, 22);
		contentPanel.add(textField_1);
		
		textField_2 = new JTextField();
		textField_2.setColumns(10);
		textField_2.setBounds(87, 131, 149, 22);
		contentPanel.add(textField_2);
		
		
		
		
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if((textField.getText() != "" && textField_1.getText() != "" ) && textField_2.getText() != "") {
				MusteriContract contract = new MusteriContract();
				MusteriContract mContract = (MusteriContract) comboBox.getSelectedItem();
				SehirContract sContract = (SehirContract) scomboBox.getSelectedItem();
				
				contract.setAdiSoyadi(textField.getText());
				contract.setAdres(textField_2.getText());
				contract.setTelefon(textField_1.getText());
				contract.setId(mContract.getId());
				contract.setSehirId(sContract.getId());
				
				new MusteriDAL().Update(contract);
				JOptionPane.showMessageDialog(null, "Musteri guncellendi");
				setVisible(false);
				}else {
					JOptionPane.showMessageDialog(null, "Gerekli alanlari doldurun");
				}
				
			}
		});
		}
		
		
	}
}
