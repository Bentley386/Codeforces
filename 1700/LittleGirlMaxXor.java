import java.io.*;
import java.util.*;

public class LittleGirlMaxXor{
    
 
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        long l = fr.nextLong(); long r = fr.nextLong();
        if (l==r) System.out.println("0");
        else {
            for (long i = 63;i>=0;--i){
                if ( ((1l<<i)&r) != 0 && ((1l<<i)&l) == 0 ){
                    System.out.println((1l<<(i+1)) - 1l);
                    break;
                }
            }
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