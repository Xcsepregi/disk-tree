#include "headers.h"
#include <iostream>
#include <fstream>

#include "tree_Disk.h"
#include "cmd_Handler.h"

#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif


namespace
{
	// set db flag to dump memory leaks
	struct SetDbFlag
	{
		SetDbFlag()
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		}
	}__;
}


int main(int argc, char * argv[])
{
	if (argc > 2)
	{
		std::cerr << "Zle vstupne argumenty, program sa skonci!" << std::endl; 
		return -1;
	}

	rapidjson::Document disk;
	if (argc == 2)
	{
		std::fstream f(argv[1], std::ios_base::in);
		if (f.bad())
		{
			std::cerr << "Chyba nacitania suboru, program sa skonci!" << std::endl;
			return -1;
		}

		rapidjson::IStreamWrapper stream(f);

		rapidjson::ParseResult result = disk.ParseStream(stream);
		if (!result)
		{
			std::cerr << "Zlyhanie parsovania suboru Json, chybova hlaska: " << result.Code();
			return -1;
		}
	}
	else
	{
		disk.Parse("[]");
	}

	auto root = tree::ParseDisk(disk);

	if (!root)
	{
		std::cout << "Chybne Json hodnoty, program sa skonci!" << std::endl;
		return -1;
	}

	std::cout << "Vitajte v Json Disk Tree Reader!" << std::endl;

	while (true)
	{
		std::cout << ">";
		std::string line;
		std::getline(std::cin, line);

		auto handler = cmd::GetHandler(line);
		if (!handler)
		{
			std::cerr << "Neplatny prikaz!" << std::endl << "Pre akceptovane prikazy zadajte prikaz help " <<std::endl;
			std::cout << std::endl;
			continue;
		}

		if (!handler(root.get(), std::cout))
			break;

		std::cout << std::endl;
	}
	return 0;
}

