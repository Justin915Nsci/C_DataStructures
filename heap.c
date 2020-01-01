#include <stdlib.h>
#include <stdio.h>

typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
} HeapType;

int initHeap (HeapType *pHeap, int size){
//   if (pHead != NULL){return -1;}
 //  pHeap = (HeapType*)malloc(sizeof(HeapType));
   pHeap->size = size;
   pHeap->end = 0;
   pHeap->store = (int*)malloc(sizeof(int)*size);
   return 0;
}

int inorder(HeapType *pHeap, int **output, int *o_size){
//   output = (int **)malloc(sizeof(int));
   *output = (int *)malloc(sizeof(int)*(pHeap->size));
//   o_size = (int*)malloc(sizeof(int));
//   *o_size = 0;
   int i = 0;
   inorderHLPR(pHeap, &*output, 0, o_size);
//   printf("%d",pHeap->store[0]);
   for (i=0;i<*o_size; i++){
      printf("%d",(*output)[i]);
   }
   return 0;
     
}

int inorderHLPR (HeapType* pHeap, int **out, int idx, int *o_size){
   int idxR = 0; int idxL = 0;
//  int * in = pHeap->store; 
   idxL = (idx*2 +1);
   idxR = idx*2 +2;
   if (idxL < pHeap->end){
//      printf("\n idxL is  %d", idxL);
      inorderHLPR(pHeap, &*out, idxL, o_size);
   }
//   printf("%d",pHeap->store[idx]);
//   printf("\n size of out is %d",*o_size);
   (*out)[*o_size] = (pHeap->store[idx]);
//   printf("\n index %d of out is %d",*o_size, (*out)[*o_size]);
   (*o_size) = (*o_size) + 1;
   if (idxR < pHeap->end){
      inorderHLPR(pHeap, out, idxR, o_size);
   }
   return 0;
}

int preorder(HeapType *pHeap, int **output, int *o_size){
   *output = (int *) malloc(sizeof(int)*(pHeap->size));
   preorderHLPR(pHeap, output, 0, o_size);
   int i = 0;
   for (i=0;i<*o_size;i++){
      printf("%d",(*output)[i]);
   } 
   return 0;
}

int preorderHLPR (HeapType* pHeap, int **out, int idx, int *o_size){
   int idxR; int idxL;
   idxL = idx*2 +1;
   idxR = idx*2 + 2;
   (*out)[*o_size] = (pHeap->store[idx]);
   (*o_size) = *o_size + 1;
   if (idxL < pHeap->end){
      preorderHLPR(pHeap,out,idxL,o_size);
   }
   if (idxR < pHeap->end){
      preorderHLPR(pHeap,out,idxR,o_size);
   }
   return 0;
}

int postorder(HeapType *pHeap, int **output, int *o_size){
   *output = (int *) malloc(sizeof(int)*(pHeap->size));
   postorderHLPR(pHeap, output, 0, o_size);
   int i = 0;
   for (i=0;i<*o_size;i++){
      printf("%d",(*output)[i]);
   } 
   return 0;
}

int postorderHLPR (HeapType* pHeap, int **out, int idx, int *o_size){
   int idxR; int idxL;
   idxL = idx*2 +1;
   idxR = idx*2 + 2;
   if (idxL < pHeap->end){
      postorderHLPR(pHeap,out,idxL,o_size);
   }
   if (idxR < pHeap->end){
      postorderHLPR(pHeap,out,idxR,o_size);
   }
   (*out)[*o_size] = (pHeap->store[idx]);
   (*o_size) = *o_size +1;
   return 0;
}

int addHeap(HeapType *pHeap, int key){
   int pIdx;
   pHeap->store[pHeap->end] = key;
   heapUp(pHeap, pHeap->end);
   pHeap->end = pHeap->end + 1;
   
   return 0;
    

}

int heapUp(HeapType* pHeap,int idx){
   if(idx == 0){
      return 0;
   }
   int temp = 0; int pIdx;
    if(idx%2 == 0){
       pIdx = (idx -2)/2;
       if(pHeap->store[pIdx]<pHeap->store[idx]){
         temp = pHeap->store[pIdx];
         pHeap->store[pIdx] = pHeap->store[idx];
         pHeap->store[idx] = temp;   
         heapUp(pHeap,pIdx);
         return 0;
       }
    }else{
       pIdx = (idx - 1)/2;
       if(pHeap->store[pIdx]<pHeap->store[idx]){
          temp = pHeap->store[pIdx];
          pHeap->store[pIdx] = pHeap->store[idx];
          pHeap->store[idx] = temp;
          heapUp(pHeap,pIdx);
          return 0;
       }
    }
    return 0;
}

int findHeap(HeapType* pHeap, int key){
   if (pHeap == NULL){return -1;}
   int i =0;
   for (i=0;i<pHeap->end;i++){
      if(pHeap->store[i]==key){
         return 1;
      }
   }return 0;
}

int delHeap(HeapType *pHeap, int *key){
   *key = pHeap->store[0];
   pHeap->store[0] = pHeap->store[pHeap->end-1];
   pHeap->store[pHeap->end-1]=0;
   pHeap->end = pHeap->end -1;
   heapDown(pHeap,0);   
   return 0;
}

int heapDown(HeapType* pHeap, int idx){
   int lIdx = 0; int rIdx = 0;
   int temp;
   lIdx = idx*2+1;
   rIdx = idx*2 +2;
   if(lIdx >= pHeap->end && rIdx >= pHeap->end){
      return 0;
   }else if(lIdx==(pHeap->end-1)){
      if(pHeap->store[lIdx]>pHeap->store[idx]){
         temp = pHeap->store[lIdx];
         pHeap->store[lIdx] = pHeap->store[idx];
         pHeap->store[idx] = temp;
      }
   }else{   
      if(pHeap->store[lIdx]>pHeap->store[rIdx]){
         temp = pHeap->store[lIdx];         
         pHeap->store[lIdx] = pHeap->store[idx];
         pHeap->store[idx] = temp;
         heapDown(pHeap, lIdx);
      }else{
         
         temp = pHeap->store[lIdx];       
         pHeap->store[rIdx] = pHeap->store[idx];
         pHeap->store[idx] = temp;
         heapDown(pHeap, rIdx);
      }
   }
   return 0;
}
int main(){
   //HeapType*  H = NULL;
//   H = (HeapType*) malloc(sizeof(HeapType));
//   HeapType H;
//   initHeap(&H,420);
//   H.store[0] = 9;
//   H.store[1] = 8;
//   H.store[2] = 7;
//   H.store[3] = 6;
//   H.store[4] = 5;
//   H.store[5] = 4;
//   H.end =6;
//   int key = 0;
//   printf("%d",H->store[3]);
//   int* arrSize = NULL;
//   arrSize = (int*)malloc(sizeof(int));
//  * arrSize = 0;
//   int arrSize = 0;
//   int *arr = NULL; 
//   inorder(&H,&arr, arrSize);
//   * arrSize = 0;
//   arr = NULL;
//   delHeap(&H,&key);
//   inorder(&H,&arr, arrSize);

//   return 0;
}
