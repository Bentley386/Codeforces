import java.io.*;
import java.util.*;

public class CountTheBlocks {
    
    static final int MOD = 998244353;

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
		
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
        }
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble() {
			return Double.parseDouble(next());
		}
		
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
    }
    public static long power(long exp){
        if (exp==0) return 1;
        long result = power(exp/2) % MOD;
        result = result*result % MOD;
        return (exp % 2 == 0) ? result : result*10 % MOD;
    }
    
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        long n = fr.nextLong();
        for (long i=1;i<=n;++i){
            long result = 0;
            if (i==n) result=10;
            else {
                if (i<=n-1) result = 180 * power(n-1-i) % MOD;
                if (i<=n-2) result += 810*(n-2-i+1)*power(n-2-i)  % MOD;
            }
            System.out.printf("%d ",result % MOD);
        }
	}
}
