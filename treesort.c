#include <stdlib.h>
#include <stdio.h>

struct bstNode {
        int val;
        struct bstNode *l;
        struct bstNode *r;
};
typedef struct bstNode bstNode;

struct avlNode {
        int balance; /* -1 Left, 0 Balanced, +1 Right */
        int val;
        struct avlNode *l;
        struct avlNode *r;
};
typedef struct avlNode avlNode;

struct qNode {
        avlNode *pval;
        struct qNode *next;
};
typedef struct qNode qNode;

struct bstqueue{
        bstNode *pval;
        struct bstqueue *next;
};
typedef struct bstqueue bstqueue;


int add_bst(bstNode **root, int val) {
        bstNode *newnode = NULL;
        if (root == NULL) { return -1; }
        if (*root == NULL) {
                newnode = (bstNode *)malloc(sizeof(bstNode *));
                newnode -> val = val;
                newnode -> l = NULL;
                newnode -> r = NULL;
                *root = newnode;
                return 0;
        }
        else if ( (*root)->val > val) {
                return add_bst(&((*root)->l), val);
        }
        else {
                return add_bst(&((*root)->r), val);
        }
        return -1;
}

int add_to_queue(bstqueue **x, bstNode *val) {
        if (x == NULL) { return -1; }
        if (*x == NULL) {
                *x = (bstqueue *)malloc(sizeof(bstqueue *));
                (*x) -> pval = val;
                (*x) -> next = NULL;
                return 0;
        } else {
                return add_to_queue(&((*x)->next),val);
        }
}

int printTreeInOrder(bstNode *root) {
        if (root == NULL) { return -1; }
        printTreeInOrder(root -> l);
        printf("%d\n", root -> val);
        printTreeInOrder(root -> r);
        return 0;
}
int printQueue(bstqueue *root) {
        if (root == NULL) { return -1; }
        printf("%d", (root)->pval);
        root = root -> next;
}

int printLevelOrder(bstNode *root, bstqueue **que) {
        if (root == NULL) { return -1; }
        printf("%d ", root->val);
        if (root->l != NULL) {
                add_to_queue(que, root->l);
        }
        if (root->r != NULL) {
                add_to_queue(que, root->r);
        }
        while(1) {
                if (*que == NULL) {
                        printf("\n");
                        return 0;
                }
                printf("%d ", (*que)->pval->val);
                if((*que)->pval->l != NULL) {
                        add_to_queue(que, (*que)->pval->l);
                }
                if ((*que)->pval->r != NULL) {
                        add_to_queue(que, (*que)->pval->r);
                }
                *que = (*que)->next;
                }
        return 0;
}

int depthcheck(bstNode *root) {
        int l_depth = 0;
        int r_depth = 0;
        if (root == NULL) { return 0; }
        if (root -> l) {
                l_depth = depthcheck(root->l);
        }
        if (root -> r) {
                r_depth = depthcheck(root->r);
        }
        if (l_depth > r_depth) { return ++l_depth; }
        if (r_depth > l_depth) { return ++r_depth; }
        else { return -1; }
}

int isavl(bstNode **root) {
        int l_depth = 0;
        int r_depth = 0;
        if (*root == NULL) { return -1; }
        l_depth = depthcheck((*root)->l);
        r_depth = depthcheck((*root)->r);
        if ((l_depth-r_depth == 1) || (l_depth-r_depth == 0) || (l_depth-r_depth==-1)) { return 0; }
        else { return -1; }
}

int rotate(avlNode **root, unsigned int Left0_Right1) {
        avlNode *temp = NULL;
        if (root == NULL) { return -1; }
        if (Left0_Right1 == 0) {
                temp = (*root)->r;
                (*root)->r = NULL;
                if (temp -> l != NULL) {
                        (*root)->r = temp -> l;
                        temp -> l = (*root);
                        (*root) = temp;
                }
                else {
                        temp->l = (*root);
                                                (*root) = temp;
                }
                return 0;
        }
        else if (Left0_Right1 == 1) {
                temp = (*root)->l;
                (*root)->l = NULL;
                if (temp->r != NULL) {
                        (*root)->l = temp-> r;
                        temp->r = (*root);
                        (*root) = temp;
                }
                else {
                        temp -> r = (*root);
                        (*root) =temp;
                }
                return 0;
        }
        else { return -1; }
}

int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1) {
        avlNode *temp = NULL;
        avlNode *temp2 = NULL;
        if (root == NULL) { return -1; }
        if (MajLMinR0_MajRMinL1 == 0) {
                temp = (*root)->r;
                (*root)->r = NULL;
                temp2 = temp->l;
                temp->l = NULL;
                if (temp2 -> r != NULL) {
                        temp->l = temp2->r;
                        temp2->r = temp;
                        temp = temp2;
                }
                else {
                        temp2 -> r = temp;
                        temp = temp2;
                }
                (*root)->r = temp2;
                return rotate(root,0);
        }
        if (MajLMinR0_MajRMinL1 == 1) {
                        temp = ((*root)->l);
                        (*root)->l = NULL;
                        temp2 = temp->r;
                        temp->r = NULL;
                        if (temp2 -> l != NULL) {
                                temp->r = temp2 ->l;
                                temp2->l = temp;
                                temp = temp2;
                        }
                        else {
                                temp2 -> l = temp;
                                temp = temp2;
                        }
                        (*root)->l = temp2;
                        return rotate(root, 1);
                }
                else {
                        return -1;
                }
}

