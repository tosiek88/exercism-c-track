#include "grade_school.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_roster(roster_t *roster) { roster->count = 0; }

int add_student(roster_t *roster, const char *name, uint8_t grade) {
  student_t potentialStudent = (student_t){grade, ""};
  strcpy(potentialStudent.name, name);

  for (unsigned long i = 0; i < roster->count; i++) {

    if (strcmp(roster->students[i].name, name) == 0) {
      return 0;
    }

    if (potentialStudent.grade < roster->students[i].grade) {
      student_t tmpStudent = roster->students[i];
      roster->students[i] = potentialStudent;
      potentialStudent = tmpStudent;
    }

    if (potentialStudent.grade == roster->students[i].grade) {
      if (strcmp(potentialStudent.name, roster->students[i].name) <= 0) {
        student_t tmpStudent = roster->students[i];
        roster->students[i] = potentialStudent;
        potentialStudent = tmpStudent;
      };
    }
  }

  roster->students[roster->count] = potentialStudent;
  roster->count += 1;
  return 1;
}

roster_t get_grade(roster_t *roster, uint8_t desire_grade) {
  roster_t tempRoster;
  init_roster(&tempRoster);

  for (int i = 0; i < (int)roster->count; i++) {
    if (roster->students[i].grade == desire_grade) {
      add_student(&tempRoster, roster->students[i].name,
                  roster->students[i].grade);
    }
  }

  return tempRoster;
}
