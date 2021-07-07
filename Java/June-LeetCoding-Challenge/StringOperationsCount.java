public class StringOperationsCount {
    public static void main(String[] args) {
        // NOTE: The following input values will be used for testing your solution.
        // Should return true if inserting a single char, deleting it or replacing it.
        System.out.println(isOneAway("abcde", "abcd"));  // should return true
        System.out.println(isOneAway("abde", "abcde"));  // should return true
        System.out.println(isOneAway("a", "a"));  // should return
        System.out.println(isOneAway("a", "b"));  // should return true
        System.out.println(isOneAway("abcdef", "abqdef"));  // should return true
        System.out.println(isOneAway("abcdef", "abccef"));  // should return true
        System.out.println(isOneAway("abcdef", "abcde"));  // should return true
        System.out.println(isOneAway("aaa", "abc"));  // should return false beacuse its two character replace
        System.out.println(isOneAway("abcde", "abc"));  // should return false
        System.out.println(isOneAway("abc", "abcde"));  // should return false
        System.out.println(isOneAway("abc", "bcc"));  // should return false
    }

    // Implement your solution below.
    public static Boolean isOneAway(String s1, String s2) {
        boolean bool = false;
        int s1Length = s1.length();
        int s2Length = s2.length();
        int editDistance = getEditDistance(s1, s2,s1Length,s2Length);
        if(editDistance>1)
                return false;
            else
                return true;
    }

    private static int getEditDistance(String s1, String s2,int s1Length, int s2Length) {

        if(s1Length==0){
            return s2Length;
        }
        if(s2Length==0){
            return s1Length;
        }
        if(s1.charAt(s1Length-1)== s2.charAt(s2Length-1))
            return getEditDistance(s1,s2,s1Length-1,s2Length-1);

        return 1+ min(getEditDistance(s1,s2,s1Length,s2Length-1)
                ,getEditDistance(s1,s2,s1Length-1,s2Length),
                getEditDistance(s1,s2,s1Length-1,s2Length-1));
    }

    private static int min(int x, int y, int z) {
        if (x <= y && x <= z)
            return x;
        if (y <= x && y <= z)
            return y;
        else
            return z;
    }
}
