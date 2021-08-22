import java.util.Scanner;
class QSort{
	public static void Sort(String a[],int m,int n){
		int i,j;
		String k,temp;
		if(m<n){
			i=m;
			j=n;k=a[m];
			do{
				do{
					i++;
				}while((i<n-1)&&(a[i].compareTo(k)<=1));

				do{
					j--;
				}while((j>m)&&(a[j].compareTo(k)>=1));

				if(i<j){
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}while(i<j);
			temp=a[j];
			a[j]=a[m];
			a[m]=temp;
			Sort(a,m,j);
			Sort(a,j+1,n);
		}
	}
	public static void main(String[] args) {
		int i,size;
		String[] a= new String[20];
		Scanner sc=new Scanner(System.in);
		System.out.println("NUMBER OF ELEMENTS:");
		size=sc.nextInt();
		System.out.println("ENTER ELEMENTS:");
		Scanner s=new Scanner(System.in);
		for (i=0;i<size ;i++ ) {
			a[i]=s.nextLine();
		}
		Sort(a,0,size);
		System.out.println("SORTED ELEMENTS:");
		for (i=0;i<size ;i++ ) {
			System.out.println(a[i]+" ");
		}

	}
}