#include <stdio.h>

#define B 100
#define L 6

int main()
{  
    int A[2][3][2];
	int c0,c1,c2,c3;
	int i,j,k;
	c3=L;
	c2=(2-1+1)*c3;//c2=(u3-l3+1)*c3
	c1=(3-1+1)*c2;//c1=(u2-l2+1)*c2
	c0=B-c1*1-c2*1-c3*1;//c0=B-c1*l1-c2*l2-c3*l3
	printf("ELEMENT       POSITION\n");
	printf("**********************\n");
	for (i=0;i<2;i++)
	    {
		for(j=0;j<3;j++)
	      {
		    for(k=0;k<2;k++)
	        {
			  A[i][j][k]=c0+c1*(i+1)+c2*(j+1)+c3*(k+1);//A[i1][i2][i3]=c0+c1*i1+c2*i2+c3*i3 // VALAME i+1,j+1,k+1 EPEIDI OI DEIKTES KSEKIANANE APO 1
			   
			   printf("A[%d][%d][%d]        %d\n\n",i+1,j+1,k+1,A[i][j][k]);
}}}
return 0;
	         
	         
}
