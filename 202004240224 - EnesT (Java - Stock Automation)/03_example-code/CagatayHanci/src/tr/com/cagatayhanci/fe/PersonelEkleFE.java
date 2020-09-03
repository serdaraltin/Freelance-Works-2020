package tr.com.cagatayhanci.fe;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;

import tr.com.cagatayhanci.core.ObjectHelper;
import tr.com.cagatayhanci.dal.PersonelDAL;
import tr.com.cagatayhanci.interfaces.FeInterfaces;
import tr.com.cagatayhanci.types.PersonelContract;

public class PersonelEkleFE extends JDialog implements FeInterfaces{

	

	public PersonelEkleFE() {
		initPencere();
	}

	@Override
	public void initPencere() {
		JPanel panel = initPanel();
		add(panel);
		setTitle("Personel Ekle");
		setSize(250,160);
		setLocationRelativeTo(null);
		setModalityType(DEFAULT_MODALITY_TYPE);
		setDefaultCloseOperation(HIDE_ON_CLOSE);
		setVisible(true);
		
		
	}

	@Override
	public JPanel initPanel() {
		JPanel panel = new JPanel(new GridLayout(3,2));
		panel.setBorder(BorderFactory.createTitledBorder("Personel Ozellik"));
		
		JLabel adiSoyadiLabel = new JLabel("Adi Soyadi ",JLabel.RIGHT);
		panel.add(adiSoyadiLabel);
		JTextField adiSoyadiField = new JTextField(20);
		panel.add(adiSoyadiField);
		JLabel emailLabel = new JLabel("Email ",JLabel.RIGHT);
		panel.add(emailLabel);
		JTextField emailField = new JTextField(20);
		panel.add(emailField);
		JButton kaydetButon = new JButton("Kaydet");
		panel.add(kaydetButon);
		JButton iptalButon = new JButton("Iptal");
		panel.add(iptalButon);
		
		kaydetButon.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				PersonelContract contract = new PersonelContract();
				contract.setAdiSoyadi(adiSoyadiField.getText());
				contract.setEmail(emailField.getText());
				new PersonelDAL().Insert(contract);
				JOptionPane.showMessageDialog(null, "Personel eklendi");
				
			}
		});
		
		return panel;
	}

	@Override
	public JMenuBar initBar() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public JTabbedPane initTabs() {
		// TODO Auto-generated method stub
		return null;
	}

}
