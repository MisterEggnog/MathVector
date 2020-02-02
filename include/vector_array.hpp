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
#ifndef MATHVECTOR_INCLUDE_MISTEREGGNOG_VECTOR_HPP_INCLUDED
#define MATHVECTOR_INCLUDE_MISTEREGGNOG_VECTOR_HPP_INCLUDED

#include <array>
#include <type_traits>

namespace MisterEggnog {

template <class T, std::size_t N>
struct Vector : public std::array<T, N> {

	static constexpr std::size_t SIZE = N;
	using scalar = T;

	constexpr Vector() noexcept(std::is_nothrow_default_constructible<std::array<T, N>>()) = default;
	constexpr Vector(const Vector&) noexcept(std::is_nothrow_copy_constructible<std::array<T, N>>()) = default;
	constexpr Vector(Vector&&) noexcept(std::is_nothrow_move_constructible<std::array<T, N>>()) = default;
	~Vector() = default;
	constexpr Vector& operator=(const Vector&) noexcept(std::is_nothrow_copy_assignable<std::array<T, N>>()) = default;
	constexpr Vector& operator=(Vector&&) noexcept(std::is_nothrow_move_assignable<std::array<T, N>>()) = default;

	constexpr Vector<T, N> operator+=(const Vector<T, N>& rhs)
	{
		for (auto i = 0U; i < SIZE; i++)
			this->operator[](i) += rhs[i];
		return *this;
	}

	constexpr Vector<T, N> operator-=(const Vector<T, N>& rhs)
	{
		for (auto i = 0U; i < SIZE; i++)
			this->operator[](i) -= rhs[i];
		return *this;
	}

	constexpr Vector<T, N> operator*=(const T& rhs)
	{
		for (auto i = 0U; i < SIZE; i++)
			this->operator[](i) *= rhs;
		return *this;
	}

	constexpr const Vector<T, N>& operator+() const
	{
		return *this;
	}

	constexpr Vector<T, N> operator-() const
	{
		return *this * -1;
	}

};

template <class T, std::size_t N>
constexpr Vector<T, N> operator+(Vector<T, N> lhs, const Vector<T, N>& rhs)
{
	return lhs += rhs;
}

template <class T, std::size_t N>
constexpr Vector<T, N> operator-(Vector<T, N> lhs, const Vector<T, N>& rhs)
{
	return lhs -= rhs;
}

template <class T, std::size_t N>
constexpr Vector<T, N> operator*(Vector<T, N> lhs, const T& rhs)
{
	return lhs *= rhs;
}

template <class T, std::size_t N>
constexpr Vector<T, N> operator*(const T& lhs, Vector<T, N> rhs)
{
	return rhs *= lhs;
}

}

#endif // MATHVECTOR_INCLUDE_MISTEREGGNOG_VECTOR_HPP_INCLUDED
