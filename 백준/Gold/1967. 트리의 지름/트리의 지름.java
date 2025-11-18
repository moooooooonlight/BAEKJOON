import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static boolean[] visited;
    static int MAX= 0;
    static ArrayList<point>[] list;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        list = new ArrayList[N+1];
        for(int i=1;i<=N;++i){
            list[i] = new ArrayList<>();
        }

        for(int i=0;i<N-1;++i){
            st = new StringTokenizer(br.readLine());
            int parent = Integer.parseInt(st.nextToken());
            int child = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            list[parent].add(new point(child,weight));
            list[child].add(new point(parent,weight));
        }
        for(int i=1;i<=N;++i){
            visited = new boolean[N+1];
            visited[i] = true;
            DFS(i,0);
        }
        System.out.println(MAX);
    }
    static class point{
        int y;
        int z;
        public point(int y, int z){
            this.y = y;
            this.z = z;
        }
    }
    static public void DFS(int node, int s){
        for(point p : list[node]){
            if(!visited[p.y]){
                visited[p.y] = true;
                DFS(p.y,s+p.z);
            }
        }
        MAX = Math.max(MAX,s);
    }
}
