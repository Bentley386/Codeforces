import java.io.*;
import java.util.*;

// https://codeforces.com/contest/1095/problem/F

public class MakeItConnected {
    
	static final int MOD = 998244353;
	static long result = 0;
	static ArrayList<Integer> reps;
	static ArrayList<Integer> sizes;

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
	
	static class SortEdges implements Comparator<ArrayList<Long>>{
		public int compare(ArrayList<Long> a, ArrayList<Long> b){
			if (a.get(2) == b.get(2)){
				if (a.get(1) == b.get(1)){
					if (a.get(0) < b.get(0)) return -1;
					else return 1;
				}
				if (a.get(1) < b.get(1)) return -1;
				else return 1;
			}
			if (a.get(2)<b.get(2)) return -1;
			else return 1;
		}
	}

	static int find(int a){
		while (reps.get(a) != a){
			a  = reps.get(a);
		}
		return a;
	}

	static boolean same(int a, int b){
		return find(a) == find(b);
	}
	static void unite(int a, int b){
		a = find(a);
		b = find(b);
		if (sizes.get(a) < sizes.get(b)){
			sizes.set(b, sizes.get(b)+sizes.get(a));
			reps.set(a,b);
		}
		else {
			sizes.set(a,sizes.get(a)+sizes.get(b));
			reps.set(b,a);
		}

	}
	public static void main(String[] args) {
        FastReader fr = new FastReader();
        int n,k;
		n = fr.nextInt(); k = fr.nextInt();
		ArrayList<ArrayList<Long>> edges = new ArrayList<>();
		ArrayList<Long> a = new ArrayList<Long>(n);
        reps = new ArrayList<Integer>(n+1); reps.add(0);
		sizes = new ArrayList<Integer>(n+1); sizes.add(0);

		int minIndex=0;
		long minValue = fr.nextLong();
		a.add(minValue);
		long curr;
		for (int i=1;i<n;++i){
			curr = fr.nextLong();
			if (curr < minValue) {
				minValue = curr;
				minIndex = i;
			}
			a.add(curr);
		}
        ArrayList<Long> temp;
        for (int i=0;i<n;++i) {
			if (i==minIndex) continue;
			temp = new ArrayList<Long>(3);
			temp.add((long) minIndex + 1l);
			temp.add((long)i + 1l);
			temp.add(minValue+a.get(i));
			edges.add(temp);
		}
		for (int i=1;i<=n;++i){
			reps.add(i);
			sizes.add(1);
		}
        for (int i=0;i<k;++i){
            temp = new ArrayList<Long>(3);
            temp.add(fr.nextLong());
            temp.add(fr.nextLong());
            temp.add(fr.nextLong());
            edges.add(temp);
		}


		SortEdges sorter = new SortEdges();
		Collections.sort(edges, sorter);

		int x,y;
		for (ArrayList<Long> e : edges){
			x = e.get(0).intValue();
			y = e.get(1).intValue();
			if (!same(x,y)) {
				unite(x,y);
				result += e.get(2);
			} 
		}

		System.out.println(result);
	}
}
