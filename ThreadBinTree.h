//
// Created by antonio on 17-11-25.
//

#ifndef THREADBITREE_THREADBINTREE_H
#define THREADBITREE_THREADBINTREE_H

#include <cstdlib>

//如何把二叉树线索化：在遍历二叉树的过程中给每个结点添加线索。
//一旦线索化完成，用户即可以想操作双向链表一样的使用。
typedef char DataType ;

typedef struct Node{
    DataType data ;//数据元素
    int leftThread ;//左线索
    struct Node* leftChild ;//左指针
    struct Node* rightChild ;//右指针
    int rightThread ;//右线索
}ThreadBiNode;//线索化的思想就是增加左右指针的功能，让他们可以同时完成两个重要的功能，这很了不起。

//中序线索化二叉树:把除头结点以外的部分进行线索化
void InThread(ThreadBiNode *curr, ThreadBiNode **pre){
    //curr是当前指针，pre是当前结点的中序前驱结点指针
    if(curr != NULL){
        InThread(curr->leftChild, pre) ;//递归线索化左子树

        if (curr->leftChild == NULL){//当前指针的左右孩子判断
            curr->leftThread = 1 ;//建立左线索标记
            curr->leftChild = *pre ;//建立左线索指针
        }
        else curr->leftThread = 0 ;//代表正常的左孩子指针
        if (curr->rightChild != NULL)
            curr->rightThread = 0 ;
        else curr->rightThread = 1 ;

        if ((*pre)->rightChild == NULL){//前驱结点指针
            (*pre)->rightThread = 1 ;//建立右线索标记
            (*pre)->rightChild = curr ;//建立右线索指针
        }
        else curr->rightThread = 0 ;
        *pre = curr ;//前序结点指针等于当前结点指针
        InThread(curr->rightChild, pre) ;//递归线索化右子树
    }

}

//创建中序线索化二叉树：给头结点线索化
void CreateInThread(ThreadBiNode **root){
    ThreadBiNode *t = *root ;
    ThreadBiNode *curr, *pre = *root ;
    //建立头结点
    *root = (ThreadBiNode *)malloc(sizeof(ThreadBiNode)) ;
    if (t == NULL){
        (*root)->leftThread = 0 ;//左孩子
        (*root)->rightThread = 1 ;//右线索
        (*root)->leftChild = *root ;
        (*root)->rightChild = *root ;
    }
    else {
        curr = t ;
        (*root)->leftChild = t ;//头结点的左指针
        (*root)->leftThread = 0 ;//头结点的左线索
        InThread(curr, &pre) ;//中序线索化二叉树
        pre->rightChild = *root ;//最后一个结点的右指针
        pre->rightThread = 1 ;//最后一个结点的右线索
        (*root)->rightChild = pre ;//头结点的右指针
        (*root)->rightThread = 1 ;//头结点的右线索
    }
}
#endif //THREADBITREE_THREADBINTREE_H
