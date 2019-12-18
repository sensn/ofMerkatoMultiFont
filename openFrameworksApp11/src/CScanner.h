#pragma once
#include "CProduct.h"
#include "CKassa.h"
#include <vector>
class CProduct;
class CKassa;
class CScanner
{
private:
	CKassa& kasse;
	std::vector <CProduct*> m_Products;
public:
	//CScanner();
	//CScanner(CKassa& kasse);
	~CScanner();

	CScanner(CKassa& thekassa);
	//void setKassa();
	//Kassa& getKassa() { return this->kasse; }
	
	//CScanner(const CScanner& original);
//	CScanner& operator=(const CScanner& original);

	int ScanProduct(CProduct& product);
	int call_Bill();
	int call_DelBill();
	//void ScanProduct(const int x);
	
};

