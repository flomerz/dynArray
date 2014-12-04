#include "dynArray.h"

#include <vector>
#include <istream>

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void testFront() {
	std::vector<int> iu { 1, 2, 5 };
	dynArray<int> dyniu { 1, 2, 5 };
	ASSERT_EQUAL(iu.front(), dyniu.front());
}

void testFrontConst() {
	std::vector<int> const iu { 1, 2, 5 };
	dynArray<int> const dyniu { 1, 2, 5 };
	ASSERT_EQUAL(iu.front(), dyniu.front());
}

void testBack() {
	std::vector<int> iu { 1, 2, 5 };
	dynArray<int> dyniu { 1, 2, 5 };
	ASSERT_EQUAL(iu.back(), dyniu.back());
}

void testBackConst() {
	std::vector<int> const iu { 1, 2, 5 };
	dynArray<int> const dyniu { 1, 2, 5 };
	ASSERT_EQUAL(iu.back(), dyniu.back());
}

void testSize() {
	std::vector<int> iu { 1, 2, 5 };
	dynArray<int> dyniu { 1, 2, 5 };
	ASSERT_EQUAL(iu.size(), dyniu.size());
}

void testEmpty() {
	std::vector<int> iu { 1, 2, 5 };
	dynArray<int> dyniu { 1, 2, 5 };
	ASSERT_EQUAL(iu.empty(), dyniu.empty());
	iu = {};
	dyniu = {};
	ASSERT_EQUAL(iu.empty(), dyniu.empty());
}

void testPushBack() {
	std::vector<int> iu { 1, 2, 5 };
	dynArray<int> dyniu { 1, 2, 5 };
	iu.push_back(3);
	dyniu.push_back(3);
	ASSERT_EQUAL(iu.size(), dyniu.size());
	ASSERT_EQUAL(iu.back(), dyniu.back());
}

void testPopBack() {
	std::vector<int> iu { 1, 2, 5 };
	dynArray<int> dyniu { 1, 2, 5 };
	iu.pop_back();
	dyniu.pop_back();
	ASSERT_EQUAL(iu.size(), dyniu.size());
}

void testDefaultConstruct() {
	dynArray<int> a { };
	ASSERT(a.empty());
	ASSERT_EQUAL(0, a.size());
}

void testListConstruct() {
	dynArray<int> a { 1, 2, 3, 4 };
	ASSERT_EQUAL(1, a[0]);
	ASSERT_EQUAL(4, a[3]);
	ASSERT_EQUAL(3, a[-2]);
	ASSERT_EQUAL(2, a[-3]);
}

void testListConstructChar() {
	dynArray<char> a { 'h', 'a', 'l', 'l', 'o' };
	std::string s { a.begin(), a.end() };
	ASSERT_EQUAL("hallo", s);
}

void testIterConstruct() {
	std::vector<int> iu { 1, 2, 5 };
	dynArray<int> a { iu.begin(), iu.end() };
	ASSERT_EQUAL(1, a[0]);
	ASSERT_EQUAL(5, a[2]);
	ASSERT_EQUAL(2, a[-2]);
}

void testIstreamIterConstruct() {
	std::istringstream a { "hallo das ist ein test" };
	using iter=std::istream_iterator<std::string>;
	dynArray<std::string> ar { iter { a }, iter { } };
	ASSERT_EQUAL(5, ar.size());
	ASSERT_EQUAL("hallo", ar[-5]);
	ASSERT_EQUAL("das", ar.at(-4));
	ASSERT_EQUAL("ist", ar[-3]);
	ASSERT_EQUAL("ein", ar[3]);
	ASSERT_EQUAL("test", ar.at(4));
}

void testMultipleConstruct() {
	dynArray<double> a(5, 2.5);
	ASSERT(!a.empty());
	ASSERT_EQUAL(5, a.size());
	ASSERT_EQUAL(2.5, a.at(0));
	ASSERT_EQUAL(2.5, a.at(1));
	ASSERT_EQUAL(2.5, a.at(2));
	ASSERT_EQUAL(2.5, a.at(-2));
	ASSERT_EQUAL(2.5, a.at(-1));
}

void testIter() {
	std::ostringstream out { };
	std::ostream_iterator<std::string> out_iter(out, " ");
	dynArray<std::string> test { "the", "answer", "is", "42" };
	std::copy(test.begin(), test.end(), out_iter);
	ASSERT_EQUAL("the answer is 42 ", out.str());
}

void testConstIter() {
	dynArray<int> const &test { 1, 2, 3, 4, 5, 6, 7, 8, 6 };
	int erg { std::accumulate(test.cbegin(), test.cend(), 0) };
	ASSERT_EQUAL(42, erg);
}

void testReverseIter() {
	std::ostringstream out { };
	std::ostream_iterator<char> out_iter(out, "");
	dynArray<char> test { 'o', 'l', 'l', 'a', 'h' };
	std::copy(test.rbegin(), test.rend(), out_iter);
	ASSERT_EQUAL("hallo", out.str());
}

void testReverseIterConst() {
	std::ostringstream out { };
	std::ostream_iterator<char> const out_iter(out, "");
	dynArray<char> const test { 'o', 'l', 'l', 'a', 'h' };
	std::copy(test.rbegin(), test.rend(), out_iter);
	ASSERT_EQUAL("hallo", out.str());
}

void testErase() {
	std::ostringstream out { };
	std::ostream_iterator<std::string> out_iter(out, " ");
	dynArray<std::string> test { "this", "12546789", "is", "a test" };
	test.erase(test.begin() + 1);
	std::copy(test.begin(), test.end(), out_iter);
	ASSERT_EQUAL("this is a test ", out.str());
}
void testMakeDynArray() {
	std::ostringstream out { };
	std::ostream_iterator<std::string> out_iter(out, " ");
	auto test = makeDynArray( { "this", "is", "a", "test" });
	std::copy(test.begin(), test.end(), out_iter);
	ASSERT_EQUAL("this is a test ", out.str());
}

void testResize() {
	dynArray<int> a { };
	a.resize(5);
	ASSERT_EQUAL(5, a.size());
}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(testFront));
	s.push_back(CUTE(testBack));
	s.push_back(CUTE(testSize));
	s.push_back(CUTE(testEmpty));
	s.push_back(CUTE(testPushBack));
	s.push_back(CUTE(testPopBack));
	s.push_back(CUTE(testListConstruct));
	s.push_back(CUTE(testMultipleConstruct));
	s.push_back(CUTE(testFrontConst));
	s.push_back(CUTE(testBackConst));
	s.push_back(CUTE(testDefaultConstruct));
	s.push_back(CUTE(testIterConstruct));
	s.push_back(CUTE(testListConstructChar));
	s.push_back(CUTE(testIstreamIterConstruct));
	s.push_back(CUTE(testReverseIter));
	s.push_back(CUTE(testReverseIterConst));
	s.push_back(CUTE(testIter));
	s.push_back(CUTE(testConstIter));
	s.push_back(CUTE(testErase));
	s.push_back(CUTE(testMakeDynArray));
	s.push_back(CUTE(testResize));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}

