
package Interfaces;

import Types.TypeKelime;
import java.util.List;
import javax.swing.table.DefaultTableModel;

public interface InterfacesController<T> {
    
    public boolean Ekle(T entity);
    public boolean Guncelle(T entity);
    public boolean Sil(int id);
    public DefaultTableModel Listele(javax.swing.JTable tablo);
    public TypeKelime GetirId(int id);
    public boolean Sorgula(T entity);
    
}
