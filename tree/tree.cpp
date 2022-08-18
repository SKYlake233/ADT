//
// Created by lenovo on 2022/8/18.
//
#include "tree.h"
//定义树
struct TreeNode{
    ElementType Element;
    SearchTree left;
    SearchTree right;
};
SearchTree MakeEmpty(SearchTree T){
    if(T != NULL){
        MakeEmpty(T -> left);
        MakeEmpty(T -> right);
        free(T);
    }
    return NULL;

}
Position Find(ElementType x , SearchTree T){
    if(T == NULL)
        return NULL;
    if(x < T -> Element)
        return Find(x , T -> left);
    if(x > T -> Element)
        return Find(x , T -> right);
    return T;
}
Position FindMax(SearchTree T){
    if(!T || !T -> right)
        return T;
    return FindMax(T -> right);
}
Position FindMin(SearchTree T){
    if(!T)
        return NULL;
    while(T -> left)
        T = T -> left;
    return T;
}
SearchTree Insert(ElementType x , SearchTree T){
    /*二叉查找树的插入
     * 1.分配空间，查找插入位置
     * 2.寻找位置插入
     * */
    if(T == NULL){
        T = (SearchTree)malloc(sizeof (struct TreeNode));
        if(T == NULL)

        else{
            T -> Element = x;
            T -> left = T -> right = NULL;
        }
    }
    else{
        if(x < T -> Element)
            Insert(x , T -> left);
        else
            if(x > T -> Element)
            Insert(x , T -> right);
        /*相等是不做重复的插入*/
    }
    return T;
}
SearchTree Delete(ElementType x , SearchTree T){
    /* 1.叶子节点的话，可以直接删除
     * 2.非叶子节点，需要进行左旋转或者右旋转*/
    Position TmpCell;
    if(T == NULL){
        //打印错误
        return NULL;
    }
    if(x < T -> Element){
        T -> left = Delete(x , T -> left);
    }
    else if(x > T -> Element){
        T -> right = Delete(x , T -> right);
    }
    //两个孩子
    else if(T -> left && T -> right){
        TmpCell = FindMin(T -> right);
        T -> Element = TmpCell -> Element;
        T -> right = Delete(T -> Element , T -> right);
    }
    //一个孩子或者没有孩子
    else {
        TmpCell = T;
        if (!T->left)
            T = T->right;
        else
            T = T->left;
        free(TmpCell);
    }
    return T;

}
ElementType Retrieve(Position P){
    if(!P){
        //打印错误日志,抛出exception
        return -1;
    }
    else{
        return P -> Element;
    }
}
