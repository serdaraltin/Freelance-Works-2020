package tr.com.cagatayhanci.fe;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import tr.com.cagatayhanci.dal.SehirDAL;
import tr.com.cagatayhanci.types.SehirContract;

import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class SehirDuzenleFE extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField textField;

	public SehirDuzenleFE() {
		setTitle("Sehir Duzenle");
		setResizable(false);
		setModal(true);
		setBounds(100, 100, 274, 193);
		setLocationRelativeTo(null);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		{
			JComboBox comboBox = new JComboBox(new SehirDAL().GetAll().toArray());
			comboBox.setBounds(87, 25, 149, 25);
			contentPanel.add(comboBox);
		
			JLabel lblSehir = new JLabel("Sehir");
			lblSehir.setHorizontalAlignment(SwingConstants.RIGHT);
			lblSehir.setBounds(10, 25, 67, 24);
			contentPanel.add(lblSehir);
		
			JLabel lblYeniAd = new JLabel("Yeni Ad");
			lblYeniAd.setHorizontalAlignment(SwingConstants.RIGHT);
			lblYeniAd.setBounds(10, 74, 67, 25);
			contentPanel.add(lblYeniAd);
		
			textField = new JTextField();
			textField.setColumns(10);
			textField.setBounds(87, 75, 149, 22);
			contentPanel.add(textField);
		
			JButton button = new JButton("Kaydet");
			button.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					if(textField.getText() !="") {
						
						SehirContract contract = new SehirContract();
						SehirContract sContract = (SehirContract) comboBox.getSelectedItem();
						
						contract.setId(sContract.getId());
						contract.setAdi(textField.getText());
						
						new SehirDAL().Update(contract);
						
						JOptionPane.showMessageDialog(null, "Sehir guncellendi");
						setVisible(false);
					}else {
						JOptionPane.showMessageDialog(null, "Gerekli alani doldurun");
					}
				}
			});
			button.setBounds(87, 108, 89, 26);
			contentPanel.add(button);
		}
	}

}
