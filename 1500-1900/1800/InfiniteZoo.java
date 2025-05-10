import java.io.*;
import java.util.*;
 
// https://codeforces.com/contest/1491/problem/D

public class InfiniteZoo {
    
 
 
    public static boolean solve(int u, int v){ //u start, v target
        if (u>v) return false;
        int[] start = new int[30];
        int[] end = new int[30];
        for (int i=0;i<30;++i){
            start[i] = (((1<<i)&u) == 0) ? 0 : 1;
            end[i] = (((1<<i)&v) == 0) ? 0 : 1;
        }
        int count=0;
        for (int i=0;i<30;++i){
            if (end[i]==1) count++;
            if (start[i]==1) count--;
            if (count>0) return false;
        }
        return true;
    }
 
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        int q;
        q = fr.nextInt();
        int u,v;
        for (int i=0;i<q;++i){
            u = fr.nextInt(); v=fr.nextInt();
            if(solve(u,v)) System.out.println("YES");
            else System.out.println("NO");
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