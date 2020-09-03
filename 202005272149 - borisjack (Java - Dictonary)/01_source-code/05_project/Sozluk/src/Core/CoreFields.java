package Core;

public class CoreFields {

   // private String driver = "org.apache.derby.jdbc.EmbeddedDriver";
    private String database = "jdbc:derby:veritabani";

  
    public String getDatabase() {
        return database;
    }

    public void setDatabase(String database) {
        this.database = database;
    }

     @Override
    public String toString() {
        return "CoreFields{" + "database=" + database + '}';
    }

    
}
