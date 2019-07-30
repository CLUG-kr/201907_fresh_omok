#include "omok.h"

int main()
{

	int board[N][N] = { 0 }; //�� ó�� ����� board.
	
	int x, y;

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
				scanf("%d,%d", &x, &y);

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
						
			if (GetTickCount() - now > limit*1000)//�ð�����
			{
				printf("time over, white wins\n");
				break;
			}
			putStone(x, y, BLACK); //�浹 ��ǥ�� �޾� ���� ���´�.
			if (blackwinTest() == 1)//�¸��ڰ� ���Դ��� Ȯ��
			{
				printf("black wins\n");
				break;
			}

			printf("��� �����...\n");
			now = GetTickCount();
			NODE * t1 = createNode(x, y, board, BLACK);//�浹�� �������� root ���� �����.
			board[x][y] = 2;//�浹�� ���ΰ��� 2�� ����

			t1 = createTree(t1,5, 2);//depth�� 5�� Ʈ���� �����.
			for (i = 0; i < 3; i++)//1,3,5���̷� Search
			{
				newt1 = alphabeta(t1, i*2+1, INT_MIN, INT_MAX, false);
				if (GetTickCount() - now > limit*1000)
					break;
			}
			if (GetTickCount() - now > limit*1000)
			{
				printf("time over, black wins\n");
				break;
			}
			putStone(t1->child[t1->next]->x, t1->child[t1->next]->y, WHITE);//�� ��ǥ�� ���� ���´�.
			board[t1->child[t1->next]->x][t1->child[t1->next]->y] = WHITE;//���忡 3�� ����.
			if (whitewinTest() == 1)//�¸��ڰ� ���Դ��� üũ.
			{
				printf("white wins\n");
				break;
			}
		
			destroyTree(t1);//Ʈ���� ����


		}
	}
	else if (whichplayer == 2)
	{
		putStone(10, 10, BLACK);//��ǻ�Ͱ� ���������� ����
		board[10][10] = BLACK;

		while (1) {
			now = GetTickCount();
			do {
				printf("��� ��ǥ��? (�ð����� %d��) ->",limit);
				scanf("%d,%d", &x, &y);

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


			if (GetTickCount() - now > limit*1000)//�ð�����30��
			{
				printf("time over, black wins\n");
				break;
			}

			putStone(x, y, WHITE); //�浹 ��ǥ�� �޾� ���� ���´�.
			if (whitewinTest() == 1)//�¸��ڰ� ���Դ��� Ȯ��
			{
				printf("white wins\n");
				break;
			}

			now = GetTickCount();
			printf("������ �����...\n");
			NODE * t1 = createNode(x, y, board, WHITE);//�鵹�� �������� root ���� �����.
			board[x][y] = WHITE;//�鵹�� ���ΰ��� 3�� ����


			t1 = createTree(t1, 5, 2);//depth�� 5�� Ʈ���� �����.
			for (i = 0; i < 3; i++)//1,3,5���̷� Search
			{
				newt1 = alphabeta(t1, i * 2 + 1, INT_MIN, INT_MAX, true);
				if (GetTickCount() - now > limit*1000)
					break;
			}
			if (GetTickCount() - now > limit*1000)
			{
				printf("time over, white wins\n");
				break;
			}
			
			putStone(t1->child[t1->next]->x, t1->child[t1->next]->y, BLACK);//�� ��ǥ�� ���� ���´�.
			board[t1->child[t1->next]->x][t1->child[t1->next]->y] = BLACK;//���忡 3�� ����.

			if (blackwinTest() == 1)//�¸��ڰ� ���Դ��� üũ.
			{
				printf("black wins\n");
				break;
			}
			destroyTree(t1);//Ʈ���� ����


		}

	}
	
	
	fflush(stdin);
	getch();
	return 0;

	
}