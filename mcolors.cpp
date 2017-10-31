/********************************
* use m colors for map coloring *
* date: 20171031                *
* author: sunqixin              *
*********************************/

#include <iostream>
#define n 5
using namespace std;
static int sum = 0;
int m = 3;
int map[n+1][n+1];
int x[n+1];
bool OK(int t)  //constraint function
{
    for(int i=1; i<t; i++)  // we checked the color of the front t-1 points , if the color of one of them is the same as t point and it is neighboring to t, the function return false, else show each point neighbor to t get different color for t;
    {
        if(map[t][i])
        {
            if(x[i]==x[t])
                return false;
        }
    }
    return true;
}

void backTrace(int t)
{
    if(t>n)  // we get a new solution
    {
        sum++;
        cout << "the " << sum << "th solution" << endl;
        for(int i=1; i<n+1; i++)
            cout << x[i] << " ";
        cout << endl << endl;
    }
    else
    {
        for(int i=1; i<=m; i++)
        {  // try the each color, we total have m colors
            x[t]=i;
            if(OK(t))  // if the color of t point is not conflicting to the front point, we explore the color of next point
                backTrace(t+1);
        }
    }
}
int main()
{
    int temp1, temp2, temp3;
    cin >> temp1;
    for(int i=0; i<temp1; i++)
    {
        cin >> temp2 >> temp3;
        map[temp2][temp3] = map[temp3][temp2] = 1;
    }

    backTrace(1);
    //cout << "Hello world!" << endl;
    return 0;
}

/*  the following data is the edges in the map, values which is corresponding with these point will be set to 1.
7
1 2
1 3
2 3
2 4
2 5
3 4
4 5
 */

