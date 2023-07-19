/*
 This code is based on the algorithm specified on the following web side:
 


*/
#include <iostream>

struct State
{
    int current_state [3][3];
    int previous_state [3][3];
    int moves;
    int x, y; // position of x
};

struct Pqueue
{
    State *state;
    int index;
    int priority;
};

void init_Pqueue(Pqueue&);
void enqueue(Pqueue&);
void dequeue(Pqueue&);
int hamming_priority(const State&);

void initialise_state(State&);
void null_state(int [3][3]);
void init_goal_state(int [3][3]);
void print_state(int [3][3]);
bool compare_states(int [3][3], int [3][3]);
bool legal_move(State);
void swap(int&, int&);
bool move_left(State);
bool move_right(State);
bool move_down(State);
bool move_up(State);

int main()
{
    State state;
    initialise_state(state);

    Pqueue queue;
    init_Pqueue(queue);
     
    int goal_state[3][3];
    init_goal_state(goal_state);

    std::cout << "Enter the start state: " << std::endl;
    std::cout << " e.g. (0 is empty state)" << std::endl;
    std::cout << " 2 1 3" << std::endl;
    std::cout << " 4 0 5" << std::endl;
    std::cout << " 7 8 6" << std::endl;
    
    int i = 0, j = 0; 
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            std::cin >> state.current_state[i][j];
        }
    }
     
    //std::cout << "moves: " << state.moves << std::endl;
    //std::cout << "priority: " << hamming_priority(state) << std::endl;

    if(compare_states(state.current_state, goal_state))
    {
        std::cout << "Goal state is same as initial state:" << std::endl;
        print_state(goal_state); 
        return 0; // exit with success status
    }
    //print_state(state.current_state);
    //print_state(goal_state);
    while(0){
       /*
        * Traverse multiple states 
        * Until goal state is reached, then exit
        * 1. 
        */ 
        
        
    }
    print_state(state.current_state);

    return 0;
}

void init_Pqueue(Pqueue& queue)
{
    queue.index = 0;
    queue.priority = 0;
}

void enqueue(Pqueue& queue)
{
    queue.index++;
    queue.state = new State[queue.index];
}

void dequeue(Pqueue&)
{

}

int hamming_priority(const State& state)
{
    int temp = 0;
    if(state.current_state[0][0] != 1){
        temp++;
    }
    if(state.current_state[0][1] != 2){
        temp++;
    }
    if(state.current_state[0][2] != 3){
        temp++;
    }
    if(state.current_state[1][0] != 4){
        temp++;
    }
    if(state.current_state[1][1] != 5){
        temp++;
    }
    if(state.current_state[1][2] != 6){
        temp++;
    }
    if(state.current_state[2][0] != 7){
        temp++;
    }
    if(state.current_state[2][1] != 8){
        temp++;
    }

    temp = temp + state.moves;
    return temp;
}

void initialise_state(State& state)
{
    int i = 0, j = 0;
    int temp = 1;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(i == 0 && j == 0){
                state.current_state[0][0] = 'x';
            }
            state.current_state[i][j] = temp;
        }
    }
    null_state(state.previous_state);
    state.x = 0, state.y = 0, state.moves = 0;
}

void init_goal_state(int goal_state[3][3])
{
    goal_state[0][0] = '1';
    goal_state[0][1] = '2';
    goal_state[0][2] = '3';
    goal_state[1][0] = '4';
    goal_state[1][1] = '5';
    goal_state[1][2] = '6';
    goal_state[2][0] = '7';
    goal_state[2][1] = '8';
    goal_state[2][2] = 'x';
}

void null_state(int state[3][3])
{
    int i = 0, j = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            state[i][j] = ' ';
        }
    }
}

void print_state(int state[3][3])
{
    int i = 0, j = 0;
    for (i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            std::cout << state[i][j] << " ";
        }
        std::cout << std::endl;         
    }
    std::cout << std::endl;
}

bool compare_states(int state1[3][3], int state2[3][3])
{
    int i = 0, j = 0;
    for (i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(state1[i][j] != state2[i][j]){
                return false;
            }
        }         
    }
    return true; // return true if the state are the same
}

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

bool move_left(State state)
{
    if(state.y < 2){
        swap(state.current_state[state.x][state.y],
             state.current_state[state.x][state.y+1]);
        state.y++;
        return true;
    }
    return false;
}

bool move_right(State state)
{
    if(state.y >= 0){
        swap(state.current_state[state.x][state.y],
             state.current_state[state.x][state.y-1]);
        state.y--;
        return true;
    }
    return false;
}

bool move_down(State state)
{
    if(state.x < 2){
        swap(state.current_state[state.x][state.y],
             state.current_state[state.x+1][state.y]);
        state.x++;
        return true;
    }
    return false;
}

bool move_up(State state)
{
    if(state.x >= 0){
        swap(state.current_state[state.x][state.y], 
             state.current_state[state.x-1][state.y]);
        state.x--;
        return true;
    }
    return false;
}
