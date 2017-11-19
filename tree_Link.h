#pragma once
#include "tree_Node.h"

namespace tree
{
	class Link : public Node
	{
	public:
		Link(const std::string & name, const std::string & path) : Node(name), _path(path)
		{
		}
		virtual ~Link() {}

		tree::Size Size(bool bFollow, bool bRecursive) const override;
		void List(bool bFollow, bool bRecursive, const std::string & offset, std::ostream & out) const override;

		void Set(NodePtr link) { _link = std::move(link); }
		const NodePtr Get() { return std::move(_link); }

		const std::string & Path() const { return _path; }
		typedef std::unique_ptr<Link> LinkPtr;
		static LinkPtr Parse(rapidjson::Value & json);

	private:
		NodePtr _link { nullptr };
		const std::string _path;
	};
}
