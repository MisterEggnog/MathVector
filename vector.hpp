/*
MIT License

Copyright (c) 2019 Josiah Baldwin

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
#ifndef MISTEREGGNOG_VECTOR_HPP_INCLUDED
#define MISTEREGGNOG_VECTOR_HPP_INCLUDED

#include <cmath>
#include <array>
#include <type_traits>

namespace MisterEggnog {

template <class T, std::size_t size>
struct Vector : public std::array<T, size> {

	constexpr Vector() noexcept(std::is_nothrow_default_constructible<std::array<T, size>>()) = default;
	constexpr Vector(const Vector&) noexcept(std::is_nothrow_copy_constructible<std::array<T, size>>()) = default;
	constexpr Vector(Vector&&) noexcept(std::is_nothrow_move_constructible<std::array<T, size>>()) = default;
	~Vector() = default;
	constexpr Vector& operator=(const Vector&) noexcept(std::is_nothrow_copy_assignable<std::array<T, size>>()) = default;
	constexpr Vector& operator=(Vector&&) noexcept(std::is_nothrow_move_assignable<std::array<T, size>>()) = default;

};

}

#endif // MISTEREGGNOG_MATH_VECTOR_HPP_INCLUDED
