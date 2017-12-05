#pragma once
#include <string>

namespace help {
	std::string list{ "Prikaz list[-follow][-recursive][path]\n------------------\nVypise zadefinovany adresar.\nAdresar je definovany cestou[path], defaultne je nastaveny hlavny adresar.\nArgument[-follow] umoznuje sledovanie linkov.\nArgument[-recursive] umoznuje rekurzivne vnaranie sa do adresarov.\n\n" };
	std::string size{ "Prikaz size [-follow] [-recursive] [path]\n------------------\nVypise velkost subora/adresara.\nArgument [path] obsahajue cestu ku objektu, ktoreho velkost sa vypise.\nArgument [-follow] zahrnie odkazovane subory a adresare.\nArgument [-recursive] rekurzivne prida vnorene adresare.\n\n" };
	std::string tree_struct{ "Prikaz tree [path]\n------------------\nZobrazi stromovu strukturu pre zadanu adresu.\nCesta [path] je cesta, pre ktoru sa struktura zobrazi.\nDefaultne zobrazi strukturu pre hlavny adresar!\n\n" };
	std::string dump{ "Prikaz dump [path]\n------------------\nVypise hierarchiu danej cesty vo formate Json.\nCesta [path], ktorej hierarchia sa vypise.\n\n" };
	std::string rm{ "Prikaz rm <path>\n------------------\nUmozni zmazanie suboru/adresara/linku.\nAdresa <path> obsahuje adresu suboru/adresara/linku na zmazanie.\nDefaultne vypise adresu hlavneho adreasara!\n\n"};
	std::string mkdir{ "Prikaz mkdir <path>\n------------------\nUmozni vytvorenie noveho adresara.\nArgument <path> obsahuje adresu, na ktorej sa novy adresar vytvori.\n\n"};
	std::string link{ "Prikaz link <name> <path>\n------------------\nUmozni vytvorenie odkazu na adresar alebo subor.\nArgument <name> je nazov linku, je to povinny argument\nAdresa <path> je adresa, na ktoru bude link ukazovat.\n\n"};
	std::string touch{ "Prikaz touch <path> size\n------------------\nUmozni vytvorenie noveho suboru na adrese <path>.\nUzivatel zadava velkost suboru v argumente size, defaultna velkost je 0 B.\n\n"};
	std::string quit{ "Prikaz quit\n------------------\nUkonci program Json Disk Tree Reader!\n\n"};
}