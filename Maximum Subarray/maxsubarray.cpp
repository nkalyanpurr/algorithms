#include <stdio.h> 

struct ReturnValue
{
    int leftmax;
    int rightmax;
    int Sum;
};

int max(int a, int b) { return (a > b)? a : b; } 
int max(int a, int b, int c) { return max(max(a, b), c); } 

ReturnValue maxspan(int arr[], int l, int m, int h) 
{ 
	// Include elements on left of mid 
	int sum = 0; 
	int leftmax, rightmax;
	int left_sum = -2000; 
	for (int i = m; i >= l; i--) 
	{ 
		sum = sum + arr[i]; 
		if (sum > left_sum) 
		{
		    left_sum = sum;
            leftmax = i;
		}
	
	} 
    
	// Include elements on right of mid 
	sum = 0; 
	int right_sum = -2000; 
	for (int i = m+1; i <= h; i++) 
	{ 
		sum = sum + arr[i]; 
		if (sum > right_sum) 
		{
		    right_sum = sum;
		    rightmax = i;
		}
	
		
	} 
	// Return indexes and sum of elements on left and right of mid 
	return {leftmax , rightmax, left_sum + right_sum}; 
} 


ReturnValue maxSubArraySum(int arr[], int l, int h) 
{ 
ReturnValue leftTree, rightTree, nodeTree;
// base case 
if (l == h) 
	return {l, l, arr[l]}; 

// Find middle point 
int m = (l + h)/2; 

leftTree = maxSubArraySum(arr,l,m); //Find maxsubarray from l to mid
rightTree = maxSubArraySum(arr,m+1,h); //Find maxsubarray from mid+1 to h
nodeTree = maxspan(arr,l,m,h);
int maxvalue=max(leftTree.Sum,rightTree.Sum,nodeTree.Sum);

if(maxvalue == leftTree.Sum)
    return leftTree;
    else if(maxvalue == rightTree.Sum)
    return rightTree;
    else
    return nodeTree;
}

int main() 
{ 
ReturnValue SubArray;
int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
int n = sizeof(arr)/sizeof(arr[0]); 
SubArray = maxSubArraySum(arr, 0, n-1); 

printf("Maximum sum is %d \n", SubArray.Sum); 

printf("indexes from %d to %d",SubArray.leftmax,SubArray.rightmax);
return 0; 
} 