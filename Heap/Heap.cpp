//
// Created by lenovo on 2022/8/22.
//
#include <cstdlib>
#include "Heap.h"
#include <memory.h>

struct HeapStruct{
    int Capacity;
    int Size;
    ElementType* elements;
};
//初始化堆
PriorityQueue Initialize(int MaxElements){
    PriorityQueue H;
    if(MaxElements < 1){
        //打印日志
        return NULL;
    }
    H = static_cast<PriorityQueue>(malloc(sizeof(HeapStruct)));
    if(H == NULL){
        //打印日志
        return NULL;
    }
    H -> elements = static_cast<ElementType *>(malloc(sizeof((MaxElements + 1) * sizeof(ElementType))));
    if(H -> elements == NULL){
        //打印日志
        return NULL;
    }
    H -> Capacity = MaxElements;
    H -> Size = 0;
    H -> elements[0] = -1;

    return H;
}
void Destory(PriorityQueue H){
    if(!H -> elements)
        free(H -> elements);
    if(!H)
        free(H);
}
void MakeEmpty(PriorityQueue H){
    H -> Size = 0;
}
void Insert(ElementType x , PriorityQueue H){
    //插入元素
    if(IsFull(H)){
        //打印日志
        return;
    }
    //确定最后的位置  H -> element[0]  是已经确定的最小值，插入的值不可能比他小，因此第一个一定是放在第一个元素上
    int i;
    for (i = ++H -> Size; x < H -> elements[i / 2]  ;i /= 2) {
        H -> elements[i] = H -> elements[i / 2];
    }
    H -> elements[i] = x;
}
ElementType DeleteMin(PriorityQueue H){
    //先判断是否为空
    //然后进行懒惰删除
    if(IsEmpty(H)){
        //打印错误日志
        return H -> elements[0];
    }
    int j,child;
    ElementType MinElement,LastElement;
    MinElement = H -> elements[0];
    LastElement = H -> elements[H -> Size--];

    for (j = 1; j * 2 <= H -> Size; j = child) {
        //child 永远都是两个里面小的一个
          child = j * 2;
          //找到两者中较小的一个
          if(child != H -> Size && H -> elements[child + 1] < H ->elements[child])
              child++;
          //是否需要向上替换  最后一个元素能不能放进去，能放进去的话就break插进去，不能放进去的话，元素向上替换
          if(LastElement > H -> elements[child])
              H -> elements[j] = child;
          else
              break;
    }
    H -> elements[j] = LastElement;
    return MinElement;
}
ElementType FindMin(PriorityQueue H){
    if(IsEmpty(H)){
        //打印日志
        return H->elements[0];
    }
    return H -> elements[1];
}
int IsEmpty(PriorityQueue H){
    if(H -> Size == 0)
        return 1;
    return 0;
}
int IsFull(PriorityQueue H){
    if(H->Size == H ->Capacity)
        return 1;
    return 0;
}