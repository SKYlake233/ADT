//
// Created by lenovo on 2022/8/18.
//

#ifndef ADT_TREE_H
#define ADT_TREE_H
#include<iostream>
using namespace std;
/*设置类型*/
typedef int ElementType;

/*声明结构*/
struct TreeNode;
//定义指针
typedef struct TreeNode *Position;
//typedef指针重定义，便于理解  TreeNode表示树，SearchTree表示泛化，即多态的意思
typedef Position SearchTree;
//function
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType x , SearchTree T);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(ElementType x , SearchTree T);
SearchTree Delete(ElementType x , SearchTree T);
ElementType Retrieve(Position P);

#endif //ADT_TREE_H
