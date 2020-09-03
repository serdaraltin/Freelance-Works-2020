package Odev2Kutuphane;

public class Rastgele {
     static long a = System.currentTimeMillis();

     int random(int max) {
        a = (a * 32719L + 3L) % 32749L;
        return (Math.toIntExact(a % (long) max + 1L)-1);
    }
}
