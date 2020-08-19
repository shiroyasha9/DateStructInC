#include<stdio.h>

// Creating the basic struct here
typedef struct date{
    int day1,mon1,year1;
	int day2,mon2,year2;

} date;

//Creates a date struct
date createDate(){
	date d;
	return d;
}


//Function that checks if the dates are valid or not, not used indiviually but is used in the next function below
int valid_date(int day, int mon, int year)
{
    int is_valid = 1, is_leap = 0;

    if (year >= 1800 && year <= 9999)
    {

        //  check whether year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            is_leap = 1;
        }

        // check whether mon is between 1 and 12
        if(mon >= 1 && mon <= 12)
        {
            // check for days in feb
            if (mon == 2)
            {
                if (is_leap && day == 29)
                {
                    is_valid = 1;
                }
                else if(day > 28)
                {
                    is_valid = 0;
                }
            }

            // check for days in April, June, September and November
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
            {
                if (day > 30)
                {
                    is_valid = 0;
                }
            }

            // check for days in rest of the months
            // i.e Jan, Mar, May, July, Aug, Oct, Dec
            else if(day > 31)
            {
                is_valid = 0;
            }
        }

        else
        {
            is_valid = 0;
        }

    }
    else
    {
        is_valid = 0;
    }

    return is_valid;

}

//Uses the above function to check if any date is invalid, if yes, quits after printing the statement
void check_for_valid(int day1, int day2, int mon1, int mon2, int year1, int year2){
	 if(!valid_date(day1, mon1, year1)){
        printf("First date is invalid.\n");
        exit(0);
    }

    if(!valid_date(day2, mon2, year2)){
        printf("Second date is invalid.\n");
        exit(0);
    }
}

// Targets 1st requirement from our task, prints date in 3 different formats
void print_dates(int day, int mon, int year){
	int choice,month_word,yr;
	do {
		printf("\nSelect which format to see the date in:");
		printf("\n1. YYYY-MM-DD");
		printf("\n2. YY-MM-DD");
		printf("\n3. DD Month YYYY");
		printf("\n4. Quit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Date is : %d-%02d-%02d", year,mon,day);
				break;
			case 2:
				yr = year % 100;
				printf("Date is : %02d-%02d-%02d", yr,mon,day);
				break;
			case 3:
				switch(mon){
					case 1:
						month_word = "January";
						break;
					case 2:
						month_word = "Febuary";
						break;
					case 3:
						month_word = "March";
						break;
					case 4:
						month_word = "April";
						break;
					case 5:
						month_word = "May";
						break;
					case 6:
						month_word = "June";
						break;
					case 7:
						month_word = "July";
						break;
					case 8:
						month_word = "August";
						break;
					case 9:
						month_word = "September";
						break;
					case 10:
						month_word = "October";
						break;
					case 11:
						month_word = "November";
						break;
					case 12:
						month_word = "December";
						break;
				}
				printf("Date : %02d %s %d", day, month_word, year);
				break;
			case 4:
				choice = 4;
		}
	
	} while(choice !=4);
	
}


//Used for adding days to date
int isLeap(int y)
{
    if (y%100 != 0 && y%4 == 0 || y %400 == 0)
        return 1;

    return 0;
}



// Given a date, returns number of days elapsed
// from the  beginning of the current year (1st
// jan).
int offsetDays(int d, int m, int y)
{
    int offset = d;

    switch (m - 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }

    if (isLeap(y) && m > 2)
        offset += 1;

    return offset;
}

// Given a year and days elapsed in it, finds
// date by storing results in d and m.
void revoffsetDays(int offset, int y, int *d, int *m)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };

    if (isLeap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    *d = offset;
    *m = i;
}

// Add x days to the given date.
void addDays(int d1, int m1, int y1, int x)
{
    int offset1 = offsetDays(d1, m1, y1);
    int remDays = isLeap(y1)?(366-offset1):(365-offset1);

    // y2 is going to store result year and
    // offset2 is going to store offset days
    // in result year.
    int y2, offset2;
    if (x <= remDays)
    {
        y2 = y1;
        offset2 = offset1 + x;
    }

    else
    {
        // x may store thousands of days.
        // We find correct year and offset
        // in the year.
        x -= remDays;
        y2 = y1 + 1;
        int y2days = isLeap(y2)?366:365;
        while (x >= y2days)
        {
            x -= y2days;
            y2++;
            y2days = isLeap(y2)?366:365;
        }
        offset2 = x;
    }

    // Find values of day and month from
    // offset of result year.
    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);

    printf("New Date after adding %d days is %d %d %d \n",x, d2, m2, y2);
}

//Actual Function which will add the days
int add_days(int day, int mon, int year, int days)
{
    addDays(day, mon, year, days);
    return 0;
}



//Subtracts both of the dates, is a bit complex, examine the code properly
int subtract_two_dates(int day1, int day2, int mon1, int mon2, int year1, int year2){
	int day_diff, mon_diff, year_diff;
	int mon2_duplicate = mon2;
	int year2_duplicate = year2;
	if(day2 < day1)
    {      
        // borrow days from february
        if (mon2 == 3)
        {
            //  check whether year is a leap year
            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) 
            {
                day2 += 29;
            }

            else
            {
                day2 += 28;
            }                        
        }

        // borrow days from April or June or September or November
        else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) 
        {
           day2 += 30; 
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
           day2 += 31;
        }

        mon2 = mon2 - 1;
    }

	//Very naive implementation to check if the year is same and the month is different, if this line is not there, gives a wrong value
	if ((year2 == year1) && (mon2_duplicate < mon1)){
		mon2 -= 11;
	}
	
	
	
	//Very naive implementation to check if the year is same, if this line is not there, gives a wrong value
	if (year2 == year1){
		year2 += 1;
	
	}
	//Very naive implementation to check if the months are same, if this line is not there, gives a wrong value	
	if (mon2_duplicate == mon1){
		mon2 -= 11;
		
	}
	
	
	//Used to get the dates 1 year ago
    if (mon2 < mon1)
    {
        mon2 += 12;
        year2 -= 1;
    }
	
	if((year2_duplicate == year1) && (mon1 < mon2_duplicate)){
		year2 = 0;
		year1 = 0;
	}
		
	//Subtracts finally	
    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;

    printf("Difference: %d years %02d months and %02d days.", year_diff, mon_diff, day_diff);

    return 0;
}


int extract(int day, int mon, int year){
	int choice;
	do{
		printf("Enter the number of the field you want to extract: ");
		printf("\n1.Day");
		printf("\n2.Month");
		printf("\n3.Year");
		printf("\n4.Quit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Day is %02d\n", day);
				break;
			case 2:
				printf("Month is %02d\n", mon);
				break;
			case 3:
				printf("Year is %d\n", year);
				break;
			case 4:
				choice = 4;
		}
	}while(choice != 4);
	return 0;
}