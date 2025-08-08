import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        int[] nonincrease = new int[security.length];
        for (int i = 1; i < security.length - time; i++) {
            if (security[i] > security[i - 1]) {
                nonincrease[i] = 0;
            } else {
                nonincrease[i] = nonincrease[i - 1] + 1;
            }
        }

        int[] nondecrease = new int[security.length];
        for (int i = security.length - 2; i >= time; i--) {
            if (security[i] > security[i + 1]) {
                nondecrease[i] = 0;
            } else {
                nondecrease[i] = nondecrease[i + 1] + 1;
            }
        }

        ArrayList<Integer> result = new ArrayList<>();
        for (int i = time; i < security.length - time; i++) {
            if (nonincrease[i] >= time && nondecrease[i] >= time) {
                result.add(i);
            }
        }
        return result;

    }
}