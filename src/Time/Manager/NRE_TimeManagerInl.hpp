 
    /**
     * @file NRE_TimeManagerInl.hpp
     * @brief Implementation of Micro's API's Object : TimeManager
     * @author Louis ABEL
     * @date 25/11/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {
            
            Time::Time() : milliseconds(0), seconds(0), minutes(0), hours(0) {
            }
            
            Time::Time(int h, int m, int s, int ms) : milliseconds(ms), seconds(s), minutes(m), hours(h) {
            }
            
            int Time::add(long amount, TimeUnit unit) {
                int& current = *(&milliseconds + unit);
                int overflow = (current + amount) / UNIT_OVERFLOW[unit];
                current = (current + amount) % UNIT_OVERFLOW[unit];
                if (overflow > 0 && unit < HOURS) {
                    overflow = add(overflow, static_cast <TimeUnit> (unit + 1));
                }
                return overflow;
            }
            
            Date::Date() : day(0), month(0), year(1900), time() {
            }
            
            Date::Date(int y, int mt, int d, int h, int m, int s, int ms) : day(d), month(mt), year(y), time(h, m, s, ms) {
            }
    
            void Date::add(long amount, TimeUnit unit) {
                if (unit >= DAYS) {
                    switch (unit) {
                        case (YEARS) : {
                            year += amount;
                            add(0, DAYS);
                            break;
                        }
                        case (MONTHS) : {
                            int overflow = (month + amount) / 12;
                            month = (month + amount) % 12;
                            year += overflow;
                            add(0, DAYS);
                            break;
                        }
                        case (DAYS) : {
                            day += amount;
                            int overflow = getDaysOverflow();
                            while (day > overflow) {
                                day = day - overflow;
                                month++;
                                if (month >= 12) {
                                    month = 0;
                                    year++;
                                }
                                overflow = getDaysOverflow();
                            }
                            break;
                        }
                    }
                } else {
                    add(time.add(amount, unit), DAYS);
                }
            }
            
            int Date::getDaysOverflow() const {
                int overflow = DAYS_OVERFLOW[month];
                if (month == 1) {
                    if ((year % 4 == 0 && year % 100 == 0) || (year % 400 == 0)) {
                        overflow++;
                    }
                }
                return overflow;
            }
            
            String TimeManager::getInfo() const {
                return String(current.day + 1) + "/" + String(current.month + 1)+ "/" + String(current.year) + " at " + String(current.time.hours) + ":" + String(current.time.minutes) + ":" + String(current.time.seconds) + ":" + String(current.time.milliseconds);
            }
            
            void TimeManager::setDate(Date const& ref) {
                current = ref;
            }
            
            void TimeManager::loop(long delta) {
                current.add(delta, TimeUnit::MILLISECONDS);
            }
        
        }
    }