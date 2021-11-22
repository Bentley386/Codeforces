import java.io.*;
import java.util.*;

public class Ex505 {

	public static void main(String[] args) {
        int n,m;
        FastReader fr = new FastReader();
        n = fr.nextInt(); m = fr.nextInt();
        char[][] a = new char[n][m];
        for (int i = 0;i<n;++i){
            String line = fr.nextLine();
			a[i] = line.toCharArray();
        }

		if (n==1 || m==1) System.out.println(0);
		else if (n>3 && m>3) System.out.println(-1);
		else {
			int[] as = new int[m];
			for (int i=0;i<m;++i){
				int num=0;
				for (int j=0;j<n;++j){
					if (a[j][i] == '1') num+= (1<<j);
				}
				as[i] = num;
			}
			int[][] dp = new int[1<<n][m];
			for (int i=0;i<(1<<n);++i){
				dp[i][0] = Integer.bitCount((i^as[0]));
				for (int j=1;j<m;++j) dp[i][j]=1000000000;
			}

			for (int i=1;i<m;++i){
				for (int j=0;j<(1<<n);++j) { //old mask
					for (int k=0;k<(1<<n);++k){ //new mask
						if (n == 2 && (Integer.bitCount(k) + Integer.bitCount(j)) % 2 == 0) continue;
						if (n == 3 &&  (Integer.bitCount(k>>1) + Integer.bitCount(j>>1)) % 2 == 0) continue;
						if (n == 3 && (Integer.bitCount(k & (~(1<<2))) + Integer.bitCount(j & (~(1<<2)))) % 2 == 0) continue;
						dp[k][i] = Math.min(dp[k][i],dp[j][i-1] + Integer.bitCount(as[i]^k));
					}
				}
			}

			int result=1000000000;
			for (int i=0;i<(1<<n);++i){
				result = Math.min(result,dp[i][m-1]);
			}
			System.out.println(result);
		}

	}

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
}
