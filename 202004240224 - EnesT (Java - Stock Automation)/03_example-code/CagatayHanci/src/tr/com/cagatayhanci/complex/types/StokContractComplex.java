package tr.com.cagatayhanci.complex.types;

public class StokContractComplex {
	private int id;
	private String personel;
	private String urun;
	private float fiyat;
	private int adet;
	private String tarih;

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getPersonel() {
		return personel;
	}

	public void setPersonel(String personel) {
		this.personel = personel;
	}

	public String getUrun() {
		return urun;
	}

	public void setUrun(String urun) {
		this.urun = urun;
	}

	public float getFiyat() {
		return fiyat;
	}

	public void setFiyat(float fiyat) {
		this.fiyat = fiyat;
	}

	public int getAdet() {
		return adet;
	}

	public void setAdet(int adet) {
		this.adet = adet;
	}

	public String getTarih() {
		return tarih;
	}

	public void setTarih(String tarih) {
		this.tarih = tarih;
	}
	
	public Object[] GetListe() {
		Object[] veriler = {id,personel,urun,fiyat,adet,tarih};
		
		return veriler;
	}
	
	@Override
	public String toString() {
		return urun;
	}

}
