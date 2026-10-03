#include <iostream> 
#include <vector>
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

int main(){
auto inputs = generateInputs(2);

for (auto row : inputs) {
    for (int value : row) {
        cout << value << " ";
    }
    cout << endl;
}
return 0;
}


