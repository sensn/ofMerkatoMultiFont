// CPP2_Supermarkt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include"_Header.h"
#include <vector>
#include <iostream>
#include <conio.h>
//
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <mutex>
//

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void menu(char*);

int change_font();
int barcode39();

std::vector <CProduct*> sortiment_create();
void sortiment_display(std::vector <CProduct*> sortiment);
//void einkauf_display(std::vector <CProduct*> einkauf);
//int sortiment_cast(CProduct& product);                     // Um zwei gleiche Produkte in den Einkaufswagen legen zu können
int sortiment_cast(CProduct& product, std::vector<CProduct*>& einkauf);
std::map<char, std::string> codemap;
std::string str;
//int main1(std::string * mystring)
//extern std::mutex vec_mutex;
std::mutex vec_mutex;
int main1(std::vector<std::string> *mystring_vec)
{
	// barcode39();
     //change_font();
     //std::cout << "Im Void is koid!\n";
	//*mystring = "Y";
	//mystring_vec->push_back("H");
	//std::cout << mystring_vec;			// Welcome message	
	std::cout << "Welcome to Supermerkato!\n";			// Welcome message	
    std::cout << "\n\n\n"<< std::endl;                 // 3 newlines plus a new line!
	//uint8_t n = 10;
	std::vector <CProduct*> sortiment;                 // Vector für Sortiment aus dem man auswählen kann
	std::vector <CProduct*> einkauf;                   // Vectmilor für die in den Einkaufswagen gelgeten Produkte

    CKassa thekassa;                                  // Erstellung eines Objektes der Classe Ckassa
    CScanner scanner(thekassa);                       // Erstellung eines Objektes der Classe Scanner - aufruf des überladenen Construktor zur initialisieren des Members (ref)&Ckassa kasse  - (Achtung Vorwärtsdeklaration und initialzer list notwendig!)    												
	system("pause");
	system("cls");

	sortiment = sortiment_create();                 //sortiment befüllen für Produktauswahl               
	//*** MENU ***
	int numproduct = 0;
	int s = 0;
	char button = 0;
	int exitButton = 0;

	char ch;
	int number;						// für Auswahl Produkte menu(A)
	int num;						// für Anzeige bei ein Scannen menu(C)
	bool loop = false;              // für abbrauch des Einkaufes Bei Esc
 	
	do {
		switch (button) {
		case 'A':
			//function															//Produkte einkaufen
			
   		while (loop == false)
			{
		//	mystring_vec->push_back("I");
			//*mystring = "YOYO";
			    sortiment_display(sortiment);
				std::cout << "__________________________"<<std::endl;
				std::cout << "Produkt auswaehlen (0-9, ESC) :";                                             
				std::cin >> number; std::cin.clear(); std::cin.ignore(std::cin.rdbuf()->in_avail());
				sortiment_cast(*sortiment[number],einkauf);
				//einkauf.push_back(sortiment[number]);   // in das Einkaufswagerl hineinlegen
				str = einkauf[numproduct]->getBeschreibung();
			    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
				std::cout<<"-"<< str;
				vec_mutex.lock();
				//mystring_vec->push_back(str);
				//mystring_vec->emplace_back(str);
			   auto it=  mystring_vec->insert(mystring_vec->begin(), str);
				vec_mutex.unlock();
				
				numproduct++;
				std::cout << std::endl;
				std::cout << "press enter to continue shopping, escape back to main menu" << std::endl;
				ch = getch();
				if (ch == 27)                                                                             //ESC ?
				loop = true;																			  // loop verlassen					
			}
			loop = false;
			std::cin.clear(); std::cin.ignore(std::cin.rdbuf()->in_avail());
        /*	std::string s(1, ch);
			number = std::atoi(s.c_str());*/
			
			button = 0;
			break;
		case 'B':																//einkaufskorb anzeigen
			//function
			sortiment_display(einkauf);
			system("pause");
			button = 0;
			break;
		case 'C':
			//function													//zur Kassa gehen ( einscannen...)						
			 num = 1;
			for (auto p : einkauf) {
				std::cout << std::endl;
				std::cout << "Scan Product" << std::endl;
				std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
				std::cout << num<<std::endl;
				scanner.ScanProduct(*p);                       // referenz übergeben -> dynamic_cast siehe Methode Scanner::Scanproduct(CProduct& product)
				printf("%p", p);
				system("pause");                              //  Tastendruck für Scanvorgang nächstes Produkt   
				num++;										 //   In Classe Scanner befindet sich ebenfalls der Vektor für die kopierten Objekte (Pointer). 								
			}												//    Dieser Vektor wird ebenfalls in Scanner:: Scanprodukte befüllt mit Pointer auf kopien. Pointer auf diese Objekte werden an  CKassa::setBill(CProduct* prod) übergeben wo sie in den Member Pointer Vekotor der Klassa Ckasse übergen werden   									
			std::cout<<std::endl;
			std::cout << "Fertig mit Scannen."<<std::endl;                 //Scanvorgang Ende
			std::cout<<"BETTER CALL BILL!"<<std::endl;              
 			scanner.call_Bill();                                // Helper funktion um  kasse.display_Bill(); aufzufufen (kasse private!)                                        
			std::cout << std::endl;
	     	system("pause");
		
			
			scanner.call_DelBill();            //ERROR...
			std::cout << "Einkaufswagen ausraeumen [delete]" << std::endl;
			 s = einkauf.size();
			for (int8_t i = 0; i < s; i++) {
				printf("%p", einkauf[i]);
				delete einkauf[i];	
			}
			einkauf.clear();
		//	thekassa.del_Bill();            //
		
			system("pause");
				button = 0;
			break;
		case 'D':
			//function
			button = 0;
			break;
		case 'E':
			//function
			button = 0;
			break;
		case 'F':
			exitButton = 1;
			return 0;
		default:
			button = 0;
			menu(&button);
		}
	} while (exitButton != 1);

//****************
}//main

void menu(char* button) {
	int validInput = 0;
	system("cls");
	do {
		switch (*button) {
		case 'A':
			std::cout << "() - " << std::endl;
			validInput = 1;
			break;
		case 'B':
			std::cout << "() - " << std::endl;
			validInput = 1;
			break;
		case 'C':
			std::cout << "() - " << std::endl;
			validInput = 1;
			break;
		case 'D':
			std::cout << "() - " << std::endl;
			validInput = 1;
			break;
		case 'E':
			std::cout << "() - " << std::endl;
			validInput = 1;
			break;
		case 'F':
			validInput = 1;
			break;
		default:
			std::cout << "Menueauswahl" << std::endl;
			std::cout << "Druecken Sie A,B,C,D oder E" << std::endl;
			std::cout << "(A) - Produkt auswaehlen " << std::endl;
			std::cout << "(B) - Einkaufskorb anzeigen" << std::endl;
			std::cout << "(C) - Zur Kassa gehen" << std::endl;
			std::cout << "(D) - " << std::endl;
			std::cout << "(E) - " << std::endl;
			std::cout << "(F) - Beenden" << std::endl;
		}
		if (validInput == 0) {
			std::cin.get(*button);
			*button = toupper(*button);
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
		}
	} while (validInput != 1);
	system("cls");
}

std::vector <CProduct*> sortiment_create() {
	std::vector <CProduct*> sortiment1 = { new CFleisch("Wursti 1", "1.13.1999", 10, "Wurscht", "1"),
										   new CFleisch("Wursti 2", "2.13.1999", 10, "Wurscht", "1"),
										   new CFleisch("Wursti 2", "3.13.1999", 10, "Wurscht", "1"),
										   new CGemuese("Gemuese 1" , "4.13.1999", 10, "Celarie", "2"),
										   new CGemuese("Gemuese 2", "5.13.1999", 10, "Celarie", "2"),
										   new CGemuese("Gemuese 3", "6.13.1999", 10, "Celarie", "2"),
										   new CObst("Obst 1", "7.13.1999", 10, "Apferl",  "2"),
										   new CObst("Obst 2", "8.13.1999", 10, "Apferl", "2"),
										   new CObst("Obst 3", "9.13.1999", 10, "Apferl", "2"),
										   new CGetraenk("Biro", "10.13.1999", 10,5, "Pivo", "3")	
	};
	return sortiment1;
}

void sortiment_display(std::vector <CProduct*> sortiment) {
	int i = 0;
	for (auto s : sortiment) {
		std::cout << i<< std::endl;
		s->display();
		i++;
	}
}

int change_font() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 20;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	printf("A quick brown fox jumps over the lazy dog\n");

	printf("Setting to Lucida Console: press <Enter> ");
	getchar();
	wcscpy(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	printf("Setting to Consolas: press <Enter> ");
	getchar();
	wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	printf("Press <Enter> to exit");
	getchar();
	return 0;

}

int barcode39() {

	return 0;
}

int sortiment_cast(CProduct& product, std::vector<CProduct*>& einkauf) {

	{
		auto tmp = dynamic_cast<CGemuese*>(&product);                    // dynamic cast -> block in klammeren um auto tmp wiederzuverwenden -> lokal wieder verfügbar nach Block.
		if (tmp != 0) {
			std::cout << "TYP Gemuese" << std::endl;                     // TYP ausgabe
			
			auto el = new CGemuese(*tmp);                               // Kopie erstellen (mittels new...)
			einkauf.push_back(el);
			return 0;
		}
	}
	{
		auto tmp = dynamic_cast<CFleisch*>(&product);
		if (tmp != 0) {
			std::cout << "TYP Fleisch" << std::endl;

			
		
			auto el = new CFleisch(*tmp);
			einkauf.push_back(el);
			return 0;
		}
	}
	{
		auto tmp = dynamic_cast<CObst*>(&product);
		if (tmp != 0) {
			std::cout << "TYP Obst" << std::endl;
			auto el = new CObst(*tmp);
			einkauf.push_back(el);
			
		
			return 0;
		}
	}
	{

		auto tmp = dynamic_cast<CGetraenk*>(&product);
		if (tmp != 0) {
			std::cout << "TYP Getraenk" << std::endl;
			//auto el = new CGetraenk(*tmp);
			einkauf.push_back(new CGetraenk(*tmp));
			
			return 0;
		}

	}

}