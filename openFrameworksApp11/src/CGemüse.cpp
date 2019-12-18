#include "CGemüse.h"
#include <iostream>

CGemuese::CGemuese():CProduct(), m_Kategorie("2")
{
	//this->setName();
	//this->setKategorie();
}

CGemuese::CGemuese(const char* p_Beschreibung, const char* p_Datum, double p_Preis,std::string t_name, std::string t_kategorie) : CProduct(p_Beschreibung,p_Datum,p_Preis), m_Kategorie("2")
{
	this->setName(t_name);
	this->setKategorie(t_kategorie);
}

CGemuese::~CGemuese()
{
	std::cout << "DESTRUCT THE GEMUESE"<<std::endl ;
}

CGemuese::CGemuese(CGemuese& orig):CProduct(orig)
{
	if (this != &orig) {
		this->setName(orig.m_Name);
		this->setKategorie(orig.m_Kategorie);
	}
}

CGemuese& CGemuese::operator=(CGemuese& orig)
{
	if (this != &orig) {
		CProduct::operator=(orig);
		this->setName(orig.m_Name);
		this->setKategorie(orig.m_Kategorie);
	}
	return *this;
}

void CGemuese::setName(std::string t_name)
{
	this->m_Name = t_name;
}

void CGemuese::setKategorie(std::string t_kategorie)
{
	this->m_Kategorie = t_kategorie;

}

void CGemuese::display()
{
	std::cout << "***---Gemuese-Display---***"<< std::endl;
	CProduct::display();
	std::cout << "Name........:" << this->m_Name << std::endl;
	std::cout << "Kategorie...:" << this->m_Kategorie << std::endl;
	std::cout << "--------------------------" << std::endl;
	
}
