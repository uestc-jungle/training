import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BigInteger one = BigInteger.valueOf(1);
        BigInteger two = BigInteger.valueOf(2);
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            BigInteger n = cin.nextBigInteger();
            BigInteger k = one;
            while (k.multiply(two).compareTo(n) <= 0)
                k = k.multiply(two);
            System.out.println(k);
        }
    }
}
