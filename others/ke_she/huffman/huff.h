#pragma once

#include<cstdio>
#include<cstdlib>
#include<Windows.h>
//#include <graphics.h>  // 引用图形库头文件，此头文件用来进行图形化界面的设计
#include <conio.h>	 // 引用图形库头文件，此头文件进行图形化界面设计。
#include<cmath>
#include<ctime>

typedef struct node
{
    char info;				//储存字符
    int data;				//储存权值
    char encode[20];		//储存其二叉编码
    node *lchild, *rchild, *next, *parent;
}huff_node;

typedef struct stack
{
    int data[100];
    int top;
}stack_1;

void QuickSort(huff_node y[], int left, int right); //数组元素快速排序
huff_node *toLink(huff_node a[], int count); //将排序后的数组元素用链表连起来
int ReadData(huff_node x[]);	//从文件读取数据
huff_node *insert(huff_node * root, huff_node *s);	//取两最小节点将节点插入
huff_node *CreatHuff(huff_node * root);	// 生成哈夫曼树的创建函数
void TreeEncode(huff_node *t, huff_node *h, int count); //用树来编码
void decode(huff_node tree[]);	//解码
void init(stack *s);//栈初始化
void push(stack *s, int  a);//压栈
int pop(stack *s);//弹栈
void draw(int x, int y, char c);//画结点
void DrawDemo(huff_node *s, int x, int y, int temp, int suojian);  //画树
void DrawMain(huff_node *s); //图形化界面主函数

