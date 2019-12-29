#ifndef MISTEREGGNOG_VECTOR2_HPP_INCLUDED
#define MISTEREGGNOG_VECTOR2_HPP_INCLUDED
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

#include <type_traits>

namespace MisterEggnog {

template <class T>
struct Vector2 {
	T x, y;

	constexpr Vector2() noexcept(std::is_nothrow_default_constructible<T>()) = default;
	constexpr Vector2(const Vector2&) noexcept(std::is_nothrow_copy_constructible<T>()) = default;
	constexpr Vector2(Vector2&&) noexcept(std::is_nothrow_move_constructible<T>()) = default;
	~Vector2() = default;
	constexpr Vector2& operator=(const Vector2&) noexcept(std::is_nothrow_copy_assignable<T>()) = default;
	constexpr Vector2& operator=(Vector2&&) noexcept(std::is_nothrow_move_assignable<T>()) = default;

	constexpr Vector2(const T& x, const T& y) noexcept
	{
		this->x = x;
		this->y = y;
	}

	constexpr Vector2<T>& operator+=(const Vector2<T>& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}

	constexpr Vector2<T>& operator-=(const Vector2<T>& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}

	constexpr Vector2<T>& operator*=(T value)
	{
		this->x *= value;
		this->y *= value;
		return *this;
	}

	constexpr T dot_product(const Vector2<T>& rhs)
	{
		return this->x * rhs.x + this->y * rhs.y;
	}

	constexpr T magnitude(T(*magnitude)(T))
	{
		return magnitude(this->dot_product(*this));
	}

	constexpr Vector2<T> unit_vector(T(*magnitude)(T))
	{
		return (*this) * ((T)1 / this->magnitude(magnitude));
	}
};

template <class T>
constexpr bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <class T>
constexpr bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return !(lhs == rhs);
}

template <class T>
constexpr Vector2<T> operator+(Vector2<T> lhs, const Vector2<T>& rhs)
{
	return lhs += rhs;
}

template <class T>
constexpr Vector2<T> operator-(Vector2<T> lhs, const Vector2<T>& rhs)
{
	return lhs -= rhs;
}

template <class T>
constexpr Vector2<T> operator*(Vector2<T> lhs, const T& rhs)
{
	return lhs *= rhs;
}

template <class T>
constexpr Vector2<T> operator*(const T& lhs, Vector2<T> rhs)
{
	return rhs *= lhs;
}


}

#endif // MISTEREGGNOG_VECTOR2_HPP_INCLUDED
