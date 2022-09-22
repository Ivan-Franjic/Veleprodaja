#pragma once
#include "Artikl.h"

class Stavka : public Artikl
{
private:
	string sifraFakture;
	int kolicina;
	float ukupnaCijena;
public:
	Stavka(Artikl a, string sifraFakture, int kolicina, float ukupnaCijena);
	string ispisiStavku();
	~Stavka();
};

