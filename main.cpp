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
};
using namespace exop;
int main () {
  CurrencyConverter cc;
  Currency USD("USD", 21.3, 0.4, 1, 0.9, 0.8);
  double cc01 = cc.convert(USD, Currencies::CZK, 3);
  cout << cc01 << endl;
  return 0;
}



