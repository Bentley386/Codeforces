import java.io.*;
import java.util.*;

public class BitwiseFormula {

    public static String myBinary(String x, String y, String Op, int m){
        char[] a = x.toCharArray();
        char[] b = y.toCharArray();
        for (int i=0;i<m;++i) {
            if (Op.equals("OR")) {
                if (a[i]=='1' || b[i]=='1') a[i]='1';
                else a[i] = '0';
            }
            if (Op.equals("AND")) {
                if (a[i]=='0' || b[i] == '0') a[i] = '0';
                else a[i]='1';
            }
            if (Op.equals("XOR")) {
                if (a[i]==b[i]) a[i] = '0';
                else a[i] = '1';
            } 
        }
        return new String(a);
    }
	public static void main(String[] args) {
        //Why?????
        FastReader fr = new FastReader();
        int n = fr.nextInt(); int m = fr.nextInt();
        TreeMap<String,String> variables0 = new TreeMap<String,String>(); //For a given variable name find its value if chosen bits zero
        TreeMap<String,String> variables1 = new TreeMap<String,String>(); //For a given variable name find its value if chosen bits ones

        variables0.put("?",String.join("", Collections.nCopies(m, "0")));
        variables1.put("?",String.join("", Collections.nCopies(m, "1")));


        ArrayList<Integer> sums0 = new ArrayList<Integer>(Collections.nCopies(m, 0)); //total number of ones so far if chosen bits zero  
        ArrayList<Integer> sums1 = new ArrayList<Integer>(Collections.nCopies(m, 0)); //total number of ones so far if chosen bits one


        for (int i=0;i<n;++i){
            String[] operations = fr.nextLine().split(" ");
            if (operations.length == 3){
                variables0.put(operations[0],operations[2]);
                variables1.put(operations[0],operations[2]);
            } else {
                String x,y,result;
                x = variables0.get(operations[2]);
                y = variables0.get(operations[4]);
                result = myBinary(x,y,operations[3],m);
                variables0.put(operations[0],result);
                for (int j=0;j<m;++j){
                    if (result.charAt(j) == '1') sums0.set(j,sums0.get(j)+1);
                }
                x = variables1.get(operations[2]);
                y = variables1.get(operations[4]);
                result = myBinary(x,y,operations[3],m);
                variables1.put(operations[0],result);
                for (int j=0;j<m;++j){
                    if (result.charAt(j) == '1') sums1.set(j,sums1.get(j)+1);
                }
            }
        }

        for (int i=0;i<m;++i) {
            if (sums0.get(i)==sums1.get(i)) System.out.print("0");
            else if (sums0.get(i) < sums1.get(i)) System.out.print("0");
            else System.out.print("1");
        }
        System.out.println();
        for (int i=0;i<m;++i) {
            if (sums0.get(i)==sums1.get(i)) System.out.print("0");
            else if (sums0.get(i) < sums1.get(i)) System.out.print("1");
            else System.out.print("0");
        }
        System.out.println();
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
