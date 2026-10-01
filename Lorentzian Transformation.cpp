#include <iostream>
#include <cmath>
#include <vector> 

std::vector<double> Lorentzian(double v, const std::vector<double>& input) {
    
    double c = 3.0e8;
    double beta = v / c;
    
   
    double gamma = 1.0 / std::sqrt(1.0 - beta * beta); 
    
   
    double M[4][4] = {
        { gamma,            0.0, 0.0, -gamma * v        },
        { 0.0,              1.0, 0.0,  0.0              },
        { 0.0,              0.0, 1.0,  0.0              },
        { -gamma * beta / c, 0.0, 0.0,  gamma            }
    };

    std::vector<double> result(4, 0.0);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i] += M[i][j] * input[j];
        }
    }

    return result;
}

int main() {
    std::vector<double> point = {100.0, 50.0, 10.0, 2.0}; 
    double v = 2.25e8; 

    std::vector<double> res = Lorentzian(v, point);

    std::cout << "Lorentzian Transformation:\n";
    std::cout << "x' = " << res[0] << "\ny' = " << res[1] 
              << "\nz' = " << res[2] << "\nt' = " << res[3] << "\n";

    return 0;
}