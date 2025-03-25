#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> assignInterviewers(vector<int> &start, vector<int> &end) 
{
    int n = start.size();
    vector<pair<int, int>> interviews; // (start_time, index)

    for (int i = 0; i < n; i++) 
    {
        interviews.push_back({start[i], i});
    }
    sort(interviews.begin(), interviews.end()); // Sort by start time

    vector<pair<int, int>> interviewers; // interviewer_id and end time
    vector<vector<int>> assignment; 
    int interviewer_count = 0;

    for (int i = 0; i < n; i++) {
        int s = interviews[i].first;
        int index = interviews[i].second;
        bool assigned = false;
        
        // Try assigning to an existing interviewer
        for (int j = 0; j < interviewers.size(); ++j)
        {
            if (interviewers[j].second <= s)
            {
                assignment[interviewers[j].first].push_back(index+1);
                interviewers[j].second = end[index];
                assigned = true;
                break;
            }
        }

        // If no existing interviewer is available, create a new one
        if (!assigned) {
            assignment.push_back({index + 1});
            interviewers.push_back({interviewer_count,end[index]});
            interviewer_count++;
        }
    }
        for (auto &interviewer : assignment) {
            sort(interviewer.begin(), interviewer.end());
    }
    return assignment;
}

int main() {
    vector<int> start = {910, 1100, 1030, 1200, 1120, 1010, 1045, 1130, 900, 1240, 1010, 955, 1105, 1135};
    vector<int> end   = {1010, 1120, 1045, 1230, 1155, 1030, 1115, 1200, 1000, 1300, 1100, 1030, 1135, 1200};

    vector<vector<int>> result = assignInterviewers(start, end);

    cout << "Interview Assignments:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Interviewer " << (i + 1) << ": ";
        for (int id : result[i]) cout << id << " ";
        cout << endl;
    }

    return 0;
}
