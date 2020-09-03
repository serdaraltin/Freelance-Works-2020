package tr.com.cagatayhanci.core;

public class CoreFields {
	
	private String userName="root"; // veritabani kullanici adi
	private String password = ""; // veritabani parolasi
	private String url="jdbc:mysql://localhost/stokvesatis"; // veritabani yolu

	/* KAPSULLEME */
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getUrl() {
		return url;
	}
	public void setUrl(String url) {
		this.url = url;
	}
	/* KAPSULLEME */
	
}
