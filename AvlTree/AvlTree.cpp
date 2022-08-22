//
// Created by lenovo on 2022/8/18.
//
#include"AvlTree.h"
struct AvlNode{
    ElementType Element;
    AvlTree left;
    AvlTree right;
    int Height;
};
static int Height(Position P);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
AvlTree MakeEmpty(AvlTree T) {
    if(T != NULL){
        MakeEmpty(T -> left);
        MakeEmpty(T -> right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType x , AvlTree T){
    if(T == NULL)
        return NULL;
    if(x < T -> Element)
        return Find(x , T -> left);
    if(x > T -> Element)
        return Find(x , T -> right);
    return T;
}
Position FindMax(AvlTree T){
    if(!T || !T -> right)
        return T;
    return FindMax(T -> right);
}
Position FindMin(AvlTree T){
    if(!T)
        return NULL;
    while(T -> left)
        T = T -> left;
    return T;
}
AvlTree Insert(ElementType x , AvlTree T){
    //插入avl树历程
    //定义左旋转 + 右旋转
    //先判断树是否为空
    if(!T){
        T = (AvlTree)malloc(sizeof(AvlNode));
        if(!T){
            //打印错误日志，抛出异常
            return NULL;
        }
        else{
            T -> Element = x;
            T -> left = T -> right = NULL;
        }
    }
    //需要进行插入，并且维护平衡
    else if(x < T -> Element){
        T -> left = Insert(x , T -> left);
        //左右子树 相差2
        if(Height(T -> left) - Height(T -> right) >= 2)
            if(x < T -> left ->Element)
                SingleRotateWithLeft(T);
            else
                //双旋转
                DoubleRotateWithLeft(T);
    }
    else if(x > T -> Element){
        T -> right = Insert(x , T -> right);
        //左右子树 相差2
        if(Height(T -> right) - Height(T -> left) >= 2)
            if(x > T -> left ->Element)
                SingleRotateWithRight(T);
            else
                //双旋转
                DoubleRotateWithRight(T);
    }
    //修正T的高度
    T -> Height = max(Height(T -> left) , Height(T -> right)) + 1;
}
AvlTree Delete(ElementType x , AvlTree T){
    //删除avl树的简单例子  删除要复杂的多，使用懒惰删除内部必须添加变量表示该节点是否删除，在此不做对该二叉树的完善
    //删除可能会导致AVl树失去平衡，先转化为二叉搜索树删除叶子结点，然后通过调整失衡节点进行删除即可


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
static int Height(Position P){
    if(!P)
        return -1;
    return P -> Height;
}

//轴在左边  右旋转
static Position SingleRotateWithLeft(Position K2){
    Position K1;
    K1 = K2 -> left;

    K2 -> left = K1 -> right;
    K1 -> right = K2;
    //K1和K2都是一定存在的，其他的可能不存在？？？
    K1 -> Height = max(Height(K1 -> left) , K2 -> Height) + 1;
    K2 -> Height = max(Height(K2 -> left), Height(K2 -> right)) + 1;
    //返回新的根
    return K1;
}
//轴在右边 左旋转
static Position SingleRotateWithRight(Position K2){
    Position K1;
    K1 = K2 -> right;
    K2 -> right = K1 -> left;
    K1 -> left = K2;

    K1 -> Height = max(K2 -> Height , Height(K1 -> right));
    K2 -> Height = max(Height(K2 -> left) , Height(K2 -> right));
    return K1;
}
static Position DoubleRotateWithLeft(Position K3){
    //先左旋  然后右旋
    K3 -> left = SingleRotateWithRight(K3 -> left);
    return SingleRotateWithLeft(K3);
}
static Position DoubleRotateWithRight(Position K3){
    //先右旋 然后左旋
    K3 -> right = SingleRotateWithLeft(K3 -> right);
    return SingleRotateWithRight(K3);
}