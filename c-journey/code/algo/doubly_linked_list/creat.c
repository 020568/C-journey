struct DoublyListNode 
{
    int val;
    struct DoublyListNode *next, *prev;
};

struct DoublyListNode* createDoublyLinkedList(int* arr, int arrSize) 
{
    if (arr == NULL || arrSize == 0) 
	{
        return NULL;
    }
    struct DoublyListNode* head = (struct DoublyListNode*)malloc(sizeof(struct DoublyListNode));
    head->val = arr[0];
    head->next = NULL;
    head->prev = NULL;
    struct DoublyListNode* cur = head;
    // use a for loop to iteratively create the doubly linked list
    for (int i = 1; i < arrSize; i++) {
        struct DoublyListNode* newNode = (struct DoublyListNode*)malloc(sizeof(struct DoublyListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        cur->next = newNode;
        newNode->prev = cur;
        cur = cur->next;
    }
    return head;
}

int main()
{
	// create a doubly linked list
	int arr[] = {1, 2, 3, 4, 5};
	struct DoublyListNode* head = createDoublyLinkedList(arr, 5);
	struct DoublyListNode* tail = NULL;

// traverse the doubly linked list from the head node to the end
	for (struct DoublyListNode* p = head; p != NULL; p = p->next) 
	{
    	printf("%d\n", p->val);
    	tail = p;
	}
//tail can make this function come ture.
// traverse the doubly linked list from the tail node to the front
	for (struct DoublyListNode* p = tail; p != NULL; p = p->prev) 
	{
    	printf("%d\n", p->val);
	}
}







