#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ){
    List a=L1->Next,b=L2->Next;
    List L=(List) malloc(sizeof(struct Node));
    L->Next=NULL;
    List tempNode=L;

    while (a&&b)
    {
        if(a->Data<=b->Data){
            tempNode->Next=a;
            tempNode=tempNode->Next;
            a=a->Next;
        }
        else{
            tempNode->Next=b;
            tempNode=tempNode->Next;
            b=b->Next;
        }
    }
    if (a) tempNode->Next=a;
    else if(b) tempNode->Next=b;
    L1->Next=L2->Next=NULL;
  
    return L;
}