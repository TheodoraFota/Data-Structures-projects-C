#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11

void retrieve(float S[],float *c,int i); //dhlwsh sunarthshs
void update(float S[],float c,int i); //dhlwsh sunarthshs
int main() {
  float x,y;
  float A[SIZE];
  float B[SIZE];
  float C[SIZE];
  int i;
  srand(time(NULL));
  for (i=1;i<SIZE;i++)
  { B[i]=rand()%10; //Dialegei tuxaious arithmous apo 0 ews kai 9
    C[i]=rand()%10; //Dialegei tuxaious arithmous apo 0 ews kai 9

  }
  for (i=1;i<SIZE;i++)
  { retrieve(B,&x,i); //x=B[i]
    retrieve(C,&y,i);//y=C[i]
    update(A,x+y,i);//A[i]=x+y
  }
  for (i=1;i<SIZE;i++)
  {
      printf("B[%d]=%.2f\n",i,B[i]);
  }
  printf("******************\n");
    for (i=1;i<SIZE;i++)
    {
        printf("C[%d]=%.2f\n",i,C[i]);
    }
    printf("******************\n");
    for (i=1;i<SIZE;i++)
    {
        printf("A[%d]=%.2f\n",i,A[i]);
    }
    return 0;
}
void retrieve(float S[],float *c,int i)
{
    *c=S[i]; //anathetw sth metablhth c thn timh S[i]
}
void update(float S[],float c,int i)
 {
    S[i]=c; //anathetw sto S[i] thn metablhth c
}
