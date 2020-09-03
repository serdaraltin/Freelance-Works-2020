import static java.lang.Math.toIntExact;
public class Rastgele {
    static long a = System.currentTimeMillis();
    int tamsayi(int max){
        a = (a * 32719 + 3) % 32749;
        return toIntExact((a % max) + 1);
    }

}
