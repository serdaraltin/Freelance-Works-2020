package Controller;

import Core.ObjectHelper;
import Interfaces.InterfacesController;
import Types.TypeIdariMemur;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ConIdariMemur extends ObjectHelper implements InterfacesController<TypeIdariMemur> {

    @Override
    public boolean Ekle(TypeIdariMemur entity) {
        Connection connection = getConnection();
        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate("Insert Into idari_memur (id,tcno,ad,soyad,yas,gorev) "
                    + "values(DEFAULT,'"+entity.getTcno()+"','"+entity.getAd()+"','"+entity.getSoyad()+"',"+entity.getYas()+",'"+entity.getGorev()+"')"
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
    public boolean Guncelle(TypeIdariMemur entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Update idari_memur set tcno='"+entity.getTcno()+"',ad='"+entity.getAd()+"',"
                    +"soyad='"+entity.getSoyad()+"',yas="+entity.getYas()+",gorev='"+entity.getGorev()+"' where id="+entity.getId()
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
    public boolean Sil(TypeIdariMemur entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Delete From idari_memur Where id=" + entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public List<TypeIdariMemur> Listele() {
        try {
            Connection connection = getConnection();
            List<TypeIdariMemur> liste = new ArrayList<>();
            TypeIdariMemur item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From idari_memur");
            while (resultSet.next()) {
                item = new TypeIdariMemur();
                item.setId(resultSet.getInt("id"));
                item.setTcno(resultSet.getString("tcno"));
                item.setAd(resultSet.getString("ad"));
                item.setSoyad(resultSet.getString("soyad"));
                item.setYas(resultSet.getInt("yas"));
                item.setGorev(resultSet.getString("gorev"));
                                
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;

    }

    @Override
    public List<TypeIdariMemur> GetirId(int id) {
        try {
            Connection connection = getConnection();
            List<TypeIdariMemur> liste = new ArrayList<>();
            TypeIdariMemur item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From idari_memur Where id=" + id);
            while (resultSet.next()) {
                item = new TypeIdariMemur();
                item.setId(resultSet.getInt("id"));
                item.setTcno(resultSet.getString("tcno"));
                item.setAd(resultSet.getString("ad"));
                item.setSoyad(resultSet.getString("soyad"));
                item.setYas(resultSet.getInt("yas"));
                item.setGorev(resultSet.getString("gorev"));
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    @Override
    public boolean Sorgula(TypeIdariMemur entity) {
        throw new UnsupportedOperationException("notlar supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}
