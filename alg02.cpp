#include <iostream>
#include <string>
#include <vector>

using namespace std;


namespace exchange {


  enum Currencies { USD, CZK, JPY };

  class Currency {

    public:
    Currency(Currencies nameIn, vector<double> ratesIn) {
      name = nameIn;
      rates = ratesIn;
    }
    Currencies name;
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

  double convert(vector<Currency> map, Currencies Source, Currencies Target, double value) {
    Currency sourceCurrency = map[Source], targetCurrency = map[Target];
    return sourceCurrency.rates[Target] * value;
  };

};

using namespace exchange;



int main () {


  vector<double> USDrates = {1, 21.72, 110.03}
    , CZKrates = {0.047, 1, 5.07}
    , JPYrates = {0.0091, 0.20, 1};

  Currency USD(Currencies::USD, USDrates)
    , CZK(Currencies::CZK, CZKrates)
    , JPY(Currencies::JPY, JPYrates);


  Currency &baseCurrency = CZK;
  vector<Currency> currencyVector = {USD, CZK, JPY};


  double result = convert(currencyVector, Currencies::USD, Currencies::CZK, 3);

  cout << result;

  return 0;
}
