#pragma once

#include <algorithm>

template<typename Container, typename Element>
void InsertSorted(Container& container, const Element& element)
{
    typename std::vector<Element>::iterator found = std::lower_bound(container.begin(), container.end(), element);
    container.insert(found, element);
}
template<typename Container, typename Element, typename Compare>
void InsertSorted(Container& container, const Element& element, Compare compare)
{
    typename std::vector<Element>::iterator found = std::lower_bound(container.begin(), container.end(), element, compare);
    container.insert(found, element);
}

template<typename Container, typename Element>
const Element& FindSorted(Container& container, const Element& element)
{
    return *std::lower_bound(container.begin(), container.end(), element);
}
template<typename Container, typename Element, typename Compare>
const Element& FindSorted(Container& container, const Element& element, Compare compare)
{
    return *std::lower_bound(container.begin(), container.end(), element, compare);
}

template<typename Container, typename Element>
bool BinaryContains(Container& container, const Element& element)
{
    return std::binary_search(container.begin(), container.end(), element);
}