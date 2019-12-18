#pragma once
#include "_header.h"
#include <vector>

class CKassa {
private:
	double m_Rechnung=0.0;
	double m_PreisMS = 0.0;
	std::vector <CProduct*> m_Bill;
public:
	CKassa();
	CKassa(double p_Rechnung);
	~CKassa();
	void display();
    void display_Bill();
	//GETTER
	double getRechnung() { return this->m_Rechnung; }
	double getPreisMS() { return this->m_PreisMS; }

	//SETTER
	void setRechnung(double p_Rechnung);
	void setPreisMs(double p_PreisMS);
	void setBill(CProduct* prod);

	void del_Bill();

	double Berechne(double p_Preis, std::string p_Kategorie);

	//CScanner(const CScanner& original);
	//CScanner& operator=(const CScanner& original);

};
