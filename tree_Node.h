#pragma once

#include "tree_Size.h"

#include <string>
#include <ostream>
#include <memory>

#include "rapidjson/document.h"


namespace tree
{
	class Node;
	typedef std::unique_ptr<Node> NodePtr;
	class Node
	{
	public:
		Node(const std::string & name = {}) : _name(name) {}
		virtual ~Node() {}

		virtual tree::Size Size(bool bFollow, bool bRecursive) const = 0;
		virtual void List(bool bFollow, bool bRecursive, const std::string & offset, std::ostream & out) const = 0;

		const std::string & Name() const { return _name; }
		
		static NodePtr Parse(rapidjson::Value & json);
	private:
		const std::string _name;
	};
}
