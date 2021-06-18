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

import tr.com.cagatayhanci.dal.KategoriDAL;
import tr.com.cagatayhanci.interfaces.FeInterfaces;
import tr.com.cagatayhanci.types.KategoriContract;

public class KategoriEkleFE extends JDialog implements FeInterfaces{

	public KategoriEkleFE() {
		initPencere();
	}

	@Override
	public void initPencere() {
		JPanel panel = initPanel();
		
		add(panel);
		setTitle("Kategori Ekle");

		setSize(250,165);
		setLocationRelativeTo(null);
		setModalityType(DEFAULT_MODALITY_TYPE);
		setDefaultCloseOperation(HIDE_ON_CLOSE);
		setVisible(true);
	}

	@Override
	public JPanel initPanel() {
		JPanel panel = new JPanel(new GridLayout(3,2));
		panel.setBorder(BorderFactory.createTitledBorder("Kategori Ozellik"));
		
		JLabel kategoriLabel = new JLabel("Kategori ",JLabel.RIGHT);
		JTextField kategoriField = new JTextField(20);
		panel.add(kategoriLabel);
		panel.add(kategoriField);
		
		JLabel kategorilerLabel = new JLabel("Kategoriler ",JLabel.RIGHT);
		JComboBox kategorilerBox = new JComboBox(new KategoriDAL().GetAll().toArray());
		kategorilerBox.insertItemAt("--Kategori--", 0);
		kategorilerBox.setSelectedIndex(0);
		panel.add(kategorilerLabel);
		panel.add(kategorilerBox);
		
		JButton kaydetButon = new JButton("Kaydet");
		JButton iptalButon = new JButton("Iptal");
		panel.add(kaydetButon);
		panel.add(iptalButon);
		
		kaydetButon.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				KategoriContract contract = new KategoriContract();
			
				if(kategorilerBox.getSelectedIndex() != 0) {
					KategoriContract casContract = (KategoriContract) kategorilerBox.getSelectedItem();
					
					contract.setAdi(kategoriField.getText());
					contract.setParentId(casContract.getId());
					
					new KategoriDAL().Insert(contract);
					JOptionPane.showMessageDialog(null, "Kategori Olusturuldu");
				}else {
					
					contract.setAdi(kategoriField.getText());
					contract.setParentId(0);
					
					new KategoriDAL().Insert(contract);
					JOptionPane.showMessageDialog(null, "Kategori Olusturuldu");
					
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
