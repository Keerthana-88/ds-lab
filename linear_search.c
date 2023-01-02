#include<stdio.h>
void main()
{
	int i,a[100],count=0,key,n;
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
        printf("Enter the element to be searched ");
        scanf("%d", &key);
        for (i = 0; i <n ; i++) {

        if (key == a[i] )
        {
            count = 1;

            break;
        }
    }

      if (count == 1)
	   printf("Element is present in the array at position %d",i+1);
    else
	    printf("elements are not found");
}
