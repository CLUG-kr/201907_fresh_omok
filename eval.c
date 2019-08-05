#include "omok.h"

void eval(int(*board_cal)[N], int(*board)[N], int x, int y) // 해당 노드가 가지고 있는 board의 가치를 평가하는 함수
{
	int i, j;

	//걍 가치 평가 함수 이중for문을 짱 많이 돌린다 (여기서 시간 되게 많이 소모할 것 같음)
	//소모시간 줄이려면 for문들 중에서 범위 같은 것들끼리 묶는 게 좋을 듯 
	//그러면 생각보다 가치평가에 많은 시간 안 쓸 것 같아 > 수정함
	//맘 같아선 하나의 함수로 묶고 검은돌/흰돌 함수로 나누고 싶지만... 그럼 시간 오래 걸리겠지?ㅜ,ㅜ
	//white가 높은것 2가 black, 3이 white

	for (i = x - 3; i <= x + 3; i++) {
		for (j = y - 3; j <= y + 3; j++) {
			if (x >= 1 && y >= 1 && x < N && y < N) {
				//●v●●
				if (board[i][j] == 3 && board[i + 1][j] == 0 && board[i + 2][j] == 3 && board[i + 3][j] == 3)
					board_cal[i + 1][j] = board_cal[i + 1][j] + 7;
				if (board[i][j] == 3 && board[i][j + 1] == 0 && board[i][j + 2] == 3 && board[i][j + 3] == 3)
					board_cal[i][j + 1] = board_cal[i][j + 1] + 7;
				if (board[i][j] == 3 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3)
					board_cal[i + 1][j + 1] = board_cal[i + 1][j + 1] + 7;
				if (board[i][j] == 3 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3)
					board_cal[i + 1][j - 1] = board_cal[i + 1][j - 1] + 7;
				if (board[i][j] == 3 && board[i - 1][j] == 0 && board[i - 2][j] == 3 && board[i - 3][j] == 3)
					board_cal[i - 1][j] = board_cal[i - 1][j] + 7;
				if (board[i][j] == 3 && board[i][j - 1] == 0 && board[i][j - 2] == 3 && board[i][j - 3] == 3)
					board_cal[i][j - 1] = board_cal[i][j - 1] + 7;
				if (board[i][j] == 3 && board[i - 1][j - 1] == 0 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3)
					board_cal[i - 1][j - 1] = board_cal[i - 1][j - 1] + 7;
				if (board[i][j] == 3 && board[i - 1][j + 1] == 0 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3)
					board_cal[i - 1][j + 1] = board_cal[i - 1][j + 1] + 7;

				//for black
				if (board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2)
					board_cal[i + 1][j] = board_cal[i + 1][j] - 7;
				if (board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2)
					board_cal[i][j + 1] = board_cal[i][j + 1] - 7;
				if (board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2)
					board_cal[i + 1][j + 1] = board_cal[i + 1][j + 1] - 7;
				if (board[i][j] == 2 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2)
					board_cal[i + 1][j - 1] = board_cal[i + 1][j - 1] - 7;
				if (board[i][j] == 2 && board[i - 1][j] == 0 && board[i - 2][j] == 2 && board[i - 3][j] == 2)
					board_cal[i - 1][j] = board_cal[i - 1][j] - 7;
				if (board[i][j] == 2 && board[i][j - 1] == 0 && board[i][j - 2] == 2 && board[i][j - 3] == 2)
					board_cal[i][j - 1] = board_cal[i][j - 1] - 7;
				if (board[i][j] == 2 && board[i - 1][j - 1] == 0 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2)
					board_cal[i - 1][j - 1] = board_cal[i - 1][j - 1] - 7;
				if (board[i][j] == 2 && board[i - 1][j + 1] == 0 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2)
					board_cal[i - 1][j + 1] = board_cal[i - 1][j + 1] - 7;

				//●v●● //뒤집힌 경우
				if (board[i][j] == 3 && board[i + 1][j] == 3 && board[i + 2][j] == 0 && board[i + 3][j] == 3)
					board_cal[i + 2][j] = board_cal[i + 2][j] + 7;
				if (board[i][j] == 3 && board[i][j + 1] == 3 && board[i][j + 2] == 0 && board[i][j + 3] == 3)
					board_cal[i][j + 2] = board_cal[i][j + 2] + 7;
				if (board[i][j] == 3 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 3)
					board_cal[i + 2][j + 2] = board_cal[i + 2][j + 2] + 7;
				if (board[i][j] == 3 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 3)
					board_cal[i + 2][j - 2] = board_cal[i + 2][j - 2] + 7;
				if (board[i][j] == 3 && board[i - 1][j] == 3 && board[i - 2][j] == 0 && board[i - 3][j] == 3)
					board_cal[i - 2][j] = board_cal[i - 2][j] + 7;
				if (board[i][j] == 3 && board[i][j - 1] == 3 && board[i][j - 2] == 0 && board[i][j - 3] == 3)
					board_cal[i][j - 2] = board_cal[i][j - 2] + 7;
				if (board[i][j] == 3 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 0 && board[i - 3][j - 3] == 3)
					board_cal[i - 2][j - 2] = board_cal[i - 2][j - 2] + 7;
				if (board[i][j] == 3 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 0 && board[i - 3][j + 3] == 3)
					board_cal[i - 2][j + 2] = board_cal[i - 2][j + 2] + 7;

				//for black
				if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 0 && board[i + 3][j] == 2)
					board_cal[i + 2][j] = board_cal[i + 2][j] - 7;
				if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 0 && board[i][j + 3] == 2)
					board_cal[i][j + 2] = board_cal[i][j + 2] - 7;
				if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 2)
					board_cal[i + 3][j + 3] = board_cal[i + 2][j + 2] - 7;
				if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 2)
					board_cal[i + 2][j - 2] = board_cal[i + 2][j - 2] - 7;
				if (board[i][j] == 2 && board[i - 1][j] == 2 && board[i - 2][j] == 0 && board[i - 3][j] == 2)
					board_cal[i - 2][j] = board_cal[i - 2][j] - 7;
				if (board[i][j] == 2 && board[i][j - 1] == 2 && board[i][j - 2] == 0 && board[i][j - 3] == 2)
					board_cal[i][j - 2] = board_cal[i][j - 2] - 7;
				if (board[i][j] == 2 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 0 && board[i - 3][j - 3] == 2)
					board_cal[i - 2][j - 2] = board_cal[i - 2][j - 2] - 7;
				if (board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 0 && board[i - 3][j + 3] == 2)
					board_cal[i - 2][j + 2] = board_cal[i - 2][j + 2] - 7;
			}
		}
	}
	for (i = x - 4; i <= x + 4; i++) {
		for (j = y - 4; j <=  y+ 4; j++) {
			if (x >= 1 && y >= 1 && x < N && y < N) {
				//●v●●●
				if (board[i][j] == 3 && board[i + 1][j] == 0 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 3)
					board_cal[i + 1][j] = board_cal[i + 1][j] + 10;
				if (board[i][j] == 3 && board[i][j + 1] == 0 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 3)
					board_cal[i][j + 1] = board_cal[i][j + 1] + 10;
				if (board[i][j] == 3 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3)
					board_cal[i + 1][j + 1] = board_cal[i + 1][j + 1] + 10;
				if (board[i][j] == 3 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3)
					board_cal[i + 1][j - 1] = board_cal[i + 1][j - 1] + 10;
				if (board[i][j] == 3 && board[i - 1][j] == 0 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 3)
					board_cal[i - 1][j] = board_cal[i - 1][j] + 10;
				if (board[i][j] == 3 && board[i][j - 1] == 0 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 3)
					board_cal[i][j - 1] = board_cal[i][j - 1] + 10;
				if (board[i][j] == 3 && board[i - 1][j - 1] == 0 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3)
					board_cal[i - 1][j - 1] = board_cal[i - 1][j - 1] + 10;
				if (board[i][j] == 3 && board[i - 1][j + 1] == 0 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3)
					board_cal[i - 1][j + 1] = board_cal[i - 1][j + 1] + 10;

				//for black
				if (board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2)
					board_cal[i + 1][j] = board_cal[i + 1][j] - 10;
				if (board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2)
					board_cal[i][j + 1] = board_cal[i][j + 1] - 10;
				if (board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2)
					board_cal[i + 1][j + 1] = board_cal[i + 1][j + 1] - 10;
				if (board[i][j] == 2 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2)
					board_cal[i + 1][j - 1] = board_cal[i + 1][j - 1] - 10;
				if (board[i][j] == 2 && board[i - 1][j] == 0 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 2)
					board_cal[i - 1][j] = board_cal[i - 1][j] - 10;
				if (board[i][j] == 2 && board[i][j - 1] == 0 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 2)
					board_cal[i][j - 1] = board_cal[i][j - 1] - 10;
				if (board[i][j] == 2 && board[i - 1][j - 1] == 0 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2)
					board_cal[i - 1][j - 1] = board_cal[i - 1][j - 1] - 10;
				if (board[i][j] == 2 && board[i - 1][j + 1] == 0 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2)
					board_cal[i - 1][j + 1] = board_cal[i - 1][j + 1] - 10;

				//●v●●● //뒤집힌 경우
				if (board[i][j] == 3 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 0 && board[i + 4][j] == 3)
					board_cal[i + 3][j] = board_cal[i + 3][j] + 10;
				if (board[i][j] == 3 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 0 && board[i][j + 4] == 3)
					board_cal[i][j + 3] = board_cal[i][j + 3] + 10;
				if (board[i][j] == 3 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 3)
					board_cal[i + 3][j + 3] = board_cal[i + 3][j + 3] + 10;
				if (board[i][j] == 3 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 3)
					board_cal[i + 3][j - 3] = board_cal[i + 3][j - 3] + 10;
				if (board[i][j] == 3 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 0 && board[i - 4][j] == 3)
					board_cal[i - 3][j] = board_cal[i - 3][j] + 10;
				if (board[i][j] == 3 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 0 && board[i][j - 4] == 3)
					board_cal[i][j - 3] = board_cal[i][j - 3] + 10;
				if (board[i][j] == 3 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 0 && board[i - 4][j - 4] == 3)
					board_cal[i - 3][j - 3] = board_cal[i - 3][j - 3] + 10;
				if (board[i][j] == 3 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 0 && board[i - 4][j + 4] == 3)
					board_cal[i - 3][j + 3] = board_cal[i - 3][j + 3] + 10;

				//for black
				if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0 && board[i + 4][j] == 2)
					board_cal[i + 3][j] = board_cal[i + 3][j] - 10;
				if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0 && board[i][j + 4] == 2)
					board_cal[i][j + 3] = board_cal[i][j + 3] - 10;
				if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 2)
					board_cal[i + 3][j + 3] = board_cal[i + 3][j + 3] - 10;
				if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 2)
					board_cal[i + 3][j - 3] = board_cal[i + 3][j - 3] - 10;
				if (board[i][j] == 2 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 0 && board[i - 4][j] == 2)
					board_cal[i - 3][j] = board_cal[i - 3][j] - 10;
				if (board[i][j] == 2 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 0 && board[i][j - 4] == 2)
					board_cal[i][j - 3] = board_cal[i][j - 3] - 10;
				if (board[i][j] == 2 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 0 && board[i - 4][j - 4] == 2)
					board_cal[i - 3][j - 3] = board_cal[i - 3][j - 3] - 10;
				if (board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 0 && board[i - 4][j + 4] == 2)
					board_cal[i - 3][j + 3] = board_cal[i - 3][j + 3] - 10;

				//v●●●v
				if (board[i][j] == 0 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 0) {
					board_cal[i][j] = board_cal[i][j] + 7;
					board_cal[i + 4][j] = board_cal[i + 4][j] + 7;
				}
				if (board[i][j] == 0 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 0) {
					board_cal[i][j] = board_cal[i][j] + 7;
					board_cal[i][j + 4] = board_cal[i][j + 4] + 7;
				}
				if (board[i][j] == 0 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 0) {
					board_cal[i][j] = board_cal[i][j] + 7;
					board_cal[i + 4][j + 4] = board_cal[i + 4][j + 4] + 7;
				}
				if (board[i][j] == 0 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 0) {
					board_cal[i][j] = board_cal[i][j] + 7;
					board_cal[i + 4][j - 4] = board_cal[i + 4][j - 4] + 7;
				}
				if (board[i][j] == 0 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 0) {
					board_cal[i][j] = board_cal[i][j] + 7;
					board_cal[i - 4][j] = board_cal[i - 4][j] + 7;
				}
				if (board[i][j] == 0 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 0) {
					board_cal[i][j] = board_cal[i][j] + 7;
					board_cal[i][j - 4] = board_cal[i][j - 4] + 7;
				}
				if (board[i][j] == 0 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 0) {
					board_cal[i][j] = board_cal[i][j] + 7;
					board_cal[i - 4][j - 4] = board_cal[i - 4][j - 4] + 7;
				}
				if (board[i][j] == 0 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 0) {
					board_cal[i][j] = board_cal[i][j] + 7;
					board_cal[i - 4][j + 4] = board_cal[i - 4][j + 4] + 7;
				}

				//for black
				if (board[i][j] == 0 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0) {
					board_cal[i][j] = board_cal[i][j] - 7;
					board_cal[i + 4][j] = board_cal[i + 4][j] - 7;
				}
				if (board[i][j] == 0 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0) {
					board_cal[i][j] = board_cal[i][j] - 7;
					board_cal[i][j + 4] = board_cal[i][j + 4] - 7;
				}
				if (board[i][j] == 0 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0) {
					board_cal[i][j] = board_cal[i][j] - 7;
					board_cal[i + 4][j + 4] = board_cal[i + 4][j + 4] - 7;
				}
				if (board[i][j] == 0 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0) {
					board_cal[i][j] = board_cal[i][j] - 7;
					board_cal[i + 4][j - 4] = board_cal[i + 4][j - 4] - 7;
				}
				if (board[i][j] == 0 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 0) {
					board_cal[i][j] = board_cal[i][j] - 7;
					board_cal[i - 4][j] = board_cal[i - 4][j] - 7;
				}
				if (board[i][j] == 0 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 0) {
					board_cal[i][j] = board_cal[i][j] - 7;
					board_cal[i][j - 4] = board_cal[i][j - 4] - 7;
				}
				if (board[i][j] == 0 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 0) {
					board_cal[i][j] = board_cal[i][j] - 7;
					board_cal[i - 4][j - 4] = board_cal[i - 4][j - 4] - 7;
				}
				if (board[i][j] == 0 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 0) {
					board_cal[i][j] = board_cal[i][j] - 7;
					board_cal[i - 4][j + 4] = board_cal[i - 4][j + 4] - 7;
				}

				//v●●●v //한쪽 막힌 경우
				if (board[i][j] == 2 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 0) {
					board_cal[i + 4][j] = board_cal[i + 4][j] - 4;
				}
				if (board[i][j] == 2 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 0) {
					board_cal[i][j + 4] = board_cal[i][j + 4] - 4;
				}
				if (board[i][j] == 2 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 0) {
					board_cal[i + 4][j + 4] = board_cal[i + 4][j + 4] - 4;
				}
				if (board[i][j] == 2 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 0) {
					board_cal[i + 4][j - 4] = board_cal[i + 4][j - 4] - 4;
				}
				if (board[i][j] == 2 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 0) {
					board_cal[i - 4][j] = board_cal[i - 4][j] - 4;
				}
				if (board[i][j] == 2 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 0) {
					board_cal[i][j - 4] = board_cal[i][j - 4] - 4;
				}
				if (board[i][j] == 2 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 0) {
					board_cal[i - 4][j - 4] = board_cal[i - 4][j - 4] - 4;
				}
				if (board[i][j] == 2 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 0) {
					board_cal[i - 4][j + 4] = board_cal[i - 4][j + 4] - 4;
				}

				//for black
				if (board[i][j] == 3 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0) {
					board_cal[i + 4][j] = board_cal[i + 4][j] + 4;
				}
				if (board[i][j] == 3 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0) {
					board_cal[i][j + 4] = board_cal[i][j + 4] + 4;
				}
				if (board[i][j] == 3 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0) {
					board_cal[i + 4][j + 4] = board_cal[i + 4][j + 4] + 4;
				}
				if (board[i][j] == 3 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0) {
					board_cal[i + 4][j - 4] = board_cal[i + 4][j - 4] + 4;
				}
				if (board[i][j] == 3 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 0) {
					board_cal[i - 4][j] = board_cal[i - 4][j] + 4;
				}
				if (board[i][j] == 3 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 0) {
					board_cal[i][j - 4] = board_cal[i][j - 4] + 4;
				}
				if (board[i][j] == 3 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 0) {
					board_cal[i - 4][j - 4] = board_cal[i - 4][j - 4] + 4;
				}
				if (board[i][j] == 3 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 0) {
					board_cal[i - 4][j + 4] = board_cal[i - 4][j + 4] + 4;
				}

				//v●●●v //다른 한쪽 막힌 경우
				if (board[i][j] == 0 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 2) {
					board_cal[i][j] = board_cal[i][j] - 4;
				}
				if (board[i][j] == 0 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 2) {
					board_cal[i][j] = board_cal[i][j] - 4;
				}
				if (board[i][j] == 0 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 2) {
					board_cal[i][j] = board_cal[i][j] - 4;
				}
				if (board[i][j] == 0 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 2) {
					board_cal[i][j] = board_cal[i][j] - 4;
				}
				if (board[i][j] == 0 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 2) {
					board_cal[i][j] = board_cal[i][j] - 4;
				}
				if (board[i][j] == 0 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 2) {
					board_cal[i][j] = board_cal[i][j] - 4;
				}
				if (board[i][j] == 0 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 2) {
					board_cal[i][j] = board_cal[i][j] - 4;
				}
				if (board[i][j] == 0 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 2) {
					board_cal[i][j] = board_cal[i][j] - 4;
				}

				//for black
				if (board[i][j] == 0 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 3) {
					board_cal[i][j] = board_cal[i][j] + 4;
				}
				if (board[i][j] == 0 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 3) {
					board_cal[i][j] = board_cal[i][j] + 4;
				}
				if (board[i][j] == 0 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 3) {
					board_cal[i][j] = board_cal[i][j] + 4;
				}
				if (board[i][j] == 0 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 3) {
					board_cal[i][j] = board_cal[i][j] + 4;
				}
				if (board[i][j] == 0 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 3) {
					board_cal[i][j] = board_cal[i][j] + 4;
				}
				if (board[i][j] == 0 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 3) {
					board_cal[i][j] = board_cal[i][j] + 4;
				}
				if (board[i][j] == 0 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 3) {
					board_cal[i][j] = board_cal[i][j] + 4;
				}
				if (board[i][j] == 0 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 3) {
					board_cal[i][j] = board_cal[i][j] + 4;
				}

				//●●v●●
				if (board[i][j] == 3 && board[i + 1][j] == 3 && board[i + 2][j] == 0 && board[i + 3][j] == 3 && board[i + 4][j] == 3)
					board_cal[i + 2][j] = board_cal[i + 2][j] + 10;
				if (board[i][j] == 3 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 0 && board[i][j + 4] == 3)
					board_cal[i][j + 2] = board_cal[i][j + 2] + 10;
				if (board[i][j] == 3 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3)
					board_cal[i + 2][j + 2] = board_cal[i + 2][j + 2] + 10;
				if (board[i][j] == 3 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3)
					board_cal[i + 2][j - 2] = board_cal[i + 2][j - 2] + 10;
				if (board[i][j] == 3 && board[i - 1][j] == 3 && board[i - 2][j] == 0 && board[i - 3][j] == 3 && board[i - 4][j] == 3)
					board_cal[i - 2][j] = board_cal[i - 2][j] + 10;
				if (board[i][j] == 3 && board[i][j - 1] == 3 && board[i][j - 2] == 0 && board[i][j - 3] == 3 && board[i][j - 4] == 3)
					board_cal[i][j - 2] = board_cal[i][j - 2] + 10;
				if (board[i][j] == 3 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 0 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3)
					board_cal[i - 2][j - 2] = board_cal[i - 2][j - 2] + 10;
				if (board[i][j] == 3 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 0 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3)
					board_cal[i - 2][j + 2] = board_cal[i - 2][j + 2] + 10;

				//for black
				if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 0 && board[i + 3][j] == 2 && board[i + 4][j] == 2)
					board_cal[i + 2][j] = board_cal[i + 2][j] - 10;
				if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0 && board[i][j + 4] == 2)
					board_cal[i][j + 2] = board_cal[i][j + 2] - 10;
				if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2)
					board_cal[i + 2][j + 2] = board_cal[i + 2][j + 2] - 10;
				if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2)
					board_cal[i + 2][j - 2] = board_cal[i + 2][j - 2] - 10;
				if (board[i][j] == 2 && board[i - 1][j] == 2 && board[i - 2][j] == 0 && board[i - 3][j] == 2 && board[i - 4][j] == 2)
					board_cal[i - 2][j] = board_cal[i - 2][j] - 10;
				if (board[i][j] == 2 && board[i][j - 1] == 2 && board[i][j - 2] == 0 && board[i][j - 3] == 2 && board[i][j - 4] == 2)
					board_cal[i][j - 2] = board_cal[i][j - 2] - 10;
				if (board[i][j] == 2 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 0 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2)
					board_cal[i - 2][j - 2] = board_cal[i - 2][j - 2] - 10;
				if (board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 0 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2)
					board_cal[i - 2][j + 2] = board_cal[i - 2][j + 2] - 10;
			}
		}
	}

	for (i = x-5; i <=x+5; i++)
	{
		for (j = y-5; j <=y+ 5; j++)
		{
			if (x >= 1 && y >= 1 && x < N && y < N) {
				//○●●●●v
				if (board[i][j] == 2 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 3 && board[i + 5][j] == 0)
					board_cal[i + 5][j] = board_cal[i + 5][j] - 7;
				if (board[i][j] == 2 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 3 && board[i][j + 5] == 0)
					board_cal[i + 5][j] = board_cal[i + 5][j] - 7;
				if (board[i][j] == 2 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3 && board[i + 5][j + 5] == 0)
					board_cal[i + 5][j + 5] = board_cal[i + 5][j + 5] - 7;
				if (board[i][j] == 2 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3 && board[i + 5][j - 5] == 0)
					board_cal[i + 5][j - 5] = board_cal[i + 5][j - 5] - 7;
				if (board[i][j] == 2 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 3 && board[i - 5][j] == 0)
					board_cal[i - 5][j] = board_cal[i - 5][j] - 7;
				if (board[i][j] == 2 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 3 && board[i][j - 5] == 0)
					board_cal[i][j - 5] = board_cal[i][j - 5] - 7;
				if (board[i][j] == 2 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3 && board[i - 5][j - 5] == 0)
					board_cal[i - 5][j - 5] = board_cal[i - 5][j - 5] - 7;
				if (board[i][j] == 2 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3 && board[i - 5][j + 5] == 0)
					board_cal[i - 5][j + 5] = board_cal[i - 5][j + 5] - 7;

				//black
				if (board[i][j] == 3 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2 && board[i + 5][j] == 0)
					board_cal[i + 5][j] = board_cal[i + 5][j] + 7;
				if (board[i][j] == 3 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2 && board[i][j + 5] == 0)
					board_cal[i + 5][j] = board_cal[i + 5][j] + 7;
				if (board[i][j] == 3 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2 && board[i + 5][j + 5] == 0)
					board_cal[i + 5][j + 5] = board_cal[i + 5][j + 5] + 7;
				if (board[i][j] == 3 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2 && board[i + 5][j - 5] == 0)
					board_cal[i + 5][j - 5] = board_cal[i + 5][j - 5] + 7;
				if (board[i][j] == 3 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 2 && board[i - 5][j] == 0)
					board_cal[i - 5][j] = board_cal[i - 5][j] + 7;
				if (board[i][j] == 3 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 2 && board[i][j - 5] == 0)
					board_cal[i][j - 5] = board_cal[i][j - 5] + 7;
				if (board[i][j] == 3 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2 && board[i - 5][j - 5] == 0)
					board_cal[i - 5][j - 5] = board_cal[i - 5][j - 5] + 7;
				if (board[i][j] == 3 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2 && board[i - 5][j + 5] == 0)
					board_cal[i - 5][j + 5] = board_cal[i - 5][j + 5] + 7;

				//○●●●●v//뒤집어서
				if (board[i][j] == 0 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 3 && board[i + 5][j] == 2)
					board_cal[i][j] = board_cal[i][j] - 7;
				if (board[i][j] == 0 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 3 && board[i][j + 5] == 2)
					board_cal[i][j] = board_cal[i][j] - 7;
				if (board[i][j] == 0 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3 && board[i + 5][j + 5] == 2)
					board_cal[i][j] = board_cal[i][j] - 7;
				if (board[i][j] == 0 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3 && board[i + 5][j - 5] == 2)
					board_cal[i][j] = board_cal[i][j] - 7;
				if (board[i][j] == 0 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 3 && board[i - 5][j] == 2)
					board_cal[i][j] = board_cal[i][j] - 7;
				if (board[i][j] == 0 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 3 && board[i][j - 5] == 2)
					board_cal[i][j] = board_cal[i][j] - 7;
				if (board[i][j] == 0 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3 && board[i - 5][j - 5] == 2)
					board_cal[i][j] = board_cal[i][j] - 7;
				if (board[i][j] == 0 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3 && board[i - 5][j + 5] == 2)
					board_cal[i][j] = board_cal[i][j] - 7;

				//black
				if (board[i][j] == 0 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2 && board[i + 5][j] == 3)
					board_cal[i][j] = board_cal[i][j] + 7;
				if (board[i][j] == 0 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2 && board[i][j + 5] == 3)
					board_cal[i][j] = board_cal[i][j] + 7;
				if (board[i][j] == 0 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2 && board[i + 5][j + 5] == 3)
					board_cal[i][j] = board_cal[i][j] + 7;
				if (board[i][j] == 0 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2 && board[i + 5][j - 5] == 3)
					board_cal[i][j] = board_cal[i][j] + 7;
				if (board[i][j] == 0 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 2 && board[i - 5][j] == 3)
					board_cal[i][j] = board_cal[i][j] + 7;
				if (board[i][j] == 0 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 2 && board[i][j - 5] == 3)
					board_cal[i][j] = board_cal[i][j] + 7;
				if (board[i][j] == 0 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2 && board[i - 5][j - 5] == 3)
					board_cal[i][j] = board_cal[i][j] + 7;
				if (board[i][j] == 0 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2 && board[i - 5][j + 5] == 3)
					board_cal[i][j] = board_cal[i][j] + 7;
			}
		}
	}
}