#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    char name[20];
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;
void shownode();
void insertnode()
{int i,n,x;char nam[20];
                             printf("Enter the node position  :: ");
                             scanf("%d",&n);
                             printf("\nenter name ::");
                             scanf("%s",nam);
                             printf("\nenter roll ::");
                             scanf("%d",&x);


    				if(n!=0)
    {struct node* temp=(struct node*)malloc(sizeof(struct node*));
      temp->data=x;
      strcpy(temp->name,nam);
      temp->next=NULL;
      temp->prev=NULL;
      if(n==1)
        {
         if(head!=NULL)
            {head->prev=temp;temp->next=head;
            }

           head=temp;
           return;

        }
      else{
      struct node* search=head;
      for(i=0;i<n-2;i++)
      search=search->next;
      temp->next=search->next;
      temp->prev=search;
      search->next=temp;
      }

    }
    else
    printf("enter valid position\n");
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
        struct node* search1=search->next,*flag=search1->prev;
        search->next=search1->next;
        search=search->next;
        search->prev=flag;
        free(search1);
    }
    else
    printf("enter valid position\n");
    printf("\n!!!!!RECORD DELETED !!!!!!\n");
    return;
}
void shownode()
{ printf("\n!!!!forward direction !!!!\n");
  struct node* search=head;
  printf("Name\t\tRoll NO\n");
  while(search!=NULL)
  {   printf("%s\t\t",search->name);
      printf("%d\n",search->data);
      search=search->next;
  }
}
void display()
{ printf("\n__________________________\n!!!!RECORD AVAILABLE!!!!\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  struct node* search=head;
   printf("Name\t\tRoll NO\n");
  while(search!=NULL)
  {   printf("%s\t\t",search->name);
      printf("%d\n",search->data);
      search=search->next;
  }
}
void reversenode()
{   printf("\n!!!!backward direction !!!!\n");
    struct node* search=head;
    while(search->next!=NULL)
    {search=search->next;}
     while(search!=NULL)
      {
      printf("Name    ::%s\n",search->name);
      printf("Roll no ::%d\n",search->data);
      search=search->prev;
     }

}

void modify()
{int n;char nam[20];
	printf("\nEnter the roll no ::  ");
	scanf("%d",&n);
  struct node* search=head;
  while(search!=NULL)
  {   if(search->data==n)
  	{
 		printf("\nenter name ::");
                 scanf("%s",nam);
                 strcpy(search->name,nam);
                 break;
  	}
      search=search->next;
  }
}

int main()
{   int x;
    int flag=0,i,ch,n;head=NULL;
    while(1)
    {
    printf("\n1.NEW RECORD\n2.ADD RECORD AT ANY POSITION\n3.DELETE RECORD FROM ANY POSITION\n4.FORWARD\n5.BACKWARD\n6.MODIFY RECORD\n7.DISPLAY\n8.EXIT\nENTER YOUR CHOICE  ::");
    scanf("%d",&ch);
        switch(ch)
            {
                case 1:printf("Enter the number of Inputs\n");
                        scanf("%d",&n);
                        printf("Enter the data record of %d students \n",n);
                        for(i=0;i<n;i++)
                        {   char nam[20];
                            printf("\nenter name ::");
                            scanf("%s",nam);;
                            printf("\nenter roll ::");
                            scanf("%d",&x);

                           struct node* temp=(struct node*)malloc(sizeof(struct node));
                           temp->data=x;
                           strcpy(temp->name,nam);
                           temp->next=NULL;
                           temp->prev=NULL;
                           if(head!=NULL)
                            {head->prev=temp;temp->next=head;
                            }
                            head=temp;

                        }
                        break;
                case 2:insertnode();break;
                case 3:printf("\nEnter the position  :: ");
                        scanf("%d",&n);deletenode(n);
                        break;
                case 4:shownode();
                       break;
                case 5:reversenode();break;
                case 6:modify();break;
                case 7:display();break;
                default:printf("\n-------------\n");break;



            }
            if(ch==8)
            break;
    }
    return 0;
}

