//
//  main.cpp
//  Book Exercise 6.22 - Crabs
//
//  Created by ax on 9/28/16.
//  Copyright © 2016 COMP130. All rights reserved.
//
/*
  -------  
 | *   * |
 |   *   |
 | *   * |
  -------
  -------
 | *   * |
 | *   * |
 | *   * |
  -------
*/

#include <iostream>
#include <iomanip>
#include <cmath>
// #include <Windows.h>
using namespace std;

int roll_dice() {
    
    int die_value = (rand() % 6 + 1);
    
    return die_value;
}

int add_dice(int d1, int d2) {
    
    return d1 + d2;
}

int main() {
    
    // random seed
    srand(time(0));
    
    
    int point = 0;
    
    cout << "Crabs : Lucky 7 or 11 \n";
    
    cout << "Roll the Dice! \n";
    
    int d1 = roll_dice(), d2 = roll_dice();
    
    cout << "You rolled " << d1 << " and " << d2 << endl;
    
    int come_out_roll = add_dice(d1, d2);
    
    if (come_out_roll == 7 || come_out_roll == 11) {
        
        cout << "You threw " << come_out_roll << ", WINNER!!" << endl;
        
    } else if (come_out_roll == 2 || come_out_roll == 3 || come_out_roll == 12) {
        
        cout << "You threw " << come_out_roll << ", CRAPS, TRY AGAIN!!" << endl;
        
    } else {
        
        point = come_out_roll;
        
        cout << "You threw " << come_out_roll << ", the POINT is " << point << endl;
        cout << "Shoot the dice again!" << endl;
        
        int shooter_roll = 0;
        
        do {
            // shooting for the point
            
            cout << "Press the 'S' key to shoot the dice!" << endl;
            char key_input = ' ';
            
            do {
                
                cin >> key_input;
                
            } while (key_input != 'S');
            
            
            shooter_roll = add_dice(roll_dice(), roll_dice());
            
            cout << "You rolled a " << shooter_roll << endl;
            
        } while (point != shooter_roll && shooter_roll != 7);
        
        if (shooter_roll == 7) {
            cout << "SEVEN, game over!" << endl;
        } else {
            cout << "You made the point?!" << endl;
        }
        
        
    }
    
    
    
    return 0;
}
