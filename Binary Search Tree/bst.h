#ifndef bst_h
#define bst_h

typedef struct data
{
	int value;
}Data;

typedef struct node
{
	Data data;
	struct node * left;
	struct node * right;
	struct node * parent;
}Node;

typedef struct tree
{
	Node * root;
	Data * (*insert)(struct tree * bst, Data value);
	Data * (*search)(struct tree *bst, Data value);
	void (*sort) (struct tree * , Data * );
	int (*sortAux)(Node *, Data *, int );
	struct tree * (*clone)(struct tree *);
	int (*compare)(struct tree *, struct tree *);
	void (*removeData)(struct tree * bst, Data value);
	void (*delete)(struct tree *);
}Tree;

Tree * newTree();

Node * newNode(Data, Node * parent);

Data * insert(Tree * bst, Data value);

Data * insertNode(Node *, Data);

Data * search(Tree *, Data);

Node * searchNode(Node *, Data);

Node * searchAux(Tree *, Data);

void removeData(Tree *, Data);

void removeLeaf(Tree *, Node *);

void shortCircuit(Tree *, Node *);

void promotion(Tree *, Node *);

Tree * clone(Tree * bst);

Tree * traverse(Node *, Tree *);

int compare(Tree *, Tree *);

int comp_traverse(Node *, Node *);

void sort(Tree * bst, Data * data);

int sortAux(Node *, Data *, int );

void delete(Tree * bst);

void deleteTree(Tree *, Node *);
 
#endif
