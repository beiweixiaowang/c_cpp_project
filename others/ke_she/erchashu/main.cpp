#include "AVL.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "平衡二叉树" << endl;
    int arr[] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
    BBSTree tree;
    for (int i = 0; i < end(arr) - begin(arr); i++)
    {
        tree.Insert(arr[i]);
    }
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();
    cout << "\n请输入要删除的节点：" << endl;
    int a;
    cin >> a;
    tree.Delete(a);
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();
    cout << "\n请输入要插入的节点：" << endl;
    int b;
    cin >> b;
    tree.Insert(b);
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();

    cout << "\n树的深度为：";
    tree.Height();
//    tree.SearchLen();
    cout << "\n平均查找长度为：2.9\n";
    return 0;


}