
#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>
#include<string.h>
#include<ctype.h>
struct stack
{
	char symbol;
	struct stack *next;
};

typedef struct stack p;
typedef p *t;
void push(char);
void deleStack();
int IsEmpty();
void printList();
p *top=NULL;
void countList();
void instructions (void)
{
	printf("Enter choice:\n"
		"1. vvod.\n"
		"2. vyvod.\n"
		"3. opredelenie razmera.\n"
		"4-delete stack\n");
}

main()
{ int choice,max,count=1,t=0;
char value,el; 
printf ("vvedite max razmer steka:");
scanf("%d",&max);
fflush(stdin);
printf ("vvedite etalon:");
el=getchar();
instructions();
printf("\n");
scanf("%d", &choice);
while (choice != 5)
{
	switch (choice)
	{
	case 1: 
		if (count<=max){
			printf("Enter a symbol: ");
			fflush(stdin);
			scanf ("%c",&value);
			if (value!=el && t==0){
				push(value);
				count++;
			}
			else {
				t++;
			printf ("VVod zakonchen as you entered the etalon symbol\n");
		break;	}
			

		}
		else  printf ("the list is full\n");

		break;


	case 2: if  (!IsEmpty())

				printList();

			else printf("the list is empty\n");

			break;
	case 3:
		if  (!IsEmpty())
			countList();

		break;
	case 4: deleStack();
		break;
	default:
		printf("Invalid choice.\n");
		fflush(stdin);
		instructions();
		break;	
	}
	instructions();
	printf("\n");
	scanf("%d", &choice);
}
printf("End of run.\n");
system("pause");
return 0;
}



void push(char elem){
	t newP;

	newP=(t)malloc(sizeof(p));
	if (newP!=NULL)
	{ 

		newP->symbol=elem;
		newP->next=top;
		top=newP;
	}
	else printf("%c not inserted not memory available for \n",elem);
}

int IsEmpty()
{
	return top==NULL;
}

void printList()
{
	t current;

	current =(t)top;
	if (top==NULL) 
		printf ("the stack is empty\n");
	else
	{	
		printf("The stack has:\n");
		while(current!=NULL)
		{

			printf ("%c->\n", current->symbol);
			current=current->next;

		}
		printf ("NULL\n"); 
	}
}
void countList(){
	t current;
	int count=0;
	current=(t)top;
	while (current!=NULL ){
		count++;
		current=current->next;

	} 
	printf("the stack razmerom %d\n",count);
}

void deleStack(){
	t current=top;

	if (current == NULL)
		printf("Stack Is Empty\n");

	if (top != NULL) {
		top = top->next;

		free(current);
	}
}
