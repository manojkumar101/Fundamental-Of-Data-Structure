#include<stdio.h>
void unionoperation(int set1[],int set2[],int n1,int n2)
{
  int i,j,k=0,flag,set3[n1+n2],p;
        for(i=0;i<n1;i++)
          {
             set3[k]=set1[i];
              k++;
           }
         for(i=0;i<n2;i++)
            {
                flag=1;
                for(j=0;j<n1;j++)
                {
                    if(set2[i]==set1[j])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==1)
                {
                set3[k]=set2[i];
                k++;
                }
            }
        p=k;
        for(k=0;k <p;k++)
        {
        printf("%d   ",set3[k]);
        }

}
void intersection(int set1[],int set2[],int n1,int n2)
{
  int i,j,k=0,flag,set3[n1+n2],p;
        for(i=0;i<n2;i++)
        {
         flag=1;
            for(j=0;j<n1;j++)
            {
            if(set2[i]==set1[j])
            {
            flag=0;
            break;
            }
            }
        if(flag==0)
        {
        set3[k]=set2[i];
        k++;
        }
    }
        p=k;

        for(k=0;k <p;k++)
        {
        printf("%d   ",set3[k]);
        }
}
void difference(int set1[],int set2[],int n1,int n2)
{
  int i,j,k=0,flag,set3[n1+n2],p;

        for(i=0;i<n1;i++)
        {
            flag=1;
            for(j=0;j<n2;j++)
            {
            if(set1[i]==set2[j])
            {
            flag=0;
            break;
            }
            }
            if(flag==1)
            {
            set3[k]=set1[i];
            k++;
            }
        }
        p=k;
        for(k=0;k <p;k++)
        {
        printf("%d   ",set3[k]);
        }
}

int main()
{
int n,m,i;
printf("Enter the number of elements of set A ::   ");
scanf("%d",&n);
int set1[n];
for(i=0;i<n;i++)
    scanf("%d",&set1[i]);
printf("\nEnter the number of elements of set B ::   ");
scanf("%d",&m);
int set2[m];
for(i=0;i<m;i++)
    scanf("%d",&set2[i]);
do{
int ch,hl;
 printf("\n\n\1.UNION OF TWO SET\n2.INTERSECTION OF TWO SET\n3.DIFFERENCE\n4.SYMMETRIC DIFFERENCE \n5.EXIT\n");
 scanf("%d",&ch);
  switch(ch)
  {
    case 1:        printf("\n\nUnion of two array \n");
               unionoperation(set1,set2,n,m);break;
    case 2:printf("\n\nintersection of two array \n");
            intersection(set1,set2,n,m);break;
    case 3: printf("1.   Set A - Set B\n2.   Set B - Set A\nPRESS KEY  ");
            int ch1; scanf("%d",&ch1);
            printf("DIfference Of two set \n");
            if(ch1==1)
            difference(set1,set2,n,m);
            else
            difference(set2,set1,m,n);
            break;
    case 4:printf("\n\nSymmetric DIfference Of two set \n");
    difference(set1,set2,n,m);difference(set2,set1,m,n);break;
    default:break;

  }
if(ch==5)
break;
}while(1);
}
