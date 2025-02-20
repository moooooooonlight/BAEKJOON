import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static int n,m;
    private static int[][] map;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][m+1];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(map[i][j] > 0){
                    // 위 아래
                    cnt += 2;

                    // 북쪽
                    if(i==0){
                        cnt+=map[i][j];
                    }else{
                        if(map[i][j] - map[i-1][j] > 0){
                            cnt += map[i][j] - map[i-1][j];
                        }
                    }

                    //남쪽
                    if(i==n-1){
                        cnt+=map[i][j];
                    }else{
                        if(map[i][j] - map[i+1][j] > 0){
                            cnt += map[i][j] - map[i+1][j];
                        }
                    }

                    // 서쪽
                    if(j==0){
                        cnt+=map[i][j];
                    }else{
                        if(map[i][j] - map[i][j-1] > 0){
                            cnt += map[i][j] - map[i][j-1];
                        }
                    }

                    // 동쪽
                    if(j==m-1){
                        cnt+=map[i][j];
                    }else{
                        if(map[i][j] - map[i][j+1] > 0){
                            cnt += map[i][j] - map[i][j+1];
                        }
                    }
                }
            }
            sum+=cnt;
        }
        System.out.println(sum);
    }
}
