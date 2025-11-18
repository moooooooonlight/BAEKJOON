import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        PriorityQueue<Integer> list = new PriorityQueue<>();
        LinkedList<Integer> result = new LinkedList<>();
        for(int i=0;i<N;++i){
            int x = scanner.nextInt();
            if(x>0){
                list.add(x);
            }else if(x==0){
                if(!list.isEmpty()){
                    int n = list.peek();
                    result.add(n);
                    list.poll();
                }else{
                    result.add(0);
                }
            }
        }

        while(!result.isEmpty()){
            System.out.println(result.remove());
        }
    }
}
