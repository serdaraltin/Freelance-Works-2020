package Test;

import Core.ObjectHelper;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class CreateDataBase extends ObjectHelper {

    public boolean Create() {
        try {
            try {
                Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(CreateDataBase.class.getName()).log(Level.SEVERE, null, ex);
            }
            Connection connection = DriverManager.getConnection(getDatabase() + ";create=true");

            connection.createStatement().execute("Create Table sozluk ("
                    + "id int generated by default as identity (START WITH 2, INCREMENT BY 1),"
                    + "dil varchar(250),"
                    + "kelime varchar(250),"
                    + "ceviri varchar(250),"
                    + "anlam varchar(250))"
            );

            return true;
        } catch (SQLException ex) {
            //Logger.getLogger(CreateDataBase.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

}
