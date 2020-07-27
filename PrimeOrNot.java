package com.assignments;

import java.util.Scanner;

public class PrimeOrNot {

	public static void main(String[] args) {
		int divCount=2;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a number to check the number is prime or not : ");
		int n = sc.nextInt();
		
		for(int i=2;i<n;i++)
		{
			int rem=n%i;
			if(rem==0)
				divCount++;
		}
		
		if (divCount>2)
			System.out.println("The number is not Prime");
		else
			System.out.println("The number is Prime");
	}

}