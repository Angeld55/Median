#include "MedianGetter.h"

MedianGetter::MedianGetter(std::initializer_list<int> ilist)
{
	for (int el : ilist)
		insert(el);
}

void MedianGetter::insert(int n)
{
	if (left.empty())
		left.push(n);
	else
	{
		if (n < left.top())
			left.push(n);
		else
			right.push(n);

		handleHeapsSizes();
	}
}

/*
Set of an even number has no distinct middle value 
and the median is usually defined the left of two middle value.

Other definition: the arithmetic mean of the two middle values.

The current implemented structure gives the median by the first definition,
but could be easly modified for the second definition.
*/
int MedianGetter::getMedian() const
{
	if (left.empty())
		throw std::logic_error("empty collection!");
	return left.top();
}

void MedianGetter::handleHeapsSizes()
{
	if (left.size() > right.size() + 1)
	{
		right.push(left.top());
		left.pop();
	}
	else if (left.size() < right.size())
	{
		left.push(right.top());
		right.pop();
	}
}
