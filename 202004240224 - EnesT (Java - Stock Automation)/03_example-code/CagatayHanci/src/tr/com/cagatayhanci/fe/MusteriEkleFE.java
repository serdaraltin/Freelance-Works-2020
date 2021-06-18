package tr.com.cagatayhanci.fe;

import java.awt.BorderLayout;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import tr.com.cagatayhanci.dal.MusteriDAL;
import tr.com.cagatayhanci.dal.SehirDAL;
import tr.com.cagatayhanci.interfaces.FeInterfaces;
import tr.com.cagatayhanci.types.MusteriContract;
import tr.com.cagatayhanci.types.SehirContract;

public class MusteriEkleFE extends JDialog implements FeInterfaces {

	public MusteriEkleFE() {
		initPencere();
	}

	@Override
	public void initPencere() {
		JPanel panel = initPanel();
		add(panel);
		
		setTitle("Musteri Ekle");
		setSize(280,220);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(HIDE_ON_CLOSE);
		setModalityType(DEFAULT_MODALITY_TYPE);
		setVisible(true);
		
		
	}

	@Override
	public JPanel initPanel() {
		JPanel panel = new JPanel(new GridLayout(5,2));
		panel.setBorder(BorderFactory.createTitledBorder("Musteri Ozellik"));
		

		JLabel musteriAdLabel = new JLabel("Musteri Ad ",JLabel.RIGHT);
		JTextField musteriAdField = new JTextField(20);
		panel.add(musteriAdLabel);
		panel.add(musteriAdField);
		

		JLabel musteriTelefonLabel = new JLabel("Musteri Telefon ",JLabel.RIGHT);
		JTextField musteriTelefonField = new JTextField(20);
		panel.add(musteriTelefonLabel);
		panel.add(musteriTelefonField);
		
		JLabel sehirLabel = new JLabel("Sehir ",JLabel.RIGHT);
		panel.add(sehirLabel);
		JComboBox sehirBox = new JComboBox(new SehirDAL().GetAll().toArray());
		panel.add(sehirBox);
		
		
	
	
		JLabel adresLabel = new JLabel("Adres ",JLabel.RIGHT);
		JTextField adresField = new JTextField(20);
		panel.add(adresLabel);
		panel.add(adresField);
		
		JButton kaydetButon = new JButton("Kaydet");
		JButton iptalButon = new JButton("Iptal");
		
		panel.add(kaydetButon);
		panel.add(iptalButon);
		
		
		kaydetButon.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				MusteriContract contract = new MusteriContract();
				SehirContract sContract = (SehirContract) sehirBox.getSelectedItem();
				
				contract.setAdiSoyadi(musteriAdField.getText());
				contract.setAdres(adresField.getText());
				contract.setTelefon(musteriTelefonField.getText());
				contract.setSehirId(sContract.getId());
				
				new MusteriDAL().Insert(contract);
				
				JOptionPane.showMessageDialog(null, "Musteri Eklendi");
				
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
