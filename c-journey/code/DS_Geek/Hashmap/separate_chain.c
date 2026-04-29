#include <stdio.h>
#include <stdlib.h>
struct node
{
	int key;
	struct node* next;
};

typedef struct
{
	int bucketcount;
	struct node** table;
}Hash;

int get_index(Hash* h,int key)
{
	return key%h->bucketcount;
}

Hash* creat_hashmap(int buckets)
{
	Hash* h=(Hash*)malloc(sizeof(Hash));
	h->bucketcount=buckets;
	h->table=(struct node**)malloc(buckets * sizeof(struct node*));
	
	for(int i=0;i<buckets;i++)
	{
		h->table[i]=NULL;
	}
	return h;
}


void insert(Hash* h,int key)
{
	int index=get_index(h,key);
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->key=key;
	new_node->next=NULL;
	
	if(h->table[index]==NULL)
	{
		h->table[index]=new_node;
	}
	
	else
	{
		struct node* temp=h->table[index];
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;
	}
}

void remove_key(Hash* h,int key)
{
	int index=get_index(h,key);
	struct node* temp=h->table[index];
	struct node* pre=NULL;
	
	while(temp!=NULL && temp->key!=key)
	{
		pre=temp;
		temp=temp->next;
	}
	
	if(temp!=NULL)
	{
		if(pre==NULL)
		{
			h->table[index]=temp->next;
		}
		else
		{
			pre->next=temp->next;
		}
		free(temp);
	}
}

void display(Hash* h)
{
	for(int i=0;i<h->bucketcount;i++)
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

void destory_hash(Hash* h)
{
	for(int i=0;i<h->bucketcount;i++)
	{
		struct node* temp=h->table[i];
		while(temp!=NULL)
		{
			struct node* todelete=temp;
			temp=temp->next;
			free(todelete);
		}
	}
	free(h->table);
	free(h);
}

int main() 
{
    int keys[] = {7, 18, 12, 25};
    int n = sizeof(keys) / sizeof(keys[0]);

    // 初始化哈希表，桶数为 7
    Hash* hashTable = creat_hashmap(7);

    // 插入数据
    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }

    // 删除元素 12
    remove_key(hashTable, 12);

    // 打印哈希表
    display(hashTable);

    // 释放内存
    destory_hash(hashTable);

    return 0;
}

