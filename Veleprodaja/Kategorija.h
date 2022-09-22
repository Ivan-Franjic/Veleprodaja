#pragma once
#include <string>
using namespace std;

class Kategorija
{
private:
	string sifra;
	string naziv;
public:
	Kategorija(string sifra, string naziv);
	Kategorija();
	~Kategorija();


	string getNaziv();
	string getSifra();

};

