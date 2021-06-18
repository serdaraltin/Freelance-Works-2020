package tr.com.cagatayhanci.complex.types;

public class SatisContractComplex {
	private int id;
	private String musteriAd;
	private String personelAd;
	private String urunad;
	private int adet;
	private String tarih;

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getMusteriAd() {
		return musteriAd;
	}

	public void setMusteriAd(String musteriAd) {
		this.musteriAd = musteriAd;
	}

	public String getPersonelAd() {
		return personelAd;
	}

	public void setPersonelAd(String personelAd) {
		this.personelAd = personelAd;
	}

	public String getUrunad() {
		return urunad;
	}

	public void setUrunad(String urunad) {
		this.urunad = urunad;
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

	public Object[] GetListele() {
		
		Object[] veriler = {id,musteriAd,personelAd,urunad,adet,tarih};
		
		return veriler;
	}
	

}
