#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <functional>
using namespace std;
using std::vector;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment>& segments) {
    vector<int> points;
    //write your code here
    //sort from left ---> increasing start
    for (int i = 0; i < segments.size() - 1; i++)
    {
        for (int j = 0; j < segments.size() - i - 1; j++)
        {
            if (segments[j].start > segments[j + 1].start)
            {
                swap(segments[j], segments[j + 1]);
            }
        }
    }


    int index = 0;
    vector<int> jointed_seg;  // can we delete this? I think yes

    while (index < segments.size())
    {
        vector<int> jointed_seg;
        jointed_seg.push_back(index);
        index++;
        while (index < segments.size())
        {
            bool jointed = true;
            for (int i = 0; i < jointed_seg.size(); i++)
            {
                if (segments[index].start <= segments[jointed_seg[i]].end)
                {
                    continue;
                }
                else
                {
                    jointed = false;
                    break;
                }
            }
            if (jointed)
            {
                jointed_seg.push_back(index);
                index++;
            }
            else
            {
                break;
            }
        }

        int max = segments[jointed_seg[0]].start;
        for (int i = 0; i < jointed_seg.size(); i++)
        {
            if (segments[jointed_seg[i]].start > max)
                max = segments[jointed_seg[i]].start;
        }
        points.push_back(max);
    }

    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}