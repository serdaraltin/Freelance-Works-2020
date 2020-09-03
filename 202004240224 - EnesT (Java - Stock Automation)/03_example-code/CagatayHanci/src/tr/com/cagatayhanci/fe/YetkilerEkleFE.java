package tr.com.cagatayhanci.fe;

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
import javax.swing.JTabbedPane;
import javax.swing.JTextField;

import tr.com.cagatayhanci.dal.YetkilerDAL;
import tr.com.cagatayhanci.interfaces.FeInterfaces;
import tr.com.cagatayhanci.types.YetkilerContract;

public class YetkilerEkleFE extends JDialog implements FeInterfaces{

	public YetkilerEkleFE() {
		initPencere();
		
	}

	@Override
	public void initPencere() {
		JPanel panel = initPanel();
		add(panel);
		
		setTitle("Yetki Ekle");
		setSize(260,120);	
		setLocationRelativeTo(null);
	
		setModalityType(DEFAULT_MODALITY_TYPE);
		setDefaultCloseOperation(HIDE_ON_CLOSE);
		setVisible(true);

		
		
	}

	@Override
	public JPanel initPanel() {
		JPanel panel = new JPanel(new GridLayout(2,2));
		panel.setBorder(BorderFactory.createTitledBorder("Yetki Ozellik"));
		
		JLabel yetkiAdiLabel = new JLabel("Yetki Adi ",JLabel.RIGHT);	
		JTextField yetkiAdiField = new JTextField(10);
		panel.add(yetkiAdiLabel);
		panel.add(yetkiAdiField);
		JButton kaydetButon = new JButton("Kaydet");
		
		JButton iptalButon = new JButton("Iptal");
		panel.add(kaydetButon);
		panel.add(iptalButon);
		kaydetButon.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				YetkilerContract contract = new YetkilerContract();
				contract.setAdi(yetkiAdiField.getText());
				new YetkilerDAL().Insert(contract);
				JOptionPane.showMessageDialog(null, "Yetki eklendi.");
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
