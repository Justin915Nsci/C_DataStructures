#include <stdio.h>
#include <stdlib.h>

struct bstNode {
        int val;
        struct bstNode *l;
        struct bstNode *r;
};
typedef struct bstNode bstNode;

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


int add_bst(bstNode** root, int val){
        if (root== NULL) { return -1;}
        if (*root == NULL){
                (*root) = (bstNode*)malloc(sizeof(bstNode));
		(*root)->val = val;
        }else{
		if (val < (*root)->val){
			if ((*root)->l == NULL){		
				(*root)->l = (bstNode*)malloc(sizeof(bstNode*));
				((*root)->l)->val = val;
			}else{
				add_bst(&(*root)->l,val);
			}
		}else{
			 if ((*root)->r == NULL){
                                (*root)->r = (bstNode*)malloc(sizeof(bstNode*));
                                ((*root)->r)->val = val;
                        }else{
                                add_bst(&(*root)->r,val);
                        }

		}
	
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
                                                                                                             
int main(){
   bstNode *root=NULL;
   add_bst(&root,5);
   add_bst(&root,3);
   add_bst(&root,1);
   add_bst(&root,4);
   add_bst(&root,7);
   add_bst(&root,6);
   add_bst(&root,8);
//   printTreeInOrder(root);
   printLevelOrder(root);
	
return 0;
}                                                                                                              
                                                                                                                                                                                                                            
                                                                                                          
                                                                                                                                                                                                                                                                                                                                                                                                                                             
                                                                                                              
                                                                                                              
                                              
