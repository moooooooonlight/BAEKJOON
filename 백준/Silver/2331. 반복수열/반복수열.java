import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    private static int a,p;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());

        a = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());
        List<Integer> list = new ArrayList<>();

        list.add(a);
        int next = transfer(a);
        list.add(next);
        while(true){
            next = transfer(next);
            if(list.contains(next)){
                break;
            }
            list.add(next);
        }
        System.out.println(list.indexOf(next));
    }

    private static int transfer(int x){
        int sum = 0;
        String[] numberStr = String.valueOf(x).split("");
        for(int i=0;i<numberStr.length;i++){
            sum += pow(Integer.parseInt(numberStr[i]), p);
        }
        return sum;
    }

    private static int pow(int x, int y){
        return (int) Math.pow(x, y);
    }
}
