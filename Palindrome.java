package com.assignments;

import java.util.Scanner;

public class Palindrome {

	public static void main(String[] args) {
		int rem,rev=0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number to check if it is Palindrome number or not : ");
		int n = sc.nextInt();
		int temp = n;
		  while(n>0)
		  {
			  rem = n % 10;
			  rev = rev * 10 + rem;
			  n = n/10;
		  }
		  if (temp==rev)
			  System.out.println("The number is palindrome");
		  else
			  System.out.println("The number is not palindrome");
			  
	}
}
