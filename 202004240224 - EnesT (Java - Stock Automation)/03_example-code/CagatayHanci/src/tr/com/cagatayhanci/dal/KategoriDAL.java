package tr.com.cagatayhanci.dal;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import tr.com.cagatayhanci.core.ObjectHelper;
import tr.com.cagatayhanci.interfaces.DALInterfaces;
import tr.com.cagatayhanci.types.KategoriContract;
import tr.com.cagatayhanci.types.UrunlerContract;

public class KategoriDAL extends ObjectHelper implements DALInterfaces<KategoriContract>{

	@Override
	public void Insert(KategoriContract entity) {
		Connection connection = getConnection();
		
		
		try {
			Statement statement = connection.createStatement();
			
			statement.executeUpdate("INSERT INTO Kategori (adi,parentId) VALUES('"+entity.getAdi()+"',"+entity.getParentId()+")");
			statement.close();
			connection.close();
			
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}


	@Override
	public List<KategoriContract> GetAll() {
		
		List<KategoriContract> dataContracts = new ArrayList<KategoriContract>();
		Connection connection = getConnection();
		KategoriContract contract;
		
		Statement statement;
		try {
			statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM Kategori");
			while(resultSet.next()) {
				contract = new KategoriContract();
				contract.setId(resultSet.getInt("Id"));
				contract.setAdi(resultSet.getString("Adi"));
				contract.setParentId(resultSet.getInt("ParentId"));
				
				dataContracts.add(contract);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		return dataContracts;
	}

	public KategoriContract GetAd(int kategoriId) {
		
		KategoriContract contract = new KategoriContract();
		//List<UrunlerContract> listele =new ArrayList<UrunlerContract>();
		
		Connection connection = getConnection();
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM kategori WHERE id="+kategoriId);
			while(resultSet.next()) {
				contract.setId(resultSet.getInt("id"));
				contract.setAdi(resultSet.getString("adi"));
			}
			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		return contract;
	}
	
	@Override
	public KategoriContract Delete(KategoriContract entity) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void Update(KategoriContract entity) {
		Connection connection = getConnection();

	
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("UPDATE `kategori` SET `adi` = '"+entity.getAdi()+"' WHERE `kategori`.`id` = "+entity.getId());

			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	@Override
	public List<KategoriContract> GetById(int id) {
		// TODO Auto-generated method stub
		return null;
	}

	
	

}
