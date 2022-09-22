#include "pch.h"
#include "Stavka.h"



Stavka::Stavka(Artikl a, string sifraFakture, int kolicina, float ukupnaCijena) : Artikl(a.getSifra(), a.getKategorija(), a.getNaziv(), a.getJmj(), a.getJedCijena())
{
	this->sifraFakture = sifraFakture;
	this->kolicina = kolicina;
	this->ukupnaCijena = ukupnaCijena;
}

string Stavka::ispisiStavku()
{
	return "  " + this->getSifra() + "\t\t" + this->getNaziv() + "\t\t" + this->getJmj() + "\t" + to_string(kolicina) + "\t" + to_string(this->getJedCijena()) + "\t" + to_string(ukupnaCijena);

}

Stavka::~Stavka()
{
}
