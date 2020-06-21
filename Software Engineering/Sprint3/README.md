# se-04-team-18

## Build Instructions

```
mkdir build
cd build
cmake ..
make
./beergame
./beergame-tests
```

## Instructor Login
```
Username = Ins
Password = 18
```

## Player Login
```
Username = player
Password = 18
```

## GUI
* [x]  Added a create game screen for the instructor that with a qt spinbox to pick the number of games
* [x]  Added the option for the player to pick the role with radio buttons
* [x]  Added Multiple screens for each player(factory, distributor..), 
* [x]  App responds to the player's role choice and goes to the appropriate screen after login validation
* [x]  Shipment and Total inventory changes as the order is placed
* [x]  Made the user interface better and more responsive in general


## Tests

We added more tests. For example:

* Game: 
    - addPlayer
    - generatePasswordsTest
    - setBackorderCostTest
    - addPlayerNumOfPlayers
    - setPlayers
    - getPlayers
    - updatePlayerInventories
    - startGame
    - getGameStarted
    - setGameStarted
    - setShipmentsToBeExecutedTest
    - getShipmentsToBeExecutedTest
    - setOrdersToBeExecutedTest
    - getOrdersToBeExecutedTest
    - getUpstreamNullPtr


* Player: 
    - placeShipmentTest
    - getAvailableShipment
    - setGame
    - getGame
    - setIncomingOrderTest
    - getIncomingOrderTest
    - setIncomingShipmentTest
    - getIncomingShipmentTest
    - setOutgoingShipmentTest
    - getOutgoingShipmentTest
    - getTotalCostTest
    - setTotalCostTest
    - setOrderReceived
    - getOrderReceived
    - setShipmentReceivedTest
    - getShipmentReceivedTest
    - setOrderPlacedTest
    - getOrderPlacedTest
    - setShipmentPlacedTest
    - getShipmentPlacedTest


* PlayerEvent:
    - getReceiverTest
    - setReceiverTest
    - getType
    - setType
    - getEventId
    - setEventId
    - getGId
    - setGId
    - setToPlayerId
    - getToPlayerId
    - setFromPlayerId
    - getFromPlayerId
    - getShippedInWeek
    - setShippedInWeek
    - getOrderedInWeek
    - setOrderedInWeek
    - setNumberOfBeers
    - getNumberOfBeers

* Instructor:
    - createGame
    - createGames
    - setGames
    - getGames
    - showGameStatus

**Total Tests: 143**

**Line Coverage: 99.7% +**

## Documentation

* Added a main page with introduction to the BeerGame that opens automatically when you run the project (if you have Firefox).
* Documentated all tests and included tests.cpp in the documentation.
* Documented a lot of methods, getters, setters that weren't documented previously.
* Added @briefs, @returns, and @params that were missing previously.


## Code:

* Implemented different class methods according to the class diagram.
* Previously, the Order/PlayerEvent classes were all mixed up. Fixed the PlayerEvent class according to the diagram.
* Fixed header guards that were causing linking issues.
* Removed unnecessary copy constructors that were dirupting performance.


