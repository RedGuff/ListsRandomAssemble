#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

vector<string> Liste1 ( 0,"" );
vector<string> Liste2 ( 0,"" );
void initListes ( string fileName1 = "", string fileName2 = "" ) { // Ok.
    ifstream file ( fileName1.c_str(), ios::in );

    if ( !file ) {
        cerr << "Impossible to open the file " << fileName1 << endl;
        }
    else {
        string line;

        while ( getline ( file, line ) ) {
            Liste1.push_back ( line );
            }

        file.close();

        ifstream file ( fileName2.c_str(), ios::in );

        if ( !file ) {
            cerr << "Impossible to open the file " << fileName2 << endl;
            }
        else {
            string line;

            while ( getline ( file, line ) ) {
                Liste2.push_back ( line );
                }

            file.close();
            }
        }
    }
void coutListes() { // Ok.

    for ( int a=0; a< Liste1.size() ; a++ ) { // Liste1.size() = Liste2.size()

        cout << Liste1[a] << " " << Liste2[a] << endl;
        }
    }
EgalitarizeLists() { // Ok.
    while ( Liste1.size() <Liste2.size() ) {
        Liste1.push_back ( " " ); // To fill the gaps.
        }

    while ( Liste1.size() >Liste2.size() ) {
        Liste2.push_back ( " " ); // To fill the gaps.
        }

    }

void mixLists() { // Mix Liste2, via une liste temporaire. // Ok.
    vector<string> tempVector ( Liste2.size(), " " );
    tempVector.swap ( Liste2 );

    for ( int a=0; a<Liste2.size(); a++ ) {
        int b = rand() % tempVector.size();
                Liste2[a] = tempVector[b];
//        tempVector[b].delete();
        tempVector.erase(tempVector.begin()+b);
        }
    }

int main() {
    srand ( time ( NULL ) ); // No need for better init.
    initListes ( "List1.txt", "List2.txt" );
    EgalitarizeLists();
    mixLists();
    coutListes();
    return 0;
    }
