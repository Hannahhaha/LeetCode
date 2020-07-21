#include<iostream>
#include<stdlib.h>
using namespace std;

typedef char ElemType;

//二叉树的二叉链表结构，1个数据域，2个指针域

typedef  struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void CreateBiTree(BiTree *T)
{
    ElemType ch;
    cin >> ch;
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild); 
    }
}


void operation1(ElemType ch, int level)
{
       cout << ch << "在第" << level << "层" << endl;
}


//递归方式前序遍历二叉树
void PreOrderTraverse(BiTree T, int level)
{
    if (T == NULL)
        return;
    operation1(T->data, level); 
    PreOrderTraverse(T->lchild, level + 1);
    PreOrderTraverse(T->rchild, level + 1);
}

