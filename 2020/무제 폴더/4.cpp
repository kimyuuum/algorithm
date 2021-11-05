#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> gift_cards = {5, 4, 5, 4, 5};
vector<int> wants = {1, 2, 3, 5, 4};
const int MAX = 100001;
int solution(vector<int> gift_cards, vector<int> wants) {
  int answer = 0;
  bool get[MAX] = {
      false,
  };

  for (int i = 0; i < gift_cards.size(); i++) {
    if (gift_cards[i] == wants[i]) {
      get[i] = true;
    }
  }

  for (int i = 0; i < gift_cards.size(); i++) {
    if (!get[i]) {
      for (int j = 0; j < gift_cards.size(); j++) {
        if (i != j) {
          int want = wants[i];
          if (gift_cards[j] == want && !get[j]) {
            int temp = gift_cards[i];
            gift_cards[i] = gift_cards[j];
            gift_cards[j] = temp;
            get[i] = true;
            if (gift_cards[j] == wants[j]) {
              get[j] = true;
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < wants.size(); i++) {
    if (!get[i]) {
      answer++;
    }
  }

  return answer;
}
