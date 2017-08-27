#include <iostream>

using namespace std;

int main()
{
    // ARRIBA 94
    // DERECHA 62
    // ABAJO 118
    // IZQUIERDA 60
    char ini, fin;
    int seconds;
    cin >> ini >> fin >> seconds;
    if(seconds%4 != 3 && seconds%4 != 1)
    {
        cout << "undefined\n";
        return 0;
    }
    if(ini == 94 && fin == 62 && seconds%4 == 3)
        cout << "ccw\n";
    else if(ini == 94 && fin == 62 && seconds%4 == 1)
        cout << "cw\n";
    else if(ini == 62 && fin == 94 && seconds%4 == 1)
        cout << "ccw\n";
    else if(ini == 62 && fin == 94 && seconds%4 == 3)
        cout << "cw\n";
    else if(ini == 94 && fin == 60 && seconds%4 == 3)
        cout << "cw\n";
    else if(ini == 94 && fin == 60 && seconds%4 == 1)
        cout << "ccw\n";
    else if(ini == 60 && fin == 94 && seconds%4 == 1)
        cout << "cw\n";
    else if(ini == 60 && fin == 94 && seconds%4 == 3)
        cout << "ccw\n";
    else if(ini == 94 && fin == 118)
        cout << "undefined\n";
    else if(ini == 60 && fin == 62)
        cout << "undefined\n";
    if(ini == 118 && fin == 62 && seconds%4 == 1)
        cout << "ccw\n";
    else if(ini == 118 && fin == 62 && seconds%4 == 3)
        cout << "cw\n";
    else if(ini == 62 && fin == 118 && seconds%4 == 1)
        cout << "cw\n";
    else if(ini == 62 && fin == 118 && seconds%4 == 3)
        cout << "ccw\n";
    else if(ini == 118 && fin == 60 && seconds%4 == 3)
        cout << "ccw\n";
    else if(ini == 118 && fin == 60 && seconds%4 == 1)
        cout << "cw\n";
    else if(ini == 60 && fin == 118 && seconds%4 == 1)
        cout << "ccw\n";
    else if(ini == 60 && fin == 118 && seconds%4 == 3)
        cout << "cw\n";

    return 0;
}
