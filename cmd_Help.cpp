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

Handler cmd::Help( const Options & options)
{
	return[arg = options.path](Node * node, std::ostream & out)
	{
		if (arg == "list") out << list;
		else if (arg == "size") out << size;
		else if (arg == "tree") out << tree_struct;
		else if (arg == "dump") out << dump;
		else if (arg == "rm") out << rm;
		else if (arg == "mkdir") out << mkdir;
		else if (arg == "link") out << link;
		else if (arg == "touch") out << touch;
		else if (arg == "quit") out << quit;
		else out << "Neznamy prikaz!" << std::endl;
		return true;
	};
}
