#pragma once
#include "Kategorija.h"
#include <string>
using namespace std;

class Artikl
{
private:
	string sifra;
	Kategorija *kategorija;
	string naziv;
	string jmj;
	float jedCijena;


public:
	Artikl(string sifra, Kategorija *kategorija, string naziv, string jmj, float jedCijena);
	Artikl();
	~Artikl();

	string getSifra();
	Kategorija* getKategorija();
	string getNaziv();
	string getJmj();
	float getJedCijena();
	string ispisiArtikl();
};

