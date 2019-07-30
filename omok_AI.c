#include "omok.h"

void calculate(int(*board_cal)[N], int(*board)[N], int color, int x, int y, int *ai_x, int *ai_y) {
	int i, j;
	int temp1 = 0; //양수, 흰돌
	int temp2 = 0; //음수, 검은돌
	int x1 = 0; //temp1에서 사용되는 좌표 임시저장
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	board[x][y] = color; //일단 돌 놓는 곳 좌표부터 찍음 
	eval(board_cal, board);
	for (i = x - 1; i <= x + 1; i++) {
		for (j = y - 1; j <= y + 1; j++) {
			if (board[i][j] == 0 && i >= 1 && j >=1&& i<N &&j<N) {		
				if (board[x][y] == BLACK) {
					board_cal[i][j]--;
				}
				else if (board[x][y] == WHITE) {
					board_cal[i][j]++;
				}
			}//흑돌이 -, 흰돌이 +
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (board[i][j] == 0) {
				if (board_cal[i][j] > temp1) {//0보다 계산값이 큰 경우 (흰돌에게 유리한 경우)
					temp1 = board_cal[i][j];
					x1 = i;
					y1 = j;
				}
				else if (board_cal[i][j] < temp2) {//0보다 계산값이 작은 경우 (흑돌에게 유리한 경우)
					temp2 = board_cal[i][j];
					x2 = i;
					y2 = j;
				}
			}
			printf("%d ", board_cal[i][j]);
		}
		printf("\n");
	}

	if (temp1 > -(temp2)) {
		*ai_x = x1;
		*ai_y = y1;
	}
	else if (temp1 < -(temp2)) {
		*ai_x = x2;
		*ai_y = y2;
	}
	else {
		if (color == BLACK) {//현재 AI턴 이전 사람이 놓은 돌이 흑돌이었을 때, 가치가 같다면 턴이 더 빠른 흰돌이 유리하므로 흰돌이 유리한쪽으로 둠 
			*ai_x = x1;
			*ai_y = y1;
		}
		else {
			*ai_x = x2;
			*ai_y = y2;
		}
	}
	system("pause");
}