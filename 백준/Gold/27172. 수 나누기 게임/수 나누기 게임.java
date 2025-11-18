import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/** : 문제 해결
 * 10만의 이중 for 구문 -> time over
 * a%b == 0 의 의미는 나눠지는지 -> a가 b의 배수인지?
 * 소수인지 확인 -> 소수라면 안나눠짐.
 * 소수가 아니라면 -> 계산?
 * 2~100,000 ->
 */
public class Main {
    private static BufferedReader br;
    private static BufferedWriter bw;
    private static StringTokenizer st;
    private static int[] cards;
    private static int[] score;
    private static boolean[] cardNumber;
    private static int size = 1000001, maxNumber;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // input n
        int n = Integer.parseInt(br.readLine());

        // input card number
        cards = new int[n];
        cardNumber = new boolean[size];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            cards[i] = Integer.parseInt(st.nextToken());
            cardNumber[cards[i]] = true;
            maxNumber = Math.max(maxNumber,cards[i]);
        }

        // fight
        score = new int[size];
        for(int i=0;i<n;i++){
            int x = cards[i];
            for(int j=x*2;j<=maxNumber;j+=x){
                if(cardNumber[j]){
                    score[x]++;
                    score[j]--;
                }
            }
        }

        // result
        for(int i : cards){
            bw.write(score[i]+" ");
        }

        bw.flush();
        bw.close();
    }

}
