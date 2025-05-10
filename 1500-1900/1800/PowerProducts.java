import java.io.*;
import java.util.*;

// https://codeforces.com/contest/1225/problem/D

public class PowerProducts {
    
    static final int MOD = 998244353;

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
    
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        int n,k;
        n = fr.nextInt(); k=fr.nextInt();
        ArrayList<Integer> a = new ArrayList<Integer>(n);
		for (int i=0;i<n;++i) a.add(i,fr.nextInt());

		ArrayList<Integer> sieve = new ArrayList<Integer>(Collections.nCopies(Collections.max(a)+10,0));
		
		for (int i=2;i<sieve.size();++i){
			if (sieve.get(i) != 0) continue;
			for (int j=2*i;j<sieve.size();j+=i){
				sieve.set(j,i);
			}
		}
		long pairs=0;
		HashMap<HashMap<Integer,Integer>,Integer> numbers = new HashMap<>();
		for (int inp : a){
			HashMap<Integer,Integer> factors = new HashMap<Integer,Integer>();
			int y=inp;
			while (y>1){
				if (sieve.get(y) == 0){
					factors.put(y,factors.getOrDefault(y, 0)+1);
					if (factors.get(y) == k) factors.remove(y);
					break;					
				}
				factors.put(sieve.get(y),factors.getOrDefault(sieve.get(y), 0)+1);
				if (factors.get(sieve.get(y)) == k) factors.remove(sieve.get(y)); 
				y/=sieve.get(y);
			}
			HashMap<Integer,Integer> toFind = new HashMap<Integer,Integer>();
			for (Map.Entry<Integer,Integer> ent : factors.entrySet()){
				toFind.put(ent.getKey(),k-ent.getValue());
			}

			if(numbers.containsKey(toFind)) pairs+= numbers.get(toFind);
			numbers.put(factors,numbers.getOrDefault(factors, 0)+1);
		}
		System.out.println(pairs);
		
	}
}
