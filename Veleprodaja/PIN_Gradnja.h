#pragma once
#include "Kategorija.h"
#include "Artikl.h"
#include "ArtiklSkladiste.h"
#include "Faktura.h"
#include "Stavka.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include "tinyxml2.h"
#include <string>
#include <algorithm>
using namespace std;
using namespace tinyxml2;

class PIN_Gradnja
{
private:
	vector<Kategorija> vKategorije;
	vector<Artikl> vArtikli;
	vector<ArtiklSkladiste> vSkladiste;
	vector<Faktura> vFakture;

	static bool sortirajVektor(const pair<Artikl, int> &a,
		const pair<Artikl, int> &b);
	


public:
	
	bool ucitajXML();
	PIN_Gradnja();
	~PIN_Gradnja();


	void StanjeSkladistaFilter();
	void PrikaziNajcesce();
	void PrikaziRacune();
	

};

