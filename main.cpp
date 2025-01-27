/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
    
 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





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
    int reserveRooms(int numberOfRoomsNeeded)
    {
        std::cout << "Return the number of rooms reserved per function call." << std::endl;
        int i = 0;
        std::string word = " room";
        while(numberOfBookedRooms < totalNumberOfGuestRooms && i < numberOfRoomsNeeded)
        {
            numberOfBookedRooms += 1;
            i += 1;
            word = (i <= 1) ? " room" : " rooms";
            std::cout << "Reserved " << i << word << "." << std::endl;
        }
        if(numberOfBookedRooms >= totalNumberOfGuestRooms)
        {
            std::cout << "Fully booked now." << std::endl;
        }
        std::cout << "Reserved " << i << word << " in total." << std::endl;
        std::string word2 = (totalNumberOfGuestRooms - numberOfBookedRooms <= 1) ? " room" : " rooms";
        std::cout << totalNumberOfGuestRooms - numberOfBookedRooms << word2 << " available." << std::endl;
        return i;
    }

    struct FrontDesk
    {
        FrontDesk();
        int numberOfCounters = 1;
        int numberOfComputers { 1 };
        int numberOfPrinters;
        int numberOfTelephones = 3;
        int numberOfReceptionists { 2 };

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
        bool coordinateCalls(unsigned int numberOfIncomingCalls)
        {
            std::cout << "Return boolean values if there are incoming calls to the front desk." << std::endl;
            if(numberOfIncomingCalls > 0)
            {
                for(int i = 1; i <= numberOfReceptionists && i <= numberOfTelephones; ++i)
                {
                    std::string word = (i < 2) ? " call" : " calls";
                    std::cout << "Taking " << i << word << "." << std::endl;
                }
                std::cout << "Please hold. All staff are taking calls from other guests." << std::endl;
                return true;
            }
            else
            {
                std::cout << "No call taken." << std::endl;
                return false;
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
    void formatDisk(unsigned int percentageOfTotalDiskSpaceNeededToBeFreedUp)
    {
        std::cout << "This function prints out the disk space that has been freed up by formatting based on the user input as the function parameter." << std::endl;
        if(percentageOfTotalDiskSpaceNeededToBeFreedUp <= 100)
        {
            int i = 0;
            while(i <= percentageOfTotalDiskSpaceNeededToBeFreedUp / 100.0 * sizeOfDiskSpaceInGb)
            {
                std::cout << i << "GB disk space has been formatted and freed." << std::endl;
                i += 1;
            }
        }
        else
        {
            std::cout << "Disk formatting failed." << std::endl;
        }
    }

    struct Display
    {
        Display();
        double electricPowerConsumedPerYearInWatts = 1.0;
        int numberOfPixles { 1 };
        std::string colorProfile;
        float lengthInCm { 1.0f };
        float WidthInCm;

        void displayColor(std::string hexColorCode = "FF5733");
        void adjustBrightness(int brightnessInPercentage = 50);
        void adjustClarity(float clarityInPercentage = 100);
        void printElectricPowerConsumedPerYearInWatts()
        {
            std::cout << "This display consumes " << electricPowerConsumedPerYearInWatts << "W electricity per year."<< std::endl;
        }
        double consumeElectricity(int numberOfYears, int brightnessInPercentage)
        {
            std::cout << "Print electricity consumed while it is on for X number of years." << std::endl;
            double electricityConsumedInWatt = 0.00;
            for(int i = 0; i <= numberOfYears; ++i)
            {
                electricityConsumedInWatt = i * electricPowerConsumedPerYearInWatts * brightnessInPercentage / 100;
                std::cout << "The display has been on for " << i << " years and consumed " << electricityConsumedInWatt << "W of electricity." << std::endl;
            }
            return electricityConsumedInWatt;
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

void Laptop::Display::adjustBrightness(int brightnessInPercentage)
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
    void washDishes (int startingCycle)
    {
        std::cout << "Print the on-going cycle number while washing dishes" << std::endl;
        while(startingCycle <= numberOfCycles && startingCycle >= 1)
        {
            std::cout << "Current cycle: " << startingCycle << std::endl;
            startingCycle += 1; 
        }
        if(startingCycle < 1 || startingCycle > numberOfCycles + 1)
        {
            std::cout << "Error. Please enter number 1 - " << numberOfCycles << "." << std::endl;
        }
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
    int numberOfSeats = 20;
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
    int numberOfLoopsToUnloadAllPassengers(int numberOfDoorsOpened)
    {
        std::cout << "Print and return number of loops to unload all the passengers assuming flying at full capacity." << std::endl;
        int numberOfLoops = 0;
        for(int i = 0; i * numberOfDoorsOpened < numberOfSeats; ++i)
        {
            std::cout << "A total of " << i * numberOfDoorsOpened << " people can be unloaded in loop " << i << "." << std::endl;
            numberOfLoops = i;
        }
        int lastLoop = (numberOfLoops * numberOfDoorsOpened < numberOfSeats) ? 1 : 0;
        numberOfLoops = numberOfLoops + lastLoop;
        std::cout << "The plane can be fully unloaded at full capacity at loop " << numberOfLoops << "." << std::endl;
        return numberOfLoops;
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
    void blinkOneEyeAtATime(int numberOfBlinksForEachEye)
    {
        std::cout << "Print the action of an eye when blink." << std::endl;
        int i = 0;
        while(i < numberOfBlinksForEachEye)
        {
            for(int e = 0; e < numberOfEyes; ++e)
            {
                std::cout << "open one eye." << std::endl;
                std::cout << "close one eye." << std::endl;
            }
            ++i;
        }
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
    void yell(int numberOfSecondsYelling)
    {
        std::cout << "This function prints each second each vocal fold vibrates." << std::endl;
        for(int i = 1; i <= numberOfSecondsYelling; ++i)
        {
            int v = 0;
            while(v < numberOfVocalFolds)
            {
                ++v;
                std::cout << "Vocal fold #" << v << " has been vibrating for " << i << " second(s)." << std::endl;
            }
        }
    }
};

Neck::Neck() :
numberOfVocalFolds(2),
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
    int numberOfHearts = 2;
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
    int totalHeartBeats(int numberOfSeconds, int heartRatePerSecond)
    {
        std::cout << "Print and return the total number of heart beats in a time period." << std::endl;
        int i = 0;
        int totalNumberOfHeartBeats = 0;
        while(i < numberOfSeconds)
        {
            totalNumberOfHeartBeats = i * heartRatePerSecond * numberOfHearts;
            std::cout << "There has been " << totalNumberOfHeartBeats << " heart beat(s) in the past " << i << " second(s)." << std::endl;
            ++i;
        }
        return totalNumberOfHeartBeats;
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
    void punch(int numberOfTimes)
    {
        for(int i = 1; i <= numberOfTimes; ++i)
        {
            std::cout << "This function prints the rotation and stretch actions for each punch." << std::endl;
            rotate(30.00f);
            stretch(75);
        }
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
    void bendToes(int numberOfTimesBend)
    {
        std::cout << "This function prints each time each toe bends." << std::endl;
        int i = 1;
        while(i <= numberOfTimesBend)
        {
            for(int t = 1; t <= numberOfToes; ++t)
            {
                std::cout << "Toe " << t << " had " << i << " bend(s)." << std::endl;
            }
            ++i;
        }
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
#include <cmath>
int main()
{
    Example::main();
    std::cout << "\n" << std::endl;

    std::cout << "UDT #1: Hotel" << std::endl;
    Hotel daysInn;
    int tLugages = daysInn.storeLugages(2);
    std::cout << "Stored " << tLugages << " lugages." << std::endl;
    int tCustomers = daysInn.hostCustomers(6);
    std::cout << "Hosted " << tCustomers << " customers." << std::endl;
    daysInn.providLaundryServices(8);
    daysInn.numberOfCafes = 5;
    std::cout << "There are " << daysInn.numberOfCafes << " cafes in this hotel." << std::endl;
    daysInn.printRoomRatePerNight();
    int roomsBooked = daysInn.reserveRooms(31);
    std::cout << "Booked " << roomsBooked << " rooms." << std::endl;
    std::cout << std::endl;

    std::cout << "UDT #2: Front Desk within a Hotel" << std::endl;
    Hotel::FrontDesk daysInnFrontDesk;
    daysInnFrontDesk.checkCustomersIn(2);
    daysInnFrontDesk.takeServiceRequests("Spa");
    daysInnFrontDesk.printBills(6);
    daysInnFrontDesk.numberOfPrinters = 8;
    std::cout << "There are " << daysInnFrontDesk.numberOfPrinters << " printers in this hotel." << std::endl;
    daysInnFrontDesk.printNumberOfReceptionists();
    bool isCalling = daysInnFrontDesk.coordinateCalls(4);
    std::cout << "Is the Front Desk Taking Phone Calls? " << (isCalling == true ? "Yes." : "No.") << std::endl;
    std::cout << std::endl;

    std::cout << "UDT #3: Laptop" << std::endl;
    Laptop macBookPro;
    int numberOfColorCodes = macBookPro.displayImage("juce.jpg");
    macBookPro.playAudio("Suspended Animation.mp3");
    macBookPro.storeData("main.cpp");
    std::cout << "The file displayed has " << numberOfColorCodes << " different hex colors." << std::endl;
    macBookPro.printSizeOfScreenInInch();
    macBookPro.formatDisk(10);
    std::cout << std::endl; 

    std::cout << "UDT #4: Display of a Laptop" << std::endl;
    Laptop::Display macBookProRetinaDisplay;
    macBookProRetinaDisplay.displayColor("000000");
    macBookProRetinaDisplay.adjustBrightness(70);
    macBookProRetinaDisplay.adjustClarity(50);
    macBookProRetinaDisplay.numberOfPixles = 1000000000;
    std::cout << "The Laptop has display with " << macBookProRetinaDisplay.numberOfPixles << " pixles." << std::endl;
    macBookProRetinaDisplay.printElectricPowerConsumedPerYearInWatts(); 
    double totalElectricityConsumed = macBookProRetinaDisplay.consumeElectricity(5, 80);
    std::cout << "Consumed " << totalElectricityConsumed << " Watts of electricity." << std::endl;
    std::cout << std::endl;  
    
    std::cout << "UDT #5: Dish Washer" << std::endl;
    DishWasher machineA;
    machineA.cleanDishes(20, 0.05);
    machineA.consumeElectricity(1.5, 0.5);
    machineA.makeNoiseWhenTurnedOn(false);
    machineA.numberOfCycles = 7;
    std::cout << "The Laptop has " << machineA.numberOfCycles << " cleaning cycles." << std::endl; 
    machineA.printNumberOfWattsConsumedPerHour();
    machineA.washDishes(3);
    std::cout << std::endl;
    
    std::cout << "UDT #6: Passenger Plane" << std::endl;
    PassengerPlane boeing737;
    boeing737.carryPassengers(300);
    boeing737.provideMultimediaEntertainment("Movies");
    boeing737.flyAboveTheClouds("New York", "San Francisco");
    boeing737.numberOfSeats = 31;
    std::cout << "This plane has " << boeing737.numberOfSeats << " seats." << std::endl;
    boeing737.printNumberOfSeats();
    int numberOfLoopsToFullyUnload = boeing737.numberOfLoopsToUnloadAllPassengers(6);
    std::cout << "It will take " << numberOfLoopsToFullyUnload << " loops to fully unload all passengers from the plane." << std::endl;
    std::cout << std::endl;  
    
    std::cout << "UDT #7: Head" << std::endl;
    Head myHead;
    myHead.think("who I am");
    myHead.hear(3.5, 1.0, 10.5);
    myHead.smell(100000);
    myHead.numberOfEyes = 3;
    std::cout << "There are " << myHead.numberOfEyes << " eyes on my head." << std::endl;
    myHead.printHeadCircumferenceInCm();
    myHead.blinkOneEyeAtATime(2);
    std::cout << std::endl;  

    std::cout << "UDT #8: Neck" << std::endl;
    Neck myNeck;
    myNeck.supportTheHead(10.0);
    myNeck.deliverFoodFromMouthToStomach(10, 1.25);
    myNeck.deliverAirFromNoseToLungs(2, 1.68);
    myNeck.neckCircumferenceInCm = 36.8;
    std::cout << "The circumference of my neck is " << myNeck.neckCircumferenceInCm << " cm." << std::endl; 
    myNeck.printNumberOfLymphNodes();
    myNeck.yell(3);
    std::cout << std::endl;

    std::cout << "UDT #9: Body" << std::endl;
    Body myBody;
    myBody.exchangeGas(2.0, 2.0);
    myBody.digestFood(6.8);
    myBody.generateUrine(1.0);
    myBody.waistCircumferenceInCm = 62.8;
    std::cout << "The circumference of my waist is " << myBody.waistCircumferenceInCm << " cm." << std::endl; 
    myBody.printNumberOfHearts();
    myBody.totalHeartBeats(3, 2);
    std::cout << std::endl;

    std::cout << "UDT #10: Arm" << std::endl;
    Arm myLeftArm;
    myLeftArm.liftThings(2, 6);
    myLeftArm.rotate(80);
    myLeftArm.stretch(100);
    myLeftArm.numberOfBones = 100;
    std::cout << "There are " << myLeftArm.numberOfBones << " bones in my arm." << std::endl;
    myLeftArm.printNumberOfMuscles();
    myLeftArm.punch(2);
    std::cout << std::endl;

    std::cout << "UDT #11: Foot" << std::endl;
    Foot myRightFoot;
    myRightFoot.stretch(88);
    myRightFoot.kick(66);
    myRightFoot.tiptoe(62);
    myRightFoot.numberOfToes = 5;
    std::cout << "There are " << myRightFoot.numberOfToes << " on my one foot." << std::endl;
    myRightFoot.printNumberOfAnkles(); 
    myRightFoot.bendToes(3);
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
    myself.head.blinkOneEyeAtATime(3);
    myself.neck.yell(4);
    myself.body.totalHeartBeats(4, 3);
    myself.leftArm.punch(3);
    myself.rightFoot.bendToes(2);
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
