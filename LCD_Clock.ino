#include <LiquidCrystal.h>

LiquidCrystal lcd(1,2,4,5,6,7);

void setup(){
    lcd.begin(16,2);
}

void printTime(int sysHour, int sysMinute, int sysSec){
  lcd.setCursor(0,1);
  lcd.print("Time: ");
  
  if(sysHour < 10){
    lcd.print("0");
    lcd.print(sysHour);
  }
  else{
   lcd.print(sysHour); 
  }
  lcd.print(":");
  if(sysMinute < 10){
    lcd.print("0");
    lcd.print(sysMinute);
  }
  else{
    lcd.print(sysMinute);
  }
  lcd.print(":");
  if(sysSec < 10){
    lcd.print("0");
    lcd.print(sysSec);
    return;
  }
  lcd.print(sysSec);
}

void printDayAndDate(char sysDay[10], char sysMonth[6], int currentDate, int sysYear, int sysHour){
  lcd.setCursor(0,0);
  lcd.print(sysDay);
  lcd.print(" ");
  lcd.print(sysMonth);
  lcd.print(" ");
  lcd.print(currentDate);
  lcd.print(" ");
  lcd.print(sysYear);
}

void loop(){
  char days[][10] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  char months[][10] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};

  //----------ENTER HOUR, MINUTES, AND SECONDS----------
  static int sysHour = 23;
  static int sysMinute = 49;
  static int sysSec = 10;
  static int monthNum = 7;
  static int numOfDays = 30; //DO NOT CHANGE
  static int currentDate = 25; //1st Jan, 2nd Jan, etc
  static int sysDay = 7; //Sun, Mon, etc
  static int sysYear = 2020;
  
  
  printTime(sysHour, sysMinute, sysSec);

  
  if(monthNum == 1 || monthNum == 3 || monthNum == 5 || monthNum == 7 || monthNum == 8 || monthNum == 10 || monthNum == 12){
    numOfDays = 31;
  }
  
  if(monthNum == 2){
    numOfDays = 28;
  }

  if((monthNum == 2 && sysYear%4 == 0 && sysYear%100 != 0) || (monthNum == 2 && sysYear%400 == 0)){
    numOfDays = 29;
  }
  
  printDayAndDate(days[sysDay - 1], months[monthNum - 1], currentDate, sysYear, sysHour);
  
  sysSec+=1;
  
  if(sysSec > 59){
    sysSec = 0;
    sysMinute+=1;
  }
  
  if(sysMinute > 59){
    sysMinute = 0;
    sysHour+=1;
  }
  
  if(monthNum > 12){
    sysYear += 1;
    monthNum = 1;
    lcd.clear();
  }

  delay(1000);
  
  if(sysHour > 23){
    sysDay += 1;
    currentDate += 1;
  }
  
  if(currentDate > numOfDays){
    currentDate = 1;
    monthNum += 1;
    lcd.clear();
  }
  
  if(sysDay > 7){
    sysDay = 1;
  }

  if(sysHour > 23){
    sysHour = 0;
  }

}
