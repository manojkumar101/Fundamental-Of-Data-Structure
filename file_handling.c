
#include <stdio.h>
#include<conio.h>
int main() {
	char name[50];

	int marks,i;

	FILE *fptr;
	fptr=(fopen("E:student.txt","w"));
	if(fptr==NULL) {
		printf("Error!");
		exit(1);
	}

		printf("For student%d\nEnter name: ",i+1);
		scanf("%s",name);
		fprintf(fptr,"%s",name);

	fclose(fptr);
    printf("OUTPUT\n");
    fptr=(fopen("E:student.txt","r"));
    int c;
    c=getc(fptr);
	while(c!=EOF) {
		fscanf(fptr,"%s%d\n",&name,&marks);
		printf("%s\n%d \n",name,marks);

	}
	fclose(fptr);

	return 0;
}
