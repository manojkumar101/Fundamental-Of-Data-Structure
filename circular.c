
#include<stdio.h>
#include<stdlib.h>
struct node
{
   int pow,coe;
    struct node* next;
};
struct node* first=NULL;
struct node* second=NULL;
struct node* ans=NULL;
struct node* getnode(int p,int c)
{
            struct node* temp=(struct node*)malloc(sizeof(struct node*));
            temp->pow=p;
            temp->coe=c;
            temp->next=NULL;
};
int main()
{
    struct node *a,*b,*c,*p;
     printf("enter the number of elements in first equation\n");
    scanf("%d",&n);
    printf("enter power_____coeffient \n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        if(first==NULL){
            first=getnode(j,k);
             p=first;
        }
        else {
        p->next=getnode(j,k);
        p=p->next;

        }
    }p->next=first;
    printf("\n");

    printf("enter the number of elements in second equation\n");
    scanf("%d",&n);
    printf("enter power_____coeffient \n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        if(second==NULL){   second=getnode(j,k); p=second; }
        else {
    p->next=getnode(j,k);
    p=p->next;

        }
    } p->next=second;

    a=first;
    b=second;
    c=ans;

    return 0;
}

