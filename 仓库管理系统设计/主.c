# define _CRT_SECURE_NO_WARNINGS 1
#include "text.h"


int main(){
	co data[40] = {
		{1001,"��ˢ",2.5,10},
		{1002,"����",5.0,12},
		{1003,"�ֽ�",4.0,34}
	}; 
	int num=0, len = sizeof(data) / sizeof(co);
	print();
	while (1) {
		printf("�������Ӧ���ܵ�����:(_____)\b\b\b\b");
		if(scanf("%d", &num) == 1){
			switch (num) {
			case 1:
				inhouse(data,len);
				print();
				break;
			case 2:
				outhouse(data,len);
				print();
				break;
			case 3:
				printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-��Ʒ��ѯ-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				inquire(data,len);
				print();
				break;
			case 4:
				sort(data,len);
				print();
				break;
			case 5:
				revise(data,len);
				print();
				break;
			case 6:
				look(data, len);
				print();
				break;
			case 0:
				return 0;
			}
		}
		else
		printf("��������1~5\n");
}
	return 0;
}