import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static BufferedWriter bw;
    private static StringTokenizer st;

    private static int[] array;
    private static int[] tree;
    private static int n,m;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        array = new int[n + 1];
        tree = new int[n * 4];
        for(int i=1;i<=n;i++){
            array[i] = Integer.parseInt(br.readLine());
        }

        init(1, n, 1);

        int a,b;
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            bw.write(search(1, n, 1, a,b)+"\n");
        }
        bw.flush();
        bw.close();
    }

    public static int init(int start, int end, int index){
        if(start == end){
            tree[index] = array[start];
            return tree[index];
        }
        int mid = (start+end)/2;
        tree[index] = Math.min(init(start, mid, index * 2), init(mid + 1, end, index * 2 + 1));
        return tree[index];
    }

    private static int search(int start, int end, int index, int left, int right) {
        if(left>end || start>right) {
            return Integer.MAX_VALUE;
        }

        if (left <= start && end <= right) {
            return tree[index];
        }

        int mid = (start+end)/2;
        int l = search(start,mid, index*2, left, right);
        int r = search(mid+1,end, index*2+1, left, right);
        return Math.min(l, r);
    }
}
