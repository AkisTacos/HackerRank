// Aki Saito
// HackerRank - Medium
// Greedy Florist
// March 30, 2019
// Language: C++
// 
/* Description:
	A group of friends want to buy a bouquet of flowers.
	The florist wants to maximize his number of new customers and the money he makes.
	To do this, he decides he'll multiply the price of each flower by the number
	of that customer's previously purchased flowers plus 1. The first flower will be
	the original price, (0 + 1) x original price, the next will be (1 + 1) x original
	price and so on.

	Given the size of the group of friends, the number of flowers they want to 
	purchase and the original prices of the flowers, determine the minimum cost to 
	purchase all of the flowers.

	For example, if there are k = 3 friends that want to buy n = 4 flowers that cost
	c = [1, 2, 3, 4] each will buy one of the flowers priced [2, 3, 4] at the
	original price. Having each purchased x = 1 flower, the first flower in the list, 
	c[0], will now cost (current purchase + previous purchase) x c[0] = (1 + 1) x 1 = 2.
	The total cost will be 2 + 3 + 4 + 2 = 11.
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int numFlower;
	cin >> numFlower;
	int numPeople;
	cin >> numPeople;

	// Grab the prices for flowers
	int i;
	int priceArray[numFlower];
	for(i = 0; i < numFlower; i++){
		cin >> priceArray[i];
	}

	// Reverse in descending order
	reverse(priceArray);

	return 0;
}

int formula(int numberOfPrevious, int cost){
	return = (1 + numberOfPrevious) * cost;
}