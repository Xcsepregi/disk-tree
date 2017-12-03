#include "headers.h"
#include "cmd_Handlers.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;

bool cmd::Quit(tree::Node *, std::ostream & out)
{
	out << "Dakujeme za pouzitie, dovidenia!" << std::endl;
	return false;
}
