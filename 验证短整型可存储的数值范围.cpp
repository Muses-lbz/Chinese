/* ��֤�����Ϳɴ洢����ֵ��Χ */
#include <stdio.h>

int main(void)
{
	short int maxShortInt = 32767;
	short int minShortInt = -32768;

	unsigned short int maxUnsShortInt = 65535;
	unsigned short int minUnsShortInt = 0;

	printf("Max = %hd\n", maxShortInt);
	printf("Max + 1 = %hd\n\n", maxShortInt + 1); 				/* ��� */

	printf("Min = %hd\n", minShortInt);
	printf("Min - 1 = %hd\n", minShortInt - 1); 					/* ��� */

	printf("Max(unsigned short int) = %hu\n", maxUnsShortInt);
	printf("Max + 1 = %hu\n\n", maxUnsShortInt + 1); 			/* ��� */

	printf("Min(unsigned short int) = %hu\n", minUnsShortInt);
	printf("Min - 1 = %hu\n", minUnsShortInt - 1); 				/* ��� */

	return 0;
}
