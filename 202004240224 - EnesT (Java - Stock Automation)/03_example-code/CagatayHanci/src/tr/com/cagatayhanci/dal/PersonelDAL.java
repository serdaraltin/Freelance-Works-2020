package tr.com.cagatayhanci.dal;

import java.lang.Thread.State;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import tr.com.cagatayhanci.core.ObjectHelper;

import tr.com.cagatayhanci.types.PersonelContract;

import tr.com.cagatayhanci.interfaces.DALInterfaces;

public class PersonelDAL extends ObjectHelper implements DALInterfaces<PersonelContract>{

	@Override
	public void Insert(PersonelContract entity) {
		Connection connection = getConnection();
		
		try {
			
			Statement statement = connection.createStatement();
			statement.executeUpdate("INSERT INTO personel (adiSoyadi,email) VALUES('"+entity.getAdiSoyadi()+"','"+entity.getEmail()+"')");
		    statement.close();
		    connection.close();
		}catch(SQLException hata) {
			hata.printStackTrace();
		}
		
	}

	@Override
	public List<PersonelContract> GetAll() {
		
		List<PersonelContract> dataContracts = new ArrayList<PersonelContract>();
		Connection connection = getConnection();
		PersonelContract contract;
		
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM personel");
			while(resultSet.next()) {
				contract = new PersonelContract();
				contract.setId(resultSet.getInt("id"));
				contract.setEmail(resultSet.getString("email"));
				contract.setAdiSoyadi(resultSet.getString("adiSoyadi"));
				
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
	public PersonelContract Delete(PersonelContract entity) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void Update(PersonelContract entity) {
		Connection connection = getConnection();

		//JOptionPane.showMessageDialog(null, entity.getId());
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("UPDATE `personel` SET `adiSoyadi` = '"+entity.getAdiSoyadi()+"', `email` = '"+entity.getEmail()+"' WHERE `personel`.`id` = "+entity.getId());
	    	statement.close();
			connection.close();
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	@Override
	public List<PersonelContract> GetById(int id) {
		// TODO Auto-generated method stub
		return null;
	}

	public PersonelContract GetPersonelAdi(int personelId) {
		PersonelContract contract = new PersonelContract();
		
		List<PersonelContract> listele = new ArrayList<PersonelContract>();
		
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT *FROM personel WHERE id='"+personelId+"'");
			while(resultSet.next()) {
				contract.setAdiSoyadi(resultSet.getString("adiSoyadi"));
				contract.setEmail(resultSet.getString("email"));
				contract.setId(personelId);
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
