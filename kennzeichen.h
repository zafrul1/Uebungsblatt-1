#pragma once
#include <string>
#include <iostream>
#define MAX 10 

namespace kfz
{
	struct kennzeichen
	{
		std::string ort;
		std::string buchstaben;
		short zahl{};
	};
	typedef struct kennzeichen kennzeichen;

	bool alphabet(char array[MAX]) { 

		char arrNumber[] = { '0','1','2','3','4','5','6','7','8','9' };
		int length = strlen(array);
		bool number = true; 


		for (int i = 0; i < length; i++) {
			for (int j = 0; j < 10; j++) {

				if (array[i] == arrNumber[j]) {

					number = false;
					break;

				}	
			
			}
			break;
		}

		return number; 



	}

	bool string(std::string str) {

		std:: string arrNumber = { '0','1','2','3','4','5','6','7','8','9' }; 
		int length = str.length();
		bool number = true;


		for (int i = 0; i < length; i++) {
			for (int j = 0; j < 10; j++) {

				if (str[i] == arrNumber[j]) {

					number = false;
					break;

				}

			}
			break;
		}

		return number;
	}

	std::string einlesenOrt() {


		char ortsAbkuerzung[MAX];
		bool number;
		int max = 3;

		std::cout << "Bitte geben Sie Ihr Ortsabkuerzung ein : ";

		while (std::cin >> ortsAbkuerzung) {

			number = alphabet(ortsAbkuerzung);
			int length = strlen(ortsAbkuerzung);
			
				if (length > max || number == false) {
					std::cin.clear();
					std::cin.ignore(123, '\n');
					std::cout << "Es werden nur zwischen ein und drei Zeichen akzeptiert : ";

				}


				else if (length <= max) {
					break;
				}

		}

		return ortsAbkuerzung; 
	
	}

	std::string einlesenBuchstaben() {
	
		std::string buchstaben; 
		bool number; 
		unsigned int max = 2; 

		std::cout << "Bitte geben Sie Buchstaben ein : ";
		
		
		while (std::cin >> buchstaben) {

			number = string(buchstaben);

			if (buchstaben.length() > max || number == false) { 

				std::cin.clear();
				std::cin.ignore(123, '\n');
				std::cout << "Es werden nur zwischen ein oder zwei Zeichen akzeptiert : "; 
			}


			else if (buchstaben.length() <= max) { 
				break;
			}

		}
		
		return buchstaben; 

	}

	short einlesenZahl() {

		short zahl;

		std::cout << "Bitte geben Sie eine Zahl zwischen 1 und 9999 ein : ";
		
		while ( std::cin >> zahl || !(std::cin>>zahl) ) {

			if (zahl < 1 || zahl > 9999 ) {

				std::cout << "Bitte geben Sie eine Zahl zwischen 1 und 9999 ein : ";
				std::cin.clear(); 
				std::cin.ignore( 123,'\n');
				
				
			}

			else {
				break;
			}

		}

		return zahl;
	}

	kennzeichen* einlesen() {
	
		kennzeichen* pKennzeichen = new kennzeichen;

		if (pKennzeichen != 0) {

			pKennzeichen->ort = einlesenOrt(); 
			pKennzeichen->buchstaben = einlesenBuchstaben();   
			pKennzeichen->zahl = einlesenZahl();

			
			
		}

		return pKennzeichen;
	}

	bool istSchnapszahl(const kennzeichen* pKennzeichen) {

		bool number; 

		for (int i = 1; i <= 9; i++) {


			if (pKennzeichen->zahl == 11*i || pKennzeichen->zahl == (11 * i) + (100 * i) || pKennzeichen->zahl == (11 * i) + (100 * i) + (1000 * i)) {

				number = true;
				break;
			}

			else if (pKennzeichen->zahl == 123) {

				number = true;
				break;
			}

			else {

				number = false;
				break; 
			}

			


		}

		return number; 

	
	}

	bool istZehner(const kennzeichen* pKennzeichen) {

		bool number; 

		for (int i = 1; i <= 9; i++) {

			if (pKennzeichen->zahl == 10 * i) {
				number = true;
				break;
			}

			else {
				number = false; 
				break; 

			}
		}

		return number; 
	
	}

	bool istHunderter(const kennzeichen& rKennzeichen) {

		bool number;

		for (int i = 1; i <= 9; i++) {

			if (rKennzeichen.zahl == 100 * i) {
				number = true;
				break;
			}

			else {
				number = false;
				break;

			}
		}

		return number;  

	}

	bool istTausender(const kennzeichen* pKennzeichen) {

		bool number;

		for (int i = 1; i <= 9; i++) {

			if (pKennzeichen->zahl == 1000 * i) {
				number = true;
				break;
			}

			else {
				number = false;
				break;

			}
		}

		return number; 

		
	}

	void schildTest(kennzeichen* schild) {


		if (istSchnapszahl(schild) == true) {

			std::cout << " ist Schnappzahl!" << std::endl;
		};

		if (istZehner(schild) == true) {

			std::cout << " ist Zehner!" << std::endl;
		};

		if (istHunderter(*schild) == true) {

			std::cout << " ist Hunderter!" << std::endl;
		};


		if (istTausender(schild) == true) {

			std::cout << " ist Tausender!" << std::endl;
		};


	}

	std::string ausgabe(const kennzeichen& rKennzeichen) {
	
		std::string ort = rKennzeichen.ort;
		std::string buchstaben = rKennzeichen.buchstaben;  
		std::string ausgabe = ort + '-' + buchstaben + '-' + std::to_string(rKennzeichen.zahl);

		return ausgabe; 


		
	}

}