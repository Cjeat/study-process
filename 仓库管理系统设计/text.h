#pragma once
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
typedef struct coty {
	int gno;//��Ʒ���
	char name[40];//��Ʒ����
	float gprice;//��Ʒ�۸�
	int coy;//��Ʒ���
}co;

//**************�Ժ�����������*****************
void print();//��ӡ����
void prin(co*, int);//��ӡ��Ʒ��Ϣ
void inhouse(co * ,int );//���
void outhouse(co*, int );//����
int inquire(co*, int );//��ѯ
void sort(co*, int);//����
void revise(co*, int);//�޸�
void look(co*, int);
void color(const unsigned short);


