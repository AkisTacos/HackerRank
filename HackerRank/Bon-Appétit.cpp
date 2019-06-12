// Aki Saito
// HackerRank - Easy
// Bon Appétit
// July 18, 2018
// Language: C++
// 
/* Description:
	MAnna and Brian are sharing a meal at a restuarant and they agree to split the bill equally. 
	Brian wants to order something that Anna is allergic to though, and they agree that Anna won't pay for that item. 
	Brian gets the check and calculates Anna's portion. You must determine if his calculation is correct.
	For example, assume the bill has the following prices: bill = [2, 4, 6]. 
	Anna declines to eat item k = bill[2] which costs 6. If Brian calculates the bill correctly, Anna will pay (2 + 4)/2 = 3. 
	If he includes the cost of bill[2], he will calculate (2 + 4+ 6)/2 = 6. In the second case, he should refund 3 to Anna.
	You are given an array of prices, bill, the cost of each of the n items, k, the item Anna doesn't eat,
	and b, the total amount of money that Brian charged Anna for her portion of the bill. 
	If the bill is fairly split, print Bon Appetit. Otherwise, print the integer amount of money that Brian must refund to Anna.

*/


#include <bits/stdc++.h>

using namespace std;

string bonAppleTeeth(vector<int> array, int billForAnna, int index) {
    // Helper Variables 
    int sumAll = 0;
    int sumAnna = 0;
    int removePrice = array[index];
    
    // Sum of all item prices
    for(int i = 0; i < array.size(); i++){
        sumAll += array[i];
    }
    
    // Find sum of bill for Anna
    int difference = abs(billForAnna - ((sumAll - removePrice)/2));

    // Check if it matches bill for Anna
    if (difference == 0) {
        return "Bon Appetit";
    }
    else {
        return to_string(difference);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    // bill is the array with each price of item
    // k is the index of the item Anna is allergic to 
    // n is the number of items
    // b is the bill for Anna
    
    // first line is n k
    // second line is inputs for bill
    // third line is total bill amount charged to Anna
    
    int n, k, b;
    
    // Get 1st line
    cin >> n;
    cin.ignore(256, ' ');
    cin >> k;
    // Ignore rest until next line is met
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Get 2nd line
    string bills;
    vector<int> bill;
    string input_line;
    getline(cin, input_line);
    istringstream iss(input_line);
    while(iss >> bills) {
        bill.push_back(stoi(bills));
    }

    
    // Get 3rd line
    cin >> b;
    
    string result = bonAppleTeeth(bill, b, k);
    cout << result;
    
    
    return 0;
}


