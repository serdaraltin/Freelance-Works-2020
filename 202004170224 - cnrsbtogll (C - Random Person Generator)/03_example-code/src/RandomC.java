import static java.lang.Math.toIntExact;
public class RandomC {
    static long a = System.currentTimeMillis();
    int randomint(int max){

        a = (a * 32719 + 3) % 32749;
        return toIntExact((a % max) + 1);
    }


    public static void main(String[] args) {
        RandomC r = new RandomC();
        for (int i =0;i<10;i++){
            System.out.println(r.randomint(10));
        }
    }
}
