
package Interfaces;

import java.util.List;

public interface InterfacesController<T> {
    
    public boolean Ekle(T entity);
    public boolean Guncelle(T entity);
    public boolean Sil(T entity);
    public List<T> Listele();
    public List<T> GetirId(int id);
    public boolean Sorgula(T entity);
    
}
