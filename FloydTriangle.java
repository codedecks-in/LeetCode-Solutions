package com.assignments;

import java.util.Scanner;

public class FloydTriangle {

	public static void main(String[] args) {
		int row,col=1,pDigit=1;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of rows : ");
		row = sc.nextInt();
		for(int i=1;i<=row;i++)
		{
			for (int k=1;k<=col;k++)
			{
				System.out.print(pDigit+" ");
				pDigit++;
			}
			System.out.println();
			col++;
		}
	}

}
