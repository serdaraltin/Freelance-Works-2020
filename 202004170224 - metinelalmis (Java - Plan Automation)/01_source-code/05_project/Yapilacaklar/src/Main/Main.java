package Main;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class Main {

    public static void Sorgu(String sorgu) {
        Connection c = null;
        Statement stmt = null;
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:yapilacaklar.db");
            stmt = c.createStatement();
            stmt.executeUpdate(sorgu);
            stmt.close();
            c.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }
    }

    public static void Listele() throws SQLException {
        try {
            Connection conn = null;
            Statement stmt = null;
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:yapilacaklar.db");
            stmt = conn.createStatement();
            String sql = "Select * From yap";
            ResultSet rs = stmt.executeQuery(sql);
            System.out.println("\nKayıtlar >> \n");
            while (rs.next()) {
                int id = rs.getInt("id");
                String ad = rs.getString("ad");
                System.out.println("id: " + id+" | ad: "+ad);
                
            }  
            rs.close();
        } catch (ClassNotFoundException ex ) {
           ex.printStackTrace();
        }
    }

    public static void main(String[] args) throws SQLException {

        while (true) {
            System.out.println("\n1. Ekle");
            System.out.println("2. Güncelle");
            System.out.println("3. Sil");
            System.out.println("4. Listele");
            System.out.println("5. Çıkış");
            System.out.print("\nSeçim : ");
            Scanner scanner = new Scanner(System.in);
            int secim = scanner.nextInt();

            if(secim == 1){
                    System.out.print("Yapılacak ismi : ");
                    scanner.nextLine();
                    String yapilacak = scanner.nextLine();
                    String sql = "Insert Into yap (ad) Values('" + yapilacak + "')";
                    Sorgu(sql);
                    
           }else if(secim == 2){
                    System.out.print("Güncellenecek ismi : ");
                    scanner.nextLine();
                    String guncellenecek = scanner.nextLine();
                    System.out.print("Yeni ismi : ");
                    String yeniDeger = scanner.nextLine();
                    String sql2 = "Update yap Set ad='" + yeniDeger + "' where ad='" + guncellenecek + "'";
                    Sorgu(sql2);
          }else if(secim == 3){
                    System.out.print("Silinecek ismi : ");
                    scanner.nextLine();
                    String silinecek = scanner.nextLine();
                    String sql3 = "Delete From yap where ad='" + silinecek + "'";
                    Sorgu(sql3);
         }else if (secim == 4){
                    Listele();
         }else if (secim == 5){
                System.out.println("Programdan çıkılıyor...");
                System.exit(0);
      	 }else{
                System.out.println("Geçerli bir değer giriniz!");
            }
        
       }
    }
}
