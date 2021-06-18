package tr.com.cagatayhanci.dal;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import tr.com.cagatayhanci.core.ObjectHelper;
import tr.com.cagatayhanci.interfaces.DALInterfaces;
import tr.com.cagatayhanci.types.SehirContract;

public class SehirDAL extends ObjectHelper implements DALInterfaces<SehirContract>{

	@Override
	public void Insert(SehirContract entity) {
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("INSERT INTO sehirler(adi) VALUES('"+entity.getAdi()+"')");
			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	@Override
	public List<SehirContract> GetAll() {
		List<SehirContract> dataContracts = new ArrayList<SehirContract>();
		SehirContract contract;
		Connection connection = getConnection();
		try {
			
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM sehirler");
			while(resultSet.next()) {
				contract = new SehirContract();
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
	public SehirContract Delete(SehirContract entity) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void Update(SehirContract entity) {
	
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("UPDATE `sehirler` SET `adi` = '"+entity.getAdi()+"' WHERE `sehirler`.`id` = "+entity.getId());
			
			statement.close();
			connection.close();
		} catch (SQLException e) {
		
			e.printStackTrace();
		}
	}

	@Override
	public List<SehirContract> GetById(int id) {
		// TODO Auto-generated method stub
		return null;
	}

}
