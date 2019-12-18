#include "CFleisch.h"
#include <iostream>

CFleisch::CFleisch() :CProduct()
{
	this->m_Name="";
	this->m_Kategorie="1";
}

CFleisch::CFleisch(const char* p_Beschreibung, const char* p_Datum, double p_Preis, std::string t_name, std::string t_kategorie) : CProduct(p_Beschreibung, p_Datum, p_Preis), m_Kategorie("1")
{
	this->setName(t_name);
	this->setKategorie(t_kategorie);
}

CFleisch::~CFleisch()
{
	std::cout << "DESTRUCT THE GEMUESE" << std::endl;
}

CFleisch::CFleisch(const CFleisch& orig) :CProduct(orig)
{
	if (this != &orig) {
		this->setName(orig.m_Name);
		this->setKategorie(orig.m_Kategorie);
	}
}

CFleisch& CFleisch::operator=(CFleisch& orig)
{
	if (this != &orig) {
		CProduct::operator=(orig);
		this->setName(orig.m_Name);
		this->setKategorie(orig.m_Kategorie);
	}
	return *this;
}

void CFleisch::setName(std::string t_name)
{
	this->m_Name = "";
	this->m_Name = t_name;
}

void CFleisch::setKategorie(std::string t_kategorie)
{
	this->m_Kategorie = "";
	this->m_Kategorie = t_kategorie;

}

void CFleisch::display()
{
	std::cout << "***---Fleisch-Display---***" << std::endl;
	CProduct::display();
	if (this->m_Name != "") {
		std::cout << "Name........:" << this->m_Name << std::endl;
	}
	if (this->m_Kategorie != "") {
		std::cout << "Kategorie...:" << this->m_Kategorie << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
}
