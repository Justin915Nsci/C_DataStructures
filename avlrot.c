#include <stdio.h>
#include <stdlib.h>

struct bstNode {
        int val;
        struct bstNode *l;
        struct bstNode *r;
};
typedef struct bstNode bstNode;

struct avlNode{
   int balance;
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode;

struct queue{
        int val;
        struct queue *next;

};
typedef struct queue queue;


int enqueue(queue** root, int val){
        if (root == NULL){return -1;}
        if (*root == NULL){
        *root = (queue*)malloc(sizeof(queue));
        (*root)->val = val;
        }else{
                if( (*root)->next == NULL){
                        (*root)->next = (queue*)malloc(sizeof(queue));
                        ((*root)->next)->val = val;
                }else{
                        return  enqueue(&(*root)->next, val);
                }
        }
        return 0;
}

int dequeue(queue** root){

        if (root == NULL|*root == NULL){return -1;}
        int ret = 0;
        ret = (*root)->val;
        queue* temp = (queue*)malloc(sizeof(queue));
        temp = (*root)->next;
        (*root)->next = NULL;
        *root = temp;
        return ret;
}

int isAVL(avlNode **root){
   int rCnt = 0; int lCnt = 0;
   if((*root)->r == NULL){
      rCnt = 0;
   }else{
      rCnt = getDepth(&((*root)->r),1);
   }
   if ((*root)->l == NULL){
      lCnt = 0;
   }else{
      lCnt = getDepth(&((*root)->l),1);
   }
   if (abs(lCnt - rCnt)< 2){
      return 0;
   }
   return -1;
}

int getDepth (avlNode **root, int cnt){
   int goR = 0; int goL = 0;
   if ((*root)->r == NULL && (*root)->l == NULL){
      return cnt;
   }
   if ((*root)->r != NULL){
      goR = getDepth(&((*root)->r),cnt +1);
   }else{
   goR = 0;
   }
   if((*root)->l == NULL){
      goL = 0;
   }else{
      goL = getDepth(&((*root)->l), cnt + 1);
      }
   printf("\n goL is %d",goL );
   printf("\n goR is %d", goR);
   if (goR > goL){
        return goR;
      }else{
          return goL;
      }
}  


//int getLeftDepth (avlNode **root, int cnt){
//   if ((*root)->l == NULL){
//      return cnt;
//   }else{
//      return getLeftDepth((*root)->l, cnt + 1);
//   }
//}

int add_avl(avlNode** root, int val){
        if (root== NULL) { return -1;}
        if (*root == NULL){
                (*root) = (avlNode*)malloc(sizeof(avlNode));
		(*root)->val = val;
        }else{
		if (val < (*root)->val){
			if ((*root)->l == NULL){		
				(*root)->l = (avlNode*)malloc(sizeof(avlNode*));
				((*root)->l)->val = val;
			}else{
				add_avl(&(*root)->l,val);
			}
		}else{
			 if ((*root)->r == NULL){
                                (*root)->r = (avlNode*)malloc(sizeof(avlNode*));
                                ((*root)->r)->val = val;
                        }else{
                                add_avl(&(*root)->r,val);
                        }

		}
	
}
	return 0;

}

int rotate(avlNode **root, unsigned int Left0_Right1){
   avlNode * temp = NULL;
   temp = (avlNode*)malloc(sizeof(avlNode));
//   printf("\n not in if statement");
   if (Left0_Right1 == 0){
      printf("\n leftright triggered.");
      temp = (*root)->r;
      (*root)->r = temp->l;
      temp->l = *root;
   }
   if (Left0_Right1 == 1){
       printf("\n rightleft triggered.");
       temp = (*root)->l;
       (*root)->l = temp->r;
       temp->r = *root;
   }
   return 0;
}

int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1){

   if (MajLMinR0_MajRMinL1 == 0){
      rotate(&((*root)->r),1);
      rotate(root,0);
   }
   if (MajLMinR0_MajRMinL1){
      rotate(&((*root)->l),0);
      rotate(root,1);
   }
   return 0;
}

int printTreeInOrder(bstNode* root){
	if (root == NULL){ return -1;}
	if (root->l == NULL && root->r == NULL){
		printf("\n %d", root->val);
		return 0;
 	}else{
		if(root->l != NULL){
			printTreeInOrder(root->l);
		}
		printf("\n %d", root->val);
		if (root->r != NULL){
			printTreeInOrder(root->r);
		}
	}
        return 0;
}

int printLevelOrder(bstNode* root){
	int i = 0; int r =0;
	if (root == NULL){return -1;}
	queue *q = NULL;
	PloHlpr(root, &q);
	while(1){
		r = dequeue(&q);
		if (r == -1){break;}
		else{ 
		printf("%d ",r);
		}
	}

	return 0;
}

int PloHlpr(bstNode* root, queue** que){
   queue ** q = NULL;
   q = que;
   enqueue(q,root->val);
   if (root->l != NULL){
      PloHlpr(root->l,que);
   }
   if (root->r != NULL){
      PloHlpr(root->r,que);
   }
   return 0;
	
}
                                                                                                             
                                                                                                             
                                                                                                                                                                                                                            
                                                                                                          
                                                                                                                                                                                                                                                                                                                                                                                                                                             
                                                                                                              
                                                                                                              
                                              
