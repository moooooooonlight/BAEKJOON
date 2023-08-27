import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static class Node{
        int current;
        Node left;
        Node right;
        public Node(int current, Node left, Node right){
            this.current = current;
            this.left = left;
            this.right = right;
        }
        public void insert(int k){
            if(k<this.current){
                if(this.left == null){this.left = new Node(k, null, null);}
                else{this.left.insert(k);}
            }else{
                if(this.right == null){this.right = new Node(k, null, null);}
                else{this.right.insert(k);}
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        Node node = new Node(N,null,null);
        while(true){
            String str = br.readLine();
            if(str == null || str.equals("")){
                break;
            }
            node.insert(Integer.parseInt(str));
        }
        postorder(node);
    }
    static public void postorder(Node node){
        if(node==null){
            return;
        }
        postorder(node.left);
        postorder(node.right);
        System.out.println(node.current);
    }
}
