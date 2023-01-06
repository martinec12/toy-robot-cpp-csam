ODIR := ../obj/src
TODIR := ../obj/test
SDIR := ../src
TDIR := ../test
GTEST_ROOT := ../third_party/googletest
GTEST_LIB_DIR := $(GTEST_ROOT)/build/lib
GTEST_INCLUDE := $(GTEST_ROOT)/googletest/include

SRCS := $(wildcard $(SDIR)/*.cpp)
TO_EXCLUDE_SRC := $(SDIR)/main.cpp
EXCLUDED_SRCS := $(filter-out $(TO_EXCLUDE_SRC),$(SRCS))

OBJS := $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRCS))
OBJS_LESS_EXCLUDED := $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(EXCLUDED_SRCS))

TSRCS := $(wildcard $(TDIR)/*.cpp)
TOBJS := $(patsubst $(TDIR)/%.cpp,$(TODIR)/%.o,$(TSRCS))

TEST_CXXFLAGS := -I$(SDIR) -I$(TDIR) -I$(GTEST_INCLUDE) -Wall
SRC_CXXFLAGS := -I$(SDIR) -Wall
LDLIBS := -lgtest -lpthread
LDFLAGS := -L$(GTEST_LIB_DIR)

$(ODIR)/%.o : $(SDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(SRC_CXXFLAGS) -c $< -o $@

$(TODIR)/%.o : $(TDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@

toyrobot-exe: $(OBJS)
	$(CXX) -o $@ $^

testtoyrobot: $(OBJS_LESS_EXCLUDED) $(TOBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf $(ODIR) $(TODIR) testtoyrobot toyrobot-exe

.PHONY: clean
