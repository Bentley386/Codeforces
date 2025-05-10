import java.io.*;
import java.util.*;

// https://codeforces.com/contest/1497/problem/E1

public class SquareFreeDivision {
    
    static final int MOD = 998244353;
    static int[] sieve = new int[10000005];

    public static void populatesieve(){
        for (int i=2;i<sieve.length;++i){
            if (sieve[i] == 0){
                sieve[i] = i;
                for (int j = 2*i;j<sieve.length;j+=i) sieve[j]=i;
            }
        }
    }

    public static HashMap<Integer,Integer> factorize (int x) {
        HashMap<Integer,Integer> factors = new HashMap<>();
        while (x != 1) {
            if (factors.containsKey(sieve[x])) {
                factors.put(sieve[x],(factors.get(sieve[x])+1)%2);
            } else factors.put(sieve[x],1);
            x/=sieve[x];
        }
        factors.values().removeIf(e -> e==0);
        return factors;
    }
    public static void solve(FastReader fr){
        int n,k;
        n = fr.nextInt(); k=fr.nextInt();
        int result = 1;
        HashSet<HashMap<Integer,Integer>> found = new HashSet<>();
        for (int i=0;i<n;++i) {
            HashMap<Integer,Integer> current = factorize(fr.nextInt());
            if (found.contains(current)) {
                result++;
                found.clear();
            }
            found.add(current);
        }
        System.out.println(result);
    }

	public static void main(String[] args) {
        FastReader fr = new FastReader();
        int t = fr.nextInt();
        populatesieve();
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