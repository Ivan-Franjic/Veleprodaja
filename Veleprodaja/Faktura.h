#pragma once
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "Stavka.h"
using namespace std;

class Faktura
{
private:
	string sifra; //moze i int
	string datum;
	vector<Stavka> stavkeFakture;
public:
	Faktura(string sifra, string datum);
	~Faktura();

	string getSifra();
	string getDatum();
	void ispisiStavkeFakture();
	void setStavkeFakture(vector<Stavka> stavkeFakture);
	vector<Stavka> getStavkeFakture();
};

