#include <iostream>
using namespace std;

class BernoulliDistributionA
{
private:
        float p;
public:
        BernoulliDistributionA(float _p):
                p(_p) {};
        float getProbability() const {
                return p;
}
};

class BernoulliDistributionB
{
public:
    BernoulliDistributionB(float _p):
        p(_p) {};
    float p;
};


int main(){

    BernoulliDistributionA DistA(0.2);
    BernoulliDistributionB DistB (0.5);

    // printf("DistA probability %f \n" , DistA.getProbability());
    // printf("DistB probability %f \n" , DistB.p);
}

