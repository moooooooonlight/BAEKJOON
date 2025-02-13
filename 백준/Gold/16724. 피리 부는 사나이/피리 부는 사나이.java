import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;

    private static char[][] map;
    private static int n,m, cnt;
    private static boolean connect;
    private static boolean[][] visit;
    private static boolean[][] visited;
    private static ArrayList<Node> list;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        // 입력 받기
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        // 그래프로 만들기
        map = new char[n + 1][m + 1];
        visit = new boolean[n + 1][m + 1];
        visited = new boolean[n + 1][m + 1];
        for(int i=0;i<n;i++){
            String tmp = br.readLine();
            char[] temp = tmp.toCharArray();
            for(int j=0;j<m;j++){
                map[i][j] = temp[j];
            }
        }


        // 사이클이 만들어지는 부분을 찾아야함.
        list = new ArrayList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j]){
                    connect = false;
                    DFS(i,j);
                    for(int k=0;k<list.size();k++){
                        visited[list.get(k).x][list.get(k).y] = true;
                    }
                    list.clear();
                    if(!connect) {
                        cnt++;
                    }
                }
            }
        }
        System.out.println(cnt);
    }

    private static void DFS(int x, int y) {
        if(map[x][y]=='U'){
            if(!visited[x][y] && !visit[x][y]){
                list.add(new Node(x,y));
                visit[x][y] = true;
                if(x!=0)
                    DFS(x-1, y);
            }else if(visited[x][y]){
                connect = true;
            }
        }else if(map[x][y]=='D'){
            if(!visited[x][y] && !visit[x][y]){
                list.add(new Node(x,y));
                visit[x][y] = true;
                if(x!=n-1)
                    DFS(x+1, y);
            }else if(visited[x][y]){
                connect = true;
            }
        }else if(map[x][y]=='L'){
            if(!visited[x][y] && !visit[x][y]){
                list.add(new Node(x,y));
                visit[x][y] = true;
                if(y!=0)
                    DFS(x, y-1);
            }else if(visited[x][y]){
                connect = true;
            }
        }else if(map[x][y]=='R'){
            if(!visited[x][y] && !visit[x][y]){
                list.add(new Node(x,y));
                visit[x][y] = true;
                if(y!=m-1)
                    DFS(x, y+1);
            }else if(visited[x][y]){
                connect = true;
            }
        }
    }

    private static class Node{
        int x;
        int y;
        public Node(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
