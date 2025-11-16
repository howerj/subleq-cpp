#ifndef SUBLEQ_CPP_H /* See <https://github.com/howerj/subleq-cpp> */
#define SUBLEQ_CPP_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T> class Subleq {
public:
	Subleq(size_t reserve = 65536, std::istream& in = std::cin, std::ostream& out = std::cout) : _in(in), _out(out) {
		m.reserve(reserve);
		for (size_t i = 0; i < reserve; i++)
			m[i] = 0;
	}

	int run() {
		const size_t L = m.capacity();
		for (size_t pc = 0; pc < L;) {
			const T a = m[pc++ % L]; 
			const T b = m[pc++ % L]; 
			const T c = m[pc++ % L];
			if (a == -1) {
				m[((unsigned)b) % L] = get();
			} else if (b == -1) {
				if (put(m[((unsigned)a) % L]) < 0)
					return -1;
			} else {
				const T r = m[((unsigned)b) % L] - m[((unsigned)a) % L];
				m[((unsigned)b) % L] = r;
				if (r <= 0) 
					pc = c;
			}
		}
		return 0;
	}

	int load(std::string file) {
		std::ifstream fh(file.c_str(), std::ios_base::in);
		if (!fh)
			return -1;
		std::istream_iterator<T> i_v, i_f(fh);
		std::copy(i_f, i_v, std::back_inserter(m));
		fh.close();
		return 0;
	}

private:
	std::vector<T> m;
	std::istream& _in;
	std::ostream& _out;

	int get() { 
		if (eof()) 
			return -1; 
		const char r = _in.get(); 
		return eof() ? -1 : r; 
	}

	int eof() {
		return _in.eof(); 
	}

	int put(int ch) { 
		if (!(_out << static_cast<char>(ch)))
			return -1;
		_out.flush();
		return 0;
	}
};

#endif
