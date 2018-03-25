#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool valid(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10)
{
    vector<int> quantitat{0, 0, 0};
    ++quantitat[i1];
    ++quantitat[i2];
    ++quantitat[i3];
    ++quantitat[i4];
    ++quantitat[i5];
    ++quantitat[i6];
    ++quantitat[i7];
    ++quantitat[i8];
    ++quantitat[i9];
    ++quantitat[i10];
    return quantitat[0] == 4 && quantitat[1] == 4;
}

int main()
{
    vector<string> v{"taronger", "llimoner", "res"};

    int count = 0;
    for (int i1 = 0; i1 < 3; ++i1)
      for (int i2 = 0; i2 < 3; ++i2)
        for (int i3 = 0; i3 < 3; ++i3)
          for (int i4 = 0; i4 < 3; ++i4)
            for (int i5 = 0; i5 < 3; ++i5)
              for (int i6 = 0; i6 < 3; ++i6)
                for (int i7 = 0; i7 < 3; ++i7)
                  for (int i8 = 0; i8 < 3; ++i8)
                    for (int i9 = 0; i9 < 3; ++i9)
                      for (int i10 = 0; i10 < 3; ++i10)
                          if (valid(i1, i2, i3, i4, i5, i6, i7, i8, i9, i10))
                            ++count;

    cout << count << endl;
}
