import java.io.*;
import java.util.*;

// https://codeforces.com/contest/1270/problem/D

public class StrangeDevice {
    
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
        int k;
        fr.nextInt(); k=fr.nextInt();
        int current=1;
		ArrayList<Integer> answers = new ArrayList<>();
        System.out.print("? ");
        for (int i=2;i<=k+1;++i) System.out.print(i + " ");
        System.out.println();
        System.out.flush();
		fr.nextInt();
		answers.add(fr.nextInt());

        for (int i=0;i<k;++i){
            System.out.print("? ");
            for (int j=1;j<=k;++j){
                if (j>current) System.out.print(j+1  + " ");
                else System.out.print(j + " ");
            }
            System.out.println();
			System.out.flush();
			fr.nextInt();
			answers.add(fr.nextInt());
            current++;
		}
		int max = Collections.max(answers);
		System.out.println("! " + Collections.frequency(answers, max));
		System.out.flush();
	}
}
