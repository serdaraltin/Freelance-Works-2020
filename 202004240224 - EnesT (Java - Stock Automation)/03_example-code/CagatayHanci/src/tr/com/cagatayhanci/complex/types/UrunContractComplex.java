package tr.com.cagatayhanci.complex.types;

import tr.com.cagatayhanci.dal.KategoriDAL;
import tr.com.cagatayhanci.types.KategoriContract;

public class UrunContractComplex {

	private int id;
	private String adi;
	private int kategoriId;
	private float fiyat;
	private String tarih;

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getAdi() {
		return adi;
	}

	public void setAdi(String adi) {
		this.adi = adi;
	}

	public int getKategoriId() {
		return kategoriId;
	}

	public void setKategoriId(int kategoriId) {
		this.kategoriId = kategoriId;
	}

	public float getFiyat() {
		return fiyat;
	}

	public void setFiyat(float fiyat) {
		this.fiyat = fiyat;
	}

	public String getTarih() {
		return tarih;
	}

	public void setTarih(String tarih) {
		this.tarih = tarih;
	}

	public Object[] GetListe() {
		String kategoriAdi = new KategoriDAL().GetAd(kategoriId).getAdi();
		
		Object[] veriler = {id,adi,kategoriAdi,fiyat,tarih};
		
		return veriler;
	}
}
