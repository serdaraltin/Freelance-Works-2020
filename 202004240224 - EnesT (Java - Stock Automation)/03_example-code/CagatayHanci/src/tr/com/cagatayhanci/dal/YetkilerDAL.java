package tr.com.cagatayhanci.dal;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import tr.com.cagatayhanci.core.ObjectHelper;



import tr.com.cagatayhanci.interfaces.DALInterfaces;
import tr.com.cagatayhanci.types.YetkilerContract;

public class YetkilerDAL extends ObjectHelper implements DALInterfaces<YetkilerContract> {

	@Override
	public void Insert(YetkilerContract entity) {
		
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("INSERT INTO yetkiler (adi) VALUES('"+entity.getAdi()+"')");
			statement.close();
			connection.close();
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
	}

	@Override
	public List<YetkilerContract> GetAll() {
	
		List<YetkilerContract> dataContracts = new ArrayList<YetkilerContract>();
		
		YetkilerContract contract;
		
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT *FROM yetkiler");
			
			while(resultSet.next()) {
				contract = new YetkilerContract();
				contract.setId(resultSet.getInt("id"));
				contract.setAdi(resultSet.getString("adi"));
				dataContracts.add(contract);
			}
			statement.close();
			connection.close();
			
			
			
			
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return dataContracts;
	}

	@Override
	public YetkilerContract Delete(YetkilerContract entity) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void Update(YetkilerContract entity) {
		Connection connection = getConnection();

	
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("UPDATE `yetkiler` SET `adi` = '"+entity.getAdi()+"' WHERE `yetkiler`.`id` = "+entity.getId());
			statement.close();
			connection.close();
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public List<YetkilerContract> GetById(int id) {
		// TODO Auto-generated method stub
		return null;
	}
	
	public YetkilerContract GetPersonelYetki(int yetkiId) {
		YetkilerContract contract = new YetkilerContract();
		List<YetkilerContract> listele = new ArrayList<YetkilerContract>();
		
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM yetkiler WHERE id='"+yetkiId+"'");
			while(resultSet.next()) {
				contract.setAdi(resultSet.getString("adi"));
				contract.setId(resultSet.getInt("id"));
			}
			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		return contract;
	}

}
