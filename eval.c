#define _CRT_SECURE_NO_WARNINGS
#include "omok.h"

int eval(NODE * node) // �ش� ��尡 ������ �ִ� board�� ��ġ�� ���ϴ� �Լ�
{
	int i, j;
	int val = 0;
	int val2 = 0;

	//�� ��ġ �� �Լ� ����for���� ¯ ���� ������ (���⼭ �ð� �ǰ� ���� �Ҹ��� �� ����)
	//�Ҹ�ð� ���̷��� for���� �߿��� ���� ���� �͵鳢�� ���� �� ���� �� 
	//�׷��� �������� ��ġ�򰡿� ���� �ð� �� �� �� ���� > ������
	//�� ���Ƽ� �ϳ��� �Լ��� ���� ������/�� �Լ��� ������ ������... �׷� �ð� ���� �ɸ�����?��,��
	//white�� ������ 2�� black, 3�� white

	for (i = 3; i < N - 3; i++)
	{
		for (j = 3; j < N - 3; j++)
		{
			//v�ܡ�v
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

			//v�ۡ�v
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
			//v�ۡ�v
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

			//v�ܡ�v
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
			//�ܡܡܡܡ�
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
			//�ܡܡܡܡ�
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
			//�ۡܡ�
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

			//�ۡ� ��
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

			//�ۡ�  ��
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

			//�ۡ�   ��
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

			//vv�ܡ�vv
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
			
			//�� �ܡ�
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

			//�� ��  �� 
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

			//�ۡܡܡ�vv
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

			//�ۡܡ�v��v
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

			//�ۡ�v�ܡ�v
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

			//�ۡ�v��v��
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

			//��v�ܡܡܡ�
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

			//�ۡܡܡܡ�v
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

			//��v�ܡܡ�v
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

			//v�ܡܡܡ�v
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

			//�ܡܡܡܡܡ�
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
			//vv�ܡ�vv
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

			//�ۡܡܡ�vv
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

			//�ۡܡ�v��v
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

			//�ۡ�v�ܡ�v
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

			//�ۡ�v��v��
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

			//�ۡܡܡܡ�v
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

			//v�ܡܡܡ�v
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

			//��v�ܡܡ�v
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

			//��v�ܡܡܡ�
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

			//�ܡܡܡܡܡ�
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

			//�� ��  �� 
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
			//�� �� ��
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

			//�� �� �� ��
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

			//�� ��   �� 
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

			//vv��v��vv
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

			//�ۡܡ�vv�ܡ�
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

			//�ۡܡ�vv��v
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

			//�ۡ�vv�ܡ�v
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

			//��v�ܡܡ�vv
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

			//��v�ܡܡ�v��
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

			//vv�ܡܡ�vv
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

			//�ۡܡ�v�ܡܡ�
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

			//�ۡܡ�v�ܡ�v
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

			//v�ܡ�v�ܡ�v
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

			//�ܡܡܡܡܡܡ�
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
			//�� �� ��
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

			//�� �� �� ��
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

			//�� ��   �� 
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

			//vv��v��vv
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

			//�ۡܡ�vv�ܡ�
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

			//�ۡܡ�vv��v
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

			//�ۡ�vv�ܡ�v
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

			//��v�ܡܡ�vv
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

			//��v�ܡܡ�v��
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

			//vv�ܡܡ�vv
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

			//�ۡܡ�v�ܡܡ�
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

			//�ۡܡ�v�ܡ�v
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

			//v�ܡ�v�ܡ�v
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

			//�ܡܡܡܡܡܡ�
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
			//vv��vv��vv
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

			//��v�ܡ�v��vv
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

			//��v�ܡ�v��v��
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

			//��v�ܡ�vv��v
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

			//��v��v�ܡ�vv
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

			//��v��vv�ܡ�v
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

			//vv��v�ܡ�vv
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
			//vv��vv��vv
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

			//vv��v�ܡ�vv
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

			//��v�ܡ�v��vv
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

			//��v�ܡ�v��v��
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

			//��v�ܡ�vv��v
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

			//��v��v�ܡ�vv
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

			//��v��vv�ܡ�v
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
			//vv��vvv��vv
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

			//��v��v��v��v��
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

			//��v��v��v��vv
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

			//vv��vv�ܡ�vv
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

			//vv��v��v��vv
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

			//�ۡ�v��v��v�ܡ�
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

			//�ۡ�v��v��v��v
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

			//v��v��v��v��v
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
			//vv��vvv��vv
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

			//��v��v��v��v��
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

			//��v��v��v��vv
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

			//vv��vv�ܡ�vv
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

			//vv��v��v��vv
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

			//�ۡ�v��v��v�ܡ�
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

			//�ۡ�v��v��v��v
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

			//v��v��v��v��v
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


