 
    /**
     * @file NRE_TimeManagerInl.hpp
     * @brief Implementation of Micro's API's Object : TimeManager
     * @author Louis ABEL
     * @date 25/11/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {
    
            inline Date::Date() : day(0), month(0), year(1900), milliseconds(0), seconds(0), minutes(0), hours(0) {
            }
    
            inline Date::Date(int y, int mt, int d, int h, int m, int s, int ms) : day(d), month(mt), year(y), milliseconds(ms), seconds(s), minutes(m), hours(h) {
            }
    
            inline void Date::add(long amount, TimeUnit unit) {
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
                    int& current = *(&milliseconds + unit);
                    int overflow = (current + amount) / UNIT_OVERFLOW[unit];
                    current = (current + amount) % UNIT_OVERFLOW[unit];
                    if (overflow > 0) {
                        add(overflow, static_cast <TimeUnit> (unit + 1));
                    }
                }
            }
            
            inline bool Date::operator ==(Date const& d) const {
                if (this == &d) {
                    return true;
                }
                return year == d.year && month == d.month && day == d.day && hours == d.hours && minutes == d.minutes && seconds == d.seconds && milliseconds == d.milliseconds;
            }
    
            inline bool Date::operator !=(Date const& d) const {
                return !(*this == d);
            }
            
            inline bool Date::operator >(Date const& d) const {
                TimeUnit current = YEARS;
                while (current != INVALID) {
                    int const& unit = *(&milliseconds + current);
                    int const& otherUnit = *(&d.milliseconds + current);
                    if (unit > otherUnit) {
                        return true;
                    }
                    if (unit < otherUnit) {
                        return false;
                    }
                    current = static_cast <TimeUnit> (current + 1);
                }
                return false;
            }
    
            inline bool Date::operator <(Date const& d) const {
                TimeUnit current = YEARS;
                while (current != INVALID) {
                    int const& unit = *(&milliseconds + current);
                    int const& otherUnit = *(&d.milliseconds + current);
                    if (unit < otherUnit) {
                        return true;
                    }
                    if (unit > otherUnit) {
                        return false;
                    }
                    current = static_cast <TimeUnit> (current + 1);
                }
                return false;
            }
            
            inline bool Date::operator >=(Date const& d) const {
                return (*this > d) || *this == d;
            }
    
            inline bool Date::operator <=(Date const& d) const {
                return (*this < d) || *this == d;
            }
    
            inline int Date::getDaysOverflow() const {
                int overflow = DAYS_OVERFLOW[month];
                if (month == 1) {
                    if ((year % 4 == 0 && year % 100 == 0) || (year % 400 == 0)) {
                        overflow++;
                    }
                }
                return overflow;
            }
    
            inline String TimeManager::getInfo() const {
                return String(current->day + 1) + "/" + String(current->month + 1)+ "/" + String(current->year) + " at " + String(current->hours) + ":" + String(current->minutes) + ":" + String(current->seconds) + ":" + String(current->milliseconds);
            }
            
            inline Date TimeManager::getCurrent() const {
                return current.get();
            }
    
            inline void TimeManager::setDate(Date const& ref) {
                current = ref;
            }
    
            inline void TimeManager::loop(long delta) {
                current->add(delta, TimeUnit::MILLISECONDS);
                current.update();
            }


            #ifdef NRE_USE_ROM
                inline void TimeManager::addData() {
                    MicroManager::get<RomManager>().addData(current);
                }
            #endif
        
        }
    }