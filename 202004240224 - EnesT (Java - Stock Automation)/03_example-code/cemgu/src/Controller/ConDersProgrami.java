package Controller;

import Core.ObjectHelper;
import Interfaces.InterfacesController;
import Types.TypeDersProgrami;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ConDersProgrami extends ObjectHelper implements InterfacesController<TypeDersProgrami> {

    @Override
    public boolean Ekle(TypeDersProgrami entity) {
        Connection connection = getConnection();
        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate("Insert Into ders_programi (id,ad,pazartesi,sali,carsamba,persembe,cuma) "
                    + "values(DEFAULT,'" + entity.getAd() + "'," + entity.getPazartesi() + "," + entity.getSali() + ","
                    + entity.getCarsamba() + "," + entity.getPersembe() + "," + entity.getCuma() + ")"
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
    public boolean Guncelle(TypeDersProgrami entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Update ders_programi set ad='" + entity.getAd() + "', pazartesi=" + entity.getPazartesi() + ","
                    + "sali=" + entity.getSali() + ",carsamba=" + entity.getCarsamba() + ",persembe=" + entity.getPersembe() + ",cuma=" + entity.getCuma()+" where id="+entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public boolean Sil(TypeDersProgrami entity) {
        Connection connection = getConnection();
        try {

            Statement statement = connection.createStatement();
            statement.executeUpdate("Delete From ders_programi Where id=" + entity.getId());
            statement.close();
            connection.close();

            return true;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public List<TypeDersProgrami> Listele() {
        try {
            Connection connection = getConnection();
            List<TypeDersProgrami> liste = new ArrayList<>();
            TypeDersProgrami item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From ders_programi");
            while (resultSet.next()) {
                item = new TypeDersProgrami();
                item.setId(resultSet.getInt("id"));
                item.setAd(resultSet.getString("ad"));
                item.setPazartesi(resultSet.getInt("pazartesi"));
                item.setSali(resultSet.getInt("sali"));
                item.setCarsamba(resultSet.getInt("carsamba"));
                item.setPersembe(resultSet.getInt("persembe"));
                item.setCuma(resultSet.getInt("cuma"));
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;

    }

    @Override
    public List<TypeDersProgrami> GetirId(int id) {
        try {
            Connection connection = getConnection();
            List<TypeDersProgrami> liste = new ArrayList<>();
            TypeDersProgrami item;

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("Select *From ders_programi Where id=" + id);
            while (resultSet.next()) {
                item = new TypeDersProgrami();
                item.setId(resultSet.getInt("id"));
                item.setAd(resultSet.getString("ad"));
                item.setPazartesi(resultSet.getInt("pazartesi"));
                item.setSali(resultSet.getInt("sali"));
                item.setCarsamba(resultSet.getInt("carsamba"));
                item.setPersembe(resultSet.getInt("persembe"));
                item.setCuma(resultSet.getInt("cuma"));
                liste.add(item);
            }
            return liste;
        } catch (SQLException ex) {
            Logger.getLogger(ConBolum.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    @Override
    public boolean Sorgula(TypeDersProgrami entity) {
        throw new UnsupportedOperationException("notlar supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}
