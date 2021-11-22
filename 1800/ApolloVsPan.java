import java.io.*;
import java.util.*;

public class ApolloVsPan {
    
    static final int MOD = 1000000007;


    public static void solve(FastReader fr){
        int n = fr.nextInt();
        ArrayList<Long> a = new ArrayList<Long>(n);
        ArrayList<Integer> count = new ArrayList<Integer>(Collections.nCopies(60, 0));
        long curr;
        for (int i=0;i<n;++i) {
            curr = fr.nextLong();
            a.add(curr);
            for (int j=0;j<60;++j) {
                if ((curr&(1L<<j)) != 0) count.set(j,count.get(j)+1);
            }
        }

        long result = 0;
        long left = 0; long right=0;
        for (int i=0;i<n;++i){
            curr = a.get(i);
            left = 0;
            right = 0;
            for (int j=0;j<60;++j){
                long powr = (1L<<j) % MOD;
                if (((1L<<j) & curr) != 0) {
                    left+= (powr * count.get(j)) % MOD;
                    right+= powr* n % MOD; 
                } else {
                    right += powr*count.get(j) % MOD;
                }
            }

            result += left % MOD * (right % MOD) % MOD;
        }
        System.out.println(result % MOD);
    }
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        int t = fr.nextInt();
        while (t-->0){
            solve(fr);
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
