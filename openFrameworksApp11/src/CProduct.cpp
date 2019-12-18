#include "CProduct.h"
#include <iostream>

CProduct::CProduct()
{
	this->m_Beschreibung = nullptr;
	this->m_Datum = nullptr;
	this->m_Preis = 0;
}

CProduct::CProduct(const char* p_Beschreibung, const char* p_Datum, double p_Preis)
{

	this->setBeschreibung(p_Beschreibung);
	this->setDatum(p_Datum);
	this->setPreis(p_Preis);
}

CProduct::~CProduct()
{
	if (this->m_Beschreibung) {
		delete[] this->m_Beschreibung;
		this->m_Beschreibung = nullptr;
	}
	if (this->m_Datum) {
		delete[] this->m_Datum;
		this->m_Datum = nullptr;
	}
}

CProduct::CProduct(const CProduct& orig)
{
	if (this != &orig) {
		this-> setBeschreibung( orig.m_Beschreibung);                       //  SETTER WICHTIG!
		this->setDatum(orig.m_Datum);
		this->setPreis(orig.m_Preis);
	}
	}

void CProduct::setBeschreibung(const char* p_Beschreibung)
{
	if (this->m_Beschreibung != nullptr) {											//schauen ob überhaupt leer
		delete[] this->m_Beschreibung;												//wenn nicht leer member löschen
		this->m_Beschreibung = nullptr;											    //und member auf nullptr setzen
	}
	if (p_Beschreibung != nullptr) {											    //überprüfen ob input leer ist
		int len = strlen(p_Beschreibung);											//länge bestimmen vom input
		if (len > 0) {																//wenn input nicht leer ist
			this->m_Beschreibung = new char[len + 1];								//member den speicherplatz freigeben von länge +1 (für \0)
			if (m_Beschreibung != nullptr) {										//erneut abfragen ob member nicht leer ist
				strncpy(this->m_Beschreibung, p_Beschreibung, len + 1);				//eingabe kopieren
			}
		}
	}
}

void CProduct::setDatum(const char* p_Datum)
{
	if (this->m_Datum != nullptr) {											//schauen ob überhaupt leer
		delete[] this->m_Datum;												//wenn nicht leer member löschen
		this->m_Datum = nullptr;										    //und member auf nullptr setzen
	}
	if (p_Datum != nullptr) {											    //überprüfen ob input leer ist
		int len = strlen(p_Datum);											//länge bestimmen vom input
		if (len > 0) {														//wenn input nicht leer ist
			this->m_Datum = new char[len + 1];								//member den speicherplatz freigeben von länge +1 (für \0)
			if (m_Beschreibung != nullptr) {								//erneut abfragen ob member nicht leer ist
				strncpy(this->m_Datum, p_Datum, len + 1);					//eingabe kopieren
			}
		}
	}
}

void CProduct::setPreis(double p_Preis)
{
	if (p_Preis > 0)
		this->m_Preis = p_Preis;
}

void CProduct::display()
{
	if (this->m_Beschreibung != nullptr) {
		std::cout << "Beschreibung...: " << this->m_Beschreibung << std::endl;
	}
	if (this->m_Datum != nullptr) {
		std::cout << "Datum....: " << this->m_Datum << std::endl;
	}
	if (this->m_Preis != 0)
		std::cout << "Preis....: " << this->m_Preis << std::endl;
}

CProduct& CProduct::operator=(CProduct& original)
{
	
	return *this;
}