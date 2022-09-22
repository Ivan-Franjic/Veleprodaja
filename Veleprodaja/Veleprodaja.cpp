// Veleprodaja.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <string>
#include "PIN_Gradnja.h"

int main()
{

	PIN_Gradnja *poslovnica = new PIN_Gradnja();
	/*poslovnica->StanjeSkladistaFilter();
	cout << endl;*/
	cout << "ispis tri najcesca:" << endl;
	poslovnica->PrikaziNajcesce();
	cout << endl;
	/*cout << endl;
	poslovnica->PrikaziRacune();*/

	poslovnica->~PIN_Gradnja();
}
