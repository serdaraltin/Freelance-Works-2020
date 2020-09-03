package Controller;

import Core.ObjectHelper;
import Interfaces.InterfacesController;
import Types.TypeBolum;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ConBolum extends ObjectHelper implements InterfacesController<TypeBolum> {

    @Override
    public boolean Ekle(TypeBolum entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Insert Into bolum (id,ad,dersProgrami_id,sure) "
                    + "values(DEFAULT,'" + entity.getAd() + "'," + entity.getDersProgrami_id() + "," + entity.getSure() + ")"
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
    public boolean Guncelle(TypeBolum entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Update bolum set ad='"+entity.getAd()+"', dersProgrami_id="+entity.getDersProgrami_id()+", sure="+entity.getSure()+" where id="+entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public boolean Sil(TypeBolum entity) {
         Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Delete From bolum Where id="+entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public List<TypeBolum> Listele() {
        try {
            Connection connection = getConnection();
            List<TypeBolum> liste = new ArrayList<>();
            TypeBolum bolum;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From bolum");
            while (resultSet.next()) {
                bolum = new TypeBolum();
                bolum.setId(resultSet.getInt("id"));
                bolum.setAd(resultSet.getString("ad"));
                bolum.setDersProgrami_id(resultSet.getInt("dersProgrami_id"));
                bolum.setSure(resultSet.getInt("sure"));
                liste.add(bolum);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    @Override
    public List<TypeBolum> GetirId(int id) {
        try {
            Connection connection = getConnection();
            List<TypeBolum> liste = new ArrayList<>();
            TypeBolum bolum;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From bolum where id=" + id);
            while (resultSet.next()) {
                bolum = new TypeBolum();
                bolum.setId(resultSet.getInt("id"));
                bolum.setAd(resultSet.getString("ad"));
                bolum.setDersProgrami_id(resultSet.getInt("dersProgrami_id"));
                bolum.setSure(resultSet.getInt("sure"));
                liste.add(bolum);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    @Override
    public boolean Sorgula(TypeBolum entity) {
        return false;
    }

}
