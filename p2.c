#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>


long long solve (int N, int start, int finish, int* Ticket_cost){
    start--;
    finish--;
    //clockwise cost
    long long cw_cost=0;
    int i=start;
    while(i!=finish)
    {
        cw_cost += Ticket_cost[i];
        i=(i+1)%N;
    }
    //anticlockwise
    long long acw_cost=0;
    i=start;
    while(i!=finish)
    {
        i=(i-1+N)%N;
        acw_cost +=Ticket_cost[i];
    }
    return(cw_cost < acw_cost) ? cw_cost : acw_cost;
}

int main() {
    int N;
    scanf("%d", &N);
    int start;
    scanf("%d", &start);
    int finish;
    scanf("%d", &finish);
    int i_Ticket_cost;
    int *Ticket_cost = (int *)malloc(sizeof(int)*(N));
    for(i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    	scanf("%d", &Ticket_cost[i_Ticket_cost]);

    long long out_ = solve(N, start, finish, Ticket_cost);
    printf("%lld", out_);
}
