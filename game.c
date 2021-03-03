#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col) 
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++) 
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����������
void PrintingBoard(char board[ROW][COL], int row, int col)
{
	/*
		   |   |           ��
		---|---|---       �ָ��� 
	       |   |           ��
		---|---|---       �ָ���
		   |   |           ��
	*/
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		//��ӡ��
		int j = 0;
		for ( j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//��ӡ�ָ���
		if (i < row - 1)
		{
			for ( j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//�������
void PlayerChess(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������壺>\n");
	while (1)
	{
		printf("���������������:");
		scanf("%d%d", &x, &y);
		//�ж��������λ���Ƿ���ȷ
		if (x >= 0 && x <= row - 1  && y >= 0 && y <= col - 1)
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = '*';
				break;
			}
			else
			{
				printf("��λ���Ѿ������ӣ��볢������λ��\n");
			}
		}
		else
		{
			printf("����λ�ò���ȷ�����������룡\n");
		}
	}
}

//��������
void ComputerChess(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�������壺>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
//�ж��Ƿ�ȡ��ʤ��
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//������
	for ( i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//������
	for ( i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//ƽ��
	if (1 == IsFull(board,ROW,COL))
	{
		return 'Q';
	}
	return 'C';
}