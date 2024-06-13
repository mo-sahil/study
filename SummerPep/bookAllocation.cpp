#include <bits/stdc++.h>

using namespace std;

int countStudents(vector<int>& books, int mid) {
    int students = 1;
    int pages = 0;

    for(int i = 0; i<books.size(); i++) {
        if(pages + books[i] <= mid) pages += books[i];
        else {
            students++;
            pages = books[i];
        }
    }

    return students;
}

int bookAllocation(vector<int>& books, int students) {
    int n = books.size();

    if(n < students) return -1;

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(countStudents(books,mid) > students) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}

int main() {
    vector<int> books = {25, 46, 28, 49, 24};
    int students = 4;

    cout << "Minimum number of pages: " << bookAllocation(books, students) << endl;
}