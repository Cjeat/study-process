# define _CRT_SECURE_NO_WARNINGS 1
#include "text.h"
void print() {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("				    |�б�ѡ��|\n");
	printf("		**************************************************\n");
	printf("		**	(1����Ʒ���		(2����Ʒ����    **\n");
	printf("		**	(3����Ʒ��ѯ		(4)��Ʒ��Ϣ���� **\n");
	printf("		**	(5) ��Ʒ��Ϣ�޸�	(6)�鿴		**\n");
	printf("		**	(0���˳�				**\n");
	printf("		**************************************************\n");
}
void prin(co* Data, int i) {
	//printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	color(4);
	printf("�Ѵ�\t�����:%d��\t������:%s��\t������:%f��\t�����:%d��\n",
		(Data + i)->gno, (Data + i)->name, (Data + i)->gprice, (Data + i)->coy);
	color(2);
	//printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}
void inhouse(co* Data,int Len) {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-��Ʒ���-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	int i = 0,num = 0 ;
	char a;
	printf("�������ţ�(_______)\b\b\b\b\b\b");
	scanf("%d", &num);
	for (i = 0; i < Len ; i++)
	{
		if ((Data + i)->gno == num) {
			prin(Data, i);
			printf("�������������");
			scanf("%d", &num);
			(Data + i)->coy += num;
			prin(Data, i);
			break;
		}
		else if((Data + i)->gno == 0) {
			printf("�ֿ��޴���Ʒ���Ƿ�¼�루Y/N):");
			getchar();
			a = getchar();
			if (a=='Y'||a=='y') {
				(Data + i)->gno = num;
				getchar();
				printf("��¼����Ʒ���ƣ�--------------(_______)\b\b\b\b\b\b");
				scanf("%s",(Data + i)->name);
				printf("���ۣ�------------------------(_______)\b\b\b\b\b\b");
				scanf("%f", &(Data + i)->gprice);
				printf("���������--------------------(_______)\b\b\b\b\b\b");
				scanf("%d", &(Data + i)->coy);
				prin(Data, i);
			}
			break;
		}
	}
}
void outhouse(co* Data, int Len) {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-��Ʒ����-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	int num,i,j;
	printf("�����������Ʒ��:");
	scanf("%d", &num);
	for (i = 0; i<40 && (Data + i)->gno != 0; i++) {
		if (num == (Data + i)->gno) {
			prin(Data, i);
			printf("��������Ϊ:");
			scanf("%d", &num);
			if ((Data + i)->coy < num)
				printf("û����ô��Ŀ��!!!!!\n");
			else {
				(Data + i)->coy -= num;
				prin(Data, i);
					if ((Data + i)->coy == 0) {
						for (j = i; j < 40; j++) {
							*(Data + j) = *(Data + j + 1);
						}
					}
					break;
			}
		}
	}
	if (i == 40)
		printf("�޴���Ʒ\n");
}
int inquire(co* Data,int Len) {
	int num , i ;
	char Name[20];
	printf("��Ų�ѯ��1����Ʒ����ѯ��0):");
	scanf("%d", &num);
	if (1 == num) {
		printf("��������:");
		scanf("%d", &num);
		for (i = 0;i<40; i++) {
			if ((Data + i)->gno == num) {
				prin(Data, i);
				return (Data + i)->gno;
			}
		}
		if (i == 40)
			printf("�޴���Ʒ!!!\n");
	}
	else if (0 == num) {
		printf("��������Ʒ��:");
		scanf("%s", Name);
		for (i = 0; i < 40; i++) {
			if (strcmp((Data + i)->name, Name) == 0) {
				prin(Data, i);
				return (Data + i)->gno;
			}
		}
		if (i == 40)
			printf("�޴˲�Ʒ����!");
	}
	else
		printf("���벻�Ϸ�������");
}
void sort(co* Data, int Len) {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-��Ʒ����-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	int i,j;
	co DATa={0,"0",0,0};
	co* DATA = &DATa;//�����м����
	printf("����ǰ\n");
	for (i = 0; ((Data + i)->gno != 0) && i < 40; i++) {
		prin(Data, i);//��Ϣ��ӡ
	}
	printf("�۸���\n");
	for (i = 0; ((Data+i)->gno!=0) && i < 39; i++) {
		for (j = i+1; ((Data + j)->gno != 0) && j < 40; j++) {//��������
			if ((Data + i)->gprice <= (Data + j)->gprice) {
				*DATA = *(Data + i);
				*(Data + i) = *(Data + j);
				*(Data + j) = *DATA;
			}
		}
	}
	for (i = 0; ((Data + i)->gno != 0) && i < 40; i++) {
		prin(Data, i);//������ӡ���
	}
}
void revise(co* Data, int Len) {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-��Ʒ��Ϣ�޸�-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	int num,i;
	num =inquire(Data, Len);//���ò�ѯ
	for (i = 0; ((Data + i)->gno != 0) && i < 40; i++) {
		if ((Data + i)->gno == num) {//��ȷ������Ʒ�����޸�
			printf("��Ʒ���޸�Ϊ:(_______)\b\b\b\b\b\b");
			scanf("%s", &(Data + i)->name);
			printf("�۸��޸�Ϊ:  (_______)\b\b\b\b\b\b");
			scanf("%f", &(Data + i)->gprice);
			printf("������޸�Ϊ:(_______)\b\b\b\b\b\b");
			scanf("%d", &(Data + i)->coy);
			printf("�޸ĺ�:");
			prin(Data, i);
			break;
		}
	}
}
void look(co* data, int len)
{
	int i;
	for (i = 0; ((data + i)->gno != 0) && i < 40; i++) {
		prin(data, i);
	}
}
void color(const unsigned short textColor)
{
	if (textColor >= 0 && textColor <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
