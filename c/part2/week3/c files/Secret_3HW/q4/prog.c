/*********************************
* Class: MAGSHIMIM C2			 *
* Week 3           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>
#include <string.h>

void printArray(char* p, int len)
{
	char* ogp = p; // the original p
	
	for (p; p < ogp + len; p++)
	{
		printf("%c", *p);
	}
	printf("\n");
}

/*
	������ ��� ���� ������ ���� ���� �� ��� ���� �� ���� ����. �� ���� ��
	������ ��� ����� ��� ����� �� ������ ����� �������� ���� ���� ���� ����� ����� �� �������\
	����� ��� �� ���� ����� ���� ���� ����� (��� ���� �����) �� �� ��� ����

	����� ����� ������� ���� ������ �� ����
	���� ����
	sigal (I used the last question, the was 2...)
*/

int main(void)
{
	char* msg = "hi jyegq meet me at 2 :)";
	printArray(msg, strlen(msg));

	(void)getchar();
	return 0;
}