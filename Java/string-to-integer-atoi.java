package com.bst.myexamples;

/**
 * Solution accepted on Leetcode with 7ms runtime and 39.2MB memory
 *
 * String to Integer (atoi)
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
 * Approach
 * 1.Prepare String that is having only +- sign and number value
 * Convert to BigInteger to compare value with 32bit signed Integer range and clamp if goes out of range
 * return output with 0 if no string number found or non number value found before any number value
 */

import java.math.*;
class StringToIntegerATOI {

    public static void main(String[] args){
      /* StringToIntegerATOI sta = new StringToIntegerATOI();
        System.out.println(sta.myAtoi("-20000000000000"));
*/

    }
    public int myAtoi(String s) {

        StringBuilder sb = new StringBuilder();

        for(int i=0; i<s.length(); i++){

            if(sb.length() == 0){
                if(Character.isWhitespace(s.charAt(i)))
                    continue;

                if('-' == s.charAt(i)){
                    sb.append("-");
                    continue;
                }

                if('+' == s.charAt(i)){
                    sb.append("+");
                    continue;
                }
            }

            if(Character.isDigit(s.charAt(i)))
                sb.append(s.charAt(i));
            else
                break;

        }

        String val = sb.toString().replace("+","");

        if(val.length() == 0 || val.equals("-"))
            val="0";

        BigInteger lvar = new BigInteger(val);

        if(lvar.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) > 0)
            lvar = BigInteger.valueOf(Integer.MAX_VALUE);
        else if(lvar.compareTo(BigInteger.valueOf(Integer.MIN_VALUE)) < 0)
            lvar = BigInteger.valueOf(Integer.MIN_VALUE);

        return lvar.intValue();
    }
}