#include <stdio.h>


//THIS PRINTBOARD CAN BE EDITED IN VARIOUS WAYS AS YOU WISH.
void printboard ( int d[3][3] ) {
	printf ("\t\t\t\t\t\t#################################\n\t\t\t\t\t\t#\t\t\t\t#");
	for ( int i = 0 ; i < 3 ; i++ ) {
		printf ("\n\t\t\t\t\t\t#\t****************\t#\n\t\t\t\t\t\t#\t");	
		for ( int k = 0 ; k < 3 ; k++ ) {
			printf ("* %c  ",d[i][k]);
		}
		printf ("\t#");
	}
	printf ("\n\t\t\t\t\t\t#\t****************\t#\n\t\t\t\t\t\t#\t\t\t\t#\n\t\t\t\t\t\t#\t\t\t\t#\n\t\t\t\t\t\t#################################\n");
}

void playerscan ( int d[3][3] , int valid ) {
	printf ("\n\t\t\t\t\t Player 1\n\t\t\t\t\tEnter the place (0-8): ") ;
	int choice;
	scanf ( "%d" ,&choice);
	if (( choice >= 0 && choice <= 8 ) && ( d[choice/3][choice%3] == ' ')) {
		d[choice/3][choice%3] = 'X';
	}
	else
	{
		printf ("INVALID MOVE TRY AGAIN \n\n");
		playerscan(d,1);
	}
}

void playerscan2 ( int d[3][3] , int valid ) {
	printf ("\n\t\t\t\t\t Player 2\n\t\t\t\t\tEnter the place (0-8): ") ;
	int choice;
	scanf( "%d" ,&choice);
	if (( choice >= 0 && choice <= 8 ) && ( d[choice/3][choice%3] == ' ')) {
		d[choice/3][choice%3] = 'O';
	}
	else
	{               
		printf("INVALID MOVE TRY AGAIN \n\n");
		playerscan2(d,1);
	}
}

int  wincheck ( int d[3][3] ) {
	int  c1_hor , c1_ver , c1_d1 , c1_d2 , c2_hor , c2_ver , c2_d1 , c2_d2 ;
	c1_hor = c1_ver = c1_d1 = c1_d2 = c2_hor = c2_ver = c2_d1 = c2_d2 = 0 ;
	for ( int i = 0 ; i < 3 ; i++ ) {
		//DIAGONALS CHECK [COUNTING] .
		if ( d[i][i] == 'X' ) c1_d1++;
		if ( d[i][2-i] == 'X' ) c1_d2++;
		if ( d[i][i] == 'O' ) c2_d2++;
		if ( d[i][2-i] == 'O' ) c2_d1++;
		//COLUMNS AND ROWS CHECK [ COUNTING ].		
		for ( int j = 0 ; j < 3 ; j++ ) {
			if ( d[i][j] == 'X' ) c1_hor++;
			if ( d[j][i] == 'X' ) c1_ver++;
			if ( d[i][j] == 'O' ) c2_hor++;
			if ( d[j][i] == 'O' ) c2_ver++;
		}
		//WIN CHECK IF ANY THREE ARE THERE.	
		if ( c1_hor == 3 || c1_ver == 3 || c1_d1 == 3 || c1_d2 == 3 ){
			printf ("\n\n\t\t\t\t\t\tPLAYER 1 WINS\n");
			return 0;
		}
		if (c2_hor == 3 || c2_ver == 3 || c2_d1 == 3 || c2_d2 == 3) {
			printf ("\n\n\t\t\t\t\t\tPLAYER 2 WINS\n");
			return 0; //USED FOR TERMINATING THE PROGRAM.
		}
		c1_hor = c1_ver = c2_hor = c2_ver = 0;
	}
	return 1;//AGAIN WERN 

}

int draw ( int d[3][3] ) {
	for ( int i = 0 ; i < 3 ; i++ ) {
		for ( int j = 0 ; j < 3 ; j++ ) {
			if ( d[i][j]==' ' ) {
				return 1;
			}
		}
	}
	return 0;
}

void game(int d[3][3])  {
	int turn =1;
	int check=1;
	while( check ) {
		if ( turn%2 == 1 ) playerscan(d,1);
		else playerscan2(d,1);
		printboard(d);
		turn++;
		check = wincheck(d);
		int dr = draw(d);    // CHECK AND RETURNS ZERO IF THERE ARE NO POSSIBLE MOVES.
		if ( dr == 0 ) {
			printf ( "\n\t\t\t\t\t\t\tDRAW MATCH\n\n");
			return;	
		}
	}
}

int main() {
	int d[3][3];
	for ( int i = 0 ; i < 3 ; i++ ) {
		for ( int j = 0 ; j < 3 ; j++ ) {
			d[i][j] = ' ' ;
		}
	}
	printboard(d); 
	printf ("\n\n\t\t\t\t\tPress Y to continue:  ");
	char s;
	scanf("%c",&s);
	if ( s == 'y' || s == 'Y' ) {
		game(d);	
	}	
	return 0;
}
