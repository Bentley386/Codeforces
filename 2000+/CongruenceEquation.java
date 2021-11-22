import java.io.*;
import java.util.*;

public class CongruenceEquation {
    
 
	public static void main(String[] args) {
        FastReader fr = new FastReader();
		long a,b,p,x;
		a = fr.nextLong(); b = fr.nextLong();
		p = fr.nextLong(); x = fr.nextLong();
		long result=0;
		long previous=1;
		for (long n=0;n<p-1;++n){
			long curr = (b*inverse(previous,p)) % p; // x = curr % p, x = n % (p-1)
			previous = (previous*a) % p;
			curr = crt(curr,n,p,p-1);
			if (curr>x) continue;
			if (curr>0) result++;
			result +=  (x-curr)/(p*(p-1));   
		}
		System.out.println(result);
	}

	static long crt(long a, long b, long p1, long p2){
		//solve x=a mod p1, x=b mod p2
		long interm = (b-a) % p2;
		long finalmod = p1*p2;
		if (interm<0) interm+=p2;
		interm = (interm*inverse(p1,p2)) % p2;
		return (a+ interm*p1 % finalmod) % finalmod;
	}
	static long inverse(long x, long p){
		return binarypow(x,p-2,p);
	}

	static long binarypow(long x, long y, long p){

		if (y==0) return 1l;
		long interm = binarypow(x,y/2,p);
		long result = (interm*interm) % p;
		if (y%2 == 1) result = (result*x)%p;
		return result;
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