import java.util.*;

public class Day22StrSubsequenceCount {
    public static void main(String[] args){
        String str = "abacde";
        String[] words = {"a", "bb", "acd", "ace"};
        int count = numMatchingSequence(str,words);
        System.out.println(count);
    }

    public static int numMatchingSequence(String str, String[] words){
        int result = 0;
        Map<Character, List<Integer>> map = new HashMap<>();

        for(int i=0; i<str.length(); i++){
            map.putIfAbsent(str.charAt(i), new ArrayList<>());
            map.get(str.charAt(i)).add(i);  // It will add size of that character in map (occurence)
        }

        for (String word : words) {
            if (match(str, word, map, 0)) {
                result++;
            }
        }

        return result;
    }

    private static boolean match(String S, String word, Map<Character, List<Integer>> map, int startIndex) {
        if (word.length() == 0) return true;
        if (!map.containsKey(word.charAt(0))) return false;
        for (int start : map.get(word.charAt(0))) {
            if (start < startIndex) continue;
            String newWord = word.substring(1, word.length());
            return match(S, newWord, map, start + 1);
        }

        return false;
    }

}
