#include<stdio.h>
void scan(int *a,int *b)
   {
	scanf("%d %d",&*a,&*b);
   }
int main()
   {
	int m,n,M,N,i,j,k,flag,flag2;
	int option,max,min;
	int p,q;
	int a[20][20],b[20][20],c[20][20];
	int count=0;

	while(1)
	   {

		printf("1. Addition\n2. Multiplication\n3. Transpose\n4. Saddle point\n5. EXIT\n");
		printf("Choose your option : ");
		scanf("%d",&option);
		printf("\n\n");
		switch(option)
		   {
		     case 1:    count=0;
                   	    printf("Enter the number of rows and columns of matrix a: ");
			            scan(&m,&n);
      			        printf("Enter the number of rows and columns of matrix  b: ");
                    	    scan(&M,&N);
                    		if((m!=M)||(n!=N))
                    		    {
                      			printf("Error , this is not allowed in addition . \n");
                      			count=1;
                                }
                    	   if(count == 1)
                           break;
                            printf("\nEnter the elements of matrix a : ");
                            for(i=0;i<m;i++)
                            for(j=0;j<n;j++)
                            scanf("%d",&a[i][j]);


                            printf("Enter the elements of matrix b : ");
                            for(i=0;i<M;i++)
                            for(j=0;j<N;j++)
                            scanf("%d",&b[i][j]);
                            printf("\nSUM OF MATRIX\n");

				        for(i=0;i<m;i++)
                        for(j=0;j<n;j++)
						c[i][j]=a[i][j]+b[i][j];


                        for(i=0;i<m;i++)
                        {
                        for(j=0;j<n;j++)
                        printf("%d ",c[i][j]);
                        printf("\n");
                        }
                        break;
			case 2:count=0;
                    		printf("Enter the number of rows and columns of matrix a: ");
                    		scan(&m,&n);
                   		    printf("Enter the number of rows and columns of matrix  b: ");
                    		scan(&M,&N);
                    		if(n!=M)
                    		   {
                        		printf("Error \n");
                        		count=1;
                    		   }
                    		if(count==1)
                        	break;
                    		printf("Enter the elements of matrix a : ");
                            for(i=0;i<m;i++)
                            for(j=0;j<n;j++)
							scanf("%d",&a[i][j]);

					printf("Enter the elements of matrix b : ");
					for(i=0;i<M;i++)
					for(j=0;j<N;j++)
                      scanf("%d",&b[i][j]);


                    for(i=0;i<m;i++)
                    for(j=0;j<N;j++)
                    c[i][j]=0;
                    for(i=0;i<m;i++)
                    {
					for(j=0;j<N;j++)
					for(p=0;p<n;p++)
                    c[i][j]+=a[i][p]*b[p][j];
                    }
                    for(i=0;i<m;i++)
                    {
                    for(j=0;j<N;j++)
					printf("%d ",c[i][j]);
					printf("\n");
                    }
                    break;
            case 3: printf("Enter the number of rows and columns of matrix a: ");
                    scan(&m,&n);
                    printf("Enter the elements of matrix a : ");
					for(i=0;i<m;i++)
					for(j=0;j<n;j++)
                    scanf("%d",&a[i][j]);

			        printf("\nTranspose of a is :\n");
                    for(i=0;i<n;i++)
                    {
					for(j=0;j<m;j++)
					printf("%d  ",a[j][i]);
					printf("\n");
                    }
                    break;
            case 4:count=0;
                    printf("Enter the number of rows and columns of matrix a: ");
                    scan(&m,&n);
                    printf("Enter the elements of matrix a : ");
					for(i=0;i<m;i++)
					for(j=0;j<n;j++)
                    scanf("%d",&a[i][j]);

                    for(i=0;i<m;i++)
                    {
                    min=a[i][0];
					flag=0;
					for(j=1;j<n;j++)
					{
					    if(a[i][j]<min)
						{min=a[i][j];
                        flag=j;
						}
                    }
                    flag2=0;
                    max=a[0][flag];
					for(k=1;k<m;k++)
					{
                        if(a[k][flag]>max)
						{       max=a[k][flag];
						}
                    }
					if(max==min)
                        {
                            printf("\nSaddle point is %d \n",max);
                            count=1;
                        }

                    }
                    if(count==0)
                    printf("Saddle point not exist . \n");
                    break;
			default:printf("thanks\n");
                    break;

		}
		if(option==5)
            break;
	}
 return 0;
}
