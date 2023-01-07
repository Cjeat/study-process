# define _CRT_SECURE_NO_WARNINGS 1
#include "text.h"
void print() {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("				    |列表选项|\n");
	printf("		**************************************************\n");
	printf("		**	(1）商品入库		(2）商品出库    **\n");
	printf("		**	(3）商品查询		(4)商品信息排序 **\n");
	printf("		**	(5) 商品信息修改	(6)查看		**\n");
	printf("		**	(0）退出				**\n");
	printf("		**************************************************\n");
}
void prin(co* Data, int i) {
	//printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	color(4);
	printf("已存\t【编号:%d】\t【名称:%s】\t【单价:%f】\t【库存:%d】\n",
		(Data + i)->gno, (Data + i)->name, (Data + i)->gprice, (Data + i)->coy);
	color(2);
	//printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}
void inhouse(co* Data,int Len) {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-商品入库-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	int i = 0,num = 0 ;
	char a;
	printf("请输入编号：(_______)\b\b\b\b\b\b");
	scanf("%d", &num);
	for (i = 0; i < Len ; i++)
	{
		if ((Data + i)->gno == num) {
			prin(Data, i);
			printf("输入入库数量：");
			scanf("%d", &num);
			(Data + i)->coy += num;
			prin(Data, i);
			break;
		}
		else if((Data + i)->gno == 0) {
			printf("仓库无此商品，是否录入（Y/N):");
			getchar();
			a = getchar();
			if (a=='Y'||a=='y') {
				(Data + i)->gno = num;
				getchar();
				printf("请录入商品名称：--------------(_______)\b\b\b\b\b\b");
				scanf("%s",(Data + i)->name);
				printf("单价：------------------------(_______)\b\b\b\b\b\b");
				scanf("%f", &(Data + i)->gprice);
				printf("入库数量：--------------------(_______)\b\b\b\b\b\b");
				scanf("%d", &(Data + i)->coy);
				prin(Data, i);
			}
			break;
		}
	}
}
void outhouse(co* Data, int Len) {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-商品出库-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	int num,i,j;
	printf("请输入出库商品号:");
	scanf("%d", &num);
	for (i = 0; i<40 && (Data + i)->gno != 0; i++) {
		if (num == (Data + i)->gno) {
			prin(Data, i);
			printf("出库数量为:");
			scanf("%d", &num);
			if ((Data + i)->coy < num)
				printf("没有那么多的库存!!!!!\n");
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
		printf("无此商品\n");
}
int inquire(co* Data,int Len) {
	int num , i ;
	char Name[20];
	printf("编号查询（1）商品名查询（0):");
	scanf("%d", &num);
	if (1 == num) {
		printf("请输入编号:");
		scanf("%d", &num);
		for (i = 0;i<40; i++) {
			if ((Data + i)->gno == num) {
				prin(Data, i);
				return (Data + i)->gno;
			}
		}
		if (i == 40)
			printf("无此商品!!!\n");
	}
	else if (0 == num) {
		printf("请输入商品名:");
		scanf("%s", Name);
		for (i = 0; i < 40; i++) {
			if (strcmp((Data + i)->name, Name) == 0) {
				prin(Data, i);
				return (Data + i)->gno;
			}
		}
		if (i == 40)
			printf("无此部品！！!");
	}
	else
		printf("请入不合法！！！");
}
void sort(co* Data, int Len) {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-商品排序-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	int i,j;
	co DATa={0,"0",0,0};
	co* DATA = &DATa;//排序中间变量
	printf("排序前\n");
	for (i = 0; ((Data + i)->gno != 0) && i < 40; i++) {
		prin(Data, i);//信息打印
	}
	printf("价格降序\n");
	for (i = 0; ((Data+i)->gno!=0) && i < 39; i++) {
		for (j = i+1; ((Data + j)->gno != 0) && j < 40; j++) {//进行排序
			if ((Data + i)->gprice <= (Data + j)->gprice) {
				*DATA = *(Data + i);
				*(Data + i) = *(Data + j);
				*(Data + j) = *DATA;
			}
		}
	}
	for (i = 0; ((Data + i)->gno != 0) && i < 40; i++) {
		prin(Data, i);//排序后打印输出
	}
}
void revise(co* Data, int Len) {
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-商品信息修改-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	int num,i;
	num =inquire(Data, Len);//调用查询
	for (i = 0; ((Data + i)->gno != 0) && i < 40; i++) {
		if ((Data + i)->gno == num) {//对确定的商品进行修改
			printf("商品名修改为:(_______)\b\b\b\b\b\b");
			scanf("%s", &(Data + i)->name);
			printf("价格修改为:  (_______)\b\b\b\b\b\b");
			scanf("%f", &(Data + i)->gprice);
			printf("库存量修改为:(_______)\b\b\b\b\b\b");
			scanf("%d", &(Data + i)->coy);
			printf("修改后:");
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
