package com.assignments;

import java.util.Scanner;

public class PerfectNumber {

	public static void main(String[] args) {
		int divPick,sum=0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number to check if the number is Perfect number or not : ");
		int num = sc.nextInt();
		for (int i=1;i<num;i++)
		{
			divPick=num%i;
			if (divPick==0)
				sum=sum+i;
			else
				continue;
			
		}
		if (sum==num)
			System.out.println("The number is perfect number.");
		else
			System.out.println("The number is not a perfect number.");

	}

}
