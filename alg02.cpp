#include <iostream>
#include <string>
#include <vector>

using namespace std;


namespace exchange {

  class Currency {

    public:
    Currency(string nameIn, vector<double> ratesIn) {
      name = nameIn;
      rates = ratesIn;
    }
    string name;
    vector<double> rates;
  };
  vector<double> multiplyVectorBy(vector<double> vec, double d) {
    for(int p = 0; p < vec.size(); p +=1) {
      double val_0 = vec[p];
      double product = val_0 * d;
      vec[p] = product;
    }
    return vec;
  };
  string stringifyDoubleVector(vector<double> vec) {
    string str(vec.begin(), vec.end());
    return str;
  };
};

using namespace exchange;

int main () {

  //Currency CZK("CZK");
  vector<double> sampleVec = {0.5,0.6,1.2};
  sampleVec = multiplyVectorBy(sampleVec, 2.4);
  cout << stringifyDoubleVector(sampleVec);
  return 0;
}
