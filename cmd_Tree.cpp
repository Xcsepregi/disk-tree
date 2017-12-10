#include "headers.h"
#include "cmd_Handlers.h"
#include "tree_Node.h"
#include "cmd_Parse.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;

Handler cmd::Tree(const Options & options)
{
	return[bFollow = options.bFollow, bRecursive = options.bRecursive, path = options.path](Node * node, std::ostream & out)
	{
		node->List(bFollow, true, "", out);

		return true;
	};
}
