
#line 4 "index.md"

	#include <iostream>
	#include <cassert>
	
#line 15 "index.md"

	template<int N>
		void identity(int (&p)[N]) {
			for (
				int i { 1 }; i <= N; ++i
			) {
				p[i - 1] = i;
			}
		}

#line 28 "index.md"

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

#line 60 "index.md"

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

#line 89 "index.md"

	template <int N>
		void inv(int (&p)[N]) {
			
#line 98 "index.md"

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

#line 92 "index.md"
;
		}

#line 7 "index.md"
;
	int main() {
		
#line 46 "index.md"
 {
	
#line 52 "index.md"
 {
	int p[4];
	identity(p);
	assert(is_identity(p));
} 
#line 78 "index.md"
 {
	int p[4] { 2, 3, 4, 1 };
	assert(! is_identity(p));
	int o[4] { 4, 1, 2, 3 };
	assert(! is_identity(o));
	mult(p, o);
	assert(is_identity(p));
} 
#line 116 "index.md"
 {
	int p[4] { 2, 3, 4, 1 };
	int o[4] { 2, 3, 4, 1 };
	inv(o);
	mult(p, o);
	assert(is_identity(p));
} 
#line 126 "index.md"
 {
	int p[4]; identity(p);
	inv(p);
	assert(is_identity(p));
} 
#line 134 "index.md"
 {
	int p[4] { 4, 3, 2, 1 };
	int o[4] { 4, 3, 2, 1 };
	inv(o);
	mult(p, o);
	assert(is_identity(p));
} 
#line 47 "index.md"

} 
#line 9 "index.md"

	};
