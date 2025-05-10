import java.io.*;
import java.util.*;

public class MathEx {
    
 
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        int n = fr.nextInt();
		HashMap<Integer,Integer> factors = new HashMap<Integer,Integer>();
		for (int i=2;i*i<=n;++i){
			int number=0;
			if (n%i==0){
				while (n%i==0){
					number++;
					n/=i;
				}
				factors.put(i, number);
			}
		}
		if (n>1) factors.put(n,1);
		int result=1;
		for (int x : factors.keySet()) result*=x;
		int numoperations;
		if (Collections.frequency(factors.values(), 1) == factors.size()) numoperations=0;
		else {
			int maxpower = Collections.max(factors.values());
			if (Collections.frequency(factors.values(), maxpower) == factors.size() && 
			(maxpower & (maxpower-1)) == 0){
				numoperations = 0;
				while (maxpower>1) {
					maxpower >>= 1;
					numoperations++;
				}
			} else {
				numoperations=1;
				if ((maxpower & (maxpower-1)) != 0) numoperations++; 
				while (maxpower>1){
					maxpower >>= 1;
					numoperations++;
				}
			}
		}
		System.out.println(result + " " + numoperations);
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