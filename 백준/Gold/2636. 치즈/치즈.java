import java.io.*;
import java.util.*;

/**
 * 가장자리를 인식
 *      ->
 */
public class Main {

    private static BufferedReader br;
    private static BufferedWriter bw;
    private static StringTokenizer st;
    private static int[][] map;
    private static boolean[][] visit;
    private static int n,m, hours, cnt;
    private static Queue<Node> queue;
    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1, 1, 0, 0,};
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visit = new boolean[n][m];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while(bfs(0,0)){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    visit[i][j] = false;
                }
            }
        }
        bw.flush();
        bw.close();
    }

    private static boolean bfs(int a, int b) throws IOException {
        ArrayList<Node> edge = new ArrayList<>();
        queue = new LinkedList<>();

        // 0,0부터 시작한 bfs면 외부를 찾을 수 있을
        // 그런데 이렇게 되면 day마다 계속 bfs를 실행해야함.
        queue.add(new Node(a, b));

        while(!queue.isEmpty()){
            Node cur = queue.peek();
            queue.remove();

            int x = cur.x;
            int y = cur.y;

            for(int i=0;i<4;i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;

                if(map[nx][ny]==1 && !visit[nx][ny]){
                    edge.add(new Node(nx, ny));
                    visit[nx][ny] = true;
                    continue;
                }

                if(map[nx][ny]==0 && !visit[nx][ny]){
                    visit[nx][ny] = true;
                    queue.add(new Node(nx, ny));
                }
            }
        }
        if(edge.size() == 0){
            bw.write(hours + "\n");
            bw.write(cnt + "\n");
            return false;
        }else{
            cnt = edge.size();
            hours++;
        }
        for(int i=0;i<edge.size();i++){
            Node cur = edge.get(i);
            map[cur.x][cur.y] = 0;
        }
        return true;
    }

    public static class Node{
        int x,y;
        public Node(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
