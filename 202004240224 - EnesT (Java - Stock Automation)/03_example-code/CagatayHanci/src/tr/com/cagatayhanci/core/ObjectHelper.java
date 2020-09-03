package tr.com.cagatayhanci.core;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


import tr.com.cagatayhanci.interfaces.CoreInterfaces;

public class ObjectHelper extends CoreFields implements CoreInterfaces {


	static {
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Override
	public Connection getConnection() {
		// TODO Auto-generated method stub
		Connection connection = null;
		
		try {
			
			connection = (Connection)DriverManager.getConnection(getUrl(),getUserName(),getPassword());
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return connection;
	}

}
