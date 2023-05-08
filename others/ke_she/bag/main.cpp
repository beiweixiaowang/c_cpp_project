#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct sq    //  顺序栈
{
    int elem[MAXSIZE];
    int top;
}Sqstack;



Sqstack *init()     //   初始化顺序栈并置空
{
    Sqstack *sq=(Sqstack *)malloc(sizeof(Sqstack));
    sq->top=0;
    return sq;
}
bool isEmpty(Sqstack *sq)    //     判断栈是否为空
{
    if(sq->top==0)
        return true;
    return false;
}
void push(Sqstack *sq , int x)      //    入栈
{
    if(sq->top==MAXSIZE)
    {
        printf("栈满!不能入栈！\n");
        return ;
    }
    sq->elem[sq->top++]=x;
}
int pop(Sqstack *sq)      //   出站
{
    if(isEmpty(sq))
    {
        printf("栈空\n");
        exit(-1);
    }
    sq->top--;
    return sq->elem[sq->top];
}
int getTop(Sqstack *sq)//    获取栈顶元素
{
    return sq->elem[sq->top-1];
}
void knap(int n,int w[],int T)// 背包问题解决
{
    Sqstack *sq=init();
    bool v[]={false};
    int c=0;// 解法个数
    for(int i=0;i<n;i++)
    {
        int k=i;
        do
        {
            while(T>0&&k<n)
            {
                push(sq,k);
                T-=w[k++];
            }
            if(T==0)
            {
                printf("第%d种挑选方法（",++c);
                for(i=0;i<sq->top;i++)
                    printf("%d ",w[sq->elem[i]]);
                printf("）\n");
            }
            k=getTop(sq);
            k++;
            T+=w[pop(sq)];
        }while(!isEmpty(sq)||k<n);
    }
    if(c==0)
        printf("无解！");
}
int main()
{
//    system("color 70");
    int T;//背包体积
    printf("请输入背包体积：\n");
    scanf("%d",&T);
    int num;//背包个数
    printf("请输入物品个数：\n");
    scanf("%d",&num);
    int w[MAXSIZE];//背包内物体体积
    printf("请输入背包内各个物体体积：\n");
    for(int i=0;i<num;i++)
        scanf("%d",&w[i]);
    knap(num,w,T);
    return 0;
}
