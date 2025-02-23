import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static int[] array, v;
    private static boolean[] visit;
    private static int sum = 0; // 전역 변수 초기화

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());

        array = new int[8];
        v = new int[8];
        visit = new boolean[8];
        for (int i = 0; i < 8; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        backTracking(0);

        System.out.println(sum);
    }

    private static void backTracking(int cnt) {
        if(cnt == 8){
            if(check()) sum++;
            return ;
        }

        for(int i=0;i<8;i++){
            if(visit[i]) continue;
            visit[i] = true;
            v[cnt] = array[i];
            backTracking(cnt+1);
            visit[i] = false;
        }
    }

    private static boolean check() {

        for(int i=0;i<8;i++){
            int a = i;
            int b = (i+1) % 8;
            int c = (i+2) % 8;

            if(v[a] * v[c] * Math.sqrt(2) > v[b] * (v[a] + v[c])){
                return false;
            }
        }
        return true;
    }
}
