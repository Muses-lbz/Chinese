/* ʹ��extern�������� */
#include <stdio.h>

int main(void) {
	extern int data;				/* ����һ������data */
	printf("data = %d\n", data);	/* ���data��ֵ */

	return 0;
}

int data = 23;						/* �������data */