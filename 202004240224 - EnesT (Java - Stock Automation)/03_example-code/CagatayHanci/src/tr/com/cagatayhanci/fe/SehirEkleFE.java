package tr.com.cagatayhanci.fe;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;

import tr.com.cagatayhanci.dal.SehirDAL;
import tr.com.cagatayhanci.interfaces.FeInterfaces;
import tr.com.cagatayhanci.types.SehirContract;

public class SehirEkleFE extends JDialog implements FeInterfaces {

	public SehirEkleFE() {
		initPencere();
	}

	@Override
	public void initPencere() {
		JPanel panel = initPanel();
		add(panel);
		setTitle("Sehir Ekle");
		setSize(250,140);
		setLocationRelativeTo(null);
		setModalityType(DEFAULT_MODALITY_TYPE);
		setDefaultCloseOperation(HIDE_ON_CLOSE);
		setVisible(true);
		
		
	}

	@Override
	public JPanel initPanel() {
		JPanel panel = new JPanel(new GridLayout(2,2));
		panel.setBorder(BorderFactory.createTitledBorder("Sehir Ozellik"));
		
		JLabel sehirAdiLabel = new JLabel("Sehir Adi ",JLabel.RIGHT);
		JTextField sehirAdiField = new JTextField(20);
		JButton kaydetButon = new JButton("Kaydet");
		JButton iptalButon = new JButton("Iptal");
		panel.add(sehirAdiLabel);
		panel.add(sehirAdiField);
		panel.add(kaydetButon);
		panel.add(iptalButon);
		
		kaydetButon.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				SehirContract contract = new SehirContract();
				contract.setAdi(sehirAdiField.getText());
				
				new SehirDAL().Insert(contract);
				JOptionPane.showMessageDialog(null, "Sehir Eklendi");
				
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
