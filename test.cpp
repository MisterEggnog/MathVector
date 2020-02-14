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
#include "include/vector2.hpp"
#include "include/vector3.hpp"
#include "include/vector_array.hpp"
#include "include/vector_functions.hpp"
#include <cstdio>
#include <cmath>
#include <limits>
#include <random>

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
		auto vc1 = MisterEggnog::Vector2(x, y);
		auto vc2 = MisterEggnog::Vector2(z, w);
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
		auto vc1 = MisterEggnog::Vector2(x, y);
		auto vc2 = MisterEggnog::Vector2(z, w);
		auto vc3 = vc1 + vc2;
		x += z;
		y += w;
		if (vc3.x != x && vc3.y == y)
			return false;
	}

	return true;
}

bool minus2_op()
{
	// vec -=
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int w = number_range(random_eng);
		auto vc1 = MisterEggnog::Vector2(x, y);
		auto vc2 = MisterEggnog::Vector2(z, w);
		x   -= z;
		y   -= w;
		vc1 -= vc2;
		if (vc1.x != x && vc1.y != y)
			return false;
	}

	// vec - vec
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int w = number_range(random_eng);
		auto vc1 = MisterEggnog::Vector2(x, y);
		auto vc2 = MisterEggnog::Vector2(z, w);
		auto vc3 = vc1 - vc2;
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
		auto vc = MisterEggnog::Vector2(x, y);
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
		auto vc = MisterEggnog::Vector2(x, y);
		x  *= z;
		y  *= z;
		auto vc2 = vc * z;
		if (vc2.x != x && vc2.y != y)
			return false;
	}

	// vec * scalar
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		auto vc = MisterEggnog::Vector2(x, y);
		x  *= z;
		y  *= z;
		auto vc2 = z * vc;
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
	auto vc1 = MisterEggnog::Vector2(number_range(random_eng), number_range(random_eng));
	auto vc2 = MisterEggnog::Vector2(number_range(random_eng), number_range(random_eng));
	auto vc3(vc1);
	return vc1 != vc2 && vc1 == vc3;
}

bool vc2_array_access()
{
	int x = number_range(random_eng);
	int y = number_range(random_eng);
	MisterEggnog::Vector2<int> vc;
	vc[0] = x;
	vc[1] = y;
	return vc[0] == x && vc[1] == y;
}

bool vc2_size_constant()
{
	return MisterEggnog::Vector2<int>::SIZE == 2;
}

bool vc2_sign_ops()
{
	auto vc1 = MisterEggnog::Vector2(number_range(random_eng), number_range(random_eng));
	auto vc2(+vc1);
	auto vc3(-vc1);
	return vc1 == vc2 && (vc1 * -1) == vc3;
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

bool minus3_op()
{
	// vec -=
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int u = number_range(random_eng);
		int v = number_range(random_eng);
		int w = number_range(random_eng);
		auto vc1 = MisterEggnog::Vector3(x, y, z);
		auto vc2 = MisterEggnog::Vector3(u, v, w);
		x   -= u;
		y   -= v;
		z   -= w;
		vc1 -= vc2;
		if (vc1.x != x && vc1.y != y && vc1.z != z)
			return false;
	}

	// vec - vec
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int u = number_range(random_eng);
		int v = number_range(random_eng);
		int w = number_range(random_eng);
		auto vc1 = MisterEggnog::Vector3(x, y, z);
		auto vc2 = MisterEggnog::Vector3(u, v, w);
		auto vc3 = (vc1 - vc2);
		x   -= u;
		y   -= v;
		z   -= w;
		if (vc3.x != x && vc3.y != y && vc3.z != z)
			return false;
	}

	return true;
}

bool multi3_op()
{
	// *=
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int u = number_range(random_eng);
		auto vc = MisterEggnog::Vector3(x, y, z);
		x  *= u;
		y  *= u;
		z  *= u;
		vc *= u;

		if (x != vc.x && y != vc.y && z != vc.z)
			return false;
	}

	// vc * scalar
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int u = number_range(random_eng);
		auto vc1 = MisterEggnog::Vector3(x, y, z);
		auto vc2 = vc1 * u;
		x  *= u;
		y  *= u;
		z  *= u;

		if (x != vc2.x && y != vc2.y && z != vc2.z)
			return false;
	}

	// scalar * vc
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int u = number_range(random_eng);
		auto vc1 = MisterEggnog::Vector3(x, y, z);
		auto vc2 = u * vc1;
		x  *= u;
		y  *= u;
		z  *= u;

		if (x != vc2.x && y != vc2.y && z != vc2.z)
			return false;
	}

	return true;
}

bool vc3_noexcept()
{
	struct throwable {
		throwable();
		throwable(const throwable&);
		throwable(throwable&&);
		throwable& operator=(const throwable&);
		throwable& operator=(throwable&&);
	};

	return !std::is_nothrow_default_constructible<MisterEggnog::Vector3<throwable>>()
		&& !std::is_nothrow_copy_constructible<MisterEggnog::Vector3<throwable>>()
		&& !std::is_nothrow_move_constructible<MisterEggnog::Vector3<throwable>>()
		&& !std::is_nothrow_copy_assignable<MisterEggnog::Vector3<throwable>>()
		&& !std::is_nothrow_move_assignable<MisterEggnog::Vector3<throwable>>();
}

bool comparision_vc3()
{
	auto vc1 = MisterEggnog::Vector3(number_range(random_eng), number_range(random_eng), number_range(random_eng));
	auto vc2 = MisterEggnog::Vector3(number_range(random_eng), number_range(random_eng), number_range(random_eng));
	auto vc3(vc1);
	return vc1 != vc2 && vc1 == vc3;
}

bool vc3_array_access()
{
	int x = number_range(random_eng);
	int y = number_range(random_eng);
	int z = number_range(random_eng);
	MisterEggnog::Vector3<int> vc;
	vc[0] = x;
	vc[1] = y;
	vc[2] = z;
	return vc[0] == x && vc[1] == y && vc[2] == z;
}

bool vc3_size_constant()
{
	return MisterEggnog::Vector3<int>::SIZE == 3;
}

bool vc3_sign_ops()
{
	auto vc1 = MisterEggnog::Vector3(number_range(random_eng), number_range(random_eng), number_range(random_eng));
	auto vc2(+vc1);
	auto vc3(-vc1);
	return vc1 == vc2 && (vc1 * -1) == vc3;
}

/////////////////////////////////////////////////////////////////////
// General Length Vector
/////////////////////////////////////////////////////////////////////

typedef MisterEggnog::Vector<int, 4> vec4;

bool vcn_add_op()
{
	// +=
	{
		int x1 = number_range(random_eng);
		int x2 = number_range(random_eng);
		int y1 = number_range(random_eng);
		int y2 = number_range(random_eng);
		int z1 = number_range(random_eng);
		int z2 = number_range(random_eng);
		int w1 = number_range(random_eng);
		int w2 = number_range(random_eng);
		vec4 vc1{x1, y1, z1, w1};
		vec4 vc2{x2, y2, z2, w2};
		x1  += x2;
		y1  += y2;
		z1  += z2;
		w1  += w2;
		vc1 += vc2;
		if (vc1[0] != x1 && vc1[1] != y1 && vc1[2] != z1 && vc1[3] != w1)
			return false;
	}

	// +
	{
		int x1 = number_range(random_eng);
		int x2 = number_range(random_eng);
		int y1 = number_range(random_eng);
		int y2 = number_range(random_eng);
		int z1 = number_range(random_eng);
		int z2 = number_range(random_eng);
		int w1 = number_range(random_eng);
		int w2 = number_range(random_eng);
		vec4 vc1{x1, y1, z1, w1};
		vec4 vc2{x2, y2, z2, w2};
		auto vc3 = vc1 + vc2;
		x1  += x2;
		y1  += y2;
		z1  += z2;
		w1  += w2;
		if (vc3[0] != x1 && vc3[1] != y1 && vc3[2] != z1 && vc3[3] != w1)
			return false;
	}

	return true;
}

bool vcn_sub_op()
{
	// -=
	{
		int x1 = number_range(random_eng);
		int x2 = number_range(random_eng);
		int y1 = number_range(random_eng);
		int y2 = number_range(random_eng);
		int z1 = number_range(random_eng);
		int z2 = number_range(random_eng);
		int w1 = number_range(random_eng);
		int w2 = number_range(random_eng);
		vec4 vc1{x1, y1, z1, w1};
		vec4 vc2{x2, y2, z2, w2};
		x1  -= x2;
		y1  -= y2;
		z1  -= z2;
		w1  -= w2;
		vc1 -= vc2;
		if (vc1[0] != x1 && vc1[1] != y1 && vc1[2] != z1 && vc1[3] != w1)
			return false;
	}

	// -
	{
		int x1 = number_range(random_eng);
		int x2 = number_range(random_eng);
		int y1 = number_range(random_eng);
		int y2 = number_range(random_eng);
		int z1 = number_range(random_eng);
		int z2 = number_range(random_eng);
		int w1 = number_range(random_eng);
		int w2 = number_range(random_eng);
		vec4 vc1{x1, y1, z1, w1};
		vec4 vc2{x2, y2, z2, w2};
		auto vc3 = vc1 - vc2;
		x1  -= x2;
		y1  -= y2;
		z1  -= z2;
		w1  -= w2;
		if (vc3[0] != x1 && vc3[1] != y1 && vc3[2] != z1 && vc3[3] != w1)
			return false;
	}

	return true;
}

bool vcn_multi_op()
{
	// *=
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int w = number_range(random_eng);
		int a = number_range(random_eng);
		vec4 vc{x, y, z, w};
		x  *= a;
		y  *= a;
		z  *= a;
		w  *= a;
		vc *= a;
		if (vc[0] != x && vc[1] != y && vc[2] != z && vc[3] != w)
			return false;
	}

	// vc * scalar
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int w = number_range(random_eng);
		int a = number_range(random_eng);
		vec4 vc1{x, y, z, w};
		vec4 vc2 = vc1 * a;
		x  *= a;
		y  *= a;
		z  *= a;
		w  *= a;
		if (vc2[0] != x && vc2[1] != y && vc2[2] != z && vc2[3] != w)
			return false;
	}

	// scalar * vc
	{
		int x = number_range(random_eng);
		int y = number_range(random_eng);
		int z = number_range(random_eng);
		int w = number_range(random_eng);
		int a = number_range(random_eng);
		vec4 vc1{x, y, z, w};
		vec4 vc2 = a * vc1;
		x  *= a;
		y  *= a;
		z  *= a;
		w  *= a;
		if (vc2[0] != x && vc2[1] != y && vc2[2] != z && vc2[3] != w)
			return false;
	}

	return true;
}

bool noexcept_vcn()
{
	struct throwable {
		throwable();
		throwable(const throwable&);
		throwable(throwable&&);
		throwable& operator=(const throwable&);
		throwable& operator=(throwable&&);
	};

	return !std::is_nothrow_default_constructible<MisterEggnog::Vector<throwable, 2>>()
		&& !std::is_nothrow_copy_constructible<MisterEggnog::Vector<throwable, 2>>()
		&& !std::is_nothrow_move_constructible<MisterEggnog::Vector<throwable, 2>>()
		&& !std::is_nothrow_copy_assignable<MisterEggnog::Vector<throwable, 2>>()
		&& !std::is_nothrow_move_assignable<MisterEggnog::Vector<throwable, 2>>();
}

bool vcn_size_constant()
{
	return MisterEggnog::Vector<int, 2>::SIZE == 2
	&& MisterEggnog::Vector<int, 4>::SIZE == 4
	&& MisterEggnog::Vector<int, 8>::SIZE == 8;
}

bool vcn_sign_ops()
{
	vec4 vc1{number_range(random_eng), number_range(random_eng), number_range(random_eng)};
	auto vc2(+vc1);
	auto vc3(-vc1);
	return vc1 == vc2 && (vc1 * -1) == vc3;
}

/////////////////////////////////////////////////////////////////////
// Vector functions
/////////////////////////////////////////////////////////////////////

bool dot_product()
{
	int x = number_range(random_eng);
	int y = number_range(random_eng);
	int z = number_range(random_eng);
	int u = number_range(random_eng);
	int v = number_range(random_eng);
	int w = number_range(random_eng);
	auto vc1 = MisterEggnog::Vector3(x, y, z);
	auto vc2 = MisterEggnog::Vector3(u, v, w);

	int d   = x*u + y*v + z*w;
	int vcd = MisterEggnog::dot_product(vc1, vc2);

	return d == vcd;
}

struct Magn {
	double operator()(double x, double y)
	{
		return std::hypot(x, y);
	}

	double operator()(double x, double y, double z)
	{
		return std::hypot(x, y, z);
	}

	double operator()(double dot_prod)
	{
		return std::sqrt(dot_prod);
	}
};

bool magn_2_17()
{
	auto x = float_number_range(random_eng);
	auto y = float_number_range(random_eng);
	auto vc1 = MisterEggnog::Vector2(x, y);
	Magn magn;
	auto magn_hyp = std::hypot(x, y);
	auto magn_vc = MisterEggnog::magnitude(vc1, magn);

	return magn_hyp == magn_vc;
}

bool magn_3_17()
{
	auto x = float_number_range(random_eng);
	auto y = float_number_range(random_eng);
	auto z = float_number_range(random_eng);
	auto vc1 = MisterEggnog::Vector3(x, y, z);
	Magn magn;
	auto magn_hyp = std::hypot(x, y, z);
	auto magn_vc = MisterEggnog::magnitude(vc1, magn);

	return magn_hyp == magn_vc;
}

bool magn_n_17()
{
	auto x = float_number_range(random_eng);
	auto y = float_number_range(random_eng);
	auto z = float_number_range(random_eng);
	auto w = float_number_range(random_eng);
	MisterEggnog::Vector<double, 4> vc1{x, y, z, w};
	Magn magn;
	auto magn_hyp = std::sqrt(x*x + y*y +  z*z + w*w);
	auto magn_vc = MisterEggnog::magnitude(vc1, magn);

	return magn_hyp == magn_vc;
}

#define TEST_NUMBER 26
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
		"vc2 []",
		"vc2 size const",
		"vc2 \"sign\" ops",
		// vc3
		"vc3 + op",
		"vc3 - op",
		"vc3 * op",
		"vc3 noexcept",
		"vc3 comparision",
		"vc3 []",
		"vc3 size const",
		"vc3 \"sign\" ops",
		// vcn
		"vcn + op",
		"vcn - op",
		"vcn * op",
		"vcn noexcept",
		"vcn size const",
		"vcn \"sign\" ops",
		// vc fns
		"dot product",
		"|vc2| stdc++17",
		"|vc3| stdc++17",
		"|vcn| stdc++17",
	};
	testfun func[TEST_NUMBER] = {
		// vc2
		add2_op,
		minus2_op,
		multi2_op,
		noexcept_vc2,
		comparision_vc2,
		vc2_array_access,
		vc2_size_constant,
		vc2_sign_ops,
		// vc3
		add3_op,
		minus3_op,
		multi3_op,
		vc3_noexcept,
		comparision_vc3,
		vc3_array_access,
		vc3_size_constant,
		vc3_sign_ops,
		// vc
		vcn_add_op,
		vcn_sub_op,
		vcn_multi_op,
		noexcept_vcn,
		vcn_size_constant,
		vcn_sign_ops,
		// vc fns
		dot_product,
		magn_2_17,
		magn_3_17,
		magn_n_17,
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

	if (success_count == TEST_NUMBER)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}
