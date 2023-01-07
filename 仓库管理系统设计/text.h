#pragma once
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
typedef struct coty {
	int gno;//商品编号
	char name[40];//商品名称
	float gprice;//商品价格
	int coy;//商品库存
}co;

//**************对函数进行声明*****************
void print();//打印界面
void prin(co*, int);//打印商品信息
void inhouse(co * ,int );//入库
void outhouse(co*, int );//出库
int inquire(co*, int );//查询
void sort(co*, int);//排序
void revise(co*, int);//修改
void look(co*, int);
void color(const unsigned short);


