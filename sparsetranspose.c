#include <stdio.h>
int a[10][10],t[20][3],tr[20][3];
int input(int a[10][10],int m,int n);
void tuple(int a[10][10],int t[10][3],int m,int n);
void print(int t[10][3],int c);
void transpose(int t[][3],int tr[][3],int c);

void main()
{
	int i,j,m,n,c;
	printf("Enter the number of rows and columns of the matix:\n");
	scanf("%d %d",&m,&n);
	printf("Enter the elements of the matrix:\n");
	c=input(a,m,n);
	if (c>m*n/2)
	{
	    printf("\n Not a Sparse matrix");
	}
	
	else 
	{
	    tuple(a,t,m,n);
	    printf("Tuple representation\nrow\tcol\tval\n");
	    print(t,c);
	    transpose(t,tr,c);
	    printf("Transpose\nrow\tcol\tval\n");
	    print(tr,c);
	}
}
	
	int input(int a[10][10],int m,int n)
	{
	
	
	    int i,j,c=0;
	    for (i=0;i<m;i++)
	    {
	       for (j=0;j<n;j++)
	       {
	          scanf("%d",&a[i][j]);
	          if (a[i][j]!=0)
	          {
	             c++;
	          }
	       }
	    }
	    return c;
	}
	    
	    void tuple(int a[10][10],int t[10][3],int m,int n)
	    {
	        t[0][0]=m;
	        t[0][1]=n;
	        int k=1,i,j;
	        for (i=0;i<m;i++)
	        {
	           for  (j=0;j<n;j++)
	           {
	              if (a[i][j]!=0)
	              {
	                 t[k][0]=i;
	                 t[k][1]=j;
	                 t[k][2]=a[i][j];
	                 k++;
	              }
	           }
	        }
	        
	        t[0][2]=k-1;
	    }
	    
	    void print(int t[10][3],int c)
	    {
	       int i;
	       for (i=0;i<=c;i++)
	       {
	          printf("%d\t%d\t%d\n",t[i][0],t[i][1],t[i][2]);
	       }
	    }
	    
	    void transpose(int t[][3],int tr[][3],int c)
	    {
	        int i,j,l=1;
	        tr[0][0]=t[0][1];
	        tr[0][1]=t[0][0];
	        tr[0][2]=c;
	        for (i=0;i<t[0][1];i++)
	        
	          for (j=1;j<=c;j++)
	          {
	           if (i==t[j][1])
	           {
	              tr[l][0]=i;
	              tr[l][1]=t[j][0];
	              tr[l][2]=t[j][2];
	              l++;
	           }
	        }
	     }
