import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringTokenizer st;
    private static int N,R,Q,U,V;
    private static ArrayList<ArrayList<Integer>> tree;
    private static int[] depth;
    private static int[] children;
    private static boolean[] visit;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        tree = new ArrayList<>();
        depth = new int[N+1];
        visit = new boolean[N+1];
        children = new int[N+1];

        for(int i=0;i<=N;i++){
            tree.add(new ArrayList<>());
        }

        for(int i=0;i<N-1;i++){
            st = new StringTokenizer(br.readLine());
            U = Integer.parseInt(st.nextToken());
            V = Integer.parseInt(st.nextToken());
            tree.get(U).add(V);
            tree.get(V).add(U);
        }

        //depth찾기
        depth[R] = 0;
        visit[R] = true;
        dfs(R,0);

        for(int i=0;i<Q;i++){
            U = Integer.parseInt(br.readLine());
            bw.write(children[U]+"\n");
        }
        bw.flush();
        bw.close();
    }

    public static int dfs(int R,int dep) {
        int sum = 0;
        int child = tree.get(R).size();
        for (int i = 0; i < tree.get(R).size(); i++) {
            int next = tree.get(R).get(i);
            if(!visit[next]){
                visit[next] = true;
                depth[next] = dep+1;
                children[R] += dfs(next,dep+1);
            }else{
                child--;
            }
        }
        if(child==0){
            children[R] = 1;
            return 1;
        }
        return ++children[R];
    }

    public static int bfs2(int R) {
        int cnt = 0;
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < tree.get(R).size(); i++) {
            int next = tree.get(R).get(i);
            if(depth[R]<depth[next]){
                queue.add(next);
                cnt++;
                visit[next] = true;
            }
        }

        while (!queue.isEmpty()) {
            int cur = queue.remove();

            for (int i = 0; i < tree.get(cur).size(); i++) {
                int next = tree.get(cur).get(i);
                if (!visit[next] && depth[cur]<depth[next]) {
                    queue.add(next);
                    cnt++;
                    visit[next] = true;
                }
            }
        }
        return cnt;
    }
}
