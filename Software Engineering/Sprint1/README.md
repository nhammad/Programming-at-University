# Beer Game - Sprint 2

![Beer Game](images/logo2.png)

## How to Compile?

```
cd build
cmake ..
make
./beergame          //Not for now
./beergame-tests
```

## How to Check GUI?

Open Qt Creator and launch the ```gui/Beer-Game``` folder. It's also attached as a zip folder. 
The GUI might not work on Visual Studio or whatever IDE you're using directly without [vcpkg](https://docs.microsoft.com/en-us/cpp/build/vcpkg?view=vs-2019)
so it would be more convinient if you just extract the folder from the zipped file and then load it into Qt Creator.

Documentation for the GUI is also included in doc/html.
## Progress:

- Implemented classes, their methods, setters, and getters.
- Ensured that all Google test cases are passing.
- Created a detailed documentation using Doxygen.
- Created a basic GUI using Qt including (screenshots attached):
    * A welcome screen 
    * A login screen
    * Role screen: Instructor or Player?
    * Player role screen: Factory, Distributor, Wholesaler, or Retailer?
    * Navigation between two screens implemented partially using signals/slots (close() and show())

- Added additional test cases for example:

    * Player Class:
        - shipTest
        - orderTest

    * Game Class:
        - generatePasswordsTest

    * Order Class:
        - getNumberOfBeersTest

    * Factory Class:
        - produceTest
        - getProducedTest
        - getProductionTime
        - setProducedTest
        - setProductionTime

## Further Improvements:

- Create a database
- Separate GUI classes & main C++ classes in documentation
- Improve GUI and link to database
- Improve beer-game functionality

and so on..


