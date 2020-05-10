# pokehash
A Pokedex that is implemented with a hash table. The pokehash will include the pokemon's name, number, weight, type(s), abilities, and a brief description. Descriptions of the original Pokemon in the pokemon.tsv file are from the Pokemon.com website. 

To run the program, execute it with a .tsv file name of your choice - this file keeps a record of all the Pokemon you added into the PokeHash, so whenever you run the program with the file name, the pokemon you added previously will already be loaded into the PokeHash. 

To run: 
g++ -std=c++11 Pokemon.cpp driver.cpp
./a.out yourFileName.tsv

Our main data structure is a hash table. The hash table is useful for this program because each pokemon has their own index. We created the index by using their name. This makes it easier for the user to search for a pokemon. 

Our second data structure were vectors. We had a vector for each type of Pokemon. These were used to organize the Pokemon by their types and allowed the user to view Pokemon by type.
