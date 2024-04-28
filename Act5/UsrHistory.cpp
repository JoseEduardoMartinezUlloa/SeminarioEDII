#include <iostream>
#include "UsrHistory.h"
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <string.h>

UsrHistory Historial;

void getHourAndDate(){
    time_t result = time(nullptr);
    std::cout << asctime(localtime(&result))<<std::endl;
}

std::vector<std::string> words{ "cake", "cookie", "carrot", "cauliflower", "cherries", "celery" };
void UsrHistory::Add(){
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<std::size_t> distribution(0, words.size()-1);
    std::size_t num = distribution(generator);
    std::cout<<"Nombre del usuario: "<<words[num]<<std::endl;
    getHourAndDate();
}