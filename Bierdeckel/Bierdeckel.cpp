/*
 * Bierdeckel.cpp
 *
 *  Created on: 07.11.2012
 *      Author: jpaehr
 */

#include <iostream>

using namespace std;

int deckelEbene(int ebene);
int summeEbenen( int ebene);
long long getNumberOfCards(long long levels);
/*Exercise
 * How many cards do i need to build chart house to defined level?
*/

//short solution ->faster, can takes more digits
long long getNumberOfCards(long long levels){
    //cards of one level = 2*level + level-1
    //with Gauss...
    return -levels+3*(levels*levels+levels)/2;
}
//long solution
int deckelEbene(int ebene){
    int startwert = 2;

    for(int i = 1; i < ebene;i++){
        startwert += 3;
    }
    return startwert;
}
int summeEbenen(int ebene){
    int startwert = 0;

    for(int i = 1; i <= ebene; i++){
        startwert+= deckelEbene(i);
    }
    return startwert;
}

int main(){
    cout << summeEbenen(3) << endl;
    cout << getNumberOfCards(3) << endl;
	return 0;
}


