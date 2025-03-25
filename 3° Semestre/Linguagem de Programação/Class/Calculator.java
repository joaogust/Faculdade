package Class;

public class Calculator {
    public static double add(double... a) {
        double sum = 0;

        for(double n: a) {
            sum += n;
        }
        return sum;
    }

    public static double sub(double... a) {
        double sub = a[0];

        for(int i = 1; i< a.length; i++) {
            sub -= a[i];
        }
        return sub;
    }

    public static double multiply (double... a) {
        double mul = a[0];

        for(int i = 1; i< a.length; i++) {
            mul *= a[i];
        }
        return mul;
    }

    public static double divide (double... a) {
        double div = a[0];

        for(int i = 1; i< a.length; i++) {
            div /= a[i];
        }
        return div;
    }
}
