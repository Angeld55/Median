#include "MedianGetter.h"
#include <iostream>

int main()
{
	MedianGetter example;
	example.insert(1);
	example.insert(2);
	example.insert(3);

	std::cout << "The median of [1, 2, 3] is" << example.getMedian() << std::endl;
	return 0;
}
