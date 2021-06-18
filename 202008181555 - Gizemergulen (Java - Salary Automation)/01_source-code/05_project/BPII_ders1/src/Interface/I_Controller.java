
package Interface;

import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public interface I_Controller<T> {
    public boolean Ekle(ArrayList<T> liste, T veri);
    public boolean Sil(ArrayList<T> liste, T veri);
    public boolean Guncelle(ArrayList<T> liste, T veri);
    public DefaultTableModel Listele(ArrayList<T> list, JTable tablo);
    public T Ara(ArrayList<T> list, T veri);
    public int Sec(ArrayList<T> list, T veri);
}
