import java.io.*;
import java.util.*;

public class KefaAndDishes {

	public static void main(String[] args) {
        FastReader fr = new FastReader();
        int n=fr.nextInt(); int m = fr.nextInt(); int k=fr.nextInt();
        ArrayList<Integer> a = new ArrayList(n);
        for (int i=0;i<n;++i) a.add(fr.nextInt());
        int[][] c = new int[20][20];
        for (int i=0;i<20;++i){
            for (int j=0;j<20;++j) c[i][j]=0;
        }
        for (int i=0;i<k;++i) {
            int x=fr.nextInt(); int y=fr.nextInt();int cost=fr.nextInt();
            c[x-1][y-1] = cost;
        }
        long[][] dp = new long[(1<<n)][n];
        for (int i=0;i<n;++i){
            dp[1<<i][i] = a.get(i);
        }
        for (int j=0;j<(1<<n);++j){ //old bitmask
            if (Integer.bitCount(j)>m-1) continue;
            for (int x=0;x<n;++x){ //all old last dishes
                if ((j&(1<<x)) == 0) continue; //old dish needs to be in
                for (int y=0;y<n;++y) { //new dishes
                    if ((j&(1<<y)) != 0) continue; //new dish cant be in
                    dp[j | (1<<y)][y] = Math.max(dp[j | (1<<y)][y],dp[j][x] + a.get(y) + c[x][y]);
                } 
            }
        }
    long result=0;
    for (int i=0;i<(1<<n);++i){
        if (Integer.bitCount(i) != m) continue;
        for (int j=0;j<n;++j){
            result = Math.max(result,dp[i][j]);
        }
    }

    System.out.println(result);
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
