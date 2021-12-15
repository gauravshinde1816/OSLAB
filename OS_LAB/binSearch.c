
#include <stdio.h>     
#include <stdlib.h>     

int cmpFunc (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main (int argc,char *argv[])
{
  int * pItem,i,key,n;
  int arr[argc];
  printf("\nArgc::%d",argc);	
  //covert char array to int 

  for(i=0;i<argc-1;i++)
  {
  	n = atoi(argv[i]);
  	arr[i] = n;
  }
  key = atoi(argv[i]);
   
  pItem = (int*) bsearch (&key, arr, 5, sizeof (int), cmpFunc);
  if (pItem!=NULL)
    printf ("\n%d is in the array.\n",*pItem);
  else
    printf ("\n%d is not in the array.\n",key);
  
  return 0;
}
