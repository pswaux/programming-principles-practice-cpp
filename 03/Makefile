#
# usage:
#
# 		make 			   				-> build all files (release by default)
# 		make target(s) 				-> build specific file(s)
# 		make mode=debug 				-> build all files with -g flag
# 		make mode=debug target(s)	-> build specific file(s) with debug mode
# 		make clean     				-> clean all files
#
.RECIPEPREFIX = >

# should be match with BINDIR and SRCDIR 
VPATH = . src bin debug include

CXXSTD   = # -std=c++14
CPPFLAGS = # -I"include"
CXXFLAGS = $(CXXSTD) $(CPPFLAGS) -Wall -time $(VERSION)
LDFLAGS  = # -L"lib"
LDLIBS   = # -lm
AR       = ar
BINDIR	=
DEBUGDIR =
SRCDIR   =
DEBUG    = -O0 -g
RELEASE  = -O2 -DNDEBUG
VERSION  = $(RELEASE)

.SUFFIXES: .cpp .o

# Create a list of source files.
SOURCES  = $(shell ls $(SRCDIR)*.cpp)
# Create a list of object files from the source file lists.
OBJECTS = ${SOURCES:.cpp=.o}
# Create a list of targets.
TARGETS = $(addprefix $(BINDIR),$(notdir $(patsubst %.cpp, % , $(SOURCES))))
#															   change this ^ with %.exe for build exe files

.PHONY: all
# Build all targets by default
all: $(TARGETS)

ifeq ($(mode), debug)
   VERSION = $(DEBUG)
endif

# A rule to build file out of a .o file
# change % with %.exe for exe files
$(BINDIR)%: %.o
> $(CXX) -o $@ $(LDFLAGS) $< $(LDLIBS)
> @echo 
> @echo -e "\033[33;1m Done building $* \033[0m"
> @echo ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# A rule to build .o file out of a .cpp file
%.o: %.cpp
> $(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: clean
# A rule to clean all the intermediates and targets
clean:
> rm -rf $(TARGETS) $(OBJECTS) $(DEBUGDIR) *.out
