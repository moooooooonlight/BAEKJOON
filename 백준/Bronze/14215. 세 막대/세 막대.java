import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        LinkedList<Integer> list = new LinkedList<>();
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        list.add(a);
        list.add(b);
        list.add(c);

        Collections.sort(list);
        a = list.get(0);
        b = list.get(1);
        c = list.get(2);

        if(a==b && b==c){
            System.out.println(a+b+c);
        } else if(a+b>c){
            System.out.println(a+b+c);
        }else {
            System.out.println(a+b+b+a-1);
        }
    }
}
