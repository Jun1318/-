#include<stdio.h>
#include<stdlib.h>

int main(void){
	FILE* fp;
	char filename[32];
	char** maze;
	int nRows, nColumns;
	
	printf("파일 이름을 입력하세요 : ");
	scanf("%s", filename);
	
	if((fp = fopen(filename, "r")) ==NULL){
		printf("입력하신 이름의 파일이 없습니다.\n");
		exit(1);
	}
	
	fscanf(fp, "%d", &nRows);
	fscanf(fp, "%d", &nColumns);
	
	maze = (char**)malloc(sizeof(char*) *nRows);
	for(int i=0; i<nRows; i++)
		maze[i] = (char*)malloc(sizeof(char) *nColumns);
		
	fgetc(fp);
	
	for(int i=0; i<nRows; i++){
		for(int j=0; j<nColumns; j++)	maze[i][j] = fgetc(fp);
		fgetc(fp);
	}
	
	for(int i=0; i<nRows; i++){
		for(int j=0; j<nColumns; j++)	printf("%c", maze[i][j]);
		printf("\n");
	}
	
	free(maze);
}
