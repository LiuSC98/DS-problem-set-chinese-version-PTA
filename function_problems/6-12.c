#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X ){
    if(!BST){
        BST=(BinTree)malloc(sizeof(struct TNode));
        BST->Data=X;
        BST->Left=BST->Right=NULL;
        return BST;
    }
    Position node=BST;
    while(1){
        if (node->Data>X)
        {
            if (node->Left) node=node->Left;
            else {
                node->Left=(BinTree)malloc(sizeof(struct TNode));
                node=node->Left;
                node->Data=X;
                node->Left=node->Right=NULL;
                return BST;
            }
        }
        else{
            if (node->Right) node=node->Right;
            else {
                node->Right=(BinTree)malloc(sizeof(struct TNode));
                node=node->Right;
                node->Data=X;
                node->Left=node->Right=NULL;
                return BST;
            }
        }
    }
}


BinTree Delete( BinTree BST, ElementType X ){
    
    if(!BST) printf("Not Found\n");
    else{
        if(X<BST->Data) BST->Left=Delete(BST->Left,X);
        else if (X>BST->Data) BST->Right=Delete(BST->Right,X);
        else
        {
            if(BST->Right&&BST->Left){
                BST->Data=FindMax(BST->Left)->Data;
                BST->Left=Delete(BST->Left,BST->Data);
            }
            else {
                BinTree tempNode=BST;
                if(!BST->Right){
                    BST=BST->Left;
                }
                else{
                    BST=BST->Right;
                }
                free(tempNode);
            }
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X ){
    while(BST){
        if(BST->Data==X) break;
        else if(BST->Data>X) BST=BST->Left;
        else BST=BST->Right;
    }
    return BST;
}

Position FindMin( BinTree BST ){
    if(BST) while (BST->Left) BST=BST->Left;
    return BST;
}

Position FindMax( BinTree BST ){
    if(BST) while (BST->Right) BST=BST->Right;
    return BST;
}