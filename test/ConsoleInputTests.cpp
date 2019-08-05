#include "pch.h"
#include "ConsoleInputFixture.h"

TEST_F( ConsoleInputFixture, Empty ) {
	std::string text = "";
	stream_ << text;
	std::string ret( console_->GetSelection() );
	EXPECT_EQ( text, ret );
}

TEST_F( ConsoleInputFixture, Long_String ) {
	std::string text = "dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn"
		"dfasdfasdfasdfasdfasdfasdf asdf asdgvsadfg sxvcbxhgnf gymh dmghnc fbh cmvncvnvbcn";
	stream_ << text;
	std::string ret( console_->GetSelection() );
	EXPECT_EQ( text, ret );
}

TEST_F( ConsoleInputFixture, AlphaNumeric_And_Symbols ) {
	std::string text = "1234567890/*-+qwertyuiop[]';.,/lkjhgfdsazxcvbnm,.QWERTYUIOPASDFGHJKLZXCVBNM<>??:{}|_+~`";
	stream_ << text;
	std::string ret( console_->GetSelection() );
	EXPECT_EQ( text, ret );
}

TEST_F( ConsoleInputFixture, Double_Quotes ) {
	std::string text = "\"";
	stream_ << text;
	std::string ret( console_->GetSelection() );
	EXPECT_EQ( text, ret );
}