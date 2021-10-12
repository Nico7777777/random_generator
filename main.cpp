#include<iostream>
#include<ctime>
using namespace std;

int manual_seed_rand(int x){
    long long result = (12413*x + 53549)%RAND_MAX;
    /*  RAND_MAX is a constant value; RAND_MAX = 32767
        the range [0, 32767] matches exactly 2 bytes, which means
        that every value returned by rand() can be stored in a short int variable
    */
   return result;
}

int main(){
    srand( time(NULL) );
    /*time() is a function established in ctime library and it aids amazingly because it counts all the seconds 
    since 1.01.1970, 00:00:00(when the function was invented), a huge value, but more important always increasing. 
    Thus, time(NULL) is the best seed
    */   
    
    // now every time you call rand(), you will be given another number between [0, 32767]
    
    /*
        srand() is equivalent to manual_seed_rand(), but much more complex, to simulate a random number,
        but it's based on a formula, which is why it is called pseudorandomisation

        P.S. C++ is a language whose random function is not very smart built comparing to nowadays demandinds, but still it works with no problem
    */



    //THE CODE ABOVE IS MEANT FOR INTEGERS ONLY( numbers from Z )
   int minimum_z, maximum_z, numbers_of_values_generated_z, x;
   cin >> minimum_z >> maximum_z >> numbers_of_values_generated_z;

    for(int i=1; i<=numbers_of_values_generated_z; i++){
        x = minimum_z + rand()%(maximum_z-minimum_z+1);
        /*  case in point if we want natural numbers from the interval I = [3, 9],
            the rand()%(9 - 3 + 1) will generate numbers from the interval II = [0, 7) => II = [0, 6].
            If we permanently assure to add the minimum value of the interval to x variable, the range of values will
            hold therefore the given interval S =[3, 9], or analitically s=[minimum, maximum]
        */
       /*   TIPS: for a huger range of values, we can let a variable be rand()^n. 
            Example1: x = rand()*rand()    ->     the values will spread between [0, 32767^2] => [0, 1 073 676 289]
            Example2: x = rand()*rand()*rand() -> the values will spread between [0, 32767^3] => [0, 35 181 150 961 663]
       */ 
        cout<<x<<' ';
    }
    cout<<"\n\n\n";



    //THE CODE ABOVE IS MEANT FOR EXCLUSIVELY RATIONAL NUMBERS( numbers from Q, which are not in Z ~ Q-Z )
    double minimum_q, maximum_q, numbers_of_values_generated_q, q;
    cin >> minimum_q >> maximum_q >> numbers_of_values_generated_q;

    for(int i=1; i<=numbers_of_values_generated_q; i++){
        q = minimum_q + ((double)rand() / RAND_MAX) * (maximum_q - minimum_q);
        /*  taking into consideration the interval [2.5, 4.7], we have minimum = 2.5,
            rand()/RAND_MAX is a subunit franction, or in the luckiest case it holds 1
            Example1: rand() takes the value 32767 => rand()/RAND_MAX = 1. Thus q equals 2.5 + (4.7 - 2.5) => q = 2.5 + 2.2 => q = 4.7(the maximum limit of the interval)
            Example2: rand() takes the value 0 => rand()/RAND_MAX = 0. Thus, q equals 2.5 + 0 => q = 2.5(the minimum limit of the interval)
        */
       cout<<q<<' ';
    }
}