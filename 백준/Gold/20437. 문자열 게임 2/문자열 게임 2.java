import java.awt.*;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    private static BufferedReader br;
    private static BufferedWriter bw;
    private static StringTokenizer st;
    private static int k;
    private static char[] chars;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        for(int i=0;i<t;i++){
            String input = br.readLine();
            chars = input.toCharArray();
            k = Integer.parseInt(br.readLine());
            int[] alphabet = new int[26];

            if(k==1){
                bw.write(1+" "+1+"\n");
                continue;
            }

            for(int j=0;j<input.length();j++){
                alphabet[chars[j]-'a']++;
            }

            //3번 가장 짧은 수열
            int indexMin = Integer.MAX_VALUE;
            int indexMax = Integer.MIN_VALUE;
            for(int j=0;j<input.length();j++){
                if(alphabet[chars[j]-'a']<k) continue;

                int cnt = 1;
                for(int l=j+1;l<input.length();l++){
                    if(chars[j] == chars[l]) cnt++;
                    if(cnt==k){
                        indexMin = Math.min(indexMin, l - j + 1);
                        indexMax = Math.max(indexMax, l - j + 1);
                        break;
                    }
                }
            }
            if(indexMin==Integer.MAX_VALUE || indexMax==Integer.MIN_VALUE){
                bw.write(-1+"\n");
            }else{
                bw.write(indexMin+" ");
                bw.write(indexMax+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
