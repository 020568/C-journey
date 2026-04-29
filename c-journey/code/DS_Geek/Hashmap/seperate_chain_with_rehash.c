#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node* next;
};

typedef struct 
{
	int bucketscount;
	struct node** table;
	int num_elements;
}Hash;

void insert_elements(Hash* h,int key);

int get_index(int key,int buckets)
{
	return key%buckets;
}

Hash* creat_hash(int buckets)
{
	Hash* h=(Hash*)malloc(sizeof(Hash));
	h->bucketscount=buckets;
	h->table=(struct node**)malloc(buckets* sizeof(struct node*));
	h->num_elements=0;
	for(int i=0;i<buckets;i++)
	{
		h->table[i]=NULL;
	}
	return h;
	
}

void rehash(Hash* h)
{
	int old_buckets=h->bucketscount;
	struct node** oldtable=h->table;
	
	h->bucketscount*=2;
	h->table=(struct node**)malloc(h->bucketscount*sizeof(struct node*));
	for(int i=0;i<h->bucketscount;i++)
	{
		h->table[i]=NULL;
	}
	h->num_elements=0;
	
	for(int i=0;i<old_buckets;i++)
	{
		struct node* temp=oldtable[i];
		while(temp!=NULL)
		{
			insert_elements(h,temp->key);
			struct node* todelete=temp;
			temp=temp->next;
			free(todelete);
		}
	}
	free(oldtable);
	printf("--- Rehashed: Capacity is now %d ---\n", h->bucketscount);
	
}

void insert_elements(Hash* h,int key)
{
	//check the load factor
	if((float)h->num_elements/h->bucketscount>0.5)
	{
		rehash(h);
	}
	
	int index=get_index(key,h->bucketscount);
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->key=key;
	newnode->next=h->table[index];
	//Pointer overlap
	h->table[index]=newnode;
	h->num_elements++;
	
}

void display(Hash* h)
{
	for(int i=0;i<h->bucketscount;i++)
	{
		printf("%d",i);
		struct node* temp=h->table[i];
		while(temp!=NULL)
		{
			printf("--> %d",temp->key);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main() 
{
    Hash* h = creat_hash(4);
    insert_elements(h, 10);
    insert_elements(h, 20);
    insert_elements(h, 30); // 3/4 = 0.75 > 0.5，触发 rehash
    display(h);
    return 0;
}



























