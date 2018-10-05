/*Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.

Input Format

The first line of input consists of an integer N that represents total number of trains.

The next N lines contain arrival Ta[i] and departure Td[i] time for each train. Time will be given given in 24H format and colons will be omitted for convinience. For ex.: 9:05AM will be given as "905", or 9:10PM will be given as "2110"

Constrains:

0 < N < 1000

0000 < T[a] < T[d] < 2359

Output Format

Output integer value of the minimum required platforms.

Sample Input

3

900 920

910 950

940 1000

Sample Output

2
*/

// Implementer: Jatin Kumar

#include<iostream>
#include<algorithm>
using namespace std;
struct timeofTrain
{
    int t;
    int type;
};
bool howtosort(timeofTrain t1,timeofTrain t2)
{
    
    return t1.t<t2.t;
}
int main()
{
    	int trains,platform,standing,size;
        platform=0;
        standing=0;
        cin>>trains;
        struct timeofTrain timet[trains*2];
        for(int i=0;i<trains*2;i++)
        {    
            cin>>timet[i].t;
            if(i%2==0)
            {
                timet[i].type=0;
            }
            else
            {
                timet[i].type=1;
            }
        }
        size=sizeof(timet)/(sizeof(timet[0]));
        sort(timet,timet+size,howtosort);
        for(int i=0;i<trains*2;i++)
        {
            
            if(timet[i].type==0)
            {
                standing++;
            }
            else
            {
                standing--;
            }
            if(standing>platform)
            {
                platform=standing;
            }
        }
        cout<<platform<<endl;
}
