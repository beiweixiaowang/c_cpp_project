#include "AVL.h"

BBSTree::BBSTree() : root(nullptr)
{
}
BBSTree::~BBSTree() {
    Destroy(root);
}

void BBSTree::Insert(int d) {
    bool taller = false;
    Insert(&root, d, &taller);
}



void BBSTree::PreOrder(Node *n) {
    if (n == nullptr){
        return;
    }
    cout << setw(4) << n->data;
    PreOrder(n->left);
    PreOrder(n->right);
}

void BBSTree::InOrder(Node *n) {
    if (n == nullptr){
        return;
    }
    InOrder(n->left);
    cout << setw(4) << n->data;
    InOrder(n->right);
}

void BBSTree::PostOrder(Node *n) {
    if (n == nullptr)
        return;
    PostOrder(n->left);
    PostOrder(n->right);
    cout << setw(4) << n->data;
}

void BBSTree::LRotate(Node **n) {
    if (n == nullptr || *n == nullptr)
        return;
    Node *r = (*n)->right;
    (*n)->right = r->left;
    r->left = *n;
    *n = r;
}

void  BBSTree::RRotate(Node **n)
{
    if (n == nullptr || *n == nullptr)
        return;
    Node *l = (*n)->left;
    (*n)->left = l->right;
    l->right = *n;
    *n = l;
}

bool BBSTree::LBalance(Node **n)
{
    Node *l = (*n)->left;
    switch (l->EF){
        case LH:{
            l->EF = (*n)->EF = EH;
            RRotate(n);
        }break;
        case RH:{
            Node *lr = l->right;
            switch (lr->EF){
                case LH:{
                    l->EF = EH;
                    (*n)->EF = RH;
                } break;
                case EH:{
                    l->EF = (*n)->EF = EH;
                }break;
                case RH:{
                    l->EF = LH;
                    (*n)->EF = EH;
                }break;
            }
            lr->EF = EH;
            LRotate(&(*n)->left);
            RRotate(n);
        }break;
    }
    return true;
}


bool BBSTree::RBalance(Node **n){
    Node *r = (*n)->right;
    switch (r->EF){
        case LH:{
            Node *rl = r->left;
            switch (rl->EF){
                case LH:{
                    r->EF = RH;
                    (*n)->EF = EH;
                }break;
                case EH:{
                    r->EF = (*n)->EF = EH;
                }break;
                case RH:{
                    (*n)->EF = LH;
                    r->EF = EH;
                }break;
            }
            rl->EF = EH;
            RRotate(&(*n)->right);
            LRotate(n);
        }break;
        case RH:{
            r->EF = (*n)->EF = EH;
            LRotate(n);
        }break;
    }
    return true;
}

bool BBSTree::Insert(Node **n, int d, bool *taller)
{
    if ((*n) == nullptr)
    {
        *n = new Node;
        (*n)->left = NULL;
        (*n)->right = NULL;
        (*n)->EF = EH;
        (*n)->data = d;
        *taller = true;
        return true;
    }
    if ((*n)->data == d)
    {
        cout << "已存在节点: " << d << ", 插入失败!" << endl;
        *taller = false;
        return false;
    }
    if (d < (*n)->data) // 插入到左子树
    {
        if (!Insert(&(*n)->left, d, taller))
        {
            return false;
        }
        if (*taller == true)
        {
            switch ((*n)->EF)
            {
                case LH:
                {
                    LBalance(n);
                    *taller = false;
                }
                    break;
                case EH:
                {
                    (*n)->EF = LH;
                    *taller = true;
                }
                    break;
                case RH:
                {
                    (*n)->EF = EH;
                    *taller = false;
                }
                    break;
            }
        }
    }
    else
    {
        if (!Insert(&(*n)->right, d, taller))
        {
            return false;
        }
        if (*taller == true)
        {
            switch ((*n)->EF)
            {
                case LH:
                {
                    (*n)->EF = EH;
                    *taller = false;
                }
                    break;
                case EH:
                {
                    (*n)->EF = RH;
                    *taller = true;
                }
                    break;
                case RH:
                {
                    RBalance(n);
                    *taller = false;
                }
                    break;
            }
        }
    }

    return true;
}

void BBSTree::PreOrder()
{
    cout << "前序遍历: ";
    PreOrder(root);
    cout << endl;
}

/**
 * @description: 中序遍历
 * @param {
 *
 * }
 * @return: void
 */
void BBSTree::InOrder()
{
    cout << "中序遍历: ";
    InOrder(root);
    cout << endl;
}

/**
 * @description: 后续遍历
 * @param {
 *
 * }
 * @return:
 */
void BBSTree::PostOrder()
{
    cout << "后序遍历: ";
    PostOrder(root);
    cout << endl;
}

/**
 * @description: 销毁二叉树
 * @param {
 *     Node* n: 要销毁的节点
 * }
 * @return:
 */
void BBSTree::Destroy(Node *n)
{
    if (n == nullptr)
        return;
    Destroy(n->left);
    Destroy(n->right);
    delete n;
    n = nullptr;
}


void BBSTree::Delete(int d)
{
    Delete(&root, d);
}

void BBSTree::Height(){
    int a = 0;
    a = Height(root);
    cout << a << endl;
}


void BBSTree::Delete(Node **n, int d)
{
    if (*n == nullptr)
    {
        return;
    }
    if (d < (*n)->data) // 在左子树中
    {
        Delete(&(*n)->left, d);
        if (Height((*n)->right) - Height((*n)->left) > 1)
            LBalance(n);
    }
    else if (d > (*n)->data)
    {
        Delete(&(*n)->right, d);
        if (Height((*n)->left) - Height((*n)->right) > 1)
            RBalance(n);
    }
    else
    {
        if ((*n)->left == nullptr)
        {
            Node* tmp = *n;
            *n = (*n)->right;
            delete tmp;
            tmp = nullptr;
        }
        else if ((*n)->right == nullptr)
        {
            Node* tmp = *n;
            *n = (*n)->left;
            delete tmp;
            tmp = nullptr;
        }
        else
        {
            Node* lmax = FindLeftMax(*n);
            (*n)->data = lmax->data;
            Delete(&(*n)->left, lmax->data);
        }
    }
}

int BBSTree::Height(Node *n)
{
    if (n == nullptr)
    {
        return 0;
    }
    int lh = Height(n->left);
    int rh = Height(n->right);
    return lh > rh ? lh + 1 : rh + 1;
}

BBSTree::Node* BBSTree::FindLeftMax(Node *n)
{
    Node* tmp = n->left;
    while(tmp->right)
        tmp = tmp->right;
    return tmp;
}


