import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static int N;
    static int[] arr;
    static boolean[] visited;
    static int max = 0;
    static ArrayList<Integer> result = new ArrayList<>();
    static Stack<Integer> stack = new Stack<>();
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        arr = new int[N];
        visited = new boolean[N];
        for (int i = 0; i < N; ++i)
            arr[i] = scanner.nextInt();

        max  = 0;
        DFS(0);

        System.out.println(max);

    }
    static public void DFS(int count){
        if(count==N){
            max = Math.max(max, getResult());
            return;
        }

        for(int i=0;i<N;++i){
            if(!visited[i]){
                visited[i] = true;
                result.add(arr[i]);
                // 방문안한 친구들 다 stack에 넣어주기.
                DFS(count+1);
                visited[i] = false;
                result.remove(result.size()-1);
            }
        }
    }
    static public  int getResult(){
        int sum=0;
        for(int i=0; i<N-1; i++){
            sum += Math.abs(result.get(i)-result.get(i+1));
        }
        return sum;
    }
}
