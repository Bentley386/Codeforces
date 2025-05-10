import java.io.*;
import java.util.*;

// https://codeforces.com/contest/1491/problem/C

public class Pekora {
    


    public static void solve(FastReader fr){
        int n;
        n = fr.nextInt();
        int[] s = new int[n];
        int[] jumps = new int[n];
        Arrays.fill(jumps,0);

        for (int i=0;i<n;++i) s[i] = fr.nextInt();
        long solution = 0;
        for (int i=0;i<n;++i){
            long current=0;
            if (s[i]>n-i-1 && s[i]>1){
                current += s[i]-(n-i-1);
                s[i]=n-i-1;
                if (s[i]==0) current--;
            }
            while (s[i]>1){
                jumps[i+s[i]]++;
                s[i]--;
                current++;
            }
            if (jumps[i]<=current) current-=jumps[i];
            else {
                if (i<n-1) jumps[i+1]+= jumps[i]-current;
                current=0;
            }
            solution+=current;
        }
        System.out.println(solution);
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
