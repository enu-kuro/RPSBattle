//
//  RPSObject.cpp
//  RPSBattle
//
//  Created by Kurose Nobuhito on 13/04/06.
//
//

#include "RPSObject.h"

bool RPSObject::init(){
    
    const char *rps;
    int random = rand()%3;
    if(random==0){
        rps="Rock";
        this->type = E_Rock;
    }
    else if (random==1){
        rps="Scissors";
        this->type = E_Scissors;
    }
    else {
        rps="paper";
        this->type = E_Paper;
    }
    
    CCLabelTTF *enemy = CCLabelTTF::create(rps, "Thonburi", 56);
    
    this->addChild(enemy, 10);
    
    return true;
}


EResult RPSObject::judge(ERps selectedValue){
    
    int result = (selectedValue - type + 3) % 3;
    if(result==2){
        return E_Win;}
    else
        if(result==1){
            return  E_Lose;}
        else{
            return E_Even;
        }
    
};