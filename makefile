CXXFLAGS=-Wall -Wextra -fwrapv -O3
TARGET=subleq
IMAGE=subleq.dec

.PHONY: all default run clean

all default: ${TARGET}

run: ${TARGET} ${IMAGE}
	./${TARGET} ${IMAGE}

${TARGET}: ${TARGET}.cpp ${TARGET}.hpp

clean:
	git clean -dffx
