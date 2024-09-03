#include<stdio.h>
#include<stdlib.h>

enum Direction { DOWN, UP, LEFT, RIGHT};

typedef struct{
	int row, col;
};

Coord mEntrance;

Coord newCoord(int row, int col){
	Coord c = {row, col};
	return c;
}

Coord getEntrance(char** m, int rows, int columns){
	Coord entrance;
	
	for(int i=0; i<rows; i++)
		for(int j=0; j<columns; j++)
			if(m[i][j] =='I'){
				entrance = newCoord(i, j);
				return entrance;
			}
			
	printf("No entrance found!\n");
	exit(1);
}

void printMaze(char** maze, int rows, int columns){
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++)
			printf("%d", maze[i][j]);
		printf("\n");
	}
}

void dirToProceed(Coord cur, char** maze, Coord* poss, int rows, int columns){
	if(cur.row >= rows-1)
		poss[DOWN] = newCoord(-1, -1);
	else{
		if(maze[cur.row +1][cur.col] ==' ' || maze[cur.row+1][cur.col] =='O')	
			poss[DOWN] = newCoord(cur.row+1, cur.col);
		else 
			poss[DOWN] = newCoord(-1, -1);
	}
	
	if(cur.row <=0)
		poss[UP] = newCoord(-1, -1);
	else{
		if(maze[cur.row -1][cur.col] ==' ' || maze[cur.row-1][cur.col] =='O')	
			poss[UP] = newCoord(cur.row-1, cur.col);
		else 
			poss[UP] = newCoord(-1, -1);
	}
	
	if(cur.col <= 0)
		poss[LEFT] = newCoord(-1, -1);
	else{
		if(maze[cur.row][cur.col -1] ==' ' || maze[cur.row][cur.col -1] =='O')	
			poss[LEFT] = newCoord(cur.row, cur.col-1);
		else 
			poss[LEFT] = newCoord(-1, -1);
	}
	
	if(cur.col >= columns-1)
		poss[RIGHT] = newCoord(-1, -1);
	else{
		if(maze[cur.row][cur.col +1] ==' ' || maze[cur.row][cur.col +1] =='O')	
			poss[RIGHT] = newCoord(cur.row, cur.col+1);
		else 
			poss[RIGHT] = newCoord(-1, -1);
	}
}

char isEqual(Coord c1, Coord c2){
	if((c1.row == c2.row) && (c1.col ==c2.col))
		return 1;
	eles
		return 0;
}

Coord solveMaze(Coord cur, char** maze, int rows, int columns){
	Coord poss[4];
	
	Coord answer;
	
	if(cur.row ==-1 && cur.col ==-1)
		return cur;
	if(maze[cur.row][cur.col] =='O')
		return newCoord(-2, -2);
		
	maze[cur.row][cur.col] = '.';
	
	dirToProceed(cur, maze, poss, rows, columns);
	for(int i=0; i<4; i++){
		answer = solveMaze(poss[i], maze, rows, columns);
		
		if(answer.row ==-1 && answer.col ==-1)
			continue;
		if(answer.row ==-2 && answer.col ==-2)
			return answer;
	}
	
	maze[cur.row][cur.col] = ' ';
	return cur;
}

int main(void){
	FILE* fp;
	char filename[32];
	char** maze;
	int nRows, nColumns;
	
	printf("미로 파일의 이름을 입력하세요 : ");
	scanf("%s", filename);
	
	if((fp = fopen(filename, "r")) ==NILL){
		printf("미로 파일 찾지 못함\n");
		exit(1);
	}
	
	fscanf(fp, "%d", &nRows);
	fscanf(fp, "%d", &nColumns);
	
	maze= (char**)malloc(sizeof(char*) * nRows);
	for(int i=0; i<nColumns; i++)
		maze[i] = (char*)malloc(sizeof(char) * nColumns);
		
	fgetc(fp);
	for(int i=0; i<nRows; i++){
		for(int j=0; j<nColumns; j++)
			maze[i][j] = fgetc(fp);
		fgetc(fp);
	}
	fclose(fp);
	
	printMaze(maze, nRows, nColumns);
	
	mEntrance = getEntrance(maze, nRows, nColumns);
	Coord mExit = solveMaze(mEntrance, maze, nRows, nColumns);
	
	if(isEqual(mEntrance, mExit))
		printf("미로찾기 실패!\n");
	else{
		printf("미로 찾기 성공!\n");
		maze[mEntrance.row][mEntrance.col] = 'I';
		printMaze(maze, nROws, nColumns);
	}
	
	for(int i=0; i<nRows; i++)
		free(maze[i]);
	free(maze);
}
