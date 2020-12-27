#include "utilities.h"



//ERROR UTILITIES
//
// Check to see if there is a nonspace character sitting in the input stream
// Sets errorFlag to true if a nonspace character is in the input stream
void checkNext(bool& errorFlag)
{
        char checkNext;
        checkNext = cin.peek();


        // If there is not a space, mark errorFlag as true
        //
        if (errorFlag != true)
        {
                if (!isspace(checkNext))
                {
                        cin.clear();
                        errorFlag = true;
                        invalidEntry(errorFlag);
                }
        }
}

// Cin error check
//
// Check if cin is in error
void cinErrorCheck(bool& errorFlag)
{
        if (errorFlag != true)
        {
                if (!cin)
                {
                        cin.clear();
                        errorFlag = true;
                        invalidEntry(errorFlag);
                }
                else
                {
                        cin.ignore(MAX_CHAR, '\n');
                        errorFlag = false;
                }
        }
}

// Invalid Entry
//
// Used to clear the input stream and echo error message.
// (cin.clear is not included so that it can be used in the more
// specific error handling function cinErrorCheck from above)
void invalidEntry(const bool& errorFlag)
{
        if (errorFlag == true)
        {
                cin.ignore(MAX_CHAR, '\n');
                cout << endl;
                cout << "Invalid Input. Please try again." << endl;
        }
}

// INPUT UTILITIES
//
// Take an int input
//
void takeInput(int& input, const string& prompt)
{
        bool errorFlag;
        errorFlag = false;
        do
        {
                errorFlag = false;

                cout << prompt;
                cin >> input;
                checkNext(errorFlag);
                cinErrorCheck(errorFlag);
        } while (errorFlag == true);
}

// Take a double input
//
void takeInput(double& input, const string& prompt)
{
        bool errorFlag;
        errorFlag = false;
        do
        {
                errorFlag = false;

                cout << prompt;
                cin >> input;
                checkNext(errorFlag);
                cinErrorCheck(errorFlag);
        } while (errorFlag == true);
}

// Take a char input
//
void takeInput(char& input, const string& prompt)
{
        bool errorFlag;

        do
        {
                errorFlag = false;

                cout << prompt;
                cin >> input;
                checkNext(errorFlag);
                cinErrorCheck(errorFlag);
        } while (errorFlag == true);
}

// Take a cstring input
//
void takeInput(char input[], const string& prompt)
{
        bool errorFlag;
        errorFlag = false;

        do
        {
                errorFlag = false;

                cout << prompt;
                cin.get(input, MAX_CHAR, '\n');
                cinErrorCheck(errorFlag);
        } while (errorFlag == true);
}

// Take a cstring input, return a value for the length of the string.
//
void takeInput(char input[], const string& prompt, int& stringLength)
{
        bool errorFlag;
        errorFlag = false;
        do
        {
                errorFlag = false;

                cout << prompt;
                cin.get(input, MAX_CHAR, '\n');
                cinErrorCheck(errorFlag);
        } while (errorFlag == true);

        // Once good info is entered for input, the string length is counted and saved as a referenced value.
        stringLength = strlen(input);
}

// CHECK FOR QUIT
//
// Check for entry of 'q' for quit for cstring input.
bool quitCheck(const char input[])
{
        if ((tolower(input[0]) == 'q') && (input[1] == '\0'))
        {
                return true;
        }
        else
        {
                return false;
        }
}

//
// Check for entry of 'q' for quit for char input.
bool quitCheck(const char& input)
{
        if (tolower(input) == 'q')
        {
                return true;
        }
        else
        {
                return false;
        }
}

// OUTPUT UTILITIES
void printCstring(const char cString[])
{
        int     i;
        int     length;

        length = strlen(cString);

        for (i = 0; i < length; i++)
        {
                cout << cString[i];
        }
}

void copyCstring(const char sourceCstring[], char destinationCstring[])
{
        stringCopy(destinationCstring, MAX_CHAR, sourceCstring);
}

// Returns -1 if char1 is less than char2
// Returns 0 if char1 is equal to char2
// Returns 1 if char1 is greater than char2
// Returns 2 if error
int compareChar(const char& char1, const char& char2)
{
        int     comparisonReturner;

        comparisonReturner = 2;

        // If char1 is equal to char2
        if (tolower(char1) == tolower(char2))
        {
                comparisonReturner = 0;
        }
        // If char1 is less than char2
        else if (tolower(char1) < tolower(char2))
        {
                comparisonReturner = -1;
        }
        // If char1 is more than char 2
        else if (tolower(char1) > tolower(char2))
        {
                comparisonReturner = 1;
        }

        return comparisonReturner;
}

int compareCstringToLowercase(const char cString1[], const char cString2[])
{
        int     stringLength1;
        int     stringLength2;
        char* cString1Lowercase;
        char* cString2Lowercase;
        bool    matchFlag;

        stringLength1 = strlen(cString1);
        stringLength2 = strlen(cString2);
        matchFlag = false;

        // If the strings are not the same length the strings are not the same
        if (strlen(cString1) != strlen(cString2))
        {
                matchFlag = false;
        }
        else
        {
                cString1Lowercase = new char[stringLength1 + 1];
                cString2Lowercase = new char[stringLength2 + 1];

                stringCopy(cString1Lowercase, (stringLength1 + 1), cString1);
                stringCopy(cString2Lowercase, (stringLength2 + 1), cString2);

                // Change cstring to lowercase for comparison
                cStringToLowercase(cString1Lowercase, stringLength1);
                cStringToLowercase(cString2Lowercase, stringLength2);

                if (!strcmp(cString1Lowercase, cString2Lowercase))
                {
                        matchFlag = true;
                }
                else
                {
                        matchFlag = false;
                }
                delete[] cString1Lowercase;
                delete[] cString2Lowercase;
        }
        return matchFlag;
}

// Cstring manipulation
void cStringToLowercase(char cString[], const int stringLength)
{
        int     i;

        for (i = 0; i < stringLength; i++)
        {
                cString[i] = tolower(cString[i]);
        }
}

// Take a cString input, check for validity, and 
bool cStringToInt(const char inputCstring[], int& outputInteger)
{
        outputInteger = atoi(inputCstring);
        if ((!outputInteger) && (outputInteger != 0))
        {
                outputInteger = -2;
                return false;
        }
        else
        {
                return true;
        }
}

void stringCopy(char destination[], const int& stringLength, const char source[])
{
        //strcpy(destination, source);
        strcpy_s(destination, stringLength, source);
}



// List Utilities
//
// Take an object from the argument list and put it into the calling list
// Returns the position of the added item in the new list for success, -1 for failure
int takeFromListl(list<string>& destinationList, list<string>& sourceList, int& stringPosition)
{
        int                     destinationPosition = 0;
        int                     sourceSize = sourceList.size();
        list<string>::iterator  currentString;

        // If the list is not empty
        // AND the position is not too large to be in the list
        if ((sourceSize > 0) && (stringPosition < sourceSize))
        {
                // Set currentString to the beginning of the sourceList
                currentString = sourceList.begin();

                // Iterate to the desired location
                advance(currentString, stringPosition);

                // Copy the item over to the destination list
                destinationList.push_back(*currentString);

                // Erase the item from the source list
                sourceList.erase(currentString);

                // The 
                destinationPosition = (destinationList.size() - 1);
        }
        else
        {
                destinationPosition = -1;
        }

        // Outputs the position of the new item (which is the list size minus 1)
        return destinationPosition;
}
// Returns   0 if source is empty or the valueToAdd doesn't exist in the source list
//          -1 if the value already exists in the destination list
//           1 if the value was successfully added to the destination list and removed from the source list
int takeFromList(list<int>& destinationList, list<int>& sourceList, int& valueToRemove)
{
        int                     successValue = 0;
        list<int>::iterator     currentSource;
        list<int>::iterator     currentDestination;
        
        
        // If the source list is not empty
        if (sourceList.size() > 0)
        {
                // Set currentSource to the beginning of the source list
                currentSource = sourceList.begin();

                // While we have not already succeeded
                // AND while the value of our current in the source list is less than or equal to
                // the one we want to remove
                while ((successValue != 1) && (*currentSource <= valueToRemove))
                {
                        // If we have found the valueToRemove in the source list
                        if (*currentSource == valueToRemove)
                        {
                                currentDestination = destinationList.begin();

                                // Iterate to the correct location in the destination list
                                while (*currentDestination <= *currentSource)
                                {
                                        ++currentDestination;
                                }

                                // If the source does not exist in the destination add it
                                if (*currentDestination != *currentSource)
                                {
                                        // Copy the item over to the destination list
                                        destinationList.insert(currentDestination, *currentSource);

                                        // Erase the item from the source list
                                        sourceList.erase(currentSource);

                                        successValue = 1;
                                }
                                // Otherwise the source already exists in the destination, so return error
                                else
                                {
                                        successValue = -1;
                                }
                        }
                        // Otherwise we have not found the valueToRemove in the source list
                        else
                        {
                                ++currentSource;
                        }
                }
        }

        return successValue;
}


// Deallocation Utilities
//
// Deallocate a string list
int deleteList(list<string>*& aList)
{
        int	successValue = 0;

        if (aList != nullptr)
        {
                aList->clear();
                delete aList;
                aList = nullptr;
        }

        return successValue;
}
// Deallocate an int list
int deleteList(list<int>*& aList)
{
        int	successValue = 0;

        if (aList != nullptr)
        {
                aList->clear();
                delete aList;
                aList = nullptr;
        }

        if (aList == nullptr)
        {
                successValue = 1;
        }

        return successValue;
}
//
int deleteList(list<list<tuple<string, int, int>>>*& aList)
{
        int	successValue = 0;

        if (aList != nullptr)
        {
                aList->clear();
                delete aList;
                aList = nullptr;
        }

        if (aList == nullptr)
        {
                successValue = 1;
        }

        return successValue;
}


int deleteList(list<list<string>>*& aList)
{
        int successValue = 0;

        if (aList != nullptr)
        {
                aList->clear();
                delete aList;
                aList = nullptr;
        }

        if (aList == nullptr)
        {
                successValue = 1;
        }

        return successValue;
}

// Design Tools
//
// Output a given number of a given string in a line
void printCharacters(const int& width, const string& designCharacter)
{
        int	i;

        for (i = 0; i < width; i++)
        {
                cout << designCharacter;
        }
}
//
// Center a given string with spaces
void centerString(const string& message)
{
        int     stringLength;
        int     spaces;

        stringLength = message.length();
        // For strings with an even number of characters
        if ((stringLength % 2) == 0)
        {
                spaces = (BOX_WIDTH - stringLength) / 2;
                printCharacters(spaces, " ");
                cout << message;
        }
        else
        {
                spaces = (BOX_WIDTH - (stringLength - 1)) / 2;
                printCharacters(spaces, " ");
                cout << message;
        }
}
//
// Output a header box with a centered given string message
void headerBox(const string& message)
{
        int     dots;
        int	stringWidth;
        int	spaces;

        dots = 13;
        stringWidth = message.length();
        spaces = (((BOX_WIDTH - stringWidth) - ((dots * 2) + 2)) / 2);

        // Output a line of equal signs with a centered header text in the middle
        //
        // Print top bar of equal signs
        cout << endl;
        printCharacters(BOX_WIDTH, "=");
        cout << endl;
        //
        // Print spaces to center the message
        printCharacters(spaces, " ");
        printCharacters(dots, ".");
        cout << " ";
        cout << message;
        cout << " ";
        printCharacters(dots, ".");
        cout << endl;
        //
        // Print bottom bar of equal signs
        printCharacters(BOX_WIDTH, "=");
        cout << endl;
}
//
// An alert box with two lines
void alertBoxTwoLines(const string& line1, const string& line2)
{
        printCharacters(BOX_WIDTH, "=");
        cout << endl;
        centerString(line1);
        cout << endl;
        centerString(line2);
        cout << endl;
        printCharacters(BOX_WIDTH, "=");
        cout << endl;
}
//
// A box to use to get input
void questionBox(char inputBuffer[], const string& prompt)
{
        cout << endl;
        printCharacters(BOX_WIDTH, "=");
        cout << endl;
        cout << endl;
        takeInput(inputBuffer, prompt);
        cout << endl;
        printCharacters(BOX_WIDTH, "=");
        cout << endl;
}