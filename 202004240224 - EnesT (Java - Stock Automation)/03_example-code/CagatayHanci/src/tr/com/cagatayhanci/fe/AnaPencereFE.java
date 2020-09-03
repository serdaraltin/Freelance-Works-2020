package tr.com.cagatayhanci.fe;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JMenu;
import javax.swing.JSeparator;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.awt.event.ActionEvent;
import javax.swing.JTabbedPane;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;

import java.awt.ScrollPane;
import javax.swing.JSplitPane;

import com.toedter.calendar.JDateChooser;

import tr.com.cagatayhanci.complex.types.SatisContractComplex;
import tr.com.cagatayhanci.complex.types.StokContractComplex;
import tr.com.cagatayhanci.complex.types.UrunContractComplex;
import tr.com.cagatayhanci.dal.KategoriDAL;
import tr.com.cagatayhanci.dal.MusteriDAL;
import tr.com.cagatayhanci.dal.PersonelDAL;
import tr.com.cagatayhanci.dal.SatisDAL;
import tr.com.cagatayhanci.dal.StokDAL;
import tr.com.cagatayhanci.dal.UrunlerDAL;
import tr.com.cagatayhanci.types.KategoriContract;
import tr.com.cagatayhanci.types.MusteriContract;
import tr.com.cagatayhanci.types.PersonelContract;
import tr.com.cagatayhanci.types.SatisContract;
import tr.com.cagatayhanci.types.StokContract;
import tr.com.cagatayhanci.types.UrunlerContract;
import tr.com.cagatayhanci.types.YetkilerContract;

import javax.swing.JDesktopPane;
import javax.swing.JDialog;
import javax.swing.JScrollPane;
import javax.swing.JInternalFrame;
import javax.swing.JLayeredPane;
import java.awt.GridLayout;
import java.awt.Dialog.ModalExclusionType;
import java.awt.Label;
import java.awt.TextField;
import java.awt.Color;
import java.awt.SystemColor;
import java.awt.CardLayout;
import javax.swing.JButton;
import javax.swing.JTable;
import javax.swing.JScrollBar;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableModel;
import javax.swing.border.LineBorder;
import javax.swing.border.MatteBorder;
import java.awt.FlowLayout;
import javax.swing.ListSelectionModel;
import javax.swing.JComboBox;
import java.awt.event.InputMethodListener;
import java.awt.event.InputMethodEvent;
import java.awt.event.TextListener;
import java.awt.event.TextEvent;

public class AnaPencereFE extends JFrame {

	private int personelId;

	public int getPersonelId() {
		return personelId;
	}

	public void setPersonelId(int personelId) {
		this.personelId = personelId;
	}

	private String yetki; // yetki degerinin tutuldugu degisken
	private String yetkiName = "Yonetici"; // yetkili icin belirlenen yonetim degeri

	public String getYetki() {
		return yetki;// yetki kapsulleme
	}

	public void setYetki(String yetki) {
		this.yetki = yetki;
	}

	private JPanel contentPane;
	private JTable table;
	private JTable table_1;
	private DefaultTableModel model1;
	private DefaultTableModel model2;
	private DefaultTableModel model3;
	private JTable table_2;
	private JComboBox urunAdBox;
	private JTable table_3;
	/*
	 * public static void main(String[] args) {
	 * 
	 * EventQueue.invokeLater(new Runnable() { public void run() { try {
	 * AnaPencereFE frame = new AnaPencereFE(); frame.setVisible(true); } catch
	 * (Exception e) { e.printStackTrace(); } } }); }
	 */

	/**
	 * Create the frame.
	 */
	public void urunAdYenile() {
		urunAdBox.removeAllItems();
		for (UrunlerContract uContract : new UrunlerDAL().GetAll()) {
			urunAdBox.addItem(uContract.getAdi());
		}
	}

	public void urunListele() {
		try {
			while (model2.getRowCount() > 0)
				model2.removeRow(0);

			for (UrunContractComplex contract : new UrunlerDAL().Listele()) {

				model2.addRow(contract.GetListe());

			}
		} catch (Exception e) {
		}
		urunAdYenile();
	}

	public void stokListele() {
		while (model1.getRowCount() > 0)
			model1.removeRow(0);

		for (StokContractComplex contract : new StokDAL().Listele()) {

			model1.addRow(contract.GetListe());

		}

		urunListele();
	}

	public void satisListele() {
		while (model3.getRowCount() > 0)
			model3.removeRow(0);

		for (SatisContractComplex contract : new SatisDAL().Listele()) {

			model3.addRow(contract.GetListele());

		}

		urunListele();
	}

	public AnaPencereFE() {

		setTitle(new PersonelDAL().GetPersonelAdi(personelId).getAdiSoyadi());
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 900, 650);
		setLocationRelativeTo(null);

		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);

		JMenu mnDosya = new JMenu("Dosya");
		menuBar.add(mnDosya);

		JMenuItem mntmCikis = new JMenuItem("Cikis");
		mntmCikis.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		mnDosya.add(mntmCikis);

		JMenu mnUrun = new JMenu("Urun");
		menuBar.add(mnUrun);

		JMenuItem mnmUrunEkle = new JMenuItem("Urun Ekle");
		mnmUrunEkle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				new UrunEkleFE(personelId);
			}
		});
		mnUrun.add(mnmUrunEkle);

		JMenuItem mntmKategoriEkle = new JMenuItem("Kategori Ekle");
		mntmKategoriEkle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new KategoriEkleFE();
			}
		});
		mnUrun.add(mntmKategoriEkle);

		JSeparator separator = new JSeparator();
		mnUrun.add(separator);

		JMenuItem mntmUrunDuzenle = new JMenuItem("Urun Duzenle");
		mntmUrunDuzenle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (yetki.equals(yetkiName)) {
					UrunDuzenleFE dialog = new UrunDuzenleFE();
					dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
					dialog.setVisible(true);
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}
			}
		});
		mnUrun.add(mntmUrunDuzenle);

		JMenuItem mntmKategoriDuzenle = new JMenuItem("Kategori Duzenle");
		mntmKategoriDuzenle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (yetki.equals(yetkiName)) {
					KategoriDuzenleFE dialog = new KategoriDuzenleFE();
					dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
					dialog.setVisible(true);
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}
			}
		});
		mnUrun.add(mntmKategoriDuzenle);
		JMenu mnPersonel = new JMenu("Personel");
		menuBar.add(mnPersonel);

		JMenuItem mntmPersoneleEkle = new JMenuItem("Personele Ekle");
		mntmPersoneleEkle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (yetki.equals(yetkiName)) {
					new PersonelEkleFE();
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}

			}
		});
		mnPersonel.add(mntmPersoneleEkle);

		JMenuItem mntmYetkiEkle = new JMenuItem("Yetki Ekle");
		mntmYetkiEkle .addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				if (yetki.equals(yetkiName)) {
					new YetkilerEkleFE();
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}
			}
		});
		mnPersonel.add(mntmYetkiEkle );

		JMenuItem mntmSifreBelirleme = new JMenuItem("Sifre Belirleme");
		 mntmSifreBelirleme .addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (yetki.equals(yetkiName)) {
					new SifreBelirlemeFE();
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}
			}
		});
		mnPersonel.add( mntmSifreBelirleme );

		JSeparator separator_1 = new JSeparator();
		mnPersonel.add(separator_1);

		JMenuItem mntmPersonelDuzenle = new JMenuItem("Personel Duzenle");
		mntmPersonelDuzenle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (yetki.equals(yetkiName)) {
					PersonelDuzenleFE dialog = new PersonelDuzenleFE();
					dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
					dialog.setVisible(true);
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}
			}
		});
		mnPersonel.add(mntmPersonelDuzenle);

		JMenuItem mntmYetkiDuzenle = new JMenuItem("Yetki Duzenle");
		mntmYetkiDuzenle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (yetki.equals(yetkiName)) {
					YetkiDuzenleFE dialog = new YetkiDuzenleFE();
					dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
					dialog.setVisible(true);
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}
			}
		});
		mnPersonel.add(mntmYetkiDuzenle);

		JMenuItem mntmSifreDuzenle = new JMenuItem("Sifre Duzenle");
		mntmSifreDuzenle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (yetki.equals(yetkiName)) {
					SifreDuzenleFE dialog = new SifreDuzenleFE();
					dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
					dialog.setVisible(true);
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}
			}
		});
		mnPersonel.add(mntmSifreDuzenle);

		JMenu mnMusteri = new JMenu("Musteri");
		menuBar.add(mnMusteri);

		JMenuItem mntmMusteriEkle = new JMenuItem("Musteri Ekle");
		mntmMusteriEkle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				new MusteriEkleFE();
			}
		});
		mnMusteri.add(mntmMusteriEkle);

		JMenuItem mntmSehirEkle = new JMenuItem("Sehir Ekle");
		mntmSehirEkle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new SehirEkleFE();

			}
		});
		mnMusteri.add(mntmSehirEkle);

		JSeparator separator_2 = new JSeparator();
		mnMusteri.add(separator_2);

		JMenuItem mntmMusteriDuzenle = new JMenuItem("Musteri Duzenle");
		mntmMusteriDuzenle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (yetki.equals(yetkiName)) {
					MusteriDuzenleFE dialog = new MusteriDuzenleFE();
					dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
					dialog.setVisible(true);
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}
			}
		});
		mnMusteri.add(mntmMusteriDuzenle);

		JMenuItem mntmSehirDuzenle = new JMenuItem("Sehir Duzenle");
		mntmSehirDuzenle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (yetki.equals(yetkiName)) {
					SehirDuzenleFE dialog = new SehirDuzenleFE();
					dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
					dialog.setVisible(true);
				} else {
					JOptionPane.showMessageDialog(null, "Yonetici yetkisi gerektirir");
				}
			}
		});
		mnMusteri.add(mntmSehirDuzenle);

		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);

		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		contentPane.add(tabbedPane, BorderLayout.CENTER);

		JLayeredPane layeredPane = new JLayeredPane();
		tabbedPane.addTab("STOK", null, layeredPane, null);

		JPanel panel = new JPanel();
		panel.setBackground(SystemColor.activeCaptionBorder);
		panel.setBounds(0, 0, 205, 562);
		layeredPane.add(panel);
		panel.setLayout(null);

		Label label = new Label("STOK ISLEMLERI");
		label.setAlignment(Label.CENTER);
		label.setBounds(21, 10, 162, 30);
		panel.add(label);

		Label label_1 = new Label("Urun Adi");
		label_1.setAlignment(Label.RIGHT);
		label_1.setBounds(10, 46, 56, 25);
		panel.add(label_1);

		TextField textField_1 = new TextField();
		textField_1.setBounds(67, 77, 128, 22);
		panel.add(textField_1);

		Label label_2 = new Label("Adet");
		label_2.setAlignment(Label.RIGHT);
		label_2.setBounds(10, 77, 56, 22);
		panel.add(label_2);

		Label label_3 = new Label("Tarih");
		label_3.setAlignment(Label.RIGHT);
		label_3.setBounds(10, 105, 56, 22);
		panel.add(label_3);

		JDateChooser textField_2 = new JDateChooser();
		textField_2.setBounds(67, 105, 128, 22);
		panel.add(textField_2);

		JButton btnStokEkle = new JButton("Stok Ekle");

		btnStokEkle.setBounds(67, 133, 128, 30);
		panel.add(btnStokEkle);

		urunAdBox = new JComboBox(new UrunlerDAL().GetAll().toArray());
		urunAdBox.setBounds(67, 46, 128, 25);
		panel.add(urunAdBox);

		JPanel panel_1 = new JPanel();
		panel_1.setBounds(210, 0, 669, 562);
		layeredPane.add(panel_1);

		panel_1.setLayout(null);

		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(0, 52, 669, 510);
		panel_1.add(scrollPane);

		table_1 = new JTable();
		scrollPane.setViewportView(table_1);

		model1 = new DefaultTableModel(null, new String[] { "Id", "Personel", "Urun", "Fiyat", "Adet", "Tarih" }) {
			boolean[] columnEditables = new boolean[] { true, false, false, false, false, false };

			public boolean isCellEditable(int row, int column) {
				return columnEditables[column];
			}
		};

		// model1.addRow(new StokDAL().Listele().toArray());

		table_1.setModel(model1);

		stokListele();
		table_1.setBackground(SystemColor.text);

		JButton btnYenile = new JButton("YENILE");
		btnYenile.setBounds(10, 11, 89, 30);
		panel_1.add(btnYenile);
		btnYenile.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				stokListele();
			}
		});

		JLayeredPane layeredPane_1 = new JLayeredPane();
		tabbedPane.addTab("URUN", null, layeredPane_1, null);

		JPanel panel_2 = new JPanel();
		panel_2.setLayout(null);
		panel_2.setBackground(SystemColor.activeCaptionBorder);
		panel_2.setBounds(0, 0, 205, 562);
		layeredPane_1.add(panel_2);

		Label label_4 = new Label("URUN ISLEMLERI");
		label_4.setAlignment(Label.CENTER);
		label_4.setBounds(21, 10, 162, 30);
		panel_2.add(label_4);

		Label label_5 = new Label("Kategori");
		label_5.setAlignment(Label.RIGHT);
		label_5.setBounds(0, 46, 66, 25);
		panel_2.add(label_5);

		TextField urunAdiField = new TextField();
		urunAdiField.setBounds(67, 77, 128, 22);
		panel_2.add(urunAdiField);

		Label label_6 = new Label("Urun Adi");
		label_6.setAlignment(Label.RIGHT);
		label_6.setBounds(10, 77, 56, 22);
		panel_2.add(label_6);

		Label label_7 = new Label("Tarih");
		label_7.setAlignment(Label.RIGHT);
		label_7.setBounds(10, 105, 56, 22);
		panel_2.add(label_7);

		JDateChooser urunTarihField = new JDateChooser();
		urunTarihField.setBounds(67, 105, 128, 22);
		panel_2.add(urunTarihField);

		JButton btnUrunEkle = new JButton("Urun Ekle");

		btnUrunEkle.setBounds(67, 189, 128, 30);
		panel_2.add(btnUrunEkle);

		JComboBox urunKategoriBox = new JComboBox(new KategoriDAL().GetAll().toArray());
		urunKategoriBox.setBounds(67, 46, 128, 25);
		panel_2.add(urunKategoriBox);

		TextField fiyatField = new TextField();
		fiyatField.setBounds(67, 133, 128, 22);
		panel_2.add(fiyatField);

		Label label_8 = new Label("Fiyat");
		label_8.setAlignment(Label.RIGHT);
		label_8.setBounds(10, 133, 56, 22);
		panel_2.add(label_8);

		TextField urunAdetField = new TextField();
		urunAdetField.setBounds(67, 161, 128, 22);
		panel_2.add(urunAdetField);

		Label label_9 = new Label("Adet");
		label_9.setAlignment(Label.RIGHT);
		label_9.setBounds(10, 161, 56, 22);
		panel_2.add(label_9);

		JPanel panel_3 = new JPanel();
		panel_3.setLayout(null);
		panel_3.setBounds(210, 0, 669, 562);
		layeredPane_1.add(panel_3);

		JScrollPane scrollPane_1 = new JScrollPane();
		scrollPane_1.setBounds(0, 52, 669, 510);
		panel_3.add(scrollPane_1);

		table_2 = new JTable();

		model2 = new DefaultTableModel(new Object[][] {}, new String[] { "Id", "Urun", "Kategori", "Fiyat", "Tarih" });

		table_2.setModel(model2);
		table_2.setBackground(Color.WHITE);
		table_2.setBounds(0, 0, 665, 1);
		scrollPane_1.setViewportView(table_2);

		JButton btnYenle = new JButton("YENILE");
		btnYenle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				urunListele();
			}
		});
		btnYenle.setBounds(10, 11, 89, 30);
		panel_3.add(btnYenle);

		JButton btnSl = new JButton("SIL");

		btnSl.setBounds(109, 11, 89, 30);
		panel_3.add(btnSl);

		JButton btnEkle = new JButton("EKLE");
		btnEkle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new UrunEkleFE(personelId);
			}
		});
		btnEkle.setBounds(208, 11, 89, 30);
		panel_3.add(btnEkle);

		JLayeredPane layeredPane_2 = new JLayeredPane();
		tabbedPane.addTab("SATIS", null, layeredPane_2, null);
		layeredPane_2.setLayout(null);

		JPanel panel_4 = new JPanel();
		panel_4.setLayout(null);
		panel_4.setBounds(210, 0, 669, 562);
		layeredPane_2.add(panel_4);

		JScrollPane scrollPane_2 = new JScrollPane();
		scrollPane_2.setBounds(0, 52, 669, 510);
		panel_4.add(scrollPane_2);

		model3 = new DefaultTableModel(new Object[][] {},
				new String[] { "Id", "Musteri", "Personel", "Urun", "Adet", "Tarih" });
		table_3 = new JTable();
		table_3.setModel(model3);
		table_3.setBackground(Color.WHITE);
		// scrollPane_2.setColumnHeaderView(table_3);
		scrollPane_2.setViewportView(table_3);

		satisListele();

		JButton abutton = new JButton("YENILE");
		abutton.setBounds(10, 11, 89, 30);
		panel_4.add(abutton);
		abutton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				satisListele();

			}
		});

		JPanel panel_5 = new JPanel();
		panel_5.setLayout(null);
		panel_5.setBackground(SystemColor.activeCaptionBorder);
		panel_5.setBounds(0, 0, 205, 562);
		layeredPane_2.add(panel_5);

		Label label_10 = new Label("SATIS ISLEMLERI");
		label_10.setAlignment(Label.CENTER);
		label_10.setBounds(21, 10, 162, 30);
		panel_5.add(label_10);

		Label label_11 = new Label("Musteri");
		label_11.setAlignment(Label.RIGHT);
		label_11.setBounds(5, 46, 56, 25);
		panel_5.add(label_11);

		Label label_12 = new Label("Urun");
		label_12.setAlignment(Label.RIGHT);
		label_12.setBounds(15, 83, 46, 25);
		panel_5.add(label_12);

		Label label_13 = new Label("Tarih");
		label_13.setAlignment(Label.RIGHT);
		label_13.setBounds(10, 142, 46, 22);
		panel_5.add(label_13);

		JDateChooser sdateChooser = new JDateChooser();
		sdateChooser.setBounds(67, 142, 128, 22);
		panel_5.add(sdateChooser);

		JButton btnSatisYap = new JButton("Satis Yap");

		btnSatisYap.setBounds(67, 209, 128, 30);
		panel_5.add(btnSatisYap);

		JComboBox mcomboBox = new JComboBox(new MusteriDAL().GetAll().toArray());
		mcomboBox.setBounds(67, 46, 128, 25);
		panel_5.add(mcomboBox);

		TextField textField_3 = new TextField();
		textField_3.setEnabled(false);
		textField_3.setBounds(67, 170, 128, 22);
		panel_5.add(textField_3);

		Label label_14 = new Label("Fiyat");
		label_14.setAlignment(Label.RIGHT);
		label_14.setBounds(5, 170, 56, 22);
		panel_5.add(label_14);

		TextField textField_4 = new TextField();

		textField_4.setBounds(67, 114, 71, 22);
		panel_5.add(textField_4);

		Label label_15 = new Label("Adet");
		label_15.setAlignment(Label.RIGHT);
		label_15.setBounds(15, 114, 46, 22);
		panel_5.add(label_15);

		JComboBox ucomboBox_1 = new JComboBox(new UrunlerDAL().GetAll().toArray());
		ucomboBox_1.setBounds(67, 84, 128, 25);
		panel_5.add(ucomboBox_1);

		Label label_16 = new Label("0");
		label_16.setBounds(146, 114, 49, 22);
		panel_5.add(label_16);

		urunListele();
		btnSl.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					int id = Integer.parseInt(table_2.getValueAt(table_2.getSelectedRow(), 0).toString());
					UrunlerContract contract = new UrunlerContract();
					contract.setId(id);

					new UrunlerDAL().Delete(contract);

					urunListele();

				} catch (Exception hata) {
					JOptionPane.showMessageDialog(null, "Secim yapin");
				}

			}
		});
		btnStokEkle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (textField_1.getText() != "" && textField_2.getDate() != null) {

					StokContract contract = new StokContract();

					SimpleDateFormat tarihformat = new SimpleDateFormat("yyyy-MM-dd");

					String date = tarihformat.format(textField_2.getDate());

					int urunId = new UrunlerDAL().GetUrunId(urunAdBox.getSelectedItem().toString()).getId();
					int eski_stok = new StokDAL().GetUrunStok(urunId).getAdet();

					contract.setAdet((Integer.parseInt(textField_1.getText())) + eski_stok);
					// contract.setPersonelId(personelId);
					contract.setUrunId(urunId);
					contract.setTarih(date);

					JOptionPane.showMessageDialog(null, "Stok eklendi");

					new StokDAL().Update(contract);

					stokListele();
					textField_1.setText(null);
					textField_2.setDate(null);
					urunAdBox.setSelectedIndex(0);
				} else {
					JOptionPane.showMessageDialog(null, "Gerekli alanlari doldurunuz");
				}
			}
		});
		btnUrunEkle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (urunAdiField.getText() != "" && urunTarihField.getDate() != null && urunAdetField.getText() != "") {
					int urunId = new UrunlerDAL().GetUrunId(urunAdiField.getText()).getId();
					if (!(urunId >0)) {
						UrunlerContract contract = new UrunlerContract();
						KategoriContract cContract = (KategoriContract) urunKategoriBox.getSelectedItem();

						SimpleDateFormat tarihformat = new SimpleDateFormat("yyyy-MM-dd");

						String date = tarihformat.format(urunTarihField.getDate());

						contract.setAdi(urunAdiField.getText());
						contract.setFiyat(Float.parseFloat(fiyatField.getText()));
						contract.setKategoriId(cContract.getId());
						contract.setTarih(date);

						new UrunlerDAL().Ekle(contract, personelId, Integer.parseInt(urunAdetField.getText()));
						JOptionPane.showMessageDialog(null, "Urun eklendi");
						urunListele();
						stokListele();
					}else {
						JOptionPane.showMessageDialog(null, "Urun zaten kayitli");
					}
				} else {
					JOptionPane.showMessageDialog(null, "Gerekli alanlari doldurun");
				}
			}
		});

		textField_4.addInputMethodListener(new InputMethodListener() {
			public void caretPositionChanged(InputMethodEvent arg0) {

			}

			public void inputMethodTextChanged(InputMethodEvent arg0) {

			}
		});
		textField_4.addTextListener(new TextListener() {
			public void textValueChanged(TextEvent arg0) {

				UrunlerContract uContract = (UrunlerContract) ucomboBox_1.getSelectedItem();
				int stok = new StokDAL().GetUrunStok(uContract.getId()).getAdet();
				int kalan = stok - Integer.parseInt(textField_4.getText());
				// JOptionPane.showMessageDialog(null, kalan);
				label_16.setText(Integer.toString(kalan));
				float fiyat = Float.parseFloat(textField_4.getText()) * uContract.getFiyat();
				textField_3.setText(Float.toString(fiyat));
				if (kalan < 0) {
					textField_4.setText(Integer.toString(stok));
				}
			}
		});
		btnSatisYap.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				if (textField_4.getText() != "" && sdateChooser.getDate() != null) {

					SatisContract contract = new SatisContract();
					MusteriContract mContract = (MusteriContract) mcomboBox.getSelectedItem();
					UrunlerContract uContract = (UrunlerContract) ucomboBox_1.getSelectedItem();

					int stok = new StokDAL().GetUrunStok(uContract.getId()).getAdet();
					int kalan = stok - Integer.parseInt(textField_4.getText());

					if (stok > 0) {

						SimpleDateFormat tarihformat = new SimpleDateFormat("yyyy-MM-dd");

						String date = tarihformat.format(sdateChooser.getDate());

						contract.setMusteriId(mContract.getId());
						contract.setPersonelId(personelId);
						contract.setUrunId(uContract.getId());
						contract.setAdet(Integer.parseInt(textField_4.getText()));
						contract.setTarih(date);

						new SatisDAL().Insert(contract);

						StokContract sContract = new StokContract();

						sContract.setAdet(kalan);
						sContract.setPersonelId(personelId);
						sContract.setTarih(date);
						int urunId = new UrunlerDAL().GetUrunId(ucomboBox_1.getSelectedItem().toString()).getId();
						sContract.setUrunId(urunId);

						new StokDAL().Update(sContract);

						JOptionPane.showMessageDialog(null, "Satis basarili");
						textField_4.setText(null);
						label_16.setText("0");
						sdateChooser.setDate(null);

						satisListele();
						stokListele();
					} else {
						JOptionPane.showMessageDialog(null, "Stokta urun yok");
					}
				} else {

					JOptionPane.showMessageDialog(null, "Gerekli alanlari doldurun");
				}
			}
		});
	}
}
