CC=g++
CFLAGS= -std=c++11 -Wall -Werror -pthread -I/usr/local/mongo-client-install/include/ -I$(HOME)/Programs/boost/include/ -L/usr/local/mongo-client-install/lib -L$(HOME)/Programs/boost/lib -lrt -lmongoclient -lboost_thread -lboost_system -lboost_regex 
DEPS = card_manager.h deck_manager.h card.h minion.h spell.h
OBJ = hearthBot.o card_manager.o card.o deck_manager.o minion.o spell.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hearthBot: $(OBJ) 
	g++ -o $@ $^ $(CFLAGS)

clean:
	rm *.o hearthBot