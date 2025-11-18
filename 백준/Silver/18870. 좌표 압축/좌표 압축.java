import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int MAX = 1000001, count=0;
        int[] input = new int[N];
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            input[i] = Integer.parseInt(st.nextToken());
            list.add(input[i]);
        }
        Collections.sort(list);

        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<N;++i){
            if(MAX!=list.get(i)){
                MAX = list.get(i);
                map.put(MAX,count++);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<N;++i){
            sb.append(map.get(input[i])).append(" ");
        }
        System.out.println(sb);
    }
}
