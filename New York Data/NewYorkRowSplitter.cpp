#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void maker2014(string, string, string, ofstream&, ofstream&,ofstream&,ofstream&,ofstream& );

int main()
{
  ifstream infile;
  string holster,top;
  int c = 0;
  string dummy = "";
  infile.open("Traffic_Volume_Counts__2014-2018_.csv");

  ofstream twenty14;
  ofstream twenty15;
  ofstream twenty16;
  ofstream twenty17;
  ofstream twenty18;

  twenty14.open("NewYork2014.csv");
  twenty15.open("NewYork2015.csv");
  twenty16.open("NewYork2016.csv");
  twenty17.open("NewYork2017.csv");
  twenty18.open("NewYork2018.csv");

  getline(infile, top);

  cout << top << endl;

  twenty14 << top << endl;
  twenty15 << top << endl;
  twenty16 << top << endl;
  twenty17 << top << endl;
  twenty18 << top << endl;


  getline(infile, holster);

  int len = holster.size();
  cout << "length is " << len << endl;
  char d, d1;
  while(infile)
  {
    for(int i = 0; i < len; i++){
      d = holster[i];
      if(d == ','){
        c ++;
        if(c == 6){
          for(int j = i+1; j < len;j++){
            d1 = holster[j];
            if(d1 == ',')
              break;
            else
              dummy += d1;
          }
          cout << dummy << endl;
          maker2014(dummy, top, holster, twenty14, twenty15, twenty16, twenty17, twenty18);
        }
      }

    }
    c = 0;
    dummy = "";

    getline(infile, holster);

    int len = holster.size();
  }

  return 0;
}

void maker2014(string d, string t, string h,ofstream& twenty14,ofstream& twenty15,ofstream& twenty16,ofstream& twenty17,ofstream& twenty18){
  int len = d.size();
  char dd;
  int ccc = 0;
  bool f = false;
  string year = "";

  for(int i = 0; i < len; i++){
    dd = d[i];
    if(f == true){
      year += dd;
    }
    if(dd == '/'){
      ccc++;
      if(ccc == 2)
        f = true;
    }

  }
  //cout << year << endl;

  if(year == "2014"){
    twenty14 << h << endl;
  }
  if(year == "2015"){
    twenty15 << h << endl;
  }
  if(year == "2016"){
    twenty16 << h << endl;
  }
  if(year == "2017"){
    twenty17 << h << endl;
  }
  if(year == "2018"){
    twenty18 << h << endl;
  }

}
