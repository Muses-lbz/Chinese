/* ��֤���ͣ�����������һ�£��ɴ洢����ֵ��Χ */
#include <stdio.h>

int main(void)
{
	int maxInt = 2147483647;
	int minInt = -2147483648;

	unsigned maxUnsInt = 4294967295;
	unsigned minUnsInt = 0;

	printf("Max(int) = %d\n", maxInt);
	printf("Max - 1 = %d\n\n", maxInt - 1);				/* ��� */

	printf("Min(int) = %d\n", minInt);
	printf("Min + 1 = %d\n", minInt + 1); 					/* ��� */

	printf("Max(unsigned int) = %u\n", maxUnsInt);
	printf("Max + 1 = %u\n\n", maxUnsInt + 1); 			/* ��� */

	printf("Min(unsigned int) = %u\n", minUnsInt);
	printf("Min - 1 = %u\n\n", minUnsInt - 1); 				/* ��� */

	return 0;
}
