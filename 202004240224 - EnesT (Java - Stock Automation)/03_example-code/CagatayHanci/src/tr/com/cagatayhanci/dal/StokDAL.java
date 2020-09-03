package tr.com.cagatayhanci.dal;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JOptionPane;

import tr.com.cagatayhanci.complex.types.StokContractComplex;
import tr.com.cagatayhanci.core.ObjectHelper;
import tr.com.cagatayhanci.fe.AnaPencereFE;
import tr.com.cagatayhanci.interfaces.DALInterfaces;
import tr.com.cagatayhanci.types.StokContract;
import tr.com.cagatayhanci.types.UrunlerContract;

public class StokDAL extends ObjectHelper implements DALInterfaces<StokContract> {

	@Override
	public void Insert(StokContract entity) {
		
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("INSERT INTO stok (personelId,urunId,tarih,adet) VALUES('"+entity.getPersonelId()+"',"+entity.getUrunId()+",'"+entity.getTarih()+"',"+entity.getAdet()+")");
			
			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	@Override
	public List<StokContract> GetAll() {
		
		
		return null;
	}

	@Override
	public StokContract Delete(StokContract entity) {
		Connection connection = getConnection();

		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("DELETE FROM stok WHERE urunId= "+entity.getUrunId());
			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}

	public StokContract GetUrunStok(int urunId) {

		StokContract contract = new StokContract();
		// List<UrunlerContract> listele =new ArrayList<UrunlerContract>();

		Connection connection = getConnection();
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM stok WHERE urunId='" + urunId + "'");
			while (resultSet.next()) {
				contract.setId(resultSet.getInt("id"));
				contract.setAdet(resultSet.getInt("adet"));
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
	public void Update(StokContract entity) {
		//JOptionPane.showMessageDialog(null, entity.getId());
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			//statement.executeUpdate("UPDATE stok SET adet = "+entity.getAdet()+"  WHERE urunId = "+entity.getUrunId());
			statement.executeUpdate("UPDATE `stok` SET `adet` = '"+entity.getAdet()+"', `tarih` = '"+entity.getTarih()+"' WHERE `stok`.`urunId` = "+entity.getUrunId());
			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public List<StokContract> GetById(int id) {
		// TODO Auto-generated method stub
		return null;
	}
	
	public List<StokContractComplex> Listele() {
		
		List<StokContractComplex> dataContract = new ArrayList<StokContractComplex>();
		StokContractComplex contract;
		
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM stok");
			while(resultSet.next()) {
		
				contract = new StokContractComplex();
				contract.setId(resultSet.getInt("id"));
				contract.setPersonel(new PersonelDAL().GetPersonelAdi(resultSet.getInt("personelId")).getAdiSoyadi());
				contract.setFiyat(new UrunlerDAL().GetUrun(resultSet.getInt("urunId")).getFiyat());
				contract.setUrun(new UrunlerDAL().GetUrun(resultSet.getInt("urunId")).getAdi());
				contract.setTarih(resultSet.getString("tarih"));
				contract.setAdet(resultSet.getInt("adet"));
				
				dataContract.add(contract);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return dataContract;
	}

}
