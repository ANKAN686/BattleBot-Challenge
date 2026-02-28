#include <bits/stdc++.h>
using namespace std;

struct Player {
    int id;
    string name;
    int water_req;
    int salary;
    int health;
    int balance;
    int no_water_days;
};
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distr(1, 10);

int main() {
    // Round 0: Initialization
    int my_player_id;
    cin >> my_player_id;
    
    vector<Player> players(5);
    for (int i = 0; i < 5; i++) {
        cin >> players[i].id >> players[i].name 
            >> players[i].water_req >> players[i].salary;
    }
    // Main game loop
    for (int round = 1; round <= 20; round++) {
        int water_supply;
        cin >> round >> water_supply;
        
        // Read player statuses
        for (int i = 0; i < 5; i++) {
            cin >> players[i].id >> players[i].health 
                >> players[i].balance >> players[i].no_water_days;
        }
        // Read previous bids (from round 2 onwards)
        int sum_bids=0;
        int prev_avg_bids=0;
        if (round >= 2) {
            vector<int> prev_bids(5);
            vector<int> water_reqs(5);
            for (int i = 0; i < 5; i++) {
                int pid;
                cin >> pid >> prev_bids[i] >> water_reqs[i];
                sum_bids+=prev_bids[i];
            }
        }
        
        int my_bid = 0;
        double bid = 0;
        prev_avg_bids = sum_bids/5;

        Player me;
        for (const auto &p : players)
        {
            if (p.id == my_player_id)
            {
                me = p;
                break;
            }
        }
        if(me.id==1 or me.id==2)
        {
        if(round==1)
        {
            bid= 0.75*me.balance;
        }
        // main crux is if no_water_days 
        else if (round>=2 and round<=8)
        {
            if(me.health>7)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance , 0.5*me.salary + distr(gen));
                }
                else 
                {
                    if(distr(gen)%2==0)
                    {
                        bid = min((double)me.balance, 0.4*(double)me.balance + distr(gen));
                    }
                    else
                    {
                        bid = min((double)me.balance, 0.6*(double)me.balance + distr(gen));
                    }
                }
            }
            else if(me.health>=5 and me.health<=7)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance,0.5* me.salary + distr(gen));
                }
                else if(me.no_water_days==1)
                {
                    bid=min((double)me.balance,distr(gen) + max(0.5*(double)me.balance , 1.5 * prev_avg_bids) );
                }
                else if(me.no_water_days==2)
                {
                    bid=min((double)me.balance,distr(gen) + max(0.75*(double)me.balance, 1.75*prev_avg_bids));  
                }
                else
                {
                    bid = (double)me.balance;
                }
            }
            else if(me.health>=3 and me.health<=5)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance, 0.5*(double)me.balance + distr(gen));
                }
                else if(me.no_water_days==1)
                {
                    bid = min((double)me.balance, distr(gen) + max(0.75*(double)me.balance,1.5*prev_avg_bids));
                }
                else
                {
                    bid = (double)me.balance;
                }
            }
            else
            {
                bid = (double)me.balance;
            }
        }
        else if(round>=9 and round<=16)
        {
            if(me.health>7)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance , 0.5*me.salary + distr(gen));
                }
                else 
                {
                    if(distr(gen)%2==0)
                    {
                        bid = min((double)me.balance, 0.5*(double)me.balance + distr(gen));
                    }
                    else
                    {
                        bid = min((double)me.balance, 0.7*(double)me.balance + distr(gen));
                    }
                }
            }
            else if(me.health>=5 and me.health<=7)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance,0.5* me.salary + distr(gen));
                }
                else if(me.no_water_days==1)
                {
                    bid=min((double)me.balance,distr(gen) + max(0.6*(double)me.balance , 1.6 * prev_avg_bids) );
                }
                else if(me.no_water_days==2)
                {
                    bid=min((double)me.balance,distr(gen) + max(0.85*(double)me.balance, 1.85*prev_avg_bids));  
                }
                else
                {
                    bid = (double)me.balance;
                }
            }
            else if(me.health>=3 and me.health<=5)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance, 0.5*(double)me.balance + distr(gen));
                }
                else if(me.no_water_days==1)
                {
                    bid = min((double)me.balance, distr(gen) + max(0.85*(double)me.balance,1.6*prev_avg_bids));
                }
                else
                {
                    bid = (double)me.balance;
                }
            }
            else
            {
                bid = (double)me.balance;
            }
        }
        else if(round>=17 and round<=18)
        {
            bid = 0.8*(double)me.balance;
        }
        else
        {
            bid = (double)me.balance;
        }
        }

        // Strategy for C,D,E
        else
        {
            if(round==1)
        {
            bid= 0.75*me.balance;
        }
        // main crux is if no_water_days 
        else if (round>=2 and round<=8)
        {
            if(me.health>7)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance , 0.5*me.salary + distr(gen));
                }
                else 
                {
                    if(distr(gen)%2==0)
                    {
                        bid = min((double)me.balance, 0.4*(double)me.balance + distr(gen));
                    }
                    else
                    {
                        bid = min((double)me.balance, 0.6*(double)me.balance + distr(gen));
                    }
                }
            }
            else if(me.health>=5 and me.health<=7)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance,0.5* me.salary + distr(gen));
                }
                else if(me.no_water_days==1)
                {
                    bid=min((double)me.balance,distr(gen) + max(0.5*(double)me.balance , 1.5 * prev_avg_bids) );
                }
                else if(me.no_water_days==2)
                {
                    bid=min((double)me.balance,distr(gen) + max(0.75*(double)me.balance, 1.75*prev_avg_bids));  
                }
                else
                {
                    bid = (double)me.balance;
                }
            }
            else if(me.health>=3 and me.health<=5)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance, 0.5*(double)me.balance + distr(gen));
                }
                else if(me.no_water_days==1)
                {
                    bid = min((double)me.balance, distr(gen) + max(0.75*(double)me.balance,1.5*prev_avg_bids));
                }
                else
                {
                    bid = (double)me.balance;
                }
            }
            else
            {
                bid = (double)me.balance;
            }
        }
        else if(round>=9 and round<=16)
        {
            if(me.health>7)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance , 0.5*me.salary + distr(gen));
                }
                else 
                {
                    if(distr(gen)%2==0)
                    {
                        bid = min((double)me.balance, 0.5*(double)me.balance + distr(gen));
                    }
                    else
                    {
                        bid = min((double)me.balance, 0.7*(double)me.balance + distr(gen));
                    }
                }
            }
            else if(me.health>=5 and me.health<=7)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance,0.5* me.salary + distr(gen));
                }
                else if(me.no_water_days==1)
                {
                    bid=min((double)me.balance,distr(gen) + max(0.6*(double)me.balance , 1.6 * prev_avg_bids) );
                }
                else if(me.no_water_days==2)
                {
                    bid=min((double)me.balance,distr(gen) + max(0.85*(double)me.balance, 1.85*prev_avg_bids));  
                }
                else
                {
                    bid = (double)me.balance;
                }
            }
            else if(me.health>=3 and me.health<=5)
            {
                if(me.no_water_days==0)
                {
                    bid = min((double)me.balance, 0.5*(double)me.balance + distr(gen));
                }
                else if(me.no_water_days==1)
                {
                    bid = min((double)me.balance, distr(gen) + max(0.85*(double)me.balance,1.6*prev_avg_bids));
                }
                else
                {
                    bid = (double)me.balance;
                }
            }
            else
            {
                bid = (double)me.balance;
            }
        }
        else if(round>=17 and round<=18)
        {
            bid = 0.8*(double)me.balance;
        }
        else
        {
            bid = (double)me.balance;
        }
        }
        // Output bid
        my_bid = (int)bid;
        cout << my_bid << endl;
        cout.flush(); 
    }
    
    return 0;
}
