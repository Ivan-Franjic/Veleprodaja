#include "pch.h"
#include "Kategorija.h"


Kategorija::Kategorija(string sifra, string naziv)
{
	this->naziv = naziv;
	this->sifra = sifra;
}

Kategorija::Kategorija()
{
}


Kategorija::~Kategorija()
{
}

string Kategorija::getNaziv()
{
	return naziv;
}

string Kategorija::getSifra()
{
	return this->sifra;
}
