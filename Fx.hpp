/**
 * 
 * Fx.hpp - Functional Modern C++ Library
 *
 */

#ifndef _FX_HPP_
#define _FX_HPP_

#include <algorithm>
#include <iterator>
#include <type_traits>
#include <vector>

namespace Fx {

template <typename InputIterator, typename Functor>
auto map(InputIterator begin, InputIterator end, Functor f) -> std::vector<typename std::result_of<Functor(typename std::iterator_traits<InputIterator>::value_type)>::type>
{
    using FunctorValueType = typename std::result_of<Functor(typename std::iterator_traits<InputIterator>::value_type)>::type;
    std::vector<FunctorValueType> functorValues;
    functorValues.reserve(unsigned(std::distance(begin, end)));
    std::transform(begin, end, std::back_inserter(functorValues), f);
    return functorValues;
}


template <typename InputIterator, typename Functor>
std::vector<typename std::iterator_traits<InputIterator>::value_type> filter(InputIterator begin, InputIterator end, Functor f)
{
    using ValueType = typename std::iterator_traits<InputIterator>::value_type;
    std::vector<ValueType> result;
    result.reserve(std::distance(begin, end));
    std::copy_if(begin, end, std::back_inserter(result), f);
    return result;
}

}

#endif
