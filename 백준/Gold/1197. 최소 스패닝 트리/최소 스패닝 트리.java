import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int v,e;
    static int arr[];
    static int parent[];
    static Queue<Node> list;
    public static void main(String argv[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        v = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());
        arr = new int[v+1];
        list = new PriorityQueue<>();
        parent = new int[v+1];

        for(int i=0;i<=v;i++){
            parent[i] = i;
        }

        int a,b,c;
        for(int i=0;i<e;i++){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            list.add(new Node(a, b, c));
        }
        solve();

        bw.flush();
        bw.close();
    }
    static private void union(int x, int y){
        x = find_parent(x);
        y = find_parent(y);
        if(x != y){
            parent[y] = x;
        }
    }
    static private int find_parent(int x){
        if(x==parent[x]) return x;
        else return parent[x] = find_parent(parent[x]);
    }
    static private void solve() throws IOException {
        long result = 0;
        for(int i=1;i<=e;i++){
            Node cur = list.poll();
            // i랑 cur.y와 연결. 가중치 cur.v
            if(find_parent(cur.x)!=find_parent(cur.y)){
                union(cur.x,cur.y);
                result += cur.v;
            }
        }
        bw.write(result + "");
    }

    static class Node implements Comparable<Node>{
        int x;
        int y;
        int v;
        private Node(int x, int y, int v){
            this.x = x;
            this.y = y;
            this.v = v;
        }
        @Override
        public int compareTo(Node o) {
            return this.v - o.v;
        }
    }
}
