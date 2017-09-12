#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insertnode(int n,int x)
{int i;
    if(n!=0)
    {struct node* temp=(struct node*)malloc(sizeof(struct node*));
      temp->data=x;
      temp->next=NULL;
      if(n==1)
        {
       temp->next=head;
           head=temp;
           return;
        }

      struct node* search=head;
      for(i=0;i<n-2;i++)
        search=search->next;
      temp->next=search->next;
      search->next=temp;

    }
    else
    printf("enter valid position\n");
    printf("\nresult after operation\n");
    shownode();
    return;
}
void deletenode(int n)
{int i;
    if(n!=0)
    {
       struct node* search=head;
       if(n==1)
        {
        head=search->next;
        return;
        }
       for(i=0;i<n-2;i++)
        search=search->next;
        struct node* search1=search->next;
        search->next=search1->next;
        free(search1);
    }
    else
    printf("enter valid position\n");
     printf("\nresult after operation\n");
    shownode();
    return;
}
void shownode()
{
  struct node* search=head;
  while(search!=NULL)
  {
      printf("data ::%d\n",search->data);
      search=search->next;
  }
}
void reversenode(int x)
{
    struct node *current,*prev,*next;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
      head=prev;
      if(x==11)
        return ;
    struct node* search=prev;
    while(search!=NULL)
    {
      printf("data ::%d\n",search->data);
      search=search->next;
     }

}
int main()
{   int x;
    int flag=0,i,ch,n;head=NULL;struct node* search=head;
    while(1)
    {
    printf("\n1.ADD NODE\n2.ADD NODE AT ANY POSITION\n3.DELETE NODE FROM ANY POSITION\n4.DISPLAY LIST\n5.DISPLAY REVERSE\n6.REVERT\nENTER YOUR CHOICE  ::");
    scanf("%d",&ch);
        switch(ch)
            {
                case 1:
                        printf("Enter the no of data:: ");
                        scanf("%d",&n);
                        for(i=0;i<n;i++)
                        {
                            printf("\nEnter the value ::");
                            scanf("%d",&x);
                             struct node* temp=(struct node*)malloc(sizeof(struct node*));
                                temp->data=x;
                                temp->next=NULL;
                                if(head==NULL)
                                 {head=temp;
                                  search=head;
                                 }
                                 else
                                 {while(search->next!=NULL)
                                     { search=search->next;}
                                     search->next=temp;
                                  }
                        }
                                            break;
                case 2:printf("Enter the node position  :: ");
                        scanf("%d",&n);
                            printf("\nEnter the value ::");
                            scanf("%d",&x);
                            insertnode(n,x);
                            break;
                case 3:printf("\nEnter the node position  :: ");
                        scanf("%d",&n);
                            deletenode(n);
                            break;
                case 4:printf("\nDISPLAY LIST\n");
                       shownode();
                       break;
                case 5:printf("\nReverse the list\n");
                       reversenode(1);
                       reversenode(11);
                       break;
                case 6:reversenode(1);


            }
    }
    return 0;
}

