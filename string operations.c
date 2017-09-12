#include<stdio.h>
#include<string.h>
void length()
{
    char *p;int i,len=0;
     char s[100];
     printf("\nENTER STRINGS ::  ");
      scanf("%s",s);
       p=s;
        for(i=0;*(p+i)!='\0';i++)
        len++;
        printf("\nLENGTH OF GIVEN STRING ::  ");
        printf("%d ",len);
}
void palindrome()
{
   char *p;int i,len=0;
     char s[100];
     printf("\nENTER STRINGS ::  ");
      scanf("%s",s);
       p=s;
        int l=strlen((s));
        for(i=0;*(p+i)!='\0';i++)
        if(*(p+i)==*(p+l-1-i))
            len++;
        if(len==l)
            printf(" \npalindrome ::  ");
        else
        printf("\nnot a palindrome ::  ");
}
void reverse()
{
  char *p;int i,len=0;
     char s[100];
      printf("\nENTER STRINGS ::  ");
      scanf("%s",s);
       p=s;
        int l=strlen((s));
           printf("\nREVERSE ::  ");
           for(i=0;*(p+i)!='\0';i++)
           {
               printf("%c",*(p+l-1-i));
           }


}
void comparison()
{int flag=0;
  char *p1,*p2;int i,l1=0,l2=0;
     char s1[100],s2[100];
     printf("\nENTER STRINGS  1 ::\n");
      scanf("%s",s1);
      printf("\nENTER STRINGS  2 ::\n");
      scanf("%s",s2);
       p1=s1;
       p2=s2;
       l1=strlen(s1);
       l2=strlen(s2);
       if(l1!=l2)
       {printf("\nSTRINGS ARE NOT EQUAL\n");}
       else
       {int i=0;
           for(i=0;i<l1;i++)
            if(*(p1+i)!=*(p2+i))
             flag=1;
            if(flag==1)
            printf("\nSTRINGS ARE NOT EQUAL\n");
            else
            printf("\nSTRINGS ARE EQUAL\n");
       }

}
void copy()
{int flag=0;
  char *p1,*p2;int i,l=0;
     char s1[100],s2[100];
     printf("\nENTER STRINGS  ::\n");
      scanf("%s",s1);
       p1=s1;
       p2=s2;
       l=strlen(s1);
           for(i=0;i<l;i++)
            *(p2+i)=*(p1+i);
            printf("\nSTRINGS COPIED::\n");
            for(i=0;i<l;i++)
                printf("%c",*(p2+i));



}
int main()
{
int choice;
 while(1)
    {
    printf("\n1.Length");
    printf("\n2.Palindrome");
    printf("\n3.String Comparison");
    printf("\n4.Copy");
    printf("\n5.Reverse");
    printf("\n6.EXIT");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:length();printf("\n----------------------------------------------\n");break;
        case 2:palindrome();printf("\n----------------------------------------------\n");break;
        case 3:comparison();printf("\n----------------------------------------------\n");break;
        case 4:copy();printf("\n----------------------------------------------\n");break;
        case 5:reverse();printf("\n----------------------------------------------\n");break;
        default:printf("\n---------------------THANKS-------------------------\n");break;
      }
      if(choice==6)break;
}
return 0;
}
