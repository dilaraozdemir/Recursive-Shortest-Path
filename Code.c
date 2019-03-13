#include <stdio.h>

int pathFinder(int matrix[][12], int, int );
int asagiGit(int aMatrix[][12], int, int, int);
int sagaGit(int sMatrix[][12],int ,int ,int );
int solaGit(int solMatrix[][12], int, int , int );
int yukariGit(int yMatrix[][12], int , int , int);


int asagiGit(int aMatrix[][12], int  a1, int a2, int aCounter){
	
	if(a1 == 5)
		return 0;
	
	if (a1 + 1 == 5 && a2 == 11){
		printf("En kisa yol : %d", ++aCounter);
		return 1;
	}
	   		
	if (aMatrix[a1+2][a2]==0 && aMatrix[a1+1][a2+1]==0 && aMatrix[a1+1][a2-1]==0) 
		return 0;
	
	a1++;
	aCounter++;
	
	if (aMatrix[a1+1][a2] == 1){
		if(asagiGit(aMatrix, a1, a2, aCounter) > 0)
			return aCounter;
	}
		
	

	if (aMatrix[a1][a2+1] == 1){
		if(sagaGit(aMatrix, a1, a2, aCounter) > 0)
			return aCounter;
	}
		
	

	if (aMatrix[a1][a2-1] == 1){
		if(solaGit(aMatrix, a1, a2, aCounter) > 0)
			return aCounter;
	}
	return 0;
		
}
int sagaGit(int sMatrix[][12],int s1 ,int s2 ,int sCounter){
	
	if (s2 == 11)
		return 0;
	
	if (s1 == 5 && s2+1 == 11){
		printf("En kisa yol : %d", ++sCounter);
		return 1;
	}

	if (sMatrix[s1][s2 + 2] ==0 && sMatrix[s1+1][s2+1] == 0 && sMatrix[s1-1][s2+1] == 0 ) 
		return 0;
	
	s2++;
	sCounter++;

	if (sMatrix[s1+1][s2] == 1){
		if(asagiGit(sMatrix, s1, s2, sCounter) > 0 )
			return sCounter;
	}

	if (sMatrix[s1][s2+1] == 1){
		if(sagaGit(sMatrix, s1, s2, sCounter) > 0 )
			return sCounter;
	}

	if (sMatrix[s1-1][s2] == 1){
		if(yukariGit(sMatrix, s1, s2, sCounter) > 0 )
			return sCounter;
	}
		
}

int solaGit(int solMatrix[][12], int sol1, int sol2, int solCounter){
	
	if (sol2 == 0)
		return 0;
	

	if (solMatrix[sol1][sol2-2] == 0 && solMatrix[sol1-1][sol2-1] == 0 && solMatrix[sol1+1][sol2-1] == 0)
		return 0;
	
	sol2--;
	solCounter++;
	

	if (solMatrix[sol1+1][sol2] == 1){
		if(asagiGit(solMatrix,sol1, sol2, solCounter) > 0 )
			return solCounter;
	}
	
	

	if (solMatrix[sol1][sol2-1] == 1){
		if(solaGit(solMatrix, sol1, sol2, solCounter) > 0 )
			return solCounter;
	}
	

	if (solMatrix[sol1-1][sol2] == 1){
		if(yukariGit(solMatrix, sol1, sol2, solCounter) > 0 )
			return solCounter;
	}
	
	
	return 0;

}

int yukariGit(int yMatrix[][12], int y1, int y2, int yCounter){
	
	if (y1 == 0)
		return 0;

			
	if (yMatrix[y1-2][y2] == 0 && yMatrix[y1-1][y2+1] == 0 && yMatrix[y1-1][y2-1]  == 0)
		return 0;
	
	y1--;
	yCounter++; 
	
	

	if (yMatrix[y1][y2+1] == 1){
		if(sagaGit(yMatrix, y1, y2, yCounter) > 0 )
			return yCounter;

	}

	if (yMatrix[y1][y2-1] == 1){
		if(solaGit(yMatrix, y1, y2, yCounter) > 0 )
			return yCounter;
	}
	

	if (yMatrix[y1-1][y2] == 1){
		if(yukariGit(yMatrix, y1, y2, yCounter) > 0 )
			return yCounter;
	}


	return 0;

}
int pathFinder(int matrix[][12], int x, int y){
	int counter = 0;
	int move  = 0;
	

	if (matrix[x+1][y] == 1)
		counter = asagiGit(matrix, x, y, move);


	else if(matrix[x][y+1] == 1)
		counter = sagaGit(matrix, x, y, move);
		

	else if(matrix[x][y-1] == 1)
		counter = solaGit(matrix, x, y, move);
	

	else if(matrix[x-1][y] == 1)
		counter = yukariGit(matrix, x, y, move);
	
	return counter;
		
}
int main(){
	int x = 0, y = 0;
	int i,j;
	int maze[6][12]={	{1,0,1,1,1,1,1,1,1,1,1,1}, 
						{1,0,1,0,0,0,0,0,0,0,0,1},
						{1,0,1,1,0,0,0,0,0,0,0,1},
        				{1,0,0,1,0,0,0,0,0,0,0,1},
						{1,0,0,1,0,0,0,0,0,1,0,1},
						{1,1,1,1,1,1,1,1,1,1,1,1} };
	for(i=0; i<6; i++){
		for(j=0; j<12; j++){
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	
	pathFinder(maze, x, y);
													
}
