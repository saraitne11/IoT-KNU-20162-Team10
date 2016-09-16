//header.h

typedef struct NODE{		//NODE 구조체
	char data[25];			//25byte 크기를 가지는 data 멤버변수, text파일에서 읽어드린 단어를 저장한다.
	int index;				//몇 번째 노드인지를 저장하는 index 멤버변수
	struct NODE* next_link;	//다음 노드를 가리킬 멤버변수
}NODE;

NODE* init_list(char* data);

void append_NODE(NODE** tail, char* data);

void print_list(NODE* head);

void destroy_list(NODE* head);

int search_NODE(NODE* head, char* search_data);