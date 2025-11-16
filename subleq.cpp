#include "subleq.hpp"

int main(int argc, char *argv[]) {
	Subleq<short> s;
	for (int i = 1; i < argc; i++)
		if (s.load(argv[i]) < 0)
			return 1;
	return s.run() < 0;
}
