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

import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class KategoriDuzenleFE extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField textField;

	/**
	 * Launch the application.
	 */

	/**
	 * Create the dialog.
	 */
	public KategoriDuzenleFE() {
		setTitle("Kategori Duzenle");
		setResizable(false);
		setBounds(100, 100, 290, 197);
		setLocationRelativeTo(null);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		
		JComboBox comboBox = new JComboBox(new KategoriDAL().GetAll().toArray());
		comboBox.setBounds(101, 31, 149, 25);
		contentPanel.add(comboBox);
		
		JLabel lblKategori = new JLabel("Kategori");
		lblKategori.setHorizontalAlignment(SwingConstants.RIGHT);
		lblKategori.setBounds(24, 31, 67, 25);
		contentPanel.add(lblKategori);
		
		JLabel lblYeniAd = new JLabel("Yeni ad");
		lblYeniAd.setHorizontalAlignment(SwingConstants.RIGHT);
		lblYeniAd.setBounds(24, 67, 67, 24);
		contentPanel.add(lblYeniAd);
		
		textField = new JTextField();
		textField.setColumns(10);
		textField.setBounds(101, 67, 149, 22);
		contentPanel.add(textField);
		
		JButton button = new JButton("Kaydet");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(textField.getText() != "") {
					KategoriContract contract = new KategoriContract();
					KategoriContract kContract = (KategoriContract) comboBox.getSelectedItem();
	
					contract.setId(kContract.getId());
					contract.setAdi(textField.getText());
					JOptionPane.showMessageDialog(null, "Kategori guncellendi.");
					setVisible(false);
					
					new KategoriDAL().Update(contract);
					}else {
						JOptionPane.showMessageDialog(null, "Gerekli alanlari doldurun");
					}
					
			}
		});
		button.setBounds(101, 100, 89, 26);
		contentPanel.add(button);
	}

}
