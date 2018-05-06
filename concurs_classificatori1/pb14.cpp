#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


const int EC = 900;
const int PO = 800;
const int FU = 700;
const int CO = 600;
const int ES = 500;
const int TR = 400;
const int DP = 300;
const int PA = 200;
const int RE = 100;


typedef pair<int, int> P;
typedef vector<P> VP;
typedef vector<int> VE;
typedef pair<VE, int> P2;


vector<VP> jug(10, VP(5));


int num(char c) {
  if (c == 'A') return 12;
  if (c == 'K') return 11;
  if (c == 'Q') return 10;
  if (c == 'J') return 9;
  if (c == 'D') return 8;
  return c - '2'; // digit
}


int pal(char c) {
  if (c == 'C') return 0;
  if (c == 'D') return 1;
  if (c == 'P') return 2;
  return 3; // 'T'
}


VE valor(int j) {
  VE Q1(13, 0);
  VE Q2(4, 0);
  for (int i = 0; i < 5; ++i) {
    P a = jug[j][i];
    ++Q1[a.first];
    ++Q2[a.second];
  }

  bool escala = true;
  int x = jug[j][0].first;
  for (int i = 1; i < 5; ++i)
    if (jug[j][i].first != x + i) escala = false;

  bool color = false;
  for (int i = 0; i < 4; ++i)
    if (Q2[i] == 5) color = true;

  VE val(6, -1);
  if (escala) {
    val[0] = (color ? EC : ES);
    val[1] = jug[j][4].first;
  }
  else {
    if (color) {
      val[0] = CO;
      for (int i = 0; i < 5; ++i) val[5-i] = jug[j][i].first;
    }
    else {
      VP num;
      for (int i = 0; i < 13; ++i)
        if (Q1[i]) num.push_back(P(Q1[i], i));
      sort(num.begin(), num.end(), greater<P>());

      if (num[0].first == 4) val[0] = PO;
      else if (num[0].first == 3) {
        if (num[1].first == 2) val[0] = FU;
        else val[0] = TR;
      }
      else if (num[0].first == 2) {
        if (num[1].first == 2) val[0] = DP;
        else val[0] = PA;
      }
      else val[0] = RE;

      for (int i = 0; i < (int)num.size(); ++i) val[i+1] = num[i].second;
    }
  }
  return val;
}


bool comp(const P2& x, const P2& y) {
  if (x.first != y.first) return x.first > y.first;
  return x.second < y.second;
}


int main() {
  int t;
  cin >> t;
  while (t--) {
    VP carta(52);
    for (int i = 0; i < 52; ++i) {
      char c1, c2;
      cin >> c1 >> c2;
      carta[i] = P(num(c1), pal(c2));
    }

    int seg = 0;
    for (int j = 0; j < 10; ++j) {
      for (int i = 0; i < 5; ++i) jug[j][i] = carta[seg++];
      sort(jug[j].begin(), jug[j].end());
    }

    vector<P2> val(10);
    for (int j = 0; j < 10; ++j) {
      val[j].first = valor(j);
      val[j].second = j;
    }
    sort(val.begin(), val.end(), comp);
    for (int j = 0; j < 10; ++j) cout << (j ? " " : "") << char('A' + val[j].second);
    cout << endl;
  }
}
