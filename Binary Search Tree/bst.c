#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

Node * newNode(Data d, Node * parent)
{
	Node * n = malloc(sizeof(Node));
	n->data = d;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
	return n;
}

Tree * newTree()
{
	Tree * t = malloc(sizeof(Tree));
	t->root = NULL;
	t->insert = insert;
	t->search = search;
	t->sort = sort;
	t->sortAux = sortAux;
	t->clone = clone;
	t->compare = compare;
	t->removeData = removeData;
	t->delete = delete;
	return t;
}

Data *insert(Tree * bst, Data value)
{
	        if (bst->root != NULL)
        	{
			Node * a = searchNode(bst->root, value);

			if(a != NULL)
			{
				return NULL;
			}
			else;
			{
				Data * a = insertNode(bst->root, value);
				return &(bst->root->data);
			}
			free(a);
	        }

		else
		{
		 bst->root = newNode(value, NULL);
                 bst->root->parent = NULL;
                 return &(bst->root->data);
		}
}

Data * insertNode(Node * node, Data value)
{
	if(node->data.value < value.value)
	{
		if(node->right == NULL)
		{
			node->right = newNode(value, NULL);
			node->right->parent = node;
		}
		else
		{
			insertNode(node->right, value);
		}
	}
	else if(node->data.value > value.value)
	{
		if(node->left == NULL)
		{
			node->left = newNode(value, NULL);
			node->left->parent = node;
		}
		else
		{
			insertNode(node->left, value);
		}
	}
	return &(node->data);
}



Data * search(Tree * bst, Data value)
{
	if(bst->root->data.value == value.value)
	{
		return &(bst->root->data);
	}
	else if(bst->root == NULL)
	{
		return NULL;
	}
	else
	{
		Node * curr = searchNode(bst->root, value);
		return &(curr->data);
	}
}

Node * searchNode(Node * node, Data value)
{
	if(node->data.value == value.value)
	{
		return node;
	}

	else if(node->data.value > value.value)
	{
		if(node->left == NULL)
		{
			return NULL;
		}
		else
		{
			searchNode(node->left, value);
		}
	}

	else if(node->right == NULL)
		{
			return NULL;
		}
	else
	{
		searchNode(node->right, value);
	}

}


Node * searchAux(Tree * bst, Data value)
{
	if(bst->root == NULL)
	{
		return NULL;
	}

	else if(bst->root->data.value == value.value)
	{
		return bst->root;
	}

	else
	{
		Node * current = searchNode(bst->root, value);
		return current;
	}
}

void removeData(Tree * bst, Data value)
{
	if(bst->root != NULL)
	{
		Node * current = searchAux(bst, value);

		if(current != NULL)
		{
			if(current->left == NULL && current->right == NULL)
			{
				removeLeaf(bst, current);
			}
			else if(current->left == NULL || current->right == NULL)
			{
				shortCircuit(bst, current);
			}
			else
			{
				promotion(bst, current);
			}
		}
	}
}

void removeLeaf(Tree * bst, Node * d_node)
{
	if(d_node->parent == NULL)
	{
		bst->root = NULL;
	}
	else if(d_node == d_node->parent->left)
	{
		d_node->parent->left = NULL;
	}
	else
	{
		d_node->parent->right = NULL;
	}

	free(d_node);
	d_node = NULL;
}


void shortCircuit(Tree * bst, Node * d_node)
{
	if(d_node->parent == NULL)
	{
		if(d_node->left == NULL)
		{
			bst->root = d_node->right;
			d_node->right->parent = NULL;
		}
		else
		{
			bst->root = d_node->left;
			d_node->left->parent = NULL;
		}
	}
	else if(d_node == d_node->parent->left)
	{
		if(d_node->left == NULL)
		{
			d_node->parent->left = d_node->right;
			d_node->right->parent = d_node->parent;
		}
		else
		{
			d_node->parent->left = d_node->left;
			d_node->left->parent = d_node->parent;
		}
	}
	else
	{
		if(d_node->left == NULL)
		{
			d_node->parent->right = d_node->right;
			d_node->right->parent = d_node->parent;
		}
		else
		{
			d_node->parent->right = d_node->left;
			d_node->left->parent = d_node->parent;
		}
	}
	free(d_node);
	d_node = NULL;
}


void promotion(Tree * bst, Node * d_node)
{
	if(d_node->parent == NULL)
	{
		if(d_node->right->left == NULL)
		{
				d_node->data.value = d_node->right->data.value;
				shortCircuit(bst, d_node->right);
		}
		else if(d_node->right->left == NULL && d_node->right->right == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			removeLeaf(bst, d_node->right);
		}
		else
		{
			Node * current = d_node->right;
			while(current->left != NULL)
			{
				current = current->left;
			}
			d_node->data.value = current->data.value;
			removeLeaf(bst, current);
		}
	}
	else if(d_node == d_node->parent->right)
	{
		Node * current = d_node->right;

		if(d_node->right->left == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			shortCircuit(bst, d_node->right);
		}
		else if(d_node->right->left == NULL && d_node->right->right == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			removeLeaf(bst, d_node->right);
		}
		else
		{
			while(current->left != NULL)
			{
				current = current->left;
			}
			d_node->data.value = current->data.value;
			removeLeaf(bst, current);
		}
	}
	else
	{
		Node * current = d_node->right;
		if(d_node->right->left == NULL && d_node->right->right == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			removeLeaf(bst, d_node->right);
		}
		else if(d_node->right->left == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			shortCircuit(bst, d_node->right);
		}
		else
		{
			while(current->left != NULL)
			{
				current = current->left;
			}
			d_node->data.value = current->data.value;
			removeLeaf(bst, current);
		}
	}
}


Tree * clone(Tree * temp)
{
	Tree * t = newTree();
	t = traverse(temp->root, t);
	return t;
}


Tree * traverse(Node * node, Tree * t)
{
	if(node != NULL)
	{
		insert(t, node->data);
		traverse(node->left, t);
		traverse(node->right, t);
	}
	return t;
}

int compare(Tree * t, Tree * copy)
{
	if(t == NULL || copy == NULL)
	{
		return 0;
	}
	int flag = comp_traverse(t->root, copy->root);

	return flag;
}


int comp_traverse(Node * node, Node * copy)
{
	int b = 1;
	if(node == NULL && copy == NULL)
	{
		b = 1;
	}
	else if(node!= NULL && copy!= NULL)
	{
		if(node->data.value == copy->data.value)
		{
			b = 1;
			comp_traverse(node->left, copy->left);
			comp_traverse(node->right, copy->right);
		}
		else
		{
			return b;
		}
	}
	return b;
}


void sort(Tree * bst, Data * data)
{
	int i = 0;
	int temp = sortAux(bst->root, data, i);
}


int sortAux(Node * current, Data * data, int i)
{
	if(current != NULL)
	{
		if(current->left != NULL)
		{
			i = sortAux(current->left, data, i);
		}

		data[i].value = current->data.value;
		i++;

		if(current->right != NULL)
		{
			i = sortAux(current->right, data, i);
		}
	}
	else
	{
		return i;
	}
	return i;
}

void delete(Tree * t)
{
		deleteTree(t, t->root);
		free(t);
		t = NULL;
}

void deleteTree(Tree * t, Node * curr)
{
	if(curr != NULL)
	{
		deleteTree(t, curr->left);
		deleteTree(t, curr->right);
		removeLeaf(t, curr);
	}
}

