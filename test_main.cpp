
#include "vector2.hpp"
#include <cstdio>
#include <limits>
#include <random>

using Vector2 = MisterEggnog::Vector2<int>;
typedef bool(*testfun)();

std::mt19937 random_eng;
std::uniform_int_distribution number_range(std::numeric_limits<short>::min(), std::numeric_limits<short>::max());

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

#define TEST_NUMBER 4
#define STRING_LENGTH 13
#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)

int main()
{
	char test_str[TEST_NUMBER][STRING_LENGTH] = {
		"vc2 + op",
		"vc2 - op",
		"vc2 * op",
		"vc2 noexcept" 
	};
	testfun func[TEST_NUMBER] = {
		add2_op,
		minus2_op,
		multi2_op,
		noexcept_vc2
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

/*
#define TEST_NUMBER
#define STRING_LENGTH
#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)

typedef bool(*testfun)();

	char test_str[TEST_NUMBER][STRING_LENGTH] = {
	};
	testfun func[TEST_NUMBER] = {
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
 */
