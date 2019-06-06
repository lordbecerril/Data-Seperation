#include<iostream>
#include<string>
#include<fstream>
using namespace std;


int main()
{
  ifstream infile;
  string holster;
  ofstream outfile;
  int c = 1;
  infile.open("SC_Volume_Data_R11_2014.csv");
  outfile.open("f.txt");
  getline(infile, holster);

  int len = holster.size();

  string dummy = "";
  char d;

  for(int i = 0; i < len; i++){
    d = holster[i];
    if(d != ','){
      if(d !=' ')
        dummy = dummy + d;
    }
    else{
      cout << "Column " << c << " is " << dummy << ". ";
      outfile << "Column " << c << " is " << dummy << ". "; // Check f.txt for the formatted csv row
      dummy = "";
      c++;
    }
  }

  return 0;
}
