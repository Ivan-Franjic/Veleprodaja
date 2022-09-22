#include "pch.h"
#include "ArtiklSkladiste.h"



ArtiklSkladiste::ArtiklSkladiste(Artikl a, string sifra, int kolicina) : Artikl(a.getSifra(), a.getKategorija(), a.getNaziv(), a.getJmj(), a.getJedCijena())
{
	this->sifra = sifra;
	this->kolicina = kolicina;

}

ArtiklSkladiste::~ArtiklSkladiste()
{
}

int ArtiklSkladiste::getKolicina()
{
	return kolicina;
}
