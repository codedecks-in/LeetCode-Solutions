public class RomanToInteger{
    public static int GetNum(int num) {//gets the number assoicate with a roman character
        if (num == 'I' || num == 'i') {
            return 1;
        }
        if (num == 'V' || num == 'v') {
            return 5;
        }
        if (num == 'X' || num == 'x') {
            return 10;
        }
        if (num == 'L' || num == 'l') {
            return 50;
        }
        if (num == 'C' || num == 'c') {
            return 100;
        }
        if (num == 'D' || num == 'd') {
            return 500;
        }
        if (num == 'M' || num == 'm') {
            return 1000;
        }

        return -1;
    }

    public static int romanToNumber(String roman){//Converts a roman numerial into a number
        int results = 0;
        for (int i = 0; i < roman.length(); i++) {//iterate through all the characters
            int cur = GetNum(roman.charAt(i));//Gets the integer of the roman number
            if (cur == -1) {//checks if the cur num is -1, if it is -1, it means that it is an invalid character
                return -1;
            }
            if (i + 1 < roman.length()) {//checks if the next index is out of bounds
                int next = GetNum(roman.charAt(i + 1));//gets the next character character
                if (next == -1) {//checks if the cur num is -1, if it is -1, it means that it is an invalid character
                    return -1;
                }
                if (cur >= next) {//compares the current number to the next number
                    results += cur;//if it is bigger, simply add the current number
                }
                else {//if the current number is smaller than the next number
                    results += (next - cur);//subtract the next number by the current number
                    i++;//increment the index, since the next number has already been used
                }
            }
            else {//only here to add the last number to the results
                results += cur;//adds the last character to the results
            }
        }
        return results;//returns the result
    }
}