package tr.com.cagatayhanci.fe;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import tr.com.cagatayhanci.dal.KategoriDAL;
import tr.com.cagatayhanci.dal.UrunlerDAL;
import tr.com.cagatayhanci.types.KategoriContract;
import tr.com.cagatayhanci.types.UrunlerContract;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import javax.swing.JComboBox;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class UrunDuzenleFE extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField textField;
	private JTextField textField_1;

	/**
	 * Launch the application.
	 */

	/**
	 * Create the dialog.
	 */

	
	public UrunDuzenleFE() {
		setModal(true);
		setResizable(false);
		setTitle("Urun Duzenle");
		setBounds(100, 100, 300, 254);
		setLocationRelativeTo(null);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		
		JLabel lblUrun = new JLabel("Urun Sec");
		lblUrun.setHorizontalAlignment(SwingConstants.RIGHT);
		lblUrun.setBounds(10, 12, 67, 24);
		contentPanel.add(lblUrun);
		
		JComboBox comboBox = new JComboBox(new UrunlerDAL().GetAll().toArray());
		comboBox.setBounds(87, 12, 149, 25);
		contentPanel.add(comboBox);
		
		JComboBox comboBox_1 = new JComboBox(new KategoriDAL().GetAll().toArray());
		comboBox_1.setBounds(87, 96, 149, 25);
		contentPanel.add(comboBox_1);
		
		JLabel lblKategori = new JLabel("Yeni Kategori");
		lblKategori.setHorizontalAlignment(SwingConstants.RIGHT);
		lblKategori.setBounds(10, 96, 67, 25);
		contentPanel.add(lblKategori);
		
		JLabel lblFiyat = new JLabel("Yeni Fiyat");
		lblFiyat.setHorizontalAlignment(SwingConstants.RIGHT);
		lblFiyat.setBounds(10, 132, 67, 24);
		contentPanel.add(lblFiyat);
		
		textField = new JTextField();
		textField.setBounds(87, 132, 149, 22);
		contentPanel.add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setColumns(10);
		textField_1.setBounds(87, 61, 149, 22);
		contentPanel.add(textField_1);
		
		JLabel lblAd = new JLabel("Yeni Ad");
		lblAd.setHorizontalAlignment(SwingConstants.RIGHT);
		lblAd.setBounds(10, 61, 67, 24);
		contentPanel.add(lblAd);
		
		JButton btnNewButton = new JButton("Kaydet");
		
		btnNewButton.setBounds(87, 165, 89, 26);
		contentPanel.add(btnNewButton);
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if(textField.getText() != "" && textField_1.getText() != "") {
				UrunlerContract contract = new UrunlerContract();
				UrunlerContract uContract = (UrunlerContract) comboBox.getSelectedItem();
				KategoriContract cContract = (KategoriContract) comboBox_1.getSelectedItem();
				
				contract.setAdi(textField_1.getText());
				contract.setFiyat(Float.parseFloat(textField.getText()));
				contract.setKategoriId(cContract.getId());
				contract.setId(uContract.getId());
				JOptionPane.showMessageDialog(null, "Urun guncellendi.");
				setVisible(false);
				//JOptionPane.showMessageDialog(null, cContract.getId());
				new UrunlerDAL().Update(contract);
				}else {
					JOptionPane.showMessageDialog(null, "Gerekli alanlari doldurun");
				}
				
			}
		});
	}
}
