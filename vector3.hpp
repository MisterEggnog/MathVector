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

	constexpr Vector3(const T& val_x, const T& val_y, const T& val_z) noexcept : x(val_x), y(val_y), z(val_z) {}

	constexpr Vector3<T> operator+=(const Vector3<T>& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	constexpr Vector3<T> operator-=(const Vector3<T>& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	constexpr Vector3<T> operator*=(const T& rhs)
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}

};

template <class T>
constexpr Vector3<T> operator+(Vector3<T> lhs, const Vector3<T>& rhs)
{
	lhs += rhs;
	return lhs;
}

template <class T>
constexpr Vector3<T> operator-(Vector3<T> lhs, const Vector3<T>& rhs)
{
	lhs -= rhs;
	return lhs;
}

template <class T>
constexpr Vector3<T> operator*(Vector3<T> lhs, const T& rhs)
{
	lhs *= rhs;
	return lhs;
}

template <class T>
constexpr Vector3<T> operator*(const T& lhs, Vector3<T> rhs)
{
	rhs *= lhs;
	return rhs;
}

}

#endif // MISTEREGGNOG_VECTOR3_HPP_INCLUDED
