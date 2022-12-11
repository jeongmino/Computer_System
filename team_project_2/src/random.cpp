
#include "../include/cache_algorithm.h"

void makeRandomData(void){
    srand(time(NULL));
    std::ofstream file("./randomDir/random.txt");
    int arr[20] = {12, 41, 42, 456, 2345, 562, 530, 1594, 2222, 1400, 3670, 6436, 1233, 4000, 1234, 3434, 121, 1212, 4100, 3333};
    for (int i = 0; i < 5000; i++){
        file << std::to_string(arr[rand() % 20]) + ",";
    }
    file.close();
}
