/* ʹ�õ�ַ��������ָ������� */
#include <stdio.h>

int main(void) {
	int key = 0;								/* �������key */

	printf("Please input a integer:");
	scanf("%d", &key);							/* ����Ļ����һ������ֵ������key */
	printf("key\t= %d\n", key);					/* ���key��ֵ */

	printf("&key\t= %p\n", &key);				/* ��ӡkey�ĵ�ַ */
	printf("*(&key)\t= %d\n", *(&key));			/* ��ӡ��ַΪ&key���ڴ�ռ������ */

	return 0;
}
