#include<stdio.h>
void Bubble()
{
    int  n, c, d,p, swap;
    printf("ENTER THE SIZE OF ARRAY ::\n");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d integers\n", n);
    for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

    printf("\nSTEP OF BUBBLE SORT-\n");
    for (c = 0 ; c < ( n - 1 ); c++)
        {
          for (d = 0 ; d < n - c - 1; d++)
            {
                if (array[d] > array[d+1])
                    {
                        swap       = array[d];
                        array[d]   = array[d+1];
                        array[d+1] = swap;
                        for ( p = 0 ; p < n ; p++ )
                        printf("%d ", array[p]);
                        printf("\n");
                    }
            }
        }
}


void selection()
{
    int  p , n, c, d, position, swap;
    printf("\nEnter number of elements\n");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d integers\n", n);
    for ( c = 0 ; c < n ; c++ )
      scanf("%d", &array[c]);
    printf("\nSTEP OF SELECTION SORT ::\n");
    for ( c = 0 ; c < ( n - 1 ) ; c++ )
       {
         position = c;
         for ( d = c + 1 ; d < n ; d++ )
            {
                if ( array[position] > array[d] )
                position = d;
            }
        if ( position != c )
            {
                swap = array[c];
                array[c] = array[position];
                array[position] = swap;
                for ( p = n-1 ; p >0 ; p-- )
                printf("%d ", array[p]);
                printf("\n");
            }
        }
}



int main()
{
    int ch;
    while(1)
      {
        printf("1.ASSENDING ORDER BY BUBBLE SORT\n2.DECENDING ORDER BY SELECTION SORT\n3.EXIT\n");
        printf("\nENTER YOUR CHOICE ::");
        scanf("%d",&ch);
        switch(ch)
            {
                case 1:Bubble();printf("\n----------------------------------");break;

                case 2:selection();printf("\n----------------------------------");break;

                default: printf("\n-------------------THANK YOU------------------");break;
            }
            if(ch==3)
                break;
      }

    return 0;
}
