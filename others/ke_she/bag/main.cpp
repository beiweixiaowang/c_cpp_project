#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct sq    //  ˳��ջ
{
    int elem[MAXSIZE];
    int top;
}Sqstack;



Sqstack *init()     //   ��ʼ��˳��ջ���ÿ�
{
    Sqstack *sq=(Sqstack *)malloc(sizeof(Sqstack));
    sq->top=0;
    return sq;
}
bool isEmpty(Sqstack *sq)    //     �ж�ջ�Ƿ�Ϊ��
{
    if(sq->top==0)
        return true;
    return false;
}
void push(Sqstack *sq , int x)      //    ��ջ
{
    if(sq->top==MAXSIZE)
    {
        printf("ջ��!������ջ��\n");
        return ;
    }
    sq->elem[sq->top++]=x;
}
int pop(Sqstack *sq)      //   ��վ
{
    if(isEmpty(sq))
    {
        printf("ջ��\n");
        exit(-1);
    }
    sq->top--;
    return sq->elem[sq->top];
}
int getTop(Sqstack *sq)//    ��ȡջ��Ԫ��
{
    return sq->elem[sq->top-1];
}
void knap(int n,int w[],int T)// ����������
{
    Sqstack *sq=init();
    bool v[]={false};
    int c=0;// �ⷨ����
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
                printf("��%d����ѡ������",++c);
                for(i=0;i<sq->top;i++)
                    printf("%d ",w[sq->elem[i]]);
                printf("��\n");
            }
            k=getTop(sq);
            k++;
            T+=w[pop(sq)];
        }while(!isEmpty(sq)||k<n);
    }
    if(c==0)
        printf("�޽⣡");
}
int main()
{
//    system("color 70");
    int T;//�������
    printf("�����뱳�������\n");
    scanf("%d",&T);
    int num;//��������
    printf("��������Ʒ������\n");
    scanf("%d",&num);
    int w[MAXSIZE];//�������������
    printf("�����뱳���ڸ������������\n");
    for(int i=0;i<num;i++)
        scanf("%d",&w[i]);
    knap(num,w,T);
    return 0;
}
