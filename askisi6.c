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
void infix_to_postfix(int *infix,int *postfix,int n);



int main()
{	
    char c;
	struct Stack s;
    int number,n1,n2,j,i;
    int count=0;//COUNTS THE ELEMENTS IN STACK
    int num_array[17]={40,2,43,40,40,10,45,3,41,42,40,8,43,3,41,41,41};//ASCII CODES OF (2+((10-3)*(8+3)))
    int postarray[9];
    infix_to_postfix(num_array,postarray,17);//TRANSFORM TO POSTFIX 
	init(&s);//INITIALIZATION OF STACK
    for(i=0;i<9;i++)
	{   
	    c=postarray[i];
		if (c>=0 && c<=10)//NUMBER 0-10
		   { 
		    number=c;
		    push(&s,number);//PUSH NUMBER IN STACK s
		    count++;
		    printf("Stack elements time %d\t",i+1);//PRINT STACK ELEMENTS
		    for (j=0;j<count;j++)
		    {
		    	printf("|%d",s.array[j]);
			}
	        printf("\n");
		}
		else //SYMBOLS: +,*,-
		{   
		    //POP TWO ELEMENTS FROM STACK AND DO THE OPERATION BASED ON THE SYMBOL
			pop(&s,&n1);
			pop(&s,&n2);
			if (c== 43)//+
		    {
		    	number=n1+n2; //I PROSTHESI EINAI ANTIMETATHETIKI
			}
			else if (c==45)//-
			{ 
			   number=n2-n1; //AFAIRW TO n1 APO TO n2  GIATI TO n2 PRIN TO POP HTAN DEUTERO STIN STOIVA DLD O PRWTOS OROS TIS PRAKSIS	
			}
			else if (c==42)//*
			{
			   number=n1*n2;//O POLLAPLASIASMOS EINAI ANTIMETATHETIKOS
			}
			 push(&s,number);//PUSH THE RESULT IN STACK
		     count--;
		     printf("Stack elements time %d   ",i+1);//PRINT STACK ELEMENTS
		    for (j=0;j<count;j++)
		    {
		    	printf("|%d",s.array[j]);
			}
		    printf("\n");
		     
		}
	}
    
    pop(&s,&number);//EXTRACT THE FINAL RESULT FROM THE STACK
    printf("The result is: %d",number);//PRINT THE RESULT
    return 0;
} 

void infix_to_postfix(int *infix,int *postfix,int n)
{   
    int i,x;
	struct Stack st;//USE A NEW STRACK TO DO THE TRANSFORMATION
	init(&st);//INITIALIZATION OF STACK st
	int j=0;
	for (i=0;i<n;i++)
	{
	  if (infix[i]>=0 && infix[i]<=10)//NUMBER 0-10
	  {
	  	postfix[j]=infix[i];//PUT THE NUMBER IN NEW ARRAY INFIX
	  	j++;//INCREASE INDEX OF THE INFIX ARRAY 
	  }	
	  else if(infix[i]==45||infix[i]==42||infix[i]==43)//+,*,-
	      {
		    push(&st,infix[i]);//PUSH THE SYMBOL IN STACK
		}
	  else if(infix[i]==41)
	  //IF ELEMENT IS ')',POP THE SYMBOL FROM STACK AND PUT IT IN THE NEW ARRAY INFIX
	      {
		  pop(&st,&x);
	      postfix[j]=x;
	      j++;//INCREASE INDEX OF THE INFIX ARRAY
         }
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
