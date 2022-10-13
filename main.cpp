/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks
 
 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.
    
 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


struct Hotel
{
    int totalNumberOfGuestRooms = 30;
    int numberOfBookedRooms { 0 };
    float roomRatePerNight;
    int numberOfCafes = 1;
    int numberOfElevators { 2 };
    int totalNumberOfCustomersStayingTonight;
    int totalNumberOfLugages = 0;

    Hotel() : 
    roomRatePerNight(123.0f),
    totalNumberOfCustomersStayingTonight(0) 
    {
        std::cout << "created a hotel." << std::endl;
    }

    int storeLugages(int numberOfLugages = 1); 
    int hostCustomers(int numberOfCustomers = 1); 
    void providLaundryServices(int numberOfClothes = 1);
    void printRoomRatePerNight()
    {
        std::cout << "Tonight's room rate is $" << roomRatePerNight << "." <<  std::endl;
    }

    struct FrontDesk
    {
        FrontDesk();
        int numberOfCounters = 1;
        int numberOfComputers { 1 };
        int numberOfPrinters;
        int numberOfTelephones = 1;
        int numberOfReceptionists { 1 };

        void checkCustomersIn(int numberOfCustomers = 1);
        void takeServiceRequests(std::string typeOfServices);
        void printBills(int numberOfBillsToPrint = 1);
        void printNumberOfReceptionists()
        {
            if(numberOfReceptionists > 1)
            {
                std::cout << "There are " << numberOfReceptionists << " receptionists at the front desk." <<std::endl;
            }
            else
            {
                std::cout << "There is " << numberOfReceptionists << " receptionist at the front desk." <<std::endl;                
            }
        }                
    };
};

// Hotel::Hotel()
// {
//     std::cout << "created a hotel." << std::endl;
// }

int Hotel::storeLugages(int numberOfLugages)
{
    totalNumberOfLugages += numberOfLugages;
    std::cout << "After adding "  << numberOfLugages << " lugages, the hotel is storing a total of " << totalNumberOfLugages <<  " lugages."  << std::endl;
    return totalNumberOfLugages;
}

int Hotel::hostCustomers(int numberOfCustomers)
{
    totalNumberOfCustomersStayingTonight += numberOfCustomers;
    std::cout << "After checking in "  << numberOfCustomers << " new guest(s), the hotel now has a total number of " << totalNumberOfCustomersStayingTonight <<  " guest(s) staying." << std::endl;
    return totalNumberOfCustomersStayingTonight;
}

void Hotel::providLaundryServices(int numberOfClothes)
{
    if(numberOfClothes < 2)
    {
        std::cout << numberOfClothes << " cloth has been taken for Laundry Service." << std::endl;
    }
    else 
    {
        std::cout << numberOfClothes << " clothes have been taken for Laundry Service." << std::endl;
    }
}

Hotel::FrontDesk::FrontDesk() :
numberOfPrinters(1)
{
    std::cout << "Created a front desk within the hotel." << std::endl;
}

void Hotel::FrontDesk::checkCustomersIn(int numberOfCustomers)
{
    if(numberOfCustomers < 2)
    {
        std::cout << "Checking in " << numberOfCustomers << " customer." << std::endl;
    }
    else 
    {
        std::cout << "Checking in " << numberOfCustomers << " customers." << std::endl;
    }  
}

void Hotel::FrontDesk::takeServiceRequests(std::string typeOfServices)
{
    std::cout << typeOfServices << " service request has been taken." << std::endl; 
}

void Hotel::FrontDesk::printBills(int numberOfBillsToPrint)
{
    if(numberOfBillsToPrint < 2)
    {
        std::cout << numberOfBillsToPrint << " bill has been printed." << std::endl;
    }
    else 
    {
        std::cout << numberOfBillsToPrint << " bills have been printed." << std::endl;
    }
}

struct Laptop
{
    Laptop() :
    sizeOfScreenInInch(13.3f),
    sizeOfDiskSpaceInGb(256)
    {
        std::cout << "Created a laptop." << std::endl;
    }
    std::string typeOfCPU = "Quad-Core Intel Core i5";
    int sizeOfRamInGb { 8 };
    float sizeOfScreenInInch;
    std::string typeOfOperatingSystem = "Linux";
    int sizeOfDiskSpaceInGb;

    int displayImage(std::string fileName); 
    void playAudio(std::string fileName);
    void storeData(std::string fileName);
    void printSizeOfScreenInInch()
    {
        std::cout << "This is a " << sizeOfScreenInInch << "in screen."<< std::endl;
    }

    struct Display
    {
        Display();
        float electricPowerConsumedPerYearInWatts = 1.f;
        int numberOfPixles { 1 };
        std::string colorProfile;
        float lengthInCm { 1.0f };
        float WidthInCm;

        void displayColor(std::string hexColorCode = "FF5733");
        void adjustBrightness(float brightnessInPercentage = 50);
        void adjustClarity(float clarityInPercentage = 100);
        void printElectricPowerConsumedPerYearInWatts()
        {
            std::cout << "This display consumes " << electricPowerConsumedPerYearInWatts << "W electricity per year."<< std::endl;
        }
    };
};

// Laptop::Laptop()
// {
//     std::cout << "Created a laptop." << std::endl;
// }

int Laptop::displayImage(std::string fileName)
{
    std::cout << "Now displaying: " << fileName << std::endl;
    int numberOfDifferentHexColorCodes = 0;
    return numberOfDifferentHexColorCodes;
}

void Laptop::playAudio(std::string fileName)
{
    std::cout << "Now playing: " << fileName << std::endl;
}

void Laptop::storeData(std::string fileName)
{
    std::cout << fileName << " has been stored the hard drive." << std::endl;
}

Laptop::Display::Display() :
colorProfile("Adobe RGB"),
WidthInCm(1.0f)
{
    std::cout << "Created a display of a laptop." << std::endl;
}

void Laptop::Display::displayColor(std::string hexColorCode)
{
    std::cout << "This is the color of hex code " << hexColorCode << std::endl;
}

void Laptop::Display::adjustBrightness(float brightnessInPercentage)
{
    std::cout << "Current brightness is " << brightnessInPercentage << "%." << std::endl;
}

void Laptop::Display::adjustClarity(float clarityInPercentage)
{
    std::cout << "Current clarity is " << clarityInPercentage << "%." << std::endl;
}

struct DishWasher
{

    double cabinVolumeInCubicMeter = 1.0000;
    int numberOfCycles { 5 };
    double numberOfWattsConsumedPerHour;
    float sizeOfMachineInMeter { 1.0f };
    int numberOfRacks;

    DishWasher() : 
    numberOfWattsConsumedPerHour(1.0000),
    numberOfRacks(2)
    {
        std::cout << "created a dish washer" << std::endl;
    }

    void cleanDishes(int numberOfDishes, double amountOfDetergentInLitter);
    void consumeElectricity(double numberOfHoursWashwerHasBeenOn, double numberOfWattsConsumedPerHour);
    void makeNoiseWhenTurnedOn(bool isOn = true);
    void printNumberOfWattsConsumedPerHour()
    {
        std::cout << "This dish washwer consumes " << numberOfWattsConsumedPerHour << "W of electricity per hour." << std::endl;
    }
};

// DishWasher::DishWasher()
// {
//     std::cout << "created a dish washer" << std::endl;
// }

void DishWasher::cleanDishes(int numberOfDishes, double amountOfDetergentInLitter)
{
    if(numberOfDishes < 2)
    {
        std::cout << numberOfDishes << " dishes has been washed with " << amountOfDetergentInLitter << " Litter of detergent." << std::endl;
    }
    else 
    {
        std::cout << numberOfDishes << " dishes have been washed with " << amountOfDetergentInLitter << " Litter of detergent." << std::endl;
    }

    if(amountOfDetergentInLitter / numberOfDishes < 0.00000001)
    {
        std::cout <<  "Dishes might not be clean due to too small amount of detergent." << std::endl;
    }
}

void DishWasher::consumeElectricity(double numberOfHoursTheWashwerHasBeenOn, double numberOfWattsConsumedPerHourOnAvg)
{
    std::cout << "The dishwasher has already consumed " << numberOfHoursTheWashwerHasBeenOn * numberOfWattsConsumedPerHourOnAvg << " Watts of electricity." << std::endl;
}

void DishWasher::makeNoiseWhenTurnedOn(bool isOn)
{
    if(isOn)
    {
        std::cout << "The machine is noisy." << std::endl;
    }
    else
    {
        std::cout << "The machine is quite." << std::endl;
    }    
}

struct PassengerPlane
{
    PassengerPlane();
    int numberOfSeats = 10;
    int nubmerOfBathrooms { 2 };
    int numberOfDoors;
    double sizeOfThePlane { 100 };
    int numberOfEngines;

    void carryPassengers(int numberOfPassengers);
    void provideMultimediaEntertainment(std::string mediaType);
    void flyAboveTheClouds(std::string from, std::string to);
    void printNumberOfSeats()
    {
        std::cout << "There are " << numberOfSeats << " seats on the plane." << std::endl;
    }
};

PassengerPlane::PassengerPlane() :
numberOfDoors(6),
numberOfEngines(4)
{
    std::cout << "created a passenger plane." << std::endl;
}

void PassengerPlane::carryPassengers(int numberOfPassengers)
{
    std::cout << "There are " << numberOfPassengers << " passengers on the plane." << std::endl;
}

void PassengerPlane::provideMultimediaEntertainment(std::string mediaType)
{
    std::cout << "Now playing: " << mediaType << std::endl;
}

void PassengerPlane::flyAboveTheClouds(std::string from, std::string to)
{
    std::cout << "This flight is from " << from << " to " << to << std::endl;
}

struct Head
{
    Head() :
    numberOfEars(2),
    numberOfMouths(1)
    {
        std::cout << "This is a head." << std::endl;
    }
    float headCircumferenceInCm = 30.0f;
    int numberOfEyes { 2 };
    int numberOfEars;
    int numberOfNoses { 1 };
    int numberOfMouths;

    void think(std::string topic);
    void hear(float sineWaveFrequency = 1.0f, float sineWaveAmplitude = 1.0f, float soundDecibels = 1.0f);
    void smell(int numberOfAirMolecules = 10000);
    void printHeadCircumferenceInCm()
    {
        std::cout << "The circumference of this head is " << headCircumferenceInCm << "cm." << std::endl;
    }
};

// Head::Head()
// {
//     std::cout << "This is a head." << std::endl;
// }

void Head::think(std::string topic)
{
    std::cout << "Thinking about " << topic << "now." << std::endl;
}

void Head::hear(float sineWaveFrequency, float sineWaveAmplitude, float soundDecibels)
{
    std::cout << "Hearing a sound with a frequency of " << sineWaveFrequency << " hertz, an amplitude of " << sineWaveAmplitude << ", and " << soundDecibels << " db." << std::endl;
}

void Head::smell(int numberOfAirMolecules)
{
    std::cout << "Breathing in " << numberOfAirMolecules << " of air molecules" << std::endl;
}

struct Neck
{
    Neck();
    int numberOfLymphNodes = 10;
    int numberOfThyroids { 1 };
    int numberOfVocalFolds;
    int numberOfTracheae { 1 };
    double neckCircumferenceInCm;

    void supportTheHead(double weightOfHeadInLb = 1.0000);
    void deliverAirFromNoseToLungs(double volumeOfOxygen = 1.0000, double lengthOfTracheaeInMeter = 1.00);
    void deliverFoodFromMouthToStomach(double volumeOfFood= 1.0000, double lengthOfEsophagusInMeter = 1.00);
    void printNumberOfLymphNodes()
    {
        std::cout << "There are " << numberOfLymphNodes << " of lymph nodes in my neck" << std::endl;
    }
};

Neck::Neck() :
numberOfVocalFolds(1),
neckCircumferenceInCm(20.0)
{
    std::cout << "This is a neck." << std::endl;
}

void Neck::supportTheHead(double weightOfHeadInLb)
{
    std::cout << "Neck is supporting a head of " << weightOfHeadInLb << " lbs." << std::endl;
}

void Neck::deliverAirFromNoseToLungs(double volumeOfOxygen, double lengthOfTracheaeInMeter)
{
    std::cout << "Neck is delivery a volume of " << volumeOfOxygen << " of oxygen via " << lengthOfTracheaeInMeter << " meter long of tracheae." << std::endl;
}

void Neck::deliverFoodFromMouthToStomach(double volumeOfFood, double lengthOfEsophagusInMeter)
{
    std::cout << "Neck is delivery a volume of " << volumeOfFood << " of food via " << lengthOfEsophagusInMeter << " meter long of esophagus." << std::endl;
}

struct Body
{
    Body() :
    numberOfStomachs(1),
    waistCircumferenceInCm(20.0)
    {
        std::cout << "This is a body." << std::endl;
    }
    int numberOfHearts = 1;
    int numberOfLungs { 4 };
    int numberOfStomachs;
    int numberOfKidneys { 2 };
    double waistCircumferenceInCm;

    void exchangeGas(double volumeOfOxygen = 1.0000, double volumeOfCarbonDioxide = 1.0000);
    void digestFood(double volumeOfFood = 1.000);
    void generateUrine(double amountOfWaterConsumedInLitter = 1.000);
    void printNumberOfHearts()
    {
        std::cout << "I have " << numberOfHearts << " heart in my body." << std::endl;
    }
};

// Body::Body()
// {
//     std::cout << "This is a body." << std::endl;
// }

void Body::exchangeGas(double volumeOfOxygen, double volumeOfCarbonDioxide)
{
    std::cout << "The lungs in your body exchange " << volumeOfOxygen << " volume of oxygen with " << volumeOfCarbonDioxide << " volume of carbon dioxide with one inhale and one exhale on average." << std::endl;
}

void Body::digestFood(double volumeOfFood)
{
    std::cout << "The stomach in your body is digesting " << volumeOfFood << " volume of food." << std::endl;
}

void Body::generateUrine(double amountOfWaterConsumedInLitter)
{
    std::cout << "The kidneys in your body generates " << amountOfWaterConsumedInLitter * 0.5 << " Litter of urine per Litter of water you consumed." << std::endl;
}

struct Arm
{
    Arm();
    float armLengthInCm = 50.000;
    int numberOfMuscles {100};
    int numberOfJoints;
    int numberOfBones {30};
    float lengthOfBloodVesselsInCm;

    void liftThings(float weightOfTheThingInLb = 10.00f, float sizeOfTheThingInCubicMeter = 1.00f);
    void rotate(float degreeOfRotation = 45.00f);
    void stretch(int numberOfMusclesMoved = 50);
    void printNumberOfMuscles()
    {
        std::cout << "There are " << numberOfMuscles << " muscles in my arm." << std::endl;
    }
};

Arm::Arm() :
numberOfJoints(50),
lengthOfBloodVesselsInCm(200.0f)
{
    std::cout << "This is an arm." << std::endl;
}

void Arm::liftThings(float weightOfTheThingInLb, float sizeOfTheThingInCubicMeter)
{
    std::cout << "The arm is lifting a thing that is in the size of " << sizeOfTheThingInCubicMeter << " in cubic meter and weighted " << weightOfTheThingInLb << " in lb." << std::endl;
}

void Arm::rotate(float degreeOfRotation)
{
    std::cout << "The arm has rotated by " << degreeOfRotation << " degree." << std::endl;
}

void Arm::stretch(int numberOfMusclesMoved)
{
    std::cout << "Your arm moved " <<  numberOfMusclesMoved << " muscles to strech." << std::endl;
}

struct Foot
{
    Foot() : 
    numberOfAnkles(1),
    numberOfHeels(1)
    {
        std::cout << "This is a foot." << std::endl;
    }
    float footLengthInCm = 15.000;
    int numberOfToes { 5 };
    int numberOfAnkles;
    float areaOfSkinsInSquareCm { 100 };
    int numberOfHeels;

    void stretch(int numberOfMusclesMoved = 20);
    void kick(float forceInNewton = 45.f);
    void tiptoe(int numberOfMusclesMoved = 10);
    void printNumberOfAnkles()
    {
        std::cout << "This foot has " << numberOfAnkles << " ankle." << std::endl;
    }
};

// Foot::Foot()
// {
//     std::cout << "This is a foot." << std::endl;
// }

void Foot::stretch(int numberOfMusclesMoved)
{
    std::cout << "Your foot moved " <<  numberOfMusclesMoved << " muscles to strech." << std::endl;
}

void Foot::kick(float forceInNewton)
{
    std::cout << "You kicked with " <<  forceInNewton << " Newton of force." << std::endl;
}

void Foot::tiptoe(int numberOfMusclesMoved)
{
    std::cout << "Your foot moved " <<  numberOfMusclesMoved << " muscles to tiptoe." << std::endl;
}

struct Human
{
    Human();
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

Human::Human()
{
    std::cout << "This is human being." << std::endl;
}

void Human::speak(int numberOfWords)
{
    std::cout << "You just said a sentence with " << numberOfWords << " number of words." << std::endl;
}

void Human::run(double distanceInMeter)
{
    std::cout << "You just ran for " << distanceInMeter << " meters." << std::endl;
}

void Human::jump(int numberOfFootUsed)
{
    if(numberOfFootUsed == 1)
    {
        std::cout << "You just jumped with 1 foot." << std::endl;
    }
    else if(numberOfFootUsed == 2)
    {
        std::cout << "You just jumped with both feet." << std::endl;  
    }
    else
    {
        std::cout << "You just jumped with " << numberOfFootUsed << " feet. You are not a normal human." << std::endl; 
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
    std::cout << "\n" << std::endl;

    std::cout << "UDT #1: Hotel" << std::endl;
    Hotel daysInn;
    daysInn.storeLugages(2);
    daysInn.hostCustomers(6);
    daysInn.providLaundryServices(8);
    daysInn.numberOfCafes = 5;
    std::cout << "There are " << daysInn.numberOfCafes << " cafes in this hotel." << std::endl;
    daysInn.printRoomRatePerNight();
    std::cout << std::endl;

    std::cout << "UDT #2: Front Desk within a Hotel" << std::endl;
    Hotel::FrontDesk daysInnFrontDesk;
    daysInnFrontDesk.checkCustomersIn(2);
    daysInnFrontDesk.takeServiceRequests("Spa");
    daysInnFrontDesk.printBills(6);
    daysInnFrontDesk.numberOfPrinters = 8;
    std::cout << "There are " << daysInnFrontDesk.numberOfPrinters << " printers in this hotel." << std::endl;
    daysInnFrontDesk.printNumberOfReceptionists();
    std::cout << std::endl;

    std::cout << "UDT #3: Laptop" << std::endl;
    Laptop macBookPro;
    int numberOfColorCodes = macBookPro.displayImage("juce.jpg");
    macBookPro.playAudio("Suspended Animation.mp3");
    macBookPro.storeData("main.cpp");
    std::cout << "The file displayed has " << numberOfColorCodes << " different hex colors." << std::endl;
    macBookPro.printSizeOfScreenInInch();
    std::cout << std::endl; 

    std::cout << "UDT #4: Display of a Laptop" << std::endl;
    Laptop::Display macBookProRetinaDisplay;
    macBookProRetinaDisplay.displayColor("000000");
    macBookProRetinaDisplay.adjustBrightness(70);
    macBookProRetinaDisplay.adjustClarity(50);
    macBookProRetinaDisplay.numberOfPixles = 1000000000;
    std::cout << "The Laptop has display with " << macBookProRetinaDisplay.numberOfPixles << " pixles." << std::endl;
    macBookProRetinaDisplay.printElectricPowerConsumedPerYearInWatts(); 
    std::cout << std::endl;  
    
    std::cout << "UDT #5: Dish Washer" << std::endl;
    DishWasher machineA;
    machineA.cleanDishes(20, 0.05);
    machineA.consumeElectricity(1.5, 0.5);
    machineA.makeNoiseWhenTurnedOn(false);
    machineA.numberOfCycles = 3;
    std::cout << "The Laptop has " << machineA.numberOfCycles << " cleaning cycles." << std::endl; 
    machineA.printNumberOfWattsConsumedPerHour();
    std::cout << std::endl;
    
    std::cout << "UDT #6: Passenger Plane" << std::endl;
    PassengerPlane boeing737;
    boeing737.carryPassengers(300);
    boeing737.provideMultimediaEntertainment("Movies");
    boeing737.flyAboveTheClouds("New York", "San Francisco");
    boeing737.numberOfSeats = 310;
    std::cout << "This plane has " << boeing737.numberOfSeats << " seats." << std::endl;
    boeing737.printNumberOfSeats(); 
    std::cout << std::endl;  
    
    std::cout << "UDT #7: Head" << std::endl;
    Head myHead;
    myHead.think("who I am");
    myHead.hear(3.5, 1.0, 10.5);
    myHead.smell(100000);
    myHead.numberOfEyes = 3;
    std::cout << "There are " << myHead.numberOfEyes << " eyes on my head." << std::endl;
    myHead.printHeadCircumferenceInCm();
    std::cout << std::endl;  

    std::cout << "UDT #8: Neck" << std::endl;
    Neck myNeck;
    myNeck.supportTheHead(10.0);
    myNeck.deliverFoodFromMouthToStomach(10, 1.25);
    myNeck.deliverAirFromNoseToLungs(2, 1.68);
    myNeck.neckCircumferenceInCm = 36.8;
    std::cout << "The circumference of my neck is " << myNeck.neckCircumferenceInCm << " cm." << std::endl; 
    myNeck.printNumberOfLymphNodes();
    std::cout << std::endl;

    std::cout << "UDT #9: Body" << std::endl;
    Body myBody;
    myBody.exchangeGas(2.0, 2.0);
    myBody.digestFood(6.8);
    myBody.generateUrine(1.0);
    myBody.waistCircumferenceInCm = 62.8;
    std::cout << "The circumference of my waist is " << myBody.waistCircumferenceInCm << " cm." << std::endl; 
    myBody.printNumberOfHearts();
    std::cout << std::endl;

    std::cout << "UDT #10: Arm" << std::endl;
    Arm myLeftArm;
    myLeftArm.liftThings(2, 6);
    myLeftArm.rotate(80);
    myLeftArm.stretch(100);
    myLeftArm.numberOfBones = 100;
    std::cout << "There are " << myLeftArm.numberOfBones << " bones in my arm." << std::endl;
    myLeftArm.printNumberOfMuscles();
    std::cout << std::endl;

    std::cout << "UDT #11: Foot" << std::endl;
    Foot myRightFoot;
    myRightFoot.stretch(88);
    myRightFoot.kick(66);
    myRightFoot.tiptoe(62);
    myRightFoot.numberOfToes = 5;
    std::cout << "There are " << myRightFoot.numberOfToes << " on my one foot." << std::endl;
    myRightFoot.printNumberOfAnkles(); 
    std::cout << std::endl;

    std::cout << "UDT #12: Human" << std::endl;
    Human myself;
    myself.speak(88);
    myself.run(66.88);
    myself.jump(1);
    myself.body.numberOfLungs = 6;
    std::cout << "I have " << myself.body.numberOfLungs << " lungs." << std::endl;
    myself.head.printHeadCircumferenceInCm();
    myself.neck.printNumberOfLymphNodes();
    myself.body.printNumberOfHearts();
    myself.leftFoot.printNumberOfAnkles();
    myself.rightArm.printNumberOfMuscles();
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
