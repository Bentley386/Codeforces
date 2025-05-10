import java.io.*;
import java.util.*;

public class RemaindersGame {
    
 
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        if (solve(fr)) System.out.println("Yes");
        else System.out.println("No");
	}

    public static boolean solve(FastReader fr){
        int n,k;
        n = fr.nextInt(); k=fr.nextInt();
        ArrayList<Long> c = new ArrayList<Long>(n);
        for (int i=0;i<n;++i) c.add(i, fr.nextLong());

		if (n==1){
			if (k>c.get(0) || c.get(0)%k != 0) return false;
			else return true;
		}
        long g = gcd(c.get(0),c.get(1));
        for (int i=2;i<n;++i){
            g = gcd(g,c.get(i));
        }
        for (int i=1;i<n;++i){
            if (c.get(i-1)%g != c.get(i)%g) return false; 
        }
		boolean modded=false;
        long mod = c.get(0);
        for (int i=1;i<n;++i){
            mod = mod*(c.get(i)/gcd(mod,c.get(i)));
			if (mod>k) {
				mod%=k;
				modded=true;
			}
        }
        if (mod%k!=0 || (!modded && mod<k)) return false;
        return true;
    }
 
    public static long gcd (long a, long b){
        if (b==0l) return a;
        return gcd(b,a%b);
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