#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void test(){
    long long susceptible, infected, recovered = 0, days;
    cin >> susceptible >> infected >> days;
    double beta, gamma;//beta: infection rate, gamma: recovery rate
    cin >> beta >> gamma;
    for(int i = 1; i <= days; ++i){
        long long new_infected = ceil(susceptible*infected*beta);
        long long new_recovered = ceil(infected*gamma);
        new_infected = min(new_infected, susceptible);
        susceptible -= new_infected;
        infected += new_infected - new_recovered;
        recovered += new_recovered;
    }
    cout << susceptible << " " << infected << " " << recovered;
}

int main(){
    test();
    return 0;
}