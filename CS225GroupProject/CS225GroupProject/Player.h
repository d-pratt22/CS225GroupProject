#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    int x;
    int y;
    int range;

    Player() {
        x = 0;
        y = 0;
        range = 10;
    }
};

#endif