#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

class CProduct
{
	private:
		 char* m_Beschreibung = nullptr;
		 char* m_Datum = nullptr;
		double m_Preis = 0;
	public:
		CProduct();
		CProduct(const char* p_Beschreibung, const char* p_Datum, double p_Preis);
		virtual ~CProduct();

		CProduct(const CProduct& orig);
		CProduct& operator=(CProduct& original);
		//getter
		char* getBeschreibung() { return this->m_Beschreibung; }
		char* getDatum() { return this->m_Datum; }
		double getPreis() { return this->m_Preis; }

		//setter
		void setBeschreibung(const char* p_Beschreibung);
		void setDatum(const char* p_Datum);
		void setPreis(double p_Preis);

		virtual void display();
	};


