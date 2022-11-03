#include <bits/stdc++.h>
using namespace std;

// This function checks if current stream item(key) exists in any of the frames or not
int search(int key, vector<int>& frame_items, int frame_occupied)
{
    for (int i = 0; i < frame_occupied; i++)
        if (frame_items[i] == key)
            return 1;
    return 0;
}

void printOuterStructure(int max_frames){
    printf("Stream\t\t ");

    for(int i = 0; i < max_frames; i++)
        printf("Frame%d\t\t ", i+1);
}
void printCurrFrames(int item, vector<int>& frame_items, int frame_occupied, int max_frames){

    // print current reference stream item
    cout << "\n" << item << "\t\t";

    // print frame occupants one by one
    for(int i = 0; i < max_frames; i++){
        if(i < frame_occupied)
            cout << frame_items[i] << "\t\t";
        else
    cout << "- \t\t";
    }
}
// This Function helps in finding frame that will not be used
// for the longest period of time in future in ref_str[0 ... refStrLen - 1]
int predict(int ref_str[], vector<int>& frame_items, int refStrLen, int index, int frame_occupied)
{
    // For each current occupant in frame item
    // we try to find the frame item that will not be referenced in
    // for the longest in future in the upcoming reference string
    int result = -1, farthest = index;
    for (int i = 0; i < frame_occupied; i++) {
        int j;
        for (j = index; j < refStrLen; j++)
        {
            if (frame_items[i] == ref_str[j])
                { if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }

        // If we find a page that is never referenced in future,
        // return it immediately as its the best
        if (j == refStrLen)
            return i;
    }

    // If none of the frame items appear in reference string
    // in the future then we return 0th index. Otherwise we return result
    return (result == -1) ? 0 : result;
}

void optimalPage(int ref_str[], int refStrLen, int max_frames)
{
    // initially none of the frames are occupied
    vector<int> frame_items;
    printOuterStructure(max_frames);

    // Here we traverse through reference string
    // and check for miss and hit.
    int hits = 0;
    for (int i = 0; i < refStrLen; i++) {

        // If found already in the frame items : HIT
        if (search(ref_str[i], frame_items, frame_items.size())) {
            hits++;
            printCurrFrames(ref_str[i], frame_items, frame_items.size(), max_frames);
            continue;
        }

        // If not found in frame items : MISS

        // If frames are empty then current reference string item in frame
        if (frame_items.size() < max_frames){
            frame_items.push_back(ref_str[i]);
            printCurrFrames(ref_str[i], frame_items, frame_items.size(), max_frames);
        }
        // else we need to use optimal algorithm to find
        // frame index where we need to do replacement for this
        // incoming reference string item
        else {
            int pos = predict(ref_str, frame_items, refStrLen, i + 1, frame_items.size());
            frame_items[pos] = ref_str[i];
            printCurrFrames(ref_str[i], frame_items, frame_items.size(), max_frames);
        }

    }
    cout << "\n\nHits: " << hits << "\n";
    cout << "Page Faults: " << refStrLen - hits << "\n";
}

// Driver Function
int main()
{
    // int ref_str[] = {9, 0, 5, 1, 0, 3, 0, 4, 1, 3, 0, 3, 1, 3};
    int ref_str[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int refStrLen = sizeof(ref_str) / sizeof(ref_str[0]);
    int max_frames = 3;

    optimalPage(ref_str, refStrLen, max_frames);
    return 0;
}
