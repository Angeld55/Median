#include "../src/MedianGetter.h"
#include <iostream>
#include <algorithm>

// All test cases are of this type
using TestFunction = bool(*)();

// Runs a single test case
bool runTest(TestFunction pfn, const char* name)
{
	bool result = pfn();

	std::cout
		<< "   ["
		<< (result ? "  OK  " : "Failed")
		<< "] "
		<< name
		<< std::endl;

	return result;
}

bool cmp(double a, double b)
{
    static const double EPSILON = 0.000001;
    return fabs(a - b) < EPSILON;
}

// Entry point for the application.
int main()
{
}

#define TEST_CASE(name)                     \
	bool name();                                \
	bool testvar_##name = runTest(name, #name); \
	bool name()

#define ASSERT(condition) if(!(condition)) return false;

//----------------------------------------------------------------

TEST_CASE(medianGetter_array_sortedAscending)
{
	MedianGetter m({ 1, 2, 3, 4, 5 });
	ASSERT(cmp(m.getMedian(),3));
	return true;
}

TEST_CASE(medianGetter_array_sortedDescending)
{
	MedianGetter m({ 5, 4, 3, 2, 1 });
	ASSERT(cmp(m.getMedian(), 3));
	return true;
}


TEST_CASE(medianGetter_array_sameNumbers)
{
	MedianGetter m({1,1,1,1,1,1,1,1,1,1});
	ASSERT(cmp(m.getMedian(), 1));
	return true;
}

TEST_CASE(medianGetter_array_numbers)
{
	MedianGetter m({ 1, 2, 1, 0, 3, 6, 9, 5, 7 });
	ASSERT(cmp(m.getMedian(), 3));
	return true;
}

TEST_CASE(medianGetter_stream_sameNumbers)
{
	MedianGetter m({ 1 });
	ASSERT(cmp(m.getMedian(), 1));

	m.insert(1);
	ASSERT(cmp(m.getMedian(), 1));

	m.insert(1);
	ASSERT(cmp(m.getMedian(), 1));
	return true;

}

TEST_CASE(medianGetter_stream_aroundNumber)
{
	MedianGetter m({ 1 });
	ASSERT(cmp(m.getMedian(), 1));

	m.insert(2);
	ASSERT(cmp(m.getMedian(), 1));

	m.insert(0);
	ASSERT(cmp(m.getMedian(), 1));

	m.insert(-1);
	ASSERT(cmp(m.getMedian(), 0));

	m.insert(3);
	ASSERT(cmp(m.getMedian(), 1));
	return true;
}

TEST_CASE(medianGetter_stream_increasing)
{
	MedianGetter m;
	m.insert(1);
	ASSERT(cmp(1, m.getMedian()));

	m.insert(2);
	ASSERT(cmp(1, m.getMedian()));

	m.insert(3);
	ASSERT(cmp(2, m.getMedian()));

	m.insert(4);
	ASSERT(cmp(2, m.getMedian()));

	m.insert(5);
	ASSERT(cmp(3, m.getMedian()));

	m.insert(6);
	ASSERT(cmp(3, m.getMedian()));

	m.insert(7);
	ASSERT(cmp(4, m.getMedian()));

	m.insert(8);
	ASSERT(cmp(4, m.getMedian()));
	return true;
}

TEST_CASE(medianGetter_stream_decreasing)
{
	MedianGetter m;
	m.insert(5);
	ASSERT(cmp(5, m.getMedian()));

	m.insert(4);
	ASSERT(cmp(4, m.getMedian()));

	m.insert(3);
	ASSERT(cmp(4, m.getMedian()));

	m.insert(2);
	ASSERT(cmp(3, m.getMedian()));

	m.insert(1);
	ASSERT(cmp(3, m.getMedian()));

	m.insert(0);
	ASSERT(cmp(2, m.getMedian()));

	m.insert(-1);
	ASSERT(cmp(2, m.getMedian()));

	m.insert(-2);
	ASSERT(cmp(1, m.getMedian()));
	return true;
}
