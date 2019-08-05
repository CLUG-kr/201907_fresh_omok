#define _CRT_SECURE_NO_WARNINGS
#include "omok.h"

int main()
{

	int board[N][N] = { 0 }; //�� ó�� ����� board.
	int board_cal[N][N] = { 0 };
	int xy[2] = { 0 };

	int x = 0;
	int y = 0;
	int ai_x, ai_y;

	int i,j;
	int whichplayer;//1�̸� �÷��̾ black, 2�̸� �÷��̾ white
	int best;
	int newt1 = 0;
	int now;
	int limit;

	do {
		printf("select Color(1.Black, 2.White) : ");
		scanf("%d", &whichplayer);
		printf("time limit? (second) : ");
		scanf("%d", &limit);
		system("cls");
	} while (whichplayer != 1 && whichplayer != 2);

	printBoard();//ù ȭ���� ����Ѵ�.

	if (whichplayer == 1)
	{
		while (1) {
			now = GetTickCount();
			do {
				printf("������ ��ǥ��? (�ð����� %d��) ->",limit);
				scanf("%d, %d", &y, &x);

				if (x >= N || y >= N || x < 1 || y < 1)
				{
					printf("Out of range, try again\n");//������ ����� ��
					fflush(stdin);
					continue;

				}
				else if (board[x][y] != 0)
				{
					printf("Not available, try again\n");//�̹� ���� �������� ��
					fflush(stdin);
					continue;
				}
				else
					break;
			} while (1);
						
			putStone(x, y, BLACK); //�浹 ��ǥ�� �޾� ���� ���´�.
			calculate(board_cal, board, BLACK, x, y, &ai_x, &ai_y); //

			if (blackwinTest() == 1)//�¸��ڰ� ���Դ��� Ȯ��
			{
				printf("black wins\n");
				break;
			}

			printf("��� �����...\n");
			
			putStone(ai_x, ai_y, WHITE);//�� ��ǥ�� ���� ���´�.
			calculate(board_cal, board, WHITE, ai_x, ai_y, &ai_x, &ai_y);

			if (whitewinTest() == 1)//�¸��ڰ� ���Դ��� üũ.
			{
				printf("white wins\n");
				break;
			}
		}
	}
	else if (whichplayer == 2)
	{
		putStone(10, 10, BLACK);//��ǻ�Ͱ� ���������� ����
		calculate(board_cal, board, BLACK, 10, 10, &ai_x, &ai_y);

		while (1) {
			now = GetTickCount();
			do {
				printf("��� ��ǥ��? (�ð����� %d��) ->",limit);
				scanf("%d, %d", &y, &x);

				if (x >= N || y >= N || x < 1 || y < 1)
				{
					printf("Out of range, try again\n");//������ ����� ��
					fflush(stdin);
					continue;

				}
				else if (board[x][y] != 0)
				{
					printf("Not available, try again\n");//�̹� ���� �������� ��
					fflush(stdin);
					continue;
				}
				else
					break;
			} while (1);

			putStone(x, y, WHITE);
			calculate(board_cal, board, WHITE, x, y, &ai_x, &ai_y);
			
			if (whitewinTest() == 1)//�¸��ڰ� ���Դ��� üũ.
			{
				printf("white wins\n");
				break;
			}

			printf("������ �����...\n");

			putStone(ai_x, ai_y, BLACK);//�� ��ǥ�� ���� ���´�.
			calculate(board_cal, board, BLACK, ai_x, ai_y, &ai_x, &ai_y);
			
			if (blackwinTest() == 1)//�¸��ڰ� ���Դ��� üũ.
			{
				printf("black wins\n");
				break;
			}
		}

	}
	
	
	fflush(stdin);
	getch();
	return 0;

	
}