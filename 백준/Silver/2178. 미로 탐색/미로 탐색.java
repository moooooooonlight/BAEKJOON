import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int N;
    static int M;
    static int[][] arr;
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static Queue<point> queue = new LinkedList<>();
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        arr = new int[N][M];

        for(int i=0;i<N;++i){
            String l = scanner.next();
            String[] list = l.split("");
            for(int k=0;k<M;++k){
                arr[i][k] = Integer.parseInt(list[k]);
            }
        }

        BFS(0,0);

        System.out.println(arr[N-1][M-1]);
    }
    static class point{
        int x;
        int y;
        public point(int x,int y){
            this.x = x;
            this.y = y;
        }
    }
    static public void BFS(int x, int y){
        if(arr[x][y]==1){
            queue.add(new point(x,y));
            while(!queue.isEmpty()){
                point p = queue.poll();
                for(int i=0;i<4;++i){
                    int xx = p.x+dx[i];
                    int yy = p.y+dy[i];
                    if(xx>=0 && xx<N && yy>=0 && yy<M && arr[xx][yy]==1){
                        queue.add(new point(xx,yy));
                        arr[xx][yy] += arr[p.x][p.y];
                    }
                }
            }
        }
    }
}
