import java.io.*;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br;
    private static BufferedWriter bw;
    private static StringTokenizer st;
    private static int parent[];
    private static int n,m;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n];
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        int a, b;
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());


            if(union(a,b)){
                bw.write(i+1+"");
                bw.flush();
                bw.close();
                return ;
            }
        }


        bw.write("0");
        bw.flush();
        bw.close();
    }

    public static boolean union(int a, int b){
        int p1 = find(a);
        int p2 = find(b);

        if(p1<p2){
            parent[p2] = p1;
            return false;
        }else if(p1>p2){
            parent[p1] = p2;
            return false;
        }else{
            return true;
        }
    }

    public static int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
}
