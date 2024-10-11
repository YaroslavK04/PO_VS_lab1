
#include "Header.h"
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    ifstream file;
   
    list<string> LIST;

    if (argc == 2) {
 
        file.open(argv[1]);
        if (!file) { cout << "ERROR open file\n"; }
    }
    else {
        file.open("C:\\Fileee\\htm.html");
        if (!file) { cout << "ERROR open file\n"; }
    }

    string perem;
    while (getline(file, perem)) {
        LIST.push_back(perem);
    };

    search(LIST);
  
 
    return 0;
}