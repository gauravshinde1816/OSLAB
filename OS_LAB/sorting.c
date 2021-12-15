#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int ascCmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int i, n;
	//take user input
	printf("Enter number of elements:");
	scanf("%d", &n);
	//creatinga array on size n+1 as to store search key
	int arr[n + 1];
	char *arrChar[n + 1];

	printf("Enter %d elements:", n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), ascCmp);

	//input the search key in array itself;
	printf("\nEnter element to be search:");
	scanf("%d", &arr[i]);

	//create process
	int pid = fork();

	//child process
	if (pid == 0)
	{

		//covert int array to char array
		for (i = 0; i < n + 1; i++)
		{
			char a[sizeof(int)];
			snprintf(a, sizeof(int), "%d", arr[i]);
			arrChar[i] = (char *)malloc(sizeof(a));
			strcpy(arrChar[i], a);
		}
		arrChar[i] = NULL;
		//execute binSearch using execve
		execve("./bs", arrChar, NULL);
	}

	return 0;
}
