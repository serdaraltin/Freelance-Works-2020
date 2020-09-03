package Controller;

import Core.ObjectHelper;
import Interfaces.InterfacesController;
import Types.Typenotlar;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Connotlar extends ObjectHelper implements InterfacesController<Typenotlar> {

    @Override
    public boolean Ekle(Typenotlar entity) {
        Connection connection = getConnection();
        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate("Insert Into notlar (id,ogrenci_id,ders_id,puan) "
                    + "values(DEFAULT,"+entity.getOgrenci_id()+","+entity.getDers_id()+","+entity.getPuan()
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
    public boolean Guncelle(Typenotlar entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Update notlar set ogrenci_id="+entity.getOgrenci_id()+","
                   +"ders_id="+entity.getDers_id()+",puan="+entity.getPuan()+" where id="+entity.getId()
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
    public boolean Sil(Typenotlar entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Delete From notlar Where id=" + entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public List<Typenotlar> Listele() {
        try {
            Connection connection = getConnection();
            List<Typenotlar> liste = new ArrayList<>();
            Typenotlar item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From notlar");
            while (resultSet.next()) {
                item = new Typenotlar();
                item.setId(resultSet.getInt("id"));
                item.setOgrenci_id(resultSet.getInt("ogrenci_id"));
                item.setDers_id(resultSet.getInt("ders_id"));
                item.setPuan(resultSet.getInt("puan"));
                                
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;

    }

    @Override
    public List<Typenotlar> GetirId(int id) {
        try {
            Connection connection = getConnection();
            List<Typenotlar> liste = new ArrayList<>();
            Typenotlar item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From notlar Where id=" + id);
            while (resultSet.next()) {
                item = new Typenotlar();
                       item.setId(resultSet.getInt("id"));
                item.setOgrenci_id(resultSet.getInt("ogrenci_id"));
                item.setDers_id(resultSet.getInt("ders_id"));
                item.setPuan(resultSet.getInt("puan"));
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

     
    public List<Typenotlar> GetirOgrenciId(int ogrid) {
        try {
            Connection connection = getConnection();
            List<Typenotlar> liste = new ArrayList<>();
            Typenotlar item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From notlar Where ogrenci_id=" + ogrid);
            while (resultSet.next()) {
                item = new Typenotlar();
                       item.setId(resultSet.getInt("id"));
                item.setOgrenci_id(resultSet.getInt("ogrenci_id"));
                item.setDers_id(resultSet.getInt("ders_id"));
                item.setPuan(resultSet.getInt("puan"));
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    @Override
    public boolean Sorgula(Typenotlar entity) {
        throw new UnsupportedOperationException("notlar supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}
