#include "player.h"
#include "game.h"
#include "instructor.h"
#include "playerEvent.h"

#include <iostream>
#include <gmock/gmock.h>


int main(){

    srand(time(NULL));
    int instrId;
    std::cout << "Welcome to the Beer Game" << std::endl;
    Instructor i;
    std::cout << "Enter Instructor Id: " << std::endl;
    std::cin >> instrId;

    while(std::cin.fail()){
      std::cout << "Invalid input \n";
      std::cin.clear();
      std::cin.ignore(256, '\n');
      std::cin >> instrId;
    }

    i.setInstrId(instrId);
    i.setInstrEmail("dh@gmail.com");
    Game one = i.createNewGame();
    std::cout << "Position names: \n";
    std::cout << "Factory:1, ";
    std::cout << "Distributor:2, ";
    std::cout << "Wholesaler:3, ";
    std::cout << "Retailer:4\n";

    //Using a bool array in order to check if positions are taken
    bool player_check[4] = {0, 0, 0, 0};
    int role_choice = 0;
    int player_count = 0;
    Player p1, p2, p3, p4;
    while(1){
      jump_to_choice:
        std::cout << "Please Enter your position: ";
        std::cin >> role_choice;
        if(role_choice > 4 || role_choice <= 0){
          std::cout << "Enter a value between 1 and 4\n";
          goto jump_to_choice;
        }

        switch (role_choice) {
          case 1:
            if(player_check[0] == 0){
              (p1).setRole(role_choice);
              p1.setPId(rand() % 1000 + 1);
              //Adding a player to the Player* vector defined in game.h (players)
              one.addPlayer(&p1, (p1).getRole()-1);
              player_check[(p1).getRole()-1] = 1;
              player_count++;
            }
            else{
              goto jump_to_choice2;
            }
            break;

          case 2:
            if(player_check[1] == 0){
              (p2).setRole(role_choice);
              p2.setPId(rand() % 1000 + 1);
              one.addPlayer(&p2, (p2).getRole()-1);
              player_check[(p2).getRole()-1] = 1;
              player_count++;
            }
            else{
              goto jump_to_choice2;
            }
            break;

          case 3:
            if(player_check[2] == 0){
              (p3).setRole(role_choice);
              p3.setPId(rand() % 1000 + 1);
              one.addPlayer(&p3, (p3).getRole()-1);
              player_check[(p3).getRole()-1] = 1;
              player_count++;
            }
            else{
              goto jump_to_choice2;
            }
            break;

          case 4:
            if(player_check[3] == 0){
              (p4).setRole(role_choice);
              p4.setPId(rand() % 1000 + 1);
              one.addPlayer(&p4, (p4).getRole()-1);
              player_check[(p4).getRole()-1] = 1;
              player_count++;
            }
            else{
              goto jump_to_choice2;
            }
            break;

          jump_to_choice2:
          default:
            std::cout << "Trying to enter as an already established player. ";
            std::cout << "Please enter other choice \n";
            goto jump_to_choice;
        }
        if(player_count>=4){
          break;
        }
    }
    one.printPlayers();

    for(int i=0; i<one.getWeeksToBePlayed(); i++){

      std::vector<Order*> orders;

      orders.push_back(NULL);
      orders.push_back(NULL);
      orders.push_back(NULL);
      orders.push_back(NULL);

      for(int j=0; j<4; j++){
        if((one.getPlayers())[j]->getRole() == 0){
          std::cout << "Factorys " << " inventory is " <<
          (one.getPlayers())[j]->getInventory()<< "\n";
        }

        else if((one.getPlayers())[j]->getRole() == 1){
          std::cout << "Distributors " << " inventory is " <<
          (one.getPlayers())[j]->getInventory()<< "\n";
        }

        else if((one.getPlayers())[j]->getRole() == 2){
          std::cout << "Wholesalers " << " inventory is " <<
          (one.getPlayers())[j]->getInventory()<< "\n";
        }

        else{
          std::cout << "Retailers " << " inventory is " <<
          (one.getPlayers())[j]->getInventory()<< "\n";
        }

      }

      std::cout << "Please enter order values \n";
      for(int k=0; k<4; k++){

        int order_amount;
        std::cout << "Order for ";

        if((one.getPlayers())[k]->getRole()==0){
          std::cout << "Factory: ";
        }

        else if((one.getPlayers())[k]->getRole()==1){
          std::cout << "Distributor: ";
        }

        else if((one.getPlayers())[k]->getRole()==2){
          std::cout << "Wholesaler: ";
        }

        else if((one.getPlayers())[k]->getRole()==3){
          std::cout << "Retailer: ";
        }

        std::cin >> order_amount;
        Order o;
        o.setNumberOfBeers(order_amount);
        // Pushing
        orders[i] = &o;
        std::cout << "\n";
      }

    }


    return 0;
}
