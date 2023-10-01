import java.util.ArrayList;
import java.util.List;

public class GenerateParenthesis {
    public static void main(String[] args) {
        System.out.println(generateParenthesis(3));
        System.out.println(generateParenthesis(2));
    }
    public static List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<String>();
        generate(n,0,0,"",ans);
        return ans;
    }
    public static void generate(int n, int openBrace, int closeBrace, String s, List<String> ans){
        if(openBrace == n && closeBrace == n){
            ans.add(s);
            return;
        }
        if(openBrace < n){
            generate(n, openBrace+1, closeBrace, s+"(",ans);
        }
        if(closeBrace < openBrace){
            generate(n, openBrace, closeBrace+1, s+")",ans);
        }
    }
}
