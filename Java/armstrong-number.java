import java.util.Scanner;

/**
 * 
 *	1134. Armstrong Number
 *	The k-digit number N is an Armstrong number if and only if the kth power of each digit sums to N.
 *	Given a positive integer N, return true if and only if it is an Armstrong number.
 *
 */
class ArmstrongNum {

	/* driver function commented
  public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		int N = kb.nextInt();
		
		int k = length(N);
		
		System.out.println(isArmstrongNumber(N, k));
		
		kb.close();
	}
  */

	public static int length(int N) {
		int length = 0;

		while (N != 0) {
			N = N / 10;
			length++;
		}

		return length;
	}

	public static boolean isArmstrongNumber(int N, int k) {
		long powerSum = 0;
		int n = N;
		
		while (n != 0) {
			int rem = n % 10;

			powerSum += (int) Math.pow(rem, k);
			
			n /= 10;
		}
		System.out.println(powerSum);
		return (powerSum==N);
	}
  
}
