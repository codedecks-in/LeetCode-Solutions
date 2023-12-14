class Solution {
    public String oddString(String[] words) {
        int matchesFirst = 0;
        int mismatchIdx = -1;
        for (int i = 1; i < words.length; i++) {
            if (matchesDiff(words[0], words[i])) {
                matchesFirst++;
            } else {
                mismatchIdx = i;
            }
        }
        if (matchesFirst == 0) {
            return words[0];
        }
        return words[mismatchIdx];
    }

    private static boolean matchesDiff(String a, String b) {
        for (int i = 0; i < a.length() - 1; i++) {
            if (a.charAt(i + 1) - a.charAt(i) != b.charAt(i + 1) - b.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}
