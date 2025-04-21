#include <gtest.h>
#include "StringClass.h"


TEST(TStringTest, DefaultConstructor)
{
  TString s;
  EXPECT_STREQ(s.GetStr(), "");
  EXPECT_EQ(s.GetLen(), 1);
}

TEST(TStringTest, ConstructorFromConstChar)
{
  const char* test = "test";
  TString s(test);
  EXPECT_STREQ(s.GetStr(), test);
  EXPECT_EQ(s.GetLen(), strlen(test));
}

TEST(TStringTest, CopyConstructor)
{
  TString original("test");
  TString copy(original);
  EXPECT_STREQ(copy.GetStr(), original.GetStr());
  EXPECT_EQ(copy.GetLen(), original.GetLen());
}

TEST(TStringTest, MoveConstructor)
{
  TString original("test");
  TString moved(std::move(original));
  EXPECT_STREQ(moved.GetStr(), "test");
  EXPECT_EQ(moved.GetLen(), 4);
}

TEST(TStringTest, SetStrUpdatesContent)
{
  TString s;
  s.SetStr("new");
  EXPECT_STREQ(s.GetStr(), "new");
  EXPECT_EQ(s.GetLen(), 3);
}

TEST(TStringTest, SetLenUpdatesLength)
{
  TString s("test");
  s.SetLen(2);
  EXPECT_EQ(s.GetLen(), 2);
}

TEST(TStringTest, FindSubstringExists)
{
  TString s("hello world");
  TString sub("world");
  EXPECT_EQ(s.Find(sub), 6);
}

TEST(TStringTest, FindSubstringNotExists)
{
  TString s("hello");
  TString sub("world");
  EXPECT_EQ(s.Find(sub), -1);
}

TEST(TStringTest, SubstringMiddle)
{
  TString s("abcdefgh");
  TString sub = s.Substring(2, 3);
  EXPECT_STREQ(sub.GetStr(), "cde");
  EXPECT_EQ(sub.GetLen(), 3);
}

TEST(TStringTest, SubstringToEnd)
{
  TString s("abcdef");
  TString sub = s.Substring(3);
  EXPECT_STREQ(sub.GetStr(), "def");
  EXPECT_EQ(sub.GetLen(), 3);
}

TEST(TStringTest, PlusOperatorConcatenation)
{
  TString a("Hello");
  TString b("World");
  TString result = a + b;
  EXPECT_STREQ(result.GetStr(), "HelloWorld");
  EXPECT_EQ(result.GetLen(), 10);
}

TEST(TStringTest, MultiplyOperatorRepeatsString)
{
  TString s("ab");
  TString result = s * 3;
  EXPECT_STREQ(result.GetStr(), "ababab");
  EXPECT_EQ(result.GetLen(), 6);
}

TEST(TStringTest, AssignmentOperatorDeepCopy)
{
  TString original("test");
  TString copy;
  copy = original;
  original.SetStr("new");
  EXPECT_STREQ(copy.GetStr(), "test");
}

TEST(TStringTest, EqualityOperator)
{
  TString a("test");
  TString b("test");
  TString c("TEST");
  EXPECT_TRUE(a == b);
  EXPECT_FALSE(a == c);
}

TEST(TStringTest, IndexOperatorAccess)
{
  TString s("test");
  EXPECT_EQ(s[0], 't');
  s[0] = 'T';
  EXPECT_EQ(s[0], 'T');
}

TEST(TStringTest, OutputOperator)
{
  TString s("test");
  std::ostringstream os;
  os << s;
  EXPECT_EQ(os.str(), "test");
}

TEST(TStringTest, InputOperator)
{
  TString s;
  std::istringstream input("test");
  input >> s;
  EXPECT_STREQ(s.GetStr(), "test");
  EXPECT_EQ(s.GetLen(), 4);
}

TEST(TStringTest, EmptyStringOperations)
{
  TString s;
  EXPECT_EQ(s.Find(TString("any")), -1);
  TString sub = s.Substring(0);
  EXPECT_STREQ(sub.GetStr(), "");
}

TEST(TStringTest, MyTest)
{
  TString s("testing123123");
  s = s;
  EXPECT_STREQ(s.GetStr(), "testing123123");
  EXPECT_EQ(s.GetLen(), 13);
}

