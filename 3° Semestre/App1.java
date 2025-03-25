package Apps;

import Class.Calculator;
import Class.Account;


public class App1 {

    public static void main(String[] args) {

        var a1 = new Account("João Gustavo", "1234");

        System.out.println(a1);
        a1.deposit(900);
        System.out.println(a1);

        var a2 = new Account("Pedro", "1235");

        System.out.println(a2);
        a1.transfer(a2, 500);
        System.out.println(a1);
        System.out.println(a2);

        System.out.println(Calculator.add(1,2,5,2));
        System.out.println(Calculator.sub(10,4,3));
        System.out.println(Calculator.multiply(10,4,3));
        System.out.println(Calculator.divide(10,2, 0.5));

    }
}
