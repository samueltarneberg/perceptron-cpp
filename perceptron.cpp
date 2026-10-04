#include <iostream> 
#include <vector>
#include <random>
using namespace std;


vector<vector<int>> generateInputs(int n){
    vector<vector<int>> inputs = {{}};
    for (int i = 0; i < n ; i++){
        vector<vector<int>> newInputs;
            for (vector<int> newVector : inputs){
                newVector.push_back(0);
                newInputs.push_back(newVector);

                newVector.back() = 1;
                newInputs.push_back(newVector);
            }
            inputs = newInputs;
    }
    return inputs;
}

vector<vector<int>> generateBooleanFunctions(int n){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0,1);

    int nInputs = pow(2, n);
    if (n <= 3){
        vector<vector<int>> functions = {{}};
        for (int i = 0 ; i < nInputs ; i++){
            vector<vector<int>> newFunctions;
            for (vector<int> function : functions){
                function.push_back(-1);
                newFunctions.push_back(function);

                function.back() = 1;
                newFunctions.push_back(function);
            }
            functions = newFunctions;
        }
        return functions;
    }
    else {
        vector<vector<int>> functions;
        for (int i = 0; i < 10000 ; i++){
            vector<int> function;
            for (int j = 0 ; j < nInputs ; j++){
                int randomValue = distribution(gen);
                
                if (randomValue == 0){
                    randomValue = -1;
                }
                
                function.push_back(randomValue);

            }
            functions.push_back(function);
        }
        return functions;
    }
}


int main(){
    auto functions = generateBooleanFunctions(4);




    for (auto row : functions) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    cout << "Number of functions: " << functions.size() << endl;
    cout << "Length of first function: " << functions[0].size() << endl;
return 0;
}


