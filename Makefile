hepsi: derle calistir
derle:
	g++ -I ./include/ -o ./lib/islem.o -c ./src/islem.cpp
	g++ -I ./include/ -o ./lib/ikiliAramaAgaci.o -c ./src/ikiliAramaAgaci.cpp
	g++ -I ./include/ -o ./bin/main ./lib/islem.o ./lib/ikiliAramaAgaci.o	./src/main.cpp
	
calistir:
	./bin/main
	