/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
// Problem Statement: C++ program to find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted.
/*Example:
1] INPUT: int arr[] = {12, 15, 17, 23, 31, 38, 34, 36, 37, 55, 62};
OUTPUT: The unsorted subarray which makes the given array
sorted lies between indices 5 and 8. */
#include<bits/stdc++.h>
using namespace std;
void UnsortedArray(int arr[], int x)
{
int a = 0, b = x-1, i, max, min;
//Start searching the element from left to right and find the first most element which is greater than the next element.
for (a = 0; a < x-1; a++)
{
	if (arr[a] > arr[a+1])
	break;
}
if (a == x-1)
{
	cout << "The complete array is sorted";
	return;
}
//Search element which is smaller than the next element.
for(b = x - 1; b > 0; b--)
{
	if(arr[b] < arr[b-1])
	break;
}
//Find the minimum and maximum values in the given array.
max = arr[a]; min = arr[a];
for(i = a + 1; i <= b; i++)
{
	if(arr[i] > max)
	max = arr[i];
	if(arr[i] < min)
	min = arr[i];
}
//Find the first element which is greater than minimum and change a to index of this element.
for( i = 0; i < a; i++)
{
	if(arr[i] > min)
	{
	a = i;
	break;
	}	
}
//Find the last element which is smaller than maximum.
for( i = x -1; i >= b+1; i--)
{
	if(arr[i] < max)
	{
	b = i;
	break;
	}
}	
//Print a and b.
cout << "The unsorted subarray lies between the indices " << endl
	<< a << " and " << b;
return;
}
int main()
{
	int array[] = {12, 15, 17, 23, 31, 38, 34, 36, 37, 55, 62};
	int array_size = sizeof(array)/sizeof(array[0]);
	UnsortedArray(array, array_size);
	getchar();
	return 0;
}