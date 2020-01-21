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
#ifndef MISTEREGGNOG_VECTOR3_HPP_INCLUDED
#define MISTEREGGNOG_VECTOR3_HPP_INCLUDED
#include <cmath>
#include <type_traits>

namespace MisterEggnog {

template <class T>
struct Vector3 {
	T x, y, z;

	constexpr Vector3() noexcept(std::is_nothrow_default_constructible<T>()) = default;
	constexpr Vector3(const Vector3&) noexcept(std::is_nothrow_copy_constructible<T>()) = default;
	constexpr Vector3(Vector3&&) noexcept(std::is_nothrow_move_constructible<T>()) = default;
	~Vector3() = default;
	constexpr Vector3& operator=(const Vector3&) noexcept(std::is_nothrow_copy_assignable<T>()) = default;
	constexpr Vector3& operator=(Vector3&&) noexcept(std::is_nothrow_move_assignable<T>()) = default;

	constexpr Vector3(const T& x, const T& y, const T& z) noexcept
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

};

}

#endif // MISTEREGGNOG_VECTOR3_HPP_INCLUDED
