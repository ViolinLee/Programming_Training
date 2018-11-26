#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
int main() {
	/*TEST 1*/
	vector<double> deg_C {21.0, 30.5, 0.0, 3.2, 100.0};
    vector<double> deg_F(deg_C.size());
    transform(begin(deg_C), end(deg_C), begin(deg_F),[](double temp){ return 32.0 + 9.0*temp/5.0; });
    for (auto n : deg_F) cout << n << ' '; cout << endl; //Result 69.8 86.9 32 37.76 212
    
    /*TEST 2*/
    std::vector<double> deg_FF; // Empty container
    std::transform(std::begin(deg_C), std::end(deg_C),std::back_inserter(deg_FF),[](double temp){ return 32.0 + 9.0* temp/5.0; });
    for (auto n : deg_Ff) cout << n << ' '; cout << endl; // Result 69.8 86.9 32 37.76 212
	
	/*TEST 3*/
	std::vector<double> temps {21.0, 30.5, 0.0, 3.2, 100.0}; // In Centigrade
    std::transform(std::begin (temps), std::end(temps), std::begin(temps),[](double temp){ return 32.0 + 9.0* temp / 5.0; });
	for (auto n : temps) cout << n << ' '; cout << endl;// Result 69.8 86.9 32 37.76 212
	
	return 0;
}

/* ×¢£º 
1.Óï·¨£º[](double temp){ function(temp); } 

*/ 
