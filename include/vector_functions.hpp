/*
MIT License

Copyright (c) 2020 Josiah Baldwin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef MATHVECTOR_INCLUDE_MISTEREGGNOG_VECTOR_FUNCTIONS_HPP_INCLUDED
#define MATHVECTOR_INCLUDE_MISTEREGGNOG_VECTOR_FUNCTIONS_HPP_INCLUDED

#include <cassert>
#include <type_traits>

namespace MathVector {

template <class T>
constexpr auto dot_product(const T& lhs, const T& rhs)
{
	typename T::scalar accumulated_val = 0;
	for (auto i = 0U; i < T::SIZE; i++)
		accumulated_val += lhs[i] * rhs[i];
	return accumulated_val;
}

// Vector 2 magnitude using hypot fn
template <class T, class F, typename std::enable_if_t<T::SIZE == 2, int> = 0>
constexpr auto magnitude(const T& vc, F func)
{
	return func(vc[0], vc[1]);
}

// Vector 3 magnitude using 3 dimensional hypot fn
template <class T, class F, typename std::enable_if_t<T::SIZE == 3, int> = 0>
constexpr auto magnitude(const T& vc, F func)
{
	return func(vc[0], vc[1], vc[2]);
}

// General case magnitude uses sqrt
template <class T, class F, typename std::enable_if_t<T::SIZE >= 4, int> = 0>
constexpr auto magnitude(const T& vc, F func)
{
	return func(dot_product(vc, vc));
}

template <class T, class F>
constexpr T unit_vector(const T& vc, F func)
{
	return vc * (1 / magnitude(vc, func));
}

}

#endif // MATHVECTOR_INCLUDE_MISTEREGGNOG_VECTOR_FUNCTIONS_HPP_INCLUDED
