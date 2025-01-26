import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main{

    private static BufferedReader br;
    private static BufferedWriter bw;
    private static StringTokenizer st;
    private static boolean[] primeNumberCheck;
    private static ArrayList<Integer> primeNumbers;
    private static int[][] cnt;
    private static int size = 1121;
    private static int t,n,k;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        primeNumberCheck = new boolean[size];
        primeNumbers = new ArrayList<>();
        cnt = new int[size*2][15]; // 크기가 달라야할 듯

        // input t
        t = Integer.parseInt(br.readLine());

        // prime check
        primeCheck();

        // calcul
        calcul();

        for(int i=0;i<t;i++){
            // input n,k
            input();

            bw.write(cnt[n][k]+"\n");
        }
        bw.flush();
        bw.close();
    }

    public static void calcul(){
        /**
         * prime 번호들로 조합을 만들어줘야하는데...
         * 하나씩 하면 시간이 너무 오래 걸림
         * T를 준 이유가 있을 듯.
         */
        cnt[0][0] = 1;
        for(int i=0;i<primeNumbers.size();i++){
            int prime = primeNumbers.get(i);
            for(int j=size;j>=prime;j--){
                for(int k=1;k<15;k++){
                    cnt[j][k]+=cnt[j-prime][k-1];
                }
            }
        }

    }
    private static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
    }

    public static void primeCheck(){

        for(int i=2;i<Math.sqrt(size);i++){
            for(int j=2*i;j<size;j+=i){
                primeNumberCheck[j] = true;
            }
        }
        for(int i=2;i<size;i++){
            if(!primeNumberCheck[i]){
                primeNumbers.add(i);
            }
        }

    }
}