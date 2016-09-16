//linked_list.cpp

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

NODE* init_list(char* data){	//creat linked list
	NODE* head = NULL;			
	head = (NODE*)malloc(sizeof(NODE));		//첫번째 노드의 메모리 공간을 할당 받는다.
	if (head == NULL){			//예외 처리
		printf("동적 메모리 할당 실패\n");
	}
	strcpy(head->data, data);	//첫번째 노드의 문자열 data를 설정한다.
	head->index = 1;			//첫번째 노드이므로 index를 1로 설정한다.
	head->next_link = NULL;		//다음 노드는 아직 없으므로 다음 노드 link를 NULL로 설정한다.
	return head;
}

//linked list의 끝을 가리키는 tail을 함수에서 수정해야하므로 이중 포인터 사용
void append_NODE(NODE** tail, char* data){	//linked list의 마지막에 노드를 추가
	NODE* new_NODE = NULL;
	new_NODE = (NODE*)malloc(sizeof(NODE));		//새로운 노드에 대한 동적 메모리 할당
	if (new_NODE == NULL){						//예외 처리
		printf("동적 메모리 할당 실패\n");
	}
	(*tail)->next_link = new_NODE;				//현재 마지막 노드의 다음 linked 노드를 새로 만든 노드로 설정
	strcpy(new_NODE->data, data);				//함수의 인수로 받은 data를 새로운 노드의 data에 copy 
	new_NODE->index = ((*tail)->index) + 1;		//새로운 노드의 index를 전 노드의 index보다 1 크게 설정
	new_NODE->next_link = NULL;					//새로 만든 노드의 다음 노드를 가리키는 포인터를 NULL로 설정
	(*tail) = new_NODE;							//linked list의 마지막 노드(tail)를 새로 만든 노드로 설정
}

void print_list(NODE* head){			//linked list의 head부터 순회하며 각 노드의 data와 index를 print
	NODE* current = head;				//현재 노드를 head로
	while (1){							
		printf("data : %-25s   index : %d\n", current->data, current->index);	//현재 노드의 data, index를 print
		current = current->next_link;		//현재 노드를 다음 노드로
		if (current == NULL) break;			//현재 노드의 link가 NULL을 가리키고 있으면 while문을 탈출하고 함수를 끝낸다.
	}
}

void destroy_list(NODE* head){			//linked list의 head부터 순회하며 각 노드의 메모리를 OS에 반납
	NODE* current = head;				//현재 노드를 head로
	NODE* next = current->next_link;	//다음 노드를 head의 다음 노드로
	while (1){
		free(current);					//현재 노드를 반납
		current = next;					//현재 노드를 다음 노드로 갱신
		next = current->next_link;		//다음 노드를 다다음 노드로 갱신
		if (next == NULL){		//다음 노드가 없다면, 즉 현재 마지막 노드라면
			free(current);		//현재 노드를 반납하고 while문 탈출하고 함수를 끝냄.
			break;
		}
	}
}

//head부터 순회하며 인수 search_data와 같은 문자열을 가진 노드를 순차 탐색한다.
int search_NODE(NODE* head, char* search_data){		
	NODE* current = head;		//현재 노드를 head로
	int counting = 0;			//찾아진 노드를 counting하는 변수, 0 으로 초기화
	while (1){
		if (strcmp(current->data, search_data) == 0){	//현재 노드의 data문자열과 인수 search_data문자열이 같을 경우
			printf("finded index : %d\n", current->index);	//현재 노드의 인덱스를 출력한다.
			counting++;										//counting변수를 1증가 시킨다.
		}
		current = current->next_link;					//현재 노드를 다음노드로
		if (current == NULL) break;						//만약 다음 노드가 NULL이라면 while문을 탈출한다.
	}
	printf("counting : %d\n", counting);				//모든 노드를 순회했으므로 찾아진 노드의 갯수를 출력한다.
	return counting;
}
