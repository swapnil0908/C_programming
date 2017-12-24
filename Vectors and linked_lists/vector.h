#ifndef vector_h
#define vector_h
#include "data.h"

typedef struct vector
{
	Data * data;
        unsigned int current_size;
        unsigned int max_size;
	void (*insert)(struct vector * , int index, Data value);
	int * index_array;
	Data * (*read)(struct vector * array, int index);
	void (*remove)(struct vector * array, int index);
	void (*delete)(struct vector *);
}Vector;

Vector * newVector();

void insertVector(Vector * array , int index, Data value);

void removeVector(Vector * array, int index);

Data * readVector(Vector * array, int index);

void * deleteVector(Vector *);

#endif

