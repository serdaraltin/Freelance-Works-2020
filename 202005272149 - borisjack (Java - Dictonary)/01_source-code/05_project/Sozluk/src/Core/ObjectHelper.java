package Core;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ObjectHelper extends CoreFields implements Interfaces.InterfacesCore {

    static {
        try {
            Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(ObjectHelper.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @Override
    public Connection getConnection() {
        Connection connection = null;
        
        try {
            connection = (Connection) DriverManager.getConnection(getDatabase());
        } catch (SQLException ex) {
            Logger.getLogger(ObjectHelper.class.getName()).log(Level.SEVERE, null, ex);
        }
        return connection;

    }

}
