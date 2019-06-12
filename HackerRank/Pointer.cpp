// Aki Saito
// HackerRank - Easy
// Pointer
// April 1, 2019
// Language: C++
// 
/* Description:
	A pointer in C is a way to share a memory address among different contexts 
	(primarily functions). They are primarily used whenever a function needs to 
	modify the content of a variable, of which it doesn't have ownership. 

	In order to access the memory address of a variable, val , we need to prepend 
	it with & sign. 

		E.g., &val returns the memory address of val. 

	This memory address is assigned to a pointer and can be shared among various 
	functions. 

		E.g. int* p = &val will assign the memory address of val to pointer p. 
		To access the content of the memory to which the pointer points, 
		prepend it with a *. 

	For example, *p will return the value reflected by val and any modification 
	to it will be reflected at the source (val).

	You have to complete the function void update(int *a,int *b), 
	which reads two integers as argument, and sets a with the sum of them, and 
	b with the absolute difference of them.

	- a' = a + b
	- b' = |a - b|

*/
	
#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int calc1, calc2;
    calc1 = (*a) + (*b);
    calc2 = ((*a) - (*b));
    if(calc2 < 0)
        calc2 *= -1;
    (*a) = calc1;
    (*b) = calc2;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

