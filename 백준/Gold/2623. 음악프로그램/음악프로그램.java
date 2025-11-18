import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static ArrayList<ArrayList<Integer>> graph;
    private static int[] innerCount;
    private static Queue<Integer> zeroCountQueue;
    private static ArrayList<Integer> result;
    private static int n,m;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        // input n,m
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());


        // init graph
        innerCount = new int[n+1];
        zeroCountQueue = new LinkedList<>();
        result = new ArrayList<>();
        graph = new ArrayList<>();
        for(int i=0;i<=n;i++){
            graph.add(new ArrayList<>());
        }

        // input sequence
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int order = Integer.parseInt(st.nextToken());
            int parent = Integer.parseInt(st.nextToken());
            for(int j=1;j<order;j++){
                int next = Integer.parseInt(st.nextToken());
                graph.get(parent).add(next);
                innerCount[next]++;
                parent = next;
            }
        }


        // dfs;
        for(int i=1;i<=n;i++){
            if(innerCount[i]==0){
                zeroCountQueue.add(i);
            }
        }
        while(!zeroCountQueue.isEmpty()) {
            int start = zeroCountQueue.peek();
            zeroCountQueue.remove();

            result.add(start);

            dfs(start);
        }

        // cycle checking
        boolean check = true;
        for(int i=1;i<=n;i++){
            if(innerCount[i]>0){
                check = false;
            }
        }


        // output print
        if(check){
            for(int i=0;i<result.size();i++){
                System.out.println(result.get(i));
            }
        }else{
            System.out.println(0);
        }
    }

    public static void dfs(int start){
        // 그래프를 돌면서 제거된 아이로 부터 연결된 얘들 제거.
        for(int i=0;i<graph.get(start).size();i++){
            int next = graph.get(start).get(i);
            innerCount[next]--;
            if(innerCount[next]==0){
                zeroCountQueue.add(next);
            }
        }
    }
}
