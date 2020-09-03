package RASTGELEKISIURET;

import java.util.Random;

/**
 *
 * @author Muhammed Erdinc(erdincmuhammed@gmail.com)
 * @since 30.03.2018
 * <p>
 * Yas sınıfında 0-100 aralığında yaş üretilmektedir.
 * </p>
 */
public class Yas {

    Random rakamuret = new Random();

    public int Yas() {
        return rakamuret.nextInt(100);
    }
}
