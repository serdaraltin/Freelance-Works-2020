package tr.com.cagatayhanci.dal;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import tr.com.cagatayhanci.core.ObjectHelper;

import tr.com.cagatayhanci.interfaces.DALInterfaces;
import tr.com.cagatayhanci.types.MusteriContract;
import tr.com.cagatayhanci.types.PersonelContract;
import tr.com.cagatayhanci.types.StokContract;

public class MusteriDAL extends ObjectHelper implements DALInterfaces<MusteriContract> {

	@Override
	public void Insert(MusteriContract entity) {
		Connection connection = getConnection();

		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate(
					"INSERT INTO musteri (adiSoyadi,telefon,adres,sehirId) VALUES('" + entity.getAdiSoyadi() + "','"
							+ entity.getTelefon() + "','" + entity.getAdres() + "'," + entity.getSehirId() + ")");
			statement.close();
			connection.close();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	@Override
	public List<MusteriContract> GetAll() {
		List<MusteriContract> dataContracts = new ArrayList<MusteriContract>();
		Connection connection = getConnection();
		MusteriContract contract;
		
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM musteri");
			while(resultSet.next()) {
				contract = new MusteriContract();
				contract.setId(resultSet.getInt("id"));
				contract.setAdiSoyadi(resultSet.getString("adiSoyadi"));
				contract.setTelefon(resultSet.getString("telefon"));
				contract.setAdres(resultSet.getString("adres"));
				contract.setSehirId(resultSet.getInt("sehirId"));
				
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
	
	public MusteriContract GetUrunStok(String adiSoyadi) {

		MusteriContract contract = new MusteriContract();
		

		Connection connection = getConnection();
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM musteri WHERE adiSoyadi="+adiSoyadi);
			while (resultSet.next()) {
				contract.setId(resultSet.getInt("id"));
				contract.setSehirId(resultSet.getInt("sehirId"));
			}
			statement.close();
			connection.close();
		} catch (SQLException e) {
			
			e.printStackTrace();
		}

		return contract;
	}
	
	public MusteriContract GetAd(int musteriId) {

		MusteriContract contract = new MusteriContract();
		

		Connection connection = getConnection();
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM musteri WHERE id="+musteriId);
			while (resultSet.next()) {
				contract.setAdiSoyadi(resultSet.getString("adiSoyadi"));
			}
			statement.close();
			connection.close();
		} catch (SQLException e) {
			
			e.printStackTrace();
		}

		return contract;
	}
	
	

	@Override
	public MusteriContract Delete(MusteriContract entity) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void Update(MusteriContract entity) {
		Connection connection = getConnection();

		//JOptionPane.showMessageDialog(null, entity.getId());
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("UPDATE `musteri` SET `adiSoyadi` = '"+entity.getAdiSoyadi()+"', `telefon` = '"+entity.getTelefon()+"', `adres` = '"+entity.getAdres()+"', `sehirId` = '"+entity.getSehirId()+"' WHERE `musteri`.`id` = "+entity.getId());
	    	statement.close();
			connection.close();
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	@Override
	public List<MusteriContract> GetById(int id) {
		// TODO Auto-generated method stub
		return null;
	}

}
