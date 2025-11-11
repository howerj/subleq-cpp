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

	void run() {
		for (int pc = 0; pc >= 0;) {
			const T a = m[pc++]; 
			const T b = m[pc++]; 
			const T c = m[pc++];
			if (a == -1) {
				m[b] = get();
			} else if (b == -1) {
				put(m[a]);
			} else {
				const T r = m[b] - m[a];
				m[b] = r;
				if (r <= 0) 
					pc = c;
			}
		}
	}

	void load(std::string file) {
		std::ifstream fh(file.c_str(), std::ios_base::in);
		std::istream_iterator<T> i_v, i_f(fh);
		std::copy(i_f, i_v, std::back_inserter(m));
		fh.close();
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

	void put(int ch) { 
		_out << static_cast<char>(ch);
		_out.flush();
	}
};

#endif
