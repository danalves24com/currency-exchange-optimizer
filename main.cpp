#include <iostream>
#include "course.h"
#include <string>
#include <vector>
using namespace std;


namespace exop {

  enum Currencies {CZK, EUR, USD, GBP, YEN};

  class Currency {
    public:
    Currency(string namePass, double rtczk, double rteur, double rtusd, double rtpound, double rtyen) {
      name = namePass;
      rateToCZK = rtczk;
      rateToEuro = rteur;
      rateToUSD = rtusd;
      rateToPound = rtpound;
      rateToYen = rtyen;
      rateVector = {rateToCZK, rateToEuro, rateToUSD, rateToPound, rateToYen};
    }
    string name;
    double rateToCZK, rateToEuro, rateToUSD, rateToPound, rateToYen;
    vector<double> rateVector;
    };
  class CurrencyConverter {

    public:
    double convert(Currency sourceCurrency, Currencies targetCurrency, double value) {
      double rate = sourceCurrency.rateVector[targetCurrency];
      return rate * value;
    };

  };
  class currencyOptimizer {
    public:
    void search(Currency c) {
      double amt = 100.0, maxAmt = -1;
      CurrencyConverter cc;
      int size = (c.rateVector).size(), maxIndex = -1;
      for(int subCurrency = 0 ; subCurrency < size ; subCurrency +=1 ) {
        double conversionResult = cc.convert(c, static_cast<Currencies>(subCurrency), amt);
        if(conversionResult > maxAmt) {
          maxIndex = subCurrency;
          maxAmt = conversionResult;
        }
      }
      cout << static_cast<Currencies>(maxIndex) << endl;
    };
  };
};
using namespace exop;


int main () {
  CurrencyConverter cc;
  currencyOptimizer co;
  Currency USD("USD", 21.76, 0.85, 1, 0.72, 109.69);
  vector<Currency> currencyList = {USD};
  for(int c = 0 ; c < 1 ; c +=1 ) {
    Currency c_c = currencyList[c];
    co.search(c_c);
  }
  return 0;
}



