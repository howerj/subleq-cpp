#include "subleq.hpp"

int main(int argc, char *argv[]) {
	Subleq<short> s;
	for (int i = 1; i < argc; i++)
		s.load(argv[i]);
	s.run();
	return 0;
}
