/*
 * seqdriver.cc
 *
 * test class sequence.
 */
#include <iostream>
#include "sequence.h"
using namespace std;

int main() {
  string inbuf, where;
  int wh;
  Sequence items( "test.dat" );
  while ( true ) {
    cout << endl << "Sequence output: " << endl;
    items.output();
    cout << endl << "1 -- add" << endl;
    cout << "2 -- delete" << endl;
    cout << "3 -- quit" << endl;
    getline( cin, inbuf );
    if ( inbuf == "1" ) {
      cout << endl << "item to add: ";
      getline( cin, inbuf );
      cout << "add where? ";
      getline( cin, where );
      wh = atoi( where.c_str() );
      if ( items.addItem( wh, inbuf ) ) {
	cout << "item added" << endl;
      } else {
	cout << "item not added" << endl;
      }
    } else if ( inbuf == "2" ) {
      cout << endl << "which to delete: ";
      getline( cin, where );
      wh = atoi( where.c_str() );
      if ( items.deleteItem( wh ) ) {
	cout << "item deleted" << endl;
      } else {
	cout << "item not deleted" << endl;
      }
    } else if ( inbuf == "3" ) {
      break;
    }
  }
  return 0;
}
