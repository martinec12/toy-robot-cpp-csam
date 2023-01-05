ODIR := ../obj/src
SDIR := ../src

SRCS := $(wildcard $(SDIR)/*.cpp)

OBJS := $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRCS))

SRC_CXXFLAGS := -I$(SDIR) -Wall

$(ODIR)/%.o : $(SDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(SRC_CXXFLAGS) -c $< -o $@

toyrobot-exe: $(OBJS)
	$(CXX) -o $@ $^

clean:
	rm -rf $(ODIR) toyrobot-exe

.PHONY: clean
