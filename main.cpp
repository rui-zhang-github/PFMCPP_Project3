 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


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
