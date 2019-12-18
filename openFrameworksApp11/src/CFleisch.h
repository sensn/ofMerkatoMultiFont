#pragma once
#include "CProduct.h"
#include <string>
class CFleisch :
	public CProduct
{
private:
	std::string m_Name = "";
	std::string m_Kategorie = "1";
public:
	CFleisch();
	CFleisch(const char* p_Beschreibung, const char* p_Datum, double p_Preis, std::string t_name, std::string t_kategorie);
	~CFleisch();

	CFleisch(const CFleisch& orig);
	CFleisch& operator=(CFleisch& orig);

	std::string getName() { return this->m_Name; }
	std::string getKategorie() { return this->m_Kategorie; }

	void setName(std::string t_name);
	void setKategorie(std::string t_kategorie);

	void display() override;
};



