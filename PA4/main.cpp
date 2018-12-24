#include "header.h"

int main(int argc, char *argv[]) {
    // This code is not a complete test code (won't even compile) and it may be syntactically inconsistent with your class definitions.
    // So modify before use as appropriate. But the idea of testing should be clear. You are free to shuffle around the order of operations in order to devise more test cases of your own.

    Board B(1000000); // specifies that the game board size is 1000000 x 1000000

    // the following is a sequence of calls to Board class methods assuming
    // 	the input example (m=10,n=8) given in the programming assignment.

    B.Insert(1, 3, 2); // assumed syntax: Insert(ID, x, y)
    B.Insert(2, 4, 3);
    B.Insert(3, 4, 6);
    B.Insert(4, 5, 7);
    B.Insert(5, 6, 3);
    B.Insert(6, 8, 2);
    B.Insert(7, 9, 3);
    B.Insert(8, 9, 8);

    B.Insert(3, 7, 6); // should fail because player 3 is already there

    B.Insert(10, 9, 8); // should fail because 9,8 is occupied already

    B.MoveTo(4, 9, 3); //assumed syntax: MoveTo(ID,x,y) // removes 7 in the process    
    B.PrintByID();
    cout << endl;

    B.MoveTo(4, 9, 8); // removes 8
    B.PrintByID();
    cout << endl;

    B.MoveTo(4, 6, 3); // should fail because move to 6,3 is from 4's current position is not valid
    B.PrintByID();
    cout << endl;

    B.MoveTo(2, 3, 3);
    B.PrintByID();
    cout << endl;

    B.MoveTo(4, 3, 2); // removes 1
    B.PrintByID();
    cout << endl;

    B.MoveTo(4, 8, 2); // removes 6
    B.PrintByID();
    cout << endl;

    B.MoveTo(5, 3, 3); // removes 2
    B.PrintByID();
    cout << endl;

    B.MoveTo(4, 4, 6); // removes 3
    B.PrintByID();
    cout << endl;

    B.MoveTo(5, 4, 3);
    B.PrintByID();
    cout << endl;

    B.MoveTo(4, 4, 3); // removes 5
    B.PrintByID();
    cout << endl;
    
    // the code should print only one player at this stage which is player 4 @ (4,3)
}