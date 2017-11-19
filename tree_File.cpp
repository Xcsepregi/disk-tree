#include "headers.h"
#include "tree_File.h"

#include <ostream>
#include <memory>

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace tree;
typedef std::unique_ptr<File> FilePtr;

void tree::File::List(bool /*bFollow*/, bool /*bRecursive*/, const std::string & /*offset*/, std::ostream & out) const
{
	out << Name() << " [" << _size.toString() << "]" << std::endl;
}

FilePtr tree::File::Parse(rapidjson::Value & json)
{
	if (!json.HasMember("name"))
		return nullptr;

	tree::Size size { json["size"].GetString() };
	if (size < tree::Size())
		return nullptr;

	//return std::unique_ptr<>(new File(std::forward(json["name"].GetString(), size)));
	//return std::unique_ptr<>  = std::make_unique(File(json["name"].GetString(), size);
	FilePtr file_ptr(new File(json["name"].GetString(), size));
	return file_ptr;
	//return new File(json["name"].GetString(), size);
}
