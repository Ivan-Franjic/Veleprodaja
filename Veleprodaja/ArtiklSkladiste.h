#pragma once
#include "Artikl.h"
#include <string>

class ArtiklSkladiste : public Artikl
{
private:
	string sifra;
	int kolicina;
public:
	ArtiklSkladiste(Artikl a, string sifra, int kolicina);
	~ArtiklSkladiste();
	int getKolicina();
};

