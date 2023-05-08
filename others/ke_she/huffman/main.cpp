#include"huff.h"
int main()
{
    huff_node a[100], *p,*root;			//定义储存变量
    int count;							//count用来存放总数据个数
    int x,d;
    count = ReadData(a);				//调用函数得到个数，确保下面函数的正确运行
    QuickSort(a, 0, count - 1);	//通过将data域的判断来进行快速排序


    /*for (int i = 0; i <= 26; i++)					//测试用例
    {
        printf("%c %d\n", a[i].info, a[i].data);
    }*/


    p = toLink(a, count);				//通过此函数将上面数组定义的结构体连接成有序链表
    root = CreatHuff(p);				//创建哈夫曼树，root保存树的顶点元素。



    /*for (int i = 0; i <= 26; i++)				//测试用例
    {
        printf("%c %d\n", a[i].info, a[i].data);
    }*/

    //菜单选项
    do
    {
        system("color 2");
        printf("*********************************菜单*********************************\n");
        printf("***************************哈夫曼编码---请按2*************************\n");
        printf("***************************显示哈夫曼树-请按3*************************\n");
        printf("***************************哈夫曼译码---请按4*************************\n");
        printf("**********************请输入功能序号(回车进行选择)********************\n");
        scanf("%d", &x);
        if (x == 2)
        {
            TreeEncode(root,p,count);			//哈夫曼编码主函数
        }//根据哈夫曼树求出哈夫曼编码

        if (x == 3)
        {
            system("color 3");
            DrawMain(root);					//调用图形化主函数
            system("pause");
        }
        if (x == 4)
        {
            TreeEncode(root, p, count);			//哈夫曼解码主函数。
            decode(root);
            system("color 5");
        }
        system("color 4");
        printf("继续操作请按1，退出请按-1\n");
        scanf("%d", &d);
        printf("***********************************************************************\n");
        system("cls");
    } while (d != -1);
    return 0;
}