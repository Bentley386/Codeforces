import java.io.*;
import java.util.*;

public class YetAnotherSubarray {
    
    static final int MOD = 998244353;
	static long[] prefix;

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
	
	static long calcSum(int l, int r){
		if (l==0) return prefix[r];
		else return prefix[r]-prefix[l-1];
	}
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        int n,m,k;
		n=fr.nextInt(); m=fr.nextInt(); k = fr.nextInt();
		prefix = new long[n];
		if (m>n) m=n;
        int[] a = new int[n];
        for (int i=0;i<n;++i) a[i] = fr.nextInt();
		prefix[0]=a[0];
        for (int i=1;i<n;++i) prefix[i]=a[i]+prefix[i-1];

        long[] big = new long[n];
        for (int i=0;i<m-1;++i) {
            big[i] = 0;
		}
		big[m-1] = Long.max(0l,calcSum(0,m-1)-k);

        for (int i = m;i<n;++i){
			big[i] = Long.max(0l,big[i-m]+calcSum(i-m+1,i)-k);
        }

		long result=0;
        for (int i=0;i<n;++i){
			if (i<m-1){
				for (int j=0;j<m;++j){
					if (i+j>=n) break;
					result = Long.max(result,calcSum(i,i+j)-k);
				}
			}
			else {
				result = Long.max(result,big[i]);
	            for (int j=1;j<m;++j){
    	            if (i+j>=n) break;
        	        result = Long.max(result,big[i]+calcSum(i+1,i+j)-k);
				}
			}
        }
        System.out.println(result);
	}
}
