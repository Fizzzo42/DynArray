#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "dynArray.h"

#include <sstream>
#include <iterator>
#include <vector>

void constructorEmpty() {
	dynArray<int> myDynArray { };
	ASSERT(false);
	//ASSERT(myDynArray.empty());
}

void constructorInitList() {
	std::initializer_list<int> input { 3, 4, 5, 6, 7, 8 };
	dynArray<int> myDynArray { input };
	ASSERT(false);
}

void constructorCntValue() {
	dynArray<double> myDynArray { 10, 3, 14 };
	ASSERT(false);
}

void constructorIterator() {
	std::istringstream is { "Hallo mein name ist Özhan" };
	std::istream_iterator<std::string> begin { is };
	std::istream_iterator<std::string> end { };
	dynArray<std::string> myDynArray { begin, end };

	ASSERT(false);
}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s { };

	s.push_back(CUTE(constructorEmpty));
	s.push_back(CUTE(constructorInitList));
	s.push_back(CUTE(constructorCntValue));
	s.push_back(CUTE(constructorIterator));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}

