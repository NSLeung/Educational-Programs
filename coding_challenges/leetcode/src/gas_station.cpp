#include "util.h"

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int gas_tank =0, sum =0;
    int starting;
    for(int i = 0; i < gas.size();i++){
        
        sum += gas[i] - cost[i];
        gas_tank += gas[i] - cost[i];
            
        if (gas_tank < 0) {
            starting = i+1;
            gas_tank = 0;
        }
    }
    return sum >= 0 ? starting%gas.size() : -1;
}



int main() {

    return 0;
}