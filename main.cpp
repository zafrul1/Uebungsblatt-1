#include <iostream>
#include "kennzeichen.h"
#include "datenbank.h"



void schnapszahlTest() {

	    kfz::kennzeichen plate; 
		plate.ort = kfz::einlesenOrt();
		plate.buchstaben = kfz::einlesenBuchstaben();
		plate.zahl = kfz::einlesenZahl(); 
		

		if (kfz::istSchnapszahl(&plate) == true) {

			std::cout << plate.ort<< "-" << plate.buchstaben<<"-" << plate.zahl << " hat Schnappzahl!" << std::endl;
		}
		else {
			std::cout<< plate.ort<< "-" << plate.buchstaben << "-" << plate.zahl << " hat keine Schnappzahl!" << std::endl;
		}

		std::cout << "\n\n";

} 
void einlesenTest() {

	kfz::kennzeichen* pKennzeichen = kfz::einlesen(); 
	std::cout << kfz::ausgabe(*pKennzeichen);
	kfz::schildTest(pKennzeichen);
	delete pKennzeichen;
	std::cout << "\n\n"; 



}
void datenbankTest() {

	db::datenbank database; 
	kfz::kennzeichen plate1; 
	kfz::kennzeichen plate2;

	std::cout << "Datenbank : ";
	std::cin >> database.name;


	plate1.ort = kfz::einlesenOrt();
	plate1.buchstaben = kfz::einlesenBuchstaben();
	plate1.zahl = kfz::einlesenZahl();

	db::einfuegen(&database , &plate1);
	
	plate2.ort = kfz::einlesenOrt();
	plate2.buchstaben = kfz::einlesenBuchstaben();
	plate2.zahl = kfz::einlesenZahl();

	db::einfuegen(&database, &plate2);
	

	std::cout<< db::ausgabe(database); 

}
int main()
{
	schnapszahlTest();
	einlesenTest();
	datenbankTest();


	return 0;
}