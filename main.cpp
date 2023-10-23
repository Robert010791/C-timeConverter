//Robert Robbins
//Project two



#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;



//InvestmentData  class below with function names
class InvestmentData {  //This class holds the investment information for each year. The userInvestmentData class uses a vector that stores 
    public:             // InvestmentData objects for each year of investment duration

    void setBalance(double t_investment);
    void setInterest(double t_interest);
    void setYear(int t_year);

    void printData();

    private:
    double m_endOfYearBalance;
    double m_interestTotPerYear;
    int    m_investmentYear;
};
//InvestmentData  class above with function names


// InvestmentData class function bodies below
void InvestmentData::setBalance(double t_investment){
    m_endOfYearBalance = t_investment;
    }
    
void InvestmentData::setInterest(double t_interest){
    m_interestTotPerYear = t_interest;
    }

void InvestmentData::setYear(int t_year){
    m_investmentYear = t_year;
    }

void InvestmentData::printData(){ // This is the function used to print each row of the investment data table. The UserInvestment class 
    cout << fixed << setprecision(2) << setfill(' ') << "   " << m_investmentYear; // calls this while looping throught the InvestmentData vector.
    cout << setw(15) << " " << m_endOfYearBalance;
    cout << setw(30)  << " " << m_interestTotPerYear << endl;
}
// InvestmentData class function bodies above









//UserInvestmentData class below with function names.
class UserInvestmentData {
    public:

    UserInvestmentData();
    
     void setInvestmentValue();
     void setInvestmentValueNoDeposit();


     void setInitialAmt(double t_inputAmt);

     void setMonthlyDeposit(double t_inputDepo);

     void setInterestRate(double t_inputInterest);

     void setYears(int t_inputYears);

     void printInvestmentTable();

    double getInitialAmt(){return m_initialInvestment;}
    double getMonthlyDepo(){return m_monthlyDeposit;}
    double getInterestRate(){return m_annualInterst;}
    int getYears() {return m_numOfYears;}

    private:
        double m_initialInvestment;
        double m_monthlyDeposit;
        double m_annualInterst;
        int m_numOfYears;
        vector<InvestmentData> investmentTableData;
        vector<InvestmentData> initialInvestmentTableData;
};
//UserInvestmentData class above with function names.


//UserInvestmentData class function bodies below
UserInvestmentData::UserInvestmentData(){ //  Constructor sets all investment values to 0  initially
            m_initialInvestment = 0.0;
            m_monthlyDeposit = 0.0;
            m_annualInterst = 0.0;
            m_numOfYears = 0;
}

void UserInvestmentData::printInvestmentTable(){  //This function prints out the investment table headers and then loops through the InvestmentData vectors
    InvestmentData currentData;                     // and calls the InvestmentData print function for each value.
    int i;

    cout << setw(5) << " " << "Balance and Interest Without Aditional Monthly Deposists" << setw(5) << " " << endl;
    cout << setfill('=') << setw(68) << "=" << endl;
    cout << setfill(' ')  << " " << "Year" << setfill(' ') << setw(9) << " ";
    cout << "Year End Balance" << setfill(' ') << setw(9) << " " << "Year End Earned Interest" << endl;
    cout << setfill('-') << setw(68) << "-" << endl;

     for (i = 0; i < initialInvestmentTableData.size(); ++i){
        currentData = initialInvestmentTableData.at(i);
        currentData.printData();
    }
    cout << endl;
    
        cout << setw(5) << " " << "Balance and Interest With Aditional Monthly Deposists" << setw(5) << " " << endl;
    cout << setfill('=') << setw(68) << "=" << endl;
    cout << setfill(' ')  << " " << "Year" << setfill(' ') << setw(9) << " ";
    cout << "Year End Balance" << setfill(' ') << setw(9) << " " << "Year End Earned Interest" << endl;
    cout << setfill('-') << setw(68) << "-" << endl;

    for (i = 0; i < investmentTableData.size(); ++i){
        currentData = investmentTableData.at(i);
        currentData.printData();
    }
    cout << endl;

}

//Setter functions that are called with user input as arguments to set values for investment.VVV
void UserInvestmentData::setInitialAmt(double t_inputAmt) {
    m_initialInvestment = t_inputAmt;}
void UserInvestmentData::setMonthlyDeposit(double t_inputDepo){
    m_monthlyDeposit = t_inputDepo;}
void UserInvestmentData::setInterestRate(double t_inputInterest){
    m_annualInterst = t_inputInterest;}
void UserInvestmentData::setYears(int t_inputYears){
    m_numOfYears = t_inputYears;}
//Setter functions that are called with user input as arguments to set values for investment. ^^^^


//This function sets data for investment of intial amount with no monthly deposits. 
void UserInvestmentData::setInvestmentValueNoDeposit(){
        InvestmentData currYearDataNoDepo;
        double currentVal = m_initialInvestment;
        double interestAmt;
        double interestTot;
        int years = m_numOfYears;
        int i;
        int j;

     for (i = 0; i < years; ++i){           

            interestTot = 0;
            for (j = 0; j < 12; ++j){
                interestAmt = ((currentVal) * (5.0/100.0)) / 12;
                currentVal = currentVal + interestAmt;
                interestTot = interestTot + interestAmt;
                interestAmt = 0;
            }
            currYearDataNoDepo.setBalance(currentVal);
            currYearDataNoDepo.setYear(i + 1);
            currYearDataNoDepo.setInterest(interestTot);

            initialInvestmentTableData.push_back(currYearDataNoDepo);
        }
}
        //The above and below functions use the investment data the user inputs to calulate the investment outcome.
            //The functions use nested for loops. The inner loops is set two itereate 12 times for each month in a year. The inner loop calculates the 
            //investment value for the year. The outer loop is set to itereate for the number of years the user inputs. 

//This function sets data for investment of intial amount with monthly deposits. 
void UserInvestmentData::setInvestmentValue(){

        InvestmentData currYearData;
        double currentVal = m_initialInvestment;
        double interestAmt;
        double interestTot;
        int years = m_numOfYears;
        int i;
        int j;

     for (i = 0; i < years; ++i){
        
        for (i = 0; i < years; ++i){

            interestTot = 0;
            for (j = 0; j < 12; ++j){
                interestAmt = ((currentVal + m_monthlyDeposit) * (5.0/100.0)) / 12;
                currentVal = currentVal + m_monthlyDeposit + interestAmt;
                interestTot = interestTot + interestAmt;
                interestAmt = 0;
            }

            currYearData.setBalance(currentVal);
            currYearData.setYear(i + 1);
            currYearData.setInterest(interestTot);

            investmentTableData.push_back(currYearData);
        }
}
}
//UserInvestmentData class function bodies above



//Below is the display menu function. It gets called by the menu function.
void displayMenu(UserInvestmentData& investment) {
            cout << setw(50)<< setfill('*') << "*"  << endl;
        cout << right << setw(20) << setfill('*') << " " << "Data Input"<< left << setw(20) << setfill('*') << " "  << endl;
        cout << "  Type number and hit enter to set investment value" << endl;
        cout << "  1- Initial Investment Amount:  " << "$" << investment.getInitialAmt() << endl;
        cout << "  2- Monthly Deposit:  " << "$" << investment.getMonthlyDepo() << endl;
        cout << "  3- Annual Interest:  " << "%" << investment.getInterestRate() * 100 << endl;
        cout << "  4- Number of years:  " << investment.getYears() << endl;
           cout << endl;

        if (!(investment.getYears() == 0.0) && !(investment.getInterestRate() == 0.0) && !(investment.getMonthlyDepo() == 0)){
            cout << "  Enter 5 to get investment outcome." << endl;
        }

        
        
}


//The munu function is below. It is a series of if statments that take action based on what the user inputs.
void menuFunc(){
    UserInvestmentData investment;
    string userInput;
    double userDataDouble;

    while (userInput != "quit") {

        displayMenu(investment);
            cin >> userInput;

        if (userInput == "1") {
            cout << "Initial Investment Amount " ;
            cin >> userDataDouble;
            investment.setInitialAmt(userDataDouble);
        } else if(userInput == "2"){
            cout << "Monthly Deposit ";
            cin >> userDataDouble;
            investment.setMonthlyDeposit(userDataDouble);
        } else if(userInput == "3") {
            cout << "Annual Interest ";
            cin >> userDataDouble;
            investment.setInterestRate(userDataDouble / 100);
        }else if (userInput == "4"){
            cout << "Number of years ";
            cin >> userDataDouble;
            investment.setYears(userDataDouble);
        } else if (userInput == "5"){
            if (!(investment.getYears() == 0.0) && !(investment.getInterestRate() == 0.0) && !(investment.getMonthlyDepo() == 0)){
            investment.setInvestmentValue();
            investment.setInvestmentValueNoDeposit();
            cout << endl;
            investment.printInvestmentTable();
            break;
            } else {
                cout << "invalid option" << endl;
            }
        } else if (userInput == "quit"){
            cout << "Exiting program";
        }else {
                cout << "invalid option" << endl;
            }
        cout << endl;
    }
    
}


// below is the main function of the program. It starts by calling the menu function which gathers user input. Once the first menu funtion loop
// ends the main function enters a while loop that allows the user to choose to enter a new investment query or exsit the program.
int main() {
    string userInput;

  
    menuFunc();


    while(userInput != "quit"){


    cout << endl;
    cout << "Enter Y to calulate another investment, or enter anyother key if finished" << endl;
    cin >> userInput;
    if (userInput == "y" || userInput == "Y"){
        menuFunc();
    } else {
        cout << "Goodbye" << endl;
        break;
    }
    }
    return 0;
}

