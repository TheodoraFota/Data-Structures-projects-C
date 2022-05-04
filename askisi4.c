#include <stdio.h>
#define MAX 10 //SIZE OF STACK

struct Stack{
	int array[MAX]; //DATA TYPE IN STACK
	int top; 
	
};

void init(struct Stack *st);
int is_empty(struct Stack st);
int is_full(struct Stack st);
int push(struct Stack *st,int value);
int pop(struct Stack *st,int *value);

int main()
{ 
   int choice,i,x;
   struct Stack STACK;
   init(&STACK);//INITIALIZATION OF STACK
   
   while(1)
    {
	printf("MENU\n");
	printf("*******\n");
	printf("Enter 1 to push element\n");
	printf("Enter 2 to pop element\n");
	printf("Enter 3 to print Stack\n");
	printf("Enter 4 to exit programm\n");
	printf("Your choice?");
	scanf("%d",&choice);
    
    switch(choice)
    {
    	case 1://PUSH ELEMENT
    		printf("Give the element:\n");
    		scanf("%d",&x);//READ THE ELEMENT FROM THE KEYBOARD
    		if(push(&STACK,x)) //FUNCTION PUSH RETURNED 1
    		   printf("Push done!\n");
    		else //FUNCTION PUSH RETURNED 0
    		   printf("Stack is full...\n");
    		break;
    	case 2://POP ELEMENT
    		if(pop(&STACK,&x))//FUNCTION POP RETURNED 1
    		   printf("Pop done and the element is:%d\n",x);//PRINT THE ELEMENT
    		else//FUNCTION POP RETURNED 0 
    		   printf("Stack is empty...\n");
    		break;
    	case 3://PRINT STACK
    		for (i=0;i<=STACK.top;i++)
    			printf("|%d",STACK.array[i]);
    			printf("|\n");
    		break;
    	case 4://EXIT 
    		printf("Bye bye!");
    		return 0;
    	default:
    		printf("You entered invalid number");   	
	}
	printf("\n\n\n");
 }
}

void init(struct Stack *st)
{
	st->top=-1; //FIRSTLY,STACK IS EMPTY
}

int is_empty(struct Stack st)
{
	if (st.top==-1)
	    return 1; //TRUE
	else
	    return 0; //FALSE
}

int is_full(struct Stack st)
{
	if (st.top==MAX-1)
	   return 1; //TRUE
	else
	   return 0; //FALSE
}

int push(struct Stack *st, int value)
{
	if (is_full(*st)) 
	   return 0;//FALSE
	else
	{
		st->top=st->top+1;//INCREASE TOP BY 1
		st->array[st->top]=value;//PUT THE NEW ELEMENT ON TOP
		return 1; //TRUE
	}
	
}

int pop(struct Stack *st,int *value)//BY REFERENCE.FUNCTION RETURNS 2 ELEMENTS(TRUE OR FALSE AND VALUE)
{
	if (is_empty(*st))
	    return 0;//FALSE
	else
	   *value=st->array[st->top];
	   st->top=st->top-1;//REDUCE THE TOP BY 1
	   return 1;//TRUE
}
