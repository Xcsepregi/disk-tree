#include "headers.h"
#include "tree_Node.h"
#include "tree_File.h"
#include "tree_Folder.h"
#include "tree_Link.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace tree;
typedef std::unique_ptr<Node> NodePtr;
typedef std::unique_ptr<File> FilePtr;
typedef std::unique_ptr<Link> LinkPtr;
typedef std::unique_ptr<Folder> FolderPtr;

std::unique_ptr<Node> Node::Parse(rapidjson::Value & json)
{
	if (json.HasMember("size"))
	{
		return File::Parse(json);
	}
	else if (json.HasMember("link"))
	{
		return Link::Parse(json);
	}
	else
	{
		return Folder::Parse(json);
	}
}
