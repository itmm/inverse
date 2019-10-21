# Knuth's Inversion Algorithm
* dissecting the in place inversion Algorithm from
  Knuth's Art of Computer Programming

```
@Def(file: inverse.cpp)
	#include <iostream>
	#include <cassert>
	#include <cstring>
	@put(globals);
	int main() {
		@put(main)
	};
@End(file: inverse.cpp)
```
* simple C++ program
* implement unit-tests with assertions

```
@def(globals)
	template<int N>
		void identity(int (&p)[N]) {
			for (
				int i { 1 }; i <= N; ++i
			) {
				p[i - 1] = i;
			}
		}
@end(globals)
```
* permutation is simple array
* initialize identity

```
@add(globals)
	template<int N>
		bool is_identity(
			const int (&p)[N]
		) {
			@put(is identity);
			return true;
		}
@end(globals)
```
* check identity

```
@def(is identity)
	for (int i { 1 }; i <= N; ++i) {
		if (p[i - 1] != i) {
			return false;
		}
	}
@end(is identity)
```
* check identity

```
@def(main) {
	@put(unit-tests)
} @end(main)
```
* own scope for unit-tests

```
@def(unit-tests) {
	int p[4];
	identity(p);
	assert(is_identity(p));
} @end(unit-tests)
```
* check that `@f(identity)` and `@f(is_identity)` work

```
@add(globals)
	template <int N>
		void mult(
			int (&p)[N],
			const int (&o)[N]
		) {
			@put(mult);
		}
@end(globals)
```
* multiply two permutations

```
@def(mult)
	assert(&p != &o);
@end(mult)
```
* both arguments must be different

```
@add(mult)
	for (int i { 1 }; i <= N; ++i) {
		p[i - 1] =
			o[p[i - 1] - 1];
	}
@end(mult)
```
* multiplication is the application of the first permutation after the
  second one

```
@add(unit-tests) {
	int p[4] { 2, 3, 4, 1 };
	assert(! is_identity(p));
	int o[4] { 4, 1, 2, 3 };
	assert(! is_identity(o));
	mult(p, o);
	assert(is_identity(p));
} @end(unit-tests)
```
* check that multiplication works

```
@add(globals)
	template <int N>
		void inv(int (&p)[N]) {
			@put(inv);
		}
@end(globals)
```
* in place invert

```
@def(inv)
	int m = N, j = -1;
	while (m > 0) {
		int i = p[m - 1];
		while (i > 0) {
			@put(inner loop);
		}
		p[m - 1] = -i;
		--m;
	}
@end(inv)
```
* perform inversion in place

```
@def(inner loop)
	p[m - 1] = j; j = -m;
	m = i; i = p[m - 1];
	if (i < 0) {
		i = j; break;
	}
@end(inner loop)
```
* perform inversion in place

```
@add(globals)
	template<int N>
		bool is_inversion(
			const int (&p)[N],
			const int (&i)[N]
		) {
			int t[N];
			std::memcpy(t, p, sizeof(p));
			mult(t, i);
			return is_identity(t);
		}
@end(globals)
```
* is `i` an inversion of `p`?

```
@add(globals)
	template<int N> void check_inversion(
		const int (&p)[N]
	) {
		int i[N];
		std::memcpy(i, p, sizeof(p));
		inv(i);
		assert(is_inversion(p, i));
	}
@end(globals)
```
* check that `p` can be inverted

```
@add(unit-tests) {
	int p[4] { 2, 3, 4, 1 };
	check_inversion(p);
} @end(unit-tests)
```
* invert simple permutation

```
@add(unit-tests) {
	int p[4]; identity(p);
	check_inversion(p);
} @end(unit-tests)
```
* invert identity

```
@add(unit-tests) {
	int p[4]; identity(p);
	inv(p);
	assert(is_identity(p));
} @end(unit-tests)
```
* invert of identity is identity

```
@add(unit-tests) {
	int p[4] { 4, 3, 2, 1 };
	check_inversion(p);
} @end(unit-tests)
```
* invert two runs

