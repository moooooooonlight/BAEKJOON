import java.util.Scanner;
import java.util.Stack;

public class Main{
    public static void main(String[] args) {
        Scanner scanner  = new Scanner(System.in);
        int N = scanner.nextInt();
        int count = 0;
        Stack<Integer> stack = new Stack<>();

        for(int i=0;i<N;++i){
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if(stack.isEmpty()){
                stack.add(y);
            }else {
                int o = stack.peek();
                if(o<y){
                    stack.add(y);
                }else if(o>y){
                    while(o>y){
                        stack.pop();
                        count++;
                        if(stack.isEmpty()) break;
                        o = stack.peek();
                    }
                    if(o!=y){
                        stack.add(y);
                    }
                }
            }
        }
        while(!stack.isEmpty()){
            int k = stack.pop();
            if(k!=0) count++;
        }
        System.out.println(count);
    }
}
