#include"huff.h"
int main()
{
    huff_node a[100], *p,*root;			//���崢�����
    int count;							//count������������ݸ���
    int x,d;
    count = ReadData(a);				//���ú����õ�������ȷ�����溯������ȷ����
    QuickSort(a, 0, count - 1);	//ͨ����data����ж������п�������


    /*for (int i = 0; i <= 26; i++)					//��������
    {
        printf("%c %d\n", a[i].info, a[i].data);
    }*/


    p = toLink(a, count);				//ͨ���˺������������鶨��Ľṹ�����ӳ���������
    root = CreatHuff(p);				//��������������root�������Ķ���Ԫ�ء�



    /*for (int i = 0; i <= 26; i++)				//��������
    {
        printf("%c %d\n", a[i].info, a[i].data);
    }*/

    //�˵�ѡ��
    do
    {
        system("color 2");
        printf("*********************************�˵�*********************************\n");
        printf("***************************����������---�밴2*************************\n");
        printf("***************************��ʾ��������-�밴3*************************\n");
        printf("***************************����������---�밴4*************************\n");
        printf("**********************�����빦�����(�س�����ѡ��)********************\n");
        scanf("%d", &x);
        if (x == 2)
        {
            TreeEncode(root,p,count);			//����������������
        }//���ݹ��������������������

        if (x == 3)
        {
            system("color 3");
            DrawMain(root);					//����ͼ�λ�������
            system("pause");
        }
        if (x == 4)
        {
            TreeEncode(root, p, count);			//������������������
            decode(root);
            system("color 5");
        }
        system("color 4");
        printf("���������밴1���˳��밴-1\n");
        scanf("%d", &d);
        printf("***********************************************************************\n");
        system("cls");
    } while (d != -1);
    return 0;
}