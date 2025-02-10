import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    /**
     * 전기줄 최소로 없애기
     *
     */
    private static BufferedReader br;
    private static StringTokenizer st;
    private static int[] array;
    private static int[] longestLine;
    private static int n;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        longestLine = new int[n + 1];
        array = new int[n + 1];
        st = new StringTokenizer(br.readLine());

        for(int i=0;i<n;i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        int index = 0;
        for(int i=0;i<n;i++) {
            if(longestLine[index] < array[i]){
                index++;
                longestLine[index] = array[i];
            }else{
                longestLine[binarySearch(0,index, array[i])] = array[i];
            }
        }
        System.out.println(n-index);
    }

    private static int binarySearch(int left, int right, int target) {

        while(left<right){
            int mid = (left+right) / 2;
            if(longestLine[mid] < target){
                 left = mid + 1;
            }else
                right = mid;
        }
        return right;
    }
}
