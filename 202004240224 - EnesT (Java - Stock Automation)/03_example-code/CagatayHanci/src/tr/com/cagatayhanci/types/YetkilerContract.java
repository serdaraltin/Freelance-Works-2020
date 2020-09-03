package tr.com.cagatayhanci.types;

public class YetkilerContract {
	private int id;
	private String adi;

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

	@Override
	public String toString() {

		return adi;
	}

}
