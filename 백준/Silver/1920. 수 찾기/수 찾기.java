import java.io.*;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        HashMap<Integer,Integer> map = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;++i){
            int x= Integer.parseInt(st.nextToken());
            map.put(x,1);
        }
        st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<M;++i){
            int y = Integer.parseInt(st.nextToken());
            if(map.containsKey(y)){
                sb.append(1).append('\n');
            }else sb.append(0).append('\n');
        }
        System.out.println(sb);

    }
}
