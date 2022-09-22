#include "pch.h"
#include "PIN_Gradnja.h"



bool PIN_Gradnja::sortirajVektor(const pair<Artikl, int>& a, const pair<Artikl, int>& b)
{
	return (a.second > b.second);
}

bool PIN_Gradnja::ucitajXML()
{
	tinyxml2::XMLDocument xml_doc;

	tinyxml2::XMLError eResult = xml_doc.LoadFile("doc.xml");
	if (eResult != tinyxml2::XML_SUCCESS) return false;

	tinyxml2::XMLNode* root = xml_doc.FirstChildElement("data");
	if (root == nullptr) return false;

	tinyxml2::XMLElement* element = root->FirstChildElement("sifrarnici");
	if (element == nullptr) return false;

	tinyxml2::XMLElement* artikli = element->FirstChildElement("artikli");
	if (artikli == nullptr) return false;

	//ucitavanje kategorija
	tinyxml2::XMLElement* kategorije = element->FirstChildElement("kategorije");
	if (kategorije == nullptr) return false;

	//ucitavanje kategorija
	for (XMLElement* elem = kategorije->FirstChildElement("kategorija"); elem != NULL; elem = elem->NextSiblingElement())
	{
		string sifra = elem->Attribute("sifra");
		string naziv = elem->Attribute("naziv");

		Kategorija k(sifra, naziv);
		this->vKategorije.push_back(k);

	}

	//ucitavanje artikala
	for (XMLElement* elem = artikli->FirstChildElement("artikl"); elem != NULL; elem = elem->NextSiblingElement())
	{
		string sifra = elem->Attribute("sifra");
		string kategorija = elem->Attribute("kategorija");
		string naziv = elem->Attribute("naziv");
		string jmj = elem->Attribute("jmj");
		string jed_cijena = elem->Attribute("jed_cijena");

		//nadi kategoriju artikla
		Kategorija *k = new Kategorija();

		for (int i = 0; i < this->vKategorije.size(); i++) {
			if (this->vKategorije[i].getSifra() == "KAT" + kategorija) {
				
				k = &(this->vKategorije.at(i));
				break;
			}
		}

		Artikl a(sifra, k, naziv, jmj, atof(jed_cijena.c_str()));
		this->vArtikli.push_back(a);

	}



	//ucitavanje skladista
	XMLElement* skladiste = root->FirstChildElement("skladiste");
	if (skladiste == nullptr) return false;

	string sifraSkladista = skladiste->Attribute("sifra");

	//ucitavanje skladista tj artiklskladiste
	for (XMLElement* elem = skladiste->FirstChildElement("artikl"); elem != NULL; elem = elem->NextSiblingElement())
	{
		string sifra = elem->Attribute("sifra");
		string kolicina = elem->Attribute("kolicina");

		//nadi artikl prema sifri
		Artikl trazeni;
		for (int i = 0; i < this->vArtikli.size(); i++)
		{
			if (this->vArtikli[i].getSifra() == sifra) {
				trazeni = this->vArtikli[i];
				break;
			}
		}

		ArtiklSkladiste arSkl(trazeni, sifra, stoi(kolicina));
		this->vSkladiste.push_back(arSkl);

	}


	//ucitavanje faktura
	XMLElement* fakture = root->FirstChildElement("fakture");

	for (XMLElement* faktura = fakture->FirstChildElement("faktura"); faktura != NULL; faktura = faktura->NextSiblingElement())
	{

		if (faktura == nullptr) return false;

		string sifraFakture = faktura->Attribute("sifra");
		string datumFakture = faktura->Attribute("datum");

		Faktura f(sifraFakture, datumFakture);

		XMLElement* stavke = faktura->FirstChildElement("stavke");
		if (stavke == nullptr) return false;

	

		vector<Stavka> vStavke;
		//ucitavanje stavki faktura
		for (XMLElement* elem = stavke->FirstChildElement("stavka"); elem != NULL; elem = elem->NextSiblingElement())
		{
			string sifra = elem->Attribute("sifra");
			string kolicina = elem->Attribute("kolicina");
			string ukupnaCijena = elem->Attribute("ukupna_cijena");

			//nadi artikl prema sifri
			Artikl trazeni;
			for (int i = 0; i < this->vArtikli.size(); i++)
			{
				if (this->vArtikli[i].getSifra() == sifra) {
					trazeni = this->vArtikli[i];
					break;
				}
			}

			Stavka stavka(trazeni, sifra, stoi(kolicina), atof(ukupnaCijena.c_str()));
			vStavke.push_back(stavka);

		}
		f.setStavkeFakture(vStavke);
		vStavke.clear();
		this->vFakture.push_back(f);
	}

	return true;
}

PIN_Gradnja::PIN_Gradnja()
{
	//kreirati i popuniti vektore
	bool uspjeh = ucitajXML();
	if (!uspjeh) {
		cout << "Nesto je poslo po zlu. Provjerite ime xml datoteke!" << endl;
	}

}


PIN_Gradnja::~PIN_Gradnja()
{
}

void PIN_Gradnja::StanjeSkladistaFilter()
{
	string pojam;
	cout << "unesite trazeni pojam: ";
	cin >> pojam;
	//pretrazi sifre i nazive artikla
	bool any = false;
	int rbr = 1;
	cout << "rbr   sifra artikla\t naziv kategorije \t naziv artikla \t     jedinica mjere \t jedinicna cijena \t kolicina" << endl;
	for (auto i = this->vSkladiste.begin(); i != this->vSkladiste.end(); i++)
	{
		if (i->getSifra().find(pojam) != string::npos) {
			any = true;
			cout << to_string(rbr) + "."<< std::flush;
			cout << i->ispisiArtikl() << "\t\t" + to_string(i->getKolicina()) << endl;;
			


			//<< endl;
			rbr++;
		}
		if (i->getNaziv().find(pojam) != string::npos) {
			any = true;
			cout << to_string(rbr) + "." << std::flush;
			cout << i->ispisiArtikl()<< "\t\t" + to_string(i->getKolicina()) << endl;
			rbr++;
		}
		
	}
	//ako nije nijedan naden sve ispisi
	if (!any) {
		for (auto i = this->vSkladiste.begin(); i != this->vSkladiste.end(); i++)
		{
			cout << to_string(rbr) + "." << std::flush;
			cout << i->ispisiArtikl() << "\t\t" + to_string(i->getKolicina()) << endl;
			rbr++;
		}
	}


}

void PIN_Gradnja::PrikaziNajcesce()
{
	//broj pojavljivanja na fakturama

	//parovi artikl, broj ponavljanja, pospremimo sve artikle
	vector < pair<Artikl, int> > ponavljanja;
	for (int i =0; i < vArtikli.size(); i++)
	{
		ponavljanja.push_back(make_pair(vArtikli[i],0));
	}

	//po fakturama
	for (auto i = this->vFakture.begin(); i != this->vFakture.end(); i++)
	{
		//po stavkama
		vector<Stavka> stavke = i->getStavkeFakture();
		for (auto j = stavke.begin(); j != stavke.end(); j++)
		{
			//nadi ga u vektoru ponavljanja
			for (int k = 0; k < ponavljanja.size(); k++)
			{
				//zbrajaj ponavljanja
				if (j->getSifra() == ponavljanja[k].first.getSifra()) {
					ponavljanja[k].second++;
				}
			}
		}
	}


	//ispisi po broju ponavljanja
	//prvo sortiramo  -- algorithm
	std::sort(ponavljanja.begin(), ponavljanja.end(), sortirajVektor);
	cout << "rbr   sifra artikla\t naziv kategorije \t naziv artikla \t  jedinica mjere \t jedinicna cijena" << endl;
	int rbr = 1;
	for (auto i = ponavljanja.begin(); i != ponavljanja.end(); i++)
	{
		cout << to_string(rbr) + "." << std::flush;
		cout << i->first.ispisiArtikl() << endl;
		rbr++;
		if (rbr == 4) {
			break;
		}
	}
}



void PIN_Gradnja::PrikaziRacune()
{
	//rbr sifra datum ispis svih
	cout << "rbr   sifra\t datum " << endl;
	int rbr = 1;
	for (auto i = this->vFakture.begin(); i != this->vFakture.end(); i++)
	{
		cout << to_string(rbr) + "." << std::flush;
		cout << i->getSifra() + "\t" + i->getDatum() << endl;
		rbr++;
	}

	//onda upis sifre pa se ispisu stavke
	cout << "upisite sifru fakture za koju hocete vidjeti stavke: ";
	string sifra;
	cin >> sifra;
	cout << "rbr   sifra\t naziv\t\t jedinica mjere   kolicina \t jedinicna cijena  ukupna_cijena " << endl;
	for (auto i = this->vFakture.begin(); i != this->vFakture.end(); i++)
	{
		if (i->getSifra() == sifra) {
			i->ispisiStavkeFakture() ;
			cout << endl;
		}
	}

}




