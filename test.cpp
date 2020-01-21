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
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector.hpp"
#include <cstdio>
#include <cmath>
#include <limits>
#include <random>

using Vector2 = MisterEggnog::Vector2<int>;
using Vector2f = MisterEggnog::Vector2<double>;
typedef bool(*testfun)();

std::mt19937 random_eng;
std::uniform_int_distribution<int> number_range(std::numeric_limits<short>::min(), std::numeric_limits<short>::max());
std::uniform_real_distribution float_number_range(-20.0, 20.0);

/////////////////////////////////////////////////////////////////////
// Vector 2
/////////////////////////////////////////////////////////////////////

bool add2_op()
{
	// vec +=
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int w = number_range(random_eng);
		Vector2 vc1{x, y};
		Vector2 vc2{z, w};
		x   += z;
		y   += w;
		vc1 += vc2;
		if (vc1.x != x && vc1.y != y)
			return false;
	}

	// vec + vec
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int w = number_range(random_eng);
		Vector2 vc1{x, y};
		Vector2 vc2{x, y};
		Vector2 vc3(vc1 + vc2);
		x += z;
		y += w;
		if (vc3.x != x && vc3.y == y)
			return false;
	}

	return true;
}

bool minus2_op()
{
	// vec +=
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int w = number_range(random_eng);
		Vector2 vc1{x, y};
		Vector2 vc2{z, w};
		x   -= z;
		y   -= w;
		vc1 -= vc2;
		if (vc1.x != x && vc1.y != y)
			return false;
	}

	// vec + vec
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int w = number_range(random_eng);
		Vector2 vc1{x, y};
		Vector2 vc2{x, y};
		Vector2 vc3(vc1 - vc2);
		x -= z;
		y -= w;
		if (vc3.x != x && vc3.y == y)
			return false;
	}

	return true;
}

bool multi2_op()
{
	// vec *= scalar
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		Vector2 vc{x, y};
		x  *= z;
		y  *= z;
		vc *= z;
		if (vc.x != x && vc.y != y)
			return false;
	}

	// scalar * vec
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		Vector2 vc{x, y};
		x  *= z;
		y  *= z;
		Vector2 vc2 = vc * z;
		if (vc2.x != x && vc2.y != y)
			return false;
	}

	// vec * scalar
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		Vector2 vc{x, y};
		x  *= z;
		y  *= z;
		Vector2 vc2 = z * vc;
		if (vc2.x != x && vc2.y != y)
			return false;
	}

	return true;
}

bool noexcept_vc2()
{
	struct throwable {
		throwable();
		throwable(const throwable&);
		throwable(throwable&&);
		throwable& operator=(const throwable&);
		throwable& operator=(throwable&&);
	};

	return !std::is_nothrow_default_constructible<MisterEggnog::Vector2<throwable>>()
		&& !std::is_nothrow_copy_constructible<MisterEggnog::Vector2<throwable>>()
		&& !std::is_nothrow_move_constructible<MisterEggnog::Vector2<throwable>>()
		&& !std::is_nothrow_copy_assignable<MisterEggnog::Vector2<throwable>>()
		&& !std::is_nothrow_move_assignable<MisterEggnog::Vector2<throwable>>();
}

bool comparision_vc2()
{
	Vector2 vc1(number_range(random_eng), number_range(random_eng));
	Vector2 vc2(number_range(random_eng), number_range(random_eng));
	Vector2 vc3(vc1);
	return vc1 != vc2 && vc1 == vc3;
}

bool vc2_dot_product()
{
	int x = number_range(random_eng);
	int y = number_range(random_eng);
	int z = number_range(random_eng);
	int w = number_range(random_eng);
	Vector2 vc1{w, x};
	Vector2 vc2{y, z};
	int dot_product = w*y + x*z;

	return dot_product == vc1.dot_product(vc2);
}

bool vc2_magnitude()
{
	double x = float_number_range(random_eng);
	double y = float_number_range(random_eng);
	Vector2f vec{x, y};
	double magnitude = std::sqrt(x*x + y*y);

	return magnitude == vec.magnitude(std::sqrt);
}

bool vc2_unit_vector()
{
	double a = float_number_range(random_eng);
	double b = float_number_range(random_eng);
	double c = std::sqrt(a*a + b*b);
	auto vec = MisterEggnog::Vector2(a, b);

	a *= 1 / c;
	b *= 1 / c;
	auto vec2 = vec.unit_vector(std::sqrt);

	return vec2.x == a && vec2.y == b;
}

bool vc2_special_implmentation()
{
	// Tests float
	{
		std::uniform_real_distribution<float> roll_float(-10.f, 10.f);
		float a = roll_float(random_eng);
		float b = roll_float(random_eng);
		auto vecf = MisterEggnog::Vector2(a, b);

		float c = std::hypotf(a, b);
		float vec_magnitude = vecf.magnitude();

		auto a_unit = a / c;
		auto b_unit = b / c;
		auto unit_vecf = vecf.unit_vector();

		if (c != vec_magnitude
			&& a_unit == unit_vecf.x
			&& b_unit == unit_vecf.y)
			return false;
	}

	// Tests double
	{
		double a = float_number_range(random_eng);
		double b = float_number_range(random_eng);
		auto vecf = MisterEggnog::Vector2(a, b);

		double c = std::hypot(a, b);
		double vec_magnitude = vecf.magnitude();

		auto a_unit = a / c;
		auto b_unit = b / c;
		auto unit_vecf = vecf.unit_vector();

		if (c != vec_magnitude
			&& a_unit == unit_vecf.x
			&& b_unit == unit_vecf.y)
			return false;
	}

	// Tests double
	{
		long double a = float_number_range(random_eng);
		long double b = float_number_range(random_eng);
		auto vecf = MisterEggnog::Vector2(a, b);

		long double c = std::hypotl(a, b);
		long double vec_magnitude = vecf.magnitude();

		auto a_unit = a / c;
		auto b_unit = b / c;
		auto unit_vecf = vecf.unit_vector();

		if (c != vec_magnitude
			&& a_unit == unit_vecf.x
			&& b_unit == unit_vecf.y)
			return false;
	}

	return true;
}

bool vc2_neg_pos_op()
{
	int x = number_range(random_eng);
	int y = number_range(random_eng);
	auto vec = -MisterEggnog::Vector2(x, y);
	
	return -x == vec.x
		&& -y == vec.y
		&& vec == +vec;
}

bool vc2_complex_multiplication()
{
	int a = number_range(random_eng);
	int b = number_range(random_eng);
	int c = number_range(random_eng);
	int d = number_range(random_eng);

	auto vc1 = MisterEggnog::Vector2(a, b);
	auto vc2 = MisterEggnog::Vector2(c, d);

	auto e = a*c - b*d;
	auto f = a*d + c*b;
	auto vc3 = MisterEggnog::complex_multiplication(vc1, vc2);

	return vc3.x == e && vc3.y == f;
}

/////////////////////////////////////////////////////////////////////
// Vector 3
/////////////////////////////////////////////////////////////////////

bool add3_op()
{
	// vec +=
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int u = number_range(random_eng);
		int v = number_range(random_eng);
		int w = number_range(random_eng);
		auto vc1 = MisterEggnog::Vector3(x, y, z);
		auto vc2 = MisterEggnog::Vector3(u, v, w);
		x   += u;
		y   += v;
		z   += w;
		vc1 += vc2;
		if (vc1.x != x && vc1.y != y && vc1.z != z)
			return false;
	}

	// vec + vec
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int u = number_range(random_eng);
		int v = number_range(random_eng);
		int w = number_range(random_eng);
		auto vc1 = MisterEggnog::Vector3(x, y, z);
		auto vc2 = MisterEggnog::Vector3(u, v, w);
		auto vc3 = (vc1 + vc2);
		x   += u;
		y   += v;
		z   += w;
		if (vc3.x != x && vc3.y == y && vc3.z == z)
			return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////
// General Length Vector
/////////////////////////////////////////////////////////////////////

#define TEST_NUMBER 12
#define STRING_LENGTH 18
#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)

int main()
{
	char test_str[TEST_NUMBER][STRING_LENGTH] = {
		// vc2
		"vc2 + op",
		"vc2 - op",
		"vc2 * op",
		"vc2 noexcept",
		"vc2 comparision",
		"vc2 dot product",
		"vc2 magnitude",
		"vc2 unit vector",
		"vc2 special impl",
		"vc2 pos/neg op",
		"vc2 complex *",
		// vc3
		"vc3 + op",
		// vc
	};
	testfun func[TEST_NUMBER] = {
		// vc2
		add2_op,
		minus2_op,
		multi2_op,
		noexcept_vc2,
		comparision_vc2,
		vc2_dot_product,
		vc2_magnitude,
		vc2_unit_vector,
		vc2_special_implmentation,
		vc2_neg_pos_op,
		vc2_complex_multiplication,
		// vc3
		add3_op,
		// vc
	};

	int success_count = 0;
	for (int i = 0; i < TEST_NUMBER; i++) {
		bool test_result = func[i]();
		if (test_result) success_count++;
		std::printf("Test%" TO_STRING(STRING_LENGTH) "s: %s\n", test_str[i], (test_result) ? "passed" : "failed");
	}
	{
		double percent_passed = (double)success_count / (double)TEST_NUMBER * 100.0;
		std::printf("%i of %i passed, %f%%\n", success_count, TEST_NUMBER, percent_passed);
	}
}
