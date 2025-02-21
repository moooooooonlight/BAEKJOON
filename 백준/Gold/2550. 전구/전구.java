import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br;
    private static BufferedWriter bw;
    private static StringTokenizer st;
    private static HashMap<Integer, Integer> map = new HashMap<>();
    private static int[] longestLine, startButton, origin, trace;
    private static int n;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());

        longestLine = new int[n + 1];
        startButton = new int[n + 1];
        origin = new int[n + 1];
        trace = new int[n + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            startButton[i] = Integer.parseInt(st.nextToken());
            map.put(startButton[i], i);
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            origin[i] = map.get(Integer.parseInt(st.nextToken()));
        }

        // LIS 구하기
        ArrayList<Integer> lis = new ArrayList<>();
        Arrays.fill(trace, -1);
        int[] pos = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            int target = origin[i];
            int idx = Collections.binarySearch(lis, target);
            if (idx < 0) idx = -(idx + 1);

            if (idx == lis.size()) {
                lis.add(target);
            } else {
                lis.set(idx, target);
            }

            pos[idx] = i;
            trace[i] = (idx > 0) ? pos[idx - 1] : -1;
        }

        bw.write(lis.size() + "\n");

        // LIS 역추적
        LinkedList<Integer> result = new LinkedList<>();
        for (int i = pos[lis.size() - 1]; i >= 0; i = trace[i]) {
            result.addFirst(startButton[origin[i]]);
        }
        Collections.sort(result);

        for (int val : result) {
            bw.write(val + " ");
        }
        bw.write("\n");

        bw.flush();
        bw.close();
    }
}
