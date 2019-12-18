#include "CObst.h"

#include <iostream>

CObst::CObst() :CProduct()
{
	this->m_Name = "";
	this->m_Kategorie = "2";
}

CObst::CObst(const char* p_Beschreibung, const char* p_Datum, double p_Preis, std::string t_name, std::string t_kategorie) : CProduct(p_Beschreibung, p_Datum, p_Preis), m_Kategorie("2")
{
	this->setName(t_name);
	this->setKategorie(t_kategorie);
}

CObst::~CObst()
{
	std::cout << "DESTRUCT THE GEMUESE" << std::endl;
}

CObst::CObst(CObst& orig) :CProduct(orig)
{
	if (this != &orig) {
		this->setName(orig.m_Name);
		this->setKategorie(orig.m_Kategorie);
	}
}

CObst& CObst::operator=(CObst& orig)
{
	if (this != &orig) {
		CProduct::operator=(orig);
		this->setName(orig.m_Name);
		this->setKategorie(orig.m_Kategorie);
	}
	return *this;
}

void CObst::setName(std::string t_name)
{
	this->m_Name = "";
	this->m_Name = t_name;
}

void CObst::setKategorie(std::string t_kategorie)
{
	this->m_Kategorie = "";
	this->m_Kategorie = t_kategorie;

}

void CObst::display()
{
	std::cout << "***---Obst-Display---***" << std::endl;
	CProduct::display();
	if (this->m_Name != "") {
		std::cout << "Name........:" << this->m_Name << std::endl;
	}
	if (this->m_Kategorie != "") {
		std::cout << "Kategorie...:" << this->m_Kategorie << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
}
#include "CObst.h"
