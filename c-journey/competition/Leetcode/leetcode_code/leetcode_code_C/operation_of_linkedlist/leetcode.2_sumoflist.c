#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* createList(int arr[], int n) 
{
    struct ListNode dummy;
    struct ListNode* cur = &dummy;
    for (int i = 0; i < n; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        cur->next = node;
        cur = node;
    }
    return dummy.next;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    
    struct ListNode dummy;
    struct ListNode* current=&dummy;
    int carry=0;
    
    while(l1!=NULL || l2!=NULL || carry!=0)
    {
    	int sum=carry;
    	if(l1!=NULL)
    	{
    		sum+=l1->val;
    		l1=l1->next;
		}
		if(l2!=NULL)
		{
			sum+=l2->val;
			l2=l2->next;
		}
		carry=sum/10;
		
    	struct ListNode* res =(struct ListNode *)malloc(sizeof(struct ListNode));
    	res->val=sum%10;
    	res->next=NULL;
    	current->next=res;
    	current=res;	
	}
	
	return dummy.next;
    
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
void freeList(struct ListNode* head) 
{
    while (head != NULL) {
        struct ListNode* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    // 342 + 465 = 807
    int a[] = {2, 4, 3};
    int b[] = {5, 6, 4};
    
    struct ListNode* l1 = createList(a, 3);
    struct ListNode* l2 = createList(b, 3);
    
    printf("l1: "); 
	printList(l1);
    printf("l2: "); 
	printList(l2);
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("结果: "); printList(result);
    
    freeList(l1);
    freeList(l2);
    freeList(result);
    
    return 0;
}