#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        string date, day;
        fflush(stdin);
        cin >> date >> day;
        int DD, MM, YYYY;
        DD = (date[1] - 48) + (date[0] - 48) * 10;
        MM = (date[4] - 48) + (date[3] - 48) * 10;
        YYYY = (date[9] - 48) + (date[8] - 48) * 10 + (date[7] - 48) * 100 + (date[6] - 48) * 1000;
        bool is_leapYear = false;
        if (YYYY % 100 == 0) {
            if (YYYY % 400 == 0) {
                is_leapYear = true;
            }
        } else if (YYYY % 4 == 0) {
            is_leapYear = true;
        }
        int lastDate = 0;
        switch (MM)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            lastDate = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            lastDate = 30;
            break;

        default:
            if (is_leapYear) {
                lastDate = 29;
            } else lastDate = 28;
            break;
        }
        int emptys = 0;
        for (int i = 0; i < 7; i++) {
            if (!(day.compare(days[i]))) {
                emptys = i;
                break;
            }
        }
        int count = 1;
        while (DD != 1) {
            DD--;
            emptys--;
            if (emptys == -1) {
                emptys = 6;
            }
        }
        int back = 0;
        if (emptys + lastDate > 35) {
            back = lastDate - ((lastDate + emptys - 35)) + 1;
        }
        for (int i = 0; i < 13; i++) {
            cout << "|";
            for (int j = 0; j < 13; j++) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        cout << "---";
                    } else cout << "-";
                } else {
                    if (i == 1) {
                        if (j % 2 == 0) {
                            cout << days[j / 2];
                        } else cout << "|";
                    } else if (i == 3) {
                        if (j % 2 == 0) {
                            if (back == 0) {
                                if (emptys != 0) {
                                    cout << " - ";
                                    emptys--;
                                } else {
                                    cout << "  " << count;
                                    count++;
                                }
                            } else {
                                cout << " " << back;
                                if (back == lastDate) {
                                    back = 0;
                                } else {
                                    back++;
                                }
                                emptys--;
                            }
                        } else cout << "|";
                    } else {
                        if (j % 2 == 0) {
                            if (count < 10) {
                                cout << "  " << count;
                                count++;
                            } else if (count <= lastDate) {
                                cout << " " << count;
                                count++;
                            } else cout << " - ";
                        } else cout << "|";
                    }
                }
            }
            cout << "|" << endl;
        }
        cout << endl;
    }
    return 0;
}