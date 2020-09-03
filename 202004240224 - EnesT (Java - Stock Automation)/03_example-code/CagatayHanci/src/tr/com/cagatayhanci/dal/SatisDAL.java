package tr.com.cagatayhanci.dal;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import tr.com.cagatayhanci.complex.types.SatisContractComplex;
import tr.com.cagatayhanci.complex.types.StokContractComplex;
import tr.com.cagatayhanci.core.ObjectHelper;

import tr.com.cagatayhanci.interfaces.DALInterfaces;
import tr.com.cagatayhanci.types.PersonelContract;
import tr.com.cagatayhanci.types.SatisContract;
import tr.com.cagatayhanci.types.UrunlerContract;

public class SatisDAL extends ObjectHelper implements DALInterfaces<SatisContract> {

	@Override
	public void Insert(SatisContract entity) {

		Connection connection = getConnection();

		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("INSERT INTO satis (musteriId,personelId,urunId,adet,tarih) VALUES("
					+ entity.getMusteriId() + "," + entity.getPersonelId() + "," + entity.getUrunId() + ","+entity.getAdet()+",'"+entity.getTarih()+"')");

			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public List<SatisContractComplex> Listele() {
		
		List<SatisContractComplex> dataContract = new ArrayList<SatisContractComplex>();
		SatisContractComplex contract;
		
		Connection connection = getConnection();
		
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM satis");
			while(resultSet.next()) {
				contract = new SatisContractComplex();
			
				contract.setId(resultSet.getInt("id"));
				contract.setMusteriAd(new MusteriDAL().GetAd(resultSet.getInt("musteriId")).getAdiSoyadi());
				contract.setPersonelAd(new PersonelDAL().GetPersonelAdi(resultSet.getInt("personelId")).getAdiSoyadi());
				contract.setUrunad(new UrunlerDAL().GetUrun(resultSet.getInt("urunId")).getAdi());
				contract.setAdet(resultSet.getInt("adet"));
				contract.setTarih(resultSet.getString("tarih"));
				
				
				
				dataContract.add(contract);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return dataContract;
	}

	@Override
	public List<SatisContract> GetAll() {

		List<SatisContract> dataContracts = new ArrayList<SatisContract>();
		Connection connection = getConnection();
		SatisContract contract;

		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM satis");
			while (resultSet.next()) {
				contract = new SatisContract();
				contract.setId(resultSet.getInt("id"));
				contract.setMusteriId(resultSet.getInt("musteriId"));
				contract.setPersonelId(resultSet.getInt("personelId"));
				contract.setUrunId(resultSet.getInt("urunId"));
				contract.setAdet(resultSet.getInt("adet"));
				contract.setTarih(resultSet.getString("tarih"));

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
	public SatisContract Delete(SatisContract entity) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void Update(SatisContract entity) {
		// TODO Auto-generated method stub

	}

	@Override
	public List<SatisContract> GetById(int id) {
		// TODO Auto-generated method stub
		return null;
	}

}
