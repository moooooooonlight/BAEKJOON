import java.io.*;
import java.util.StringTokenizer;

public class Main{
    private static BufferedReader br;
    private static BufferedWriter bw;
    private static StringTokenizer st;
    private static int[] array;
    private static Node[] tree;
    private static int n,m;
    private static int min ,max;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        array = new int[n + 1];
        tree = new Node[n*4];
        for(int i=1;i<=n;i++){
            array[i] = Integer.parseInt(br.readLine());
        }


        init(1,n,1); // 각 위치별 최소 최대값 구하기

        int start,end;
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());

            Node result = result(1,n,1,start, end);
            bw.write(result.min + " " + result.max+"\n");

        }
        bw.flush();
        bw.close();
    }

    public static Node result(int start, int end, int index, int left, int right){
        if (left > end || right < start){
            return new Node(Integer.MAX_VALUE, 0);
        }
        if(left<=start && end<=right){
            return tree[index];
        }
        int mid = (start + end) / 2;
        Node L = result(start, mid, index*2, left, right);
        Node R = result(mid+1, end, index*2+1, left, right);
        min = (L.min < R.min) ? L.min : R.min;
        max = (L.max > R.max) ? L.max : R.max;
        return new Node(min, max);
    }

    public static Node init(int start,int end,int index){
        if(start == end){
            tree[index] = new Node(array[start], array[start]);
            return tree[index];
        }
        int mid = (start + end)/2;
        Node L = init(start, mid, index * 2);
        Node R = init(mid + 1, end, index * 2 + 1);
        min = (L.min < R.min) ? L.min : R.min;
        max = (L.max > R.max) ? L.max : R.max;
        tree[index] = new Node(min, max);
        return tree[index];
    }

    public static class Node{
        int min;
        int max;
        public Node(int min, int max){
            this.max = max;
            this.min = min;
        }
    }
}