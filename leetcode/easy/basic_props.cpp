#include<iostream>

using namespace std;

class Car {
    public:
    std::string color, model;
    std::int32_t currentSpeed;

    public:
        Car(std::string clr, std::string model, std::int32_t currentSpeed = 0){
            this->color = clr;
            this->model = model;
        }
    public:
        int add(int a, int b){
            return a + b;
        }
};

int main(){
    Car bmw("red", "BMW");
    int time = 5, dist = 100;
    std::cout << bmw.color << '\n';
    std::cout << bmw.currentSpeed << '\n';
    bmw.currentSpeed = dist / time;
    std::cout << bmw.currentSpeed;
    bmw.add(5, 4);
    return 0;
}