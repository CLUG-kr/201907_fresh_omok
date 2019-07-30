#include "omok.h"

void calculate(int(*board_cal)[N], int(*board)[N], int color, int x, int y, int *ai_x, int *ai_y) {
	int i, j;
	int temp1 = 0; //���, ��
	int temp2 = 0; //����, ������
	int x1 = 0; //temp1���� ���Ǵ� ��ǥ �ӽ�����
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	board[x][y] = color; //�ϴ� �� ���� �� ��ǥ���� ���� 
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
			}//�浹�� -, ���� +
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (board[i][j] == 0) {
				if (board_cal[i][j] > temp1) {//0���� ��갪�� ū ��� (�򵹿��� ������ ���)
					temp1 = board_cal[i][j];
					x1 = i;
					y1 = j;
				}
				else if (board_cal[i][j] < temp2) {//0���� ��갪�� ���� ��� (�浹���� ������ ���)
					temp2 = board_cal[i][j];
					x2 = i;
					y2 = j;
				}
			}
			//printf("%d ", board_cal[i][j]);
		}
		//printf("\n");
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
		if (color == BLACK) {//���� AI�� ���� ����� ���� ���� �浹�̾��� ��, ��ġ�� ���ٸ� ���� �� ���� ���� �����ϹǷ� ���� ������������ �� 
			*ai_x = x1;
			*ai_y = y1;
		}
		else {
			*ai_x = x2;
			*ai_y = y2;
		}
	}
	//system("pause");
}