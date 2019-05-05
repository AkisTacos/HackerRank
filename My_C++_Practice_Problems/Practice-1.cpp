//
// Description
/*

	Given a number and a list of numbers, write a program that gives the total
	number of times the numbers in the list sum to the given number.
	Numbers in the list can be repeated.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func_total_number_of_finds(vector<int> &nums, int givenNum){
	int result = 0, i, check;

	vector<int>::iterator it;

	for(i = 0; i < nums.size(); i++){
		// Don't need to test numbers that are larger than our given number
		if(nums.at(i) > givenNum){
			break;
		} else {
			check = givenNum - nums.at(i);
			// check if that number is in list
			it = find(nums.begin(), nums.end(), check);
			if(it != nums.end()){
				// found it
				result++;
			}
		}
	}

	return result;
}


int main(){

	vector<int> list;
	// Generate 10 random number from 1-10;
	int i, randomNum, result, testNumber;

	cout << "List: ";
	for(i = 0; i < 10; i++){
		randomNum = rand() % 10 + 1;
		list.push_back(randomNum);
		cout << randomNum << ' ';
	}
	cout << endl;

	testNumber = rand() % 20 + 5;
	result = func_total_number_of_finds(list, testNumber);

	
	cout << "Our given number: " << testNumber << endl;
	cout << "Our results: " << result << endl;
}