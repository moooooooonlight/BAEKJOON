import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] range = new int[N];
        st = new StringTokenizer(br.readLine());
        range[0] = Integer.parseInt(st.nextToken());
        for(int i=1;i<N;++i){
            range[i] = range[i-1] + Integer.parseInt(st.nextToken());
        }

        int[] result = new int[M];
        for(int i=0;i<M;++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(a == 1){
                int x = range[b-1];
                result[i] = x;
                continue;
            }
            int x= range[b-1]-range[a-2];
            result[i] = x;
        }

        for(int i=0;i<M;++i)
            System.out.println(result[i]);

    }
}
