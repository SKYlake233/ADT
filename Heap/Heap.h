//
// Created by lenovo on 2022/8/22.
//

#ifndef ADT_HEAP_H
#define ADT_HEAP_H
//完全二叉树：最底层元素从左到右，上层全部是全满
typedef int ElementType;

struct HeapStruct;
typedef HeapStruct* PriorityQueue;

PriorityQueue Initialize(int MAXElements);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType x , PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
#endif //ADT_HEAP_H
