class MyCalendarTwo {
private:
    vector<pair<int, int>> singleBookings;
    vector<pair<int, int>> doubleBookings;
public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (const pair<int, int>& doubleBooking : doubleBookings) {
            if (doubleBooking.first < end && doubleBooking.second > start) {
                return false;  
            }
        }

        for (const pair<int, int>& singleBooking : singleBookings) {
            if (singleBooking.first < end && singleBooking.second > start) {
                int overlapStart = max(singleBooking.first, start);
                int overlapEnd = min(singleBooking.second, end);
                doubleBookings.push_back(make_pair(overlapStart, overlapEnd)); 
            }
        }

        singleBookings.push_back(make_pair(start, end));

        return true;
    }
};

/**
 * Usage:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool result = obj->book(start, end);
 */