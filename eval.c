#include "omok.h"

void eval(int(*board_cal)[N], int(*board)[N]) // �ش� ��尡 ������ �ִ� board�� ��ġ�� ���ϴ� �Լ�
{
	int i, j;

	//�� ��ġ �� �Լ� ����for���� ¯ ���� ������ (���⼭ �ð� �ǰ� ���� �Ҹ��� �� ����)
	//�Ҹ�ð� ���̷��� for���� �߿��� ���� ���� �͵鳢�� ���� �� ���� �� 
	//�׷��� �������� ��ġ�򰡿� ���� �ð� �� �� �� ���� > ������
	//�� ���Ƽ� �ϳ��� �Լ��� ���� ������/�� �Լ��� ������ ������... �׷� �ð� ���� �ɸ�����?��,��
	//white�� ������ 2�� black, 3�� white
	for (i = 4; i < N - 4; i++) {
		for (j = 4; j < N - 4; j++) {
			//��v�ܡܡ�
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

			//��v�ܡܡ� //������ ���
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

			//v�ܡܡ�v
			if (board[i][j] == 0 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 0) {
				board_cal[i][j] = board_cal[i][j] + 7;
				board_cal[i + 4][j] = board_cal[i + 4][j] + 7;
			}
			if (board[i][j] == 0 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 0) {
				board_cal[i][j] = board_cal[i][j] + 7;
				board_cal[i ][j+4] = board_cal[i][j+4] + 7;
			}
			if (board[i][j] == 0 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 0) {
				board_cal[i][j] = board_cal[i][j] + 7;
				board_cal[i + 4][j+4] = board_cal[i + 4][j+4] + 7;
			}
			if (board[i][j] == 0 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 0) {
				board_cal[i][j] = board_cal[i][j] + 7;
				board_cal[i + 4][j-4] = board_cal[i + 4][j-4] + 7;
			}
			if (board[i][j] == 0 && board[i - 1][j] == 3 && board[i - 2][j] ==3 && board[i - 3][j] == 3 && board[i - 4][j] == 0) {
				board_cal[i][j] = board_cal[i][j] + 7;
				board_cal[i - 4][j] = board_cal[i - 4][j] + 7;
			}
			if (board[i][j] == 0 && board[i][j - 1] == 3 && board[i][j - 2] ==3 && board[i][j - 3] == 3 && board[i][j - 4] == 0) {
				board_cal[i][j] = board_cal[i][j] + 7;
				board_cal[i][j-4] = board_cal[i][j-4] + 7;
			}
			if (board[i][j] ==0 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 0) {
				board_cal[i][j] = board_cal[i][j] + 7;
				board_cal[i -4][j-4] = board_cal[i - 4][j-4] + 7;
			}
			if (board[i][j] == 0 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3&& board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 0) {
				board_cal[i][j] = board_cal[i][j] + 7;
				board_cal[i-4][j+4] = board_cal[i -4][j+4] + 7;
			}

			//for black
			if (board[i][j] == 0 && board[i + 1][j] == 2 && board[i + 2][j] == 2&& board[i + 3][j] == 2 && board[i + 4][j] == 0) {
				board_cal[i][j] = board_cal[i][j] - 7;
				board_cal[i + 4][j] = board_cal[i + 4][j] - 7;
			}
			if (board[i][j] == 0 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2&& board[i][j + 4] == 0) {
				board_cal[i][j] = board_cal[i][j] - 7;
				board_cal[i][j + 4] = board_cal[i][j + 4] - 7;
			}
			if (board[i][j] == 0 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2&& board[i + 4][j + 4] == 0) {
				board_cal[i][j] = board_cal[i][j] - 7;
				board_cal[i + 4][j + 4] = board_cal[i + 4][j + 4] - 7;
			}
			if (board[i][j] == 0 && board[i + 1][j - 1] == 2&& board[i + 2][j - 2] ==2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0) {
				board_cal[i][j] = board_cal[i][j] - 7;
				board_cal[i + 4][j - 4] = board_cal[i + 4][j - 4] - 7;
			}
			if (board[i][j] == 0 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 0) {
				board_cal[i][j] = board_cal[i][j] - 7;
				board_cal[i - 4][j] = board_cal[i - 4][j] - 7;
			}
			if (board[i][j] == 0 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] ==2 && board[i][j - 4] == 0) {
				board_cal[i][j] = board_cal[i][j] - 7;
				board_cal[i][j - 4] = board_cal[i][j - 4] - 7;
			}
			if (board[i][j] == 0 && board[i - 1][j - 1] == 2&& board[i - 2][j - 2] ==2 && board[i - 3][j - 3] ==2 && board[i - 4][j - 4] == 0) {
				board_cal[i][j] = board_cal[i][j] - 7;
				board_cal[i - 4][j - 4] = board_cal[i - 4][j - 4] - 7;
			}
			if (board[i][j] == 0 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 0) {
				board_cal[i][j] = board_cal[i][j] - 7;
				board_cal[i - 4][j + 4] = board_cal[i - 4][j + 4] - 7;
			}

			//�ܡ�v�ܡ�
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
	for (i = 5; i < N - 5; i++)
	{
		for (j = 5; j < N - 5; j++)
		{
			//�ۡܡܡܡ�v
			if (board[i][j] == 2 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 3 && board[i + 5][j] == 0)
				board_cal[i + 5][j] = board_cal[i + 5][j] + 9;
			if (board[i][j] == 2 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 3 && board[i][j + 5] == 0)
				board_cal[i + 5][j] = board_cal[i + 5][j] + 9;
			if (board[i][j] == 2 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3 && board[i + 5][j + 5] == 0)
				board_cal[i + 5][j+5] = board_cal[i + 5][j+5] + 9;
			if (board[i][j] == 2 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3 && board[i + 5][j - 5] == 0)
				board_cal[i + 5][j-5] = board_cal[i + 5][j-5] + 9;
			if (board[i][j] == 2 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 3 && board[i - 5][j] == 0)
				board_cal[i - 5][j] = board_cal[i - 5][j] + 9;
			if (board[i][j] == 2 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 3 && board[i][j - 5] == 0)
				board_cal[i][j-5] = board_cal[i][j-5] + 9;
			if (board[i][j] == 2 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3 && board[i - 5][j - 5] == 0)
				board_cal[i -5][j-5] = board_cal[i - 5][j-5] + 9;
			if (board[i][j] == 2 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3 && board[i - 5][j + 5] == 0)
				board_cal[i - 5][j+5] = board_cal[i -5][j+5] + 9;
			
			//black
			if (board[i][j] == 3 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2 && board[i + 5][j] == 0)
				board_cal[i + 5][j] = board_cal[i + 5][j] - 9;
			if (board[i][j] == 3 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2 && board[i][j + 5] == 0)
				board_cal[i + 5][j] = board_cal[i + 5][j] - 9;
			if (board[i][j] == 3 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2 && board[i + 5][j + 5] == 0)
				board_cal[i + 5][j + 5] = board_cal[i + 5][j + 5] - 9;
			if (board[i][j] == 3 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2 && board[i + 5][j - 5] == 0)
				board_cal[i + 5][j - 5] = board_cal[i + 5][j - 5] - 9;
			if (board[i][j] == 3 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 2 && board[i - 5][j] == 0)
				board_cal[i - 5][j] = board_cal[i - 5][j] - 9;
			if (board[i][j] == 3 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 2 && board[i][j - 5] == 0)
				board_cal[i][j - 5] = board_cal[i][j - 5] - 9;
			if (board[i][j] == 3 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2 && board[i - 5][j - 5] == 0)
				board_cal[i - 5][j - 5] = board_cal[i - 5][j - 5] - 9;
			if (board[i][j] == 3 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2 && board[i - 5][j + 5] == 0)
				board_cal[i - 5][j + 5] = board_cal[i - 5][j + 5] - 9;

			//�ۡܡܡܡ�v//�����
			if (board[i][j] == 0 && board[i + 1][j] == 3 && board[i + 2][j] == 3 && board[i + 3][j] == 3 && board[i + 4][j] == 3 && board[i + 5][j] == 2)
				board_cal[i][j] = board_cal[i][j] + 9;
			if (board[i][j] == 0 && board[i][j + 1] == 3 && board[i][j + 2] == 3 && board[i][j + 3] == 3 && board[i][j + 4] == 3 && board[i][j + 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 9;
			if (board[i][j] == 0 && board[i + 1][j + 1] == 3 && board[i + 2][j + 2] == 3 && board[i + 3][j + 3] == 3 && board[i + 4][j + 4] == 3 && board[i + 5][j + 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 9;
			if (board[i][j] == 0 && board[i + 1][j - 1] == 3 && board[i + 2][j - 2] == 3 && board[i + 3][j - 3] == 3 && board[i + 4][j - 4] == 3 && board[i + 5][j - 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 9;
			if (board[i][j] == 0 && board[i - 1][j] == 3 && board[i - 2][j] == 3 && board[i - 3][j] == 3 && board[i - 4][j] == 3 && board[i - 5][j] == 2)
				board_cal[i][j] = board_cal[i][j] + 9;
			if (board[i][j] == 0 && board[i][j - 1] == 3 && board[i][j - 2] == 3 && board[i][j - 3] == 3 && board[i][j - 4] == 3 && board[i][j - 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 9;
			if (board[i][j] == 0 && board[i - 1][j - 1] == 3 && board[i - 2][j - 2] == 3 && board[i - 3][j - 3] == 3 && board[i - 4][j - 4] == 3 && board[i - 5][j - 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 9;
			if (board[i][j] == 0 && board[i - 1][j + 1] == 3 && board[i - 2][j + 2] == 3 && board[i - 3][j + 3] == 3 && board[i - 4][j + 4] == 3 && board[i - 5][j + 5] == 2)
				board_cal[i][j] = board_cal[i][j] + 9;

			//black
			if (board[i][j] == 0 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2 && board[i + 5][j] == 3)
				board_cal[i][j] = board_cal[i][j] - 9;
			if (board[i][j] == 0 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2 && board[i][j + 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 9;
			if (board[i][j] == 0 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2 && board[i + 5][j + 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 9;
			if (board[i][j] == 0 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2 && board[i + 5][j - 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 9;
			if (board[i][j] == 0 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2 && board[i - 4][j] == 2 && board[i - 5][j] == 3)
				board_cal[i][j] = board_cal[i][j] - 9;
			if (board[i][j] == 0 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2 && board[i][j - 4] == 2 && board[i][j - 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 9;
			if (board[i][j] == 0 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 2 && board[i - 5][j - 5] == 3)
				board_cal[i][j] = board_cal[i][j] - 9;
			if (board[i][j] == 0 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2 && board[i - 5][j + 5] == 3)
				board_cal[i][j] = board_cal[i][j] -9;
		}
	}
}


