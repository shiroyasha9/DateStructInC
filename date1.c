#include<date.h>
#include<stdio.h>
void main(){
    date d = createDate();
    d.day1 = 18;
    d.mon1 = 3;
    d.year1 = 2010;
    d.day2 = 3;
    d.mon2 = 7;
    d.year2 = 2011;

    check_for_valid(d.day1, d.day2, d.mon1, d.mon2, d.year1, d.year2);
    subtract_two_dates(d.day1, d.day2, d.mon1, d.mon2, d.year1, d.year2);
    print_dates(d.day1,d.mon1,d.year1);
    add_days(d.day1,d.mon1,d.year1, 10);   //quit from above to actually see this output
    extract(d.day1,d.mon1,d.year1);

}
