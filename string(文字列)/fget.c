#include <stdio.h>

int main(void)
{
	char str[80];  /* ���͂��ꂽ��������i�[����ꏊ */


	puts( "�������������͂��Ă��������B" );
	fgets( str, 80, stdin );

	/* ���͂��ꂽ����������̂܂܏o�͂��� */
	puts( str );
	getchar();
	return 0;
}