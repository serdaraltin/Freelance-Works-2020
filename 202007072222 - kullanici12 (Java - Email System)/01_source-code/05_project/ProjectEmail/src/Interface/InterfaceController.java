package Interface;

import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public interface InterfaceController<T> {

    public boolean Ekle(T veri);

    public boolean Guncelle(T veri);

    public boolean Sil(T veri);

    public ArrayList<T> Liste();

    public T Ara(T veri);

    public T Getir(int id);

    public ArrayList<String[]> Cevir(ArrayList<T> veriler);
    
    public DefaultTableModel TabloDoldur(JTable Tablo, ArrayList<T> veriler);
}
