#include"vector.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Vector * newVector()
{
	Vector * new_v = malloc(sizeof(Vector));
	new_v->current_size = 0;
	new_v->max_size = 0;
	new_v->data = NULL;
	new_v->index_array = NULL;
	new_v->insert = insertVector;
	new_v->read = readVector;
	new_v->remove = removeVector;
	new_v->delete = deleteVector;
	return new_v;
}

void insertVector(Vector * array, int index, Data value){


        if(index >= array->max_size)
        {
                array->max_size = index * 2 + 1;
                Data * new_array = malloc(sizeof(Data) * array->max_size);
                memset(new_array, -1, sizeof(Data) * array->max_size);
		int * new_array1 = malloc(sizeof(int) * array->max_size);
		memset(new_array1, -1, sizeof(int) * array->max_size);

		memcpy(new_array, array->data, sizeof(Data) * array->current_size);
		free(array->data);
		array->data = NULL;

		memcpy(new_array1, array->index_array, sizeof(int) * array->current_size);
		free(array->index_array);
		array->index_array = NULL;


		array->data = new_array;
		array->index_array = new_array1;
	}

	array->data[index] = value;
	array->index_array[index] = index;

	if(index >= array->current_size)
        {
                array->current_size = index+1;
        }

}

Data * readVector(Vector * array, int index)
{
	if(index <= array->max_size)
	{
		if(array->index_array[index] == -1)
		{
			return &array->data[index];
		}

		else
		{
			return &(array->data[array->index_array[index]]);
		}
	}
	else
	{
		return NULL;
	}

}

void removeVector(Vector * array, int index)
{

int i;

        if(index <= array->current_size)
        {
		for(i=0; i< index; i++)
		{
			array->index_array[i] = i;
		}

		for(i=index; i< array->current_size; i++)
		{
			array->index_array[i] = i+1;
		}

		if(i==(array->current_size))
		{
			array->index_array[i] = -1;
		}

		array->current_size = array->current_size - 1;
	}

	else
        {
                return;
        }

}


void * deleteVector(Vector * v)
{
	free(v->data);

	free(v->index_array);

	free(v);

	return NULL;

}

