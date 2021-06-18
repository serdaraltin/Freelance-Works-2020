package Veritabani;

import java.sql.*;
import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class Veritabani {

    public boolean BaglantiTest() {
        Connection connection = null;
        try {
            Class.forName("org.sqlite.JDBC");
            connection = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
        } catch (ClassNotFoundException | SQLException e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            return false;
        }
        return true;
    }

    public boolean TabloOlustur() {
        BaglantiTest();
        Connection c = null;
        Statement stmt = null;
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = c.createStatement();
            String tbl_yonetici = "CREATE TABLE tbl_yonetici "
                    + "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    + " email TEXT, "
                    + " parola TEXT)";
            String tbl_musteri = "CREATE TABLE tbl_musteri "
                    + "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    + " tc TEXT, "
                    + " ad TEXT, "
                    + " soyad TEXT, "
                    + " telefon TEXT, "
                    + " adres TEXT, "
                    + " email TEXT, "
                    + " sosyal_medya TEXT, "
                    + " posta TEXT)";

            String tbl_urun = "CREATE TABLE tbl_urun "
                    + "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    + " ad TEXT, "
                    + " miktar INTEGER, "
                    + " fiyat INTEGER)";

            String tbl_siparis = "CREATE TABLE tbl_siparis "
                    + "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    + " musteri_id INTEGER NOT NULL, "
                    + " urun_id INTEGER, "
                    + " adet INTEGER, "
                    + " toplam INTEGER, "
                    + " tarih TEXT, "
                    + " durum TEXT) ";

            stmt.executeUpdate(tbl_yonetici);
            stmt.executeUpdate(tbl_musteri);
            stmt.executeUpdate(tbl_urun);
            stmt.executeUpdate(tbl_siparis);
            stmt.close();
            c.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            return false;
        }
        return true;
    }

    public boolean Sorgu(String sorgu) {
        Connection c = null;
        Statement stmt = null;
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = c.createStatement();
            stmt.executeUpdate(sorgu);
            stmt.close();
            c.close();
            return true;
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            return false;
        }
    }

    public ArrayList<String> GetirMusteri(int _id) throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_musteri where id=" + _id;
            ResultSet rs = stmt.executeQuery(sql);
            ArrayList<String> bilgiler = new ArrayList<String>();
            while (rs.next()) {
                int id = rs.getInt("id");
                bilgiler.add(Integer.toString(id));
                bilgiler.add(rs.getString("tc"));
                bilgiler.add(rs.getString("ad"));
                bilgiler.add(rs.getString("soyad"));
                bilgiler.add(rs.getString("telefon"));
                bilgiler.add(rs.getString("adres"));
                bilgiler.add(rs.getString("email"));
                bilgiler.add(rs.getString("sosyal_medya"));
                bilgiler.add(rs.getString("posta"));
            }
            rs.close();
            return bilgiler;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public ArrayList<String> GetirMusteri(String ad) throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_musteri where ad='" + ad + "'";
            ResultSet rs = stmt.executeQuery(sql);
            ArrayList<String> bilgiler = new ArrayList<String>();
            while (rs.next()) {
                int id = rs.getInt("id");
                bilgiler.add(Integer.toString(id));
                bilgiler.add(rs.getString("tc"));
                bilgiler.add(rs.getString("ad"));
                bilgiler.add(rs.getString("soyad"));
                bilgiler.add(rs.getString("telefon"));
                bilgiler.add(rs.getString("adres"));
                bilgiler.add(rs.getString("email"));
                bilgiler.add(rs.getString("sosyal_medya"));
                bilgiler.add(rs.getString("posta"));
            }
            rs.close();
            return bilgiler;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public ArrayList<String> GetirUrun(int _id) throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_urun where id=" + _id;
            ResultSet rs = stmt.executeQuery(sql);
            ArrayList<String> bilgiler = new ArrayList<String>();
            while (rs.next()) {
                int id = rs.getInt("id");
                bilgiler.add(Integer.toString(id));
                bilgiler.add(rs.getString("ad"));
                bilgiler.add(Integer.toString(rs.getInt("miktar")));
                bilgiler.add(Integer.toString(rs.getInt("fiyat")));
            }
            rs.close();
            return bilgiler;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public ArrayList<String> GetirUrun(String ad) throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_urun where ad='" + ad + "'";
            ResultSet rs = stmt.executeQuery(sql);
            ArrayList<String> bilgiler = new ArrayList<String>();
            while (rs.next()) {
                int id = rs.getInt("id");
                bilgiler.add(Integer.toString(id));
                bilgiler.add(rs.getString("ad"));
                bilgiler.add(Integer.toString(rs.getInt("miktar")));
                bilgiler.add(Integer.toString(rs.getInt("fiyat")));
            }
            rs.close();
            return bilgiler;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public ArrayList<String> GetirYonetici(int _id) throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_yonetici where id=" + _id;
            ResultSet rs = stmt.executeQuery(sql);
            ArrayList<String> bilgiler = new ArrayList<String>();
            while (rs.next()) {
                int id = rs.getInt("id");
                bilgiler.add(Integer.toString(id));
                bilgiler.add(rs.getString("email"));
                bilgiler.add(rs.getString("parola"));
            }
            rs.close();
            return bilgiler;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public boolean YoneticiDogrula(String email, String parola) throws SQLException {
        try {

            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_yonetici where email='" + email + "' and parola='" + parola + "'";
            ResultSet rs = stmt.executeQuery(sql);

            if (rs.next()) {
                rs.close();
                return true;
            }

            return false;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return false;
        }
    }

    public ArrayList<String> GetirSiparis(int _id) throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_siparis where id=" + _id;
            ResultSet rs = stmt.executeQuery(sql);
            ArrayList<String> bilgiler = new ArrayList<String>();
            while (rs.next()) {
                int id = rs.getInt("id");
                bilgiler.add(Integer.toString(id));
                bilgiler.add(Integer.toString(rs.getInt("musteri_id")));
                bilgiler.add(Integer.toString(rs.getInt("urun_id")));
                bilgiler.add(Integer.toString(rs.getInt("adet")));
                bilgiler.add(Integer.toString(rs.getInt("toplam")));
                bilgiler.add(rs.getString("tarih"));
                bilgiler.add(rs.getString("durum"));

            }
            rs.close();
            return bilgiler;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public ArrayList<String[]> ListeleSiparis() throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_siparis";
            ResultSet rs = stmt.executeQuery(sql);
            ArrayList<String[]> bilgiler = new ArrayList<String[]>();
            while (rs.next()) {
                int id = rs.getInt("id");
                String[] kayit = {
                    Integer.toString(id),
                    Integer.toString(rs.getInt("musteri_id")),
                    Integer.toString(rs.getInt("urun_id")),
                    Integer.toString(rs.getInt("adet")),
                    Integer.toString(rs.getInt("toplam")),
                    rs.getString("tarih"),
                    rs.getString("durum")
                };

                bilgiler.add(kayit);
            }
            rs.close();
            return bilgiler;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public ArrayList<String[]> ListeleMusteri() throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_musteri";
            ResultSet rs = stmt.executeQuery(sql);
            ArrayList<String[]> bilgiler = new ArrayList<String[]>();
            while (rs.next()) {
                int id = rs.getInt("id");
                String[] kayit = {
                    Integer.toString(id),
                    rs.getString("tc"),
                    rs.getString("ad"),
                    rs.getString("soyad"),
                    rs.getString("telefon"),
                    rs.getString("adres"),
                    rs.getString("email"),
                    rs.getString("sosyal_medya"),
                    rs.getString("posta")
                };

                bilgiler.add(kayit);
            }
            rs.close();
            return bilgiler;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public ArrayList<String[]> ListeleUrun() throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_urun";
            ResultSet rs = stmt.executeQuery(sql);
            ArrayList<String[]> bilgiler = new ArrayList<String[]>();
            while (rs.next()) {
                int id = rs.getInt("id");
                String[] kayit = {
                    Integer.toString(id),
                    rs.getString("ad"),
                    Integer.toString(rs.getInt("miktar")),
                    Integer.toString(rs.getInt("fiyat"))
                };

                bilgiler.add(kayit);
            }
            rs.close();
            return bilgiler;
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public DefaultTableModel Siparisler(javax.swing.JTable tablo) throws SQLException {
        try {
            DefaultTableModel model = (DefaultTableModel) tablo.getModel();
            model.setRowCount(0);
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_siparis";
            ResultSet rs = stmt.executeQuery(sql);
           
            while (rs.next()) {
              
                model.addRow(new Object[]{
                rs.getInt("id"),
                    rs.getInt("musteri_id"),
                    rs.getInt("urun_id"),
                    rs.getInt("adet"),
                    rs.getInt("toplam"),
                    rs.getString("tarih"),
                    rs.getString("durum")
                });
            
            }
            rs.close();
      
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
        return null;
    }

    
    public DefaultTableModel Siparisler(javax.swing.JTable tablo , int id) throws SQLException {
        try {
            DefaultTableModel model = (DefaultTableModel) tablo.getModel();
            model.setRowCount(0);
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_siparis where id="+id;
            ResultSet rs = stmt.executeQuery(sql);
           
            while (rs.next()) {
              
                model.addRow(new Object[]{
                rs.getInt("id"),
                    rs.getInt("musteri_id"),
                    rs.getInt("urun_id"),
                    rs.getInt("adet"),
                    rs.getInt("toplam"),
                    rs.getString("tarih"),
                    rs.getString("durum")
                });
            
            }
            rs.close();
      
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
        return null;
    }
     public DefaultTableModel SiparislerMus(javax.swing.JTable tablo , int id) throws SQLException {
        try {
            DefaultTableModel model = (DefaultTableModel) tablo.getModel();
            model.setRowCount(0);
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:veritabani.db");
            stmt = conn.createStatement();
            String sql = "Select * From tbl_siparis where musteri_id="+id;
            ResultSet rs = stmt.executeQuery(sql);
           
            while (rs.next()) {
              
                model.addRow(new Object[]{
                rs.getInt("id"),
                    rs.getInt("musteri_id"),
                    rs.getInt("urun_id"),
                    rs.getInt("adet"),
                    rs.getInt("toplam"),
                    rs.getString("tarih"),
                    rs.getString("durum")
                });
            
            }
            rs.close();
      
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
            return null;
        }
        return null;
    }

}
