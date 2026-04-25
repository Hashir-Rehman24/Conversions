
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;


void printTitle();
void gotoxy( int x, int y);
void clearScreen();
void printSubMenu(string subMenu);
int mainMenu();
int convertionMenu();
int encryptionMenu();
int decryptionMenu();
void convertDecimalIntoBinary(int decimal);
void convertDecimalIntoOctal(int decimal);
void decimalIntoHexadecimal( int decimal);
bool binaryNumberValidation(int binaryNumber);
int binaryIntoDecimal(int binary);
int power(int exponent,int base);
int hexaintodecimal(string hexa);
int octalIntoDecimal(int binary);
void convertIntoDecimalArray(string);
void convertIntoStringArray( string);
bool stringLengthTillSpace(string);
void decryptBinaryToDecimal( string encrytedMessage);

char hexaDecimalValues[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
int encryptedDecimalArray[150];
int decryptedDecimalArray[150];
string finalMessage;
int index = 0;
int decryptIndex = -1;
int lastdecryptIdx = 0;
int mainNewidx = 0;
bool decryptLoop = true;


HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    int mainOption;
    int convertionOption;
    int encryptionOption;
    int decryptionOption;
    int inputValue;
    int decimal;
    string inputToEncrypt;
    string inputToDecrypt;


    while(true)
    {   
        clearScreen();
        printSubMenu( "Main");
        mainOption = mainMenu();

        // Convertions

        if ( mainOption == 1)
        {
            bool convertLoop = true;
            while ( convertLoop)
            {
        
                clearScreen();
                printSubMenu( "Convertions");
                convertionOption = convertionMenu();
                
                if(convertionOption == 2)
                {
                    index = 0;
                    clearScreen();
                    cout << "\033[38;5;45mEnter the value to Convert\033[38;5;15m: ";
                    cin >> inputValue;        
                    convertDecimalIntoBinary(inputValue);
                    decimalIntoHexadecimal(inputValue);
                    convertDecimalIntoOctal(inputValue);
                
                    cout <<endl << endl << "\033[38;5;45mPress Any value to Exit";
                    getch();
                }
                else if (convertionOption == 1)
                {
                    index = 0;
                    clearScreen();
                    bool result;

                    cout << "\033[38;5;45mEnter the value to Convert\033[38;5;15m: ";
                    cin >> inputValue;
                    result = binaryNumberValidation(inputValue);
                    
                    if (result == true)
                    {
                        decimal = binaryIntoDecimal(inputValue);
                        cout << "\033[38;5;208mDecimal\033[38;5;15m: " << decimal;
                        convertDecimalIntoOctal(decimal);
                        decimalIntoHexadecimal(decimal);
                        
                        cout <<endl << endl << "\033[38;5;45mPress Any value to Exit";
                        getch();                        

                    }
                    
                    else
                    {
                        cout << "\033[38;5;196m You Have Entered wrong Binary Value" << endl;
                        cout << "\033[38;5;45mPress Any key to continue: ";
                        getch();
                    }

                }
                else if( convertionOption == 3)
                {
                    index = 0;
                    string hexaValue;
                    clearScreen();
                    cout << "\033[38;5;45mEnter the value to Convert\033[38;5;15m: ";
                    cin >> hexaValue;
                    decimal = hexaintodecimal(hexaValue);
                    cout << "\033[38;5;208mDecimal\033[38;5;15m: " << decimal;
                    convertDecimalIntoOctal(decimal);
                    convertDecimalIntoBinary(decimal); 

                    cout <<endl << endl << "\033[38;5;45mPress Any value to Exit";
                    getch();   
                }
                else if (convertionOption == 4)
                {
                    index = 0;
                    clearScreen();
                    cout << "\033[38;5;45mEnter the value to Convert\033[38;5;15m: ";
                    cin >> inputValue;
                    decimal = octalIntoDecimal(inputValue);
                    cout << "\033[38;5;208mDecimal\033[38;5;15m: " << decimal;
                    convertDecimalIntoBinary(decimal);
                    decimalIntoHexadecimal(decimal); 

                    cout <<endl << endl << "\033[38;5;45mPress Any value to Exit";
                    getch();
                }


                else if (convertionOption == 5)
                {
                    convertLoop = false;
                }

                else
                {
                    cout << "\033[38;5;196mYou Have Entered Wrong Credentials: " << endl;
                    cout << "\033[38;5;45mPress any key to go back.." << endl;
                    getch();
                }
            }
            

        }
        // Encryption Work

        else if ( mainOption == 2)
        {
            clearScreen();
            printSubMenu(" Encryption ");

            cout << "\033[38;5;45m Enter the message you want to Encrypt\033[38;5;15m: ";
            cin.ignore();
            getline (cin , inputToEncrypt);
            convertIntoDecimalArray(inputToEncrypt);
            encryptionOption = encryptionMenu();


            if(encryptionOption == 1)
            {
                clearScreen();
                cout << "\033[38;5;45m Your encrypt value in decimal is\033[38;5;15m: " ;
                for( int i = 0; i <= index; i++)
                {
                    cout << encryptedDecimalArray[i] << " ";
                }
                cout <<  endl<< "\033[38;5;208m Write this encrypted Message or copy it to decrypt.." << endl;
                cout << "\033[38;5;45m Press any key to go back.." << endl;
                getch();
            }

            else if( encryptionOption == 2)
            {
                clearScreen();
                cout << "\033[38;5;45m Your encrypt value in binary is\033[38;5;15m: ";
                for ( int i = 0; i <= index; i++)
                {
                    convertDecimalIntoBinary(encryptedDecimalArray[i]);
                    cout << " ";
                }
                
                cout <<  endl<< "\033[38;5;208m Write this encrypted Message or copy it to decrypt.." << endl;
                cout << "\033[38;5;45m Press any key to go back.." << endl;
                getch();
            }
            else if (encryptionOption == 3)
            {
                clearScreen();
                cout << "\033[38;5;45m Your encrypt value in Hexadecimal is\033[38;5;15m: ";
                for ( int i = 0; i <= index; i++)
                {
                    decimalIntoHexadecimal(encryptedDecimalArray[i]);
                    cout << " ";
                }
                
                cout <<  endl <<endl << "\033[38;5;208m Write this encrypted Message or copy it to decrypt.." << endl;
                cout << "\033[38;5;45m Press any key to go back.." << endl;
                getch(); 
            }
            else if (encryptionOption == 4)
            {
                clearScreen();
                cout << "\033[38;5;45m Your encrypt value in Octal is\033[38;5;15m: ";
                for ( int i = 0; i <= index; i++)
                {
                    convertDecimalIntoOctal(encryptedDecimalArray[i]);
                    cout << " ";
                }
                
                cout <<  endl <<endl << "\033[38;5;208m Write this encrypted Message or copy it to decrypt.." << endl;
                cout << "\033[38;5;45m Press any key to go back.." << endl;
                getch();
            }

        }

        // Decryption
        else if(mainOption == 3)
        {
            clearScreen();
            printSubMenu( "Decryption ");
            decryptionOption = decryptionMenu();

            if(decryptionOption == 1)
            {
                decryptIndex = -1;
                lastdecryptIdx = 0;
                mainNewidx = 0;

                clearScreen();
                cout << "\033[38;5;45m Enter Decimal value to Decrypt\033[38;5;15m: ";
                cin.ignore();
                getline (cin , inputToDecrypt);
                decryptLoop = true;
                while (decryptLoop)
                {
                    decryptLoop = stringLengthTillSpace(inputToDecrypt);
                    convertIntoStringArray( inputToDecrypt);

                }
                cout << "\033[38;5;45m Decrypted Message\033[38;5;15m:  ";
                for (int x = 0; x<= mainNewidx - 1; x++ )
                {
                    char letter = decryptedDecimalArray[x];
                    cout << letter;
                }

                cout << "\n\n\033[38;5;45m Enter to exit\033[38;5;41m:";
                getch();
            }
            else if (decryptionOption == 2)
            {
                decryptIndex = -1;
                lastdecryptIdx = 0;
                mainNewidx = 0;
                int binaryOption;

                clearScreen();
                cout << "\033[38;5;45m Enter Binary value to Decrypt(space at end)\033[38;5;15m: ";
                cin.ignore();
                getline (cin , inputToDecrypt);
                decryptLoop = true;
                while (decryptLoop)
                {
                    decryptLoop = stringLengthTillSpace(inputToDecrypt);
                    decryptBinaryToDecimal( inputToDecrypt);

                }

                clearScreen();
                cout << "\033[38;5;45m Enter " << endl;
                cout << "\033[38;5;15m 1)\033[38;5;208m   If you want to see original Message " << endl;
                cout << "\033[38;5;15m 2)\033[38;5;208m   If yoou want to see Decimal decryption" << endl;
                cout << "\033[38;5;15m 3)\033[38;5;208m   Exit" << endl << endl;
                cout << "\n\n\033[38;5;45m Choose the Option\033[38;5;41m:";
                cin >> binaryOption;
                
                if(binaryOption == 2)
                {
                    cout << "\033[38;5;45m Decrypted Message\033[38;5;15m:  ";
                    for (int x = 0; x < mainNewidx-1; x++ )
                    {
                        
                        cout << decryptedDecimalArray[x];
                        cout << " ";
                    }
                    cout << "\n\n\033[38;5;45m Enter to exit\033[38;5;41m:";
                    getch();
                }
                if(binaryOption == 1)
                {
                    cout << "\033[38;5;45m Decrypted Message\033[38;5;15m:  ";
                    for (int x = 0; x < mainNewidx; x++ )
                    {
                        char letter = decryptedDecimalArray[x];
                        cout << letter;
                    }
                    cout << "\n\n\033[38;5;45m Enter to exit\033[38;5;41m:";
                    getch();

                }

            }
            else if (decryptionOption == 3)
            {
                clearScreen();
                cout << "\033[38;5;196mWork have been done till decimal: " << endl;
                cout << "\033[38;5;45mPress any key to go back.." << endl;
                getch();
            }
            
            else if (decryptionOption == 4)
            {
                clearScreen();
                cout << "\033[38;5;196mWork have been done till decimal: " << endl;
                cout << "\033[38;5;45mPress any key to go back.." << endl;
                getch();
            }
        }

        else if (mainOption == 4)
        {
            return 0;
        }
        else
        {
            cout << "\033[38;5;196mYou Have Entered Wrong Credentials: " << endl;
            cout << "\033[38;5;45mPress any key to go back.." << endl;
            getch();
        }
    }
}

void printTitle()
{
cout << "\033[38;5;220m ________________________________________________________________________________" << endl;
cout << "\033[38;5;220m|________________________________________________________________________________|" << endl;   
cout << "||\033[38;5;45m   ___    ___    _  _  __   __  ___   ___   _____   ___    ___    _  _   ___  \033[38;5;220m||" << endl;
cout << "||\033[38;5;45m  / __|  / _ \\  | \\| | \\ \\ / / | __| | _ \\ |_   _| |_ _|  / _ \\  | \\| | / __| \033[38;5;220m||" << endl;
cout << "||\033[38;5;45m | (__  | (_) | | .` |  \\ V /  | _|  |   /   | |    | |  | (_) | | .` | \\__ \\ \033[38;5;220m||" << endl;
cout << "||\033[38;5;45m  \\___|  \\___/  |_|\\_|   \\_/   |___| |_|_\\   |_|   |___|  \\___/  |_|\\_| |___/ \033[38;5;220m||" << endl;
cout << "||______________________________________________________________________________||" << endl<< endl << endl;
                                                                              

}
void gotoxy( int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void clearScreen()
{
    
    system("cls");
    printTitle();
}

void printSubMenu(string subMenu)
{
    
    string totalMenu = subMenu + "  Menu";

    cout << "\033[38;5;220m\t\t\t\t   " << totalMenu << endl;
    cout << "\t\t\033[38;5;45m   _____________________________________________" << endl << endl;
}

int mainMenu()
{  
    int mainOption;

    cout << "\033[38;5;208m1.     Convertions" << endl;
    cout << "2.     Encryption" << endl;
    cout << "3.     Decryption" << endl;
    cout << "4.     Exit" << endl << endl;
    cout << "\033[38;5;45mChoose the option\033[38;5;15m: ";
    cin >> mainOption;

    return mainOption;

}

int convertionMenu()
{
    int convertionOption;

    cout << "\033[38;5;45m Enter the Type of input Value From Options Given Below" << endl;
    cout << "\033[38;5;15m 1)\033[38;5;208m   Binary " << endl;
    cout << "\033[38;5;15m 2)\033[38;5;208m   Decimal" << endl;
    cout << "\033[38;5;15m 3)\033[38;5;208m   Hexadecimal" << endl;
    cout << "\033[38;5;15m 4)\033[38;5;208m   Octal" << endl;
    cout << "\033[38;5;15m 5)\033[38;5;208m   Exit" << endl << endl ;

    cout << "\033[38;5;45mChoose the option\033[38;5;15m: ";
    cin >> convertionOption; 

    return convertionOption;   
}

void convertDecimalIntoOctal(int decimal)
{
    int reminder;
    int convertedOctal[32];
    int idx = 0;
   
    if (index == 0)
    {
        cout << "\n\033[38;5;208mOctal\033[38;5;15m: ";
    }

    if( decimal == 0)
    {
        cout << "0";
    }
    
    while(decimal > 0)
    {
        reminder = decimal % 8;
        convertedOctal[idx] = reminder;
        if( decimal == 1)
        {
            decimal = 0;
        }
        else
        {
            decimal = decimal / 8;
        }
        idx++;

    }
    

    for( int i = idx - 1; i >= 0; i--)
    {
        cout <<convertedOctal[i] ;
    }

}

void convertDecimalIntoBinary(int decimal)
{
    int reminder;
    int convertedBinary[32];
    int idx = 0;
    
    if (index == 0)
    {
        cout << "\n\033[38;5;208mBinary\033[38;5;15m: ";
    }
    if( decimal == 0)
    {
        cout << "0";
    }
    while(decimal > 0)
    {
        reminder = decimal % 2;
        convertedBinary[idx] = reminder;
        if( decimal == 1)
        {
            decimal = 0;
        }
        else
        {
            decimal = decimal / 2;
        }
        idx++;

    }
    
    for( int i = idx - 1; i >= 0; i--)
    {
        cout <<convertedBinary[i] ;
    }

}

void decimalIntoHexadecimal( int decimal)
{
    int reminder;
    char convertedBase16[128];
    int idx = 0;
    
    if (index == 0)
    {
        cout << "\n\033[38;5;208mHexadecimal\033[38;5;15m: ";
    }

    if( decimal == 0)
    {
        cout << "0";
    }
    while(decimal > 0)
    {
        reminder = decimal % 16;
        convertedBase16[idx] = hexaDecimalValues[reminder];
        if( decimal == 1)
        {
            decimal = 0;
        }
        else
        {
            decimal = decimal / 16;
        }
        idx++;

    }
    
    for( int i = idx - 1; i >= 0; i--)
    {
        cout <<convertedBase16[i];
    }
}

bool binaryNumberValidation(int binaryNumber)
{
    int checkMode;

    while(binaryNumber != 0 )
    {
        checkMode = binaryNumber % 10;
        if (checkMode == 0 || checkMode == 1)
        {
            binaryNumber = binaryNumber / 10;
        }
        else 
        {
            return false;
        }
    }
    
    return true;
}

int binaryIntoDecimal(int binary)
{
    int reminder;
    int count = 0;
    int sum = 0;
    while (binary != 0)
    {
        reminder = binary % 10;
        sum =  sum + ( reminder * power(count, 2));
        binary = binary / 10;
        count ++;
    }
    return sum;
}

int power(int exponent, int base) 
{
    int product = 1;
    for (int i = 0; i < exponent; ++i)
     {
        product *= base;
    }
    return product;
}

int hexaintodecimal(string hexa)
{
    int sum = 0;
    int count = 0;
    int powerCount = 0;

    while( hexa[count] != '\0')
    {
        count++;
    }
    count = count - 1;
    for (int i = count; i >= 0; i--)
    {
        for (int x = 0; x < 16; x++)
        {
            if(hexa[i] == hexaDecimalValues[x])
            {
                sum = sum + x * (power(powerCount, 16));
                powerCount++;
                break;
            } 
        }
    }
    return sum;

}

int octalIntoDecimal(int octal)
{
    int reminder;
    int count = 0;
    int sum = 0;
    while (octal != 0)
    {
        reminder = octal % 10;
        sum =  sum + ( reminder * power(count, 8));
        octal = octal / 10;
        count ++;
    }
    return sum;
}

int encryptionMenu()
{
    int encryptionOption;

    cout << endl <<endl << "\033[38;5;40m Enter the Type in which you want to encrypt given message: " << endl;
    cout << "\033[38;5;15m 1)\033[38;5;208m   Decimal " << endl;
    cout << "\033[38;5;15m 2)\033[38;5;208m   Binary" << endl;
    cout << "\033[38;5;15m 3)\033[38;5;208m   Hexadecimal" << endl;
    cout << "\033[38;5;15m 4)\033[38;5;208m   Octal" << endl;
    cout << "\033[38;5;15m 5)\033[38;5;208m   Exit" << endl << endl ;

    cout << "\033[38;5;45m Choose the option\033[38;5;15m: ";
    cin >> encryptionOption; 

    return encryptionOption;

}

void convertIntoDecimalArray(string inputString)
{
    int asciiValue;
    int stringIdx = 0;

    while (inputString[stringIdx] != '\0')
    {
        asciiValue = inputString[stringIdx];
        encryptedDecimalArray[stringIdx] = asciiValue;
        stringIdx++;
    }
    index = stringIdx - 1;
}

int decryptionMenu()
{
    int decryptionOption;

    cout << endl <<endl << "\033[38;40m You can use Following decryption bases: " << endl;
    cout << "\033[38;5;15m 1)\033[38;5;208m   Decimal " << endl;
    cout << "\033[38;5;15m 2)\033[38;5;208m   Binary" << endl;
    cout << "\033[38;5;15m 3)\033[38;5;208m   Hexadecimal" << endl;
    cout << "\033[38;5;15m 4)\033[38;5;208m   Octal" << endl;
    cout << "\033[38;5;15m 5)\033[38;5;208m   Exit" << endl << endl ;

    cout << "\033[38;5;45m Choose the option\033[38;5;15m: ";
    cin >> decryptionOption; 

    return decryptionOption;

}

bool stringLengthTillSpace(string encryptedMessage)
{
    int i = decryptIndex + 1;
    if ( encryptedMessage[i] == '\0')
    {
        return false;
        
    }
    while (encryptedMessage[i] != ' ' && encryptedMessage[i] != '\0' )
    {
        i++;
    }
    decryptIndex = i;
    return true;
}

void convertIntoStringArray( string encryptedMessage)
{
    int newIndex = decryptIndex - 1;
    char number[3];
    char zeroValue = '0';
    int numIdx = 0;
    int countLoop = 0;
    int singleValue = 0;
    int exactValue = 0;
    

    for (int i = newIndex; i >= lastdecryptIdx; i--)
    {
        if (countLoop == 0)
        {
            number[numIdx] = encryptedMessage[i];
            singleValue = number[numIdx] - zeroValue;

            exactValue = exactValue + singleValue;
        }
        else if (countLoop == 1)
        {
            number[numIdx] = encryptedMessage[i];
            singleValue = number[numIdx] - zeroValue ;
            singleValue = singleValue * 10;
            exactValue = exactValue + singleValue;
        }
        
        else if ((newIndex - lastdecryptIdx)  == 2 )
        {
            number[numIdx] = encryptedMessage[i];
            singleValue = number[numIdx] - zeroValue ;
            singleValue = singleValue * 100;
            exactValue = exactValue + singleValue;

        }
        countLoop++;
        numIdx++;
    }
    decryptedDecimalArray[mainNewidx] = exactValue;
    mainNewidx ++;
    lastdecryptIdx = decryptIndex + 1 ;
    
}


void decryptBinaryToDecimal( string encrytedMessage)
{
    int count = 0;
    int newIndex = decryptIndex - 1;
    int sum = 0;
    int binary[16];
    int firstloopcount = 0;
    for ( int i = lastdecryptIdx; i <= newIndex; i++ )
    {
        binary[firstloopcount] = encrytedMessage[i];
        if(binary[firstloopcount] == 49)
        {
            binary[firstloopcount] = 50 - binary[firstloopcount];
        }
        else if(binary[firstloopcount] == 48)
        {
            binary[firstloopcount] = 48 - binary[firstloopcount];
        }
        firstloopcount++;
    }
    
    for (int x = firstloopcount - 1 ; x >= 0; x--)
    {
        sum =  sum + ( binary[x] * power(count, 2));
        count ++;
    }

    decryptedDecimalArray[mainNewidx] = sum;
    mainNewidx ++;
    lastdecryptIdx = decryptIndex + 1;

}
