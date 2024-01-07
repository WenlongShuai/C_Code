//  stackCreate.h


#ifndef stackCreate_h
#define stackCreate_h

#include <stdio.h>

struct HeadNode* StackInit();
int Empty(struct HeadNode *T);
void PrintStack(struct HeadNode *T);
void PushOperation(struct HeadNode *T,int d);
void PopOperation(struct HeadNode *T);
int TopOperation(struct HeadNode *T);


#endif /* stackCreate_h */
