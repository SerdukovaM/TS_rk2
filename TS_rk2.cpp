//Óñëîâèå: 15 âàðèàíò ôîðìóëà: sinxexp(-y)^2/(1+x^2+y^2)
//Âåðîÿòíîñòü ìóòàöèè: 25% 
//Òî÷åê 6

#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <map>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::map;

pair<double, double> Initialization() {
    pair<double, double> p;
    p.first = (static_cast<double>(rand() % (3 * 100000)) / 100000);
    p.second = (static_cast<double>(rand() % (5 * 100000)) / 100000) - 2;
    return p;
}

pair<double, int> FindMax(vector<pair<double, int>>& v) {
    pair<double, int> m;
    m.first = 0;
    for (size_t k = 0; k < 6; k++)
        if (v[k].first > m.first) {
            m.first = v[k].first;
            m.second = k;
        }
    return m;
}

int main() {
    srand(time(nullptr));
    vector<pair<double, double>> population;
    double function;
    pair<double, int> par;
    vector<pair<double, int>> values;
    pair<double, int> max;
    double mutant;
    mutant = 1;
    mutant *= (static_cast<double>((rand() % 100) - 49) / 100) + 0.5;
    cout << mutant << endl;

    for (size_t i = 0; i < 100; i++) {
        cout << endl;
        if (i == 0) {
            for (size_t i = 0; i < 6; i++) {
                population.push_back(Initialization());
            }
            for (size_t i = 0; i < 6; i++) {
                function = (sin(population[i].first) * exp(-pow(population[i].second, 2))) /
                    (1 + pow(population[i].first, 2) + pow(population[i].second, 2));
                par.first = function;
                par.second = i;
                values.push_back(par);
            }

        }
        else {

            max = FindMax(values);

            population[0] = population[max.second];
            population[1].first = population[max.second].first;
            mutant = population[max.second].second;
            if (rand() % 4 == 0) mutant *= (static_cast<double>((rand() % 200) - 99) / 100) + 1;
            population[1].second = mutant;
            mutant = population[max.second].first;
            if (rand() % 4 == 0) mutant *= (static_cast<double>((rand() % 200) - 99) / 100) + 1;
            population[2].first = mutant;
            population[2].second = population[max.second].second;

            population[3].first = population[max.second].first * (static_cast<double>((rand() % 200) - 99) / 100) + 1;
            population[3].second = population[max.second].second * (static_cast<double>((rand() % 200) - 99) / 100) + 1;

            population[4].first = population[max.second].first * (static_cast<double>((rand() % 100) - 49) / 100) + 0.5;
            population[4].second = population[max.second].second * (static_cast<double>((rand() % 100) - 49) / 100) + 0.5;

            population[5].first = population[max.second].first * (static_cast<double>((rand() % 50) - 24) / 100) + 0.25;
            population[5].second = population[max.second].second * (static_cast<double>((rand() % 50) - 24) / 100) + 0.25;

            for (size_t j = 0; j < 6; j++) {

                function = (sin(population[j].first) * exp(-pow(population[j].second, 2))) /
                    (1 + pow(population[j].first, 2) + pow(population[j].second, 2));
                par.first = function;
                par.second = j;
                values[j] = par;
            }


        }
        cout << "      X      " << "      Y      " << "      FIT      " << endl;
        for (size_t k = 0; k < 6; k++)
            cout << population[k].first << "     " << population[k].second << "     " << values[k].first << endl;
    }
    max = FindMax(values);
    cout << endl << "X = " << population[max.second].first << ";   Y = " << population[max.second].second << "  FIT= "
        << max.first;
    return 0;
}
