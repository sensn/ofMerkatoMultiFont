#pragma once
#include "CProduct.h"
#include <string>

class CGetraenk : public CProduct {
private:
	double m_Alkoholgehalt = 0;
	std::string m_Name = "";
	std::string m_Kategorie = "3";
public:
	CGetraenk();
	CGetraenk(const char* p_Beschreibung, const char* p_Datum, double p_Preis, double p_Alkoholgehalt, std::string p_Name, std::string p_Kategorie);
	~CGetraenk();

	//GETTER
	double getAlkoholgehalt() { return this->m_Alkoholgehalt; }
	std::string getName() { return this->m_Name; }
	std::string getKategorie() { return this->m_Kategorie; }

	//SETTER
	void setAlkoholgehalt(double p_Alkoholgehalt);
	void setName(std::string p_Name);
	void setKategorie(std::string p_Kategorie);

	void display();

	CGetraenk(CGetraenk& original);
	CGetraenk& operator=(CGetraenk& original);
};
