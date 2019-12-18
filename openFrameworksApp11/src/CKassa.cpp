#include "CKassa.h"
#include <iostream>

CKassa::CKassa()
{
	this->m_Rechnung = 0.0;
}

CKassa::CKassa(double p_Rechnung)
{
	if (p_Rechnung != 0)
		this->m_Rechnung = p_Rechnung;
}

CKassa::~CKassa()
{
	std::cout << "Destruktor Kassa" << std::endl;
}

//Ckasse(CKassa& orig) {
//
//}

void CKassa::setRechnung(double p_Rechnung)
{
	if (p_Rechnung > 0)
		this->m_Rechnung = p_Rechnung;
}

void CKassa::setPreisMs(double p_PreisMS)
{
	if (p_PreisMS > 0)
		this->m_PreisMS = p_PreisMS;
}



void CKassa::display()
{
	std::cout << "Kassandra" << std::endl;	
	std::cout << "Preis incl MWST: " << this->m_PreisMS <<std::endl;
	std::cout << "SUMME: " << this->m_Rechnung <<std::endl;
}

void CKassa::setBill(CProduct* prod)
{
	m_Bill.push_back(prod);               //Member Vektor von Pointer m_Bill befüllen
}

void CKassa::del_Bill()
{
	//m_Bill.erase(m_Bill.begin(), m_Bill.end());
	int s = m_Bill.size();
	for (int i = 0; i < s; i++) {
		printf("KILL BILL %p --", m_Bill[i]);
		delete m_Bill[i];
	}
	//m_Bill.clear();

}

void CKassa::display_Bill()
{
	system("cls");
	
	puts("");
	std::cout << "***Gesamtrechnung***" << std::endl;
	for (auto p : m_Bill) {												  // alle Objekte (kopien der Original einkäufe im Array in Scanner - hier Pointerarray) Infos per getter anzeigen. 
		//std::cout << "Kassandra" << std::endl;	
		std::cout << p->getBeschreibung()<<"....."<<p->getPreis() <<std::endl;
		//std::cout << "Preis incl.MWST..." <<p->getPreis();
		//p->display();												 // optional volles Display aufrufen (Basisklasse display + Derived funktion Display)
		//printf("%p", *p);
	}
	std::cout << "___________________" << m_Rechnung << std::endl;
	
	std::cout << "Gesamt:..........." << m_Rechnung << std::endl;
	
}

double CKassa::Berechne(double p_Preis, std::string p_Kategorie)
{
	int tmp_Kategorie = std::atoi(p_Kategorie.c_str());													                               
	if (tmp_Kategorie == 1) {
		   setPreisMs(p_Preis / 100 * 105);									// ´zusätzlicher Member PreisMS wird verwendet um memper preis von Kopierten objekten upzudaten -> in Scanner::ScanProduct() ->  el->setPreis(kasse.getPreisMS());
	       setRechnung(this->m_Rechnung + m_PreisMS);
		  
	}
	if (tmp_Kategorie == 2) {
		setPreisMs(p_Preis / 100 * 110);
		this->setRechnung(this->m_Rechnung + m_PreisMS);
	}
	if (tmp_Kategorie == 3) {
		setPreisMs(p_Preis / 100 * 125);
		this->setRechnung(this->m_Rechnung+m_PreisMS);
	}
	
	display();                                                           // Ckassa::display() aufrufen um Zwischen/Gesamt SUMME anzuzeigen.
	 ///  COPY IT TO m_Bill                                              // in Scanner:: SCanProduct();

	return 0;
	
}

