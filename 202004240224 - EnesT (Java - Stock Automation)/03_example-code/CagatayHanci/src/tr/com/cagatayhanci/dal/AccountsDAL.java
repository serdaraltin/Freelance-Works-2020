package tr.com.cagatayhanci.dal;

import java.lang.Thread.State;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import tr.com.cagatayhanci.core.CoreFields;

import tr.com.cagatayhanci.interfaces.DALInterfaces;
import tr.com.cagatayhanci.types.AccountsContract;

import tr.com.cagatayhanci.core.ObjectHelper;

public class AccountsDAL extends ObjectHelper implements DALInterfaces<AccountsContract>{

	@Override
	public void Insert(AccountsContract entity) {
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("INSERT INTO accounts(personelId,yetkiId,sifre) VALUES("+entity.getPersonelId()+","+entity.getYetkiId()+",'"+entity.getSifre()+"')");
			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

	@Override
	public List<AccountsContract> GetAll() {
		List<AccountsContract> dataContract = new ArrayList<AccountsContract>();
		AccountsContract contract;
		
		Connection connection = getConnection();
		
		try {
			
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM accounts");
			while(resultSet.next()) {
				contract = new AccountsContract();
				contract.setId(resultSet.getInt("id"));
				contract.setPersonelId(resultSet.getInt("personelId"));
				contract.setSifre(resultSet.getString("sifre"));
				contract.setYetkiId(resultSet.getInt("yetkiId"));
				
				dataContract.add(contract);
			}
			statement.close();
			connection.close();
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		
		return dataContract;
	}

	@Override
	public AccountsContract Delete(AccountsContract entity) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void Update(AccountsContract entity) {
		Connection connection = getConnection();
		
		//JOptionPane.showMessageDialog(null, entity.getId());
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("UPDATE `accounts` SET `sifre` = '"+entity.getSifre()+"' WHERE `accounts`.`personelId` = "+entity.getPersonelId());
	    	statement.close();
			connection.close();
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public List<AccountsContract> GetById(int id) {
		
		return null;
	}

	public AccountsContract GetPersonelIdVeSifre(int personelId,String sifre) {
		AccountsContract contract = new AccountsContract();
		List<AccountsContract> listele = new ArrayList<AccountsContract>();
		
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM accounts WHERE personelId="+personelId+" AND Sifre='"+sifre+"'");
			
			while(resultSet.next()) {
				contract.setPersonelId(resultSet.getInt("PersonelId"));
				contract.setSifre(resultSet.getString("sifre"));
				contract.setYetkiId(resultSet.getInt("yetkiId"));
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
