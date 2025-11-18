import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br;
    private static StringTokenizer st;
    private static int[] parent;
    private static int[][] capacity;
    private static int[][] flow;
    private static Queue<Integer> queue;
    private static int n,p, source, sink, totalFlow = 0;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());

        int a,b;
        capacity = new int[n + 1][n + 1];
        flow = new int[n + 1][n + 1];
        parent = new int[n + 1];
        for(int i=0;i<p;i++){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            capacity[a][b] = 1;
        }

        source = 1;
        sink = 2;
        networkFlow();
        System.out.println(totalFlow);
    }

    private static void networkFlow() {
        queue = new LinkedList<>();

        while(true){
            for(int i=1;i<=n;i++){
                parent[i] = -1;
            }
            queue.add(source);
            parent[source] = source;

            while(!queue.isEmpty()){
                int cur = queue.remove();

                for(int i=1;i<=n;i++){
                    if(capacity[cur][i] - flow[cur][i] > 0 && parent[i]==-1){
                        queue.add(i);
                        parent[i] = cur;
                    }
                }
            }
            if(parent[sink]==-1) break;

            int amount = Integer.MAX_VALUE,p = sink;
            while(p!=source){
                amount = Math.min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
                p = parent[p];
            }
            totalFlow += amount;
            p = sink;

            while(p!=source){
                flow[parent[p]][p] += amount;
                flow[p][parent[p]] -= amount;
                p = parent[p];
            }

        }

    }
}
