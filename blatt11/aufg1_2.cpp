// Sämtliche Include-Makros fehlen
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <ext/functional>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::equal_to;
using std::remove_if;
using std::bind2nd;
using std::modulus;
using std::copy;
using __gnu_cxx::compose1;

int main()
{
  vector<int> v;    // Ein Vektor mit 6 unterschiedlichen Ganzzahlen wird 
  v.push_back(1);   // konstruiert.
  v.push_back(4);
  v.push_back(2);
  v.push_back(8);
  v.push_back(5);
  v.push_back(7);
  
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;     // Der ganze Vektor wird in den Standard Ausgabestrom 
                    // kopiert.
  
  vector<int>::iterator new_end = 
    remove_if(v.begin(), v.end(), 
              compose1(bind2nd(equal_to<int>(), 0),
                       bind2nd(modulus<int>(), 2)));
                    // Es sollen alle geraden Zahlen aus dem Vektor gelöscht
                    // werden. 
  
  // remove_if kann nicht die länge des Arrays verändern. Dafür 
  // signalisiert die funktion die neue Länge durch den zurück-
  // gegebenen Iterator.
  copy(v.begin(), new_end, ostream_iterator<int>(cout, " "));
  cout << endl;     // Wiederrum wird der Inhalt des Vektors ausgegeben.
}
