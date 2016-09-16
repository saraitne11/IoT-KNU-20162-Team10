//main.cpp

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

int main(){

	FILE* fp = NULL;		//file 포인터
	NODE* head = NULL;		//linked list의 첫번째 노드를 가리킬 변수
	NODE* tail = NULL;		//linked list의 마지막 노드를 가리킬 변수
	char data[25];			//파일에서 문자열을 읽어드리는 임시변수
	char* temp;				//strtok를 이용하기 위한 임시변수

	fp = fopen("Korean_text.txt", "r");
	if (fp == NULL)
		printf("파일 읽기 실패\n");
	else
		printf("파일 읽기 성공\n");

	fscanf(fp, "%s", data);		//첫번째 노드에 들어갈 문자열 데이터를 파일에서 받아옴.
	head = init_list(data);		//linked list 초기화, 첫번째 노드 생성
	tail = head;				//노드가 하나밖에 없으므로 

	while (1){
		if (fscanf(fp, "%s", data) == EOF) break;		//공백문자 기준으로 나누어 문자열 입력, 파일 끝에 도착하면 while문 탈출
		if (strchr(data, ',') || strchr(data, '.')){	//단어 뒷부분 문장부호 ',' and '.' 제거
			temp = strtok(data, ",.");
			strcpy(data, temp);
		}
		append_NODE(&tail, data);	//파일에서 받아온 문자열(한 단어)을 데이터로 하여 linked list의 마지막에 새로운 노드 추가 
	}

	print_list(head);				//linked list의 처음부터 마지막까지 순회(travel)하며 linked list의 data와 index 출력

	printf("찾고자 하는 단어를 입력하시오. : ");
	scanf("%s", data);
	search_NODE(head, data);

	destroy_list(head);				//linked list의 처음부터 마지막까지 순회(travel)하며 linked list의 모든 노드를 삭제
	fclose(fp);				
}
