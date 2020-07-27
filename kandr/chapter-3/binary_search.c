/* binsearch find x in v[0] <= v[1] <= ... <= v[n-1] */ 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "/home/slanjo/Programming/C/kandr/chapter-6/count_keywords.h"
int binsearch(int x, int v[], int n);
int main(){
	int x  = 2;
	int y;	
	int v[] = {1,2,18,22,23,35,36,44,45,51,52,61,64,156,11110};
	int n = (int) (sizeof(v)/sizeof(int));
//	int n =  15;
    
    printf("n = %i\n", n);
	y = binsearch(x, v, n);
	printf("y = %i\n", y);
	if (y == -1)
		printf("the number %i is not in the array v\n", x);
	else 
		printf("the number %i is in the array v\n", v[y]); 



	return 0;

}

int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n - 1;
	
	while (low <= high){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found a match */
			return mid;
	}
	return -1;



}
