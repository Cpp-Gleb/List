#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
}List;

List* Create(int data){ // create first
	List* tmp = (List*)malloc(sizeof(List));
	tmp -> value = data; // assign a value to Node
	tmp -> next = NULL;
	return(tmp);
}

List* Push_start(int data, List* head){
	List* tmp = (List*)malloc(sizeof(List));
	tmp -> value = data;
	tmp -> next = head;
	return(tmp);
}

void Push_end(int data, List* head){
	List* tmp = (List*)malloc(sizeof(List));
	tmp -> value = data;
	tmp -> next = NULL;
	List* p = head;
	while(p -> next != 0){
		p = p -> next;
	}
	p -> next = tmp;
}

List* Push_n_position(int data, int n, List* head){
	List* p = head;
	int count = 1;
	while(count < n-1 && p -> next !=NULL){
		p = p -> next;
		count++;
	}
	List* tmp = (List*)malloc(sizeof(List));
	tmp -> value = data;
	tmp -> next = p -> next;
	p -> next = tmp;
	return head;
}

void Peek(List* tmp){
	while(tmp != 0){
		printf("%d\n", tmp -> value);
		tmp = tmp -> next;
	}
}

List* Pop_elem(int x,List* head){
	List* tmp= head, *p = NULL;
	if(head == NULL)
		return NULL;
	while(tmp && tmp -> value != x){
		p = tmp;
		tmp = tmp -> next;
	}
	if(tmp == head){
		free(head);
		return tmp -> next;
	}
	if(!tmp)
		return head;
	p -> next = tmp -> next;
	free(tmp);
	return head;
}

List* Pop_List(List* head){
	while(head != 0){
		List* p = head;
		head = head -> next;
		free(p);
	}
	return 0;
}

int main(){
	List* head;
	int a;
	int data = 1;
	head = Create(data);
	printf("a = ");
	scanf("%d", &a);
	while(a != 0){
		Push_end(a, head);
		printf("a = ");
		scanf("%d", &a);
	}
	Peek(head);
	printf("delete x = ");
	scanf("%d", &a);
	head = Pop_elem(a, head);
	Peek(head);
	head = Pop_List(head);
	return 0;
}
