package Lec23;

public class Permutation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = "abc";
		printPermutation(str, "");

	}

	public static void printPermutation(String ques, String ans) {
		if (ques.length() == 0) {
			System.out.println(ans);
			return;
		}

		for (int i = 0; i < ques.length(); i++) {

			char ch = ques.charAt(i);

			String ros = ques.substring(0, i) + ques.substring(i + 1);

			printPermutation(ros, ans + ch);

		}

	}

}
