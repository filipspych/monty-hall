#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cmath>
using namespace std;
int x,a,y,b,u,xc,ac,yc,uc,wc,xuc,auc,wuc;
unsigned long long iuc, ic, f, measurementPeriod, currentWins=0, currentWinsSwitch=0;
double rc,ruc;
int main()
{
    srand(time(0));
    x=rand()%3+1;
    cout<<"Here is how the game work:\n\nYou choose 1st, 2nd, or 3rd door.\n"<<"Your pick is: ";
    cin>>a;
    do
    {
        y=rand()%3+1;
    }
    while((a==y)||(x==y));
    cout<<"Door "<<y<<" opened. Nothing there.\nYou can change your pick.\nIf you want to do it write Y, if no write N: ";
    char b;
    cin>>b;
    if((b=='Y')||(b=='y'))
    {
        do
        {
            u=rand()%3+1;
        }
        while((a==u)||(y==u));
        cout<<"Your new pick is "<<u<<endl;
        if(u==x)
        {
            cout<<"You've won.\n\n";
        }
        else {cout<<"You've lost.\n\n";}
    }
    else
    if(a==x)
    {
        cout<<"You've won.\n\n";
    }
    else {cout<<"You've lost.\n\n";}
    cout<<"Write how many times you want to run the game:";
    cin>>f;
    cout<<"And now we'll run it for "<<f<<" times,\nwhen we always change our pick\nand "<<f<<" times without changing.\n\n";
    ///dodane:
    cout.precision(10);
    cout << "We will count an avarage amount of games won in every period.\nInsert the measurement period (expressed in games)."
    << endl << "Your choice: ";
    cin >> measurementPeriod;
    cout << "Do you want a dynamic UI? (0 - no, 1 - yes)"
    << endl << "Answer: ";
    int dynamicUI;
    cin >> dynamicUI;
    cout << "Let's go:" << endl;

    for(ic=0;ic<f;ic++)
    {
        xc=rand()%3+1;
        ac=rand()%3+1;
        do
        {
            yc=rand()%3+1;
        }
        while((ac==yc)||(xc==yc));
        do
        {
            uc=rand()%3+1;
        }
        while((ac==uc)||(yc==uc));
        if(uc==xc){wc++;currentWinsSwitch++;}

        ///dodane:
        if(ic%measurementPeriod==0 && ic!=0) {
                rc = double(currentWinsSwitch)/(measurementPeriod)*100;
                if(dynamicUI){
                    cout << "Period #" << (ic)/measurementPeriod << " out of " << 2*f/measurementPeriod
                    << " (" << int((double(ic)/2/f*100)) << "%)"<< " | "
                    << "Wins WITH switch in this period: " << rc << "%       "
                    << '\r' << flush;
                } else {
                    cout << "Period #" << (ic)/measurementPeriod << " out of " << 2*f/measurementPeriod
                    << " (" << int((double(ic)/2/f*100)) << "%)"<< " | "
                    << "Wins WITH switch in this period: " << rc << "%       "
                    << endl;
                }

                currentWinsSwitch=0;
        }

    }
    for(iuc=0;iuc<f;iuc++)
    {
        xuc=rand()%3+1;
        auc=rand()%3+1;
        if(auc==xuc){wuc++;currentWins++;}
        ///dodane:
        if(iuc%measurementPeriod==0 && iuc!=0) {
                ruc=double(currentWins)/(measurementPeriod)*100;
                if(dynamicUI){
                    cout << "Period #" << (iuc+ic)/measurementPeriod << " out of " << f/measurementPeriod
                    << " (" << int(double(iuc+ic)/f/2*100) << "%)" << " | "
                    << "Wins WITHOUT switch in this period: " << ruc << "%      "
                    << '\r' << flush;
                    } else {
                        cout << "Period #" << (iuc+ic)/measurementPeriod << " out of " << f/measurementPeriod
                    << " (" << int(double(iuc+ic)/f/2*100) << "%)" << " | "
                    << "Wins WITHOUT switch in this period: " << ruc << "%      "
                    << endl;
                }
                currentWins=0;
        }
    }
    ///dodane:
    cout << endl << "Process completed." << endl << endl;

    rc=double(wc)/f*100;
    ruc=double(wuc)/f*100;
    cout<<"After "<<f<<" attempts with switching you've won total of "<<rc<<"% times.\nAfter "<<f<<" attempts without switching you've won a total of "<<ruc<<"% times.";
}

