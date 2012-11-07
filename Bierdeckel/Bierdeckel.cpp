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

int main(){
	cout << summeEbenen(3);
	return 0;
}
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


