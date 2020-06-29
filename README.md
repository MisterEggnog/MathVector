# Math Vector
## Overview
This library provides low weight vector objects that support vector addition & scalar multiplication.
There are implementations for two space vectors, three space vectors, & a template length vector.
All of these classes & functions are located in the namespace MathVector.

Note, this library requires c++17.
It has been tested with gcc & clang.

## Vector2
```cpp
#include <Vector2.hpp>
```
To accesses the members you can use either array notation or by member access, with the members `x` & `y`.

## Vector3
```cpp
#include <Vector3.hpp>
```
To accesses the members you can use either array notation or by member access, with the members `x`, `y`, & `z`.

## Vector Array
```cpp
#include <vector_array.hpp>
```
To access the members you can only use array notation.
Also, since this is derived from `std::array`, you can use >, <, >=, <=, & iterators.

## Vector Functions
```cpp
#include <vector_functions.hpp>
```
There's not a lot here but I included a few functions I use frequently.

```cpp
constexpr auto magnitude(const T& vc, F func)
```
This function takes a vector & a function object as arguments.
Currently the functions F must support depend on the size of `vc`.
* If `vc` is two space, F must have an overload for two scalar values, aka a `hypot` function.
* If `vc` is three space, F must have an overload for three scalar values, also `hypot` function.
* If `vc` is any other size, F must have an overload for only one scalar value, this one is just square root.

You can find these in `cmath`.
Unfortunately I cannot find a way around this with c++17.

```cpp
constexpr std::optional<T> unit_vector(const T& vc, F func)
```
This function returns a vector of length 1, pointing in the same direction of `vc`.
`F` is under the same rules as specified in `magnitude`.

If vc is trivial, this function returns no value.

```cpp
constexpr auto dot_product(const T& lhs, const T& rhs)
```
This function returns the dot product of two vectors, also called a scalar product.
