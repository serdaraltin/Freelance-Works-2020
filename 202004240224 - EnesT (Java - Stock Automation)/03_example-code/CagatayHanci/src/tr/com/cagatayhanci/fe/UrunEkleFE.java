package tr.com.cagatayhanci.fe;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;

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

import com.toedter.calendar.JDateChooser;

import tr.com.cagatayhanci.dal.KategoriDAL;
import tr.com.cagatayhanci.dal.StokDAL;
import tr.com.cagatayhanci.dal.UrunlerDAL;
import tr.com.cagatayhanci.interfaces.FeInterfaces;
import tr.com.cagatayhanci.types.KategoriContract;
import tr.com.cagatayhanci.types.StokContract;
import tr.com.cagatayhanci.types.UrunlerContract;

public class UrunEkleFE extends JDialog implements FeInterfaces{
	
	private int personelId;
	

	public UrunEkleFE(int personelId) {
		this.personelId = personelId;
		initPencere();
	}

	@Override
	public void initPencere() {
		JPanel panel = initPanel();
		
		add(panel);
		setTitle("Urun Ekleme");
		setSize(250, 230);
		setLocationRelativeTo(null);
		setModalityType(DEFAULT_MODALITY_TYPE);
		setDefaultCloseOperation(HIDE_ON_CLOSE);
		setVisible(true);
	
		
		
	}

	@Override
	public JPanel initPanel() {
		
		JPanel panel = new JPanel(new GridLayout(6,2));
		panel.setBorder(BorderFactory.createTitledBorder("Urun Ozellik"));
		
		
		JLabel adiLabel = new JLabel("Urun Adi ",JLabel.RIGHT);
		JTextField adiField = new JTextField(10);
		panel.add(adiLabel);
		panel.add(adiField);
		
		JLabel kategoriLabel = new JLabel("Kategori ",JLabel.RIGHT);
		JComboBox kategoriBox = new JComboBox(new KategoriDAL().GetAll().toArray());
		panel.add(kategoriLabel);
		panel.add(kategoriBox);
		
		JLabel tarihLabel = new JLabel("Tarih ",JLabel.RIGHT);
		JDateChooser tarihDate = new JDateChooser();
		panel.add(tarihLabel);
		panel.add(tarihDate);
		
		JLabel fiyatLabel = new JLabel("Fiyat ",JLabel.RIGHT);
		JTextField fiyatField = new JTextField(10);
		panel.add(fiyatLabel);
		panel.add(fiyatField);
		
		JLabel adetLabel = new JLabel("Adet ",JLabel.RIGHT);
		JTextField adetField = new JTextField(10);
		panel.add(adetLabel);
		panel.add(adetField);
		
		JButton kaydetButon = new JButton("Kaydet");
		JButton iptalButon = new JButton("Iptal");
		panel.add(kaydetButon);
		panel.add(iptalButon);
		
		kaydetButon.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				if (adetField.getText() != "" && tarihDate.getDate() != null && adetField.getText() != "") {
					
				String urunad = new UrunlerDAL().GetUrunId(adetField.getText()).getAdi();
				if (!(urunad != "")) {
				UrunlerContract contract = new UrunlerContract();
				KategoriContract casContract = (KategoriContract) kategoriBox.getSelectedItem();
				
				SimpleDateFormat tarihformat = new SimpleDateFormat("yyyy-MM-dd");
				
				String date = tarihformat.format(tarihDate.getDate());
				
				contract.setAdi(adiField.getText());
				contract.setKategoriId(casContract.getId());
				contract.setTarih(date);
				contract.setFiyat(Float.parseFloat(fiyatField.getText()));
				
				new UrunlerDAL().Ekle(contract,personelId,Integer.parseInt(adetField.getText()));
				
				
				
				JOptionPane.showMessageDialog(null, "Urun basariyla eklendi");
				}else {
					JOptionPane.showMessageDialog(null, "Urun zaten kayitli");
				}
				
			}else {
				JOptionPane.showMessageDialog(null, "Gerekli alanlari doldurun");
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
