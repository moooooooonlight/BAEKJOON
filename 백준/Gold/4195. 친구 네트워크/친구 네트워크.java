import java.io.*;
import java.util.Map;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static BufferedWriter bw;
    private static StringTokenizer st;
    private static int[] parent;
    private static int[] level;

    private static int t,n,cnt;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        t = Integer.parseInt(br.readLine());


        int index = 0;
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < t; i++) {
            n = Integer.parseInt(br.readLine());

            //init
            parent = new int[n*2+1];
            level = new int[n*2+1];
            index = 0;
            map.clear();
            for(int j=0;j<n*2+1;j++) {
                parent[j] = j;
                level[j] = 1;
            }

            // union
            String friend1,friend2;
            int friendIndex1, friendIndex2;
            for(int j=0;j<n;j++){
                st = new StringTokenizer(br.readLine());
                friend1 = st.nextToken();
                friend2 = st.nextToken();

                if(!map.containsKey(friend1)){
                    map.put(friend1,index++);
                }
                if(!map.containsKey(friend2)){
                    map.put(friend2,index++);
                }


                // calcul count
                int cnt = union(map.get(friend1),map.get(friend2));


                bw.write(cnt+"\n");
            }
        }
        bw.flush();
        bw.close();
    }

    public static int union(int f1, int f2){
        int p1 = find(f1);
        int p2 = find(f2);

        if(p1 != p2){
            parent[p2] = p1;
            level[p1] += level[p2];
        }

        return level[p1];
    }

    private static int find(int f) {
        if(f != parent[f]){
            parent[f] = find(parent[f]);
        }
        return parent[f];
    }
}
