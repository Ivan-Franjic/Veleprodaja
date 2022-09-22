#include "pch.h"
#include "Artikl.h"


Artikl::Artikl(string sifra, Kategorija *kategorija, string naziv, string jmj, float jedCijena)
{
	this->sifra = sifra;
	this->kategorija = kategorija;
	this->naziv = naziv;
	this->jedCijena = jedCijena;
	this->jmj = jmj;

}

Artikl::Artikl()
{
}


Artikl::~Artikl()
{
}

string Artikl::getSifra()
{
	return this->sifra;
}

Kategorija * Artikl::getKategorija()
{
	return this->kategorija;	
}

string Artikl::getNaziv()
{
	return this->naziv;
}

string Artikl::getJmj()
{
	return this->jmj;
}

float Artikl::getJedCijena()
{
	return this->jedCijena;
}

string Artikl::ispisiArtikl()
{
	
	return "   " + sifra + "\t\t" + kategorija->getNaziv() + "\t\t" + naziv + "\t" + jmj + "\t\t" + to_string(jedCijena);
}
