#pragma once
#include<iostream>
#include<string>
#include<queue>
#include"RadixSort.h"


using namespace std;

// function to perform value comparison
int comparisonFunction(int x, int a) {


	if (x <= a)return x;//if value x is less than or equal to value a, return x.
	else return a;//else, return a.
}


//Function performs search based on fibonacci values generated with the help of array size
int FibonacciSearch(int arr[], int x, int z) {

	//Fibonacci foundation integers
	int value1 = 0;int value2 = 1;int sumvalue = value2 + value1;

	//
	while (sumvalue < z)//while sumvalue is less than size of array, generate fibonacci numbers.
	{
		value2 = value1;//value2 now contains whatever value1 had.
		value1 = sumvalue;// value1 now contains whatever value sumvalue had.
		sumvalue = value2 + value1;//sumvalue now contains whatever values V1 and V2 had.
	}
	//Integer used in accounting for array positions already searched
	int postrac = -1;


	//Last fibonacci value based on size of array is 13

	while (sumvalue > 1)//while sumvalue is greater than 1
	{



		int i = comparisonFunction(postrac + value2, z - 1);//provide integer i based on minimum function calculation
											//
		if (arr[i] < x)//if array position arr[i] is less than searched value, perfom value reassignment
					   //value reassignment is based on reverting to previous state of "before last" fibonacci values
		{
			sumvalue = value1;//sumvalue now contains whatever value value1 had.
			value1 = value2;//value1 now contains whatever value value2 had.
			value2 = sumvalue - value1;//value2 now contains whatever (sumvalue minus value1) equates to.
			postrac = i;//postrac now contains whatever value integer i had.
		}

		//
		else if (arr[i] > x) {// if array position arr[i] is greater than searched value, we will still perform value reassignment
							  // however, value reassignment is slightly different, no longer needing to account for postrac adjustment

			sumvalue = value2;// sumvalue now contains whatever value V1 had.
			value1 = value1 - value2;//V1 now contains value of (V1-V2)
			value2 = sumvalue - value1;//sumvalue now contains value of (sumvalue minus V1).
		}
		else {
			return i;// value should be found in this case, return position for display when function is called.
			
			}
	}

	//This if statement accounts for a value to be searched in the very last position of the array.
	//If value 1 and array position [postrac + 1] is equal to value to be found, return postrac plus 1.
	if (value1 && arr[postrac + 1] == x) {
		return postrac + 1;//return postrac plus 1
	}


	
	return -1;//Return -1 in the event value is not found


}