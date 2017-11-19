#pragma once

#include "tree_Node.h"
#include <memory>
//typedef std::unique_ptr<File> FilePtr;

namespace tree
{
	class File : public Node
	{
	public:
		File(const std::string & name, tree::Size size) : Node(name), _size(size) {}
		virtual ~File() {}

		tree::Size Size(bool /*bFollow*/, bool /*bRecursive*/) const override { return _size; }
		void List(bool /*bFollow*/, bool /*bRecursive*/, const std::string & /*offset*/, std::ostream & out) const override;
		typedef std::unique_ptr<File> FilePtr;
		static FilePtr Parse(rapidjson::Value & json);

	private:
		const tree::Size _size { 0. };
	};
}
