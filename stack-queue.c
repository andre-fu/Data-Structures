typedef struct IntStack_T {
	int *store;
	unsigned int size;
	unsigned int count;
	unsigned int head_index;
} IntStack_T;

typedef struct IntQueue_T {
	int *store;
	unsigned int size;
	unsigned int count;
	unsigned int head_index;
	unsigned int tail_index;
} IntQueue_T;

/* For all functions: the return value will be:
 * 0 for success, -1 for error .
 * The algorithmic return value will be "returned" via pointer arguments */

/* STACK */
int init_stack(IntStack_T *x) {
	if (x==NULL) { return -1; }
	x->store = (int *)malloc(C_SIZE*sizeof(int));
	if (x->store == NULL) { return -1; }
	x->size = C_SIZE;
	x->count = 0;
	x->head_index = -1;
	return 0;
}

int push(IntStack_T *x,int value) {
	if (x==NULL) { return -1; }
	if (x->count == x->size) { return -1; }
	x->count = x->count + 1;
	x->head_index = x->head_index + 1;
	x->store[x->head_index] = value;
	return 0;
}

int pop(IntStack_T *x,int *pvalue) {
	if (x==NULL) { return -1; }
	if (pvalue==NULL) { return -1; }
	if (x->count==0) { return -1; }
	x->count = x->count - 1;
	*pvalue = x->store[x->head_index];
	x->head_index = x->head_index - 1;
	return 0;
}

int empty_stack(IntStack_T *x,unsigned int *IsEmpty) {
	if (x==NULL) { return -1; }
	if (IsEmpty==NULL) { return -1; }
	if (x->count == 0) {
		*IsEmpty = 1;
		return 0;
	} else {
		*IsEmpty = 0;
		return 0;
	}
}

int full_stack(IntStack_T *x,unsigned int *IsFull) {
	if (x==NULL) { return -1; }
	if (IsFull==NULL) { return -1; }
	if (x->count == x->size) {
		*IsFull = 1;
		return 0;
	} else { 
		*IsFull = 0;
		return 0;
	}
}

/* QUEUE */
int init_queue(IntQueue_T *x) {
	if (x ==NULL) { return -1; }
	x->store=(int *)malloc(C_SIZE *sizeof(int));
	if (x->store==NULL) { return -1; }
	x->size = C_SIZE;
	x->count = 0;
	x->head_index = -1;
	x->tail_index = -1;
	return 0;
}

int enqueue(IntQueue_T *x,int value) {
	if (x==NULL) { return -1; }
	if (x->count == x->size) { return -1; }
	x->count = x->count + 1;
	x->head_index = (x->head_index + 1) % (x->size);
	x->store[x->head_index] = value;
	if (x->count == 1) {
		x->tail_index = x->head_index;
	}
	return 0;
}

int dequeue(IntQueue_T *x,int *pvalue) {
	if (x==NULL) { return -1; }
	if (pvalue==NULL) { return -1; }
	if (x->count==0) { return -1; }
	x->count = x->count-1;
	*pvalue = x->store[x->tail_index];
	x->tail_index = (x->tail_index+1)%(x->size);
	return 0;
}

int empty_q(IntQueue_T *x,unsigned int *IsEmpty) {
	if (x==NULL) { return -1; }
	if (IsEmpty==NULL) { return -1; }
	if (x->count == 0) {
		*IsEmpty = 1;
		return 0;
	} else {
		*IsEmpty = 0;
		return 0;
	}
}

int full_q(IntQueue_T *x,unsigned int *IsFull) {
	if (x==NULL) { return -1; }
	if (IsFull==NULL) { return -1; }
	if (x->count == x->size) {
		*IsFull=1;
		return 0;
	} else {
		*IsFull=0;
		return 0;
	}
}
