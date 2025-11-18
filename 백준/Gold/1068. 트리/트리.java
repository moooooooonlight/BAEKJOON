import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static class Node{
        int current;
        Node left;
        Node right;
        public Node(int current, Node left, Node right){
            this.current = current;
            this.left = left;
            this.right = right;
        }
    }
    static int N;
    static int[] arr;
    static int[] parent;
    static int count =0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        arr = new int[N];  //자식 개수
        parent = new int[N]; //부모 가리키는 값.
        st = new StringTokenizer(br.readLine());
        int root=0;
        for (int i = 0; i < N; ++i) { // k가 부모를 가리킨다.
            int k = Integer.parseInt(st.nextToken());
            if(k==-1) root = i;
            if(k != -1)  arr[k]++;
            parent[i] = k;
        }

        st = new StringTokenizer(br.readLine());
        int cut = Integer.parseInt(st.nextToken());

        if(cut == root){  // 끊는 점과 0인 위치가 같으면.
            System.out.println(0);
            return;
        }

        for(int i=0;i<N;++i){ // 루트 노드 신경 써야함
            if(union(i,cut)){
                arr[i] = -1;
            }
        }

        arr[parent[cut]]--;

        for(int i=0;i<N;++i){
            if(arr[i]==0) count++;
        }
        System.out.println(count);
    }
    public  static  boolean union(int x, int y){
        int n = x;
        while(parent[n] != -1){
            if(n == y){
                return true;
            }else{
                n = parent[n];
            }
        }
        return false;
    }
}