import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static Point a,b,c,d;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        a = new Point(Long.parseLong(st.nextToken()),Long.parseLong(st.nextToken()));
        b = new Point(Long.parseLong(st.nextToken()),Long.parseLong(st.nextToken()));
        st = new StringTokenizer(br.readLine());
        c = new Point(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken()));
        d = new Point(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken()));

        long L1L2 = ccw(a,b,c) * ccw(a,b,d);
        long L2L1 = ccw(c,d,a) * ccw(c,d,b);

        if(L1L2 < 0 && L2L1 < 0){
            System.out.println(1);
        }else {
            System.out.println(0);
        }
    }

    public static long ccw(Point a,Point b,  Point c){
        return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x < 0 ? 1 : -1;
    }

    private static class Point{
        Long x,y;
        public Point(Long x, Long y){
            this.x = x;
            this.y = y;
        }
    }
}
