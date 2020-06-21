# se-03-team-13

It would be better if you have Firefox installed. Then you'll be able to open the documentation automatically.

## Compilation

In the previous group's codebase, there was no build folder and no instructions were given on how to set-up things so we added them ourselves. The main code was also not separated into folders like doc and src previously. The documentation/gui nothing was working according to the commands. It works now.

```
cd build
cmake ..
make
./beergame
./beergame-tests
```

## Classes:

* Modified classes according to the new diagram. For example:

    - Player Class:
        * Added a default constructor with default values of attributes like inventory, backorder etc.
        * Added attributes incomingOrder, incomingShipment, outgoingShipment, totalCost.
        * Added setters/getters for added attributes.
        * Added boolean attributes: orderReceived, shipmentReceived, orderPlaced, shipmentPlaced.
        * ​Modified attribute orderPlaced from int to bool.
        * Modified methods order(numberOfBeers:int, from:Player) and ship(numberOfBeers:int, to:Player) to placeOrder(numberOfBeers:int) and placeShipment(numberOfBeers:int).
        * Added methods receiveOrder and receiveShipment. 
        * Added method getAvailableShipment.
        * Filled methods like getAvailableShipment, setGame, getGame, printPlayers

    - Instructor Class:
        * Added attribute games:vector<Game>. This vector stores the games that have been created by the Instructor.
        * Filled methods like createGame, createGames.

    - Factory Class:
        * Eliminated this class.

    - Game Class:
        * Improved variable names (eg hc -> holdingCost, si -> startingInventory) to avoid confusion.
        * Added a default constructor with default values of attributes like factoryDelay etc.
        * Filled methods generatePasswords, getOrdersToBeExecuted, getOrdersToBeShipped.
        * Removed attribute orderTimeDelay. 
        * Added attributes factoryDelay, numberOfPlayers, shipmentsToBeExecuted, Vector<Player*>.
        * Added setters/getters for added attributes.
        * Renamed attribute demandPerWeek to consumerDemandPerWeek for better clarity.
        * Added methods startGame, executeShipmentsForCurrentWeek, getConsumerDemandForWeek, getDownstream, getUpstream, addShipment, addPlayer, addPlayer, addShipment.
        * Modified method addOrder(order:Order) to addOrder(role: const int&, numberOfBeers: int).

    
    - Order Class:
        * Order class has been renamed to PlayerEvent. 
        * Added two derived classes, Shipment and Order.
        * Added method, executeOrder for class Order and executeShipment for class Shipment.
        * Added attribute receiver:Player*
        * Filled methods like setReceiver, getReceiver





## Documentation:
    
The previous group had created a doxygen-file but it wasn't filled and no proper (html/latex) documentation was created for any of the classes even if we ran Doxygen using their previous Doxyfile. We fixed it in a way that now it generates documentation for all classes, tests, and also has a main page. In previous group's codebase, they also hadn't documented most methods/setters/getters/tests. We added all those things.

The documentation is built automatically in the ```doc``` folder upon:
```
cd build
cmake ..
make
```
Additionally, the main page of the documentation is automatically opened if you have Firefox. If you don't want this to happen, you can remove the following line from ```CMakeLists.txt```:
```
COMMAND firefox ${CMAKE_CURRENT_SOURCE_DIR}/doc/html/index.html
```
## GUI

The GUI from the previous group wasn't building and compiling and successfully even if we opened it in the QT Creator IDE.

- We removed several errors/warnings and fixed the gui.
- Added resource files for this and future sprints.
- Added a "Choose Player Type" screen.
- Added a Stacked Widget for easier navigation between screens throughout all sprints.
- Added missing text labels for example for number of games.
- Added stylesheets.
- Fixed sizes of main window, labels, text boxes etc. For example, previously, the sign up button and password fields were overlapping.
- Added a welcome image and added code for image insertion so it's convinient for the next group.
- Removed unnecessary classes/screens.



## Tests:

We fixed the existing tests according to the new diagram and changed a few typing errors for easier understanding. We added more tests after the last sprint (not just of EXPECT_EQ but also other types eg EXPECT_NE / EXPECT_FALSE). For example:

* Player: 
    - getAvailableShipment
    - getAvailableShipment_Inventory
    - getAvailableShipment_BackOrder
    - setGame
    - getGame
    - setIncomingOrder
    - getIncomingOrder
    - setIncomingShipment
    - getIncomingShipment
    - setOutgoingShipment
    - setTotalCost
    - getTotalCost
    - setOrderReceived
    - getOrderReceived
    - setShipmentReceived
    - getShipmentReceived
    - getOrderPlaced
    - setOrderPlaced
    - getShipmentPlaced
    - setShipmentPlaced
* Game: 
    - generatePasswords
    - setBackOrderCost
    - getNumberOfPlayers
    - setNumberOfPlayers
* Instructor:
    - createGame
    - createGames
* PlayerEvent:
    - setReceiver
    - getReceiver
    - getEventId
    - getNumberOfBeers

Total Tests: 92
## ReadMe:

- The previous readme.md was empty. We added details about how to build, run everything.

## Game From the Terminal

```
cd build
cmake ..
make
./beergame-cli
```
Since our backend isn't linked with the gui for now, we tried to test some parts of a game by creating a mini game on the terminal. It could be run using the commands shown above. The game is created, players and orders initiated, however the pace of the game lacks coherence because of missing methods. 
