#include<stdio.h>
struct dataent
{   int rollno;
    char name[30];
    float mark;
}data;
void insert()
{   FILE *fp;
    fp=fopen("E:\\record","a+");
    printf("ENTER ROLL NO :");
    scanf("%d",&data.rollno);
    printf("ENTER NAME    :");
    scanf("%s",&data.name);
    printf("ENTER MARKS   :");
    scanf("%f",&data.mark);
    fwrite(&data,sizeof(data),1,fp);
    fclose(fp);
}
void disp()
{
    FILE *fp1;
    fp1=fopen("E:\\record","r");
    rewind(fp1);
    printf("\nRoll No\tName\tMark\n");
    while(fread(&data,sizeof(data),1,fp1)){
    printf("%d\t%s\t%.2f\n",data.rollno,data.name,data.mark);
    }
    fclose(fp1);
}
void search()
{
    FILE *fp2;
    int r,s,flag=0;
    printf("\nEnter the Roll:");
    scanf("%d",&r);
    {    fp2=fopen("E:\\record","r");
        while(fread(&data,sizeof(data),1,fp2))
        {
            s=data.rollno;
            if(s==r)
            {
                printf("\nRoll no ::%d",data.rollno);
                printf("\nName    ::%s",data.name);
                printf("\nMark    ::%.2f",data.mark);
                flag=1;
            }
        }
        if(flag=0)printf("Data not found");
        fclose(fp2);
    }
}
void deletedata()
{
    FILE *fp;
    FILE *fpt;
    int r,s;
    printf("Enter the Roll :");
    scanf("%d",&r);
        fp=fopen("E:\\record","r");
        fpt=fopen("E:\\extra","w");
        while(fread(&data,sizeof(data),1,fp))
        {    s=data.rollno;
            if(s!=r)
            fwrite(&data,sizeof(data),1,fpt);
        }
        fclose(fp);
        fclose(fpt);
        fp=fopen("E:\\record","w");
        fpt=fopen("E:\\extra","r");
        while(fread(&data,sizeof(data),1,fpt))
        {
           fwrite(&data,sizeof(data),1,fp);
        }
    printf("\nDELETED!!!!!!!!!\n");
    fclose(fp);
    fclose(fpt);
}
void update()
{
    FILE *fpt;
    FILE *fp;
    int s,r,ch;
    printf("enter roll number to update");
    scanf("%d",&r);
        fp=fopen("E:\\record","r");
        fpt=fopen("E:\\extra","w");
        while(fread(&data,sizeof(data),1,fp))
          {
            s=data.rollno;
              if(s!=r)
              fwrite(&data,sizeof(data),1,fpt);
              else
               {    printf("Enter Name : ");
                    scanf("%s",data.name);
                    printf("Enter Mark : ");
                    scanf("%f",&data.mark);
                    fwrite(&data,sizeof(data),1,fpt);
                }

            }
        fclose(fp);
        fclose(fpt);
        fp=fopen("E:\\record","w");
        fpt=fopen("E:\\extra","r");
        while(fread(&data,sizeof(data),1,fpt))
        {
            fwrite(&data,sizeof(data),1,fp);
        }
        fclose(fp);
        fclose(fpt);
        fpt=fopen("E:\\extra","w");
        fclose(fpt);
        printf("UPDATED!!!!!");
}
int main()
{   int choice;
    do
    {         printf("\n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.DELETE\n5.UPDATE");
              printf("\nEnter your choice:");
                 scanf("%d",&choice);
                 printf("\n");
                 switch(choice)
                {       case 1:insert();break;
                        case 2:disp();break;
                        case 3:search();break;
                        case 4:deletedata();break;
                        case 5:update();break;
                        default:exit(0);
                }
    }while(choice<6);
}
