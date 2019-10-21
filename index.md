# Understand Knuth's Inversion Algorithm

```
@Def(file: inverse.cpp)
	#include <iostream>
	#include <cassert>
	@put(globals);
	int main() {
		@put(main)
	};
@End(file: inverse.cpp)
```

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

```
@add(globals)
	template<int N>
		bool is_identity(
			const int (&p)[N]
		) {
			for (
				int i { 1 }; i <= N; ++i
			) {
				if (p[i - 1] != i) {
					return false;
				}
			}
			return true;
		}
@end(globals)
```

```
@def(main) {
	@put(unit-tests)
} @end(main)
```

```
@def(unit-tests) {
	int p[4];
	identity(p);
	assert(is_identity(p));
} @end(unit-tests)
```

```
@add(globals)
	template <int N>
		void mult(
			int (&p)[N],
			const int (&o)[N]
		) {
			assert(&p != &o);
			for (
				int i { 1 }; i <= N; ++i
			) {
				p[i - 1] =
					o[p[i - 1] - 1];
			}
		}
@end(globals)
```

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

```
@add(globals)
	template <int N>
		void inv(int (&p)[N]) {
			@put(inv);
		}
@end(globals)
```

```
@def(inv)
	int m = N, j = -1;
	while (m > 0) {
		int i = p[m - 1];
		while (i > 0) {
			p[m - 1] = j; j = -m;
			m = i; i = p[m - 1];
			if (i < 0) {
				i = j; break;
			}
		}
		p[m - 1] = -i;
		--m;
	}
@end(inv)
```

```
@add(unit-tests) {
	int p[4] { 2, 3, 4, 1 };
	int o[4] { 2, 3, 4, 1 };
	inv(o);
	mult(p, o);
	assert(is_identity(p));
} @end(unit-tests)
```

```
@add(unit-tests) {
	int p[4]; identity(p);
	inv(p);
	assert(is_identity(p));
} @end(unit-tests)
```

```
@add(unit-tests) {
	int p[4] { 4, 3, 2, 1 };
	int o[4] { 4, 3, 2, 1 };
	inv(o);
	mult(p, o);
	assert(is_identity(p));
} @end(unit-tests)
```
