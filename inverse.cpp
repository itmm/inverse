
#line 6 "index.md"

	#include <iostream>
	#include <cassert>
	#include <cstring>
	
#line 20 "index.md"

	template<int N>
		void identity(int (&p)[N]) {
			for (
				int i { 1 }; i <= N; ++i
			) {
				p[i - 1] = i;
			}
		}

#line 35 "index.md"

	template<int N>
		bool is_identity(
			const int (&p)[N]
		) {
			
#line 48 "index.md"

	for (int i { 1 }; i <= N; ++i) {
		if (p[i - 1] != i) {
			return false;
		}
	}

#line 40 "index.md"
;
			return true;
		}

#line 75 "index.md"

	template <int N>
		void mult(
			int (&p)[N],
			const int (&o)[N]
		) {
			
#line 88 "index.md"

	assert(&p != &o);

#line 95 "index.md"

	for (int i { 1 }; i <= N; ++i) {
		p[i - 1] =
			o[p[i - 1] - 1];
	}

#line 81 "index.md"
;
		}

#line 118 "index.md"

	template <int N>
		void inv(int (&p)[N]) {
			
#line 128 "index.md"

	int m = N, j = -1;
	while (m > 0) {
		int i = p[m - 1];
		while (i > 0) {
			
#line 143 "index.md"

	p[m - 1] = j; j = -m;
	m = i; i = p[m - 1];
	if (i < 0) {
		i = j; break;
	}

#line 133 "index.md"
;
		}
		p[m - 1] = -i;
		--m;
	}

#line 121 "index.md"
;
		}

#line 154 "index.md"

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

#line 170 "index.md"

	template<int N> void check_inversion(
		const int (&p)[N]
	) {
		int i[N];
		std::memcpy(i, p, sizeof(p));
		inv(i);
		assert(is_inversion(p, i));
	}

#line 10 "index.md"
;
	int main() {
		
#line 59 "index.md"
 {
	
#line 66 "index.md"
 {
	int p[4];
	identity(p);
	assert(is_identity(p));
} 
#line 106 "index.md"
 {
	int p[4] { 2, 3, 4, 1 };
	assert(! is_identity(p));
	int o[4] { 4, 1, 2, 3 };
	assert(! is_identity(o));
	mult(p, o);
	assert(is_identity(p));
} 
#line 184 "index.md"
 {
	int p[4] { 2, 3, 4, 1 };
	check_inversion(p);
} 
#line 192 "index.md"
 {
	int p[4]; identity(p);
	check_inversion(p);
} 
#line 200 "index.md"
 {
	int p[4]; identity(p);
	inv(p);
	assert(is_identity(p));
} 
#line 209 "index.md"
 {
	int p[4] { 4, 3, 2, 1 };
	check_inversion(p);
} 
#line 60 "index.md"

} 
#line 12 "index.md"

	};
