#pragma once
#include "CProduct.h"
#include <string>
class CGemuese :
	public CProduct
{
private:
	std::string m_Name = "";
	std::string m_Kategorie = "2";
public:
	CGemuese();
	CGemuese(const char* p_Beschreibung, const char* p_Datum, double p_Preis, std::string t_name, std::string t_kategorie);
	~CGemuese();

	CGemuese(CGemuese& orig);
	CGemuese& operator=(CGemuese& orig);

	std::string getName() { return this->m_Name; }
	std::string getKategorie() { return this->m_Kategorie; }

	void setName(std::string t_name);
	void setKategorie(std::string t_kategorie);

	void display() override;
};


