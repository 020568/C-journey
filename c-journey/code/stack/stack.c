#include <stdio.h>

typedef struct
{
	int *data;
	int size;
}Arrystack;

//Constructor
Arraystack * new_arry_stack()
{
	Arrystack * stack = malloc(sizeof(Arrystack));
	stack->data = malloc(sizeof(int)*MAX_SIZE);
	stack->size = 0;
	return stack;
}


//Destructor
void deArrystack(Arrystack *stack)
{
	free(stack->data);
	free(stack);
}


//Get the length of the stack
int size(Arrystack *stack)
{
	return stack->size==0;
}


//Check if the stack is empty
bool isEmpty(Arrystack *stack)
{
	return stack->size==0;
}


//Push onto stack
void push(Arrystack *stack , int num)
{
	if(stack->size==MAX_SIZE)
	{
		printf("full");
		return 0;
	}
	stack->	data[stack->size]=num;
	stack->size++;
}


//Accessing the top element of the stack
int peek(Arrystack *stack)
{
	if(stack->size==0)
	{
		printf("null");
		return INT_MAX;
	}
	return INT_MAX;
}


//Popping from stack
int pop(Arrystack *stack)
{
	int val=peek(stack);
	stack->size--;
	return val;
}






