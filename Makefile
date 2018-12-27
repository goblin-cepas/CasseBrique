CXX=g++
CXX_FLAGS=-g -O0 -ansi -std=c++11 -pedantic -Wall
LD_FLAGS =

PROGS= CasseBrique
SOURCES= window.cpp Paddle.cpp Ball.cpp Bonus.cpp Brick.cpp Score.cpp Configuration.cpp Game.cpp Home.cpp Level.cpp Save.cpp Log.cpp
HEADERS= window.h Paddle.h Ball.h Bonus.h Brick.h Score.h Configuration.h Game.h Home.h Level.h Rectangle.h Vector2.h Log.h Clock.h playerScore.h Velocity.h Save.h
DEPFILE=.depend

ifeq ($(wildcard $(DEPFILE)), )

all: $(DEPFILE)
	make

else

all: $(PROGS)
include $(DEPFILE)

endif

include $(DEPFILE)

.SUFFIXES: .cpp .h .o

$(PROGS): $(SOURCES:.cpp=.o)
	$(CXX) $(LD_FLAGS) $^ -o $@ -lncurses

.cpp.o:
	$(CXX) $(CXX_FLAGS) $< -c

$(DEPFILE): $(SOURCES)
	$(CXX) -MM $^ > $@

clean:
	rm -f *~ $(SOURCES:.cpp=.o) $(PROGS)
