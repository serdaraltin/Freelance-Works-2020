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
import javax.swing.JPasswordField;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;

import tr.com.cagatayhanci.dal.AccountsDAL;
import tr.com.cagatayhanci.dal.PersonelDAL;
import tr.com.cagatayhanci.dal.YetkilerDAL;
import tr.com.cagatayhanci.interfaces.FeInterfaces;
import tr.com.cagatayhanci.types.AccountsContract;
import tr.com.cagatayhanci.types.PersonelContract;
import tr.com.cagatayhanci.types.YetkilerContract;

public class SifreBelirlemeFE extends JDialog implements FeInterfaces{

	public SifreBelirlemeFE() {
		initPencere();
	}

	@Override
	public void initPencere() {
		JPanel panel = initPanel();
		add(panel);
		
		setTitle("Personel Duzenle");
		setSize(250,225);
		setLocationRelativeTo(null);
		setModalityType(DEFAULT_MODALITY_TYPE);
		setDefaultCloseOperation(HIDE_ON_CLOSE);
		setVisible(true);
	}

	@Override
	public JPanel initPanel() {
		JPanel panel = new JPanel(new GridLayout(5,2));
		panel.setBorder(BorderFactory.createTitledBorder("Personel Ozellik"));
		
		JLabel personelAdLabel = new JLabel("Personel ",JLabel.RIGHT);
		JComboBox personelAdBox = new JComboBox(new PersonelDAL().GetAll().toArray());
		panel.add(personelAdLabel);
		panel.add(personelAdBox);
		
		JLabel yetkiAdLabel = new JLabel("Yetki ",JLabel.RIGHT);
		JComboBox yetkiAdBox = new JComboBox(new YetkilerDAL().GetAll().toArray());
		panel.add(yetkiAdLabel);
		panel.add(yetkiAdBox);
		
		JLabel sifreLabel = new JLabel("Sifre ",JLabel.RIGHT);
		JPasswordField sifreField = new JPasswordField(20);
		panel.add(sifreLabel);
		panel.add(sifreField);
		
		JLabel sifreTekrarLabel = new JLabel("Sifre Tekrar ",JLabel.RIGHT);
		JPasswordField sifreTekrarField = new JPasswordField(20);
		panel.add(sifreTekrarLabel);
		panel.add(sifreTekrarField);
		
		JButton kaydetButon = new JButton("Kaydet");
		JButton iptalbuton = new JButton("Iptal");
		panel.add(kaydetButon);
		panel.add(iptalbuton);
		
		kaydetButon.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				if(sifreField.getText().equals(sifreTekrarField.getText())) {
					
					AccountsContract contract = new AccountsContract();
					PersonelContract pContract = (PersonelContract)personelAdBox.getSelectedItem();
					YetkilerContract yContract = (YetkilerContract)yetkiAdBox.getSelectedItem(); 
					
					contract.setPersonelId(pContract.getId());
					contract.setSifre(sifreField.getText());
					contract.setYetkiId(yContract.getId());
					
					new AccountsDAL().Insert(contract);
					
					JOptionPane.showMessageDialog(null, "Duzenlendi");
					
				}else {
					JOptionPane.showMessageDialog(null, "Sifreler uyusmuyor");
				}
				
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
