
package Interfaces;

import java.util.ArrayList;


public interface InterfaceController<T> {

    public boolean Ekle(ArrayList<T> list, T type);
    public boolean Guncelle(ArrayList<T> list, T type);
    public boolean Sil(ArrayList<T> list, T type);
    public void Listele(ArrayList<T> list);
    public T Ara(ArrayList<T> list, T type);
    public int Sec(ArrayList<T> list, T type);
    public void Yazdir(T type);
}
