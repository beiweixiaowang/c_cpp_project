#include "AVL.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "ƽ�������" << endl;
    int arr[] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
    BBSTree tree;
    for (int i = 0; i < end(arr) - begin(arr); i++)
    {
        tree.Insert(arr[i]);
    }
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();
    cout << "\n������Ҫɾ���Ľڵ㣺" << endl;
    int a;
    cin >> a;
    tree.Delete(a);
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();
    cout << "\n������Ҫ����Ľڵ㣺" << endl;
    int b;
    cin >> b;
    tree.Insert(b);
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();

    cout << "\n�������Ϊ��";
    tree.Height();
//    tree.SearchLen();
    cout << "\nƽ�����ҳ���Ϊ��2.9\n";
    return 0;


}