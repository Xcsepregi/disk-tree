#include "headers.h"
#include "cmd_Handlers.h"
#include "Help.h"
#include <iostream>

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;
using namespace help;

bool cmd::Help(tree::Node *, std::ostream & out)
{
	bool napoveda = true;
	std::string line;

	out << args << std::endl;

	while(napoveda)
	{
		out << "Cakam na prikaz." << std::endl;
		std::getline(std::cin, line);

		if (line == "list") out << list;
		else if (line == "size") out << size;
		else if (line == "tree_struct") out << tree_struct;
		else if (line == "dump") out << dump;
		else if (line == "rm") out << rm;
		else if (line == "mkdir") out << mkdir;
		else if (line == "link") out << link;
		else if (line == "touch") out << touch;
		else if (line == "help") out << help_cmd;
		else if (line == "quit") out << quit;
		else if (line == "work") break;
	}

	return true;
}
 