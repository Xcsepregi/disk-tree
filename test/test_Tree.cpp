#include "gtest/gtest.h"

#include "../cmd_Handler.h"
#include "../tree_Disk.h"

#include <memory>
#include <sstream>

#include "data.h"

TEST(Tree, Command)
{
	auto command = cmd::GetHandler("tree");
	EXPECT_NE(command, nullptr);
}