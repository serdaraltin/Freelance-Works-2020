package Controller;

import Core.ObjectHelper;
import Interfaces.InterfacesController;
import Types.TypeKelime;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.table.DefaultTableModel;

public class ConSozluk extends ObjectHelper implements InterfacesController<TypeKelime> {



    @Override
    public boolean Ekle(TypeKelime entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Insert Into sozluk (id,dil,kelime,ceviri,anlam) "
                    + "values(DEFAULT,'" + entity.getDil() + "','" + entity.getKelime() + "','" + entity.getCeviri() + "','" + entity.getAnlam() + "')"
            );
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConSozluk.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public boolean Guncelle(TypeKelime entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Update sozluk set dil='" + entity.getDil() + "', kelime='" + entity.getKelime() + "', ceviri='" + entity.getCeviri() + "', anlam='" + entity.getAnlam() + "' where id=" + entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConSozluk.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public boolean Sil(int id) {
        Connection connection = getConnection();
        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate("Delete From sozluk Where id=" + id);
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConSozluk.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public DefaultTableModel Listele(javax.swing.JTable tablo) {
        try {
            Connection connection = getConnection();

            DefaultTableModel model = (DefaultTableModel) tablo.getModel();
            model.setRowCount(0);
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From sozluk");
            while (resultSet.next()) {
                model.addRow(new Object[]{
                    
                    resultSet.getInt("id"),
                    resultSet.getString("dil"),
                    resultSet.getString("kelime"),
                    resultSet.getString("ceviri")
                   // resultSet.getString("anlam")
                        
                });
            }
            return  model;
        } catch (SQLException ex) {
            Logger.getLogger(ConSozluk.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;

    }
    
      
    public DefaultTableModel Ara(javax.swing.JTable tablo, String kelime) {
        try {
            Connection connection = getConnection();

            DefaultTableModel model = (DefaultTableModel) tablo.getModel();
            model.setRowCount(0);
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From sozluk where kelime LIKE '%"+kelime +"%' or ceviri LIKE '%"+kelime+"%'");
            while (resultSet.next()) {
                model.addRow(new Object[]{
                    
                    resultSet.getInt("id"),
                    resultSet.getString("dil"),
                    resultSet.getString("kelime"),
                    resultSet.getString("ceviri")
                    //resultSet.getString("anlam")
                        
                });
            }
            return  model;
        } catch (SQLException ex) {
            Logger.getLogger(ConSozluk.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;

    }


    @Override
    public TypeKelime GetirId(int id) {
        try {
            Connection connection = getConnection();
            TypeKelime kelime;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From sozluk where id=" + id);
            while (resultSet.next()) {
                kelime = new TypeKelime();

                kelime.setId(resultSet.getInt("id"));
                kelime.setDil(resultSet.getString("dil"));
                kelime.setKelime(resultSet.getString("kelime"));
                kelime.setCeviri(resultSet.getString("ceviri"));
                kelime.setAnlam(resultSet.getString("anlam"));

                return kelime;

            }

        } catch (SQLException ex) {
            Logger.getLogger(ConSozluk.class
                    .getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    @Override
    public boolean Sorgula(TypeKelime entity) {
        return false;
    }

}
