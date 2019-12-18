#include "CScanner.h"
#include <iostream>


//CScanner::CScanner() {
//}

CScanner::~CScanner() {


}
CScanner::CScanner(CKassa& thekassa) :kasse(thekassa)
{
}
int CScanner::ScanProduct(CProduct& product)
{
   static int count = 0;

    {
        auto tmp = dynamic_cast<CGemuese*>(&product);                    // dynamic cast -> block in klammeren um auto tmp wiederzuverwenden -> lokal wieder verfügbar nach Block.
        if (tmp != 0) {
            std::cout << "TYP Gemuese" << std::endl;                     // TYP ausgabe
            product.display();                                          // anzeige mittelsw überladener Funktion anzeigen (dynamic cast hier nicht involviert)    
            kasse.Berechne(tmp->getPreis(), tmp->getKategorie());       //   PreisBrechenen in CKLasse   
            auto el = new CGemuese(*tmp);                               // Kopie erstellen (mittels new...)
            el->setPreis(kasse.getPreisMS());                           // Gerade berechnter Preis incl MWST in Kopiertes Projekt schreiben
            kasse.setBill(el);
            //m_Products.push_back(el);                                   // Objekt in Pointerarray der KLasse Scanner schreiben  
            //kasse.setBill(m_Products[count]);                           // Pointer an kasse übergeben ( wird dort in Pointer array m_Bill geschrieben 
            count++;
            
            return 0;
        }
    }
    {
        auto tmp = dynamic_cast<CFleisch*>(&product);
        if (tmp != 0) {
            std::cout << "TYP Fleisch" << std::endl;

            product.display();
            kasse.Berechne(tmp->getPreis(), tmp->getKategorie());
            auto el = new CFleisch(*tmp);
            el->setPreis(kasse.getPreisMS());
            kasse.setBill(el);
            //m_Products.push_back(el);
            //kasse.setBill(m_Products[count]);
            count++;
            return 0;
        }
    }
    {
        auto tmp = dynamic_cast<CObst*>(&product);
        if (tmp != 0) {
            std::cout << "TYP Obst" << std::endl;
            product.display();
            kasse.Berechne(tmp->getPreis(), tmp->getKategorie());
            auto el = new CObst(*tmp);
            el->setPreis(kasse.getPreisMS());
            kasse.setBill(el);
            //m_Products.push_back(el);
            //kasse.setBill(m_Products[count]);
            count++;
            return 0;
        }
    }
    {

        auto tmp = dynamic_cast<CGetraenk*>(&product);
        if (tmp != 0) {
            std::cout << "TYP Getraenk" << std::endl;
            product.display();
            kasse.Berechne(tmp->getPreis(), tmp->getKategorie());
            m_Products.push_back(new CGetraenk(*tmp));
            //CGetraenk* el = new CGetraenk(*tmp);
            m_Products[count]->setPreis(kasse.getPreisMS());
          //  el1->setPreis(kasse.getPreisMS());
           // kasse.setBill(el);
         //   m_Products.push_back(el1);
            kasse.setBill(m_Products[count]);
            count++;
            return 0;
        }
      
    }
    return 1;
}

int CScanner::call_Bill()
{                                                      // helper funktion 
    kasse.display_Bill();            
    return 0;
}

int CScanner::call_DelBill()
{
    kasse.del_Bill();
    return 0;
}


   


