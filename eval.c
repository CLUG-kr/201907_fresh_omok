#define _CRT_SECURE_NO_WARNINGS
#include "omok.h"

int eval(NODE * node) // 해당 노드가 가지고 있는 board의 가치를 평가하는 함수
{
	int i, j;
	int val = 0;
	int val2 = 0;

	//걍 가치 평가 함수 이중for문을 짱 많이 돌린다 (여기서 시간 되게 많이 소모할 것 같음)
	//소모시간 줄이려면 for문들 중에서 범위 같은 것들끼리 묶는 게 좋을 듯 
	//그러면 생각보다 가치평가에 많은 시간 안 쓸 것 같아 > 수정함
	//맘 같아선 하나의 함수로 묶고 검은돌/흰돌 함수로 나누고 싶지만... 그럼 시간 오래 걸리겠지?ㅜ,ㅜ
	//white가 높은것 2가 black, 3이 white

	for (i = 3; i < N - 3; i++)
	{
		for (j = 3; j < N - 3; j++)
		{
			//v●●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0)
				val += 8;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0)
				val += 8;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0)
				val += 8;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0)
				val += 8;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0)
				val += 8;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0)
				val += 8;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0)
				val += 8;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0)
				val += 8;

			//v○●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 )
				val += 5;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 )
				val += 5;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 )
				val += 5;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 )
				val += 5;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 )
				val += 5;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 )
				val += 5;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0)
				val += 5;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 )
				val += 5;

			//for black
			//v○●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0)
				val2 += 5;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0)
				val2 += 5;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0)
				val2 += 5;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0)
				val2 += 5;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0)
				val2 += 5;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0)
				val2 += 5;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0)
				val2 += 5;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0)
				val2 += 5;

			//v●●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0)
				val2 += 8;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0)
				val2 += 8;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0)
				val2 += 8;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0)
				val2 += 8;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0)
				val2 += 8;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0)
				val2 += 8;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0)
				val2 += 8;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0)
				val2 += 8;
		}
	}
	for (i = 4; i < N - 4; i++)
	{
		for (j = 4; j < N - 4; j++)
		{
			//●●●●●
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3)
				val += 9999;

			//for black
			//●●●●●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2)
				val2 += 9999;
		}
	}
	for (i = 5; i < N - 5; i++)
	{
		for (j = 5; j < N - 5; j++)
		{
			//○●●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0)
				val += 10;

			//○● ●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0)
				val += 10;

			//○●  ●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0)
				val += 10;

			//○●   ●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3)
				val += 10;

			//vv●●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0)
				val += 20;
			
			//○ ●●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0)
				val += 20;

			//○ ●  ● 
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3)
				val += 20;

			//○●●●vv
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0)
				val += 20;

			//○●●v●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0)
				val += 20;

			//○●v●●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0)
				val += 20;

			//○●v●v●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3)
				val += 20;

			//●v●●●○
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 2)
				val += 33;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 2)
				val += 33;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 2)
				val += 33;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 2)
				val += 33;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 2)
				val += 33;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 2)
				val += 33;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 2)
				val += 33;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 2)
				val += 33;

			//○●●●●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0)
				val += 35;

			//●v●●●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0)
				val += 40;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0)
				val += 40;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0)
				val += 40;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0)
				val += 40;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0)
				val += 40;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0)
				val += 40;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0)
				val += 40;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0)
				val += 40;

			//v●●●●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0)
				val += 1000;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0)
				val += 1000;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0)
				val += 1000;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0)
				val += 1000;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0)
				val += 1000;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0)
				val += 1000;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0)
				val += 1000;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0)
				val += 1000;

			//●●●●●●
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 3)
				val += 9999;

			//for black
			//vv●●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0)
				val2 += 20;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0)
				val2 += 20;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0)
				val2 += 20;

			//○●●●vv
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0)
				val2 += 20;

			//○●●v●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0)
				val2 += 20;

			//○●v●●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0)
				val2 += 20;

			//○●v●v●
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2)
				val2 += 20;

			//○●●●●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0)
				val2 += 35;

			//v●●●●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0)
				val2 += 1000;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0)
				val2 += 1000;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0)
				val2 += 1000;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0)
				val2 += 1000;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0)
				val2 += 1000;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0)
				val2 += 1000;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0)
				val2 += 1000;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0)
				val2 += 1000;

			//●v●●●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0)
				val2 += 40;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0)
				val2 += 40;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0)
				val2 += 40;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0)
				val2 += 40;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0)
				val2 += 40;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0)
				val2 += 40;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0)
				val2 += 40;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0)
				val2 += 40;

			//●v●●●○
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 3)
				val2 += 33;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 3)
				val2 += 33;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 3)
				val2 += 33;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 3)
				val2 += 33;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 3)
				val2 += 33;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 3)
				val2 += 33;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 3)
				val2 += 33;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 3)
				val2 += 33;

			//●●●●●●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 2)
				val2 += 9999;

			//○ ●  ● 
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2)
				val2 += 20;
		}
	}
	for (i = 6; i < N - 6; i++)
	{
		for (j = 6; j < N - 6; j++)
		{
			//○ ● ●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 0)
				val += 23;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 0)
				val += 23;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 0)
				val += 23;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 0)
				val += 23;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 0)
				val += 23;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 0)
				val += 23;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 0)
				val += 23;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 0)
				val += 23;

			//○ ● ● ○
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 2)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 2)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 2)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 2)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 2)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 2)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 2)
				val += 10;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 2)
				val += 10;

			//○ ●   ● 
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 3)
				val += 18;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 3)
				val += 18;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 3)
				val += 18;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 3)
				val += 18;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 3)
				val += 18;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 3)
				val += 18;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 3)
				val += 18;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 3)
				val += 18;

			//vv●v●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 0)
				val += 25;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 0)
				val += 25;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 3)
				val += 25;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 3)
				val += 25;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 0)
				val += 25;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 0)
				val += 25;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 0)
				val += 25;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 0)
				val += 25;

			//○●●vv●○
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 2)
				val += 20;

			//○●●vv●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0)
				val += 15;

			//○●vv●●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0)
				val += 15;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0)
				val += 15;

			//○v●●●vv
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 0)
				val += 30;

			//○v●●●v○
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 2)
				val += 20;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 2)
				val += 20;

			//vv●●●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 0)
				val += 30;

			//○●●v●●○
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 2)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 2)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 2)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 2)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 2)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 2)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 2)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 2)
				val += 32;

			//○●●v●●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0)
				val += 32;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0)
				val += 32;

			//v●●v●●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0)
				val += 35;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0)
				val += 35;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0)
				val += 35;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0)
				val += 35;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0)
				val += 35;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0)
				val += 35;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0)
				val += 35;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0)
				val += 35;

			//●●●●●●●
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 3)
				val += 9999;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 3)
				val += 9999;
			
			//for black
			//○ ● ●
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 0)
				val2 += 23;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 0)
				val2 += 23;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 0)
				val2 += 23;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 0)
				val2 += 23;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 0)
				val2 += 23;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 0)
				val2 += 23;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 0)
				val2 += 23;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 0)
				val2 += 23;

			//○ ● ● ○
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 3)
				val2 += 10;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 3)
				val2 += 10;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 3)
				val2 += 10;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 3)
				val2 += 10;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 3)
				val2 += 10;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 3)
				val2 += 10;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 3)
				val2 += 10;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 3)
				val2 += 10;

			//○ ●   ● 
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 2)
				val2 += 18;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 2)
				val2 += 18;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 2)
				val2 += 18;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 2)
				val2 += 18;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 2)
				val2 += 18;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 2)
				val2 += 18;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 2)
				val2 += 18;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 2)
				val2 += 18;

			//vv●v●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 0)
				val2 += 25;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 0)
				val2 += 25;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 2)
				val2 += 25;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 2)
				val2 += 25;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 0)
				val2 += 25;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 0)
				val2 += 25;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 0)
				val2 += 25;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 0)
				val2 += 25;

			//○●●vv●○
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 3)
				val2 += 20;

			//○●●vv●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0)
				val2 += 15;

			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0)
				val2 += 15;

			//○●vv●●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0)
				val2 += 15;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0)
				val2 += 15;

			//○v●●●vv
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 0)
				val2 += 30;

			//○v●●●v○
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 3)
				val2 += 20;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 3)
				val2 += 20;

			//vv●●●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 0)
				val2 += 30;

			//○●●v●●○
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 3)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 3)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 3)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 3)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 3)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 3)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 3)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 3)
				val2 += 32;

			//○●●v●●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0)
				val2 += 32;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0)
				val2 += 32;

			//v●●v●●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0)
				val2 += 35;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0)
				val2 += 35;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0)
				val2 += 35;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0)
				val2 += 35;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0)
				val2 += 35;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0)
				val2 += 35;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0)
				val2 += 35;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0)
				val2 += 35;

			//●●●●●●●
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 2)
				val2 += 9999;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 2)
				val2 += 9999;
		}
	}
	for (i = 7; i < N - 7; i++)
	{
		for (j = 7; j < N - 7; j++)
		{
			//vv●vv●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 3 && node->board[i + 7][j + 7] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 3 && node->board[i + 7][j - 7] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 0)
				val += 15;

			//○v●●v●vv
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 0)
				val += 30;

			//○v●●v●v○
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 2)
				val += 30;

			//○v●●vv●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 3 && node->board[i + 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 3 && node->board[i][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 3 && node->board[i + 7][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 3 && node->board[i + 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 3 && node->board[i - 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 3 && node->board[i][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 3 && node->board[i - 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 3 && node->board[i - 7][j + 7] == 0)
				val += 30;

			//○v●v●●vv
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 0)
				val += 30;

			//○v●vv●●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 3 && node->board[i + 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 3 && node->board[i][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 3 && node->board[i + 7][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 3 && node->board[i + 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 3 && node->board[i - 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 3 && node->board[i][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 3 && node->board[i - 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 3 && node->board[i - 7][j + 7] == 0)
				val += 30;

			//vv●v●●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 0)
				val += 30;

			//for black
			//vv●vv●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 2 && node->board[i + 7][j + 7] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 2 && node->board[i + 7][j - 7] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 0)
				val2 += 15;

			//vv●v●●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 0)
				val2 += 30;

			//○v●●v●vv
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 0)
				val2 += 30;

			//○v●●v●v○
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 3)
				val2 += 30;

			//○v●●vv●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 2 && node->board[i + 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 2 && node->board[i][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 2 && node->board[i + 7][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 2 && node->board[i + 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 2 && node->board[i - 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 2 && node->board[i][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 2 && node->board[i - 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 2 && node->board[i - 7][j + 7] == 0)
				val2 += 30;

			//○v●v●●vv
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 0)
				val2 += 30;

			//○v●vv●●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 2 && node->board[i + 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 2 && node->board[i][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 2 && node->board[i + 7][j + 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 2 && node->board[i + 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 2 && node->board[i - 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 2 && node->board[i][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 2 && node->board[i - 7][j - 7] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 2 && node->board[i - 7][j + 7] == 0)
				val2 += 30;
		}
	}
	for (i = 8; i < N - 8; i++)
	{
		for (j = 8; j < N - 8; j++)
		{
			//vv●vvv●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 3 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 3 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 3 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 3 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 3 && node->board[i - 7][j] == 0 && node->board[i - 8][j] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 3 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 3 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 0)
				val += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 3 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 0)
				val += 15;

			//○v●v●v●v○
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 3 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 2)
				val += 25;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 3 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 2)
				val += 25;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 3 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 2)
				val += 25;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 3 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 2)
				val += 25;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 3 && node->board[i - 7][j] == 0 && node->board[i - 7][j] == 2)
				val += 25;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 3 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 2)
				val += 25;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 3 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 2)
				val += 25;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 3 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 2)
				val += 25;

			//○v●v●v●vv
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 3 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 3 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 3 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 3 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 3 && node->board[i - 7][j] == 0 && node->board[i - 7][j] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 3 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 3 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 0)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 3 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 0)
				val += 30;

			//vv●vv●●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 3 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 3 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 3 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 3 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 3 && node->board[i - 7][j] == 0 && node->board[i - 8][j] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 3 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 3 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 3 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 0)
				val += 30;

			//vv●v●v●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 3 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 3 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 3 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 3 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 3 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 3 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 3 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 3 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 3 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 3 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 3 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 3 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 3 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 3 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 3 && node->board[i - 7][j] == 0 && node->board[i - 8][j] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 3 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 3 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 3 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 3 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 3 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 3 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 0)
				val += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 3 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 3 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 3 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 0)
				val += 30;

			//○●v●v●v●○
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 3 && node->board[i + 8][j] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 3 && node->board[i][j + 8] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 3 && node->board[i + 8][j + 8] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 3 && node->board[i + 8][j - 8] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 3 && node->board[i - 7][j] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 3 && node->board[i][j - 8] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 3 && node->board[i - 8][j - 8] == 2)
				val += 30;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 3 && node->board[i - 8][j + 8] == 2)
				val += 30;

			//○●v●v●v●v
			if (node->board[i][j] == 2 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 3 && node->board[i + 8][j] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 3 && node->board[i][j + 8] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 3 && node->board[i + 8][j + 8] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 3 && node->board[i + 8][j - 8] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 3 && node->board[i - 7][j] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 3 && node->board[i][j - 8] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 3 && node->board[i - 8][j - 8] == 0)
				val += 35;
			if (node->board[i][j] == 2 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 3 && node->board[i - 8][j + 8] == 0)
				val += 35;

			//v●v●v●v●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 3 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 3 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 3 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 3 && node->board[i + 8][j] == 0)
				val += 40;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 3 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 3 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 3 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 3 && node->board[i][j + 8] == 0)
				val += 40;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 3 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 3 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 3 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 3 && node->board[i + 8][j + 8] == 0)
				val += 40;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 3 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 3 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 3 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 3 && node->board[i + 8][j - 8] == 0)
				val += 40;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 3 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 3 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 3 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 3 && node->board[i - 7][j] == 0)
				val += 40;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 3 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 3 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 3 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 3 && node->board[i][j - 8] == 0)
				val += 40;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 3 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 3 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 3 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 3 && node->board[i - 8][j - 8] == 0)
				val += 40;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 3 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 3 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 3 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 3 && node->board[i - 8][j + 8] == 0)
				val += 40;

			//for black
			//vv●vvv●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 2 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 2 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 2 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 2 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 2 && node->board[i - 7][j] == 0 && node->board[i - 8][j] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 2 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 2 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 0)
				val2 += 15;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 2 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 0)
				val2 += 15;

			//○v●v●v●v○
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 2 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 3)
				val2 += 25;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 2 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 3)
				val2 += 25;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 2 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 3)
				val2 += 25;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 2 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 3)
				val2 += 25;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 2 && node->board[i - 7][j] == 0 && node->board[i - 7][j] == 3)
				val2 += 25;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 2 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 3)
				val2 += 25;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 2 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 3)
				val2 += 25;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 2 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 3)
				val2 += 25;

			//○v●v●v●vv
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 2 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 2 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 2 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 2 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 2 && node->board[i - 7][j] == 0 && node->board[i - 7][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 2 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 2 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 2 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 0)
				val2 += 30;

			//vv●vv●●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 2 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 2 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 2 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 2 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 2 && node->board[i - 7][j] == 0 && node->board[i - 8][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 2 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 2 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 2 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 0)
				val2 += 30;

			//vv●v●v●vv
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 0 && node->board[i + 2][j] == 2 && node->board[i + 3][j] == 0 && node->board[i + 4][j] == 2 && node->board[i + 5][j] == 0 && node->board[i + 6][j] == 2 && node->board[i + 7][j] == 0 && node->board[i + 8][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 0 && node->board[i][j + 2] == 2 && node->board[i][j + 3] == 0 && node->board[i][j + 4] == 2 && node->board[i][j + 5] == 0 && node->board[i][j + 6] == 2 && node->board[i][j + 7] == 0 && node->board[i][j + 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 0 && node->board[i + 2][j + 2] == 2 && node->board[i + 3][j + 3] == 0 && node->board[i + 4][j + 4] == 2 && node->board[i + 5][j + 5] == 0 && node->board[i + 6][j + 6] == 2 && node->board[i + 7][j + 7] == 0 && node->board[i + 8][j + 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 0 && node->board[i + 2][j - 2] == 2 && node->board[i + 3][j - 3] == 0 && node->board[i + 4][j - 4] == 2 && node->board[i + 5][j - 5] == 0 && node->board[i + 6][j - 6] == 2 && node->board[i + 7][j - 7] == 0 && node->board[i + 8][j - 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 0 && node->board[i - 2][j] == 2 && node->board[i - 3][j] == 0 && node->board[i - 4][j] == 2 && node->board[i - 5][j] == 0 && node->board[i - 6][j] == 2 && node->board[i - 7][j] == 0 && node->board[i - 8][j] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 0 && node->board[i][j - 2] == 2 && node->board[i][j - 3] == 0 && node->board[i][j - 4] == 2 && node->board[i][j - 5] == 0 && node->board[i][j - 6] == 2 && node->board[i][j - 7] == 0 && node->board[i][j - 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 0 && node->board[i - 2][j - 2] == 2 && node->board[i - 3][j - 3] == 0 && node->board[i - 4][j - 4] == 2 && node->board[i - 5][j - 5] == 0 && node->board[i - 6][j - 6] == 2 && node->board[i - 7][j - 7] == 0 && node->board[i - 8][j - 8] == 0)
				val2 += 30;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 0 && node->board[i - 2][j + 2] == 2 && node->board[i - 3][j + 3] == 0 && node->board[i - 4][j + 4] == 2 && node->board[i - 5][j + 5] == 0 && node->board[i - 6][j + 6] == 2 && node->board[i - 7][j + 7] == 0 && node->board[i - 8][j + 8] == 0)
				val2 += 30;

			//○●v●v●v●○
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 2 && node->board[i + 8][j] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 2 && node->board[i][j + 8] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 2 && node->board[i + 8][j + 8] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 2 && node->board[i + 8][j - 8] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 2 && node->board[i - 7][j] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 2 && node->board[i][j - 8] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 2 && node->board[i - 8][j - 8] == 3)
				val2 += 30;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 2 && node->board[i - 8][j + 8] == 3)
				val2 += 30;

			//○●v●v●v●v
			if (node->board[i][j] == 3 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 2 && node->board[i + 8][j] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 2 && node->board[i][j + 8] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 2 && node->board[i + 8][j + 8] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 2 && node->board[i + 8][j - 8] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 2 && node->board[i - 7][j] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 2 && node->board[i][j - 8] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 2 && node->board[i - 8][j - 8] == 0)
				val2 += 35;
			if (node->board[i][j] == 3 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 2 && node->board[i - 8][j + 8] == 0)
				val2 += 35;

			//v●v●v●v●v
			if (node->board[i][j] == 0 && node->board[i + 1][j] == 2 && node->board[i + 2][j] == 0 && node->board[i + 3][j] == 2 && node->board[i + 4][j] == 0 && node->board[i + 5][j] == 2 && node->board[i + 6][j] == 0 && node->board[i + 7][j] == 2 && node->board[i + 8][j] == 0)
				val2 += 40;
			if (node->board[i][j] == 0 && node->board[i][j + 1] == 2 && node->board[i][j + 2] == 0 && node->board[i][j + 3] == 2 && node->board[i][j + 4] == 0 && node->board[i][j + 5] == 2 && node->board[i][j + 6] == 0 && node->board[i][j + 7] == 2 && node->board[i][j + 8] == 0)
				val2 += 40;
			if (node->board[i][j] == 0 && node->board[i + 1][j + 1] == 2 && node->board[i + 2][j + 2] == 0 && node->board[i + 3][j + 3] == 2 && node->board[i + 4][j + 4] == 0 && node->board[i + 5][j + 5] == 2 && node->board[i + 6][j + 6] == 0 && node->board[i + 7][j + 7] == 2 && node->board[i + 8][j + 8] == 0)
				val2 += 40;
			if (node->board[i][j] == 0 && node->board[i + 1][j - 1] == 2 && node->board[i + 2][j - 2] == 0 && node->board[i + 3][j - 3] == 2 && node->board[i + 4][j - 4] == 0 && node->board[i + 5][j - 5] == 2 && node->board[i + 6][j - 6] == 0 && node->board[i + 7][j - 7] == 2 && node->board[i + 8][j - 8] == 0)
				val2 += 40;
			if (node->board[i][j] == 0 && node->board[i - 1][j] == 2 && node->board[i - 2][j] == 0 && node->board[i - 3][j] == 2 && node->board[i - 4][j] == 0 && node->board[i - 5][j] == 2 && node->board[i - 6][j] == 0 && node->board[i - 7][j] == 2 && node->board[i - 7][j] == 0)
				val2 += 40;
			if (node->board[i][j] == 0 && node->board[i][j - 1] == 2 && node->board[i][j - 2] == 0 && node->board[i][j - 3] == 2 && node->board[i][j - 4] == 0 && node->board[i][j - 5] == 2 && node->board[i][j - 6] == 0 && node->board[i][j - 7] == 2 && node->board[i][j - 8] == 0)
				val2 += 40;
			if (node->board[i][j] == 0 && node->board[i - 1][j - 1] == 2 && node->board[i - 2][j - 2] == 0 && node->board[i - 3][j - 3] == 2 && node->board[i - 4][j - 4] == 0 && node->board[i - 5][j - 5] == 2 && node->board[i - 6][j - 6] == 0 && node->board[i - 7][j - 7] == 2 && node->board[i - 8][j - 8] == 0)
				val2 += 40;
			if (node->board[i][j] == 0 && node->board[i - 1][j + 1] == 2 && node->board[i - 2][j + 2] == 0 && node->board[i - 3][j + 3] == 2 && node->board[i - 4][j + 4] == 0 && node->board[i - 5][j + 5] == 2 && node->board[i - 6][j + 6] == 0 && node->board[i - 7][j + 7] == 2 && node->board[i - 8][j + 8] == 0)
				val2 += 40;
		}
	}
	if (num == WHITE)
		return val - val2;
	else if (num == FALSE)
		return val2 - val;
}


