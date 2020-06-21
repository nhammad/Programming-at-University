#ifndef PLAYER_H
#define PLAYER_H

class Game;
class Order;

class Player
{
private:
    int pId;                       /*!< ID of the player */
    int role;                      /*!< Role that the player has in the game */
    int inventory = 0;             /*!< Current beer inventory of the player */
    int backorder = 0;             /*!< Beer demand that was not satisfied */
    int incomingOrder = 0;         /*!< Amount of beer that was ordered */
    int incomingShipment = 0;      /*!< Amount of beer in the next incoming shipment */
    int outgoingShipment = 0;      /*!< Amount of beer in the next shipment */
    double cost = 0.0;             /*!< Current cost of backorder and keeping beer in inventory */
    double totalCost = 0.0;        /*!< Total cost of backorder and keeping beer in inventory */
    bool orderReceived = false;    /*!< Bool variable to indicate if an order has been received */
    bool shipmentReceived = false; /*!< Bool variable to indicate if a shipment has been received */
    bool orderPlaced = false;          /*!< Amount of beer ordered by the player */
    bool shipmentPlaced = false;   /*!< Bool variable to indicate if a shipment has been placed */
    int demand = 0;                /*!< Demand of beer that the player has to satisfy */
    Game *game;                    /*!< Pointer to the Game object in which this Player is participating */

public:
    //Constructors
    Player();                                   /*!< Default constructor */
    Player(int nId, int nRole, Game *nGame); /*!< Parametric constructor */
    ~Player();                                  /*!< Destructor */

    //Other functions
    void placeOrder(int numberOfBeers);       /*!< Send player's order to the next player */
    void placeShipment(int numberOfBeers);    /*!< Ship beers ordered by previous player */
    int getAvailableShipment(int demand);     /*!< Inventory is adjusted according to demand and number of beers available for shipping is returned */
    int decreaseInventory(int numberOfBeers); /*!< Decrease the player's inventory */
    int increaseInventory(int numberOfBeers); /*!< Increase the player's inventory */
    void receiveShipment(int orderId);        /*!< Receive beer shipment */
    void receiveOrder(int orderedBeers);      /*!< Receive order from other player */
    int factoryProduce(int numberOfBeers);

    //Setters and getters
    void setBackorder(int numberOfBeers);     /*!< Setter for player's backorder */
    int getBackorder() const;                 /*!< Getter for player's backorder */
    void setCost(double nCost);               /*!< Setter for player's cost */
    double getCost() const;                   /*!< Getter for player's cost */
    void setInventory(int numberOfBeers);     /*!< Setter for player's inventory */
    int getInventory() const;                 /*!< Getter for player's inventory */
    void setPId(int nId);                     /*!< Setter for player's ID */
    int getPId() const;                       /*!< Getter for player's ID */
    void setRole(int nRole);                  /*!< Setter for player's role */
    int getRole() const;                      /*!< Getter for player's role */
    void setOrderPlaced(bool nOrderPlaced);    /*!< Setter for player's orderPlaced */
    bool getOrderPlaced() const;               /*!< Getter for player's orderPlaced */
    void setDemand(int nDemand);              /*!< Setter for player's demand */
    int getDemand();                          /*!< Getter for player's demand */
    void setShipmentPlaced(bool nPlaced);     /*!< Setter for ShipmentPlaced bool variable */
    bool getShipmentPlaced() const;           /*!< Getter for ShipmentPlaced bool variable */
    void setShipmentReceived(bool nReceived); /*!< Setter for ShipmentReceived bool variable */
    bool getShipmentReceived() const;         /*!< Getter for ShipmentReceived bool variable */
    void setOrderReceived(bool nReceived);    /*!< Setter for orderReceived bool variable */
    bool getOrderReceived() const;            /*!< Getter for orderReceived bool variable */
    void setTotalCost(double nTotalCost);     /*!< Setter for total cost */
    double getTotalCost() const;              /*!< Getter for total cost */
    void setOutgoingShipment(int nOutgoing);  /*!< Setter for variable outgoingShipment */
    int getOutgoingShipment() const;          /*!< Getter for variable outgoingShipment */
    void setIncomingShipment(int nIncoming);  /*!< Setter for variable incomingShipment */
    int getIncomingShipment() const;          /*!< Getter for variable incomingShipment */
    void setIncomingOrder(int nOrder);        /*!< Setter for variable incomingOrder */
    int getIncomingOrder() const;             /*!< Getter for variable incomingOrder */
    void setGame(Game *nGame);                /*!< Setter for pointer to Game object */
    Game *getGame() const;                    /*!< Getter for pointer to Game object */
};

#endif //PLAYER_H
