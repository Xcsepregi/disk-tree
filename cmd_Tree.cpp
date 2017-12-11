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
	return[bFollow = options.bFollow, path = options.path](Node * node, std::ostream & out)
	{
		if(path == "")node->List(bFollow , true, "", out);
		else
		{
			auto root = ParsePath(path, node);
			if (std::holds_alternative<Node*>(root))
				std::get<Node*>(root)->List(bFollow, true, "", out);
		}
		return true;
	};
}
