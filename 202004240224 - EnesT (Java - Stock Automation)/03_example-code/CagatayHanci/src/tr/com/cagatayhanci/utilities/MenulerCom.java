package tr.com.cagatayhanci.utilities;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.SwingUtilities;

import tr.com.cagatayhanci.fe.KategoriEkleFE;
import tr.com.cagatayhanci.fe.MusteriEkleFE;
import tr.com.cagatayhanci.fe.SifreBelirlemeFE;
import tr.com.cagatayhanci.fe.PersonelEkleFE;
import tr.com.cagatayhanci.fe.SehirEkleFE;
import tr.com.cagatayhanci.fe.UrunEkleFE;
import tr.com.cagatayhanci.fe.YetkilerEkleFE;

public class MenulerCom  {
	
	public static JMenuBar initBar() {
		JMenuBar bar = new JMenuBar();
		//DOSYA ISLEMLERI
		JMenu dosyaMenu = new JMenu("Dosya");
		JMenuItem cikisItem = new JMenuItem("Cikis");
		dosyaMenu.add(cikisItem);
		bar.add(dosyaMenu);
		
		//URUN ISLEMLERI
		JMenu urunlerMenu = new JMenu("Urunler");
		bar.add(urunlerMenu);
		JMenuItem urunEkleItem = new JMenuItem("Urun Ekle");
		urunlerMenu.add(urunEkleItem);
		JMenuItem kategoriEkle = new JMenuItem("Kategori Ekle");
		urunlerMenu.add(kategoriEkle);
		//----------------------------
		urunlerMenu.addSeparator();
		//----------------------------
		JMenuItem urunDuzenleItem = new JMenuItem("Urun Duzenle");
		urunlerMenu.add(urunDuzenleItem);
		JMenuItem kategoriDuzenleItem = new JMenuItem("Kategori Duzenle");
		urunlerMenu.add(kategoriDuzenleItem);
	
		//PERSONEL ISLEMLERI
		JMenu personellerMenu = new JMenu("Personel Islemleri");
		bar.add(personellerMenu);
		JMenuItem personelEkleItem = new JMenuItem("Personel Ekle");
		personellerMenu.add(personelEkleItem);
		JMenuItem yetkiEkleItem = new JMenuItem("Yetki Ekle");
		personellerMenu.add(yetkiEkleItem);
		JMenuItem sifreBelirleItem = new JMenuItem("Sifre Belirleme");
		personellerMenu.add(sifreBelirleItem);
		//----------------------------
		personellerMenu.addSeparator();
		//----------------------------
		JMenuItem personelDuzenleItem = new JMenuItem("Personel Duzenle");
		personellerMenu.add(personelDuzenleItem);
		JMenuItem yetkiDuzenleItem = new JMenuItem("Yetki Duzenle");
		personellerMenu.add(yetkiDuzenleItem);
		JMenuItem sifreDuzenleItem = new JMenuItem("Sifre Duzenle");
		personellerMenu.add(sifreDuzenleItem);
        //MUSTERI ISLEMLERI
		JMenu musterilerMenu = new JMenu("Musteriler");
		bar.add(musterilerMenu);
		JMenuItem musteriEkleItem = new JMenuItem("Musteri Ekle");
		musterilerMenu.add(musteriEkleItem);
		JMenuItem sehirEkleItem = new JMenuItem("Sehir Ekle");
		musterilerMenu.add(sehirEkleItem);
		//----------------------------
		musterilerMenu.addSeparator();
		//----------------------------
		JMenuItem musterDuzenleItem = new JMenuItem("Musteri Duzenle");
		musterilerMenu.add(musterDuzenleItem);
		JMenuItem sehirDuzenleItem = new JMenuItem("Sehir Duzenle");
		musterilerMenu.add(sehirDuzenleItem);
	
		
		
		
		
		
		urunEkleItem.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				SwingUtilities.invokeLater(new Runnable() {
					
					@Override
					public void run() {
						//new UrunEkleFE();
						
					}
				});
				
			}
		});
		
		kategoriEkle.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				SwingUtilities.invokeLater(new Runnable() {
					
					@Override
					public void run() {
						new KategoriEkleFE();
						
					}
				});
				
			}
		});
		
		personelEkleItem.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new PersonelEkleFE();
				
			}
		});
		
		yetkiEkleItem.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				new YetkilerEkleFE();
			}
		});
		
		sifreBelirleItem.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new SifreBelirlemeFE();
				
			}
		});
		
		musteriEkleItem.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				new MusteriEkleFE();
				
			}
		});
		
		sehirEkleItem.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				new SehirEkleFE();
				
			}
		});
		return bar;
		
	}

}
