EXEC = planejamento_de_horario_na_UF.exe
CXX = g++
CXXFLAGS = -Wall -O0 -pedantic
SRCS = main.cpp funcoes.cpp
OBJS = $(SRCS:.cpp=.o)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)

clean-windows:
	@if exist *.o del /Q *.o
	@if exist $(EXEC) del /Q $(EXEC)