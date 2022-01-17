/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};

/*
Thing 1) Hotel
5 properties:
    1) total number of guest rooms (int)
    2) number of booked rooms (int)
    3) room rate per night (float)
    4) number of cafes (int)
    5) number of elevators (int)
3 things it can do:
    1) store lugages
    2) host customers
    3) provide laundry services
 */

struct Hotel
{
    // 5 properties:
    // 1) total number of guest rooms (int)
    int totalNumberOfGuestRooms = 30;
    // 2) number of booked rooms (int)
    int numberOfBookedRooms = 0;
    // 3) room rate per night (float)
    float roomRatePerNight = 123.0f;
    // 4) number of cafes (int)
    int numberOfCafes = 1;
    // 5) number of elevators (int)
    int numberOfElevators = 2;

    // 3 things it can do:
    // 1) store lugages
    int storeLugages(int numberOfLugages = 1); // returns the total number of lugages in the storage room
    // 2) host customers
    int hostCustomers(int numberOfCustomers = 1); // returns the total number of Customers staying in the hotel tonight
    // 3) provide laundry services
    void providLaundryServices(int numberOfClothes = 1);

    struct FrontDesk
    {
        // 5 properties:
        // 1) number of counters (int)
        int numberOfCounters = 1;
        // 2) number of computers (int)
        int numberOfComputers = 1;
        // 3) number of printers (int)
        int numberOfPrinters = 1;
        // 4) number of telephones (int)
        int numberOfTelephones = 1;
        // 5) number of receptionists (int)
        int numberOfReceptionists = 1;

        // 3 things it can do:
        // 1) Check customers in
        void checkCustomersIn(int numberOfCustomers = 1);
        // 2) take service requests
        void takeServiceRequests(std::string typeOfServices);
        // 3) print bills
        void printBills(int numberOfBillsToPrint = 1);                
    };
};

/*
Thing 2) Laptop
5 properties:
    1) type of CPU (std::string)
    2) size of RAM (int)
    3) size of screen (float)
    4) type of operating system (std::string)
    5) size of disk space (int)
3 things it can do:
    1) display images
    2) play audio
    3) store data
 */

struct Laptop
{
    // 5 properties:
    // 1) type of CPU (std::string)
    std::string typeOfCPU = "Quad-Core Intel Core i5";
    // 2) size of RAM (int)
    int sizeOfRamInGb = 8;
    // 3) size of screen (float)
    float sizeOfScreenInInch = 13.3f;
    // 4) type of operating system (std::string)
    std::string typeOfOperatingSystem = "Linux";
    // 5) size of disk space (int)
    int sizeOfDiskSpaceInGb = 256;

    //3 things it can do:
    // 1) display images
    int displayImage(std::string fileName); // return number of different hex color codes displayed
    // 2) play audio
    void playAudio(std::string fileName);
    // 3) store data
    void storeData(std::string fileName);

    struct Display
    {
        // 5 properties:
        // 1) electric power consumed per year in Watts (float)
        float electricPowerConsumedPerYearInWatts = 1.f;
        // 2) number of pixles (int)
        int numberOfPixles = 1;
        // 3) color profile (std::string)
        std::string colorProfile = "Adobe RGB";
        // 4) length in cm (float)
        float lengthInCm = 1.0f;
        // 4) Width in cm (float)
        float WidthInCm = 1.0f;

        // 3 things it can do:
        // 1) display color
        void displayColor(std::string hexColorCode = "FF5733");
        // 2) adjust brightness
        void adjustBrightness(float brightnessInPercentage = 50);
        // 3) adjust clarity
        void adjustClarity(float clarityInPercentage = 100);
    };
};

/*
Thing 3) Dish washer
5 properties:
    1) cabin volume (double)
    2) number of cycles (int)
    3) number of watts consumed per hour (double)
    4) size of the machine (float)
    5) number of racks (int)
3 things it can do:
    1) clean dishes
    2) consume electricity
    3) make noise when turned on
 */

struct DishWasher
{
    // 5 properties:
    // 1) cabin volume (double)
    double cabinVolumeInCubicMeter = 1.0000;
    // 2) number of cycles (int)
    int numberOfCycles = 5;
    // 3) number of watts consumed per hour (double)
    double numberOfWattsConsumedPerHour = 1.0000;
    // 4) size of the machine (float)
    float sizeOfMachineInMeter = 1.0f;
    // 5) number of racks (int)
    int numberOfRacks = 2;

    // 3 things it can do:
    // 1) clean dishes
    void cleanDishes(int numberOfDishes, double amountOfDetergentInLitter);
    // 2) consume electricity
    void consumeElectricity(double numberOfHoursWashwerHasBeenOn, double numberOfWattsConsumedPerHour);
    // 3) make noise when turned on
    void makeNoiseWhenTurnedOn(bool isOn = true);
};

/*
Thing 4) Passenger plane
5 properties:
    1) number of seats (int)
    2) number of bathrooms (int)
    3) number of doors (int)
    4) size of the plane (double)
    5) number of engines (int)
3 things it can do:
    1) carry passengers
    2) provide multi-media entertainment
    3) fly above the clouds 
 */

struct PassengerPlane
{
    // 5 properties:
    // 1) number of seats (int)
    int numberOfSeats = 10;
    // 2) number of bathrooms (int)
    int nubmerOfBathrooms = 2;
    // 3) number of doors (int)
    int numberOfDoors = 6;
    // 4) size of the plane (double)
    double sizeOfThePlane = 100;
    // 5) number of engines (int)
    int numberOfEngines = 4;

    // 3 things it can do:
    // 1) carry passengers
    void carryPassengers(int numberOfPassengers);
    // 2) provide multi-media entertainment
    void provideMultimediaEntertainment(std::string mediaType);
    // 3) fly above the clouds 
    void flyAboveTheClouds(std::string from, std::string to);
};


/*
Thing 5) Head
5 properties:
    1) head circumference in cm (float)
    2) number of eyes (int)
    3) number of ears (int)
    4) number of noses (int)
    5) number of mounths (int)
3 things it can do:
    1) think
    2) hear
    3) smell
 */

struct Head
{
    // 5 properties:
    // 1) head circumference in cm (float)
    float headCircumferenceInCm = 30.0f;
    // 2) number of eyes (int)
    int numberOfEyes = 2;
    // 3) number of ears (int)
    int numberOfEars = 2;
    // 4) number of noses (int)
    int numberOfNoses = 1;
    // 5) number of mounths (int)
    int numberOfMouths = 1;

    // 3 things it can do:
    // 1) think
    void think(std::string topic);
    // 2) hear
    void hear(float sineWaveFrequency = 1.0f, float sineWaveAmplitude = 1.0f, float soundDecibels = 1.0f);
    // 3) smell
    void smell(int numberOfAirMolecules = 10000);
};

/*
Thing 6) Neck
5 properties:
    1) number lymph nodes (int)
    2) number of thyroids (int)
    3) number of vocal folds (int)
    4) number of tracheae (int)
    5) neck circumference in cm (float)
3 things it can do:
    1) support the head
    2) deliver air from nose to lungs
    3) deliver food from mouth to stomach
 */

struct Neck
{
    // 5 properties:
    // 1) number lymph nodes (int)
    int numberOfLymphNodes = 10;
    // 2) number of thyroids (int)
    int numberOfThyroids = 1;
    // 3) number of vocal folds (int)
    int numberOfVocalFolds = 1;
    // 4) number of tracheae (int)
    int numberOfTracheae = 1;
    // 5) neck circumference in cm (float)
    float neckCircumferenceInCm = 20.0f;

    // 3 things it can do:
    // 1) support the head
    void supportTheHead(double weightOfHeadInLb = 1.0000);
    // 2) deliver air from nose to lungs
    void deliverAirFromNoseToLungs(double volumeOfOxygen = 1.0000, double lengthOfTracheaeInMeter = 1.00);
    // 3) deliver food from mouth to stomach   
    void deliverFoodFromMouthToStomach(double volumeOfFood= 1.0000, double lengthOfEsophagusInMeter = 1.00);
};

/*
Thing 7) body 
5 properties:
    1) number of hearts (int)
    2) number of lungs (int)
    3) number of stomachs (int)
    4) number of kidneys (int)
    5) waist circumference in cm (float)
3 things it can do:
    1) exchange gas
    2) digest food
    3) generate urine
 */

struct Body
{
    // 5 properties:
    // 1) number of hearts (int)
    int numberOfHearts = 1;
    // 2) number of lungs (int)
    int numberOfLungs = 4;
    // 3) number of stomachs (int)
    int numberOfStomachs = 1;
    // 4) number of kidneys (int)
    int numberOfKidneys = 2;
    // 5) waist circumference in cm (float)
    float waistCircumferenceInCm = 70.0f;

    // 3 things it can do:
    // 1) exchange gas
    void exchangeGas(double volumeOfOxygen = 1.0000, double volumeOfCarbonDioxide = 1.0000);
    // 2) digest food
    void digestFood(double volumeOfFood = 1.000);
    // 3) generate urine  
    void generateUrine(double amountOfWaterConsumedInLitter = 1.000);
};

/*
Thing 8) arms
5 properties:
    1) arm length in cm (float)
    2) number of muscles (int)
    3) number of joints (int)
    4) number of bones (int)
    5) length of blood vessels in cm (float)
3 things it can do:
    1) lift things
    2) rotate
    3) stretch
 */

struct Arm
{
    // 5 properties:
    // 1) arm length in cm (float)
    float armLengthInCm = 50.000;
    // 2) number of muscles (int)
    int numberOfMuscles = 100;
    // 3) number of joints (int)
    int numberOfJoints = 50;
    // 4) number of bones (int)
    int numberOfBones = 30;
    // 5) length of blood vessels in cm (float)
    float lengthOfBloodVesselsInCm = 200.0f;

    // 3 things it can do:
    // 1) lift things
    void liftThings(float weightOfTheThingInLb = 10.0f, float sizeOfTheThingInCubicMeter = 1.0f);
    // 2) rotate
    void rotate(float degreeOfRotation = 45);
    // 3) stretch 
    void stretch(int numberOfMusclesMoved = 50);
};

/*
Thing 9)
5 properties: foot
    1) foot length in cm (float)
    2) number of toes (int)
    3) number of ankles (int)
    4) area of skins in square cm (float)
    5) number of heels
3 things it can do:
    1) stretch 
    2) kick
    3) tiptoe
 */

struct Foot
{
    // 5 properties:
    // 1) foot length in cm (float)
    float footLengthInCm = 15.000;
    // 2) number of toes (int)
    int numberOfToes = 5;
    // 3) number of ankles (int)
    int numberOfAnkles = 1;
    // 4) area of skins in square cm (float)
    float areaOfSkinsInSquareCm = 100;
    // 5) number of heels (int)
    int numberOfHeels = 1;

    // 3 things it can do:
    // 1) stretch
    void stretch(int numberOfMusclesMoved = 20);
    // 2) kick
    void kick(float forceInNewton = 45);
    // 3) tiptoe 
    void tiptoe(int numberOfMusclesMoved = 10);
};

/*
Thing 10) Human
5 properties:
    1) Head
    2) Neck
    3) Body
    4) Arm
    5) Foot
3 things it can do:
    1) Speak
    2) Run
    3) Jump
 */

struct Human
{
    // 5 properties:
    // 1) Head
    Head head;
    // 2) Neck
    Neck neck;
    // 3) Body
    Body body;
    // 4) Arm
    Arm leftArm;
    Arm rightArm;
    // 5) Foot
    Foot leftFoot;
    Foot rightFoot;

    // 3 things it can do:
    // 1) Speak
    void speak(int numberOfWords = 1);
    // 2) Run
    void run(double distanceInMeter = 1000.00);
    // 3) jump
    void jump(int numberOfFootUsed = 2);
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
