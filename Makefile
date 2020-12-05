CXX = g++
CXXFLAGS = -std=c++17 -L/opt/X11/lib -Llib/ann_1.1.2/lib -I /opt/X11/include -I include -I lib/ann_1.1.2/include -o $@ -lANN -lpthread -lstdc++
TARGET = bin/main
DIRS = bin build

SRCFILES = $(shell find src -type f -name '*.cpp')
APPFILES = $(wildcard app/*.cpp)

OBJFILES = $(patsubst src/%.cpp, build/%.o, $(wildcard src/*.cpp))
BINFILES = $(patsubst app/%.cpp, bin/%, $(wildcard app/*.cpp))

.PRECIOUS: $(OBJFILES)

all: $(BINFILES)

bin/%: app/%.cpp # $(OBJFILES)
	mkdir -p "$(@D)"
	$(CXX) $(CXXFLAGS) $^

build/%.o: src/%.cpp include/%.hpp
	mkdir -p "$(@D)"
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf $(DIRS)
