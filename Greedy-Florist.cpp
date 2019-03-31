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

int formula(int numberOfPrevious, int cost){
    return (1 + numberOfPrevious) * cost;
}

int main(){
    int numFlower;
    cin >> numFlower;
    int numPeople;
    cin >> numPeople;

    // Grab the prices for flowers
    int i, temp;
    vector<int> prices;

    for(i = 0; i < numFlower; i++){
        cin >> temp;
        prices.push_back(temp);
    }
    
    // Reverse in descending order
    // if not sorted sort
    sort(prices.begin(), prices.end());
    reverse(prices.begin(), prices.end());
    
  
    // Calculate result
    int result = 0;
    int numOfPrev = 0;
    // Calculate the most expensive ones as many as we can first
    // to prevent excessive payment then the next ones and so on...
    // make sure to keep the number of flowers each person has is near or balanced
    for(i = 0; i < numFlower; i++){
        if(i % numPeople == 0 && i != 0)
            numOfPrev++;
        result += formula(numOfPrev, prices.at(i));
    }
    cout << result;

    return 0;
}

