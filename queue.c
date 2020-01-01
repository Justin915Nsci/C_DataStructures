

struct queue{
	int val;
	struct *next;
	
};
typedef struct queue queue;

int enqueue(queue** root, int val){
	if (root == NULL){return -1}
	if (*root == NULL){
	*root = (queue*)malloc(sizeof(queue));
	(*root)->val = val;
	}else{
		if((*root)->next == NULL){
			(*root)->next = (queue*)malloc(sizeof(queue));
			((*root)->next)->val = val;
		}else{
			return	enqueue((*root)->next, val);
		}
	}
	return 0;
}

int dequeue(queue** root){
	
	if (root == NULL|*root == NULL){return -1}
	int ret = 0;
	ret = (*root)->val;
	queue* temp = (queue*)malloc(sizeof(queue));
	temp = (*root)->next;
	(*root)->next = NULL;
	*root = temp;
	return ret;
}
