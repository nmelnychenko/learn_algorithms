#include <string>
#include <iostream>
#include "table.h"

using namespace std;

float calculateAvaregeScore(Table<int> scoresTable) {
  float sum = 0.00;
  int count = scoresTable.Count();
  int *allScores = scoresTable.getValues();

  for (int i = 0; i < 1000; i++) {
    if (allScores[i]) {
      sum = sum + allScores[i];
    }
  }

  return sum / count;
}

int main () {
  Table<int> EducationScores;

  EducationScores.put("math", 90);
  EducationScores.put("physics", 92);
  EducationScores.put("programming", 91);
  EducationScores.put("english", 85);

  cout << calculateAvaregeScore(EducationScores);

  return 0;
}
