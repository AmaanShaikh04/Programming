#include<iostream>
using namespace std;

class graph{
    int cost[10][10];
    int cities;

    public:
        graph(){
            int i,j;
            cities=0;
            cout<<"Enter the number of cities - ";
            cin >> cities;
            for (i=0;i<cities;i++){
                for(j=0;j<cities;j++){
                    cost[i][j]=999;
                }
            }
        }

        void create();
        void display();
        int prims(int v);
};

void graph :: create(){
    cout<<"\nNote : If there is no edge between cities enter (999)\n";
    int i,j;
    for (i=0;i<cities;i++){
        for(j=i+1;j<cities;j++){
            cout<<"Enter the cost between (city " << i << " - city " << j<< ") : ";
            cin>>cost[i][j];
            cost[j][i]=cost[i][j];
        }
    }
}

void graph :: display(){
    int i,j;
    cout<<"\nThe Cost Matrix is : \n";
    for (i=0;i<cities;i++){
        for(j=0;j<cities;j++){
            cout<< cost[i][j] << "\t";
            }
        cout<<endl;
    }
}

int graph :: prims(int v){
    int i,j,k,r=0;
    int t[cities-1][3];
    int mincost=0;
    int nearest[cities];
    nearest[v]=-1;
    for (int i=0;i<(cities);i++){
        if(i!=v){
            nearest[i]=v;
        }
    }

    for (int i=1;i<(cities);i++){
        int min=999;
        for(k=0;k<(cities);k++){
            if(nearest[k] != -1 && cost[k][nearest[k]] < min ){
                j=k;
                min=cost[k][nearest[k]];
            }
        }
        t[r][0]=j;
        t[r][1]=nearest[j];
        t[r][2]=cost[j][nearest[j]];
        r=r+1;
        mincost=mincost + cost[j][nearest[k]];
        nearest[j]=-1;

        for(k=0;k<(cities);k++){
            if(nearest[k] != -1 && cost[k][nearest[k]]>cost[k][j])
                nearest[k]=j;
        }
    }

    cout<<"\nThe Mincost array is : \n";
    for (i=0;i<(cities-1);i++){
        for(j=0;j<3;j++){
            cout<< t[i][j] << "\t";
            }
        cout<<endl;
    }
    return mincost;
}

int main(){
    int v,mincost;
    graph g;
    g.create();
    g.display();
    cout<<"\nEnter the starting city number : ";
    cin>> v;
    mincost = g.prims(v);
    cout<<"The cost of the minimum spanning tree is : " << mincost;
}

