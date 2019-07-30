#include "omok.h"

void eval(int(*board_cal)[N], int(*board)[N]) // 해당 노드가 가지고 있는 board의 가치를 평가하는 함수
{
	int i, j;

	//걍 가치 평가 함수 이중for문을 짱 많이 돌린다 (여기서 시간 되게 많이 소모할 것 같음)
	//소모시간 줄이려면 for문들 중에서 범위 같은 것들끼리 묶는 게 좋을 듯 
	//그러면 생각보다 가치평가에 많은 시간 안 쓸 것 같아 > 수정함
	//맘 같아선 하나의 함수로 묶고 검은돌/흰돌 함수로 나누고 싶지만... 그럼 시간 오래 걸리겠지?ㅜ,ㅜ
	//white가 높은것 2가 black, 3이 white
	for (i = 4; i < N - 4; i++) {
		for (j = 4; j < N - 4; j++) {
			//●v●●●
			if (board[i][j] == 3 && board[i + 1][j] == 0 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 3)
				board_cal[i + 1][j] = board_cal[i + 1][j] + 100;
			if (board[i][j] == 3 && board[i][j + 1] == 0 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 3)
				board_cal[i][j + 1] = board_cal[i][j + 1] + 100;
			if (board[i][j] == 3 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3)
				board_cal[i + 1][j + 1] = board_cal[i + 1][j + 1] + 100;
			if (board[i][j] == 3 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3)
				board_cal[i + 1][j - 1] = board_cal[i + 1][j - 1] + 100;
			if (board[i][j] == 3 && board[i - 1][j] == 0 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 3)
				board_cal[i - 1][j] = board_cal[i - 1][j] + 100;
			if (board[i][j] == 3 && board[i][j - 1] == 0 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 3)
				board_cal[i][j - 1] = board_cal[i][j - 1] + 100;
			if (board[i][j] == 3 && board[i - 1][j - 1] == 0 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3)
				board_cal[i - 1][j - 1] = board_cal[i - 1][j - 1] + 100;
			if (board[i][j] == 3 && board[i - 1][j + 1] == 0 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3)
				board_cal[i - 1][j + 1] = board_cal[i - 1][j + 1] + 100;

			//for black
			if (board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2)
				board_cal[i + 1][j] = board_cal[i + 1][j] - 100;
			if (board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2)
				board_cal[i][j + 1] = board_cal[i][j + 1] - 100;
			if (board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2)
				board_cal[i + 1][j + 1] = board_cal[i + 1][j + 1] - 100;
			if (board[i][j] == 2 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2)
				board_cal[i + 1][j - 1] = board_cal[i + 1][j - 1] - 100;
			if (board[i][j] == 2 && board[i - 1][j] == 0 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 2)
				board_cal[i - 1][j] = board_cal[i - 1][j] - 100;
			if (board[i][j] == 2 && board[i][j - 1] == 0 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 2)
				board_cal[i][j - 1] = board_cal[i][j - 1] - 100;
			if (board[i][j] == 2 && board[i - 1][j - 1] == 0 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2)
				board_cal[i - 1][j - 1] = board_cal[i - 1][j - 1] - 100;
			if (board[i][j] == 2 && board[i - 1][j + 1] == 0 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2)
				board_cal[i - 1][j + 1] = board_cal[i - 1][j + 1] - 100;

			//●v●●● //뒤집힌 경우
			if (board[i][j] == 3 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 0 && board[i + 4][j] == 3)
				board_cal[i + 3][j] = board_cal[i + 3][j] + 100;
			if (board[i][j] == 3 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 0 && board[i][j + 4] == 3)
				board_cal[i][j + 3] = board_cal[i][j + 3] + 100;
			if (board[i][j] == 3 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 3)
				board_cal[i + 3][j + 3] = board_cal[i + 3][j + 3] + 100;
			if (board[i][j] == 3 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 3)
				board_cal[i + 3][j - 3] = board_cal[i + 3][j - 3] + 100;
			if (board[i][j] == 3 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 0 && board[i - 4][j] == 3)
				board_cal[i - 3][j] = board_cal[i - 3][j] + 100;
			if (board[i][j] == 3 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 0 && board[i][j - 4] == 3)
				board_cal[i][j - 3] = board_cal[i][j - 3] + 100;
			if (board[i][j] == 3 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 0 && board[i - 4][j - 4] == 3)
				board_cal[i - 3][j - 3] = board_cal[i - 3][j - 3] + 100;
			if (board[i][j] == 3 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 0 && board[i - 4][j + 4] == 3)
				board_cal[i - 3][j + 3] = board_cal[i - 3][j + 3] + 100;

			//for black
			if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0 && board[i + 4][j] == 2)
				board_cal[i + 3][j] = board_cal[i + 3][j] - 100;
			if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0 && board[i][j + 4] == 2)
				board_cal[i][j + 3] = board_cal[i][j + 3] - 100;
			if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 2)
				board_cal[i + 3][j + 3] = board_cal[i + 3][j + 3] - 100;
			if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 2)
				board_cal[i + 3][j - 3] = board_cal[i + 3][j - 3] - 100;
			if (board[i][j] == 2 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 0 && board[i - 4][j] == 2)
				board_cal[i - 3][j] = board_cal[i - 3][j] - 100;
			if (board[i][j] == 2 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 0 && board[i][j - 4] == 2)
				board_cal[i][j - 3] = board_cal[i][j - 3] - 100;
			if (board[i][j] == 2 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 0 && board[i - 4][j - 4] == 2)
				board_cal[i - 3][j - 3] = board_cal[i - 3][j - 3] - 100;
			if (board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 0 && board[i - 4][j + 4] == 2)
				board_cal[i - 3][j + 3] = board_cal[i - 3][j + 3] - 100;

			//v●●●v
			if (board[i][j] == 0 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 0) {
				board_cal[i-1][j] = board_cal[i-1][j] + 70;
				board_cal[i + 5][j] = board_cal[i + 5][j] + 70;
			}
			if (board[i][j] == 0 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 0) {
				board_cal[i][j-1] = board_cal[i][j-1] + 70;
				board_cal[i ][j+5] = board_cal[i][j+5] + 70;
			}
			if (board[i][j] == 0 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 0) {
				board_cal[i-1][j-1] = board_cal[i-1][j-1] + 70;
				board_cal[i + 4][j+4] = board_cal[i + 4][j+4] + 70;
			}
			if (board[i][j] == 0 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 0) {
				board_cal[i-1][j+1] = board_cal[i-1][j+1] + 70;
				board_cal[i + 5][j-5] = board_cal[i + 5][j-5] + 70;
			}
			if (board[i][j] == 0 && board[i - 1][j] == 3 && board[i - 2][j] ==3 && board[i - 3][j] == 3 && board[i - 4][j] == 0) {
				board_cal[i+1][j] = board_cal[i+1][j] + 70;
				board_cal[i - 5][j] = board_cal[i - 5][j] + 70;
			}
			if (board[i][j] == 0 && board[i][j - 1] == 3 && board[i][j - 2] ==3 && board[i][j - 3] == 3 && board[i][j - 4] == 0) {
				board_cal[i][j+1] = board_cal[i][j+1] + 70;
				board_cal[i][j-5] = board_cal[i][j-5] + 70;
			}
			if (board[i][j] ==0 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 0) {
				board_cal[i+1][j+1] = board_cal[i+1][j+1] + 70;
				board_cal[i -5][j-5] = board_cal[i - 5][j-5] + 70;
			}
			if (board[i][j] == 0 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3&& board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 0) {
				board_cal[i+1][j-1] = board_cal[i+1][j-1] + 70;
				board_cal[i-5][j+5] = board_cal[i -5][j+5] + 70;
			}

			//for black
			if (board[i][j] == 0 && board[i + 1][j] == 2 && board[i + 2][j] == 2&& board[i + 3][j] == 2 && board[i + 4][j] == 0) {
				board_cal[i-1][j] = board_cal[i-1][j] - 70;
				board_cal[i + 5][j] = board_cal[i + 5][j] - 70;
			}
			if (board[i][j] == 0 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2&& board[i][j + 4] == 0) {
				board_cal[i][j-1] = board_cal[i][j-1] - 70;
				board_cal[i][j + 5] = board_cal[i][j + 5] - 70;
			}
			if (board[i][j] == 0 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2&& board[i + 4][j + 4] == 0) {
				board_cal[i-1][j-1] = board_cal[i-1][j-1] - 70;
				board_cal[i + 5][j + 5] = board_cal[i + 5][j + 5] - 70;
			}
			if (board[i][j] == 0 && board[i + 1][j - 1] == 2&& board[i + 2][j - 2] ==2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0) {
				board_cal[i-1][j+1] = board_cal[i-1][j+1] - 70;
				board_cal[i + 5][j - 5] = board_cal[i + 5][j - 5] - 70;
			}
			if (board[i][j] == 0 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 0) {
				board_cal[i+1][j] = board_cal[i+1][j] - 70;
				board_cal[i - 5][j] = board_cal[i - 5][j] - 70;
			}
			if (board[i][j] == 0 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] ==2 && board[i][j - 4] == 0) {
				board_cal[i][j+1] = board_cal[i][j+1] - 70;
				board_cal[i][j - 5] = board_cal[i][j - 5] - 70;
			}
			if (board[i][j] == 0 && board[i - 1][j - 1] == 2&& board[i - 2][j - 2] ==2 && board[i - 3][j - 3] ==2 && board[i - 4][j - 4] == 0) {
				board_cal[i+1][j+1] = board_cal[i+1][j+1] - 70;
				board_cal[i - 5][j - 5] = board_cal[i - 5][j - 5] - 70;
			}
			if (board[i][j] == 0 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 0) {
				board_cal[i+1][j-1] = board_cal[i+1][j-1] - 70;
				board_cal[i - 5][j + 5] = board_cal[i - 5][j + 5] - 70;
			}

			//●●v●●
			if (board[i][j] == 3 && board[i + 1][j] == 3 && board[i + 2][j] == 0 && board[i + 3][j] == 3 && board[i + 4][j] == 3)
				board_cal[i + 2][j] = board_cal[i + 2][j] + 100;
			if (board[i][j] == 3 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 0 && board[i][j + 4] == 3)
				board_cal[i][j + 2] = board_cal[i][j + 2] + 100;
			if (board[i][j] == 3 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3)
				board_cal[i + 2][j + 2] = board_cal[i + 2][j + 2] + 100;
			if (board[i][j] == 3 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3)
				board_cal[i + 2][j - 2] = board_cal[i + 2][j - 2] + 100;
			if (board[i][j] == 3 && board[i - 1][j] == 3 && board[i - 2][j] == 0 && board[i - 3][j] == 3 && board[i - 4][j] == 3)
				board_cal[i - 2][j] = board_cal[i - 2][j] + 100;
			if (board[i][j] == 3 && board[i][j - 1] == 3 && board[i][j - 2] == 0 && board[i][j - 3] == 3 && board[i][j - 4] == 3)
				board_cal[i][j - 2] = board_cal[i][j - 2] + 100;
			if (board[i][j] == 3 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 0 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3)
				board_cal[i - 2][j - 2] = board_cal[i - 2][j - 2] + 100;
			if (board[i][j] == 3 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 0 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3)
				board_cal[i - 2][j + 2] = board_cal[i - 2][j + 2] + 100;

			//for black
			if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 0 && board[i + 3][j] == 2 && board[i + 4][j] == 2)
				board_cal[i + 2][j] = board_cal[i + 2][j] - 100;
			if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0 && board[i][j + 4] == 2)
				board_cal[i][j + 2] = board_cal[i][j + 2] - 100;
			if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2)
				board_cal[i + 2][j + 2] = board_cal[i + 2][j + 2] - 100;
			if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2)
				board_cal[i + 2][j - 2] = board_cal[i + 2][j - 2] - 100;
			if (board[i][j] == 2 && board[i - 1][j] == 2 && board[i - 2][j] == 0 && board[i - 3][j] == 2 && board[i - 4][j] == 2)
				board_cal[i - 2][j] = board_cal[i - 2][j] - 100;
			if (board[i][j] == 2 && board[i][j - 1] == 2 && board[i][j - 2] == 0 && board[i][j - 3] == 2 && board[i][j - 4] == 2)
				board_cal[i][j - 2] = board_cal[i][j - 2] - 100;
			if (board[i][j] == 2 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 0 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2)
				board_cal[i - 2][j - 2] = board_cal[i - 2][j - 2] - 100;
			if (board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 0 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2)
				board_cal[i - 2][j + 2] = board_cal[i - 2][j + 2] - 100;
		}
	}
	for (i = 5; i < N - 5; i++)
	{
		for (j = 5; j < N - 5; j++)
		{
			//○●●●●v
			if (board[i][j] == 2 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 3 && board[i + 5][j] == 0)
				board_cal[i + 5][j] = board_cal[i + 5][j] + 90;
			if (board[i][j] == 2 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 3 && board[i][j + 5] == 0)
				board_cal[i + 5][j] = board_cal[i + 5][j] + 90;
			if (board[i][j] == 2 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3 && board[i + 5][j + 5] == 0)
				board_cal[i + 5][j+5] = board_cal[i + 5][j+5] + 90;
			if (board[i][j] == 2 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3 && board[i + 5][j - 5] == 0)
				board_cal[i + 5][j-5] = board_cal[i + 5][j-5] + 90;
			if (board[i][j] == 2 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 3 && board[i - 5][j] == 0)
				board_cal[i - 5][j] = board_cal[i - 5][j] + 90;
			if (board[i][j] == 2 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 3 && board[i][j - 5] == 0)
				board_cal[i][j-5] = board_cal[i][j-5] + 90;
			if (board[i][j] == 2 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3 && board[i - 5][j - 5] == 0)
				board_cal[i -5][j-5] = board_cal[i - 5][j-5] + 90;
			if (board[i][j] == 2 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3 && board[i - 5][j + 5] == 0)
				board_cal[i - 5][j+5] = board_cal[i -5][j+5] + 90;
			
			//black
			if (board[i][j] == 3 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2 && board[i + 5][j] == 0)
				board_cal[i + 5][j] = board_cal[i + 5][j] - 90;
			if (board[i][j] == 3 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2 && board[i][j + 5] == 0)
				board_cal[i + 5][j] = board_cal[i + 5][j] - 90;
			if (board[i][j] == 3 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2 && board[i + 5][j + 5] == 0)
				board_cal[i + 5][j + 5] = board_cal[i + 5][j + 5] - 90;
			if (board[i][j] == 3 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2 && board[i + 5][j - 5] == 0)
				board_cal[i + 5][j - 5] = board_cal[i + 5][j - 5] - 90;
			if (board[i][j] == 3 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 2 && board[i - 5][j] == 0)
				board_cal[i - 5][j] = board_cal[i - 5][j] - 90;
			if (board[i][j] == 3 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 2 && board[i][j - 5] == 0)
				board_cal[i][j - 5] = board_cal[i][j - 5] - 90;
			if (board[i][j] == 3 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2 && board[i - 5][j - 5] == 0)
				board_cal[i - 5][j - 5] = board_cal[i - 5][j - 5] - 90;
			if (board[i][j] == 3 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2 && board[i - 5][j + 5] == 0)
				board_cal[i - 5][j + 5] = board_cal[i - 5][j + 5] - 90;

			//○●●●●v//뒤집어서
			if (board[i][j] == 0 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 3 && board[i + 5][j] == 2)
				board_cal[i][j] = board_cal[i][j] + 90;
			if (board[i][j] == 0 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 3 && board[i][j + 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 90;
			if (board[i][j] == 0 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3 && board[i + 5][j + 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 90;
			if (board[i][j] == 0 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3 && board[i + 5][j - 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 90;
			if (board[i][j] == 0 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 3 && board[i - 5][j] == 2)
				board_cal[i][j] = board_cal[i][j] + 90;
			if (board[i][j] == 0 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 3 && board[i][j - 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 90;
			if (board[i][j] == 0 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3 && board[i - 5][j - 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 90;
			if (board[i][j] == 0 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3 && board[i - 5][j + 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 90;

			//black
			if (board[i][j] == 0 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2 && board[i + 5][j] == 3)
				board_cal[i][j] = board_cal[i][j] - 90;
			if (board[i][j] == 0 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2 && board[i][j + 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 90;
			if (board[i][j] == 0 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2 && board[i + 5][j + 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 90;
			if (board[i][j] == 0 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2 && board[i + 5][j - 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 90;
			if (board[i][j] == 0 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 2 && board[i - 5][j] == 3)
				board_cal[i][j] = board_cal[i][j] - 90;
			if (board[i][j] == 0 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 2 && board[i][j - 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 90;
			if (board[i][j] == 0 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2 && board[i - 5][j - 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 90;
			if (board[i][j] == 0 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2 && board[i - 5][j + 5] == 3)
				board_cal[i][j] = board_cal[i][j] -90;
		}
	}
}


