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

// void fn_i(BernoulliDistributionA & b){
//     b.p = 10;
// }

// void fn_ii(BernoulliDistributionA *& b){
//     b = 0;
// }

// void fn_iii(const BernoulliDistributionB & b){
//     b.p = 10;
// }

// void fn_iii(BernoulliDistributionB & b){
//     b.p = 10;
// }

// void fn_v(BernoulliDistributionB b){
//     b.p = 10;
// }

int main(){

    BernoulliDistributionA DistA(0.2);
    BernoulliDistributionB DistB (0.5);

    // printf("DistA probability %f \n" , DistA.getProbability());
    // printf("DistA probability %f \n" , DistA.p);
    // printf("DistB probability %f \n" , DistB.p);

    // Part 1
    // fn_i(DistA);
    // printf("DistA probability %f \n" , DistA.getProbability());

    // Part 2
    // BernoulliDistributionA* ptr_dista = &DistA;
    // printf("DistA probability %f \n" , ptr_dista->getProbability());
    // fn_ii(ptr_dista);
    // printf("DistA probability %f \n" , ptr_dista->getProbability());

    // Part 3
    // see above

    // Part 4
    // printf("DistB probability %f \n" , DistB.p);
    // fn_iii(DistB);
    // printf("DistB probability %f \n" , DistB.p);

    // Part 5
    // printf("DistB probability %f \n" , DistB.p);
    // fn_v(DistB);
    // printf("DistB probability %f \n" , DistB.p);

}


// void fn_i(BernoulliDistributionA & b);
// void fn_ii(BernoulliDistributionA *& b);
// void fn_iii(const BernoulliDistributionB & b);
// void fn_iv(BernoulliDistributionB & b);
// void fn_v(BernoulliDistributionB b);


// Solutions:
// void fn_i(BernoulliDistributionA & b);: Argument is pass by ref- erence but p is encapsulated and cannot be changed by the interface, therefore object remains unchanged.
// void fn_ii(BernoulliDistributionA *& b);: This is a reference to a pointer! Whilst the pointer can’t be used to change the contents of the object originally pointed-to, the whole pointer can be rewritten since it’s a (non-const) reference. This means that the after the call b could point to a completely different object. So, the original object would remain unchanged, but the calling function could get a completely different object back at the end of the pointer.
// void fn_iii(const BernoulliDistributionB & b);: Since this is a const reference, the contents of b cannot be changed.
// void fn_iv(BernoulliDistributionB & b);: This is a non-const ref- erence. p is public, therefore the function could change p and thus b may be different after the call.
// void fn_v(BernoulliDistributionB b); This is pass by value, so even though the function could alter the value of p (and thus b), the alterations would happen on a copy and thus the original object would remain un- changed.