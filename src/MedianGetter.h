#include <queue>
#include <vector>
#include <iostream>
#include <functional>  
#include <initializer_list> 


class MedianGetter
{
	std::priority_queue<int> left;
	std::priority_queue<int, std::vector<int>, std::greater<int>> right;

	void handleHeapsSizes();
public:
	MedianGetter() = default;
	MedianGetter(std::initializer_list<int>);

	void insert(int);
	double getMedian() const;
};
