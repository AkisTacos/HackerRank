// Aki Saito
// HackerRank - Easy
// Taum and B'day
// August 23, 2018
// Language: C++
// 
/* Description:

	Taum is planning to celebrate the birthday of his friend, Diksha. 
	There are two types of gifts that Diksha wants from Taum: one is black and the other is white. 
	To make her happy, Taum has to buy  black gifts and  white gifts.
	
	The cost of each black gift is bc units.
	The cost of every white gift is wc units.
	The cost of converting each black gift into white gift or vice versa is z units.
	
	Help Taum by deducing the minimum amount he needs to spend on Diksha's gifts.
	For example, if Taum wants to buy b = 3 black gifts and w = 5 white gifts at a cost of bc = 3, wc = 4
	 and conversion cost z = 1, we see that he can buy a black gift for 3 and convert it to a white gift for 1, making the total cost of each white gift 4. 
	That matches the cost of a white gift, so he can do that or just buy black gifts and white gifts. Either way, the overall cost is 3 * 3 + 5 * 4 = 29.

*/

#include <bits/stdc++.h>

using namespace std;

long long int calculate(long long int b, long long int w, long long int bc, long long int wc, long long int z){
    return ( b * min(bc, wc + z) + (w * min(wc, bc + z)) );
}


int main()
{
    long long int t, b, w, bc, wc, z, result;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> b >> w;
        cin >> bc >> wc >> z;
        result = calculate(b, w, bc, wc, z);
        cout << result << endl;
    }
    return 0;
    
}