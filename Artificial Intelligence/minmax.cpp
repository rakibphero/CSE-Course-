#include <bits/stdc++.h>
using namespace std;

int minimax(int depth, int nodeIndex, bool maximizingPlayer,
            int values[], int alpha, int beta)
{
    if (depth == 3) {
        return values[nodeIndex];
    }

    if (maximizingPlayer) {
        int best = INT_MIN;

        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i,
                              false, values, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);

            if (beta <= alpha)
                break;
        }
        return best;
    }
    else {
        int best = INT_MAX;

        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i,
                              true, values, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);

            if (beta <= alpha)
                break;
        }
        return best;
    }
}

int main()
{
    int values[] = { -1, 4, 2, 6, -3, -5, 0, 7 };
    cout << "The optimal value is : " << minimax(0, 0, true, values, INT_MIN, INT_MAX);
    return 0;
}

