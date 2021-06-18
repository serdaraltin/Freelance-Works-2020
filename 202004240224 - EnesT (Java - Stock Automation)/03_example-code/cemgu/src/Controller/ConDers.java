package Controller;

import Core.ObjectHelper;
import Interfaces.InterfacesController;
import Types.TypeDers;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;


public class ConDers extends ObjectHelper implements InterfacesController<TypeDers> {

    @Override
    public boolean Ekle(TypeDers entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Insert Into ders (id,ad,kredi) "
                    + "values(DEFAULT,'" + entity.getAd() + "'," + entity.getKredi() + ")"
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
    public boolean Guncelle(TypeDers entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Update ders set ad='" + entity.getAd() + "', kredi=" + entity.getKredi()+" where id="+entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public boolean Sil(TypeDers entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Delete From ders Where id=" + entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public List<TypeDers> Listele() {
        try {
            Connection connection = getConnection();
            List<TypeDers> liste = new ArrayList<>();
            TypeDers item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From ders");
            while (resultSet.next()) {
                item = new TypeDers();
                item.setId(resultSet.getInt("id"));
                item.setAd(resultSet.getString("ad"));
                item.setKredi(resultSet.getInt("kredi"));
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;

    }

    @Override
    public List<TypeDers> GetirId(int id) {
        try {
            Connection connection = getConnection();
            List<TypeDers> liste = new ArrayList<>();
            TypeDers item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From ders where id=" + id);
            while (resultSet.next()) {
                item = new TypeDers();
                item.setId(resultSet.getInt("id"));
                item.setAd(resultSet.getString("ad"));
                item.setKredi(resultSet.getInt("kredi"));
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

  
    @Override
    public boolean Sorgula(TypeDers entity) {
        throw new UnsupportedOperationException("notlar supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}
