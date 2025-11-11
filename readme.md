# C++ SUBLEQ VM
* Author: Richard James Howe
* License: 0BSD
* Repo: <https://github.com/howerj/subleq-cpp>
* Email: <mailto:howe.r.j.89@gmail.com>

Implementation of a SUBLEQ VM in C++ as a header-only library. Images are
provided from <https://github.com/howerj/subleq> and end in `*.dec`. 

There is a test program, use `make run` to build and run the Forth interpreter
in `subleq.dec`. `int`/`long`/`short` has been tested (`char` will not work)
when used a template parameter. You should compile any compilation unit that
uses this with `-fwrapv`.

