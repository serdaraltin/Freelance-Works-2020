package tr.com.cagatayhanci.dal;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JOptionPane;

import tr.com.cagatayhanci.complex.types.StokContractComplex;
import tr.com.cagatayhanci.complex.types.UrunContractComplex;
import tr.com.cagatayhanci.core.ObjectHelper;
import tr.com.cagatayhanci.types.KategoriContract;
import tr.com.cagatayhanci.types.PersonelContract;
import tr.com.cagatayhanci.types.StokContract;
import tr.com.cagatayhanci.types.UrunlerContract;
import tr.com.cagatayhanci.interfaces.DALInterfaces;

public class UrunlerDAL extends ObjectHelper implements DALInterfaces<UrunlerContract> {

	@Override
	public void Insert(UrunlerContract entity) {
		Connection connection = getConnection();

		
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("INSERT INTO urunler(adi,kategoriId,tarih,fiyat) VALUES('" + entity.getAdi() + "',"
					+ entity.getKategoriId() + ",'" + entity.getTarih() + "'," + entity.getFiyat() + ")");

			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	public void Ekle(UrunlerContract entity, int personelId, int adet) {
		Connection connection = getConnection();
	
		
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("INSERT INTO urunler(adi,kategoriId,tarih,fiyat) VALUES('" + entity.getAdi() + "',"
					+ entity.getKategoriId() + ",'" + entity.getTarih() + "'," + entity.getFiyat() + ")");

			StokContract sContract = new StokContract();
			sContract.setPersonelId(personelId);
			sContract.setUrunId(new UrunlerDAL().GetUrunId(entity.getAdi()).getId());
			sContract.setTarih(entity.getTarih());
			sContract.setAdet(adet);

			new StokDAL().Insert(sContract);
			statement.close();
			connection.close();
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
	}

	@Override
	public List<UrunlerContract> GetAll() {
		List<UrunlerContract> dataContracts = new ArrayList<UrunlerContract>();
		Connection connection = getConnection();
		UrunlerContract contract;

		Statement statement;
		try {
			statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM urunler");
			while (resultSet.next()) {
				contract = new UrunlerContract();
				contract.setId(resultSet.getInt("id"));
				contract.setFiyat(resultSet.getFloat("fiyat"));
				contract.setKategoriId(resultSet.getInt("kategoriId"));
				contract.setTarih(resultSet.getString("tarih"));
				contract.setAdi(resultSet.getString("adi"));

				dataContracts.add(contract);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return dataContracts;
	}

	public List<UrunContractComplex> Listele() {

		List<UrunContractComplex> dataContract = new ArrayList<UrunContractComplex>();
		UrunContractComplex contract;

		Connection connection = getConnection();

		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM urunler");
			while (resultSet.next()) {

				contract = new UrunContractComplex();
				contract.setId(resultSet.getInt("id"));
				contract.setAdi(resultSet.getString("adi"));
				contract.setFiyat(resultSet.getFloat("fiyat"));
				contract.setKategoriId(resultSet.getInt("kategoriId"));
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
	public UrunlerContract Delete(UrunlerContract entity) {
		Connection connection = getConnection();

		//JOptionPane.showMessageDialog(null, entity.getId());
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("DELETE FROM urunler WHERE id= "+entity.getId());
			statement.close();
			connection.close();
			
			StokContract contract = new StokContract();
			contract.setUrunId(entity.getId());
			
			new StokDAL().Delete(contract);
			
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}

	@Override
	public void Update(UrunlerContract entity) {
		Connection connection = getConnection();

		//JOptionPane.showMessageDialog(null, entity.getId());
		try {
			Statement statement = connection.createStatement();
			statement.executeUpdate("UPDATE `urunler` SET `adi` = '"+entity.getAdi()+"', `kategoriId` = '"+entity.getKategoriId()+"', `fiyat` = '"+entity.getFiyat()+"' WHERE `urunler`.`id` = "+entity.getId());

			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}



	@Override
	public List<UrunlerContract> GetById(int id) {
		// TODO Auto-generated method stub
		return null;
	}

	public UrunlerContract GetUrunId(String urunAdi) {

		UrunlerContract contract = new UrunlerContract();
		// List<UrunlerContract> listele =new ArrayList<UrunlerContract>();

		Connection connection = getConnection();
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM urunler WHERE adi='" + urunAdi + "'");
			while (resultSet.next()) {
				contract.setId(resultSet.getInt("id"));
				contract.setAdi(resultSet.getString("adi"));
				contract.setFiyat(resultSet.getFloat("fiyat"));
				contract.setKategoriId(resultSet.getInt("kategoriId"));
				contract.setTarih(resultSet.getString("tarih"));
			}
			statement.close();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return contract;
	}

	public UrunlerContract GetUrun(int urunId) {
		UrunlerContract contract = new UrunlerContract();
		// List<UrunlerContract> listele =new ArrayList<UrunlerContract>();

		Connection connection = getConnection();
		try {
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("SELECT * FROM urunler WHERE id='" + urunId + "'");
			while (resultSet.next()) {
				contract.setId(urunId);
				contract.setAdi(resultSet.getString("adi"));
				contract.setFiyat(resultSet.getFloat("fiyat"));
				contract.setKategoriId(resultSet.getInt("kategoriId"));
				contract.setTarih(resultSet.getString("tarih"));
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
