package Soru2;

public class Islem {

    public static int Fibonacci1(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        int fibo1 = 1, fibo2 = 1, fibonacci = 1;
        for (int i = 3; i < n; i++) {
            
            fibonacci = fibo1 + fibo2;
            fibo1 = fibo2;
            fibo2 = fibonacci;
        }
        return fibonacci; 
    }

    public static int Fibonacci2(int n) {
        if((n-1) == 1 || (n-1) == 2){
            return 1;
        }
      
        return Fibonacci2(n-1) + Fibonacci2(n -2); 
    }
}
