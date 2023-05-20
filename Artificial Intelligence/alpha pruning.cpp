#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int alphaBeta(int depth, int nodeIndex, bool isMax, int scores[], int alpha, int beta) {
    if (depth == 0) {
        return scores[nodeIndex];
    }

    if (isMax) {
        int best = -INF;
        for (int i = 0; i < 2; i++) {
            int val = alphaBeta(depth - 1, nodeIndex * 2 + i, false, scores, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    } else {
        int best = INF;
        for (int i = 0; i < 2; i++) {
            int val = alphaBeta(depth - 1, nodeIndex * 2 + i, true, scores, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    }
}

int main() {
    int scores[] = {3, 2, 5, 9, 0, 1, 7, 5};
    int n = sizeof(scores) / sizeof(scores[0]);

    int result = alphaBeta(3, 0, true, scores, -INF, INF);
    cout << "The optimal value is: " << result << endl;

    return 0;
}

