#include "CGetränk.h"
#include <iostream>

CGetraenk::CGetraenk()
{
	this->m_Alkoholgehalt = 0;
	this->m_Name = "";
	this->m_Kategorie = "3";
}

CGetraenk::CGetraenk(const char* p_Beschreibung, const  char* p_Datum, double p_Preis, double p_Alkoholgehalt, std::string p_Name, std::string p_Kategorie) : CProduct(p_Beschreibung, p_Datum, p_Preis), m_Kategorie("3")
{
	this->setAlkoholgehalt(p_Alkoholgehalt);
	this->setName(p_Name);
	this->setKategorie(p_Kategorie);
}

CGetraenk::~CGetraenk()
{
	std::cout << "dest. Getraenke" << std::endl;
}

void CGetraenk::setAlkoholgehalt(double p_Alkoholgehalt)
{
	if (p_Alkoholgehalt >= 0)
		this->m_Alkoholgehalt = p_Alkoholgehalt;
}

void CGetraenk::setName(std::string p_Name)
{
	if (p_Name != "")
		this->m_Name = p_Name;
}

void CGetraenk::setKategorie(std::string p_Kategorie)
{
	if (p_Kategorie != "")
		this->m_Kategorie = p_Kategorie;
}

void CGetraenk::display()
{
	std::cout << "***---Getraenk-Display---***" << std::endl;
	CProduct::display();
	if (this->m_Alkoholgehalt >= 0) {
		std::cout << "Alkoholgehalt:...." << this->m_Alkoholgehalt << std::endl;
	}
	if (this->m_Name != "") {
		std::cout << "Name:...." << this->m_Name << std::endl;
	}
	if (this->m_Kategorie != "") {
		std::cout << "Kategorie:...." << this->m_Kategorie << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
}

CGetraenk::CGetraenk(CGetraenk& original) : CProduct(original)
{
	if (this != &original)
		this->setAlkoholgehalt(original.m_Alkoholgehalt);
	this->setName(original.m_Name);
	this->setKategorie(original.m_Kategorie);
	printf("COPYKONSTRUKTOR GETRAENK!!!");

}

CGetraenk& CGetraenk::operator=(CGetraenk& original)
{
	CProduct::operator=(original);
	this->setAlkoholgehalt(original.m_Alkoholgehalt);
	this->setName(original.m_Name);
	this->setKategorie(original.m_Kategorie);
	return *this;
}
