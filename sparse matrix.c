#include<stdio.h>
main()

{
    printf("enter size of 2 matrix alternatively \n");
    int r,c,i,j,k=0;
    scanf("%d%d",&r,&c);
    int mat1[r][c],mat2[r][c];
    printf("enter data into first matrix\n");
    for(i=0;i<r;i++)
    for(j=0;j<c;j++){scanf("%d",&mat1[i][j]); if(mat1[i][j]!=0)k++; }
    int spar1[k+1][3];
    spar1[0][0]=r;
    spar1[0][1]=c;
    spar1[0][2]=k;
    int x=1;
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
        if(mat1[i][j]!=0)
        { spar1[x][2]=mat1[i][j];
            spar1[x][0]=i;spar1[x][1]=j;x++;
        }

        k=0;
         printf("enter data into second matrix\n");

    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
        {scanf("%d",&mat2[i][j]); if(mat2[i][j]!=0)k++; }
    int spar2[k+1][3];
    spar2[0][0]=r;
    spar2[0][1]=c;
    spar2[0][2]=k;
    x=1;
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)if(mat2[i][j]!=0){ spar2[x][2]=mat2[i][j]; spar2[x][0]=i;spar2[x][1]=j;x++;  }

    x=1;int a=1,b=1;
    int spar3[spar2[0][2]+spar1[0][2]+1][3];
    spar3[0][0]=r;
    spar3[0][1]=c;
    int z=spar2[0][2]+spar1[0][2];
    spar3[0][2]=z;
    for(i=1;i<=z;i++)
    {
        int r1,r2,c1,c2,v,temp=2;
        if(a>spar1[0][2]){temp=1;}
        if(b>spar2[0][2]){temp=0;}
        r1=spar1[a][0];
        r2=spar2[b][0];
        c1=spar1[a][1];
        c2=spar2[b][1];

        if(r1<r2||temp==0){     v=spar1[a][2];spar3[i][0]=r1;spar3[i][1]=c1;spar3[i][2]=v;a++;     }
        else if(r1==r2&&temp==2){

            if(c1<c2)
                {v=spar1[a][2];spar3[i][0]=r1;spar3[i][1]=c1;spar3[i][2]=v;a++; }
            if(c2<c1)
            { v=spar1[b][2];spar3[i][0]=r2;spar3[i][1]=c2;spar3[i][2]=v;b++;    }
            if(c1==c2)
            { v=spar2[b][2];spar3[i][0]=r2;spar3[i][1]=c2;spar3[i][2]=v; v=spar1[a][2]; spar3[i][2]+=v;   b++; a++;z--;    }

        }
        else if(r2<r1||temp==1){   v=spar2[b][2];spar3[i][0]=r2;spar3[i][1]=c2;spar3[i][2]=v;b++;    }

    }
        spar3[0][2]=z;
        int spar5[z+1][3]; int spar6[z+1][3];
printf("addition\n");
    for(i=0;i<=z;i++)
    {
        for(j=0;j<3;j++){  if(j!=2)spar5[i][j]=spar3[i][j]+1; else spar5[i][j]=spar3[i][j];   printf("%d ",spar3[i][j]);}
        printf("\n");
    }

    spar6[0][0]=spar5[0][0];
    spar6[0][1]=spar5[0][1];
    spar6[0][2]=spar5[0][2];
    int spar4[z+1][3];
    spar4[0][1]=spar3[0][1];
    spar4[0][2]=spar3[0][2];
    spar4[0][0]=spar3[0][0];
    for(i=1;i<=z;i++)
    {
    int min=1000000;
    int temp;
       for(j=1;j<=z;j++)
       {
           if(spar3[j][1]<min){min=spar3[j][1]; temp=j;}
       }
        spar4[i][0]=spar3[temp][1];
        spar4[i][1]=spar3[temp][0];
        spar4[i][2]=spar3[temp][2];
        spar3[temp][1]=10000000;
    }
    printf("\n\n");
    printf("simple transpose\n");
     for(i=0;i<=z;i++)
    {
        for(j=0;j<3;j++)printf("%d ",spar4[i][j]);
        printf("\n");

    }


int t=z;

int s[c+1];for(i=0;i<=c;i++)
{
    s[i]=0;
}

int T[c+1];
T[1]=1;

for(i=1;i<=t;i++)
{
    s[spar5[i][1]]++;
}

for(i=2;i<=c;i++)
{
    T[i]=T[i-1]+s[i-1];
}

for(i=1;i<=t;i++)

{
    j=spar5[i][1];
    spar6[T[j]][0]=spar5[i][1]-1;
    spar6[T[j]][1]=spar5[i][0]-1;
    spar6[T[j]][2]=spar5[i][2];
    T[j]=T[j]+1;
}
printf("fast transpose\n");
for(i=0;i<=t;i++)
{
    printf("%d %d %d \n",spar6[i][0],spar6[i][1],spar6[i][2]);
}

}
