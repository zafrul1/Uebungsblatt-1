#pragma once
#define DB_LIMIT 10
#include "kennzeichen.h"
#include <string>

namespace db
{
	struct datenbank
	{
		std::string name;
		kfz::kennzeichen* schilder[DB_LIMIT];
		int eintraege = 0;
	};
	typedef struct datenbank datenbank;

	bool einfuegen(datenbank* db, kfz::kennzeichen* schild) {
	
		
		bool number = true;

		if (db->eintraege == 0) {

			for (int i = 0; i < DB_LIMIT; i++) {

				db->schilder[i] = 0;
			}

		}

		for (int i = 0; i < DB_LIMIT; i++) {

			if (db->schilder[i] == NULL) {

				db->schilder[i] = schild;
				db->eintraege += 1;
				number;
				break;

			}
			else {
				number = false;
			}

		}

		return number;

		
	}


	std::string ausgabe(const datenbank& db) {


		std::string datenbank = db.name + "\n" + "------------------------------\n";
		std::string plate[DB_LIMIT];

		for (int i = 0; i < DB_LIMIT; i++) {

			if (db.schilder[i] != NULL) {

				plate[i] = kfz::ausgabe(*(db.schilder[i])) + "\n";
				datenbank = datenbank + plate[i];

			}

			else {
				break; 
			}

			

		} 

		return datenbank; 


	
		
	}
}
