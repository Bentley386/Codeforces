import java.io.*;
import java.util.*;

// https://codeforces.com/contest/1280/problem/B

public class Beingawesomeism {
	
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
        int t,r,c;
        t = fr.nextInt();
        ArrayList<String> field;
        while (t-->0){
            r = fr.nextInt();
            c = fr.nextInt();
            field = new ArrayList<String>(r);
            boolean allA = true, allP=true;
            for (int i=0;i<r;++i){
                field.add(i,fr.nextLine());
                for (int j=0;j<c;++j){
                    if (allA && field.get(i).charAt(j) == 'P') allA=false;
                    if (allP && field.get(i).charAt(j) == 'A') allP=false;
                }
            }
            if (allA) {
                System.out.println("0");
                continue;
            }
            if (allP){
                System.out.println("MORTAL");
                continue;
            }
            boolean fullRow=false, fullRowStart=false;
            for (int i=0;i<r;++i){
                boolean full=true;
                for (int j=0;j<c;++j){
                    if (field.get(i).charAt(j) == 'P') {
                        full = false;
                        break;
                    }
                }
                if (full){
                    if (i==0 || i==r-1) {
                        fullRowStart=true;
                        break;
                    } else fullRow=true;
                }
            }

            for (int i=0;i<c;++i){
                boolean full=true;
                for (int j=0;j<r;++j){
                    if (field.get(j).charAt(i) == 'P') {
                        full = false;
                        break;
                    }
                }
                if (full){
                    if (i==0 || i==c-1) {
                        fullRowStart=true;
                        break;
                    } else fullRow=true;
                }
            }

            if (fullRowStart){
                System.out.println("1");
                continue;
            }
            if (fullRow){
                System.out.println("2");
                continue;
            }
            if (field.get(0).charAt(0) == 'A' || field.get(0).charAt(c-1) == 'A' || 
            field.get(r-1).charAt(0) == 'A' || field.get(r-1).charAt(c-1) == 'A'){
                System.out.println("2");
                continue;
            }
            boolean onEdge=false;
            for (int i=0;i<r;++i){
                if(field.get(i).charAt(0) == 'A' || field.get(i).charAt(c-1) == 'A'){
                    onEdge=true;
                    break;
                }
            }
            
            for (int i=0;i<c;++i){
                if(field.get(0).charAt(i) == 'A' || field.get(r-1).charAt(i) == 'A'){
                    onEdge=true;
                    break;
                }
            }

            if (onEdge) System.out.println("3");
            else System.out.println("4");
        }
	}
}
