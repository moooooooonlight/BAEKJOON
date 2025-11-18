import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br;
    private static StringTokenizer st;
    private static int[][] dice;
    private static int n, result;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        // 입력 받기
        dice = new int[n + 1][7];
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=6;j++){
                dice[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 위에서 부터 재귀수행
        backtracking(1, 6,1,0);
        backtracking(2, 4,1,0);
        backtracking(3, 5,1,0);
        backtracking(6, 1,1,0);
        backtracking(4, 2,1,0);
        backtracking(5, 3,1,0);
        System.out.println(result);
    }

    private static void backtracking(int top, int down, int depth, int cnt) {
        if(depth == n+1){
            result = Math.max(result, cnt);
            return;
        }

        // 옆면중에 가장 큰 수를 저장해서 넘긴다.
        int temp = 0;
        for(int i=1;i<=6;i++){
            if(i!=top && i!=down){
                temp = Math.max(temp, dice[depth][i]);
            }
        }

        if(depth!=n){
            for(int i=1;i<=6;i++){
                if(dice[depth+1][i]==dice[depth][top]) {
                    if(i==1){
                        backtracking(6,1,depth+1, cnt+temp);
                    }else if(i==2){
                        backtracking(4,2,depth+1, cnt+temp);
                    }else if(i==3){
                        backtracking(5,3,depth+1, cnt+temp);
                    }else if(i==4){
                        backtracking(2,4,depth+1, cnt+temp);
                    }else if(i==5){
                        backtracking(3,5,depth+1, cnt+temp);
                    }else if(i==6){
                        backtracking(1,6,depth+1, cnt+temp);
                    }
                }
            }
        }else{
            backtracking(0,0,depth+1, cnt+temp);
        }
    }
}
