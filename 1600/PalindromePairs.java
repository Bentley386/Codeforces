import java.io.*;
import java.util.*;

public class PalindromePairs {
    
 
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        int n = fr.nextInt();
        long result=0;
        TreeMap<Integer,Integer> seen = new TreeMap();
        for (int i=0;i<n;++i){
            int curr = 0;
            for (char c : fr.nextLine().toCharArray()) {
                int index = c-'a';
                curr ^=  (1<<index);
            }
            result += seen.getOrDefault(curr, 0);
            for (int j=0;j<26;++j){
                result += seen.getOrDefault(curr^(1<<j), 0);
            }
            seen.put(curr, seen.getOrDefault(curr, 0)+1);
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