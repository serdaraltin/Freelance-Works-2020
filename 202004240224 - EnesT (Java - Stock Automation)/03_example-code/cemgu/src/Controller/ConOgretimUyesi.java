package Controller;

import Core.ObjectHelper;
import Interfaces.InterfacesController;
import Types.TypeOgretimUyesi;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ConOgretimUyesi extends ObjectHelper implements InterfacesController<TypeOgretimUyesi> {

    @Override
    public boolean Ekle(TypeOgretimUyesi entity) {
        Connection connection = getConnection();
        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate("Insert Into ogretimuye (id,tcno,ad,soyad,yas,bolum_id) "
                    + "values(DEFAULT,'" + entity.getTcno() + "','" + entity.getAd() + "','" + entity.getSoyad() + "'," + entity.getYas() + "," + entity.getBolum_id() + ")"
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
    public boolean Guncelle(TypeOgretimUyesi entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Update ogretimuye set tcno='" + entity.getTcno() + "',ad='" + entity.getAd() + "',"
                    + "soyad='" + entity.getSoyad() + "',yas=" + entity.getYas() + ",bolum_id=" + entity.getBolum_id() + " where id=" + entity.getId()
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
    public boolean Sil(TypeOgretimUyesi entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Delete From ogretimuye Where id=" + entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public List<TypeOgretimUyesi> Listele() {
        try {
            Connection connection = getConnection();
            List<TypeOgretimUyesi> liste = new ArrayList<>();
            TypeOgretimUyesi item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From ogretimuye");
            while (resultSet.next()) {
                item = new TypeOgretimUyesi();
                item.setId(resultSet.getInt("id"));
                item.setTcno(resultSet.getString("tcno"));
                item.setAd(resultSet.getString("ad"));
                item.setSoyad(resultSet.getString("soyad"));
                item.setYas(resultSet.getInt("yas"));
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
    public List<TypeOgretimUyesi> GetirId(int id) {
        try {
            Connection connection = getConnection();
            List<TypeOgretimUyesi> liste = new ArrayList<>();
            TypeOgretimUyesi item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From ogretimuye where id=" + id);
            while (resultSet.next()) {
                item = new TypeOgretimUyesi();
                item.setId(resultSet.getInt("id"));
                item.setTcno(resultSet.getString("tcno"));
                item.setAd(resultSet.getString("ad"));
                item.setSoyad(resultSet.getString("soyad"));
                item.setYas(resultSet.getInt("yas"));
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
    public boolean Sorgula(TypeOgretimUyesi entity) {
        throw new UnsupportedOperationException("notlar supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}
