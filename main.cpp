/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Hotel
{
    int totalNumberOfGuestRooms = 30;
    int numberOfBookedRooms = 0;
    float roomRatePerNight = 123.0f;
    int numberOfCafes = 1;
    int numberOfElevators = 2;
    int totalNumberOfCustomersStayingTonight = 0;
    int totalNumberOfLugages = 0;

    int storeLugages(int numberOfLugages = 1); 
    int hostCustomers(int numberOfCustomers = 1); 
    void providLaundryServices(int numberOfClothes = 1);

    struct FrontDesk
    {
        int numberOfCounters = 1;
        int numberOfComputers = 1;
        int numberOfPrinters = 1;
        int numberOfTelephones = 1;
        int numberOfReceptionists = 1;

        void checkCustomersIn(int numberOfCustomers = 1);
        void takeServiceRequests(std::string typeOfServices);
        void printBills(int numberOfBillsToPrint = 1);                
    };
};

int Hotel::storeLugages(int numberOfLugages)
{
    totalNumberOfLugages += numberOfLugages;
    return totalNumberOfLugages;
}

int Hotel::hostCustomers(int numberOfCustomers)
{
    totalNumberOfCustomersStayingTonight += numberOfCustomers;
    return totalNumberOfCustomersStayingTonight;
}

void Hotel::providLaundryServices(int numberOfClothes)
{
    if(numberOfClothes < 2)
    {
        std::cout << numberOfClothes << " has been taken for Laundry Service.";
    }
    else 
    {
        std::cout << numberOfClothes << " have been taken for Laundry Service.";
    }
}

void Hotel::FrontDesk::checkCustomersIn(int numberOfCustomers)
{
    if(numberOfCustomers < 2)
    {
        std::cout << "Checking in " << numberOfCustomers << " customer.";
    }
    else 
    {
        std::cout << "Checking in " << numberOfCustomers << " customers.";
    }  
}

void Hotel::FrontDesk::takeServiceRequests(std::string typeOfServices)
{
    std::cout << typeOfServices << " service request has been taken."; 
}

void Hotel::FrontDesk::printBills(int numberOfBillsToPrint)
{
    if(numberOfBillsToPrint < 2)
    {
        std::cout << numberOfBillsToPrint << " has been printed.";
    }
    else 
    {
        std::cout << numberOfBillsToPrint << " have been printed.";
    }
}

struct Laptop
{
    std::string typeOfCPU = "Quad-Core Intel Core i5";
    int sizeOfRamInGb = 8;
    float sizeOfScreenInInch = 13.3f;
    std::string typeOfOperatingSystem = "Linux";
    int sizeOfDiskSpaceInGb = 256;

    int displayImage(std::string fileName); 
    void playAudio(std::string fileName);
    void storeData(std::string fileName);

    struct Display
    {
        float electricPowerConsumedPerYearInWatts = 1.f;
        int numberOfPixles = 1;
        std::string colorProfile = "Adobe RGB";
        float lengthInCm = 1.0f;
        float WidthInCm = 1.0f;

        void displayColor(std::string hexColorCode = "FF5733");
        void adjustBrightness(float brightnessInPercentage = 50);
        void adjustClarity(float clarityInPercentage = 100);
    };
};

int Laptop::displayImage(std::string fileName)
{
    std::cout << "Now displaying: " << fileName;
    int numberOfDifferentHexColorCodes = 0;
    return numberOfDifferentHexColorCodes;
}

void Laptop::playAudio(std::string fileName)
{
    std::cout << "Now playing: " << fileName;
}

void Laptop::storeData(std::string fileName)
{
    std::cout << fileName << " has been stored the hard drive.";
}

void Laptop::Display::displayColor(std::string hexColorCode)
{
    std::cout << "This is the color of hex code " << hexColorCode;
}

void Laptop::Display::adjustBrightness(float brightnessInPercentage)
{
    std::cout << "Current brightness is " << brightnessInPercentage << "%.";
}

void Laptop::Display::adjustClarity(float clarityInPercentage)
{
    std::cout << "Current clarity is " << clarityInPercentage << "%.";
}

struct DishWasher
{
    double cabinVolumeInCubicMeter = 1.0000;
    int numberOfCycles = 5;
    double numberOfWattsConsumedPerHour = 1.0000;
    float sizeOfMachineInMeter = 1.0f;
    int numberOfRacks = 2;

    void cleanDishes(int numberOfDishes, double amountOfDetergentInLitter);
    void consumeElectricity(double numberOfHoursWashwerHasBeenOn, double numberOfWattsConsumedPerHour);
    void makeNoiseWhenTurnedOn(bool isOn = true);
};

void DishWasher::cleanDishes(int numberOfDishes, double amountOfDetergentInLitter)
{
    if(numberOfDishes < 2)
    {
        std::cout << numberOfDishes << "has been washed with" << amountOfDetergentInLitter << " Litter of detergent.";
    }
    else 
    {
        std::cout << numberOfDishes << "have been washed with" << amountOfDetergentInLitter << " Litter of detergent.";
    }

    if(amountOfDetergentInLitter / numberOfDishes < 0.00000001)
    {
        std::cout <<  "Dishes might not be clean due to too small amount of detergent.";
    }
}

void DishWasher::consumeElectricity(double numberOfHoursTheWashwerHasBeenOn, double numberOfWattsConsumedPerHourOnAvg)
{
    std::cout << "The dishwasher has already consumed " << numberOfHoursTheWashwerHasBeenOn * numberOfWattsConsumedPerHourOnAvg << " Watts of electricity.";
}

void DishWasher::makeNoiseWhenTurnedOn(bool isOn)
{
    if(isOn)
    {
        std::cout << "The machine is noisy.";
    }
}

struct PassengerPlane
{
    int numberOfSeats = 10;
    int nubmerOfBathrooms = 2;
    int numberOfDoors = 6;
    double sizeOfThePlane = 100;
    int numberOfEngines = 4;

    void carryPassengers(int numberOfPassengers);
    void provideMultimediaEntertainment(std::string mediaType);
    void flyAboveTheClouds(std::string from, std::string to);
};

void PassengerPlane::carryPassengers(int numberOfPassengers)
{
    std::cout << "There are " << numberOfPassengers << " passengers on the plane.";
}

void PassengerPlane::provideMultimediaEntertainment(std::string mediaType)
{
    std::cout << "Now playing: " << mediaType;
}

void PassengerPlane::flyAboveTheClouds(std::string from, std::string to)
{
    std::cout << "This flight is from " << from << " to " << to;
}

struct Head
{
    float headCircumferenceInCm = 30.0f;
    int numberOfEyes = 2;
    int numberOfEars = 2;
    int numberOfNoses = 1;
    int numberOfMouths = 1;

    void think(std::string topic);
    void hear(float sineWaveFrequency = 1.0f, float sineWaveAmplitude = 1.0f, float soundDecibels = 1.0f);
    void smell(int numberOfAirMolecules = 10000);
};

void Head::think(std::string topic)
{
    std::cout << "Thinking about " << topic << "now.";
}

void Head::hear(float sineWaveFrequency, float sineWaveAmplitude, float soundDecibels)
{
    std::cout << "Hearing a sound with a frequency of " << sineWaveFrequency << " hertz, an amplitude of " << sineWaveAmplitude << ", and " << soundDecibels << " db.";
}

void Head::smell(int numberOfAirMolecules)
{
    std::cout << "Breathing in " << numberOfAirMolecules << " of air molecules";
}

struct Neck
{
    int numberOfLymphNodes = 10;
    int numberOfThyroids = 1;
    int numberOfVocalFolds = 1;
    int numberOfTracheae = 1;
    float neckCircumferenceInCm = 20.0f;

    void supportTheHead(double weightOfHeadInLb = 1.0000);
    void deliverAirFromNoseToLungs(double volumeOfOxygen = 1.0000, double lengthOfTracheaeInMeter = 1.00); 
    void deliverFoodFromMouthToStomach(double volumeOfFood= 1.0000, double lengthOfEsophagusInMeter = 1.00);
}; 

void Neck::supportTheHead(double weightOfHeadInLb)
{
    std::cout << "Neck is supporting a head of " << weightOfHeadInLb << " lbs.";
}

void Neck::deliverAirFromNoseToLungs(double volumeOfOxygen, double lengthOfTracheaeInMeter)
{
    std::cout << "Neck is delivery a volume of " << volumeOfOxygen << " of oxygen via " << lengthOfTracheaeInMeter << " meter long of tracheae";
}

void Neck::deliverFoodFromMouthToStomach(double volumeOfFood, double lengthOfEsophagusInMeter)
{
    std::cout << "Neck is delivery a volume of " << volumeOfFood << " of food via " << lengthOfEsophagusInMeter << " meter long of esophagus";
}

struct Body
{
    int numberOfHearts = 1;
    int numberOfLungs = 4;
    int numberOfStomachs = 1;
    int numberOfKidneys = 2;
    float waistCircumferenceInCm = 70.0f;

    void exchangeGas(double volumeOfOxygen = 1.0000, double volumeOfCarbonDioxide = 1.0000);
    void digestFood(double volumeOfFood = 1.000);
    void generateUrine(double amountOfWaterConsumedInLitter = 1.000);
};

void Body::exchangeGas(double volumeOfOxygen, double volumeOfCarbonDioxide)
{
    std::cout << "The lungs in your body exchange " << volumeOfOxygen << " volume of oxygen with " << volumeOfCarbonDioxide << " volume of carbon dioxide with one inhale and one exhale on average.";
}

void Body::digestFood(double volumeOfFood)
{
    std::cout << "The stomach in your body is digesting " << volumeOfFood << " volume of food.";
}

void Body::generateUrine(double amountOfWaterConsumedInLitter)
{
    std::cout << "The kidneys in your body generates " << amountOfWaterConsumedInLitter * 0.5 << " Litter of urine per Litter of water you consumed.";
}

struct Arm
{
    float armLengthInCm = 50.000;
    int numberOfMuscles = 100;
    int numberOfJoints = 50;
    int numberOfBones = 30;
    float lengthOfBloodVesselsInCm = 200.0f;

    void liftThings(float weightOfTheThingInLb = 10.0f, float sizeOfTheThingInCubicMeter = 1.0f);
    void rotate(float degreeOfRotation = 45);
    void stretch(int numberOfMusclesMoved = 50);
};

void Arm::liftThings(float weightOfTheThingInLb, float sizeOfTheThingInCubicMeter)
{
    std::cout << "The arm is lifting a thing that is in the size of " << sizeOfTheThingInCubicMeter << " in cubic meter and weighted " << weightOfTheThingInLb << " in lb."; 
}

void Arm::rotate(float degreeOfRotation)
{
    std::cout << "The arm has rotated by " << degreeOfRotation << " degree.";
}

void Arm::stretch(int numberOfMusclesMoved)
{
    std::cout << "Your arm moved " <<  numberOfMusclesMoved << " muscles to strech.";
}

struct Foot
{
    float footLengthInCm = 15.000;
    int numberOfToes = 5;
    int numberOfAnkles = 1;
    float areaOfSkinsInSquareCm = 100;
    int numberOfHeels = 1;

    void stretch(int numberOfMusclesMoved = 20);
    void kick(float forceInNewton = 45);
    void tiptoe(int numberOfMusclesMoved = 10);
};

void Foot::stretch(int numberOfMusclesMoved)
{
    std::cout << "Your foot moved " <<  numberOfMusclesMoved << " muscles to strech.";
}

void Foot::kick(float forceInNewton)
{
    std::cout << "You kicked with " <<  forceInNewton << " Newton of force.";
}

void Foot::tiptoe(int numberOfMusclesMoved)
{
    std::cout << "Your foot moved " <<  numberOfMusclesMoved << " muscles to tiptoe.";
}

struct Human
{
    Head head;
    Neck neck;
    Body body;
    Arm leftArm;
    Arm rightArm;
    Foot leftFoot;
    Foot rightFoot;

    void speak(int numberOfWords = 1);
    void run(double distanceInMeter = 1000.00);
    void jump(int numberOfFootUsed = 2);
};

void Human::speak(int numberOfWords)
{
    std::cout << "You just said a sentence with " << numberOfWords << " number of words.";
}

void Human::run(double distanceInMeter)
{
    std::cout << "You just ran for " << distanceInMeter << " meters.";
}

void Human::jump(int numberOfFootUsed)
{
    if(numberOfFootUsed == 1)
    {
        std::cout << "You just jumped with 1 foot.";
    }
    else if(numberOfFootUsed == 2)
    {
        std::cout << "You just jumped with both feet.";    
    }
    else
    {
        std::cout << "You just jumped with " << numberOfFootUsed << " feet. You are not a normal human.";  
    }
}

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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
