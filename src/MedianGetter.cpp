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

double MedianGetter::getMedian() const
{
	if (left.empty())
		throw std::logic_error("empty collection!");
	return left.size() == right.size() ? (left.top() + right.top())/2.0 : left.top();
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
