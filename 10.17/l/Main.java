import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    static int maxn = 100000;
    static BigInteger[] f = new BigInteger[maxn];
    static void init() {
        BigInteger lim = BigInteger.valueOf(10).pow(190);
        f[0] = BigInteger.valueOf(3);
        f[1] = BigInteger.valueOf(20);
        for (int i = 2; f[i - 1].compareTo(lim) == -1; i++)
        {
            f[i] = f[i - 1].multiply(BigInteger.valueOf(6))
                    .subtract(f[i - 2])
                    .add(BigInteger.valueOf(2));
        }
    }
    public static void main(String[] args) throws Exception {
        init();
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            BigInteger L = cin.nextBigInteger();
            int j;
            for (j = 0; f[j].compareTo(L) == -1; j++);
            System.out.println(f[j]);
        }
    }
}
