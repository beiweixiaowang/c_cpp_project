#include "huff.h"
//#include <graphics.h>

void QuickSort(huff_node y[], int left, int right) //数组元素快速排序
{
    huff_node x;
    int i, j, flag = 1;
    if (left < right)
    {
        i = left;
        j = right;
        x = y[i];
        while (i < j)
        {
            while (i < j&&x.data < y[j].data)
                j--;
            if (i < j)
                y[i++] = y[j];
            while (i < j&&x.data > y[i].data)
                i++;
            if (i < j)
                y[j--] = y[i];
        }
        y[i] = x;
        QuickSort(y, left, i - 1);		//递归实现
        QuickSort(y, i + 1, right);		//递归实现
    }
}

huff_node *toLink(huff_node a[], int count) //将排序后的数组元素用链表连起来
{
    node *h = NULL, *q = NULL, *p = NULL;
    int  i;
    for (i = 0; i < count; i++)
    {
        p = (node *)malloc(sizeof(node));
        p->info = a[i].info;
        p->data = a[i].data;
        p->lchild = NULL;
        p->rchild = NULL;
        p->next = NULL;
        if (i == 0)
        {
            h = p; q = p;
        }
        else
        {
            q->next = p; q = p;
        }
    }
    return h;
}


int ReadData(huff_node x[])	//从文件读取数据
{
    char ch;
    int fru;
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("文件打开失败！");
        return 0;
    }
    int i = 0;
    while (fscanf(fp, "%c %d\n", &ch, &fru) >= 0)
    {
        x[i].info = ch;
        x[i].data = fru;
        i++;
    }
    /*for (int j = 0; j < i; j++)
    {
        printf("%c %d\n", x[j].info, x[j].data);
    }
    printf("读取成功！\n");*/
    return i;
}
huff_node *insert(huff_node * root, huff_node *s)//取两最小节点将节点插入
{
    huff_node *p1, *p2;
    if (root == NULL)
        root = s;
    else
    {
        p1 = NULL;
        p2 = root;
        while (p2&&p2->data < s->data)
        {
            p1 = p2;
            p2 = p2->next;
        }
        s->next = p2;
        if (p1 == NULL)
            root = s;
        else
            p1->next = s;
    }
    return root;
}


huff_node *CreatHuff(huff_node * root)	// 生成哈夫曼树的创建函数
{
    huff_node *s, *rl, *rr,*root1;
    root1 = root;
    while (root&&root->next)
    {
        rl = root;
        rr = root->next;
        root = rr->next;
        s = (huff_node *)malloc(sizeof(huff_node));
        s->parent = NULL;
        rl->parent = s;
        rr->parent = s;
        s->info = NULL;
        s->next = NULL;
        s->data = rl->data + rr->data;
        s->lchild = rl;
        s->rchild = rr;
        root = insert(root, s);
    }
    printf("创建完成！\n");
    return root;
}

void TreeEncode(huff_node *t, huff_node *h, int count) //用树来编码
{
    int i = 0, j = 0;
    huff_node *p, *q, *tmp;
    stack s;
    init(&s);
    p = h;
    q = h;
    while ( p != NULL)
    {
        q = p;
        while (q != t)
        {
            tmp = q;
            q = q -> parent;
            if (q->lchild == tmp)
            {
                push(&s, 0);
            }
            if (q->rchild == tmp)
            {
                push(&s, 1);
            }
        }
        j = 0;
        for(j = 0; s.top > 0; j++)
        {
            p->encode[j] = pop(&s);
        }
        p->encode[j] = 2;
        if (p->info != NULL)
        {
            printf("%c ", p->info);
            for (j = 0; p->encode[j] != 2; j++)
            {
                printf("%d", p->encode[j]);
            }
            printf("\n");
        }
        p = p->next;
    }
}



/*
  此部分为哈夫曼译码，实现思想，从树的顶点开始遍历，如果碰到输入为0则走向左子树，
  如果碰到1就走向其右子树，检测是否结束，结束的话再次将指针指到root结点遍历，直
  到碰到终止条件：用户输入2。
*/
void decode(huff_node tree[]){  //依次读入，根据哈夫曼树译码
    huff_node *t;
    int i = 0, j = 0;
    char b[200];
    char end_flag = '2';
    getchar();
    printf("输入编码(以’2‘为标志结束）：");
    gets(b);
    printf("译码后的字符为：\n");
    while (b[j] != '2'){
        if (b[j] == '0') {
            t = t->lchild; //走向左孩子
        }
        else{
            t = t->rchild; //走向右孩子
        }
        if (t->lchild == NULL) {  //tree[i]是叶结点
            printf("%c", t->info); 	//回到根结点
            t = &tree[0];
        }
        j++;
    }
    printf("\n");
    if (tree[j].lchild != NULL && b[j] != '2')			//读完，但尚未到叶子结点
        printf("\n您输入的电文有错请重新输入!\n");		//输入电文有错
}





void init(stack *s)//栈初始化
{
    s->top = 0;
}
void push(stack *s, int  a)//压栈
{
    s->data[s->top++] = a;
}
int pop(stack *s)//弹栈
{
    s->top--;
    return(s->data[s->top]);
}

//void draw(int x, int y, char c)//画结点
//{
//    circle(x, y, 10); Sleep(100);//画圈并暂停100ms
//    outtextxy(x - 5, y - 7, c);   //输出元素
//}
//
//void DrawDemo(huff_node *s, int x, int y, int temp, int suojian)  //画树
//{
//    if (s != NULL && s->info != 'J'&&s->info != 'Z') //避免结点过多J，Z节点重合
//        draw(x, y, s->info);
//    if (s->lchild != NULL)
//    {
//        if (s->lchild->info != 'J')
//        {
//            suojian += 4;//缩减值自增
//            line(x - 8, y + 8, x - temp / suojian, y + 50 - 10);
//            outtextxy(x - (8 + temp / suojian) / 2, y + 19, '0');
//            Sleep(10);//画线并暂停10ms
//            DrawDemo(s->lchild, x - temp / suojian, y + 50, temp, suojian);//递归调用左子树
//        }
//        else
//        {
//            line(x - 8, y + 8, x - 25, y + 50 - 10);
//            outtextxy(x - 25, y + 19, '0');
//            Sleep(10);
//            draw(x - 25, y + 50, s->lchild->info);
//        }   //使J，Z节点分隔开
//    }
//    suojian -= 4;
//    if (s->rchild != NULL)
//    {
//        if (s->rchild->info != 'Z')
//        {
//            suojian += 4;//缩减值自增
//            line(x + 8, y + 8, x + temp / suojian, y + 50 - 10);
//            outtextxy(x + (8 + temp / suojian) / 2, y + 19, '1');
//            Sleep(10);//画线并暂停10ms
//            DrawDemo(s->rchild, x + temp / suojian, y + 50, temp, suojian);//递归调用右子树
//        }
//        else
//        {
//            line(x + 8, y + 8, x + 25, y + 50 - 10);
//            outtextxy(x + 25, y + 19, '1');
//            Sleep(10);
//            draw(x + 25, y + 50, s->rchild->info);
//        }   //使J，Z节点分隔开
//    }
//    suojian -= 4;
//}
//
//void DrawMain(huff_node *s)//图形化界面主函数
//{
//    int a = 1400;
//    int b = 0;
//    initgraph(1920, 1080);			// 创建绘图窗口，SHOWCONSOLE
//    setbkcolor(WHITE);			// 设置背景填充颜色
//    cleardevice();						//进行填充
//    setcolor(BLACK);
//    DrawDemo(s, 860, 20, a, b);				//递归调用画树的子文件
//    _getch();						 // 检测键盘输入时间。
//    closegraph();					 // 关闭绘图窗口
//}