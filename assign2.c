//stack assignment

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define STK_SIZE 10
#define true 1

// to coordinate in any function
COORD Cur;

typedef struct _stack {
	int peek;
	int data[STK_SIZE];
} STACK;

int main(void) {
	//functions
	void gotoxy(int x, int y);
	int is_empty(STACK* s);
	int is_full(STACK* s);
	void push(STACK* s, int item);
	void pop(STACK* s);
	void print_stack(STACK* s);
	void clear_area(int x, int y, int n);
	
	//variables
	char check;
	int pushed;
	STACK s;
	
	// stack init
	s.peek = -1;

	while(true){
		print_stack(&s);

		gotoxy(0,21);
		printf("Press u to push\nPress o to pop\nPress q to quit\n: ");
		clear_area(2, 24, 10);
		scanf("%c", &check);
		if(check == 'u'){
			printf("Enter a number you want to push: ");
			scanf("%d", &pushed);
			push(&s, pushed);
		}
		else if(check == 'o') pop(&s);
		else if(check == 'q') break;
		else 				  printf(" ");

		clear_area(33, 25, 15);
	}
	
	return 0;		
}
//////////////////////////////////////////////////////////////////////////////
void gotoxy(int x, int y)
{
      Cur.X = x;
      Cur.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}
void clear_area(int x, int y, int n) {
	gotoxy(x, y);
	for(int i=0; i<n; ++i) printf(" ");
	gotoxy(x, y);
}
//////////////////////////////////////////////////////////////////////////////

int is_empty(STACK* s){return (s->peek == -1);}
int is_full(STACK* s){return (s->peek == (STK_SIZE-1));}
void push(STACK* s, int item) {
	if(item < 0) {
		gotoxy(22, 5);
		printf("insert positive integer!");
		return;
	}

	if(is_full(s)){
		gotoxy(22,5);
		printf("Stack is full\n");
		gotoxy(20,20);
		return;
	}
	else{
		s->data[++s->peek] = item;
		gotoxy(1,10-(s->peek)-1);
		printf("%d",s->data[s->peek]);
		gotoxy(22,0);
		clear_area(Cur.X, Cur.Y, 10);
		printf("%d pushed!",s->data[s->peek]);
//		gotoxy(20,20);
//		getch();
	}
}

void pop(STACK* s) {
	if(is_empty(s)){
		gotoxy(22,5);
		printf("Stack is Empty\n");
		//gotoxy(20,20);
		//exit(1);
	}
	else{
		//gotoxy(5,10);
		//printf("%d",s->data[s->peek]);
		gotoxy(22,0);
		printf("%d popped!",s->data[s->peek--]);
//		gotoxy(20,20);
//		getch();
	}
}

void print_stack(STACK* s) {
    int max_digits = 2, cnt;
    int elem;

	for(int i=0; i<20; ++i) {
		for(int j=0; j<11; ++j) {
			gotoxy(i, j);
			printf(" ");
		}
	}

    for(int i=0; i<=s->peek; ++i) {
        elem = s->data[i];
        cnt = 0;
        while(elem) {
            elem /= 10;
            ++cnt; 
        }
        if(cnt > max_digits) max_digits = cnt;
    }

    for(int i=0; i<STK_SIZE; ++i) {
        gotoxy(0, STK_SIZE-1 - i);
		if(i <= s->peek) {
			printf("|");
        	printf("%d", s->data[i]);
			gotoxy(max_digits+1, Cur.Y);
        	printf("|");
		}
        else {
			printf("|");
			for(int j=0; j<max_digits; ++j)
				printf(" ");
			printf("|");
		}
    }
}