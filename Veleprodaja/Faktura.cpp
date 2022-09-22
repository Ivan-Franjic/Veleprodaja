#include "pch.h"
#include "Faktura.h"



Faktura::Faktura(string sifra, string datum)
{
	this->sifra = sifra;
	this->datum = datum;
}

Faktura::~Faktura()
{
}

string Faktura::getSifra()
{
	return sifra;
}

string Faktura::getDatum()
{
	return datum;
}

void Faktura::ispisiStavkeFakture()
{
	int rbr = 1;

	for (auto i = this->stavkeFakture.begin(); i != this->stavkeFakture.end(); i++)
	{
		cout << to_string(rbr) + "." << flush;
		cout << i->ispisiStavku() <<endl;
		rbr++;
	}
}

void Faktura::setStavkeFakture(vector<Stavka> stavkeFakture)
{
	this->stavkeFakture = stavkeFakture;
}

vector<Stavka> Faktura::getStavkeFakture()
{
	return stavkeFakture;
}
