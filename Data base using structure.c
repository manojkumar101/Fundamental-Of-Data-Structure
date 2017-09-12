#include<stdio.h>

struct student
{
    int roll;
    float marks;
    char name[100];
};

void display(struct student s1)
{
    printf("\n%12s%7d%10f",s1.name,s1.roll,s1.marks);

}

int search (struct student a[],int x,int p)
{
    int i;
    for(i=0;i<p;i++)
    {
        if(a[i].roll==x)
        {
            return i;
        }

    }
    return -1;

}

void modify(struct student* a)
{
    int b;
    printf("\n1.NAME\n2.MARKS\n3.ROLL NO\nPRESS KEY ::");
    scanf("%d",&b);
    switch(b)
    {
        case 1:printf("\nEnter Name\n"); scanf("%s",a->name);break;
        case 2:printf("\nEnter Marks\n");scanf("%f",&a->marks);break;
        case 3:printf("\nEnter roll no.\n");scanf("%d",&a->roll);break;
    }

}


main()
{
    int p=0,b=1,c,i,q;
    char ch;
    struct student a[100];
    do
      {
        printf("\n1.ADD DATA\n2.DISPLAY DATA\n3.DELETE DATA\n4.MODIFY DATA\n5.SEARCH DATA\n6.EXIT\n\nENTER YOUR CHOICE  ::");
        scanf("%d",&b);
        switch(b)
            {
                case 1: printf("\nENTER YOUR DATA\nROLLNO\tMARKS\tNAME OF STUDENT\n");
                        scanf("%d\t%f\t%s",&a[p].roll,&a[p].marks,a[p].name);
                        p++;
                        break;
                case 2: printf("\nNAME\tROLL NO.\tMARKS  \n");
                        for(i=0;i<p;i++)
                            {
                                display(a[i]);
                                printf("\n------------------------------------------------------\n");
                            }
                        break;
                case 3: printf("\nENTER ROLL.NO OF STUDENT\n");
                        scanf("%d",&b);
                        c = search(a,b,p);
                        if(c!=-1)
                            {
                                for(i=c;i<p-1;i++)
                                    {
                                        a[i]=a[i+1];
                                    }
                                p--;
                                printf("\nSUCCESSFULLY DELETED ::\n");

                            }
                        else
                            {
                                printf("\nDATA NOT FOUND\n");
                            }

                        break;
            case 4: printf("\nENTER ROLL NO OF STUDENT\n");
                    scanf("%d",&b);
                    c = search(a,b,p);
                    if(c!=-1)
                    {
                        modify(&a[c]);
                        printf("\nSUCCESSFULLY MODIFY ::\n");
                    }
                    else
                        printf("\nRECORD NOT FOUND\n");
                        break;

            case 5:
                    printf("\nENTER ROLL NO OF STUDENT\n");
                    scanf("%d",&b);
                    c = search(a,b,p);
                    if(c!=-1)
                      {
                        printf("\nRecord found\n");
                        display(a[c]);
                      }
                    else
                      {
                        printf("\nDATA NOT FOUND\n");
                      }
                    break;
            case 6:
                    break;

        }
    }while(ch!=6);

}
