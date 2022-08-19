//
// Created by lenovo on 2022/8/18.
//

#ifndef ADT_AVLTREE_H
#define ADT_AVLTREE_H
#include<iostream>
using namespace std;
typedef int ElementType;
struct AvlNode;
typedef AvlNode* Position;
typedef AvlNode* AvlTree;

//function
AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType x , AvlTree T);
Position FindMax(AvlTree T);
Position FindMin(AvlTree T);
AvlTree Insert(ElementType x , AvlTree T);
AvlTree Delete(ElementType x , AvlTree T);
ElementType Retrieve(Position P);
#endif //ADT_AVLTREE_H
