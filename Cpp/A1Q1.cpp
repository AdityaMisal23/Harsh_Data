*
READ ME FIRST

This is a Menu Driven Program in which I have Used a class and and other functoions Outside the class 
I have passed Class object by reference to these functions 
*/



#include <iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;    

    public:
        int getDay(){
            return day;
        }    
        int getMonth(){
            return month;
        }
        int getYear(){
            return year;
        }
        int setDay(int day){
            this->day = day;
        }
        int setMonth(int month){
            this->month = month;
        }
        int setYear(int year){
            this->year = year;
        }
};
bool isLeap(int year){
    if(year%100!=0 && year%4==0){
        return true;
    }
    else if(year%100==0 && year%400==0){
        return true;
    }
    return false;
}
void initDate(Date* d1)
        {   d1->setYear(2002);
            d1->setMonth(5);
            d1->setDay(23);
            cout<<"\nThe date is successfully saved to default...:)";
            
        }
void printDateOnConsole(Date* d1){
    cout<<"\nCurrent date is => "<<d1->getDay()<<" : "<<d1->getMonth()<<" : "<<d1->getYear()<<endl; 
}
void acceptDateFromConsole(Date *d1){
    int count =0;
    bool leap=true;
    cout<<"Enter year";
    int year;
    cin>>year;
    d1->setYear(year);
    if(isLeap(year)){
        leap = true;
    }
    else{
        leap = false;
    }
    while(true){
        if(count == 0){
            cout<<"\nEnter Month";
            int month;
            cin>>month;
            d1->setMonth(month);
            if(month>12 && month<1){
                cout<<"\nEnter month between 1 and 12";
                continue;
            }
            count++;
        }
        cout<<"Enter Day";
        int day;
        cin>>day;
        d1->setDay(day);
        if(d1->getMonth() ==1 || d1->getMonth() ==3 || d1->getMonth() ==5 || d1->getMonth() ==7 || d1->getMonth() ==8 || d1->getMonth() ==10 || d1->getMonth() ==12){
            if(day<=31 && day>=1){
                break;
            }
            else{
                cout<<"\nEnter day between 1 to 31\n";
                continue;
            }
        }
        if(d1->getMonth() ==2){
            if(leap){
                if(day<=29 && day>=1){
                    break;
                }
                else{
                    cout<<"Its a leap year, so enter day between 1 and 29";
                    continue;
                }
            }
            else{
                if(day<=28 && day>=1){
                    break;
                }
                else{
                    cout<<"Its not a leap year, so enter day between 1 and 28";
                    continue; 
                }
            }
        }
        else{
            if(day<=30 && day>=1){
                break;
            }
            else{
                cout<<"Enter day between 1 to 30";
                continue;
            }
        }
    }    
    
}
void enterChoice(Date* d1){
    int choice=1;
    while(choice!=0){
        cout<<"\nEnter your choice:\n0 : For Exit\n1 : add date\n2 : Show date\n3 : set date to default\n4 : check if current year is leap or not? ";
        cin>>choice;
        switch(choice){
            case 0: cout<<"\nThank You for using Application\n";
                    break;
            case 1: acceptDateFromConsole(d1);
                    break;
            case 2: printDateOnConsole(d1);
                    break;
            case 3: initDate(d1);
                    break;
            case 4 :if(isLeap(d1->getYear())){
                        cout<<"Its a leap year";
                    }
                    else{
                        cout<<"Its not a leap year";
                    }
                    break;
            default: cout<<"\nWrong choice";                
        }
    }
}
int main(){
    Date d;
    enterChoice(&d);
    return 0;
}
