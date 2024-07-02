#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#define count 3

enum figuretype { c, t, r};

struct figure{
	enum figuretype type;
	union{
		int radius;
		int tri_sides[3];
		int rac_sides[2];
	};
};

float area(struct figure *f){
	float area, s;
	switch(f->type){
		case c:
			area = 3.14*f->radius*f->radius;
			break;
		case t:
			s = (f->tri_sides[0]+f->tri_sides[1]+f->tri_sides[2])/2;
			area = sqrt(s*(s-f->tri_sides[0])*(s-f->tri_sides[1])*(s-f->tri_sides[2]));
			break;
		case r:
			area = f->rac_sides[0] * f->rac_sides[1];
			break;
	}
	return area;
}

void printfigure(struct figure *f){
	switch(f->type){
		case c:
			printf("원의 반지름 : %d, 원의 넓이 : %f\n", f->radius, area(f));
			break;
		case t:
			printf("삼각형 각 변 길이 : %d / %d / %d, 삼각형 넓이 : %f\n", f->tri_sides[0], f->tri_sides[1], f->tri_sides[2], area(f));
			break;
		case r: 
			printf("사각형 각 양변 길이 : %d / %d, 사각형 넓이 : %f\n", f->rac_sides[0], f->rac_sides[1], area(f));
			break;
	}
}

bool checktriangle(struct figure fig){
	int max = 0, othersum=0;
	
	for(int i=0;i<3;i++)
		if(fig.tri_sides[i]>max)
			max = fig.tri_sides[i];
	
	for(int i=0;i<3;i++)
		if(fig.tri_sides[i] != max)
			othersum += fig.tri_sides[i];

	if(max>othersum){
		printf("두변의 길이의 합은 가장 큰 변보다 커야함\n");
		return false;
	}
	
	else
		return true;
}

int main(void){
	struct figure fig[count];
	int type;
	
	for(int i=0;i<count;i++){
		printf("도형 종류를 입력하세요(c-circle, t-triangle, r-ractangle) : ");
		scanf("%c", &type);
		fflush(stdin);
		 switch(type){
		 	case 'c':
		 		fig[i].type = c;
		 		printf("반지름을 입력하세요 : ");
		 		scanf("%d", &fig[i].radius);
		 		fflush(stdin);
		 		break;
		 	case 't':
		 		printf("삼각형의 각 변을 입력하세요 : ");
		 		scanf("%d %d %d", &fig[i].tri_sides[0], &fig[i].tri_sides[1], &fig[i].tri_sides[2]);
		 		fflush(stdin);
		 		if(checktriangle(fig[i]) == false){
		 			printf("삼각형이 만들어지지 않음\n");
		 			continue;
				 }
				 fig[i].type = t;
		 		break;
		 	case 'r':
		 		fig[i].type = r;
		 		printf("직사각형의 변 2개를 입력하세요 : ");
		 		scanf("%d %d", &fig[i].rac_sides[0], &fig[i].rac_sides[1]);
		 		fflush(stdin);
		 		break;
		}
	}
	for(int i=0;i<count;i++)
			printfigure(&fig[i]);
}
