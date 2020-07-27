package com.assignments;

import java.util.Scanner;

public class Fibonacci {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the length of Fibonacci Series : ");
		int n = sc.nextInt();
		System.out.println("Enter first number of Fibonacci Series : ");
		int num1 = sc.nextInt();
		System.out.println("Enter second number of Fibonacci Series : ");
		int num2 = sc.nextInt();
		System.out.print(num1+" , "+num2+" , ");
		for(int i = 1;i<=n;i++)
		{
			int num3 = num1+num2;
			num1=num2;
			num2=num3;
			
			if (i==n)
				System.out.print(num3+" .");
			else
				System.out.print(num3+" , ");
		}

	}

}
