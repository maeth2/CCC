/*
A planetary "rover" is traveling on a perfectly level surface (no obstacles) on Mars. The
rover is in radio communication with the "lander" it arrived in. The lander accumulates and
relays commands, which it receives from Earth, to the rover. The rover makes several
excursions. Each excursion begins with the rover at the lander facing in a known direction.
At the end of each excursion the lander must compute and transmit a sequence of
instructions to return the rover to the lander.
The rover responds to a sequence of commands sent from the lander. Each command tells
the rover to move ahead some multiple of an exact unit of distance, or to turn left or right
exactly 90 degrees.
The "move ahead" command is encoded using two consecutive lines in the input file. The
first line contains the integer 1, and the second line contains a non-negative integer n, the
distance to move forward.
The "turn right" command is encoded using a single input line containing the integer 2.
The "turn left" command is encoded using a single input line containing the integer 3.
For example, the following sequence of commands instructs the rover to turn left, then move
ahead 10 units, then turn right, and then move ahead 5 units.
3
1
10
2
1
5
Your task is, given such a sequence of commands, to determine how far the rover must travel
to return to the lander, and to determine the shortest sequence of commands that will return
the rover to the lander. In the example above, the rover must travel 15 units to return, and the
shortest sequence of commands is
2
1
10
2
1
5
*/
#include <iostream>

using namespace std;
using ll = long long;

int find_shortest_distance(int a, int b){
    int d = b + 4;
    while(d % 4 != a){
        int diff1 = abs(d - a);
        int diff2 = abs(d - (a + 8));
        if(diff1 > diff2){
            d--;
            cout << '3' << "\n";
        }else if(diff2 > diff1){
            d++;
            cout << '2' << "\n";
        }
    }
    return d % 4;
}

int solve(){
    int i = -1;
    int x = 0, y = 0;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 0;

    while(i != 0){
        cin >> i;
        if(i == 1){
            int dist;
            cin >> dist;
            x += dir[d][0] * dist;
            y += dir[d][1] * dist;
        }else if(i == 2){
            d += 1;
            if(d == 4) d = 0;
        }else if(i == 3){
            d -= 1;
            if(d == -1) d = 3;
        }
    }

    cout << "distance is " << abs(x) + abs(y) << "\n";

    cout << "\n";
    
    if(x != 0){
        d = find_shortest_distance((x > 0 ? 3 : 1), d);
        cout << '1' << "\n";
        cout << abs(x) << "\n";
    }
    if(y != 0){
        d = find_shortest_distance((y > 0 ? 2 : 0), d);
        cout << '1' << "\n";
        cout << abs(y) << "\n";
    }    
}

int main(void){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}