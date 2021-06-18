package Controller;

import Core.ObjectHelper;
import Interfaces.InterfacesController;
import Types.TypeOgrenci;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ConOgrenci extends ObjectHelper implements InterfacesController<TypeOgrenci> {

    @Override
    public boolean Ekle(TypeOgrenci entity) {
        Connection connection = getConnection();
        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate("Insert Into ogrenci (id,tcno,ad,soyad,yas,baba_adi,ana_adi,uyruk,bolum_id) "
                    + "values(DEFAULT,'" + entity.getTcno() + "','" + entity.getAd() + "','" + entity.getSoyad() + "'," + entity.getYas() + ",'" + entity.getBaba_adi() + "',"
                    + "'" + entity.getAna_adi() + "','" + entity.getUyruk() + "'," + entity.getBolum_id() + ")"
            );
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public boolean Guncelle(TypeOgrenci entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Update ogrenci set tcno='" + entity.getTcno() + "',ad='" + entity.getAd() + "',"
                    + "soyad='" + entity.getSoyad() + "',yas=" + entity.getYas() + ",baba_adi='" + entity.getBaba_adi() + "',"
                    + "ana_adi='" + entity.getAna_adi() + "',uyruk='" + entity.getUyruk() + "',bolum_id=" + entity.getBolum_id() + " where id=" + entity.getId()
            );
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public boolean Sil(TypeOgrenci entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Delete From ogrenci Where id=" + entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public List<TypeOgrenci> Listele() {
        try {
            Connection connection = getConnection();
            List<TypeOgrenci> liste = new ArrayList<>();
            TypeOgrenci item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From ogrenci");
            while (resultSet.next()) {
                item = new TypeOgrenci();
                item.setId(resultSet.getInt("id"));
                item.setTcno(resultSet.getString("tcno"));
                item.setAd(resultSet.getString("ad"));
                item.setSoyad(resultSet.getString("soyad"));
                item.setYas(resultSet.getInt("yas"));
                item.setBaba_adi(resultSet.getString("baba_adi"));
                item.setAna_adi(resultSet.getString("ana_adi"));
                item.setUyruk(resultSet.getString("uyruk"));
                item.setBolum_id(resultSet.getInt("bolum_id"));
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;

    }

    @Override
    public List<TypeOgrenci> GetirId(int id) {
try {
            Connection connection = getConnection();
            List<TypeOgrenci> liste = new ArrayList<>();
            TypeOgrenci item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From ogrenci where id="+id);
            while (resultSet.next()) {
                item = new TypeOgrenci();
                item.setId(resultSet.getInt("id"));
                item.setTcno(resultSet.getString("tcno"));
                item.setAd(resultSet.getString("ad"));
                item.setSoyad(resultSet.getString("soyad"));
                item.setYas(resultSet.getInt("yas"));
                item.setBaba_adi(resultSet.getString("baba_adi"));
                item.setAna_adi(resultSet.getString("ana_adi"));
                item.setUyruk(resultSet.getString("uyruk"));
                item.setBolum_id(resultSet.getInt("bolum_id"));
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    @Override
    public boolean Sorgula(TypeOgrenci entity) {
        throw new UnsupportedOperationException("notlar supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}
