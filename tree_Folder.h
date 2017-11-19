#pragma once

#include "tree_Node.h"

#include <vector>
#include <regex>
//typedef std::unique_ptr<tree::Node> NodePtr;

namespace tree
{	
	class Folder : public Node
	{
	public:
		Folder(const std::string & name) : Node(name) {}
		virtual ~Folder() {}

		tree::Size Size(bool bFollow, bool bRecursive) const override;
		void List(bool bFollow, bool bRecursive, const std::string & offset, std::ostream & out) const override;

		void Insert(NodePtr node);
		void Remove(const NodePtr node);
		const std::vector<std::unique_ptr<Node>> & Content() const { return _content; }

		NodePtr Find(const std::string & path)/* const*/;
		NodePtr Find(std::sregex_token_iterator iter) /*const*/;

		typedef std::unique_ptr<Folder> FolderPtr;
		static FolderPtr Parse(rapidjson::Value & json);

	private:
		std::vector<std::unique_ptr<Node>> _content;
	};
}
