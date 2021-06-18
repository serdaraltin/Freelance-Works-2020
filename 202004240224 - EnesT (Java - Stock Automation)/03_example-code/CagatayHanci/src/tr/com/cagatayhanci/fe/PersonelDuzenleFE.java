package tr.com.cagatayhanci.fe;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import tr.com.cagatayhanci.dal.PersonelDAL;
import tr.com.cagatayhanci.types.PersonelContract;
import tr.com.cagatayhanci.types.YetkilerContract;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class PersonelDuzenleFE extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField textField;
	private JTextField textField_1;

	public PersonelDuzenleFE() {
		setModal(true);
		setResizable(false);
		setTitle("Personel Duzenle");
		setBounds(100, 100, 298, 205);
		setLocationRelativeTo(null);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		{
			JButton button = new JButton("Kaydet");

			button.setBounds(87, 128, 89, 26);
			contentPanel.add(button);

			textField = new JTextField();
			textField.setColumns(10);
			textField.setBounds(87, 95, 149, 22);
			contentPanel.add(textField);
			textField_1 = new JTextField();
			textField_1.setColumns(10);
			textField_1.setBounds(87, 60, 149, 22);
			contentPanel.add(textField_1);

			JLabel label = new JLabel("Yeni Ad");
			label.setHorizontalAlignment(SwingConstants.RIGHT);
			label.setBounds(10, 60, 67, 24);
			contentPanel.add(label);

			JLabel lblYetki = new JLabel("Email");
			lblYetki.setHorizontalAlignment(SwingConstants.RIGHT);
			lblYetki.setBounds(10, 95, 67, 25);
			contentPanel.add(lblYetki);

			JComboBox comboBox = new JComboBox(new PersonelDAL().GetAll().toArray());
			comboBox.setBounds(87, 11, 149, 25);
			contentPanel.add(comboBox);

			JLabel lblPersonel = new JLabel("Personel");
			lblPersonel.setHorizontalAlignment(SwingConstants.RIGHT);
			lblPersonel.setBounds(10, 11, 67, 24);
			contentPanel.add(lblPersonel);

			button.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					if(textField.getText() != "" && textField_1.getText() != "") {
					PersonelContract contract = new PersonelContract();
					PersonelContract pContract = (PersonelContract) comboBox.getSelectedItem();
					
					contract.setAdiSoyadi(textField_1.getText());
					contract.setEmail(textField.getText());
					contract.setId(pContract.getId());
					
					new PersonelDAL().Update(contract);
					
					JOptionPane.showMessageDialog(null, "Personel guncellendi");
					setVisible(false);
					}else {
						JOptionPane.showMessageDialog(null, "Gerekli alanlari doldurun");
					}
				}
			});
		}
	}

}
