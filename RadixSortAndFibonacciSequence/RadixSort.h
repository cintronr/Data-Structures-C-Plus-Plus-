#pragma once
#include<iostream>
#include<string>
#include<queue>
#include <chrono>
#include <thread>
#include <ctime>
#include<cstdlib>

using namespace std;
using namespace std::this_thread;// allows sleep_for or sleep_until
using namespace std::chrono_literals;//enables use of nano seconds, ms, s, h, etc.
using std::chrono::system_clock;


//Function for printing contents of array.
void printArray(int firstPass[], int n) {
	for (int i = 0; i < n; i++)//for int i; i <(array size); i++
		cout << firstPass[i] << " ";
		
		cout << endl;
		sleep_for(300ms);


}





void radixSort1(int numbersArray[], int firstPass[], int secondPass[], int thirdPass[], int finalPass[], int n, int one[], int two[], int three[], int four[], int five[], int six[], int seven[], int eight[], int nine[], int zero[]) {

	//integers for array bucket positions
	int posit1 = 0;
	int posit2 = 0;
	int posit3 = 0;
	int posit4 = 0;
	int posit5 = 0;
	int posit6 = 0;
	int posit7 = 0;
	int posit8 = 0;
	int posit9 = 0;
	int posit0 = 0;

	// for loop using size of array passed in as limiting value
	for (int i = 0; i < n; i++)
	{
		//integers for calculations, useful in digit position determination
		int temp;
		int pass;
		temp = (numbersArray[i] % 10);//temp is equal to array value in position [i] mod whatever value was passed in, in this first pass, values should be 10 and 100
		pass = (temp / 1);//value generated based on value at digit position in the ones place
		if (pass == 0)// if value is equal to zero... 
		{
			zero[posit0] = numbersArray[i]; //we ill push that whole value into bucket named zero at position 0.
			posit0++;// increment in the event another array position value also has a digit in the ones place equal to zero
		}
		//all following else if and else statements follow the same principle above, if a value in the ones place is equal to 1,2,3,etc this value will be pushed into a bucket based on the value of digit in ones place
		else if (pass == 1) {
			one[posit1] = numbersArray[i];
			posit1++;
		}
		else if (pass == 2) {
			two[posit2] = numbersArray[i];
			posit2++;
		}
		else if (pass == 3) {
			three[posit3] = numbersArray[i];
			posit3++;
		}
		else if (pass == 4) {
			four[posit4] = numbersArray[i];
			posit4++;
		}
		else if (pass == 5) {
			five[posit5] = numbersArray[i];
			posit5++;
		}
		else if (pass == 6) {
			six[posit6] = numbersArray[i];
			posit6++;
		}
		else if (pass == 7) {
			seven[posit7] = numbersArray[i];
			posit7++;
		}
		else if (pass == 8) {
			eight[posit8] = numbersArray[i];
			posit8++;
		}
		else if (pass == 9) {
			nine[posit9] = numbersArray[i];
			posit9++;
		}
		else cout << "<Invalid value!";


	}
	// this section  of for statements will take values stored in bucket from aforementioned code and will pass values into a new array called first pass. 
	
	int firstPASS = 0;
	int uniqueP0 = 0;
	for (int i = 0; i < posit0; i++) {
		firstPass[firstPASS] = zero[uniqueP0];
		uniqueP0++;//unique pass int incrementation allows for accounting of this specific array positon for correct incrementation.
		firstPASS++;//this firstPass incrmentation will provide proper accounting for entire array size
	}
	//following for loops follow the same exact principle of the for loop above, with the exception that this is now handling 1,2,3,4 et cetera...
	int uniqueP1 = 0;
	for (int i = 0; i < posit1; i++) {
		firstPass[firstPASS] = one[uniqueP1];
		uniqueP1++;
		firstPASS++;
	}
	int uniqueP2 = 0;
	for (int i = 0; i < posit2; i++) {
		firstPass[firstPASS] = two[uniqueP2];
		uniqueP2++;
		firstPASS++;
	}
	int uniqueP3 = 0;
	for (int i = 0; i < posit3; i++) {
		firstPass[firstPASS] = three[uniqueP3];
		uniqueP3++;
		firstPASS++;
	}
	int uniqueP4 = 0;
	for (int i = 0; i < posit4; i++) {
		firstPass[firstPASS] = four[uniqueP4];
		uniqueP4++;
		firstPASS++;
	}
	int uniqueP5 = 0;
	for (int i = 0; i < posit5; i++) {
		firstPass[firstPASS] = five[uniqueP5];
		uniqueP5++;
		firstPASS++;
	}
	int uniqueP6 = 0;
	for (int i = 0; i < posit6; i++) {
		firstPass[firstPASS] = six[uniqueP6];
		uniqueP6++;
		firstPASS++;
	}
	int uniqueP7 = 0;
	for (int i = 0; i < posit7; i++) {
		firstPass[firstPASS] = seven[uniqueP7];
		uniqueP7++;
		firstPASS++;
	}
	int uniqueP8 = 0;
	for (int i = 0; i < posit8; i++) {
		firstPass[firstPASS] = eight[uniqueP8];
		uniqueP8++;
		firstPASS++;
	}
	int uniqueP9 = 0;
	for (int i = 0; i < posit9; i++) {

		firstPass[firstPASS] = nine[uniqueP9];
		uniqueP9++;
		firstPASS++;
	}

}


//function for second pass, following same principles from the first pass function, with the exception that we are now examining the digit in the "tens" place...
void radixSort2(int numbersArray[], int firstPass[], int secondPass[], int thirdPass[], int finalPass[], int n, int one[], int two[], int three[], int four[], int five[], int six[], int seven[], int eight[], int nine[], int zero[]) {

	int posit1 = 0;
	int posit2 = 0;
	int posit3 = 0;
	int posit4 = 0;
	int posit5 = 0;
	int posit6 = 0;
	int posit7 = 0;
	int posit8 = 0;
	int posit9 = 0;
	int posit0 = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		int pass;
		temp = (firstPass[i] % 100);
		pass = (temp / 10);
		if (pass == 0)
		{
			zero[posit0] = firstPass[i];
			posit0++;
		}
		else if (pass == 1) {
			one[posit1] = firstPass[i];
			posit1++;
		}
		else if (pass == 2) {
			two[posit2] = firstPass[i];
			posit2++;
		}
		else if (pass == 3) {
			three[posit3] = firstPass[i];
			posit3++;
		}
		else if (pass == 4) {
			four[posit4] = firstPass[i];
			posit4++;
		}
		else if (pass == 5) {
			five[posit5] = firstPass[i];
			posit5++;
		}
		else if (pass == 6) {
			six[posit6] = numbersArray[i];
			posit6++;
		}
		else if (pass == 7) {
			seven[posit7] = firstPass[i];
			posit7++;
		}
		else if (pass == 8) {
			eight[posit8] = firstPass[i];
			posit8++;
		}
		else if (pass == 9) {
			nine[posit9] = firstPass[i];
			posit9++;
		}
		else cout << "<Invalid value!";


	}
	int secondPASS = 0;
	int uniqueP0 = 0;
	for (int i = 0; i < posit0; i++) {
		secondPass[secondPASS] = zero[uniqueP0];
		uniqueP0++;
		secondPASS++;
	}
	int uniqueP1 = 0;
	for (int i = 0; i < posit1; i++) {
		secondPass[secondPASS] = one[uniqueP1];
		uniqueP1++;
		secondPASS++;
	}
	int uniqueP2 = 0;
	for (int i = 0; i < posit2; i++) {
		secondPass[secondPASS] = two[uniqueP2];
		uniqueP2++;
		secondPASS++;
	}
	int uniqueP3 = 0;
	for (int i = 0; i < posit3; i++) {
		secondPass[secondPASS] = three[uniqueP3];
		uniqueP3++;
		secondPASS++;
	}
	int uniqueP4 = 0;
	for (int i = 0; i < posit4; i++) {
		secondPass[secondPASS] = four[uniqueP4];
		uniqueP4++;
		secondPASS++;
	}
	int uniqueP5 = 0;
	for (int i = 0; i < posit5; i++) {
		secondPass[secondPASS] = five[uniqueP5];
		uniqueP5++;
		secondPASS++;
	}
	int uniqueP6 = 0;
	for (int i = 0; i < posit6; i++) {
		secondPass[secondPASS] = six[uniqueP6];
		uniqueP6++;
		secondPASS++;
	}
	int uniqueP7 = 0;
	for (int i = 0; i < posit7; i++) {
		secondPass[secondPASS] = seven[uniqueP7];
		uniqueP7++;
		secondPASS++;
	}
	int uniqueP8 = 0;
	for (int i = 0; i < posit8; i++) {
		secondPass[secondPASS] = eight[uniqueP8];
		uniqueP8++;
		secondPASS++;
	}
	int uniqueP9 = 0;
	for (int i = 0; i < posit9; i++) {

		secondPass[secondPASS] = nine[uniqueP9];
		uniqueP9++;
		secondPASS++;
	}

}

//function for third pass, following same principles from the second pass function, with the exception that we are now examining the digit in the "hundreds" place...
void radixSort3(int numbersArray[], int firstPass[], int secondPass[], int thirdPass[], int finalPass[], int n, int one[], int two[], int three[], int four[], int five[], int six[], int seven[], int eight[], int nine[], int zero[]) {

	int posit1 = 0;
	int posit2 = 0;
	int posit3 = 0;
	int posit4 = 0;
	int posit5 = 0;
	int posit6 = 0;
	int posit7 = 0;
	int posit8 = 0;
	int posit9 = 0;
	int posit0 = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		int pass;
		temp = (secondPass[i] % 1000);
		pass = (temp / 100);
		if (pass == 0)
		{
			zero[posit0] = secondPass[i];
			posit0++;
		}
		else if (pass == 1) {
			one[posit1] = secondPass[i];
			posit1++;
		}
		else if (pass == 2) {
			two[posit2] = secondPass[i];
			posit2++;
		}
		else if (pass == 3) {
			three[posit3] = secondPass[i];
			posit3++;
		}
		else if (pass == 4) {
			four[posit4] = secondPass[i];
			posit4++;
		}
		else if (pass == 5) {
			five[posit5] = secondPass[i];
			posit5++;
		}
		else if (pass == 6) {
			six[posit6] = secondPass[i];
			posit6++;
		}
		else if (pass == 7) {
			seven[posit7] = secondPass[i];
			posit7++;
		}
		else if (pass == 8) {
			eight[posit8] = secondPass[i];
			posit8++;
		}
		else if (pass == 9) {
			nine[posit9] = secondPass[i];
			posit9++;
		}
		else cout << "<Invalid value!";


	}
	int thirdPASS = 0;
	int uniqueP0 = 0;
	for (int i = 0; i < posit0; i++) {
		thirdPass[thirdPASS] = zero[uniqueP0];
		uniqueP0++;
		thirdPASS++;
	}
	int uniqueP1 = 0;
	for (int i = 0; i < posit1; i++) {
		thirdPass[thirdPASS] = one[uniqueP1];
		uniqueP1++;
		thirdPASS++;
	}
	int uniqueP2 = 0;
	for (int i = 0; i < posit2; i++) {
		thirdPass[thirdPASS] = two[uniqueP2];
		uniqueP2++;
		thirdPASS++;
	}
	int uniqueP3 = 0;
	for (int i = 0; i < posit3; i++) {
		thirdPass[thirdPASS] = three[uniqueP3];
		uniqueP3++;
		thirdPASS++;
	}
	int uniqueP4 = 0;
	for (int i = 0; i < posit4; i++) {
		thirdPass[thirdPASS] = four[uniqueP4];
		uniqueP4++;
		thirdPASS++;
	}
	int uniqueP5 = 0;
	for (int i = 0; i < posit5; i++) {
		thirdPass[thirdPASS] = five[uniqueP5];
		uniqueP5++;
		thirdPASS++;
	}
	int uniqueP6 = 0;
	for (int i = 0; i < posit6; i++) {
		thirdPass[thirdPASS] = six[uniqueP6];
		uniqueP6++;
		thirdPASS++;
	}
	int uniqueP7 = 0;
	for (int i = 0; i < posit7; i++) {
		thirdPass[thirdPASS] = seven[uniqueP7];
		uniqueP7++;
		thirdPASS++;
	}
	int uniqueP8 = 0;
	for (int i = 0; i < posit8; i++) {
		thirdPass[thirdPASS] = eight[uniqueP8];
		uniqueP8++;
		thirdPASS++;
	}
	int uniqueP9 = 0;
	for (int i = 0; i < posit9; i++) {

		thirdPass[thirdPASS] = nine[uniqueP9];
		uniqueP9++;
		thirdPASS++;
	}

}

//function for final pass, following same principles from the third pass function, witht the exception that we are now examining the digit in the "thousand" place...
void radixSort4(int numbersArray[], int firstPass[], int secondPass[], int thirdPass[], int finalPass[], int n, int one[], int two[], int three[], int four[], int five[], int six[], int seven[], int eight[], int nine[], int zero[]) {

	int posit1 = 0;
	int posit2 = 0;
	int posit3 = 0;
	int posit4 = 0;
	int posit5 = 0;
	int posit6 = 0;
	int posit7 = 0;
	int posit8 = 0;
	int posit9 = 0;
	int posit0 = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		int pass;
		temp = (thirdPass[i] % 10000);
		pass = (temp / 1000);
		if (pass == 0)
		{
			zero[posit0] = thirdPass[i];
			posit0++;
		}
		else if (pass == 1) {
			one[posit1] = thirdPass[i];
			posit1++;
		}
		else if (pass == 2) {
			two[posit2] = thirdPass[i];
			posit2++;
		}
		else if (pass == 3) {
			three[posit3] = thirdPass[i];
			posit3++;
		}
		else if (pass == 4) {
			four[posit4] = thirdPass[i];
			posit4++;
		}
		else if (pass == 5) {
			five[posit5] = thirdPass[i];
			posit5++;
		}
		else if (pass == 6) {
			six[posit6] = thirdPass[i];
			posit6++;
		}
		else if (pass == 7) {
			seven[posit7] = thirdPass[i];
			posit7++;
		}
		else if (pass == 8) {
			eight[posit8] = thirdPass[i];
			posit8++;
		}
		else if (pass == 9) {
			nine[posit9] = thirdPass[i];
			posit9++;
		}
		else cout << "<Invalid value!";


	}
	int fourthPASS = 0;
	int uniqueP0 = 0;
	for (int i = 0; i < posit0; i++) {
		finalPass[fourthPASS] = zero[uniqueP0];
		uniqueP0++;
		fourthPASS++;
	}
	int uniqueP1 = 0;
	for (int i = 0; i < posit1; i++) {
		finalPass[fourthPASS] = one[uniqueP1];
		uniqueP1++;
		fourthPASS++;
	}
	int uniqueP2 = 0;
	for (int i = 0; i < posit2; i++) {
		finalPass[fourthPASS] = two[uniqueP2];
		uniqueP2++;
		fourthPASS++;
	}
	int uniqueP3 = 0;
	for (int i = 0; i < posit3; i++) {
		finalPass[fourthPASS] = three[uniqueP3];
		uniqueP3++;
		fourthPASS;
	}
	int uniqueP4 = 0;
	for (int i = 0; i < posit4; i++) {
		finalPass[fourthPASS] = four[uniqueP4];
		uniqueP4++;
		fourthPASS++;
	}
	int uniqueP5 = 0;
	for (int i = 0; i < posit5; i++) {
		finalPass[fourthPASS] = five[uniqueP5];
		uniqueP5++;
		fourthPASS++;
	}
	int uniqueP6 = 0;
	for (int i = 0; i < posit6; i++) {
		finalPass[fourthPASS] = six[uniqueP6];
		uniqueP6++;
		fourthPASS++;
	}
	int uniqueP7 = 0;
	for (int i = 0; i < posit7; i++) {
		finalPass[fourthPASS] = seven[uniqueP7];
		uniqueP7++;
		fourthPASS++;
	}
	int uniqueP8 = 0;
	for (int i = 0; i < posit8; i++) {
		finalPass[fourthPASS] = eight[uniqueP8];
		uniqueP8++;
		fourthPASS++;
	}
	int uniqueP9 = 0;
	for (int i = 0; i < posit9; i++) {

		finalPass[fourthPASS] = nine[uniqueP9];
		uniqueP9++;
		fourthPASS++;
	}

}

//While my radix sort function would have benefited from recursion and a few other modifications, however i felt my iteration of radix sort helped me understand the complete operation and I will be able to develop radix sort algorithms with intimate understanding in mind.